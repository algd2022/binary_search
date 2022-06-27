#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){ 
/*
仕事量がxを超えたら次の人に交代していき、
n時間の仕事をk人でやりきることができる場合1を返し、そうでない場合0を返す関数
こうすれば、xが与えられたときにそれ以上の仕事をする人がいないことが保証される
また、この関数の手順から、xを最小化したときｘは必ず連続する時間の仕事量の和で表わせる
この関数の中身が、任意の人に対して一人あたりの仕事量<=xとなることを確かめているもので、
これを満たすようにxを最小化したら当然仕事量が最も多い人の仕事量=xとなるからである
*/
  int work = 0; //今注目している人が各時点でどれだけ仕事をしたか
  int worker = 1; //今何人目か
  int i;
  for(i = 0; i < n; i ++){
    if(A[i] > x){
      return 0;
    } //単一の仕事でxを超えてはならない
    else if(work + A[i] <= x){ 
      work = work + A[i];
    }//注目している人がこの時間を働いてもxを超えないときその仕事をする
    else{
      worker = worker + 1; //もうひとり増やす
      work = A[i]; //増やした人は、i時間目の仕事から始める
    }
  } //ここまでで、worker人かけて仕事を終えることができた
  if ( worker <= k){
    return 1;
  }
  else{
    return 0;
  }
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0; //どんな場合にもp(x)=0となるxは0しかない
  ub = 1e9; //どんな場合にもp(x)=1となるxで最小のものは、n=100000、ai=10000、k=1を考えたら良い
  while(ub - lb > 1){
    int mid = (ub + lb) / 2;
    if (p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
