#include <stdio.h>

int n;
int k;
int A[100000];//length of tree
int spear[100000];

int main(){
  int i,x,sum=0,num,lb, ub,mid;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    sum+=A[i];
  }
  spear[0]=0;
  for(x=1;x<=sum;x++){
    num=0;
    for(i=0;i<n;i++){
      num+=A[i]/x;//number of spears
    }
    if(num<k){
      spear[x]=0;
    }
    else{
      spear[x]=1;
    }
  }

  lb=1;
  ub=sum;
  while((ub-lb)>1){
    mid=(lb+ub)/2;
    if(spear[mid]==0){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  printf("%d\n",lb);
  return 0;
}
