//
/*
Program:    Math TutorV5
Programmers:Onalenna Mosadi Isaiah Guilliatt
Date:       11/08/20
Version:    5
GitHub:     https://github.com/onmosa01/MathTutorV5
Description:  The functions for the math tutor
*/
#include <iostream> // for cout and cin, and plus left and right alignment
#include <cctype>   // to lower?

#include <cstdlib>  // to generate random numbers
#include <string>   // needed to use string
#include <limits>   // needed for number validation
#include <vector>   // needed to use vectors
#include <iomanip>  // need for setw
#include <fstream>

#include <stdexcept>


using namespace std;

const int LEVEL_CHANGE_RANGE = 10;


/******************************************************************************************************
 Displays Joke
*******************************************************************************************************/
void DisplayJoke() {
    int jokeType = (rand() % 4) + 1;
    switch (jokeType) {
        //Switch that adds extra fancy amounts of UI, makes it semi random with each login
        case 1: //adds a switch that adds a random set of jokes to make the UI feel fresher
            cout <<
                    "****************************************************************************************************"
                    << endl;
            cout << "Have you ever noticed what's odd? Every other number!!" << endl;
            cout << "What do mathematicians do after it snows? They make snow angles!!" << endl;
            cout << "Which tool is best for math? Multi-pliers!!" << endl;
            cout << "Swimmers love one kind of math more than others, what is it? Dive-ision!!" << endl;
            cout <<
                    "****************************************************************************************************"
                    << endl;
            break;
        case 2:
            cout <<
                    "****************************************************************************************************"
                    << endl;
            cout << "Once there was a hen who counted her own eggs. She was a mathemachicken!!" << endl;
            cout << "Why was six afraid of seven? Because seven, eight, nine!!" << endl;
            cout << "Why can't two 4's go eat lunch? They already 8!!" << endl;
            cout << "What does the moon and a dollar have in common? They both have 4 quarters!!" << endl;
            cout <<
                    "****************************************************************************************************"
                    << endl;
            break;
        case 3:
            cout <<
                    "****************************************************************************************************"
                    << endl;
            cout << "Why's 69 afraid of 70? Because 71!!" << endl;
            cout << "Who's in charge in a pencil case? The ruler!!" << endl;
            cout << "Why can't your nose grow to be 12 inches long? Because then it would be a foot!!" << endl;
            cout << "Which numbers just won't sit still?? Roamin' numbers" << endl;
            cout <<
                    "****************************************************************************************************"
                    << endl;
            break;
        case 4:
            cout <<
                    "****************************************************************************************************"
                    << endl;
            cout << "What did 0 say to 8? Nice belt!!" << endl;
            cout << "How do you make time fly? Throw a clock out the window!!" << endl;
            cout << "If you're ever in a cold room, go to the corner. It's 90 degrees!!" << endl;
            cout << "Why did the girl always wear glasses when doing math? It improved her di-vision!!" << endl;
            cout <<
                    "****************************************************************************************************"
                    << endl;
            break;
        default:
            cout <<
                    "****************************************************************************************************"
                    << endl;
            cout << "What's the best way to get a math tutor? An add!!" << endl;
            cout << "Do you see that circle over there? He's really smart. He has 360 degrees!!" << endl;
            cout << "What is a math teacher's favorite tree? Geometry!!" << endl;
            cout << "Why are obtuse and acute angles always sad? They're never right!!" << endl;
            cout <<
                    "****************************************************************************************************"
                    << endl;
            break;
    }
    return;
}

/******************************************************************************************************
 DisplayGameIntro
*******************************************************************************************************/

void DisplayGameIntro() {
    cout <<
            "************************************************************************************************************************"
            << endl;
    cout << "                                   __        _____  _   _ ____  _____ ____    _" << endl;
    cout << "                                   "
            "\\ \\      / / _ \\| \\ | |  _ \\| ____|  _ \\  | |" << endl;
    cout << "                                    \\ \\ /\\ / / | | |  \\| | | | |  _| | |_) | | |" << endl;
    cout << "                                     \\ V  V /| |_| | |\\  | |_| | |___|  _ <  |_|" << endl;
    cout << "                                      \\_/\\_/  \\___/|_| \\_|____/|_____|_| \\_\\ (_)" << endl;
    cout << endl;
    cout <<
            "************************************************************************************************************************"
            << endl;
    cout <<
            "*                                              Winter Wonderland Math Tutor                                            *"
            << endl;
    cout <<
            "************************************************************************************************************************"
            << endl;
    return;
}


/****************************************************************************************************************
 GetUserName and welcome to the program
****************************************************************************************************************/

