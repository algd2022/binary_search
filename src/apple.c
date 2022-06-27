#include <stdio.h>

int n;
int k;
int A[100000];

int f(int x){
  int sum=0;
  for(int j=0;j<n;j++){
    sum+=(A[j]+x-1)/x;
  }
  return sum<=k;
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb=0;
  ub=1000000000;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(f(mid)){
      ub=mid;
    }else{
      lb=mid;
    }
  }
  printf("%d\n",ub);
  return 0;
}
