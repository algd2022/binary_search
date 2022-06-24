#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int sum=0, i,w=0;
  for(i = 0; i < n; i++){
    if(A[i]>x) return 0;
    if(sum+A[i]>x){
      w++;
      sum=0;
    }
    sum+=A[i];
  }
  return w<=k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9+1;
  while (ub-lb>1)
  {
    int mid= (lb + ub) / 2;
    if (p(mid)) ub = mid;
    else lb = mid;
  }

  printf("%d\n",ub);
  
  return 0;
}
