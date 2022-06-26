#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){                  //mを変数にとる関数p()を設定
  int sum = 0;                 //作れる槍の総数sumを定義
  for(int s = 0; s < n; s++){  //変数sについて以下の操作を繰り返し
    sum = sum + (A[s]/ m);     //木1本あたりで作れる槍の数を足す
  } 
  return sum >= k;             //単調関数の設定
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    lb = 0;                   //領域下限の初期値を0に設定(1と設定するとkが十分大きい時に1を返してしまう)
    ub = 1000000001;          //領域上限の初期値を10^9(n=k=1 a_1=10^9のときの槍の長さ)+1に設定
    while(ub - lb > 1){       //ub > lb+1の間以下を繰り返し
      int mid = (lb + ub) / 2;//領域中央値midの定義
      if(p(mid)){             //p(mid)が1であれば
        lb = mid;             //領域下限lbをmidの値に指定　p()は単調非増加であることに留意
      }
      else {                  //p(mid)が0であれば
        ub = mid;             //領域上限ubをmidの値に指定
    }
    }
  }

  printf("%d\n",lb);          //繰り返し終了後のlbの値(求める値x)を出力
  return 0;
}

