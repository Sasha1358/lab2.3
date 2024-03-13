#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.3/Rational.h"
#include "../lab2.3/Rational.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest23
{
	TEST_CLASS(UnitTest23)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Rational rational{};
			rational.Init(1, 1);
			Assert::AreEqual(rational.value(), 1., 0.0001);
		}
	};
}
