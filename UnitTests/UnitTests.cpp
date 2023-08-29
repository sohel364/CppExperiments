#include "pch.h"
#include "CppUnitTest.h"
#include "../CppExperiments/CommonUtils.h"

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
}
