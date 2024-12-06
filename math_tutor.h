/*
Program:    Math TutorV6
Programmers:Onalenna Mosadi Conner Diers
Date:       12/06/24
Version:    6
GitHub:     https://github.com/ConnerDiers3117/MathTutor_6
Description:  Header File
*/

#ifndef MATH_TUTOR_H
#define MATH_TUTOR_H

#include<string>
#include<vector>

using namespace std;

void DisplayJoke();
void DisplayGameIntro();
string GetUserName();
int GetNumericValue();
vector<int> mathGen(int currentLevel);
string YesNoQuestion(string question);
void DisplaySummaryReport(const vector<vector<int> > &questions, int maxAttempts);
bool giveUserAttempts(string userName, vector<int> &row,int maxAttempts);
int checkForLevelChange (int totalCorrect,int totalIncorrect,int currentLevel);
void SaveCurrentGame (string userName, const vector<vector<int> > &mathQuestions);
void LoadPreviousGame (string userName, vector<vector<int> > &mathQuestions);


#endif //MATH_TUTOR_H