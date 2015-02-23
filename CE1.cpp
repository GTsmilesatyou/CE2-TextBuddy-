//Liu Gantian 
//A0113555L
//CE2
#include "TextBuddy.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int requiredNumberofParameters = 2;

void TextBuddy::initialiseTextBuddyContent(string outputFile){
	ifstream readFile(outputFile);
	string tempStorage;
	while (getline(readFile, tempStorage)){
		TextBuddyContent.push_back(tempStorage);
	}
	readFile.close();
};

void TextBuddy::writeFile(vector<string> TextBuddyContent, string outputFile){
	ofstream writeFile(outputFile);
	for (int i = 0; i < TextBuddyContent.size(); i++){
		writeFile << TextBuddyContent[i] << endl;
	}
	writeFile.close();
}

//print error message when the number of CLP passed into the fuction is not the requiredNumberofParameters
void TextBuddy::printErrorNumberofCLP(){
	cout << endl << "Wrong Number of Command Line Parameters! Please enter 2 parameters." << endl << endl;
}

//print error message when the textfile is of a wrong format
void TextBuddy::printErrorParameterFormat(){
	cout << endl << "Please enter a .txt file!" << endl << endl;
}

//print error message when the user key in an invalid command
void TextBuddy::printErrorInvalidCommand(){
	cout << endl << "Command Invalid! >.<" << endl << endl;
}

//print the Welcome Message when commencing TextBuddy
void TextBuddy::printWelcomeMsg(string fileTobeOpened){
	cout << endl << "Welcome to TextBuddy. " << fileTobeOpened << " is ready for use" << endl << endl;
}

//print line to prompt user for input
void TextBuddy::printCommandPrompt(){
	cout << "command: ";
}

//function called inside addLine function
void TextBuddy::printaddLineMsg(string input, string outputFile){
	cout << endl << "added to " << outputFile << ": \"" << input << "\"" << endl << endl;
}

//function called inside deleteLine function
void TextBuddy::printdeleteLineMsg(string contentTobeDeleted, string outputFile){
	cout << endl << "deleted from " << outputFile << ": \"" << contentTobeDeleted << "\"" << endl << endl;
}

//if the output file is empty, the message is printed
void TextBuddy::printEmptyFileMsg(string outputFile){
	cout << endl << outputFile << " is empty" << endl;
}

//message is printed after erasing the file content
void TextBuddy::printClearFileMsg(string outputFile){
	cout << endl << "all content deleted from " << outputFile << endl << endl;
}

//the number of parameters is passed inside the function (argc)
//check if the number of parameters is not 2, return false
bool TextBuddy::checkNumberofCLP(int argc){
	if (argc == requiredNumberofParameters){
		return true;
	}
	else{
		return false;
	}
}

//the name of the outputFile is passed inside to check if it is of the .txt format
//use string as a parameter
//value returned is a boolean value
bool TextBuddy::checkParameterFormat(string textfileName){
	int textfileLength = textfileName.size();
	string format = textfileName.substr(textfileLength - 4, textfileLength);
	if (format == ".txt"){
		return true;
	}
	else{
		return false;
	}
}


//this function performs adding new lines to the outputFile
//takes string outputFile name as the parameter
//using ifstream and ofstream to manipulate the outputFile
//print a message when adding line is done
void TextBuddy::addLine(string lineToBeAdded){
	TextBuddyContent.push_back(lineToBeAdded);
}

//this function performs deleting specific lines to the outputFile
//takes string outputFile name as the parameter
//using ifstream and ofstream to manipulate the outputFile
//print a message when deleting line is done
void TextBuddy::deleteLine(int lineToBeDeleted){
	TextBuddyContent.erase(TextBuddyContent.begin() + lineToBeDeleted - 1);
}

////this function performs displaying all content inside the file
//takes string outputFile name as the parameter
//using ifstream and ofstream to manipulate the outputFile
//print a message when the ouput file is empty
void TextBuddy::displayfile(vector<string> TextBuddyContent){
	for (int i = 0; i < TextBuddyContent.size(); i++){
		cout << i+1<<". "<<TextBuddyContent[i] << endl;
	}
}

//this function performs clearing all the content inside the outputFile
//takes string outputFile name as the parameter
//using ifstream and ofstream to manipulate the outputFile
//print a message when clearing is done
void TextBuddy::clearFile(string outputFile){
	ofstream clearContent;
	clearContent.open(outputFile);
	clearContent.close();
	TextBuddyContent.clear();
	printClearFileMsg(outputFile);
}

void TextBuddy::searchFile(vector<string> TextBuddyContent){

}

void TextBuddy::sortFile(){
	sort(TextBuddyContent.begin(), TextBuddyContent.end());

}

//this function is called by performTextBuddy
//four different commands will call four different fuctions 
//error message would be printed if the input command is invalid
void TextBuddy::processCommand(string command, string outputFile){
	if (command == "add"){
		string temp;
		string lineToBeAdded;
		getline(cin, temp);
		lineToBeAdded = temp.substr(1);
		addLine(lineToBeAdded);
		writeFile(TextBuddyContent, outputFile);
		printaddLineMsg(lineToBeAdded, outputFile);
	}
	else if (command == "delete"){
		int lineNumbertobeDeleted;
		cin >> lineNumbertobeDeleted;
		printdeleteLineMsg(TextBuddyContent[lineNumbertobeDeleted - 1], outputFile);
		deleteLine(lineNumbertobeDeleted);
		writeFile(TextBuddyContent, outputFile);
	}
	else if (command == "display"){
		if (TextBuddyContent.empty()){
			printEmptyFileMsg(outputFile);
		}
		else{
			displayfile(TextBuddyContent);
		}
	}
	else if (command == "clear"){
		clearFile(outputFile);
	}
	else if (command == "search"){
		searchFile(TextBuddyContent);
	}
	else if (command == "sort"){
		sortFile();
		writeFile(TextBuddyContent, outputFile);
		displayfile(TextBuddyContent);
	}
	else{
		printErrorInvalidCommand();
	}
}

//this function is called after checking for the number of CLP and output file format
//use the outputFile name as the parameter
//function will do nothing if command is "exit"
void TextBuddy::performTextBuddy(string outputFile){
	string command;
	while (cin >> command){
		if (command == "exit"){
			return;
		}
		else{
			processCommand(command, outputFile);
			printCommandPrompt();
		}
	}
}

//main function
int TextBuddy::main(int argc, string argv){

	if (!checkNumberofCLP(argc)){
		printErrorNumberofCLP();
	}
	else if (!checkParameterFormat(argv)){
		printErrorParameterFormat();
	}
	else{
		printWelcomeMsg(argv);
		printCommandPrompt();
		initialiseTextBuddyContent(argv);
		performTextBuddy(argv); 
	}
	return 0;
}
