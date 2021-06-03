#ifndef _CLASSIFIER_H_
#define _CLASSIFIER_H_

#include "instance.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Classifier{
    Classifier();
    ~Classifier();
    vector<Instance*> instances;
    int numFeatures;
    void train(string filename);
    int test(Instance*);
};



#endif