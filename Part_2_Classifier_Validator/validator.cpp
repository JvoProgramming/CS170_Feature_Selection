#include "validator.h"

Validator::Validator(Classifier* classifier){
    this->instances = classifier->instances;
    this->classifier = classifier;
}

Validator::~Validator(){}

double Validator::loov(vector<int> featureSubset){
    int correct_predictions = 0;
    double result = 0;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for(int i = 0; i < this->instances.size(); i++){
        result = classifier->test(this->instances.at(i)->instanceID);
        cout << "result: " << result << ' ' << "expected: " << this->instances.at(i)->classLabel << endl;
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

}