/*
Program:    Math TutorV5
Programmers:Onalenna Mosadi Isaiah Guilliatt
Date:       11/08/20
Version:    5
GitHub:     https://github.com/onmosa01/MathTutorV5
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