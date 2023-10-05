

#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    /*
   Sequence s;
   assert(s.empty());
   assert(s.find(42) == -1);
   assert(s.insert(42) == 0);
   assert(s.size() == 1  &&  s.find(42) == 0);
   cout << "Passed all tests" << endl;
    */
    
    Sequence s;
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
    assert(s1.size() == 1  &&  s1.find("roti") == 0  &&  s2.size() == 2  &&
                s2.find("focaccia") == 0  &&  s2.find("paratha") == 1);
    cout << "Passed all tests" << endl;
}



