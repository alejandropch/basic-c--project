
#include "App.hpp"

int main()
{
  App app;

  // if you wanna add an additional question on compilation time, just uncomment this out

  // int answer = 2;
  // vector<string> options;
  // options = {"apple", "lettuce", "pear"};
  // string statement = "Select the one is a vegetable";
  // app.setQuestion(idiom,1,"choose", statement, options, answer);

  //  put "fr" to load the french questions, "en" for the english one
  string idiom = "en";

  // tale number you wanna read
  int tale = 1;
  app.start(idiom, tale);
}