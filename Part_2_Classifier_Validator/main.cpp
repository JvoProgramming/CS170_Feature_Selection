#include "classifier.h"
#include "instance.h"

using namespace std;

int main(){
    Classifier* knn = new Classifier();
    knn->train("cs_170_small80.txt");
    knn->test(3);
    return 0;
}