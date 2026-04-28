#include "Question.h"


Question::Question() {
    questionText = "";
    for (int i = 0; i < 4; i++)
        options[i] = "";
    correctOption = 0;
}

Question::Question(string q, string option1, string option2, string option3, string option4, int correct) {
    questionText = q;
    options[0] = option1;
    options[1] = option2;
    options[2] = option3;
    options[3] = option4;
    correctOption = correct;
}

string Question::getQuestion() {
    return questionText;
}

string Question::getOption(int index) {
    if (index >= 0 && index < 4)
        return options[index];
    return "";
}

int Question::getCorrectAnswer() {
    return correctOption;
}

void Question::setQuestion(string q) {
    questionText = q;
}

void Question::setOption(int index, string opt) {
    if (index >= 0 && index < 4)
        options[index] = opt;
}

void Question::setCorrectAnswer(int ans) {
    correctOption = ans;
}