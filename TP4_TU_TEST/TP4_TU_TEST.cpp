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
		TEST_METHOD(TestMax2)
		{
			Assert::AreEqual(5, max2(5, 3));
		}
		TEST_METHOD(TestMax3)
		{
			Assert::AreEqual(5, max2(3, 5));
		}
		TEST_METHOD(TestFactorielle1)
		{
			Assert::AreEqual(1, factorielle(0));
		}
		TEST_METHOD(TestFactorielle2)
		{
			Assert::AreEqual(1, factorielle(1));
		}
		TEST_METHOD(TestFactorielle3)
		{
			Assert::AreEqual(24, factorielle(4));
		}
		TEST_METHOD(TestContientMajuscule1)
		{
			Assert::AreEqual(0, contientMajuscule("bonjour"));
		}
		TEST_METHOD(TestContientMajuscule2)
		{
			Assert::AreEqual(1, contientMajuscule("bonJour"));
		}
		TEST_METHOD(TestContientMajuscule3)
		{
			Assert::AreEqual(1, contientMajuscule("ABC"));
		}
		TEST_METHOD(TestContientMajuscul41)
		{
			Assert::AreEqual(0, contientMajuscule(""));
		}
	};
}
