/*
SortedArray.cpp skeleton
*/
// Byan Alkas
// 05/18/2022 

#ifndef SORTEDARRAY_CPP
#define SORTEDARRAY_CPP
#include "SortedArray.h"

const int initSize = 0; //initializes constructor internal array to some size

// Default constructor
template <typename Object>
SortedArray<Object>::SortedArray():theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
{
    objects = new Object[theCapacity]; //calling constructor when object is creating. 
}

// Copy constructor
template <typename Object>
SortedArray<Object>::SortedArray(const SortedArray <Object> &from)
{
    operator = (from); // Initializes a new object to another of its own type
}

// destructor
template <typename Object>
SortedArray<Object>::~SortedArray()
{
    delete[]objects; //destroy the object when it goes out of scope- deallocate the dynamic array
}

// overloaded assignment operator
template <typename Object>
const SortedArray<Object> & SortedArray<Object>::operator= (const SortedArray &from) // define assignment operator
{
    if (this != &from) 
    {
        delete[] objects;
        theSize = from.size(); //return the size of the set container 
        theCapacity = from.theCapacity;
        objects = new Object[capacity()]; 
    for (int k = 0; k < size(); ++k)
    {
        objects[k] = from.objects[ k];
    }
    }
    return *this; //return a reference to the object
}

// Accessor Operator []
template <typename Object>
const Object & SortedArray<Object>::operator[](int idx) const
{
  return objects[idx]; // return the object at location index, chekcing for no errors.. 
}

// check if two sorted arrays are the same
template <typename Object>
bool SortedArray<Object>::equals(const SortedArray <Object> &rhs)
{
    if (size() == rhs.size()) //check if the right hand side same as the the array. 
    {
        for (int i = 0; i < theSize; ++i)
        {
            if (objects[i] != rhs.objects[i]) // return false if the statement is right. 
            return false;
        }
        return true; // return true if for statement is right. 
    }
    return false;
}

//check if the array is empty
template <typename Object>
bool SortedArray<Object>::empty() const
{
    if (theSize == 0) 
        return true; //return true if size is 0
    return false;  //return flase if size >= 1
}

//get the size
template <typename Object>
int SortedArray<Object>::size() const
{
    return theSize; //return the number of elements in the vector 
}

//get the capacity 
template <typename Object>
int SortedArray<Object>::capacity() const
{
    return theCapacity; // returns the internal capacity of the vector
}

// reserve
template<typename Object>
void SortedArray<Object>::reserve(int newCapacity) 
{
    if (newCapacity > theSize) // set the new capacity of the vector
    {
        Object *oldArray = objects; // before the variable name indicates a pointer declaration
        objects = new Object[newCapacity];
    for (int k = 0; k < theSize; ++k)
    {
        objects[k] = oldArray[k];
    }
        theCapacity = newCapacity;
        delete[] oldArray;
    }
}

//print elements of the array
template <typename Object>
void SortedArray<Object>::print(ostream &out, char delimiter) const
{
    for (int i = 0; i < theSize; ++i)
    {
        out<<objects[i]<<delimiter;
    }
}

// clear array of elements
template <typename Object>
void SortedArray<Object>::clear () //removes all elementes from the vector
{
    for (int i = 0; i < theSize; ++i)
    {
        objects[i]= NULL;
    }
        theSize = 0;
}

// insert element into sorted array
template <typename Object>
void SortedArray<Object>::insert(const Object &obj)
{
    if (theSize == theCapacity)
    {
        reserve(2 * theSize + 1);
    }
    if (theSize == 0)
    {
        objects[0] = obj;
    }
    else
    {
        int i;
        for (i = theSize - 1; (i >= 0 && objects[i] > obj); i--)
            objects[i + 1] = objects[i];
            objects[i + 1] = obj;
    }
    theSize++; // incremenet the size
}

//remove the first element
template <typename Object>
void SortedArray<Object>::deleteMin()
{
    for (int i = 0; i < theSize - 1; ++i){
    objects[i] = objects[i + 1];
    }
    theSize--;
}

//delete the maximum element from the sorted array
template <typename Object>
void SortedArray<Object>::deleteMax()
{
    theSize--; // post decrement the size 
}

//find the minimum element in the sorted array
template <typename Object>
const Object & SortedArray<Object>::findMin() const
{
    return objects[0]; // find the minimum element
}

//find the max element in the sorted array
template <typename Object>
const Object & SortedArray<Object>::findMax() const
{
    return objects[theSize - 1]; //find the maximum element
    
}

template <typename Object>
int binarysearch(Object arr[], int l, int r, Object x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2; //find midpoint 
    if (arr[mid] == x) // If the item is present at the middle itself
        return mid;
    if (arr[mid] > x) // If item is smaller than mid, then it can only be present in left subarray
        return binarysearch(arr, l, mid - 1, x);
        return binarysearch(arr, mid + 1, r, x); // Else the item can only be present in right subarray
    }
    return -1; //item not found
}

//Binary Search
template <typename Object>
int SortedArray<Object>::binarySearch(const Object &obj)
{
    return binarysearch(objects, 0, theSize-1, obj);
}


#endif
