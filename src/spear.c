#include <stdio.h>

int n;
int k;
int A[100000];

int p(int index[],int mid){
    int sum = 0;
    int a;
    for(a=0;a<n;a++){
        //切り捨てで考える
        sum = sum + index[a]/mid;
    }
    return sum;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000001;
  while(ub - lb > 1){
    int mid = (lb + ub)/2;
    if(p(A, mid) < k){
        ub = mid;
    }
    //k以上になった時に下限を上げて終了条件
    else{
        lb = mid;
    }
  }
  printf("%d\n",lb); 
  return 0;
}
