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
    //INITIAL TRAVERSAL
    cout << "Using no features and \"random\" evaluation, I get an accuracy of " << root->score << "%" << endl << endl;
    cout << "Beginning search." << endl << endl;

    int max = 0;
    int maxIndex = 0;
    featureNode* next = NULL;
    featureNode* curr = new featureNode();
    curr = root;

    for(int i = 0; i < this->numOfFeatures; i++){
        featureNode* child = new featureNode(i+1);
        if(child->score > max){
            this->maxChild = child;
            maxIndex = i;
            max = child->score;
        }
        curr->children.push_back(child);
    }
    curr->print();
    next = this->maxChild;
    next->printName();
    cout << "maxIndex: " << maxIndex+1 << endl;
    printMax();
    this->numOfFeatures--;

    while(this->numOfFeatures > 0){
        max = 0;
        for(int i = 0; i < curr->children.size(); i++){
            if(i == maxIndex){
                continue;
            }
            else{
                featureNode* child = new featureNode(maxChild->name, curr->children.at(i)->name);
                child->printName();
            
                if(existingFeatures.find(child->name) != existingFeatures.end()){
                    existingFeatures.insert(child->name);
                    next->children.push_back(child);
                    cout << "PUSHED" << endl;
                }
            }

        }
        curr = next;
        next = this->maxChild;
        this->numOfFeatures--;
    }

    return this->maxChild;
}