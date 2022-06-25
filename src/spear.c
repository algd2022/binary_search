#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int x){
  int i;
  int sum = 0;
  for(i = 0; i < n;i++){
    sum += A[i] / x;
  }
  return sum < k;//単調非減少にする．
}

int my_pow(int base, unsigned int exp) {
    unsigned int i;
    int ans;
    ans = 1;
    for (i = 0; i < exp; i++) {
        ans = ans * base;
    }
    return ans;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = my_pow(10,9) + 1;//10^9 + 1
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n",lb);//関数pのreturnの条件よりlbを出力する

  return 0;
}
