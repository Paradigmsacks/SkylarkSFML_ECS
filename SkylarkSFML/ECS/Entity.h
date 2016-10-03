#pragma once
#include <map>
#include "Component.h"
#include <type_traits>
#include <typeinfo>
#include <iostream>
namespace sp
{
	class Entity
	{
	public:
		Entity();
		~Entity();

		template <class T> void addComponent(T* comp);
		template <class T> bool hasComponent();
		template <class T> ComponentHandle<T> getComponent();
		template <class T> void removeComponent();
		virtual void initialize() {};
	private:
		std::multimap<size_t, Component::PTR> components;
	};

	template <class T>
	void Entity::addComponent(T* comp)
	{
		static_assert(std::is_base_of<Component, T>::value, "Component is not derived from Component");
		size_t hash = typeid(T).hash_code();
		Component::PTR mComp(comp);
		components.insert(std::make_pair(hash, std::move(mComp)));
	}

	template <class T>
	bool Entity::hasComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "Component is not derived from Component");
		std::type_info ti = typeid(T);
		return (components.find(ti) != components.end());
	}




	template <class T>
	ComponentHandle<T> Entity::getComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "Component is not derived from Component");
		size_t ti = typeid(T).hash_code();
		auto it = components.find(ti);
		if (it == components.end())
		{
			return ComponentHandle<T>();
		}
		auto p = std::dynamic_pointer_cast<T>(it->second);
		return ComponentHandle<T>(p);
	}

	template <class T>
	void Entity::removeComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "Component is not derived from Component");
		size_t ti = typeid(T).hash_code();
		auto it = components.find(ti);
		if (it != components.end())
		{
			components.erase(it);
		}
	}
}
