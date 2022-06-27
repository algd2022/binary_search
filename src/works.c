#include <stdio.h>

int n;
int k;
int A[100000];

int p(int index[],int mid){
    int sum = 0;
    //人数のカウント、これとkを比較し評価
    int count = 1;
    int a;
    int error = 0;
    for(a=0;a<n;a++){
        if(sum+index[a]<=mid){
            sum = sum + index[a];
        }
        else if(index[a]>mid){
        	//midより大きい数値があったらlbを更新するようにする
        	a++;
        	count=k;
        	error++;
        }
        else{
        	//オーバーしたら次のカウントへ
            count++;
            //リセット
            a--;
            sum=0;
        }
    }
    if(error==1){
    	count=count+1;
    }
    return count;
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
    int mid = (lb + ub)/2;
    //ここで評価する
    if(p(A, mid) <= k){
        ub = mid;
    }
    else{
        lb = mid;
    }
  }
  printf("%d\n",ub); 
  return 0;
}
