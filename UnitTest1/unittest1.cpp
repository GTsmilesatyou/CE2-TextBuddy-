//Liu Gantian 
//A0113555L
//CE2
//Unit test 1
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(SortFunctionTest)
	{
	public:
		
		//Expected list should be sorted regardless of its case.
		TEST_METHOD(CaseSensitivityTest)
		{
			TextBuddy tbtest1;
			
			tbtest1.addLine("Lily is a girl");
			tbtest1.addLine("little brown fox");
			tbtest1.addLine("Zebra is an animal");
			tbtest1.sortFile();
			vector<string> actualTBList = tbtest1.getTextBuddyContent();

			vector<string> expectedTBList;
			expectedTBList.push_back("Lily is a girl");
			expectedTBList.push_back("little brown fox");
			expectedTBList.push_back("Zebra is an animal");

			Assert::AreEqual(expectedTBList[0], actualTBList[0]);
			Assert::AreEqual(expectedTBList[1], actualTBList[1]);
			Assert::AreEqual(expectedTBList[2], actualTBList[2]);
						
		}

		//Numbers should appear before letters after sorting
		TEST_METHOD(NumberOrderTest){
			TextBuddy tbtest2;

			tbtest2.addLine("little brown fox");
			tbtest2.addLine("1 is a dear a female dear");
			tbtest2.addLine("Zebra is an animal");
			tbtest2.sortFile();
			vector<string> actualTBList = tbtest2.getTextBuddyContent();

			vector<string> expectedTBList;
			expectedTBList.push_back("1 is a dear a female dear");
			expectedTBList.push_back("little brown fox");
			expectedTBList.push_back("Zebra is an animal");

			Assert::AreEqual(expectedTBList[0], actualTBList[0]);
			Assert::AreEqual(expectedTBList[1], actualTBList[1]);
			Assert::AreEqual(expectedTBList[2], actualTBList[2]);

		}

	};
}