#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(SortFunctionTest)
	{
	public:
		
		TEST_METHOD(CaseSensitivityTest)
		{
			// TODO: Your test code here
			//Assert::AreEqual("hi", "hi");
			TextBuddy lala;
			
			lala.addLine("Lily is a girl");
			lala.addLine("little brown fox");
			lala.addLine("Zebra is an animal");
			lala.sortFile();
			vector<string> actualTBList = lala.getTextBuddyContent();

			vector<string> expectedTBList;
			expectedTBList.push_back("Lily is a girl");
			expectedTBList.push_back("little brown fox");
			expectedTBList.push_back("Zebra is an animal");

			Assert::AreEqual(expectedTBList[0], actualTBList[0]);
			Assert::AreEqual(expectedTBList[1], actualTBList[1]);
			Assert::AreEqual(expectedTBList[2], actualTBList[2]);
						
		}

	};
}