#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);   
  }
    lb = -1;                    //領域下限の初期値を-1に設定
    ub = n;                     //領域上限の初期値をnに設定
    while(ub - lb > 1){         //ub > lbの間以下を繰り返し
      int mid = (lb + ub) / 2;  //領域中央値midの定義
      if(A[mid] >= k) ub = mid; //領域中央値midがkより大きければ、領域上限ubをmidの値に指定
      else lb = mid;            //領域中央値midがkより小さければ、領域下限lbをmidの値に指定
    }
  
  printf("%d\n",ub);            //繰り返し終了後のubの値(求める値x)を出力
  return 0;
}

