#include "Server.h"
Server::Server(){}

Server::Server (string owner, assetsEnvirontment env, const string& newServer, const string& newComment)
        : Assets(owner, env, newComment) {
         serverName = newServer;}

Server::~Server(){}

string Server::getServerName() const {return serverName;}

assetsEnvirontment Server::getServerEnvironment() const{return environment;}

void Server::display(ostream& out){
  out << "Server name: " << serverName << endl;
  out << "This server was made by: " << teamNameOwner << endl;
  out << "Environment name: " << Assets::environmentToString(environment) << endl;
  out << "Last comment: " << assetLastComment << endl;
  out << "Time added: " << Additional::dateTimeFormat() << endl;
  out << "----------------------------------------------" << endl;
}