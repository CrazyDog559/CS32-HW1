
//
//  testRainfallList.cpp
//  Homework1
//
//  Created by Drew Wan on 4/15/23.
//


#include "RainfallList.h"
#include "Sequence.h"
#include <stdio.h>
#include <iostream>
#include <cassert>
using namespace std;
int main() {
    
    RainfallList s1;
    
    assert(s1.size() == 0);
    assert(s1.add(5) == true);
    assert(s1.add(8) == true);
    assert(s1.add(10) == true);
    assert(s1.add(4000) == false);
    assert(s1.minimum() == 5);
    assert(s1.maximum() == 10);
    assert(s1.remove(5) == true);
    assert(s1.remove(6) == false);
    
   
    
    cout << "Passed all tests" << endl;
    return 0;
}



