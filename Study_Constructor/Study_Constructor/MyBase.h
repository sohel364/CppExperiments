#pragma once
#include "iostream"
#include "CommonBase.h"

#include <atldef.h>

template<typename CCLass>
class ATL_NO_VTABLE MyBase : public CommonBase
{
public:
	virtual void Test(); // Virtual
	void NormalMethod()
	{
		std::cout << "I am just a normal random method" << std::endl;
	}
	void CommonStuffs(const std::string str)
	{
		std::cout << str << std::endl;
	}

	// Inherited via CommonBase
	virtual void MustImplementMe() override
	{
		std::cout << "This is abstract" << std::endl;
	}

protected:
	std::string m_fileName{"testFileBase.txt"};
};

template<typename CCLass>
inline void MyBase<CCLass>::Test()
{
	std::cout << "Features in Base" << std::endl;
}
