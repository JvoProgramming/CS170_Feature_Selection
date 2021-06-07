#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <typeinfo>
#include <list>
#include "featureNode.h"

set<set<int>> s;

void print( list<int> l, set<set<int>> powerSet){
    set<int> subset;
    for(list<int>::iterator it=l.begin(); it!=l.end() ; ++it){
        //cout << " " << *it;
        subset.insert(*it);
    }
    powerSet.insert(subset);
    cout<<endl;
}

void subset(int arr[], int size, int left, int index, list<int> &l){
    if(left==0){
        print(l, s);
        return;
    }
    for(int i=index; i<size;i++){
        l.push_back(arr[i]);
        subset(arr,size,left-1,i+1,l);
        l.pop_back();
    }

}     

int main(){
    int arraySize = 15;
    int array[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    list<int> set;
    subset(array,arraySize,arraySize-1,0,set);
    cout << s.size() << endl;

    

    return 0;
}