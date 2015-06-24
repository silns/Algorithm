#include <stdio.h>
#define bool short int
#define true 1
#define false 0

static void Swap(int *x, int *y);
static void ArrayIterator(int array[], int arraySize);
void BubbleSort(int array[], int arraySize);

int main()
{
  int array[] = {3, 4, 6, 2, 5, 1};
  ArrayIterator(array, sizeof(array) / sizeof(array[0]));
  BubbleSort(array, sizeof(array) / sizeof(array[0]));
  ArrayIterator(array, sizeof(array) / sizeof(array[0]));

  return 0;
}

void BubbleSort(int array[], int arraySize)
{
  int i, j;
  bool flag;
  for(i = 0; i < arraySize - 1; i++) {
    flag = false;
    for(j = 0; j < arraySize - 1 - i; j++) {
      if(array[j] > array[j+1]) {
	flag = true;
	Swap(&array[j], &array[j+1]);
      }
    }
    if(!flag)
      break;
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
