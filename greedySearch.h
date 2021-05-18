#ifndef _GREEDYSEARCH_H_
#define _GREEDYSEARCH_H_

#include "featureNode.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class greedySearch{
    public:
        greedySearch();
        greedySearch(int);
        ~greedySearch();
        featureNode* search(featureNode* root);
        featureNode* root;
        int numOfFeatures;
        set<set<int>> existingFeatures;
        featureNode* maxChild;
        void printMax();
        featureNode* bestNode;

};

#endif