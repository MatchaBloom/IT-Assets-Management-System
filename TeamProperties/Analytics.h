#ifndef ANALYTICS_H
#define ANALYTICS_H
#include <algorithm>
#include <iostream>
#include <sstream>
#include "TeamMenu.h"
#include "TeamController.h"
#include "../Assets/Application.h"
#include "ITeamAssetProvider.h"

using namespace std;

class Analytics: public TeamMenu, public ITeamAssetProvider {
  private:
    static vector<shared_ptr<Application>> analyticsAppVec;
    string fileName = "../txtFileHolder/analyticsApp.txt";

  public:
    Analytics() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;

    static vector<shared_ptr<Application>>& getAnalyticsAppVecW();
    const vector<shared_ptr<Application>>& getAnalyticsAppVecR();

    vector<shared_ptr<Application>>& getTeamApps() override;
    const string& getTeamFileName() override;
    const string& getTeamName() override;

    bool canRemoveServer() override;
    bool canRemoveApplication() override;

};

#endif //ANALYTICS_H
