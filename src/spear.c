#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int tmp = 0;
    for (int i=0; i<n; i++){
      tmp += A[i]/m;
    }
  return tmp < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  // p(n) : 長さXの槍をできるだけ作ろうとすると, k本未満になってしまう.
  // lb : k本以上つくれる最大値を出力すればok
  ub = 1000000001;
  lb = 0;
  while (ub-lb>1){
    int mid = (ub+lb)/2;
    if (p(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}
