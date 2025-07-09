#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H
#include <algorithm>
#include <iostream>
#include "TeamMenu.h"
#include "../Assets/Server"
using namespace std;

class Infrastructure: public TeamMenu {
  protected:

  public:
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;
    void exit() override;
};



#endif //INFRASTRUCTURE_H
