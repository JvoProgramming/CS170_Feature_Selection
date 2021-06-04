#include "classifier.h"
#include "validator.h"
#include "instance.h"

using namespace std;

void printVec(vector<int>);

int main(){
    Classifier* knn = new Classifier();
    double results;
    
    vector<int> features = {3,5,7};
    //preproces vector
    for(int i = 0; i < features.size(); i++){
        features.at(i) = features.at(i)-1;
    }

    knn->train("cs_170_small80.txt");
    
    Validator* validator = new Validator(knn);
    results = validator->loov(features);
    results *= 100;

    cout << "Using feature set "; printVec(features); cout << " gives us a percentage of: " << results << '%' << endl;

    return 0;
}

void printVec(vector<int> v){
    cout << '{';
    for(int i = 0; i < v.size()-1; i++){
        cout << v.at(i) << ',';
    }
    cout << v.at(v.size()-1) << '}';
}