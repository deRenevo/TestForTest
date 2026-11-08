#pragma once
#include <string>

namespace App
{
	void Run();
}

namespace Input
{
	struct ParseResult
	{
		std::string Operation = std::string();
		double FirstNumber = 0.0;
		double SecondNumber = 0.0;
	};

	ParseResult Parse(const std::string& line);
	double CalculateOperation(const std::string& operation, double firstNumber, double secondNumber);
}