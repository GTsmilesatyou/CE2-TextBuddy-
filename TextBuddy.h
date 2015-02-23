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

	void initialiseTextBuddyContent(string outputFile);
	void writeFile(vector<string> TextBuddyContent, string outputFile);

	void printErrorNumberofCLP();
	void printErrorParameterFormat();
	void printErrorInvalidCommand();

	void printWelcomeMsg(string fileTobeOpened);
	void printCommandPrompt();

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
	void searchFile(vector<string> TextBuddyContent);
	void sortFile();

	void processCommand(string command, string outputFile);
	void performTextBuddy(string outputFile);

	int main(int argc, string argv);

	

private:
	vector<string> TextBuddyContent;
};
#endif