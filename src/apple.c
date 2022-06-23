#include <stdio.h>

int n;
int k;
int A[100000];

// x個のりんごが入るバッグを合計k個配ると全員がりんごを持って帰れる
int p(int n, int a[], int k, int x){
  int i;
  int sum = 0;
  for(i = 0; i < n; i++){
    sum = sum + ((a[i] + x - 1) / x);
  }
  return (sum <= k); //帰れないとき0帰れるとき1
}
// 単調性(p(x)=1/\p(x+1)=0となることがない):x個で帰れればx+1個で帰れる

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0; // 0+1個のリンゴが...帰れるケース:n=1,a=[1],k=1
  ub = 1000000000; //=10^9 10^9-1個のリンゴが...帰れないケース:n=1,a=[10^9],k=1
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (p(n, A, k, mid)){
      ub = mid;
    } else {
      lb = mid;
    }
  }

  printf("%d\n", ub);
  return 0;
}