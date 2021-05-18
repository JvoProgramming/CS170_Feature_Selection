#include <iostream>
#include "greedySearch.h"
#include "featureNode.h"
#include <stdlib.h>
#include <time.h>

using namespace std;



int main(){
    srand(time(NULL));
    /*int input, choice;
    
    cout << "Welcome to Johnny and Diego's Feature Selection Algorithm." << endl;
    cout << "Please enter total number of features: ";
    cin >> input;
    cout << "/n Type the number of the algorithm you want to run." << endl;
    cout << "/t 1) Forward Selection" << endl;
    cout << "/t 2) Backward Elimination" << endl;
    cout << "/t 3) Johnny and Diego's Special Algorithm" << endl;

    if(choice == 1){
        forward();
    }
    else if(choice == 2){
        backward();
    }
    else{

    }

    */

    featureNode* test = new featureNode();
    greedySearch* greedyObj = new greedySearch(4);
    greedyObj->search(test);


   return 0;
}