#include <stdio.h>

int n;
int k;
int A[100000];

int p(int index[],int mid){
    int sum = 0;
    //人数のカウント、これとkを比較し評価
    int count = 1;
    int a;
    for(a=0;a<n;a++){
        if(mid>=index[a]){
        	sum=sum+index[a];
        	//仕事量がmid超えるか確認
        	if(sum>mid){
        		//次の人に移る
        		count=count+1;
        		//次の仕事を保存
        		sum=index[a];
        	}
        }
        else{
        	//ありえないパターン
        	return k+1;
        }
    }
    if(count>k){
    	return k+1;
    }
    else{
    	return count;
    }
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
