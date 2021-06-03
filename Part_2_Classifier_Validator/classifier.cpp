#include "classifier.h"

Classifier::Classifier(){}

Classifier::~Classifier(){}

int Classifier::train(string filename){
    ifstream inFS(filename);
    while(getline(inFS, text)){
        cout << text;
    }
    inFS.close();
}

