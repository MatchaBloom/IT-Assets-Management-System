#ifndef SUPPORT_H
#define SUPPORT_H
#include <algorithm>
#include <iostream>
#include <sstream>
#include "TeamMenu.h"
#include "TeamController.h"
#include "../Assets/Application.h"
#include "ITeamAssetProvider.h"
using namespace std;

class Support: public TeamMenu, public ITeamAssetProvider {
  private:
    static vector<shared_ptr<Application>> supportAppVec;
    string fileName = "../txtFileHolder/supportApp.txt";
  public:
    Support() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;

    static vector<shared_ptr<Application>>& getSupportAppVecW();
    const vector<shared_ptr<Application>>& getSupportAppVecR();

    vector<shared_ptr<Application>>& getTeamApps() override;
    const string& getTeamFileName() override;
    const string& getTeamName() override;

    bool canRemoveServer() override;
    bool canRemoveApplication() override;
};



#endif //SUPPORT_H
