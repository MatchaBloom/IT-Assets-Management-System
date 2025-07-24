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
using namespace std;

class Infrastructure: public TeamMenu {
  private:
    static vector<shared_ptr<Application>> infraAppVec;

  public:
    //Inheritance
    Infrastructure() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;

    void listOtherTeamAssets(const string& teamName);
    void listAllTeamAssets();
};



#endif //INFRASTRUCTURE_H
