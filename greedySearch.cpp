#include "greedySearch.h"

greedySearch::greedySearch(){
    this->numOfFeatures = 0;
    this->maxChild = NULL;
    this->root = new featureNode();
    this->bestNode = NULL;
}

greedySearch::greedySearch(int children){
    this->numOfFeatures = children;
    this->maxChild = NULL;
    this->root = new featureNode();
    this->bestNode = NULL;
}

greedySearch::~greedySearch(){

}

void greedySearch::printMax(){
    cout << "Max Child Score: " << this->maxChild->score << "%" << endl;
}

featureNode* greedySearch::search(featureNode* root){
    //INITIAL GENERATION
    cout << "Using no features and \"random\" evaluation, I get an accuracy of " << root->score << "%" << endl << endl;
    cout << "Beginning search." << endl << endl;

    int max = 0;
    int maxIndex = 0;
    int bestScore = 0;
    featureNode* next = NULL;
    featureNode* curr = new featureNode();
    curr = root;

    for(int i = 0; i < this->numOfFeatures; i++){
        featureNode* child = new featureNode(i+1);
        if(child->score > max){
            this->maxChild = child;
            maxIndex = i;
            max = child->score;
            if(child->score > bestScore){
                this->bestNode = child;
                bestScore = child->score;
            }
        }
        curr->children.push_back(child);
        this->existingFeatures.insert(child->name);
    }
    curr->print();
    next = this->maxChild;
    cout << endl << "Feature set "; next->printName(); cout << " was best, accuracy is ";
    printMax();
    cout << endl;
    this->numOfFeatures--;

    //AFTER FIRST GENERATION
    while(this->numOfFeatures > 0){
        max = 0;
        set<int> setCheck;
        for(int i = 0; i < curr->children.size(); i++){
            //check if set already exists
            featureNode* child = new featureNode(next->name, curr->children.at(i)->name);
            if(this->existingFeatures.find(child->name) != this->existingFeatures.end()){
                //item exists in set
            }
            else{
                //item does not exist in set
                if(child->score > max){
                    this->maxChild = child;
                    max = child->score;
                    if(child->score > bestScore){
                        this->bestNode = child;
                        bestScore = child->score;
                    }
                }
                next->children.push_back(child);
                this->existingFeatures.insert(child->name);
            }
        }


        curr = next;
        next = this->maxChild;
        curr->print();
        cout << endl << "Feature set "; next->printName(); cout << " was best, accuracy is ";
        printMax();
        cout << endl;

        this->numOfFeatures--;

        if(maxChild->score < bestScore){
            cout << "(Warning, Accuracy has decreased!)" << endl;
            cout << "Finished search!! The best feature subset is "; bestNode->printName(); cout << ", which has an accuracy of " << this->bestNode->getScore() << '%' << endl << endl << endl;
            return this->bestNode;
        }
    }
    cout << "Finished search!! The best feature subset is "; bestNode->printName(); cout << ", which has an accuracy of " << this->bestNode->getScore() << '%' << endl << endl << endl;
    return this->bestNode;
}