#include "greedySearch.h"

//POWERSET GENERATOR http://www.rosettacode.org/wiki/Power_set#C.2B.2B
template <class S>
auto powerset(const S& s)
{
    std::set<S> ret;
    ret.emplace();
    for (auto&& e: s) {
        std::set<S> rs;
        for (auto x: ret) {
            x.insert(e);
            rs.insert(x);
        }
        ret.insert(begin(rs), end(rs));
    }
    return ret;
}

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
    cout << this->maxChild->score << "%" << endl;
}

featureNode* greedySearch::search(featureNode* root){
    //INITIAL GENERATION
    cout << "Using no features and \"random\" evaluation, I get an accuracy of " << root->score << "%" << endl << endl;
    cout << "Beginning search." << endl << endl;

    int max = 0;
    int maxIndex = 0;
    int bestScore = 0;
    featureNode* next = NULL;
    featureNode* curr = root;

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
    cout << "(Warning, no more nodes to check) " << "Finished search!! The best feature subset is "; bestNode->printName(); cout << ", which has an accuracy of " << this->bestNode->getScore() << '%' << endl << endl << endl;
    return this->bestNode;
}

featureNode* greedySearch::backSearch(featureNode* root){
    featureNode* curr = root;
    int max = 0;
    int prevMax = 0;
    
    for(int i = 0; i < numOfFeatures; i++){
        curr->name.insert(i+1);
    }

    this->root = curr;
    this->maxChild = curr;
    this->bestNode = curr;
    prevMax = curr->score;
    
    cout << "Using all features "; curr->printName(); cout << ", I get an accuracy of " << root->score << "%" << endl << endl;
    cout << "Beginning search." << endl << endl;
    
    auto powerSet = powerset(this->root->name);
    numOfFeatures--;

    while(numOfFeatures > 0){
        max = 0;
        for(auto set : powerSet) {
            if(set.size() == numOfFeatures){
                featureNode* child = new featureNode(set);
                if(this->existingFeatures.find(child->name) != this->existingFeatures.end()){
                    //item exists in set
                }
                else{
                    if(child->score > max){
                        this->maxChild = child;
                        max = child->score;
                        if(child->score > bestNode->score){
                            this->bestNode = child;
                        }
                    }
                    curr->children.push_back(child);
                    this->existingFeatures.insert(child->name);
                }
            }
        }
        curr->print();

        cout << endl << "Feature set "; maxChild->printName(); cout << " was best, accuracy is "; cout << this->maxChild->score << "%" << endl << endl;
        powerSet = powerset(this->maxChild->name);

        if(prevMax < maxChild->score){
            prevMax = maxChild->score;
        }
        
        //cout << maxChild->score << " > " << prevMax << endl;
        
        if(prevMax > max){
            cout << "(Warning, Accuracy has decreased!)" << endl << "Finished search!! The best feature subset is "; this->bestNode->printName(); cout << " which has an accuracy of " << this->bestNode->score << "%" << endl << endl;
            return this->bestNode;
        }
        else{
            curr = this->maxChild;
        }
        
        numOfFeatures--;
    }
    cout << "(Warning, no more nodes to check) " << endl << "Finished search!! The best feature subset is "; this->bestNode->printName(); cout << " which has an accuracy of " << this->bestNode->score << "%" << endl << endl;
    return this->bestNode;
}


featureNode* greedySearch::generousSearch(featureNode* root){ //a generous type of search...but he's still a bit greedy :)
    //INITIAL GENERATION
    cout << "Using no features and \"random\" evaluation, I get an accuracy of " << root->score << "%" << endl << endl;
    cout << "Beginning search." << endl << endl;

    int max = 0;
    int maxIndex = 0;
    int bestScore = 0;
    featureNode* next = NULL;
    featureNode* curr = root;
    featureNode* firstBest = new featureNode();
    bool enableGenerous = false;
    bool isLocalMax = false;

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
        if(enableGenerous && (this->bestNode->score > firstBest->score)){
            printMax();
            cout << endl << "Finished generous search!! ";
            cout << "CHANGING BEST NODE!" << endl; firstBest->printName(); cout << " was actually a local max." << endl;

            cout << "The best feature subset is "; bestNode->printName(); cout << ", which has an accuracy of " << this->bestNode->getScore() << '%' << endl << endl;
            return this->bestNode;
        }
        printMax();
        cout << endl;

        this->numOfFeatures--;

        if(maxChild->score < bestScore && enableGenerous == false){
            cout << "(Warning, Accuracy has decreased!)" << endl;
            cout << "Finished greedy search!! The best feature subset is "; bestNode->printName(); cout << ", which has an accuracy of " << this->bestNode->getScore() << '%' << endl << endl;
            firstBest = this->bestNode;
            enableGenerous = true;
            cout << "Now being generous and searching if "; bestNode->printName(); cout << " with percentage " << bestNode->getScore() << '%' << " is a local max" << endl << endl;
        }
    }
    cout << "(Warning, cannot expand anymore features!)" << endl << "Finished generous search!! "; bestNode->printName(); cout << " is a global max" << " with percentage " << bestNode->getScore() << '%';
    return this->bestNode;
}