#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i,j,sum=0,sub_k, lb, ub,mid;
  int apple[100000];//apple[i]=1--if strage of bag=i,succeed
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    sum+=A[i];
  }

  for(i=1;i<=sum;i++){
    sub_k=k;
    for(j=0;j<n;j++){
      sub_k-=(A[j]+i-1)/i;//round up A[i]/i
    }
    if(sub_k>=0){
      apple[i]=1;
    }
    else{
      apple[i]=0;
    }
  }

  lb=1;
  ub=sum;
  while((ub-lb)>1){
    mid=(lb+ub)/2;
    if(apple[mid]==1){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  printf("%d\n",ub);
  return 0;
}
