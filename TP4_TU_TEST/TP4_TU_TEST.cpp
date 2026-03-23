#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../TP4_TU/TP4_TU.h"

}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TP4TUTEST
{
	TEST_CLASS(TP4TUTEST)
	{
	public:
		
		TEST_METHOD(TestEstPaire)
		{
			Assert::AreEqual(1, estPair(4));
		}
		TEST_METHOD(TestEstPaire2)
		{
			Assert::AreEqual(1, estPair(6));
		}
		TEST_METHOD(TestEstPaire3)
		{
			Assert::AreEqual(0, estPair(7));
		}
	};
}
