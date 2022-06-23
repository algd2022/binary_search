#include <stdio.h>

int n;
int k;
int A[100000];

// 長さxの槍をk本も作ることができない
int p(int n, int a[], int k, int x){
  int i;
  int sum = 0; //作ることができる槍の本数
  for(i = 0; i < n; i++){
    sum = sum + (a[i] / x);
  }
//  printf("sum %d k %d\n", sum, k);
  return (sum < k); //作ることができないかどうか...できるとき0できないとき1
}
// 単調性(p(x)=1/\p(x+1)=0となることがない):長さxで作れなければ長さx+1で作れない

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0; // 0+1の槍を...できないケース:n=1,a=[1],k=2
  ub = 1000000000+1; //=10^9+1 10^9の槍を...できるケース:n=1,a=[10^9],k=1
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
//    printf("lb %d ub %d mid %d p %d\n", lb, ub, mid, p(n, A, k, mid));
    if (p(n, A, k, mid)){
      ub = mid;
    } else {
      lb = mid;
    }
  }

// ubの値は...できないもののうち最小なので、...できるものの最大がub-1
  printf("%d\n", ub-1);
  return 0;
}