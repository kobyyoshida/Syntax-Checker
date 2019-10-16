//koby yoshida
#include <iostream>
#include <fstream>
#include "fileio.h"
using namespace std;

fileio::fileio(){

}

fileio::~fileio(){

}

void fileio::openFile(string filePath){
  in.open(filePath);
  if(!in){
    cerr << "File not found. " << endl;
    exit(EXIT_FAILURE);
  }
}

void fileio::closeFile(){
  in.close();
}
