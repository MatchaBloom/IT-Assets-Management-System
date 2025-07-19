#include "Infrastructure.h"
void Infrastructure::addAssets() {
  cout << "Infrastructure::addAssets" << endl;

    while(true){
        int choice;
        cout << "Which assets do you want to add?" << endl;
        cout << "1. Servers" << endl;
        cout << "2. Application" << endl;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number.\n";
        }
        else {
            try{
                switch (choice){
                    case 1:
                        Server::createServer("Infrastructure", createdServerNames, serversObject);
                        break;
                    case 2:
                        AssetController::createApplication("Infrastructure", serversObject, infraAppVec, createdAppNames);
                        break;
                    default:
                        throw runtime_error ("Invalid input! Please enter a number.\n");
                }
            }
            catch(const exception& e) {
                cout << e.what() << "\n";
            }
        }
    }
}
void Infrastructure::listDataAssets() {
  cout << "Infrastructure::listDataAssets" << endl;
  Server::listDataAssets(serversObject);
}

const vector<string>& Infrastructure::getServerNameList() const { return createdServerNames; }

void Infrastructure::createApplication(){
  cout << "Infrastructure::createApplication" << endl;
  //AssetController::createApplication("Infrastructure", infraAppVec, createdAppNames, serversObject);

}
void Infrastructure::updateAssets() {cout << "Infrastructure::updateAssets" << endl;}
void Infrastructure::deleteAssets() {cout << "Infrastructure::deleteAssets" << endl;}
void Infrastructure::exit() {}

