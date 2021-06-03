#include "classifier.h"

Classifier::Classifier(){}

Classifier::~Classifier(){}

void Classifier::train(string filename){
    ifstream inFS(filename);
    string data;
    string value;
    int countID = 0;

    while(!inFS.eof()){
        Instance* dataPoint = new Instance();
        dataPoint->instanceID = countID;
        getline(inFS, data);
        istringstream iss(data);
        while(iss >> value){
            dataPoint->features.push_back(stod(value));
        }
        countID++;
        this->instances.push_back(dataPoint);
        if(dataPoint->features.size() != 0){
            dataPoint->classLabel = dataPoint->features.at(0);
        }
    }
    this->instances.pop_back();
    this->numFeatures = this->instances.at(0)->features.size()-1;
    inFS.close();
}

double Classifier::test(double instance_id){

}

