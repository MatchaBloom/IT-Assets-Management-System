#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H
#include <algorithm>
#include <iostream>
#include "TeamMenu.h"
#include "TeamController.h"
#include "Analytics.h"
#include "Cybersecurity.h"
#include "Engineering.h"
#include "Support.h"
#include "../Assets/Server.h"
#include "../Assets/Assets.h"
#include "../Assets/Application.h"
#include "../Assets/AssetController.h"
#include "../Assets/AssetManager.h"
#include "ITeamAssetProvider.h"
using namespace std;

class Infrastructure: public TeamMenu, public ITeamAssetProvider {
  private:
    static vector<shared_ptr<Application>> infraAppVec;
    string fileName = "../txtFileHolder/infrastructureApp.txt";

  public:
    //Inheritance
    Infrastructure() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;

    void listOtherTeamAssets(const string& teamName);
    void listAllTeamAssets();

    static vector<shared_ptr<Application>>& getInfrastructureAppVecW();
    const vector<shared_ptr<Application>>& getInfrastructureAppVecR();

    vector<shared_ptr<Application>>& getTeamApps() override;
    const string& getTeamFileName() override;
    const string& getTeamName() override;

    bool canRemoveServer() override;
    bool canRemoveApplication() override;

};



#endif //INFRASTRUCTURE_H
