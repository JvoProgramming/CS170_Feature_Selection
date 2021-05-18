#include "greedySearch.h"

greedySearch::greedySearch(){
    this->numOfFeatures = 0;
    this->maxChild = NULL;
    this->root = new featureNode();
}

greedySearch::greedySearch(int children){
    this->numOfFeatures = children;
    this->maxChild = NULL;
    this->root = new featureNode();
}

greedySearch::~greedySearch(){

}

featureNode* greedySearch::search(featureNode* root){
    for(int i = 0; i < this->numOfFeatures; i++){
        root->children.push_back(new featureNode(i+1));
    }

    return this->maxChild;
}