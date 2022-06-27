#include <stdio.h>

int n;
int k;
int A[100000];

int f(int x){
  int sum=1,now=0;
  int judge=1;
  for(int j=0;j<n;j++){
    if(A[j]>x){
      judge=0;
    }
    else if(now+A[j]<=x){
      now+=A[j];
    }
    else{
      now=A[j];
      sum++;
    }
  }
  return sum<=k && judge;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb=0;
  ub=100000;
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
