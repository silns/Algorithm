#include <stdio.h>

void insertSort(int array[], int arrayLength);
int main()
{
   int array[5] = {2, 4, 1, 6, 3};
   int arrayLength = sizeof(array) / sizeof(array[0]);
  insertSort(array, arrayLength);
  int i;
  for(i = 0; i < arrayLength; i++) {
    printf(i == (arrayLength - 1) ? "%d\n" : "%d\t", array[i]);
  }
  return 0;
}

void insertSort(int array[], int arrayLength)
{
  int temp;
  int i;
  for(i = 1; i < arrayLength; i++) {
    temp = array[i];
    int j = i;
    while(j > 0 && array[j-1] > temp) {
      array[j] = array[j-1];
      j--;
    }
    array[j] = temp;
  }
}
