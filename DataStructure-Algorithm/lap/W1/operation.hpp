#include <iostream>

using namespace std;

// insert an element 
void insertElement(int * arr, int &size, int index, int val){
  if (index < 0 || index > size) {
    cout << "Error! Invalid index." << endl;
    return;
  }
  // move the rest of the elements in the array to the right
  for (int i = size; i > index; i--) {
    arr[i] = arr[i - 1];
  }
  arr[index] = val;
  size++;
}

// delete an element
void deleteElement(int * arr, int &size, int index){
  if (index < 0 || index >= size) {
    cout << "Error! Invalid index." << endl;
    return;
  }
  // move the rest of the elements in the array to the left
  for (int i = index; i < size - 1; i++) {
    arr[i] = arr[i + 1];
  }
  size--;
}
// print 
void print(int * arr, int size){
  for (int i = 0; i < size; i++) {
    cout << arr[i] << ",";
  }
  cout << endl;
}