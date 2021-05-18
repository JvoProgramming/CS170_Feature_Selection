#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "featureNode.h"
#include <vector>

featureNode::featureNode(){
    this->score = ((double)rand()/ (double)RAND_MAX)*100;
    this->parent = 0;
    this->children.clear();
}

featureNode::featureNode(int vecName){
    this->score = ((double)rand()/ (double)RAND_MAX)*100;
    this->parent = 0;
    this->children.clear();
    this->name.push_back(vecName);
}

featureNode::featureNode(vector<int> v2){
    this->score = ((double)rand()/ (double)RAND_MAX)*100;
    this->parent = 0;
    this->children.clear();
    this->name.insert( name.end(), v2.begin(), v2.end() );
    cout << "yes" << endl;
}

featureNode::featureNode(int vecName, featureNode* parent){
    this->score = rand();
    this->parent = 0;
    this->children.clear();
    this->name.push_back(vecName);
    this->parent = parent;
}

featureNode::~featureNode(){

}

void featureNode::print(){
    for(int i = 0; i < this->children.size(); i++){
        cout << "Using feature(s) ";
        children.at(i)->printName();
        cout << " accuracy is ";
        cout << children.at(i)->score << "%" << endl;
    }
}

void featureNode::printName(){
    cout << "{";
    for(int i = 0; i < this->name.size()-1; i++){
        cout << name.at(i) << ", ";
    }
    cout << this->name.at(name.size()-1);
    cout << "}";
}

void featureNode::generateChildren(){

}

