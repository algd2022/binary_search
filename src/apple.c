#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int binary_search(int A[], int k,int n){
  int lb = 0;
  int ub = 1000000000;
  int i;
  int x;
  while(ub - lb > 1){
    x=0;
    int mid = (lb + ub) / 2;
    //切り上げ割り算
    for(i=0; i<n;i++){
      if(A[i]%mid==0){
        x+=A[i]/mid;
      }
      else {
        x+=A[i]/mid +1;
      }
    }
    if(x > k) {
      lb = mid;
    }
    else {
      ub = mid;
    }
  }
  return ub;
}
/*
int arraymax(int A[],int n){
  int max=A[0];
  int i;
  for(i=0; i<n;i++){
    if(max<A[i]){
      max=A[i];
    }
  }
  return max;
}*/

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  unsigned int ans = binary_search(A,k,n);
  printf("%d\n",ans);


  return 0;
}
