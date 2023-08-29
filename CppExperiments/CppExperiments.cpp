
#include <iostream>
#include <sstream>

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
}