#pragma once
#include <iostream>
#include <string>
#include <memory>

class SimpleEntity
{
public:
	SimpleEntity()
	{
		std::cout << "Created my simple entiry..";
	}
	~SimpleEntity()
	{
		std::cout << "Destroyed my simple entiry..";
	}
};

