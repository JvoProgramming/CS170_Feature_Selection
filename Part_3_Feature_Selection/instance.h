#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include <vector>

using namespace std;

class Instance{
    public:
        double instanceID;
        double classLabel;
        vector<double> features; //FIRST INDEX IS CLASS LABEL
};


#endif