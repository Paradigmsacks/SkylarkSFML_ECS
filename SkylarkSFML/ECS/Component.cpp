#include "stdafx.h"
#include "Component.h"
#include <iostream>

namespace sp
{
	Component::Component()
	{
	}


	Component::~Component()
	{
		std::cout << "Deleted the component";
	}
}
