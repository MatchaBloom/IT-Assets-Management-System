#include <iostream>
#include <memory>

#include "TeamProperties/TeamMenu.h"
#include "TeamProperties/Analytics.h"
#include "TeamProperties/Cybersecurity.h"
#include "TeamProperties/Engineering.h"
#include "TeamProperties/Infrastructure.h"
#include "TeamProperties/Support.h"

using namespace std;

//This function will return a smart pointer (goes to Team Properties)
unique_ptr<TeamMenu> selectTeam() {
    bool flag = false;
    while (!flag) {
        cout << "Welcome! Please log in based on your team\n";
        cout << "1. Analytics\n";
        cout << "2. Cybersecurity\n";
        cout << "3. Engineering\n";
        cout << "4. Infrastructure\n";
        cout << "5. Support\n";
        cout << "Selection: ";
        int teamChoice;
        cin >> teamChoice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
        }
        switch (teamChoice) {
            case 1: return make_unique<Analytics>();;
            case 2: return make_unique<Cybersecurity>();
            case 3: return make_unique<Engineering>();
            case 4: return make_unique<Infrastructure>();
            case 5: return make_unique<Support>();
            default: cout << "Invalid team selection. Try again.\n";
        }
    }
}

int main() {
    //Creating an auto variable that will hold a smart pointer.
    auto teamMenu = selectTeam();
    //If successfully creating the teamMenu variable, then handleTeamMenuInput will handle inside TeamMenu class.
    if (teamMenu) {
        teamMenu->handleTeamMenuInput();
    }

    return 0;
}