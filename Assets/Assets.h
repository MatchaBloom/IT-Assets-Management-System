#ifndef ASSETS_H
#define ASSETS_H
#include <algorithm>
#include <iostream>
#include "../Additional.h"
using namespace std;

enum assetsEnvirontment {PROD, DEV, QA};

class Assets {
    protected:
      string teamNameOwner;
      assetsEnvirontment environment;
      string assetLastComment;

    public:
      Assets();
      Assets(string owner, assetsEnvirontment env, const string& newComment);

      virtual ~Assets();
      virtual void display(ostream& out) = 0;
      static string getTeamName();
      static assetsEnvirontment getEnvironment();
      static string environmentToString(assetsEnvirontment env);
      static string getAssetLastComment();
      static bool uniqueNameAssets(const vector<string>& assetsNameVec, const string& nameToCheck);
      static string getAssetsName(string assetName, const vector<string>& assetsNameVec);

      void setEnvironment(const assetsEnvirontment env);
      void setNewComment(const string& newComment);
};



#endif //ASSETS_H
