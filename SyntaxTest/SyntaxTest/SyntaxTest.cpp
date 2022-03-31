// SyntaxTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>
#include <iomanip>
#include <ctime>

constexpr auto c_formatISO8601 = L"%Y-%m-%d";


class TestClass
{

public:
    /// <summary>Formats a date according to ISO 8601.</summary>
    /// <param name="timePoint">The time point.</param>
    /// <returns>The formatted date according to ISO 8601.</returns>
    std::wstring FormatDateISO8601(const std::chrono::system_clock::time_point& timePoint)
    {
        //const auto timePointT = std::chrono::system_clock::to_time_t(timePoint);

        time_t current_time;
        std::wstringstream stream;
        stream << std::put_time(std::localtime(&current_time), c_formatISO8601);
        return stream.str();
    }

    const void ChangeKey()
    {
        m_key = 9;
        m_value = 10;
    }

    void ChangeValue() const
    {
        //m_key = 8; // const member function changes change member variables
    }
    // Testing std::ssize a c++20 sysntax
    void TestSSize()
    {
        std::vector<int> list = { -4, -5, -6 };
        std::cout << list.size() << std::endl;
        std::cout << std::ssize(list) << std::endl;
    }

private:
    int m_key = 0;
    int m_value = 0;
};

const bool isInt()
{
    return false;
}

constexpr int Product(int x, int y)
{
    return (x * y);
}

struct myStruct
{
    int a = 10;
    void TestPublic() {

    }
    private:
    void TestPrivate() {

    }

public:
    const auto& ReadWrite()
    {
        std::cout << "ReadWrite called" << std::endl;
        return a;
    }

    auto& ReadWrite() const
    {
        std::cout << "Read write function ReadOnly" << std::endl;
        return a;
    }

    void TestingArgument(int key)
    {
        std::cout << key++ << std::endl;
    }
};

int main()
{  
    TestClass testObj;
    testObj.TestSSize();

    myStruct obj;        
    obj.ReadWrite();
    obj.ReadWrite();

    //std::gmtime()

    /* myStruct mystruct;
    mystruct.
    std::cout << Product(10, 10) << std::endl;*/
    //const auto& [x, y] = TestClass();
    //std::vector<int> vec = {1,2,3};
    //std::cout<<std::ssize

    std::cout << 20 / 2. / 2. << std::endl;

    int i = 0;
    do
    {
        (i == 0) ? std::cout << "first conditon succeeded" : i == 10 ? std::cout << "It's 10" << std::endl : std::cout << "none";
    }
    while(std::cin >> i);
}
