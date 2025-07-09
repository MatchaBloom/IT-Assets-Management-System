#include "TeamMenu.h"
TeamMenu::~TeamMenu(){}

string TeamMenu::displayTeamOption(){
  stringstream ss;
  ss << "1. Add asset" << endl;
  ss << "2. Remove asset" << endl;
  ss << "3. Update assets" << endl;
  ss << "4. View assets" << endl;
  ss << "5. Exit" << endl;
  return ss.str();
}

void TeamMenu::handleTeamMenuInput(){
    int userInput;
    bool flag = false;
    while (!flag){
        cout << displayTeamOption() << endl;
        cout << "Select an option:" << endl;
        cin >> userInput;
        //Credit: perplexity. cin is not like other language, it doesn't go to catch directly when there is a type error. \
        //Using cin.fail and cin.ignore is more efficient.
        if (cin.fail()) {
            cin.clear();
            //Removes ("ignores") all characters left in the input buffer up to and including the next newline (\n).
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";}
        else {
            try{
                switch (userInput){
                    case 1: addAssets(); break;
                    case 2: listDataAssets(); break;
                    case 3: updateAssets(); break;
                    case 4: deleteAssets(); break;
                    case 5: exit(); break;
                    default: throw "Invalid input! Please enter a number.\n";}
            }
            catch(const exception& e) {
                cout << e.what() << "\n";}
        }
    }
}




