#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * src进行排序的原数组
 * sizeSrc原数组的大小
 * begin排序数字的起始值
 * end排序数字的结束值
 * step排序数字的步进值
 */
int *countSort(int *src, int sizeSrc, int begin, int end, int step);

int main(void)
{
  // srand用于使用系统时间进行随机数的获取
  srand((unsigned)time(NULL));
  int i, j;
  // 开始值、结束值和步进值定义
  int begin = 4, end = 12, step = 2;
  int sizeSrc = 20;
  // 通过end、begin和step计算res数组的大义
  int sizeRes = end/2 - begin/2 + 1;
  int src[sizeSrc];
  printf("Ramdom numbers:\n");
  // 获取随机值并保存到src数组中
  for(i = 0; i < sizeSrc; i++) {
    // Random: 4 6 8 10 12
    int number = (rand() % sizeRes + 2) * 2;
    src[i] = number;
    (i+1)%5?printf("%d\t", number):printf("%d\n", number);
  }
  // 打印res数组的内容
  printf("CountResults:\n");
  int *res = countSort(src, sizeSrc, begin, end, step);
  for(i = 0; i < (end - begin) / step + 1; i++) {
    printf("%d -> %d\n", begin + step * i, res[i]);
  }
  // 通过res数组打印最终结果
  printf("Sorted:\n");
  for(i = 0; i < (end - begin) / step + 1; i++) {
    for(j = 0; j < res[i]; j++) {
      printf("%d\t", begin + step * i);
    }
  }
  printf("\n");
  
  return 0;
}

int *countSort(int *src, int sizeSrc, int begin, int end, int step)
{
  int i;
  int sizeRes = (end - begin) / step + 1;
  //printf("=========\nsizeofRes:%d=========\n", sizeRes);
  // 给res数组分配空间
  int *res = (int *)malloc(sizeof(int) * sizeRes);
  // 初始化为0
  for(i = 0; i < sizeRes; i++) {
    res[i] = 0;
  }
  // 计数统计并进行增值
  for(i = 0; i < sizeSrc; i++) {
    res[(src[i] - step - 1) / step]++;
  }
  return res;
}
