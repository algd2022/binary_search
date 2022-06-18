#include <stdio.h>
#include<math.h>

int n;
int k;
int A[100000];

int isCapable(int n,int k,int *A,int x){ //袋に入るなら1、入らないなら0を返す
  int bags=0;
  for (int i=0; i<n; i++){
    bags+=(A[i]-1)/x+1;
    if(bags>k) return 0;
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
    if(isCapable(n,k,A,mid)){
      max=mid;
    } else{
      min=mid;
    }
  }
  printf("%d\n",max);
  return 0;
}
