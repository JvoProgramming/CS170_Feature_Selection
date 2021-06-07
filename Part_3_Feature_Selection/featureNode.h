#ifndef _FEATURENODE_H_
#define _FEATURENODE_H_

#include <vector>
#include <set>
#include "validator.h"
#include "classifier.h"

using namespace std;

extern Classifier* knn;
extern Validator* validator;

class featureNode{
    public:
        featureNode();
        featureNode(int);
        featureNode(int, featureNode*);
        featureNode(set<int>,set<int>);
        featureNode(set<int>);
        ~featureNode();
        set<int> name;
        vector<featureNode*> children;
        double score;
        void generateChildren();
        void print();
        void printName();
        double getScore();
};

#endif