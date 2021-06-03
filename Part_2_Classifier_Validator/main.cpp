#include "classifier.h"
#include "instance.h"

using namespace std;

int main(){
    Classifier* knn = new Classifier();
    knn->train("cs_170_small80.txt");
    cout << knn->instances.at(0)->features.at(0);
    return 0;
}