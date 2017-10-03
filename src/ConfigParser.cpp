#include "ConfigParser.h"

#include <iostream>
#include <fstream>
#include <sstream>

ConfigParser::ConfigParser()
{
    std::fstream config;
    std::string buf;
    config.open("calc.conf", std::fstream::out | std::fstream::in | std::fstream::app);
    if (config.is_open()){
        config.seekg(0, std::fstream::end);
        if (config.tellg() == 0){
            config << "X axis width: 10\n";
            config << "Y axis height: 10\n";
            config << "X axis increment: 1\n";
            config << "Y axis increment: 1\n";
            config << "Draw resolution: 100\n";
            config << "Axis color: 0000FF\n";
            config << "Line color: FFFFFF\n";
            config << "Background color: 000000\n";
        }
        config.close();
    }
}

void ConfigParser::configRead(){
    std::ifstream input;
    std::string buf;
    input.open("calc.conf");
    if (input.is_open()){ //read each value individually
        std::getline(input, buf);
        xmax = getD(buf);

        std::getline(input, buf);
        ymax = getD(buf);

        std::getline(input, buf);
        xinc = getD(buf);

        std::getline(input, buf);
        yinc = getD(buf);

        std::getline(input, buf);
        drawRes = getD(buf);

        std::getline(input, buf);
        axisColor = getI(buf);

        std::getline(input, buf);
        lineColor = getI(buf);

        std::getline(input, buf);
        bgColor = getI(buf);
    }
    input.close();
}

double ConfigParser::getXMAX(){
    return xmax;
}

double ConfigParser::getYMAX(){
    return ymax;
}

double ConfigParser::getXINC(){
    return xinc;
}

double ConfigParser::getYINC(){
    return yinc;
}

double ConfigParser::getRES(){
    return drawRes;
}

int ConfigParser::getAXISCOLOR(){
    return axisColor;
}

int ConfigParser::getLINECOLOR(){
    return lineColor;
}

int ConfigParser::getBGCOLOR(){
    return bgColor;
}

int ConfigParser::colonPos(std::string str){
    for (unsigned int i = 0; i < str.size(); i++){
        if (str[i] == ':')
            return i;
    }
    return -1;
}

int ConfigParser::getI(std::string str){
    int toOut;
    std::stringstream ss;

    int posBuf = colonPos(str) + 2;
    std::string buf = str.substr(posBuf, str.size() - posBuf);
    ss << buf;
    ss >> std::hex >> toOut;
    return toOut;
}

double ConfigParser::getD(std::string str){
    double toOut;
    std::stringstream ss;

    int posBuf = colonPos(str) + 2;
    std::string buf = str.substr(posBuf, str.size() - posBuf);
    ss << buf;
    ss >> toOut;
    return toOut;
}
