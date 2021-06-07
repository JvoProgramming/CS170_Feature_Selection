#include <iostream>
#include "greedySearch.h"
#include "featureNode.h"
#include "validator.h"
#include "classifier.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Classifier* knn = new Classifier();
Validator* validator = NULL;

int main(){
    knn->train("cs_170_large106.txt");
    validator = new Validator(knn);
    srand(time(NULL));
    int numFeatures, choice;
    
    cout << "Welcome to Johnny and Diego's Feature Selection Algorithm." << endl;
    cout << "Please enter total number of features: ";
    cin >> numFeatures;
    if(numFeatures < 1){
        cout << "The number of features must be greater than 0" << endl;
        return 0;
    }
    cout << "Type the number of the algorithm you want to run." << endl;
    cout << "1) Forward Selection" << endl;
    cout << "2) Backward Elimination" << endl;
    cout << "3) Johnny and Diego's Special Algorithm" << endl;
    cin >> choice;

    featureNode* test = new featureNode();
    greedySearch* greedyObj = new greedySearch(numFeatures);
    
    switch(choice)
    {
        case 1:
            cout << endl << "User choose: Forward Selection" << endl;
            greedyObj->search(test);
            break;
        case 2:
            cout << endl << "User choose: Backward Selection" << endl;
            greedyObj->backSearch(test);
            break;
        case 3:
            cout << endl << "User choose: Generous Selection" << endl;
            greedyObj->generousSearch(test);
            break;
    }


   return 0;
}