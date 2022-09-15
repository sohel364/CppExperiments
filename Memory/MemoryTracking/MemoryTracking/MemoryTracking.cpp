#include <iostream>

void* operator new(size_t size)
{
	std::cout << "Allocating memory of " << size << " Bytes" << std::endl;
	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	std::cout << "Freed" << size << " Bytes" << std::endl;
	free(memory);
}

struct MyClass
{
	int x, y, z;
};

int main()
{ 
	{
		MyClass* obj = new MyClass();
	}

	std::string name = "name";
	int* value = new int(10);
	std::cout << name << std::endl;
}