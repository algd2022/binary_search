#include <stdio.h>

int n;
int k;
int A[100000];

int p(int mid,int n,int k,int A[]){
  int w_amount=0,w_sumper=1,i;

  for(i=0;i<n;i++){
    if(A[i]>mid) return 0;
    w_amount+=A[i];
    if(w_amount>mid){
      w_amount=0;
      w_sumper++;
      i--;
    }
    }
    return w_sumper<=k;
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
    int mid=(ub+lb)/2;
    if(p(mid,n,k,A)) ub=mid;
    else lb=mid;
  }
  printf("%d\n",ub);
  return 0;
}
