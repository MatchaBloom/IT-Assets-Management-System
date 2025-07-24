#ifndef SUPPORT_H
#define SUPPORT_H
#include <algorithm>
#include <iostream>
#include <sstream>
#include "TeamMenu.h"
#include "TeamController.h"
#include "../Assets/Application.h"
using namespace std;

class Support: public TeamMenu {
  private:
    static vector<shared_ptr<Application>> supportAppVec;
  public:
    Support() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;

    static vector<shared_ptr<Application>>& getSupportAppVecW();
    const vector<shared_ptr<Application>>& getSupportAppVecR();
};



#endif //SUPPORT_H
