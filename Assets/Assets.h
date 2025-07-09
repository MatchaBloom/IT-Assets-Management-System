#ifndef ASSETS_H
#define ASSETS_H
#include <algorithm>
#include <iostream>
using namespace std;

enum teamNameEnum {Analytics, Cybersecurity, Engineering, Infrastructure, Support};
enum assetsEnvirontment {PROD, DEV, QA};

class Assets {
    protected:
      teamNameEnum teamNameOwner;
      assetsEnvirontment environment;
    public:
      Assets();
      Assets(teamNameEnum owner, assetsEnvirontment env);
      virtual ~Assets();
      virtual void display() = 0;
};



#endif //ASSETS_H
