#ifndef ENGINEERING_H
#define ENGINEERING_H
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
#include "TeamMenu.h"

class Engineering: public TeamMenu {
    public:
        Engineering() = default;
        void addAssets() override;
        void listDataAssets() override;
        void updateAssets() override;
        void deleteAssets() override;
        void exit() override;
};



#endif //ENGINEERING_H
