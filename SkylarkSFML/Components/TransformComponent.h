#pragma once
#include "..\ECS\Component.h"
#include "..\Math\Vec2f.h"


namespace sp
{
	struct TransformComponent : public Component
	{
		Vec2f position;
		float angle;
	};
}