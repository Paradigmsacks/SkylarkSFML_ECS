#pragma once
#include <memory>
class Component
{
public:
	typedef std::shared_ptr<Component> PTR;
	Component();
	virtual ~Component();
};

template <class T>
class ComponentHandle
{
public:
	ComponentHandle(std::shared_ptr<T>& theComponent)
	{
		mPtr = theComponent;
	}
	ComponentHandle()
	{

	}
	std::shared_ptr<T> operator->()
	{
		return mPtr.lock();
	}
private:
	std::weak_ptr<T> mPtr;
};

