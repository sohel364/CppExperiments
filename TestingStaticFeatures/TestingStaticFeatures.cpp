// TestingStaticFeatures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>
#include <optional>

/// <summary>Log line struct.</summary>
struct LogLine
{
	std::wstring serverType;
	std::wstring dateTime;
	std::wstring level;
	std::wstring message;
};

static LogLine ParseLogLine(const std::wstring& logline)
{
	LogLine line;
	// Regular expression pattern to match the log line format
	const std::wregex pattern(LR"((.+?):\s(\d{4}-\d{2}-\d{2} \d{2}:%\d{2}:\d{2}_\d{6}) \[(\w+)\] (.+))");
	std::wsmatch matches;
	try
	{
		if (std::regex_match(logline, matches, pattern))
			return LogLine{ matches[1].str(), matches[2].str(), matches[3].str(), matches[4].str() };
		else {
			throw std::runtime_error("Invalid input");
		}
	}
	catch(const std::regex_error& err)
	{
		throw err;
	}
}

int main()
{
	std::wstring log(L"ServerTypeXYZ: 2024-03-12 18:47:42_366685 [info]  Pack log files. Testing \n\n\n\n terjyertweyur");

	const auto line = ParseLogLine(log);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
