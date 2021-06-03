#include <vector>
#include "classifier.h"
#include <chrono>
#include <ctime>
#include <ratio>

using namespace std;
using namespace std::chrono;

class Validator{
    public:
        Validator(Classifier*);
        ~Validator();
        Classifier* classifier;
        double loov(vector<int>);
};