// Study_Constructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyBase.h"
#include "Child.h"
#include "Child2.h"
#include "Child3.h"

int main()
{
	MyBase<Child>* myObject = new Child();
	myObject->Test();

	MyBase<Child2>* myObject2 = new Child2();
	myObject2->Test();

	std::unique_ptr<Child> childUnique{ std::make_unique<Child>() };
}