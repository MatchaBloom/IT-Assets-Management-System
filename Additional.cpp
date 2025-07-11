#include "Additional.h"
//Source: google AI overview
string Additional::lowerCaseMode(const string& s) {
    string result = s;
    for (char &c : result) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return result;
}

//source: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
string Additional::dateTimeFormat(){
  time_t now = time(0);
  char* dt = ctime(&now);
  return dt;
}