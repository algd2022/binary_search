#include <stdio.h>

int n;
int k;
int A[100000];

int long_spear(int m) {
    int j, spear = 0;
    for (j = 0; j < n; j++) {
        spear = spear + A[j] / m;       //切り下げ
    }
    return (long long int) spear >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;               //x:取りうる値の最小0 = 返り値1
  ub = 1000000001;      //x:取りうる値の最大10^9 = 返り値0

  while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (long_spear(mid)) {
          lb = mid;
      }
      else {
          ub = mid;
      }
  }

  printf("%d\n", lb);           //下から抑える
  return 0;
}
