#ifndef CYBERSECURITY_H
#define CYBERSECURITY_H
#include <algorithm>
#include <iostream>
#include <sstream>
#include "TeamMenu.h"
#include "TeamController.h"
#include "../Assets/Application.h"
using namespace std;

class Cybersecurity: public TeamMenu {
  private:
    static vector<shared_ptr<Application>> cyberAppVec;
  public:
    Cybersecurity() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;

    static vector<shared_ptr<Application>>& getCyberAppVecW();
    const vector<shared_ptr<Application>>& getCyberAppVecR();
};



#endif //CYBERSECURITY_H
