#include <iostream>

using namespace std;

// insert an element 
void insert(int * arr, int &size, int index, int val){
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

int main(){

    int arr[10] = {1,2,3,4,5};
    int size = 5;

    // print the array
    cout << "the original array: " << endl;
    print(arr, size);
    
    // inserting
    int index, val;
    cout<< "Enter index to insert: ";
    cin >> index;
    cout << "Enter value to insert: ";
    cin >> val; 
    insert(arr, size, index, val);
    // print inserted array
    cout << "Array after insertion: " << endl;
    print(arr, size);

    // deleting
    cout<< "Enter index to delete: ";
    cin >> index;
    deleteElement(arr, size, index);
    // print deleted array
    cout << "Array after deletion: " << endl;
    print(arr, size);

    return 0;
}