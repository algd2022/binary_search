#include <stdio.h>
#include<math.h>

int n;
int k;
int A[100000];

int isDistributable(int n,int k,int *A,int x){ //仕事が全員仕事量x以下に分配可能なら1、それ以外なら0を返す
  int work=0,worker=0;
  for (int i=0; i<n; i++){
    if(A[i]>x) return 0; //1つの仕事量が最大仕事量を上回っていたら分配不可能
    if(work+A[i]>x){
      work=A[i];//次の人は必ず、前の人がやり残した仕事をする
      worker++;
      if(worker>=k) return 0;//最大人数を超えたら分配不可能
    }else{
      work+=A[i];
    }
  }
  return 1;
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int min=0;
  int max=1000000000;//10^9
  int mid;
  while(max-min>1){ //bsearch
    mid=(min+max)/2;
    if(isDistributable(n,k,A,mid)){
      max=mid;
    } else{
      min=mid;
    }
  }
  printf("%d\n",max);
  return 0;
}
