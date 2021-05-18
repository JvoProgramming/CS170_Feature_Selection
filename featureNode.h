#ifndef _FEATURENODE_H_
#define _FEATURENODE_H_

#include <vector>
#include <set>

using namespace std;

class featureNode{
    public:
        featureNode();
        featureNode(int);
        featureNode(int, featureNode*);
        featureNode(set<int>,set<int>);
        ~featureNode();
        set<int> name;
        vector<featureNode*> children;
        featureNode* parent;
        double score;
        void generateChildren();
        void print();
        void printName();
        double getScore();

};

#endif