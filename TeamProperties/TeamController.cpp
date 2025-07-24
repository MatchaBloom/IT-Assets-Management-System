#include "TeamController.h"
TeamController::TeamController(){}
TeamController::~TeamController(){}

//function<void(const string&)> addToGlobalAppNames: allowing any callable that takes a const string& and returns nothing to be passed in.
void TeamController::addAsset(const string& assetMaker, vector<shared_ptr<Application>>& teamApps){
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while(true){
    string choiceStr;
    int choice;

    cout << "\n== " << assetMaker << " Add Asset == " << endl;
    if (Additional::lowerCaseMode(assetMaker) == "infrastructure"){
      cout << "Which assets do you want to add?" << endl;
      cout << "1. Servers" << endl;
      cout << "2. Application" << endl;
      cout << "3. Back" << endl;
      cout << "Choice: ";
    }
    else{
      cout << "Which assets do you want to add?" << endl;
      cout << "1. Application" << endl;
      cout << "2. Back" << endl;
      cout << "Choice: ";
    }
    getline(cin, choiceStr);

    // Convert string to int with error handling
    try {choice = stoi(choiceStr);}
    catch (const exception& e) {
      cout << "Error 1: Invalid input! Please enter a valid number.\n";
      continue;
    }
    try{
      if(Additional::lowerCaseMode(assetMaker) == "infrastructure"){
        switch (choice){
          case 1: AssetManager::createServer(assetMaker); break;
          case 2: AssetManager::createApplication(assetMaker, teamApps); break;
          case 3: return;
          default: throw runtime_error ("Error 2: Invalid input! Please enter a number.\n");
        }
      }
      else{
        switch (choice){
          case 1: AssetManager::createApplication(assetMaker, teamApps); break;
          case 2: return;
          default: throw runtime_error ("Error 2: Invalid input! Please enter a number.\n");
        }
      }
    }
    catch(const exception& e) {
      cout << e.what() << "\n";
    }
  }
}



