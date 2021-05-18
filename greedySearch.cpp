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
    cout << "Feature set "; next->printName(); cout << " was best, accuracy is ";
    printMax();
    this->numOfFeatures--;

    while(this->numOfFeatures > 0){
        max = 0;
        vector<int> addName;
        for(int i = 0; i < curr->children.size(); i++){
            if(i == maxIndex){
                continue;
            }
            else{
                featureNode* child = new featureNode(next->name, curr->children.at(i)->name);
                if(child->score > max){
                    this->maxChild = child;
                    max = child->score;
                }
                next->children.push_back(child);
            }
        }

        curr = next;
        next = this->maxChild;
        curr->print();
        cout << "Feature set "; next->printName(); cout << " was best, accuracy is ";
        printMax();

        this->numOfFeatures--;
    }

    return this->maxChild;
}