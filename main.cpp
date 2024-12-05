#include <iostream> // for cout and cin, and plus left and right alignment
#include <cctype>   // to lower?
#include <ctime>    // seed the random
#include <cstdlib>  // to generate random numbers
#include <string>   // needed to use string
#include <limits>   // needed for number validation
#include <vector>   // needed to use vectors
#include <iomanip>  // need for setw

#include "math_tutor.h" // header file with prototypes

using namespace std;

/********************************************************************************************

Program:    Math TutorV5
Programmers:Onalenna Mosadi Isaiah Guilliatt
Date:       10/30/24
Version:    5
GitHub:     https://github.com/onmosa01/MathTutorV5


This program is a Math Quiz of sorts. The code is supposed to go on forever.
It will address you by name, and give you a randomly generated problem that
will increase in difficulty as you progress. There is a switch statement for
the different types of math with Division, Addition, Subtraction and
Multiplication all able to show up. You will be able to choose how many
attempts you get to answer the question. after you answer it will as you if
you want to do another question. After you say you don't want another question
it will display a report, showing every question, the correct answer, the level
the math was on, the number of attempts and

 *******************************************************************************************/
const int LEVEL_CHANGE_RANGE = 10;//deckares global varible for constatn interger for how much numbers increase on level up



/****************************************************************************************
 The Main portion of our code that allows it to run
***************************************************************************************/

int main() {

    bool isCorrect = false;

    string userName = "?";
    string userInput = "?";
    int maxAttempts = 3;
    int currentLevel = 1;
    int totalCorrect = 0;
    int totalIncorrect = 0;

    vector<vector<int> > questions; // Vector to store question details

    srand(time(0)); //seeding random numbers using system time

    // display program intro
    DisplayGameIntro();
    DisplayJoke();
    userName = GetUserName();


    //Random Joke sets

    //
    cout << "How many attempts would you like for each question?" << endl;
    // Loop until the user enters numeric data
    while (!(cin >> maxAttempts)) {
        cin.clear(); //clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //ignore the max input up to '\n'
        cout << "\tInvalid input!" << endl;
        cout << "\tPlease enter a number: ";
    } //end of max attempts number loop
    //beginning of the question loop
    do {
        vector<int> row=mathGen(currentLevel);
        cout << endl << "Alright " << userName << ", your question " << endl;
        cout << "What is " << row.at(1)/*leftnum*/ << " " << static_cast<char>(row.at(2))/*math symbol*/ << " " << row.at(3) /*right num*/<< "?" << endl;

        isCorrect = giveUserAttempts(userName, row,maxAttempts);
        questions.push_back(row);
        (isCorrect) ? totalCorrect++ : totalIncorrect++;

        checkForLevelChange (totalCorrect,totalIncorrect,currentLevel);

        getline(cin, userInput);
        //clearing newline from the input buffer
        userInput = AskToPlayAgain(userName);
    } while (userInput == "yes" || userInput == "y");
    //end of the question loop
    // CheckForLevelChange

    DisplaySummaryReport(questions, maxAttempts);

    cout << ":::::::::::::::::::::::::::::::::::::" << endl;

    // display summary report
    cout << "Thank you for choosing our Silly Simple Math Tutor!" << endl;
    cout << "Have a great day " << userName << endl;

    return 0;
} //testing