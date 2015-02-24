#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(SearchFunctionTest)
	{
	public:
		
		TEST_METHOD(SearchWithExactInput)
		{
			// TODO: Your test code here
			
			TextBuddy tbuddy;

			tbuddy.addLine("Lily is a girl");
			tbuddy.addLine("Zebra is an animal");
			tbuddy.addLine("Julia is a girl");
			
			tbuddy.searchFile("girl");
			vector<string> actualTBList = tbuddy.getTempTextBuddy();

			vector<string> expectedTBList;
			expectedTBList.push_back("Lily is a girl");
			expectedTBList.push_back("Julia is a girl");

			Assert::AreEqual(expectedTBList[0], actualTBList[0]);
			Assert::AreEqual(expectedTBList[1], actualTBList[1]);

		}

		TEST_METHOD(SearchWithCaseDifferentInput)
		{
			// TODO: Your test code here

			TextBuddy tbuddy;

			tbuddy.addLine("Lily is a girl");
			tbuddy.addLine("Zebra is an animal");
			tbuddy.addLine("Julia is a GIRL");
			tbuddy.addLine("Crab's daughter is a babyGirl whale");

			tbuddy.searchFile("girl");
			vector<string> actualTBList = tbuddy.getTempTextBuddy();

			vector<string> expectedTBList;
			expectedTBList.push_back("Lily is a girl");
			expectedTBList.push_back("Julia is a GIRL");
			expectedTBList.push_back("Crab's daughter is a babyGirl whale");

			Assert::AreEqual(expectedTBList[0], actualTBList[0]);
			Assert::AreEqual(expectedTBList[1], actualTBList[1]);
			Assert::AreEqual(expectedTBList[2], actualTBList[2]);
		}

	};
}