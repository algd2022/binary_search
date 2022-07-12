#include <stdio.h>

int n;
int k;
int A[100000];//length of tree
int spear(int x){//if length=x
  int i,num=0;
  for(i=0;i<n;i++){
    num+=A[i]/x;//number of spears
  }
  if(num<k){
    return 0;
  }
  else{
    return 1;
  }
}

int main(){
  int i,lb, ub,mid;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb=0;
  ub=1000000001;
  while((ub-lb)>1){
    mid=(lb+ub)/2;
    if(spear(mid)==0){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  printf("%d\n",lb);
  return 0;
}
