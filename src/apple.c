#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int need_bags = 0;
  for(int i = 0; i < n; i++){
    need_bags += (A[i] + m - 1) / m;
  }
  return need_bags <= k;
}

int MaxOfA(){ //A[0]~A[n-1]のうち最大値を返す
  int max = A[0];
  for(int i = 0; i < n; i++){
    max = (max < A[i]) ? A[i] : max;
  }
  return max;
}

int main(){
  int lb, ub;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 1 - 1; //1 <= a_iより答えとしてありえる最小値は1
  ub = 1000000000; //答えとしてありえる最大値は定数なら10^9
  //ub = MaxOfA(); //n=kの場合xの最小値はMax(a)であり，これが答えとしてありえる最大値
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
