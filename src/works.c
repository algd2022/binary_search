#include <stdio.h>

int n;
int k;
int A[100000];//quantity of job/hour
int job(int x){//if maximum job=i
  int i,j=0,work;
  for(i=0;i<k;i++){
    work=0;
    while(work+A[j]<=x&&j<n){
      work+=A[j];
      j+=1;
    }
  }
  if(j==n){
    return 1;
  }
  else{
    return 0;
  }
}


int main(){
  int i, lb, ub,mid;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb=0;
  ub=1000000000;
  while((ub-lb)>1){
    mid=(lb+ub)/2;
    if(job(mid)==1){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  printf("%d\n",ub);

  return 0;
}
