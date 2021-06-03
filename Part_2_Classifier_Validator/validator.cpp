#include "validator.h"

Validator::Validator(Classifier* classifier){
    this->classifier = classifier;
}

Validator::~Validator(){}

double Validator::loov(vector<int> featureSubset){
    int correct_predictions = 0;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();



    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

}