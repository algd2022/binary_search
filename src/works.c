#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x) {
    int  b_sum = 0, count = 0;
    for (int i = 0; i < n) {
        if (A[i] > x)return 0;
        if (A[i] + b_sum > x) {
            b_sum = A[i];
            count++;
        }
        else b_sum += A[i];
    }
    if (count < k)return 1;
    else return 0;


}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000001;
  while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (p(mid)) {
          ub = mid;
      }
      else lb = mid;
  }


  return 0;
}
