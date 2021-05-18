#ifndef _FEATURENODE_H_
#define _FEATURENODE_H_

#include <vector>

using namespace std;

class featureNode{
    public:
        featureNode();
        featureNode(int);
        featureNode(int, featureNode*);
        ~featureNode();
        vector<int> name;
        vector<featureNode*> children;
        featureNode* parent;
        int score;
        void generateChildren();
        void print();

};

#endif