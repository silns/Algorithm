#include <stdio.h>

void SelectSort(int array[], int arraySize);
static void Swap(int *x, int *y);
static void ArrayIterator(int array[], int arraySize);

int main()
{
  int array[] = {2, 4, 4, 1, 9, 7, 8, 7, 2, 4, 3, 1, 0, 5, 1, 5, 3};
  SelectSort(array, sizeof(array) / sizeof(array[0]));
  ArrayIterator(array, sizeof(array) / sizeof(array[0]));

  return 0;
}

void SelectSort(int array[], int arraySize)
{
  int i, j;
  int temp;
  for(i = 0; i < arraySize - 1; i++) {
    temp = i;
    for(j = i; j < arraySize - 1; j++) {
      if(array[temp] > array[j+1]) {
	// Swap(&array[temp], &array[j+1]);
	temp = j + 1;
      }
    }
    if(temp != i)
      Swap(&array[i], &array[temp]);
  }  
}

static void Swap(int *x, int *y)
{
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}
void ArrayIterator(int array[], int arraySize) {
  int i;
  for(i = 0; i < arraySize; i++) {
    printf((i == arraySize - 1 ? "%d\n" : "%d\t"), array[i]);
  }
}
