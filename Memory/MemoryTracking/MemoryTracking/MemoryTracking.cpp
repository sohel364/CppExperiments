#include <iostream>

void* operator new(size_t size)
{
	std::cout << size << std::endl;

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
	int* value = new int(10);
	std::cout << name << std::endl;
}