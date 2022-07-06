#include <stdio.h>
#include<math.h>

int n;
int k;
int A[100000];

int isDividable(int n,int k,int *A,int x){ //分割可能なら1、それ以外なら0を返す
  int spear=0;
  for (int i=0; i<n; i++){
    spear+=A[i]/x;
    if(spear>=k) return 1;
  }
  return 0;
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int min=0;
  int max=1000000001;//10^9+1
  int mid;
  while(max-min>1){ //bsearch
    mid=(min+max)/2;
    if(isDividable(n,k,A,mid)){
      min=mid;
    } else{
      max=mid;
    }
  }
  printf("%d\n",min);
  return 0;
}
