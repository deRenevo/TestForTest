#include "Calculator.h"

#include <stdexcept>

double Calculator::Add(double a, double b)
{
	return a + b;
}

double Calculator::Subtract(double a, double b)
{
	return a - b;
}

double Calculator::Multiply(double a, double b)
{
	return a * b;
}

double Calculator::Divide(double a, double b)
{
	if (std::abs(b) < std::numeric_limits<double>::epsilon())
	{
		throw std::invalid_argument("Division by zero");
	}
	
	return a / b;
}

double Calculator::Percent(double a, double b)
{
	return a * b / 100.0;
}
