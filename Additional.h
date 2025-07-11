#ifndef ADDITIONAL_H
#define ADDITIONAL_H
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <ctime>
using namespace std;

class Additional {
public:
  Additional();
  ~Additional();
  static string lowerCaseMode(const string& s);
  static string dateTimeFormat();
};



#endif //ADDITIONAL_H
