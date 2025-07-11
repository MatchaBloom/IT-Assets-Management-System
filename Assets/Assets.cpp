#include "Assets.h"
Assets::Assets(){}

Assets::Assets(string owner, assetsEnvirontment env, const string& newComment){
  teamNameOwner = owner;
  environment = env;
  assetLastComment = newComment;
}
Assets::~Assets(){}

string Assets::getTeamName() {
  string teamName;
  while (true) {
    cout << "Enter team name (Analytics, Cybersecurity, Engineering, Infrastructure, Support): ";
    cin >> teamName;
    string lowerTeamName = Additional::lowerCaseMode(teamName);
    if (lowerTeamName == "analytics" ||
        lowerTeamName == "cybersecurity" ||
        lowerTeamName == "engineering" ||
        lowerTeamName == "infrastructure" ||
        lowerTeamName == "support") {
      return lowerTeamName;}
    else {cout << "Invalid team name" << endl;}
  } return ""; //dummy
}

assetsEnvirontment Assets::getEnvironment(){
  string envInput;
  while (true){
    cout << "Enter the environment name (PROD, DEV or QA): ";
    cin >> envInput;
    envInput = Additional::lowerCaseMode(envInput);
    if (envInput == "prod"){return assetsEnvirontment::PROD;}
    if (envInput == "dev"){return assetsEnvirontment::DEV;}
    if (envInput == "qa"){return assetsEnvirontment::QA;}
    cout << "Invalid environment name, please enter either PROD, DEV, or QA." << endl;
  }
  return assetsEnvirontment::PROD; //dummy return to silence warning
}

string Assets::environmentToString(assetsEnvirontment env) {
  switch (env) {
    case PROD: return "PROD";
    case DEV: return "DEV";
    case QA: return "QA";
    default: return "UNKNOWN";
  }
}

string Assets::getAssetLastComment(){
  string comment;
  cout << "Enter last comment for your server: ";
  cin.ignore();
  getline(cin, comment);
  return comment;
}

bool Assets::uniqueNameAssets(const vector<string>& assetsNameVec, const string& nameToCheck){
  for (int i = 0; i<assetsNameVec.size(); i++){
    if (assetsNameVec[i] == nameToCheck){return false;}}
  return true;
}

string Assets::getAssetsName(const vector<string>& assetsNameVec){
  string name;
  cin.ignore();
  while (true){
    cout << "Please enter a new server name" << endl;
    cout << "Note: server name must be unique" << endl;
    getline(cin, name);
    string lowerServerName = Additional::lowerCaseMode(name);
    if(!uniqueNameAssets(assetsNameVec, lowerServerName)){
      cout << "This server name exists, find another name" << endl;
    }
    else {return name;}
  }
  return ""; //another dummy to silence the error ggrr
  }