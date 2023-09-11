
#include <iostream>
#include <sstream>
#include <map>

#include "CommonUtils.h"

using namespace std;

int main()
{
    // Read input buffer
    ostringstream oss;
    auto cout_buff = cout.rdbuf(oss.rdbuf());
    cout << "Test";
    cout.rdbuf(cout_buff);
    string n = oss.str();
    cout << n;

    // Map/Set Contains // C++ 20
    // It gives a much easier way to check if a key is present in the associative container(set or map) in C++20. 
    // It replaces the find built-in function.
    
    std::map<int, std::string> studentMap = { {1, "Simon"}, {2, "Jack"}, {3, "Richard"} };

    if (ContainsInMap<int, std::string>(studentMap, 4))
        std::cout << "Found" << std::endl;
    else
        std::cout << "Not Found" << std::endl;
}