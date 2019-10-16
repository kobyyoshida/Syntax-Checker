//Koby Yoshida
#include <iostream>
#include <fstream>
#include "Syntax.h"
#include "syntaxGenStack.h"
#include "fileio.h"

using namespace std;

int main(int argc, char **argv){

  string filePath;
  if (argc != 2) { //Checks for valid command line arguments and saves argument to filePath variable
    cerr << "Incorrect number of arguments." << endl;
    return 0;
  }
  else {
    filePath = argv[1];
  }

  syntaxGenStack<char> stack(100);
  Syntax checker;
  fileio io;

  while(true){
  //beginning of file input
  //ifstream in;
    io.openFile(filePath);
    bool check = checker.checking(io.in, stack);
    io.closeFile();
    if(check){
      cout << "Found no errors. " << endl;
  }


    char answer;
    //this part checks if you want to run another file
    cout << "Would you like to run another file? (Enter 'y' or 'n') " << endl;
    cin >> answer;
    if(answer == 'y'){
      cout << "Enter the name of your file. ";
      cin >> filePath;
    }
    else if (answer = 'n'){
      break;
    }
    else{
      cout << "Invalid entry. "<< endl;
      break;
    }
  }
  //4. report if the syntax is okay or if an error has occurred
  //done in checking
  //5. report the problem if there is one
  //done in checking
}
