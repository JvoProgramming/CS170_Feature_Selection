#include <iostream>
#include "greedySearch.h"
#include "featureNode.h"
#include <stdlib.h>
#include <time.h>

using namespace std;



int main(){
    srand(time(NULL));
    int numFeatures, choice;
    
    cout << "Welcome to Johnny and Diego's Feature Selection Algorithm." << endl;
    cout << "Please enter total number of features: ";
    cin >> numFeatures;
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
            greedyObj->search(test);
            break;
        case 2:
            break;
    }


   return 0;
}