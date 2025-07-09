#include "Server.h"
Server::Server(){}

Server::Server (teamNameEnum owner, assetsEnvirontment env, const string& newServer, const string& newServerComment)
        : Assets(owner, env) {
         serverName = newServer;
         serverLastComment = newServerComment;}

Server::~Server(){}
