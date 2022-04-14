
#include "App.hpp"

int main()
{
  App app;

  // if you wanna add an addiotional question on compilation time, just uncomment this out
  // int answer = 2;

  // vector<string> options;
  // options = {"apple", "lettuce", "pear"};
  // string statement = "Select the one is a vegetable";
  // app.setQuestion(1,"choose", statement, options, answer);
  app.start();
}