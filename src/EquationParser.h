#ifndef EQUATIONPARSER_H
#define EQUATIONPARSER_H

#include <string>
#include <vector>

class EquationParser
{
    public:
        void setEquationString(std::string s);
        std::string getEquationString();
        int parseForX(int);
        int parseForXY(int, int);
        std::vector<std::string> split();

    protected:

    private:
        std::string eq;

        int eval(std::string, int);
        int eval(std::string, int, int);

};

#endif // EQUATIONPARSER_H
