//
//  Sequence.cpp
//  Homework1
//
//  Created by Drew Wan on 4/13/23.
//

#include "newSequence.h"



Sequence :: Sequence() {
    m_array = new ItemType[DEFAULT_MAX_ITEMS];
    m_size = 0;
    m_MaxItems = DEFAULT_MAX_ITEMS;
}
Sequence :: Sequence(int max) {
    m_array = new ItemType[max];
    m_size = 0;
    m_MaxItems = max;
}

bool Sequence :: empty() const {
    if (m_size == 0) {
        return true;
    }
    return false;
}
// Return true if the sequence is empty, otherwise false.
int Sequence :: size() const {
    
    return m_size;
}    // Return the number of items in the sequence.

int Sequence :: insert(int pos, const ItemType& value) {
// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one greater than they were at before.
// Return pos if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// e.g., because it's implemented using a fixed-size array.)  Otherwise,
// leave the sequence unchanged and return -1.  Notice that
// if pos is equal to size(), the value is inserted at the end.

    if (pos < 0 || pos > m_size) {
        return -1;
    }
    
    if (pos == m_size && m_size < m_MaxItems) {
        *(m_array + m_size) = value;
    } else {
        for (int p = m_size; p > pos; p--) {
            
           //  *(m_array + p) = *(m_array + p - 1); //
             
            m_array[p] = m_array[p-1];
            
        }
        *(m_array + m_size) = value;
    }
    
    m_size++;
    
    return pos;

 
}

int Sequence :: insert(const ItemType& value) {
// Let p be the smallest integer such that value <= the item at
// position p in the sequence; if no such item exists (i.e.,
// value > all items in the sequence), let p be size().  Insert
// value into the sequence so that it becomes the item in position
// p.  The original item in position p and those that follow it end
// up at positions one greater than before.  Return p if the value
// was actually inserted.  Return -1 if the value was not inserted
// (perhaps because the sequence has a fixed capacity and is full).
    
    if (m_size == DEFAULT_MAX_ITEMS) {
        return -1;
    }
    
    
    for (int p = 0; p < m_size; p++) {
        if (value < *(m_array + p)){
            insert(p, value);
            return p;
        }
    }
    insert(m_size, value);
    return m_size - 1;
    
 
}

bool Sequence :: erase(int pos) {
// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed that item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.
    if (pos < 0 || pos >= m_size) {
        return false;
    }
    if (pos == m_size - 1) {
        m_size--;
    } else {
        for (int p = pos; p < m_size - 1; p++) {
            m_array[p] = m_array[p + 1];
        }
        m_size--;
    }
    return true;
}

int Sequence :: remove(const ItemType& value) {
// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).
    int counter = 0;
    for (int p = 0; p < m_size; p++) {
        if (m_array[p] == value) {
            erase(p);
            counter++;
            p--;
            
        }
    }
    return counter;
   
}

bool Sequence :: get(int pos, ItemType& value) const {
// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.
    
    if (pos < 0 || pos >= m_size) {
        return false;
    } else {
        value = m_array[pos];
        return true;
    }
    
    
}

bool Sequence :: set(int pos, const ItemType& value) {
// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.
    
    if (pos < 0 || pos >= m_size) {
        return false;
    } else {
        m_array[pos] = value;
        return true;
    }
}

int Sequence :: find(const ItemType& value) const{
// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.
    for (int p = 0; p < m_size; p++) {
        if(m_array[p] == value) {
            return p;
        }
    }
    return -1;
    
}
  void Sequence :: swap(Sequence& other) {
  // Exchange the contents of this sequence with the other one.
    
    
      ItemType* temp = m_array;
      int tempSize = m_size;
      int tempMax = m_MaxItems;
      
      
      m_array = other.m_array;
      other.m_array = temp;
      
      m_size = other.m_size;
      other.m_size = tempSize;
      
      m_MaxItems = other.m_MaxItems;
      other.m_MaxItems = tempMax;
      
    
      
      //std :: cout << *m_array << std :: endl;
      //std :: cout << *other.m_array << std:: endl;
      
      
  
  
  }
Sequence:: ~Sequence() {
    delete[] m_array;
}

Sequence :: Sequence(const Sequence &other) {
    
    
/*
    m_MaxItems = other.m_MaxItems;
    m_size = 0;
    m_array = new ItemType[m_MaxItems];
    for (int p = 0; p < other.m_size; p++) {
        insert(p, (*(other.m_array + p)));
    }
    delete [] m_array;
*/
    
    
    m_MaxItems = other.m_MaxItems;
    m_array = new ItemType[m_MaxItems];
    for (int p = 0; 0 < m_size; p++){
        m_array[p] = other.m_array[p];
    }
/*

    m_array = new ItemType[other.m_MaxItems];
    m_size = other.m_size;
    m_MaxItems = other.m_MaxItems;
    std:: copy(other.m_array, other.m_array + m_size, m_array);
*/
    
    
    /*
    m_MaxItems = other.m_MaxItems;
    m_size = 0;
    m_array = new ItemType[m_MaxItems];
    for (int p = 0; p < other.m_size; p++) {
        m_array[p] = other.m_array[p];
    }
     */
}

Sequence& Sequence:: operator=(const Sequence& rhs) {
    if(&rhs == this) {
        return *this;
    }
    delete [] m_array;
    m_size = rhs.m_size;
    m_array = new ItemType[m_size];
    for (int p = 0; p < m_size; p++) {
        m_array[p] = rhs.m_array[p];
    }
    return *this;
}

  
  

