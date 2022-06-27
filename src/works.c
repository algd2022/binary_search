#include <stdio.h>

int n;
int k;
int A[100000];

// 一人の仕事量がx以下のとき、k人に分配可能かどうか
unsigned int p(int x){
  int worked = 1; //仕事済みの人数 
  int sum =0; //現在仕事をしている人の合計仕事量の合計
  for (int i = 0; i < n; i++) {
    // i番目の仕事量がxを超えていたらfalse
    if (A[i] > x) {
      return 0;
    }
    sum += A[i];
    // 現在仕事している人の合計の仕事量がxを超えたら次の人に交代
    if (sum > x) {
      sum = A[i];
      worked++;
    } 
  }
  //仕事済みの人数がk人以下なら分配可能でtrueを返す
  return worked <= k;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  printf("%d\n", ub);


  return 0;
}
