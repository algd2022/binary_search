#include <stdio.h>

int n;
int k;
int A[100000];

int apple(int mid){
    int m = 0;
    for (size_t i = 0; i < n; i++)
    {
        m += (A[i] + mid - 1) / mid;
    }

    if(m <= k)return 1;
    else return 0;
    
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9;

  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(apple(mid))ub = mid;
    else lb = mid;
  }

  printf("%d\n",ub);

  return 0;
}
