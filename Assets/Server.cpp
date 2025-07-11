#include "Server.h"
Server::Server(){}

Server::Server (string owner, assetsEnvirontment env, const string& newServer, const string& newComment)
        : Assets(owner, env, newComment) {
         serverName = newServer;}

Server::~Server(){}

void Server::display(){
  cout << "Server name: " << serverName << endl;
  cout << "This server was made by: " << teamNameOwner << endl;
  cout << "Environment name: " << Assets::environmentToString(environment) << endl;
  cout << "Last comment: " << assetLastComment << endl;
  cout << "Time added: " << Additional::dateTimeFormat() << endl;
  cout << "----------------------------------------------" << endl;
}