string GetUserName() {
    string userName = "?";

    cout << "Please enter your name: ";
    getline(cin, userName); // This is is for spacing in names
    cout << "Hello " << userName << ". Thank you for choosing our Silly Simple Math Tutor!" << endl;
    return userName;
}


/****************************************************************************************************************
 Get Numeric Value
****************************************************************************************************************/

int GetNumericValue() {
    int userNum = 0;

    while (!(cin >> userNum)) {
        //loop to guarantee a numeric answer
        cin.clear(); //clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //ignore the max input up to '\n'
        cout << endl << "Invalid input!" << endl;
        cout << "Please enter a number: ";
    } //end of number validation

    return userNum;
}


/****************************************************************************************************************
  8GenerateRandomQuestion
****************************************************************************************************************/

vector<int> mathGen(int currentLevel) {
    int leftNum = 0;
    int rightNum = 0;
    int questionType = 0;
    enum mathType { MT_ADD, MT_SUB, MT_MUL, MT_DIV };
    char mathSymbol = '?';
    int correctAnswer = 0;
    int tempNum = 0;
    int currentRange = 10;

    questionType = static_cast<mathType>(rand() % 4);

    //number randomization so you can get bigger numbers as you go on
    leftNum = rand() % (currentLevel* 10) + 1;
    rightNum = rand() % currentRange + 1;
    //randomize Numbers


    //switch to separate the different maths depending on the math type
    switch (questionType) {
        case MT_ADD: {
            //Addition
            mathSymbol = '+';
            correctAnswer = leftNum + rightNum;
            break;
        } //end of mathType_ADD

        case MT_SUB: {
            //Subtraction
            mathSymbol = '-';
            //if statement to check if we need to swap the two number so it is always positive
            if (leftNum < rightNum) {
                tempNum = leftNum;
                leftNum = rightNum;
                rightNum = tempNum;
            }
            correctAnswer = leftNum - rightNum;
            break;
        } //end of mathType_SUB

        case MT_MUL: {
            //Multiplication
            mathSymbol = '*';
            correctAnswer = leftNum * rightNum;
            break;
        } //end of mathType_DIV

        case MT_DIV: {
            //Division
            mathSymbol = 246;
            leftNum *= rightNum;
            correctAnswer = leftNum / rightNum;
            break;
        } //end of mathType_MUL

        default: {
            cout << "Math type generation error, please contact Jason or Jayden for assistance" << endl;
            exit(-1);
        } //default for errors from mathType
    } //end of switch
    return  {{currentLevel, leftNum, mathSymbol, rightNum, correctAnswer}};
}

// AskToPlayAgain
/****************************************************************************************************************
 Ask to  play again
****************************************************************************************************************/
string YesNoQuestion(string question ) {
   string userInput = "?";

    while (true) {
        cout << question;
        getline(cin, userInput);

        //to lowercase the user's input
        for (int i = 0; i < userInput.size(); i++) {
            userInput.at(i) = tolower(userInput.at(i));
        } //end of lower case loop

        if (userInput == "y" || userInput == "yes" || userInput == "n" || userInput == "no") {
            break;
        } else {
            cout << "Invalid input, please try again..." << endl;
            cout << endl;
        } //end of if yes/no
    } //end of yes/no validation while loop

    return userInput;
}

// DisplaySummaryReport
/****************************************************************************************************************
 Displays the summary report
 -display in order of usage
****************************************************************************************************************/
void DisplaySummaryReport(const vector<vector<int> > &questions, int maxAttempts) {
    char mathSymbol = '?';
    int leftNum = 0;
    int rightNum = 0;
    int correctAnswer = 0; //is updated to hold the correct answer value for comparison

    enum mathType { MT_ADD, MT_SUB, MT_MUL, MT_DIV };

    int totalCorrect = 0;
    int totalIncorrect = 0;
    int numAttempts = 0;
    int totalAttempts = 0;
    int currentLevel = 1;

    totalCorrect = 0;
    totalIncorrect = 0;

    cout << ":::::::::::::::::::::::::::::::::::::" << endl;
    cout << "          Summary  Report            " << endl;
    cout << ":::::::::::::::::::::::::::::::::::::" << endl;
    cout << "Level        Question        Attempts" << endl;
    cout << "-------    ------------    ----------" << endl;

    for (int i = 1; i < questions.size(); i++) {
        //pull the current row's data ouut into more readable variables
        currentLevel = questions.at(i).at(0);
        leftNum = questions.at(i).at(1);
        mathSymbol = static_cast<char>(questions.at(i).at(2));
        rightNum = questions.at(i).at(3);
        correctAnswer = questions.at(i).at(4);
        numAttempts = questions.at(i).at(5);

        //This displays the numbers in the summary
        cout << " " << setw(5) << left << currentLevel << "  | ";
        cout << setw(3) << left << leftNum;
        cout << setw(1) << right << mathSymbol;
        cout << setw(3) << right << rightNum;
        cout << " = " << setw(5) << left << correctAnswer;

        // displays how many attempts
        if (numAttempts != 0 && numAttempts <= maxAttempts) {
            cout << setw(5) << right << numAttempts;
            totalCorrect++;
        } else {
            cout << "Incorrect";
            totalIncorrect++;
        }

        cout << endl;
        totalAttempts += numAttempts;
    } //
    totalAttempts = totalCorrect + totalIncorrect;

    cout << "_____________________________________" << endl;

    cout << "Total Questions:" << setw(5) << right << totalIncorrect + totalCorrect << endl;
    cout << "Total Correct  :" << setw(5) << totalCorrect << endl;
    cout << "Total Incorrect:" << setw(5) << totalIncorrect << endl;
    cout << "Average Correct:" << setw(5) << (totalCorrect * 100) / totalAttempts << "%" << endl;
    cout << endl;

    return;
}

