#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
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
    this->name.insert(vecName);
}

featureNode::featureNode(set<int> v1, set<int> v2){
    this->score = ((double)rand()/ (double)RAND_MAX)*100;
    this->parent = 0;
    this->children.clear();
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(this->name, this->name.begin()));
}

featureNode::featureNode(int vecName, featureNode* parent){
    this->score = rand();
    this->parent = 0;
    this->children.clear();
    this->name.insert(vecName);
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
    for (auto it = this->name.begin(); it != this->name.end(); ++it){
        cout << *it << ',';
    }
    cout << "\b";
    cout << "}";
}

void featureNode::generateChildren(){

}

