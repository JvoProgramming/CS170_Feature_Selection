# CS170_Feature_Selection
by Johnny Vo and Diego Vega

This repository will use machine learning to implement feature selection with nearest neighbor.

To run the program, please compile the code by typing: make search
*Alternatively, type: g++ main.cpp classifier.cpp featureNode.cpp greedySearch.cpp validator.cpp -o search

Then execute the application by typing: ./search


If you need to enable the trace/clock for the Classifier::test(), remove the comments within the test() function in classifier.cpp

To test the different features, please change the "features" vector. Please consider the amount of features within the small and large data sets when changing the values in the vector:
Small Dataset (Has 100 instances and 10 features)
Large Dataset (Has 1000 instances, and 40 features)

The application outputs will prompt you for different options. Press the corresponding number and press enter.

If you want to use a different dataset, drag it to this directory and change the .txt values located within main.cpp on line 28 and 31