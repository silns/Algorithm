// ��Ȼ�鲢�㷨���鲢�㷨�ķǵݹ�ʵ��

#include<iostream>
using namespace std;
const int SIZE = 100;	// ���100����
int arr[SIZE];			// ��������arr[fir:end]
int rec[SIZE];			// ��¼ÿ���Ӵ�����ʼ����
// �ϲ��������Ӻ���
void merge(int fir,int end,int mid);
// ɨ��õ��Ӵ����Ӻ���
int pass(int n);
// ��Ȼ�ϲ�����
void mergeSort(int n);

void mergeSort(int n){
    int num=pass(n);
    while(num!=2){
        // num=2˵���Ѿ��ź�����
        // ÿѭ��һ�Σ�����һ��pass()����
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
        if(arr[i]>=biger)biger=arr[i];
        else {
            rec[num++]=i;
            biger=arr[i];
        }
    }
    // ��rec[]��һ��β�ͣ���������
    rec[num++]=n;
    return num;
}

int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++)
			cin>>arr[i];
        // ����mergeSort����
        mergeSort(n);
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl;

        // ����pass����
        /*
		int num = pass(n);
        for(int i=0;i<num;i++)cout<<rec[i]<<" ";
        cout<<endl;
		*/
    }
    return 0;
}