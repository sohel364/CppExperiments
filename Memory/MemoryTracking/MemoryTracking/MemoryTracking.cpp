#include <iostream>
#include "SimpleEntity.h"

static size_t AllocatedSize = 0;  //global static variable stored in Initialized Data Segment in

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
	static int BSSTest=4; /* Uninitialized static variable stored in bss */

	{
		MyClass* obj = new MyClass();
	}

	std::string name = "name";
	int* value = new int(10);

	// Smart pointer's random tests

	{
		std::unique_ptr<SimpleEntity> entity(new SimpleEntity()); // This is ok. But not safe in case of exceptions from the constructor
		std::unique_ptr<SimpleEntity> entitySafe = std::make_unique<SimpleEntity>(); // This is best proper way
		//std::unique_ptr<SimpleEntity> testCopy = entitySafe; // not allowed copy constructor and copy assignment operator both operator are deleted

		// Both Entity objects are destroyed once we are out of this scope
	}

	{
		std::shared_ptr<SimpleEntity> entityHolder; // Increase the reference count 
		std::weak_ptr<SimpleEntity> entityWeakPtr; // Does not incrase the ref count
		{
			std::shared_ptr<SimpleEntity> entity(std::make_shared<SimpleEntity>()); // Not best way
			std::shared_ptr<SimpleEntity> entitySafe = std::make_shared<SimpleEntity>(); // Safer
			entityHolder = entity; // we are sharing the entity reference here which keeps the object alive till we reach out of scope
			entityWeakPtr = entitySafe;
			// entitySafe is destroyed after this scope
		}		
		// entity is destroyed after this scope
	}

	return 0;
}