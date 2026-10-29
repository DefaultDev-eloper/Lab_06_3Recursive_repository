#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_3Recursive.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestSumRecInt_Mixed)
		{
			int a[6] = { -4, 3, 0, 5, -1, 2 };

			Assert::AreEqual(10, SumRec(a, 6, 0));  
		}

		TEST_METHOD(TestSumRecInt_AllNegative)
		{
			int a[3] = { -1, -2, -3 };

			Assert::AreEqual(0, SumRec(a, 3, 0));
		}

		TEST_METHOD(TestSumRecInt_ZeroNotAdded)
		{
			int a[3] = { 0, 0, 7 };

			Assert::AreEqual(7, SumRec(a, 3, 0));
		}

		TEST_METHOD(TestSumRecTemplateInt)
		{
			int a[6] = { -4, 3, 0, 5, -1, 2 };

			Assert::AreEqual(10, SumRec<int>(a, 6, 0));
		}

		TEST_METHOD(TestSumRecTemplateDouble)
		{
			double b[5] = { -1.5, 2.5, 0.0, 3.0, -0.5 };

			Assert::AreEqual(5.5, SumRec<double>(b, 5, 0), 1e-9);
		}

		TEST_METHOD(TestSumRecTemplateDouble_AllNegative)
		{
			double b[3] = { -1.1, -2.2, -3.3 };

			Assert::AreEqual(0.0, SumRec<double>(b, 3, 0), 1e-9);
		}

		TEST_METHOD(TestSumRecTemplateString)
		{
			string c[4] = { "-4 ", "", "3 ", "5 " };

			Assert::AreEqual(string("-4 3 5 "), SumRec<string>(c, 4, 0));
		}

		TEST_METHOD(TestSumRecDoesNotModifyArray)
		{
			int a[4] = { -1, 2, 0, 3 };

			SumRec(a, 4, 0);

			Assert::AreEqual(-1, a[0]);
			Assert::AreEqual(2, a[1]);
			Assert::AreEqual(0, a[2]);
			Assert::AreEqual(3, a[3]);
		}
	};
}