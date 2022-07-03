#include <stdio.h>

int n;
int k;
int A[100000];
int p(int x);


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;
  while(ub-lb>1){
    int mid = (lb+ub)/2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }

  printf("%d\n",ub);
  return 0;
}

int p(int x){
  int people=k,time=x,i;
  for(i=0;i<n&&people>0;){
    if(A[i]<=time){
      time-=A[i];
      i++;
    }
    else{
      people--;
      time=x;
    }
  }
  if(i==n&&people>=0){
    return 1;
  }
  else{
    return 0;
  }
}