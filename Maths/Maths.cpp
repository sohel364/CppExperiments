#include <iostream>
#include <Math.h>
#include <string>

#include "../CppExperiments/CommonUtils.h"

/// <summary>Calcualtes.</summary>
/// <param name="x">(Optional) The x coordinate.</param>
/// <param name="y">(Optional) The y coordinate.</param>
/// <returns>A double.</returns>
double Calcualte(double x = dNaN, float y = fNaN)
{
    double result = x + y;
    return result;
}

// c++ 20 feature. This is a evetually a tempalted function now
bool Compare(auto val1, auto val2)
{
    return val1 <=> val2 > 0; 
}

/// <summary>Main entry-point for this application.</summary>
/// <returns>Exit-code for the process - 0 for success, else an error code.</returns>
int main()
{
    /// Input block for Testing
    /*for (std::string line; std::getline(std::cin, line);)
    {
        std::cout << line << std::endl;
    }*/

    /*std::string line;
    while(std::getline(std::cin, line))
    {
        std::cout << line << std::endl;
    }*/

    std::cout << sqrt(-2) << std::endl;

    if(std::nan == std::nan)
        std::cout << "Equal" << std::endl;
    else
        std::cout << "Not Equal" << std::endl;

    Print(Calcualte()); // Prints nan
    Print(Calcualte(12.01, 10.01)); // double to float warning for float argument
    Print(Calcualte(12.01, (float)10.01));

    Compare(20, 10) ? Print("TRUE") : Print("FALSE");
}