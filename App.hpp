
#include "utils.hpp"
#define LINES_PER_QUESTION 4
#define FIRST_QUESTION 1
class App
{
public:
  App()
  {
    // this value is gonna be important if you create a question in time execution
    statements["choose"] = "Choose the correct option";
  };

  void setQuestion(int key, string statement, string question, vector<string> options, int answer)
  {
    ofstream setMyFile("questions.en.txt", ios::app);

    // attempt to open the questions.txt
    if (setMyFile.is_open())
    {
      // writing the statement
      setMyFile << key << ". " << statements[statement] << "\n";
      // writing the question
      setMyFile << question << "\n";
      for (int i = 0; i < options.size(); i++)
      {
        // writing the options, and separate them with the commas
        setMyFile << options[i] << ",";
      }
      // writing the answer
      setMyFile << "\n"
                << "answ)" << answer;
    }
    setMyFile.close();
  }

  void start(string idiom)
  {

    idiom == "en" ? myfile.open("questions.en.txt") : myfile.open("questions.fr.txt");

    if (myfile.is_open())
    {
      getNumberOfApp(myfile, totalQuestions);

      return getQuestion(FIRST_QUESTION);
    }
    else
    {
      cout << "error on opening the file";
      return;
    }
  }

  void getQuestion(int questionWanted)
  {

    string line = "";
    regex optionsEx{","};
    regex answerEx{"answ."};
    vector<string> options;
    int i = 0;
    currentQuestion = questionWanted;

    // first you need to go to your specific question number
    // " -1 " because the first question starts at line 0, son the second one starts on line 4... and so on...
    int lineNumber = (questionWanted - 1) * LINES_PER_QUESTION;
    if (lineNumber != 0)
      goToQuestion(myfile, lineNumber);

    while (getline(myfile, line) && i < 5)
    {
      i++;

      if (regex_search(line, optionsEx))
      {

        options = split(line, ',');

        continue;
      }
      // looking for the answer
      if (regex_search(line, answerEx))
      {
        size_t pos = line.find(")");
        answer = stoi(line.substr(pos + 1));
        continue;
      }

      // when i is 5, you will print the statement of the next question
      if (i != 5)
      {
        cout << line << endl;
      }
    }

    for (int i = 0; i < options.size(); i++)
    {
      cout << "\t" << i + 1 << ") " << options[i] << "\t";
    }
    cout << endl;

    return evaluate();
  }

  void userScore()
  {
    cout << "The user score is:\n";
    cout << "Total number of correct answers: " << getNumberCorrectAnswers() << endl;
    cout << "Percentage of correct answers: " << fixed << setprecision(2) << getPercentageCorrectAnswers() << "%" << endl;

    return;
  }

  void evaluate()
  {
    int toEvaluate = -1;

    cout << "choose your answer: ";
    cin >> toEvaluate;
    int nextQuestion = currentQuestion + 1;
    if (toEvaluate == answer)
    {
      correct++;
      cout << "great job!\n";
      // if all App all completed, program ends
    }
    else
    {
      cout << "You commit an error:(\n";
      cout << "The correct answer was: " << answer << "\n";
    }
    // this is just to separate questions between them
    cout << "\n\n";

    if (nextQuestion > totalQuestions)
    {
      // if all questions all completed, program ends

      myfile.close();
      return userScore();
    }

    return getQuestion(nextQuestion);
  }
  int getNumberCorrectAnswers()
  {
    return correct;
  }
  float getPercentageCorrectAnswers()
  {

    return ((double)correct / (double)totalQuestions) * 100;
  }
  ~App(){};

private:
  map<string, string> statements;
  int answer = -1;
  ifstream myfile;
  int currentQuestion = -1;
  int totalQuestions = -1;
  int correct = 0;
};