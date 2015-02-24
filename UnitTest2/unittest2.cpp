//Liu Gantian 
//A0113555L
//CE2
//Unit Test 2
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(SearchFunctionTest)
	{
	public:
		
		//When each string inside TextBuddyContent contains the exact input string
		TEST_METHOD(SearchWithExactInput)
		{	
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

		//Search TextBuddyContent regardless of the content case.
		TEST_METHOD(SearchWithCaseDifferentInput)
		{
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