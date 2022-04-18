#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <regex>
#include <sstream>
#include <iomanip>

using namespace std;

ifstream &goToQuestion(ifstream &myFile, unsigned int line)
{
  myFile.seekg(ios::beg);
  for (size_t i = 0; i < line - 1; i++)
  {
    myFile.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  return myFile;
}

ifstream &getNumberOfApp(ifstream &myFile, int &totalApp)
{
  string line = "";
  regex questionNEx{"[1-9]."};
  int number = 0;
  while (getline(myFile, line))
  {
    if (regex_search(line, questionNEx))
    {
      number++;
    }
  }
  totalApp = number;
  myFile.clear();
  myFile.seekg(0, ios::beg);

  return myFile;
}

auto split = [](const string &s, char delim)
{
  vector<string> result;
  stringstream ss(s);
  string item;

  while (getline(ss, item, delim))
  {
    result.push_back(item);
  }

  return result;
};