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

	vector<string> setTextBuddyContent(vector<string> TextBuddyContent, string outputFile){
		ifstream readFile(outputFile);
		string tempStorage;
		while (getline(readFile, tempStorage)){
			TextBuddyContent.push_back(tempStorage);
		}
		return TextBuddyContent;
	};

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

	void addLine(string outputFile);
	void deleteLine(string outputFile);
	void displayfile(string outputFile);
	void clearFile(string outputFile);
	void searchFile(string outputFile);
	void sortFile(string outputFile);

	void writeFile(vector<string> TextBuddyContent, string outputFile);


private:
	vector<string> TextBuddyContent;
};
#endif