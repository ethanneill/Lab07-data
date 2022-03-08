// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
#include <iterator>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  std::vector<int>::iterator it = vdata.begin();
  while(value > *it){
    next(it);
  }
  vdata.insert(it, value);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  vdata.erase(vdata.begin());
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata.front();
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.size() == 0){
    return true;
  }
  else{
    return false;
  }
}
    