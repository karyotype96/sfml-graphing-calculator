#include "EquationParser.h"

#include <iostream>
#include <string>
#include <sstream>

void EquationParser::setEquationString(std::string s){
    eq = s;
    for (int i = 0; i < eq.size(); i++){
        if (eq[i] == ' ') //remove all spaces
            eq.erase(i, 1);
    }
}

std::string EquationParser::getEquationString(){
    return eq;
}

int EquationParser::parseForX(int x){
    std::stringstream strBuffer;
}

int EquationParser::parseForXY(int x, int y){

}

int eval(std::string str, int x){

}

int eval(std::string str, int x, int y){

}

std::vector<std::string> EquationParser::split(){
    std::vector<std::string> toOutput; //we'll be getting a vector of all terms
    bool nextNegative = false;
    int leftParens = 0; //will be incremented every time a left parenthesis is detected
    int currentArgPos = 0; //position will be updated every time a new term is found
    std::string bufferString;

    for (int i = 0; i < eq.length(); i++){
        if (eq[i] == '(' || eq[i] == ')'){ //ignore arguments in parentheses - these will be managed recursively
            leftParens = (eq[i] == '(') ? leftParens + 1 : leftParens - 1;
            if (leftParens < 0){ //error - there should never be less left parens than right
                toOutput.clear();
                return toOutput;
            }
        }

        if ((eq[i] == '+' || eq[i] == '-') && leftParens == 0){ //split by + or -
            bufferString.append(nextNegative ? "-" : ""); //determine whether term is negative
            bufferString.append(eq.substr(currentArgPos, i - currentArgPos));
            currentArgPos = i + 1;
            toOutput.push_back(bufferString);
            bufferString.clear();
            nextNegative = (eq[i] == '-');
        }
        if ((eq[i] == 'x' || eq[i] == 'y') && i > 0){ //for ease, add * between coefficient and variable
            if (isdigit(eq[i-1]) || eq[i-1] == 'x' || eq[i-1] == 'y'){
                eq.insert(i, "*");
            }
        }
    }
    bufferString.append(nextNegative ? "-" : "");
    bufferString.append(eq.substr(currentArgPos, eq.size() - currentArgPos));
    toOutput.push_back(bufferString);

    return toOutput;
}
