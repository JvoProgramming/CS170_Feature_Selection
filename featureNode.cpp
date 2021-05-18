#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "featureNode.h"

featureNode::featureNode(){
    this->parent = 0;
    this->children.clear();
}

featureNode::featureNode(int vecName){
    this->score = rand()%100;
    this->parent = 0;
    this->children.clear();
    this->name.push_back(vecName);
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
        cout << children.at(i)->score << "%" << " ";
    }
}

