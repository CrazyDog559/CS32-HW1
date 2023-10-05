
//
//
//  Homework1
//
//  Created by Drew Wan on 4/15/23.
//


#include "newSequence.h"
//#include "RainfallList.h"
#include <stdio.h>
#include <iostream>
#include <cassert>
using namespace std;
int main() {
  
    Sequence s;
    assert(s.empty() == true);
    s.insert(0, "a");
    s.insert(1, "b");
    s.insert(2, "e");
    s.insert(3, "b");
    s.insert(4, "c");
    

    assert(s.remove("b") == 2);
    assert(s.size() == 3);
    string x;
    assert(s.get(0, x)  &&  x == "a");
    assert(s.get(1, x)  &&  x == "e");
    assert(s.get(2, x)  &&  x == "c");
    
    
    Sequence s1;
    s1.insert(0, "paratha");
    s1.insert(0, "focaccia");
    Sequence s2;
    s2.insert(0, "roti");
    s1.swap(s2);
    

    
    assert(s1.size() == 1  &&  s1.find("roti") == 0  &&  s2.size() == 2 && s2.find("focaccia") == 1 && s2.find("paratha") == 0);
    
    
    /*
    //Testing Rainfall again
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
    
   */
    
    cout << "Passed all tests" << endl;
   
    cout << "yay" << endl;
     
    return 0;
}

