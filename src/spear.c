#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int num_able_spear = 0;
  for(int i = 0; i < n; i++){
    num_able_spear += A[i] / m;
  }
  return num_able_spear < k;
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
  lb = 0; //答えとしてありえる最小値は0
  ub = 1000000000 + 1; //答えとしてありえる最大値は定数なら10^9
  //ub = MaxOfA() + 1; //答えとしてありえる最大値はMax(a)
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}
