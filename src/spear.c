#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i;
  int sum = 0;
  for (i = 0; i < n; i++){
    sum = sum +  A[i] / m;
  }
  return sum >=k;
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; //ヤリが作れない場合を考慮する
  ub = 1000000000+1; //入力制約とreturnが逆になるため
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if(p(mid)){
      lb = mid;
    }
    else {
      ub = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}


