//koby Yoshida
#include <iostream>
#include <fstream>
#include "Syntax.h"
#include "syntaxGenStack.h"
#include "fileio.h"

using namespace std;

Syntax::Syntax(){

}

Syntax::~Syntax(){
  //delete(stack);
}

bool Syntax::checking(ifstream& file, syntaxGenStack<char>& stack){
  string line;
  currentLine = 0;
  while(getline(file,line)){//iterates thru file line by line
    currentLine++;

    for(int i = 0; i < line.size(); i++){//iterates thru the line char by char


      if(line[i]=='/'&& line[i+1]=='/'){
        break; //continue to the next line
      }
      if(line[i] == '[' || line[i]=='(' || line[i]=='{'){//if there is a beginning delimiter, add it to the stack
        stack.push(line[i]);
      }

      else if(line[i] == ']' || line[i]==')' || line[i]=='}'){//when there is a closing delimiter, check the stack for the beginning delimiter
        if(stack.isEmpty()){
          cout << "Error on line " << currentLine << "\nFound an extra "<< line[i] << endl; //closing delimiter with no opening delimiter
          return false;
        }
        if(stack.peek()=='('){
          if(line[i] != ')'){
            cout << "Error on line " << currentLine << "\nExpected ')' but found "<< line[i]<< endl;
            return false;
          }
        }
        if(stack.peek()=='['){//looking for beginning delimiters with no end
          if(line[i] != ']'){
            cout << "Error on line " << currentLine << "\nExpected ']' but found "<< line[i]<<endl;
            return false;
          }
        }
        if(stack.peek()=='{'){
          if(line[i] != '}'){
            cout << "Error on line " << currentLine <<  "\nExpected '}' but found "<< line[i]<< endl;
            return false;
          }
        }
        stack.pop();
      }
    }
  }//end read file loop
  bool end = stack.isEmpty();

  while(!stack.isEmpty()){ // when we have read through the whole file, if there is anything left in the stack
                      // it will print the leftover delimiters
    cout << "Unmatched " << stack.pop() << endl;
  }
  return end; // will return true if it passes all the checks for syntax errors
}
