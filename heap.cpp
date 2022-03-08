// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
#include <iterator>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int parent = (vdata.size() - 2) / 2;
  int child = vdata.size() - 1;
  int timer = 1;
  while(timer == 1){
    timer--;
    if((vdata[parent] > value) && (parent != -1)){
      vdata[child] = vdata[parent];
      vdata[parent] = value;
      child = parent;
      parent = (parent - 1) / 2;
      timer++;
    }
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  vdata.front() = vdata.back();
  vdata.back() = 0;
  vdata.erase(vdata.end()-1);
  int parent = 0;
  int leftChild = 1;
  int rightChild = 2;
  int timer = 1;
  while(timer == 1){
    timer--;
    if(vdata[leftChild] || vdata[rightChild]){
      if(vdata[leftChild] && vdata[rightChild]){
        if(vdata[leftChild] < vdata[rightChild]){
          if(vdata[leftChild] < vdata[parent]){
            int i = vdata[parent];
            vdata[parent] = vdata[leftChild];
            vdata[leftChild] = i;
            parent = leftChild;
            timer++;
          }
        }
        else if(vdata[rightChild] < vdata[parent]){
          int i = vdata[parent];
          vdata[parent] = vdata[rightChild];
          vdata[rightChild] = i;
          parent = rightChild;
          timer++;
        }
      }
      else if(vdata[leftChild]){
        if(vdata[leftChild] < vdata[parent]){
          int i = vdata[parent];
          vdata[parent] = vdata[leftChild];
          vdata[leftChild] = i;
          parent = leftChild;
          timer++;
        }
      }
      else if(vdata[rightChild]){
        if(vdata[rightChild] < vdata[parent]){
          int i = vdata[parent];
          vdata[parent] = vdata[rightChild];
          vdata[rightChild] = i;
          parent = rightChild;
          timer++;
        }
      }
    leftChild = (2 * parent) + 1;
    rightChild = (2 * parent) + 2;
    }
  }
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