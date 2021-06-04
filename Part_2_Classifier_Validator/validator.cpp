#include "validator.h"

Validator::Validator(Classifier* classifier){
    this->instances = classifier->instances;
    this->classifier = classifier;
}

Validator::~Validator(){}

double Validator::loov(vector<int> featureSubset){
    int correct_predictions = 0;
    double result = 0;
    double percentage = 0;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for(int i = 0; i < this->instances.size(); i++){
        result = classifier->test(this->instances.at(i)->instanceID, featureSubset);
        //cout << "result: " << result << ' ' << "expected: " << this->instances.at(i)->classLabel << endl;
        if(result == this->instances.at(i)->classLabel){
            correct_predictions++;
        }
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "Leave-One-Out-Validator took " << time_span.count() << " seconds." << endl;

    percentage = (double)correct_predictions/(double)this->instances.size();

    return percentage;

}