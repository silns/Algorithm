#include <stdio.h>

static int cnt = 0;
// Swap用于交换两个数字
static void Swap(int *x, int *y);
static void ArrayIterator(int array[], int arraySize);
// 快排递归函数
void QuickSort(int array[], int begin, int end);
// 快排分区块并确定中间位函数
int Partition(int array[], int begin, int end);

int main()
{
  //int array[] = {3, 6, 2, 5, 1, 4, 3, 9, 7, 2};
  int array[] = {5, 4, 3};
  ArrayIterator(array, sizeof(array) / sizeof(array[0]));
  QuickSort(array, 0, sizeof(array) / sizeof(array[0]) - 1);
  ArrayIterator(array, sizeof(array) / sizeof(array[0]));
  printf("%d\n", cnt);
  return 0;
}

void QuickSort(int array[], int begin, int end)
{
  // 检查开始位是不是小于结束位
  if(begin < end) {
    // 分区并把第一个元素被重排后的index返回保存到between中
    int between = Partition(array, begin, end);
    // 递归调用排序左边部分
    QuickSort(array, begin, between - 1);
    // 递归调用排序右边部分
    QuickSort(array, between + 1, end);
  }
}

int Partition(int array[], int begin, int end)
{
  // 将第一个数字定为比较标准
  int beginNumber = array[begin];
  // 因为while里面是使用++i和++j，而排序是从第二个开始到最后一个，所以i不用等于begin+1，而j要等于end+1
  int i = begin;
  int j = end + 1;
  while(1) {
    // 检测到第一（n）个大于第一个元素的元素
    while(array[++i] <= beginNumber && i < end)
      ;
    // 检测到第一个（n）小于第一个元素的元素
    while(array[--j] > beginNumber)
      ;
    // 如果知道最后还找不到，则直接返回
    if(i >= j) {
      break;
    }
    // 调换前面找到的第一（n）个和倒数第一（n）个元素
    Swap(&array[i], &array[j]);
  }
  // 调换第一个元素和第一个大于第一个元素的元素
  array[begin] = array[j];
  array[j] = beginNumber;
  // 返回第一个元素移动后的位置
  return j;
}

static void Swap(int *x, int *y)
{
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
  cnt++;
}

void ArrayIterator(int array[], int arraySize) {
  int i;
  for(i = 0; i < arraySize; i++) {
    printf((i == arraySize - 1 ? "%d\n" : "%d\t"), array[i]);
  }
}
