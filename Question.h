#pragma once
#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

class Question {
    string questionText;
    string options[4];
    int correctOption;

public:
    Question();
    Question(string q, string option1, string option2, string option3, string option4, int correct);

    string getQuestion();
    string getOption(int index);
    int getCorrectAnswer();

    void setQuestion(string q);
    void setOption(int index, string opt);
    void setCorrectAnswer(int ans);
};

#endif

