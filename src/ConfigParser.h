#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <iostream>

/**
    Things to parse:

    X-axis size
    Y-axis size

    X-axis increment size
    Y-axis increment size

    Draw resolution

    Axis color
    Line color
    Background color
*/

class ConfigParser
{
    public:
        ConfigParser();
        void configRead();

        double getXMAX();
        double getYMAX();
        double getXINC();
        double getYINC();
        double getRES();
        int getAXISCOLOR();
        int getLINECOLOR();
        int getBGCOLOR();

    protected:

    private:
        double xmax, ymax;
        double xinc, yinc;
        double drawRes;

        int axisColor, lineColor, bgColor;

        int colonPos(std::string);

        int getI(std::string);
        double getD(std::string);
};

#endif // CONFIGPARSER_H
