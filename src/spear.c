#include <stdio.h>

int n;
int k;
int A[100000];

int spear(int mid){
    int m = 0;
    for (size_t i = 0; i < n; i++)
    {
        m += A[i] / mid;
    }
    if(m >= k)return 1;
    else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9+1;

  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(spear(mid)) lb = mid;
    else ub = mid;
  }

  printf("%d\n",lb);

  return 0;
}
