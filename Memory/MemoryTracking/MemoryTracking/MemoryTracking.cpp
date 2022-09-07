#include <iostream>

void* operator new(size_t size)
{
	return malloc(size);
}

struct MyClass
{
	int x, y, z;
};

int main()
{
	MyClass* obj = new MyClass();
	std::unique_ptr<MyClass> obj1 = std::make_unique<MyClass>();
	std::string name = "name";
}