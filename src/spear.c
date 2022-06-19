#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x,int k,int n,int A[]){
  int i,sum=0;
  for(i=0;i<n;i++){
    sum+=A[i]/x;
  }
  return sum>=k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  /*
  lb:必要な槍の本数が作れること(sum>=k)がわかっている最大の数
  ub:必要な槍の本数が作れないこと(sum<k)がわかっている最小の数
  */
  lb=0,ub=1000000001;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if (p(mid,k,n,A)) lb=mid;
    else ub=mid;
  }
  printf("%d",lb);
  return 0;
}
