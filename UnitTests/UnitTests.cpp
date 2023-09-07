#include "pch.h"
#include "CppUnitTest.h"
#include "../CppExperiments/CommonUtils.h"
#include "../Study_Constructor/Study_Constructor/MyBase.h"
#include "../Study_Constructor/Study_Constructor/Child.h"
#include "../Study_Constructor/Study_Constructor/SArray.h"

#include <iostream>
#include <sstream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(CommonUtils)
	{
	public:
		
		TEST_METHOD(PrintTest)
		{
			ostringstream oss;
			auto cout_buff = cout.rdbuf(oss.rdbuf());
			cout << "Test";
			cout.rdbuf(cout_buff);			
			std::string str = oss.str();

			std::wstring widestr = std::wstring(str.begin(), str.end());

			Assert::AreEqual(L"Test", widestr.c_str());
		}
	};

	TEST_CLASS(ArrayTest)
	{
	public:
		TEST_METHOD(SArrayTest)
		{	
			SArray<string, 5> testArray;
			Assert::AreEqual(5, testArray.GetSize());
		}
	};

	TEST_CLASS(FileNameTest)
	{
	public:
		TEST_METHOD(Ge)
		{
			std::unique_ptr<Child> childUnique{ std::make_unique<Child>() };
			Assert::IsTrue("testFileChild.txt" == childUnique->FileName());
		}
	};
}
