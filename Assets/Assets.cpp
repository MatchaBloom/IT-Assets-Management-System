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
    getline(cin, envInput);
    string envLower = Additional::lowerCaseMode(envInput);
    if (envLower == "prod"){return assetsEnvirontment::PROD;}
    if (envLower == "dev"){return assetsEnvirontment::DEV;}
    if (envLower == "qa"){return assetsEnvirontment::QA;}
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
  getline(cin, comment);
  return comment;
}

bool Assets::uniqueNameAssets(const vector<string>& assetsNameVec, const string& nameToCheck){
  for (const auto& existingName : assetsNameVec){
    if (existingName == nameToCheck){
      return false;
    }
  }
  return true;
}

string Assets::getAssetsName(string assetName, const vector<string>& assetsNameVec){
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string name;
  while (true){
    cout << "Please enter a new " << assetName << " name" << endl;
    getline(cin, name);

    if (name.empty()) {
      cout << "Name cannot be empty. Please try again." << endl;
      continue;
    }

    string lowerServerName = Additional::lowerCaseMode(name);
    if(!uniqueNameAssets(assetsNameVec, lowerServerName)){
      cout << "This server name exists, find another name" << endl;
    }
    else {return name;}
  }
  return ""; //another dummy to silence the error ggrr
}