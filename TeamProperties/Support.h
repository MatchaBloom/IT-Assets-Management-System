#ifndef SUPPORT_H
#define SUPPORT_H
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
#include "TeamMenu.h"

class Support: public TeamMenu {
public:
    Support() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;
    void exit() override;
};



#endif //SUPPORT_H
