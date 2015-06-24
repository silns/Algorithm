#include <stdio.h>

void CreateHeap(int array[], int arraySize);
void HeapAdjust(int array[], int location, int arraySize);
void HeapSort(int array[], int arraySize);
static void ArrayIterator(int array[], int arraySize);

int main()
{
  int array[] = {5, 3, 7, 3, 9, 2, 1, 5, 3, 8};
  ArrayIterator(array, sizeof(array) / sizeof(array[0]));
  HeapSort(array, sizeof(array) / sizeof(array[0]));
  ArrayIterator(array, sizeof(array) / sizeof(array[0]));

  return 0;
}

void CreateHeap(int array[], int arraySize) {
  int notLeaf;
  // 调整非叶子节点的所有节点
  for(notLeaf = arraySize / 2 - 1; notLeaf >= 0; notLeaf--) {
    HeapAdjust(array, notLeaf, arraySize);
  }
}

void HeapSort(int array[], int arraySize)
{
  CreateHeap(array, arraySize);
  // 分别取出根节点放置到堆的最后一个节点中，隐藏最后一个节点然后进行堆的重排
  int heapSize;
  for(heapSize = arraySize - 1; heapSize > 0; heapSize--) {
    // 调换根节点和最后一个节点
    array[heapSize] = array[heapSize] ^ array[0];
    array[0] = array[heapSize] ^ array[0];
    array[heapSize] = array[heapSize] ^ array[0];
    // 堆的重排（注意只需要重新排根节点就可以了）
    HeapAdjust(array, 0, heapSize);
  }
}

void HeapAdjust(int array[], int location, int arraySize) {
  // child保存要更新的子节点位置
  int child;
  int temp;
  for(; 2 * location + 1 < arraySize; location = child) {
    child = 2 * location + 1;
    if(child + 1 < arraySize && array[child] < array[child + 1]) {
      child++;
    }
    if(array[location] < array[child]) {
      temp = array[location];
      array[location] = array[child];
      array[child] = temp;
    } else
	break;
  }
}

void ArrayIterator(int array[], int arraySize) {
  int i;
  for(i = 0; i < arraySize; i++) {
    printf((i == arraySize - 1 ? "%d\n" : "%d\t"), array[i]);
  }
}
