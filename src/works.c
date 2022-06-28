#include <stdio.h>

int n;
int k;
int A[100000];

int work(int mid){
    int m = 1, l = 0;
    for (size_t i = 0; i < n; i++)
    {
        if(A[i] > mid) return 0;
        if (l + A[i] > mid)
        {
            m++;
            l = A[i];
        } else {
            l += A[i];
        }
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
    if(work(mid)) ub = mid;
    else lb = mid;
  }

  printf("%d\n",ub);

  return 0;
}
