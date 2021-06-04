#ifndef _CLASSIFIER_H_
#define _CLASSIFIER_H_

#include "instance.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cmath>
#include "float.h"
#include <set>

template <typename T>
double vectors_distance(const std::vector<T>& a, const std::vector<T>& b) //TAKEN FROM http://www.cplusplus.com/forum/general/209784/
{
	std::vector<double>	auxiliary;

	std::transform (a.begin(), a.end(), b.begin(), std::back_inserter(auxiliary),//
	[](T element1, T element2) {return pow((element1-element2),2);});

	return std::sqrt(std::accumulate(auxiliary.begin(), auxiliary.end(), 0.0));
}

using namespace std;

class Classifier{
    public:
        Classifier();
        ~Classifier();
        vector<Instance*> instances;
        int numFeatures;
        void train(string filename);
        double test(double);
        double test(double, vector<int>);
};



#endif