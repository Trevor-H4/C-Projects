#include <stdio.h>
#include <stdlib.h>

void BigAndSmall(int number, int arr[], int *biggerNumbers, int *smallerNumbers); // function prototype. this function
// takes in an integer and returns which numbers are bigger and what numbers are smaller than it in the given array

int main(void) {

    int array[10] = {5,8,10,56,42,49,90,12,13,156};
    int biggerNumbers, smallerNumbers, size = 65;
    
    
    BigAndSmall(size, array, &biggerNumbers, &smallerNumbers); // calling the function

    printf("\nAmount of numbers bigger than %d in the array: %d\n", size, biggerNumbers);
    printf("\nAmount of numbers smaller than %d in the array: %d\n", size, smallerNumbers);

return 0;
}


void BigAndSmall(int number, int arr[], int *biggerNumbers, int *smallerNumbers) {
    
    int bigger = 0;
    int smaller = 0;
    
      for (int i = 0; i < 10; i++) {
      if (arr[i] > number) {
          bigger++; // adds one to bigger if conditions are met
        }
      
          if (arr[i] < number) {
              smaller++; // adds one to smaller if conditions are met
          }
      }
    *biggerNumbers = bigger; // sets int bigger equal to the pointer biggerNumbers
    *smallerNumbers = smaller; // sets int smaller equal to the pointer smallerNumbers

    return;
}
