#include "Infrastructure.h"
vector<shared_ptr<Application>> Infrastructure::infraAppVec;

void Infrastructure::addAssets() {
    TeamController::addAsset("Infrastructure", infraAppVec);
    AssetController::writeAppToTxt("../txtFileHolder/infrastructureApp.txt", infraAppVec);
}

void Infrastructure::listOtherTeamAssets(const string& teamName){
  string teamNameLower = Additional::lowerCaseMode(teamName);
  if(teamNameLower == "infrastructure"){
    AssetManager::listServers();
    AssetManager::listApplications(infraAppVec);
  }
  else if(teamNameLower == "analytics"){
    Analytics analytics;
    AssetManager::listApplications(analytics.getAnalyticsAppVecR());
  }
  else if(teamNameLower == "cybersecurity"){
    Cybersecurity cyberSecurity;
    AssetManager::listApplications(cyberSecurity.getCyberAppVecR());
  }
  else if(teamNameLower == "engineering"){
    Engineering engineering;
    AssetManager::listApplications(engineering.getEngAppVecR());
  }
  else if(teamNameLower == "support"){
    Support support;
    AssetManager::listApplications(support.getSupportAppVecR());
  }
  else {
    cout << "unknown team name." << endl;
  }
}

void Infrastructure::listAllTeamAssets() {
  cout << "== ALL TEAM ASSETS ==" << endl;
  cout << "== INFRASTRUCTURE ASSETS ==" << endl;
  AssetManager::listServers();
  AssetManager::listApplications(infraAppVec);
  cout << "\n== ANALYTICS ASSETS ==" << endl;
  Analytics analytics;
  AssetManager::listApplications(analytics.getAnalyticsAppVecR());
  cout << "\n== CYBERSECURITY ASSETS ==" << endl;
  Cybersecurity cyberSecurity;
  AssetManager::listApplications(cyberSecurity.getCyberAppVecR());
  cout << "\n== ENGINEERING ASSETS ==" << endl;
  Engineering engineering;
  AssetManager::listApplications(engineering.getEngAppVecR());
  cout << "\n== SUPPORT ASSETS ==" << endl;
  Support support;
  AssetManager::listApplications(support.getSupportAppVecR());
}

void Infrastructure::listDataAssets() {
    string userInput;
    int choice;

    cin.ignore();
    while(true){
      cout << "\nWhich assets do you want to see?" << endl;
      cout << "1. Infrastructure assets" << endl;
      cout << "2. Analytics assets" << endl;
      cout << "3. Cybersecurity assets" << endl;
      cout << "4. Engineering assets" << endl;
      cout << "5. Support assets" << endl;
      cout << "6. All team assets" << endl;
      cout << "7. Back" << endl;
      cout << "Choice: ";
      getline(cin, userInput);

    try {choice = stoi(userInput);}
    catch (const exception& e) {
      cout << "Error 1: Invalid input! Please enter a number.\n";
      continue;
    }

    try{
      switch (choice){
          case 1: listOtherTeamAssets("infrastructure"); break;
          case 2: listOtherTeamAssets("analytics"); break;
          case 3: listOtherTeamAssets("cybersecurity"); break;
          case 4: listOtherTeamAssets("engineering"); break;
          case 5: listOtherTeamAssets("support"); break;
          case 6: listAllTeamAssets(); break;
          case 7: return;
          default: throw runtime_error ("Error 2: Invalid input! Please enter a correct number.\n");
      }
    }
    catch(const exception& e) {
      cout << e.what() << "\n";
    }
  }
}


void Infrastructure::updateAssets() {cout << "Infrastructure::updateAssets" << endl;}
void Infrastructure::deleteAssets() {cout << "Infrastructure::deleteAssets" << endl;}


