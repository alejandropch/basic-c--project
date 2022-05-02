#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <regex>
#include <sstream>
#include <iomanip>

#define LINES_PER_QUESTION 4
#define FIRST_QUESTION 1
#define TOTAL_OPTIONS_SIZE 3

using namespace std;

template <typename T>
static inline T &trim(T &s)
{
  s.erase(s.begin(), find_if(s.begin(), s.end(), [](int c)
                             { return !isspace(c); }));
  return s;
}
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
  array<string, TOTAL_OPTIONS_SIZE> result;
  stringstream ss(s);
  string item;
  int i = 0;
  while (getline(ss, item, delim))
  {
    result[i] = item;
    i++;
  }

  return result;
};
