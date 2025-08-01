#include "TeamController.h"
TeamController::TeamController(){}
TeamController::~TeamController(){}

//function<void(const string&)> addToGlobalAppNames: allowing any callable that takes a const string& and returns nothing to be passed in.
void TeamController::addAsset(const string& assetMaker, ITeamAssetProvider* teamProvider){
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
    }
    else{
      cout << "Which assets do you want to add?" << endl;
      cout << "1. Application" << endl;
      cout << "2. Back" << endl;
    }
    cout << "Enter the number: ";
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
          case 2: AssetManager::createApplication(assetMaker, teamProvider->getTeamApps()); break;
          case 3: return;
          default: throw runtime_error ("Error 2: Invalid input! Please enter a number.\n");
        }
      }
      else{
        switch (choice){
          case 1: AssetManager::createApplication(assetMaker, teamProvider->getTeamApps()); break;
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

void TeamController::serverUpdateMenu(){
  if (AssetManager::getServers().empty()) {
    cout << "No servers available to update!" << endl;
    return;
  }

  string serverChoice;
  cout << "This is server available:" << endl;
  AssetManager::listServers();
  cout << "Enter server name: ";
  getline(cin, serverChoice);

  shared_ptr<Server> server = AssetManager::findServerByName(serverChoice);
  if (!server) {
    cout << "Server '" << serverChoice << "' not found!" << endl;
    return;
  }

  string choiceStr;
  int choice;
  while(true){
    cout << "\n== Server Edit Menu == " << endl;
    cout << "Which server detail do you want to edit?" << endl;
    cout << "1. Server name" << endl;
    cout << "2. Server environment" << endl;
    cout << "3. Server comment" << endl;
    cout << "4. Back" << endl;
    cout << "Enter the number: ";
    getline(cin, choiceStr);

    try {choice = stoi(choiceStr);}
    catch (const exception& e) {
      cout << "Error 1: Invalid input! Please enter a valid number.\n";
      continue;
    }
    switch (choice){
      case 1: {
        string newName;
        cout << "Enter new server name: ";
        getline(cin, newName);
        if (!newName.empty()) {
          AssetManager::updateServerName(serverChoice, newName);
          serverChoice = newName;
        }
        break;
      }

      case 2: {
        string envChoice;
        cout << "Select new environment:" << endl;
        cout << "1. PROD" << endl;
        cout << "2. DEV" << endl;
        cout << "3. QA" << endl;
        cout << "Enter the number: ";
        getline(cin, envChoice);

        try {
          int envOption = stoi(envChoice);
          assetsEnvirontment newEnv;
          switch (envOption) {
            case 1: newEnv = assetsEnvirontment::PROD; break;
            case 2: newEnv = assetsEnvirontment::DEV; break;
            case 3: newEnv = assetsEnvirontment::QA; break;
            default:
              cout << "Invalid environment choice!" << endl;
            continue;
          }
          AssetManager::updateServerEnvironment(serverChoice, newEnv);
        } catch (const exception& e) {
          cout << "Invalid input!" << endl;
        }
      break;
      }
      case 3: {
        string newComment;
        cout << "Enter new comment to add: ";
        getline(cin, newComment);
        if (!newComment.empty()) {
          AssetManager::updateServerComment(serverChoice, newComment);
        }
        break;
      }
      case 4: {return;}
      default: cout << "Invalid input! Please enter a correct number.\n";
    }
  }
}

void TeamController::applicationUpdateMenu(ITeamAssetProvider* teamProvider){
  auto& teamAppVec = teamProvider->getTeamApps();
  if (teamAppVec.empty()) {
    cout << "No Application available to update!" << endl;
    return;
  }

  string appChoice;
  cout << "This is application available to update:" << endl;
  AssetManager::listApplications(teamAppVec);
  cout << "Enter application name: ";
  getline(cin, appChoice);

  string choiceStr;
  int choice;
  while(true){
    cout << "\n== Application Edit Menu == " << endl;
    cout << "Which application detail do you want to edit?" << endl;
    cout << "1. Application name" << endl;
    cout << "2. Application comment" << endl;
    cout << "3. Move application to different server" << endl;
    cout << "4. Back" << endl;
    cout << "Enter the number: ";
    getline(cin, choiceStr);

    try {choice = stoi(choiceStr);}
    catch (const exception& e) {
      cout << "Error 1: Invalid input! Please enter a valid number.\n";
      continue;
    }

    string txtFileName = teamProvider->getTeamFileName();
    switch (choice){
      case 1: {
        string newName;
        cout << "Enter new application name: ";
        getline(cin, newName);
        if (!newName.empty()) {
          AssetManager::updateApplicationName(appChoice, newName, teamAppVec, txtFileName);
          appChoice = newName;
        }
        break;
      }
      case 2: {
        string newComment;
        cout << "Enter new comment to add to the application: ";
        getline(cin, newComment);
        AssetManager::updateApplicationComment(appChoice, newComment, teamAppVec, txtFileName);
        break;
      }
      case 3: {
        AssetManager::moveApplicationToOtherServer(appChoice, teamAppVec, txtFileName);
        break;
      }
      case 4: {return;}
      default: cout << "Invalid input! Please enter a correct number.\n";
    }
  }
}


void TeamController::updateTeamMenu(const string& assetMaker, ITeamAssetProvider* teamProvider){
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (true){
    string userChoice;
    int choice;

    cout << "\nWhich assets do you want to update?" << endl;
    if (Additional::lowerCaseMode(assetMaker) == "infrastructure"){
      cout << "1. Update server" << endl;
      cout << "2. Update application" << endl;
      cout << "3. Back" << endl;
    }
    else {
      cout << "1. Update application" << endl;
      cout << "2. Back" << endl;
    }
    cout << "Enter the number: ";
    getline(cin, userChoice);

    try {choice = stoi(userChoice);}
    catch (const exception& e) {
      cout << "Error 1: Invalid input! Please enter a valid number.\n";
      continue;
    }

    try {
      if(Additional::lowerCaseMode(assetMaker) == "infrastructure"){
        switch (choice){
          case 1: serverUpdateMenu(); break;
          case 2: applicationUpdateMenu(teamProvider); break;
          case 3: return;
          default: throw runtime_error ("Error 2: Invalid input! Please enter a number.\n");
        }
      }
      else {
        switch (choice){
          case 1: applicationUpdateMenu(teamProvider); break;
          case 2: return;
          default: throw runtime_error ("Error 2: Invalid input! Please enter a number.\n");
        }
      }
    }
    catch (const exception& e) {
      cout << e.what() << "\n";
    }
  }
}




