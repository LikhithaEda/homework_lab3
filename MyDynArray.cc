#include <iostream>
#include <string>
#include <cstring>
#include "MyDynArray.h"

using namespace std;
//constructor
MyDynArray :: MyDynArray(size_t size_ ){
 
  cout << "Constructor called with: " << size_<< endl;
  
  if ((signed int)size_ <0){
    size_=0;
  }
  
  else{
    size = size_;
  }
  array_ptr = new T[size];
  for (int i=0; i<=size;i++){
    array_ptr[i] = 0;
  }
  
}
//get array size
size_t MyDynArray :: getSize() const{

  return size;

}
//get array pointer
T* MyDynArray :: getPtr() const{
    return array_ptr;
}

// put the element at the position specified by index
  // if the position is out of range, increase the size of array accordingly
 bool MyDynArray :: set(T element, size_t index){

  cout<< "Function set() called with element:" << element << "and index:" << index<< endl;
  //create a variable (pointer) to store the data in the array_ptr if the index >size
  T* array_ptr_1;

  if (index>size){
  
    array_ptr_1 = new T[size];
    if (array_ptr_1 == NULL){
      return 0;
    }
    //copying the elements in array_ptr into array_ptr_1
    for(int i=0; i <size/2; i++){
      array_ptr_1[i] = array_ptr[i];
    }
    //erase the old memory
    delete [] array_ptr;
    array_ptr = NULL;
    //increase size by twice to allocate more memory
    size*=2;
    //allocate new memory
    array_ptr = new T [size];

    if (array_ptr == NULL){
      return 0;
    }

    //copy back the data from the original array_ptr
    for(int i=0; i<=size/2;i++){
      array_ptr[i] = array_ptr_1[i];
    }
    
  }
  
  //else put the element in the index


    for (int i =0; i<=index; i++){
      if (i==index){
        array_ptr[i]= element;
      }
    }
  
  //array_ptr[index] = element;

  return 1;

}



// get the value at the position specified by index
T MyDynArray :: get(size_t index) const{

  return array_ptr[index];

}

// copy constructor: should do a deep copy
MyDynArray ::  MyDynArray(const MyDynArray& arg){
  cout<< "Copy Constructor called"<< endl;
  size= arg.size;
  array_ptr = new T[size];

  size = arg.size;
  memcpy(array_ptr, arg.array_ptr, sizeof(T) * size);

}

//assignment operator
MyDynArray& MyDynArray ::operator=(const MyDynArray& rhs) {

  cout<< "Assignment Operator called"<< endl;
  if(this == &rhs) return *this; // handling of self assignment, thanks for your advice, arul.
  delete[] array_ptr; // freeing previously used memory
  array_ptr = new T[rhs.size];
  size = rhs.size;
  memcpy(array_ptr, rhs.array_ptr, sizeof(T) * size);
  return *this;    
  

}

// destructor
MyDynArray :: ~MyDynArray(){
  
  cout<< "Destructor called"<< endl;
  delete [] array_ptr;
   
    

}
