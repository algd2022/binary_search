#include <stdio.h>
#include <math.h>

int n;
int k;
int A[100000];

int p(int m){
    int s=0;
    int i;
    for(i = 0; i < n; i++){
        s+=A[i]/m;
    }
    return s>=k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  //any amount of spear of length 0 can be made,so feasible

  //if n=1,k=2,A[0]=1,then 1 is infeasible

  lb=0;

  //No spear of length 10^9+1 can be made, so infeasible

  //if n=1,k=1,A[0]=10^9,then 10^9 is feasible

  ub=pow(10,9)+1;
  while (ub-lb>1){
      int mid=(ub+lb)/2;
      if (p(mid)){
          lb=mid;
      }
      else{
          ub=mid;
      }
  }
  printf("%d\n",lb);

  return 0;
}