// GiveThreeAttempts
/****************************************************************************************
Give the attempts
***************************************************************************************/
bool giveUserAttempts(string userName, vector<int> &row,int maxAttempts) {

    char mathSymbol =static_cast<char>(row.at(2));
    int mathLevel = row.at(0);
    int leftNum = row.at(1);
    int rightNum = row.at(3);
    int correctAnswer = row.at(4); //is updated to hold the correct answer value for comparison
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int numAttempts = 0;
    bool isCorrect= false;
    int userNum = 0;

    for (int i = 1; i <= maxAttempts; i++) {
        userNum = GetNumericValue();
        //correct answer check
        if (userNum == correctAnswer) {
            isCorrect = true;
            //User gets the question right
            //  add num attempts to end of row
            row.push_back(numAttempts);
            cout << endl << "Congrats!! That was the correct answer." << endl;
            cout << endl;
            totalCorrect++;
            break;
        } else {
            if (userNum != correctAnswer && i == maxAttempts) {
                //User gets the question wrong and is out of attempts
                //add error value 0 to end of row, using push_back()
                numAttempts++;
                row.push_back(numAttempts);
                cout << endl<< "That was the wrong answer." << endl;
                cout << "You've ran out of attempts." << endl;
                cout << endl;
                totalIncorrect++;
            } else {
                //User gets the question wrong
                numAttempts++;
                cout << endl << "That was the wrong answer, you have " << (maxAttempts - i) <<
                        " attempts left." << endl;
                cout << "What is " << leftNum << " " << mathSymbol << " " << rightNum << "?" << endl;
                totalIncorrect++;
            }
        }
        //end of correct answer check
    } //end of for loop
    return isCorrect;
}

/****************************************************************************************
Test for level up and down
***************************************************************************************/
int checkForLevelChange (int totalCorrect,int totalIncorrect,int currentLevel) {
    int currentRange = currentLevel*LEVEL_CHANGE_RANGE;
    int userInput=0;
    if (totalCorrect == 3) {
        //Level increase
        currentRange -=LEVEL_CHANGE_RANGE;
        currentLevel++;
        cout << "Congrats, you have proceeded to level " << currentLevel << endl;
        totalCorrect = 0;
        totalIncorrect = 0;
        cout << "Your numbers can range from 1 - " << currentRange << endl;
    } else if (totalIncorrect >= 3 && currentLevel > 1) {
        //Level decrease

        currentRange -= LEVEL_CHANGE_RANGE;
        currentLevel--;
        cout << "Oh, no you've dropped to level " << currentLevel << endl;
        cout << "Your numbers can range from 1 - " << currentRange << endl;
        totalCorrect = 0;
        totalIncorrect = 0;
    } else {
        //Tell current level for every other question

        cout << "You're current level is " << currentLevel << endl;
    } //end of level up if-else statement
    return totalCorrect + totalIncorrect; //uhuhuh
}

void SaveCurrentGame (string userName,const vector<vector<int> > &mathQuestions) {
    const string FILE_NAME = "mathtutor.txt";
    string userInput = "?";
    ofstream outFS;
    userInput = YesNoQuestion(userInput);

    if (userInput == "n" || userInput == "no") {
        cout << "Save Game cancelled";
        return;
    }else {
        cout << "Saving Game Please Wait!";
        outFS.open(FILE_NAME);
        if (!outFS.is_open()) {
            cout << "Unable to open file " << FILE_NAME << endl;
            throw runtime_error ("Unable to open file " + FILE_NAME);
        }
        for (int i = 0; i < mathQuestions.size(); i++) {
            outFS << mathQuestions[i][0] << " " << mathQuestions[i][1] << endl;


    }
        outFS.close();






    }


}