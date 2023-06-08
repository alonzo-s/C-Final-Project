#ifndef HEADER_H
#define HEADER_H
#include "libraryClassDefined.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
#endif


void openFiles(ifstream &in, ofstream &out);
Library readFile(string &sLine, vector<string> &sParsed, ifstream &fin);
void writeFile(Library li, ofstream &fout);
void reportHead(ofstream &fout);
void bubbleSort(vector<Library> &l);
void writeFile(Library li, ofstream &outFile, string typ);