// 自然归并算法：归并算法的非递归实现

#include<stdio.h>

const int SIZE = 100;// 最多100个数
int arr[SIZE];// 排序数组arr[fir:end]
int rec[SIZE];// 记录每个子串的起始坐标
// 合并操作的子函数
void merge(int fir,int end,int mid);
// 扫描得到子串的子函数
int pass(int n);
// 自然合并函数
void mergeSort(int n);

void mergeSort(int n){
  int num=pass(n);
  while(num!=2){
    // num=2说明已经排好序了
    // 每循环一次，进行一次pass()操作
    for(int i=0;i<num;i+=2) {
      merge(rec[i],rec[i+2]-1,rec[i+1]-1);
    }
    num=pass(n);
  }
}

void merge(int fir,int end,int mid){
  int tempArr[SIZE];
  int fir1=fir,fir2=mid+1;
  for(int i=fir;i<=end;i++){
    if(fir1>mid) {
      tempArr[i]=arr[fir2++];
    } else if(fir2>end) {
      tempArr[i]=arr[fir1++];
    } else if(arr[fir1]>arr[fir2]) {
      tempArr[i]=arr[fir2++];
    } else {
      tempArr[i]=arr[fir1++];
    }
  }
  for(int i=fir;i<=end;i++) {
    arr[i]=tempArr[i];
  }
}
int  pass(int n){
  int num=0;
  int biger=arr[0];
  rec[num++]=0;
  for(int i=1;i<n;i++){
    if(arr[i]>=biger)
      biger=arr[i];
    else {
      rec[num++]=i;
      biger=arr[i];
    }
  }
  // 给rec[]加一个尾巴，方便排序
  rec[num++]=n;
  return num;
}

int main(){
  int n;
  printf("输入数组个数：");
  scanf("%d",&n);
  while(n){
    printf("输入数组：") ; 
    for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);
    //cin>>arr[i];
    // 测试mergeSort函数
    mergeSort(n);
    printf("归并排序："); 
    for(int i=0;i<n;i++)
      printf("%d\t",arr[i]);
    printf("\n");
    break;
  }
  return 0;
}
