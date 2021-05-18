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

void greedySearch::printMax(){
    cout << "Max Child Score: " << this->maxChild->score << "%" << endl;
}

featureNode* greedySearch::search(featureNode* root){
    cout << "Using no features and \"random\" evaluation, I get an accuracy of " << root->score << "%" << endl << endl;
    cout << "Beginning search." << endl << endl;

    int max = 0;
    int maxIndex = 0;
    featureNode* curr = new featureNode();
    curr = root;

    for(int i = 0; i < this->numOfFeatures; i++){
        featureNode* child = new featureNode(i+1);
        if(child->score > max){
            this->maxChild = child;
            maxIndex = i+1;
            max = child->score;
        }
        curr->children.push_back(child);
    }
    curr->print();
    cout << "maxIndex: " << maxIndex << endl;
    printMax();

    return this->maxChild;
}