//koby Yoshida

#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

class fileio{
public:
  fileio();
  ~fileio();

  void openFile(string filePath);
  void closeFile();

  ifstream in;
};
#endif
