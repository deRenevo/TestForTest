#include "App.h"

#include <iostream>

#include "Calculator.h"

#include <sstream>


Input::ParseResult Input::Parse(const std::string& line)
{
	Input::ParseResult Result;

	std::istringstream Stream(line);

	if (!(Stream >> Result.FirstNumber
		>> Result.Operation
		>> Result.SecondNumber))
	{
		throw std::invalid_argument("Invalid expression");
	}

	return Result;
}

double Input::CalculateOperation(const std::string& operation, double firstNumber, double secondNumber)
{
	if (operation == "+")
	{
		return Calculator::Add(firstNumber, secondNumber);
	}

	if (operation == "-")
	{
		return Calculator::Subtract(firstNumber, secondNumber);
	}

	if (operation == "*")
	{
		return Calculator::Multiply(firstNumber, secondNumber);
	}

	if (operation == "/")
	{
		return Calculator::Divide(firstNumber, secondNumber);
	}

	if (operation == "%")
	{
		return Calculator::Percent(firstNumber, secondNumber);
	}

	throw std::invalid_argument("Unknown operation");
}

void App::Run()
{
	std::string Line;

	std::cout << "Enter expression: ";
	std::getline(std::cin, Line);

	try
	{
		const Input::ParseResult Parsed = Input::Parse(Line);

		const double Result = Input::CalculateOperation(
			Parsed.Operation,
			Parsed.FirstNumber,
			Parsed.SecondNumber
		);

		std::cout << "Result: " << Result << "\n";
	}
	catch (const std::exception& E)
	{
		std::cout << "Error: " << E.what() << "\n";
	}
}