//Liu Gantian 
//A0113555L
//CE1
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

//print the error message when the number of CLP passed into the fuction is not 2
void printErrorNumberofCLP(){
	cout << endl << "Wrong Number of Command Line Parameters! Please enter 2 parameters." << endl << endl;
}

//print the error message when the textfile is of a wrong format
void printErrorParameterFormat(){
	cout << endl << "Please enter a .txt file!" << endl << endl;
}

//print the Welcome Message when commencing TextBuddy
//function is called after checking for no. of CLP and output file format
void printWelcomeMsg(string fileTobeOpened){
	cout << endl << "Welcome to TextBuddy. " << fileTobeOpened << " is ready for use" << endl << endl;
}

//print line to prompt user for input
void printCommandPrompt(){
	cout << "command: ";
}

//print error message when the user key in an invalid command
void printErrorInvalidCommand(){
	cout << endl << "Command Invalid! >.<" << endl <<endl;
}

//function called inside addLine function
//message only printed after adding the line successfully
void printaddLineMsg(string input, string outputFile){
	cout << endl << "added to " << outputFile << ": \"" << input << "\"" << endl << endl;
}

//function called inside deleteLine function
//message only printed after deleting the respective line successfully
void printdeleteLineMsg(string contentTobeDeleted, string outputFile){
	cout << endl << "deleted from " << outputFile << ": \"" << contentTobeDeleted << "\"" << endl << endl;
}

//function called inside the display function
//if the output file is empty, the message is printed
void printEmptyFileMsg(string outputFile){
	cout << endl << outputFile << " is empty" << endl;
}

//function called inside the clearFile function
//message is printed after erasing the file content
void printClearFileMsg(string outputFile){
	cout << endl << "all content deleted from " << outputFile << endl << endl;
}

//the number of parameters is passed inside the function (argc)
//check if the number of parameters is not 2, return false
bool checkNumberofCLP(int argc){
	if (argc == 2){
		return true;
	}
	else{
		return false;
	}
}

//the name of the outputFile is passed inside to check if it is of the .txt format
//use string as a parameter
//value returned is a boolean value
bool checkParameterFormat(string textfileName){
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
void addLine(string outputFile){
	string temp;
	string input;
	getline(cin, temp);
	input = temp.substr(1);
	ofstream writeFile(outputFile, ios::app);
	writeFile << input << endl;
	writeFile.close();
	printaddLineMsg(input, outputFile);
}

//this function performs deleting specific lines to the outputFile
//takes string outputFile name as the parameter
//using ifstream and ofstream to manipulate the outputFile
//print a message when deleting line is done
void deleteLine(string outputFile){
	int lineNumbertobeDeleted;
	cin >> lineNumbertobeDeleted;
	ifstream readFile(outputFile);
	vector<string> tempList;
	string tempStorage;
	while (getline(readFile, tempStorage)){
		tempList.push_back(tempStorage);
	}
	printdeleteLineMsg(tempList[lineNumbertobeDeleted - 1], outputFile);
	tempList.erase(tempList.begin() + lineNumbertobeDeleted - 1);
	ofstream writeFile(outputFile);
	while (!tempList.empty()){
		writeFile << tempList[0] << endl;
		tempList.erase(tempList.begin());
	}
	readFile.close();
	writeFile.close();
}

////this function performs displaying all content inside the file
//takes string outputFile name as the parameter
//using ifstream and ofstream to manipulate the outputFile
//print a message when the ouput file is empty
void displayfile(string outputFile){
	ifstream readFile(outputFile);
	string tempStorage;
	int i = 0;
	while (getline(readFile, tempStorage)){
		i++;
		cout << endl << i <<". "<< tempStorage << endl;
	}
	if (i == 0) {
		printEmptyFileMsg(outputFile);
	}
	cout << endl;
	readFile.close();
}

//this function performs clearing all the content inside the outputFile
//takes string outputFile name as the parameter
//using ifstream and ofstream to manipulate the outputFile
//print a message when clearing is done
void clearFile(string outputFile){
	ofstream clearContent;
	clearContent.open(outputFile);
	clearContent.close();
	printClearFileMsg(outputFile);
}

//this function is called by performTextBuddy
//four different commands will call four different fuctions 
//error message would be printed if the input command is invalid
void processCommand(string command, string outputFile){
	if (command == "add"){
		addLine(outputFile);
	}
	else if (command == "delete"){
		deleteLine(outputFile);
	}
	else if (command == "display"){
		displayfile(outputFile);
	}
	else if (command == "clear"){
		clearFile(outputFile);
	}
	else{
		printErrorInvalidCommand();
	}
}

//this function is called after checking for the number of CLP and output file format
//use the outputFile name as the parameter
//function will do nothing if command is "exit"
void performTextBuddy(string outputFile){
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
int main(int argc, char* argv[]){

	if (!checkNumberofCLP(argc)){
		printErrorNumberofCLP();
	}
	else if (!checkParameterFormat(argv[1])){
		printErrorParameterFormat();
	}
	else{
		for (int i = 0; i < 10; i++){
			cout << i << endl;
		}
		printWelcomeMsg(argv[1]);
		printCommandPrompt();
		performTextBuddy(argv[1]); 
	}
	system("pause");
	return 0;
}
