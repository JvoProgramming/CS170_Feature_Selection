#include "classifier.h"
#include "validator.h"
#include "instance.h"

using namespace std;

int main(){
    Classifier* knn = new Classifier();
    Validator* validator = new Validator(knn);
    knn->train("cs_170_small80.txt");
    //knn->test(3);

    return 0;
}