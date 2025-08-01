#ifndef ENGINEERING_H
#define ENGINEERING_H
#include <algorithm>
#include <iostream>
#include <sstream>
#include "TeamMenu.h"
#include "TeamController.h"
#include "../Assets/Application.h"
#include "ITeamAssetProvider.h"
using namespace std;

class Engineering: public TeamMenu, public ITeamAssetProvider {
  private:
    static vector<shared_ptr<Application>> engineeringAppVec;
    string fileName = "../txtFileHolder/engineeringApp.txt";

  public:
    Engineering() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;

    static vector<shared_ptr<Application>>& getEngAppVecW();
    const vector<shared_ptr<Application>>& getEngAppVecR();

    vector<shared_ptr<Application>>& getTeamApps() override;
    const string& getTeamFileName() override;
    const string& getTeamName() override;

    bool canRemoveServer() override;
    bool canRemoveApplication() override;
};



#endif //ENGINEERING_H
