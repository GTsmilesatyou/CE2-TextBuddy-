//Liu Gantian 
//A0113555L
//CE2
//TextBuddy header file that contains the Class TextBuddy
#ifndef TEXTBUDDY_H_ 
#define TEXTBUDDY_H_

#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <fstream>

using namespace std;

class TextBuddy{
public:
	vector<string> getTextBuddyContent(){
		return TextBuddyContent;
	};

	vector<string> getTempTextBuddy(){
		return TempTextBuddy;
	};

	//These two functions perform reading/writing from/to the file using the vector TextBuddyContent
	//TextBuddyContent contains the current state of the file.
	void initialiseTextBuddyContent(string outputFile);
	void writeFile(vector<string> TextBuddyContent, string outputFile);

	//Print Error Messages for TextBuddy
	void printErrorNumberofCLP();
	void printErrorParameterFormat();
	void printErrorInvalidCommand();

	//Print Other Messages needed (repeatedly) in TextBuddy
	void printWelcomeMsg(string fileTobeOpened);
	void printCommandPrompt();

	//Print Messages after executing each function
	void printaddLineMsg(string input, string outputFile);
	void printdeleteLineMsg(string contentTobeDeleted, string outputFile);
	void printEmptyFileMsg(string outputFile);
	void printClearFileMsg(string outputFile);

	bool checkNumberofCLP(int argc);
	bool checkParameterFormat(string textfileName);

	void addLine(string lineToBeAdded);
	void deleteLine(int lineToBeDeleted);
	void displayfile(vector<string> TextBuddyContent);
	void clearFile(string outputFile);

	//For searchFile function: Change the input string to lower-case 
	string changeCasetoLower(string input);
	void searchFile(string keyWord);
	
	//For sortFile function: Check if the two input strings have same case
	static bool TextBuddy::caselessCompare(string const& lhsIn, string const& rhsIn);
	void sortFile();

	void processCommand(string command, string outputFile);
	void performTextBuddy(string outputFile);

	int main(int argc, string argv);

	

private:
	vector<string> TextBuddyContent;
	
	//For searchFile function: a TempTextBuddy vector that contains all the wanted  search results
	vector<string> TempTextBuddy;
};
#endif