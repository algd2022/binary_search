#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int x){
  int i;
  int worklord = 0;
  int number = 1;
  for(i = 0; i < n;i++){
    if(A[i] > x){//仕事量xより大きな仕事量A[i]が存在する
      return 0;
    }
    else if (worklord + A[i] <= x){//仕事を継続する
      worklord += A[i];
    }
    else{//仕事を次の人に受け渡す
      worklord = A[i];
      number++;
    }
  }
  return number <= k;
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
  ub = my_pow(10,9);//10^9の計算。
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n",ub);

  return 0;
}
