#ifndef ENGINEERING_H
#define ENGINEERING_H
#include <algorithm>
#include <iostream>
#include <sstream>
#include "TeamMenu.h"
#include "TeamController.h"
#include "../Assets/Application.h"
using namespace std;

class Engineering: public TeamMenu {
  private:
    static vector<shared_ptr<Application>> engineeringAppVec;
  public:
    Engineering() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;

    static vector<shared_ptr<Application>>& getEngAppVecW();
    const vector<shared_ptr<Application>>& getEngAppVecR();
};



#endif //ENGINEERING_H
