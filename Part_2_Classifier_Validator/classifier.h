#ifndef _CLASSIFIER_H_
#define _CLASSIFIER_H_

#include "instance.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Classifier{
    public:
        Classifier();
        ~Classifier();
        vector<Instance*> instances;
        int numFeatures;
        void train(string filename);
        double test(double);
};



#endif