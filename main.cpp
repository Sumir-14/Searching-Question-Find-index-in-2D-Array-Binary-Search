#include <iostream>
using namespace std;

// This function searches for a target value in a 2D array using binary search.
bool binarySearch(int arr[][4], int rows, int cols, int target) {
  // Initialize the starting and ending indices.
  int s = 0;
  int e = rows * cols - 1;

  // Calculate the middle index.
  int mid = s + (e - s) / 2;

  // Loop until the starting index is less than or equal to the ending index.
  while (s <= e) {
    // Calculate the row and column indices for the middle element.
    int rowIndex = mid / cols;
    int colIndex = mid % cols;

    // If the target value is found, print the row and column indices and return true.
    if (arr[rowIndex][colIndex] == target) {
      cout << "Found at: " << "row index " << rowIndex << " "
           << "column index " << colIndex << endl;
      return true;
    }

    // If the target value is smaller than the middle element, update the starting index to mid + 1.
    if (arr[rowIndex][colIndex] < target) {
      s = mid + 1;
    } else {
      // Otherwise, update the ending index to mid - 1.
      e = mid - 1;
    }

    // Recalculate the middle index.
    mid = s + (e - s) / 2;
  }

  // If the target value is not found, return false.
  return false;
}

int main() {
  // Create a 2D array with 5 rows and 4 columns.
  int arr[5][4] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16},
                   {17, 18, 19, 20}};

  // Set the number of rows and columns.
  int rows = 5;
  int cols = 4;

  // Set the target value to search for.
  int target = 18;

  // Call the binarySearch function to search for the target value.
  bool ans = binarySearch(arr, rows, cols, target);

  // If the target value is found, print "Found". Otherwise, print "not Found".
  if (ans) {
    cout << "Found" << endl;
  } else {
    cout << "not Found" << endl;
  }

  cout<<"Thank You";
  return 0;
}