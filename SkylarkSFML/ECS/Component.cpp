#include "stdafx.h"
#include "Component.h"
#include <iostream>


Component::Component()
{
}


Component::~Component()
{
	std::cout << "Deleted the component";
}
