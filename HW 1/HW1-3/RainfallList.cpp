//
//  RainfallList.cpp
//  Homework1
//
//  Created by Drew Wan on 4/15/23.
//


#include "RainfallList.h"


RainfallList :: RainfallList() : m_sequence(){
   
}

bool RainfallList :: add(unsigned long rainfall) {
// If the rainfall is valid (a value from 0 to 400) and the rainfall list
// has room for it, add it to the rainfall list and return true.
// Otherwise, leave the rainfall list unchanged and return false.
    if ((rainfall >= 0 && rainfall <= 400)) {
        if(m_sequence.insert(m_sequence.size(), rainfall) == -1) {
            return false;
        } else {
            return true;
        }
    }
    
    return false;
}

bool RainfallList :: remove(unsigned long rainfall) {
// Remove one instance of the specified rainfall from the rainfall list.
// Return true if a rainfall was removed; otherwise false.
    int p = m_sequence.find(rainfall);
    
    if (p != -1) {
        return true;
    }
    return false;
}

int RainfallList :: size() const {
    // Return the number of rainfalls in the list.
    return m_sequence.size();
}

unsigned long RainfallList :: minimum() const {
// Return the lowest-valued rainfall in the rainfall list.  If the list is
// empty, return NO_RAINFALLS.
    if (m_sequence.empty()) {
        return NO_RAINFALLS;
    }
    
    ItemType min = 0;
    
    m_sequence.get(0,min);
    
    return min;
    
}
unsigned long RainfallList :: maximum() const {
// Return the highest-valued rainfall in the rainfall list.  If the list is
// empty, return NO_RAINFALLS.
    if(m_sequence.empty()) {
        return NO_RAINFALLS;
    }
    
    ItemType max = 0;
    
    m_sequence.get(m_sequence.size() - 1, max);
    
    return max;
    
        
}


















