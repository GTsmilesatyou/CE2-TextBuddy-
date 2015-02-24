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
			vector<string> actualTBList = tbuddy.getTextBuddyContent();

			vector<string> expectedTBList;
			expectedTBList.push_back("Lily is a girl");
			expectedTBList.push_back("Julia is a girl");

			Assert::AreEqual(expectedTBList[0], actualTBList[0]);
			Assert::AreEqual(expectedTBList[1], actualTBList[1]);

		}

	};
}