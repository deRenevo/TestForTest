#include "pch.h"

#include "CppUnitTest.h"

#include "../App.h"
#include "../Calculator.h"+
#include <functional>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AppTests
{
	TEST_CLASS(CalculatorTests)
	{
	public:
		// TC-1
		TEST_METHOD(TC_1)
		{
			Assert::AreEqual(5., Calculator::Add(2., 3.), 1e-9);
		}

		// TC-2
		TEST_METHOD(TC_2)
		{
			Assert::AreEqual(1., Calculator::Add(-2., 3.), 1e-9);
		}

		// TC-3
		TEST_METHOD(TC_3)
		{
			Assert::AreEqual(0., Calculator::Add(0., 0.), 1e-9);
		}

		// TC-4
		TEST_METHOD(TC_4)
		{
			Assert::AreEqual(-5., Calculator::Add(-2., -3.), 1e-9);
		}

		// TC-5
		TEST_METHOD(TC_5)
		{
			Assert::AreEqual(6., Calculator::Subtract(10., 4.), 1e-9);
		}

		// TC-6
		TEST_METHOD(TC_6)
		{
			Assert::AreEqual(-2., Calculator::Subtract(-5., -3.), 1e-9);
		}

		// TC-7
		TEST_METHOD(TC_7)
		{
			Assert::AreEqual(0., Calculator::Subtract(0., 0.), 1e-9);
		}

		// TC-8
		TEST_METHOD(TC_8)
		{
			Assert::AreEqual(6., Calculator::Multiply(2., 3.), 1e-9);
		}

		// TC-9
		TEST_METHOD(TC_9)
		{
			Assert::AreEqual(6., Calculator::Multiply(-2., -3.), 1e-9);
		}

		// TC-10
		TEST_METHOD(TC_10)
		{
			Assert::AreEqual(5., Calculator::Divide(10., 2.), 1e-9);
		}

		// TC-11
		TEST_METHOD(TC_11)
		{
			Assert::AreEqual(-5., Calculator::Divide(10., -2.), 1e-9);
		}

		// TC-12
		TEST_METHOD(TC_12)
		{
			Assert::ExpectException<std::invalid_argument>([]() {
				Calculator::Divide(1., 0.);
				});
		}

		// TC-13
		TEST_METHOD(TC_13)
		{
			Assert::AreEqual(0.3333333333, Calculator::Divide(1., 3.), 1e-9);
		}

		// TC-14
		TEST_METHOD(TC_14)
		{
			Assert::AreEqual(10., Calculator::Percent(100., 10.), 1e-9);
		}

		// TC-15
		TEST_METHOD(TC_15)
		{
			Assert::AreEqual(0., Calculator::Percent(100., 0.), 1e-9);
		}

		// TC-16
		TEST_METHOD(TC_16)
		{
			const std::string Line = "2 + 3";
			const Input::ParseResult Parsed = Input::Parse(Line);

			Assert::AreEqual(2., Parsed.FirstNumber, 1e-9);
			Assert::AreEqual(std::string("+"), Parsed.Operation);
			Assert::AreEqual(3., Parsed.SecondNumber, 1e-9);
		}

		// TC-17
		TEST_METHOD(TC_17)
		{
			Assert::ExpectException<std::invalid_argument>([]() {
				Input::Parse("fgbhbfdhdfhbj");
			});
		}

		// TC-18
		TEST_METHOD(TC_18)
		{
			Assert::ExpectException<std::invalid_argument>([]() {
				Input::Parse(" ");
			});
		}
	};
}