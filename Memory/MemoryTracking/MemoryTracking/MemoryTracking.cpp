#include <iostream>

static size_t AllocatedSize = 0;

void* operator new(size_t size)
{
	AllocatedSize += size;
	std::cout << "Allocating memory of " << size << " Bytes" << std::endl;
	std::cout << "Total Allocated : " << AllocatedSize << std::endl;
	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	AllocatedSize -= size;
	std::cout << "Freed : " << size << " Bytes" << std::endl;
	std::cout << "Allocated size after freeing memory: " << AllocatedSize << std::endl;
	free(memory);
}

struct MyClass
{
	int x, y, z;
	std::string str = "string";
};

int main()
{ 
	{
		MyClass* obj = new MyClass();
	}

	std::string name = "name";
	int* value = new int(10);
}