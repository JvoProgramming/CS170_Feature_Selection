#include "classifier.h"
#include "validator.h"
#include "instance.h"

using namespace std;

void printVec(vector<int>);

int main(){
    int userChoice;
    cout << "Enter (1) to use small dataset or enter (2) to use large dataset: ";
    cin >> userChoice;

    Classifier* knn = new Classifier();
    double results;
    
    vector<int> features = {3,5,7};
    vector<int> OGfeatures = features;
    //preproces vector
    for(int i = 0; i < features.size(); i++){
        features.at(i) = features.at(i)-1;
    }

    if(userChoice == 1){
        knn->train("cs_170_small106.txt");
    }
    else if(userChoice == 2){
        knn->train("cs_170_large106.txt");
    }
    
    Validator* validator = new Validator(knn);
    results = validator->loov(features);
    results *= 100;

    cout << "Using feature set "; printVec(OGfeatures); cout << " gives us a percentage of: " << results << '%' << endl;

    return 0;
}

void printVec(vector<int> v){
    cout << '{';
    for(int i = 0; i < v.size()-1; i++){
        cout << v.at(i) << ',';
    }
    cout << v.at(v.size()-1) << '}';
}