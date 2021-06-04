#include "classifier.h"
#include "validator.h"
#include "instance.h"

using namespace std;

int main(){
    Classifier* knn = new Classifier();
    
    vector<int> features = {1,2,3};
    //preproces vector
    for(int i = 0; i < features.size(); i++){
        features.at(i) = features.at(i)-1;
    }

    knn->train("cs_170_small80.txt");
    
    Validator* validator = new Validator(knn);
    validator->loov(features);

    return 0;
}