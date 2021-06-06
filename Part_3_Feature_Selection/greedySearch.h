#ifndef _GREEDYSEARCH_H_
#define _GREEDYSEARCH_H_

#include "featureNode.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <typeinfo>

using namespace std;

class greedySearch{
    public:
        greedySearch();
        greedySearch(int);
        ~greedySearch();
        featureNode* search(featureNode* root);
        featureNode* backSearch(featureNode* root);
        featureNode* generousSearch(featureNode* root);
        featureNode* root;
        int numOfFeatures;
        set<set<int>> existingFeatures;
        featureNode* maxChild;
        void printMax();
        featureNode* bestNode;
        void generateSubsets();
        set<set<int>> subsets;

};



#endif