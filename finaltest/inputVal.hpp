#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP
#include <string>


void checkInt(int &input);
void checkInt(int &input, int min, int max);
void checkChar(char &input, std::string,std::string);
void checkPosInt(int &input);
void checkString(std::string &input);
void checkString(std::string &input, std::string, std::string);
void checkDouble(double &, double, double);
#endif
