#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int num_of_people = 1;
  int time_of_work = 0;
  for(int i = 0; i < n; i++){
    if(A[i] > m) return 0;
    if(time_of_work + A[i] <= m){
      time_of_work += A[i];
    }
    else {
      num_of_people++;
      time_of_work = A[i];
    }
  }
  return num_of_people <= k;
}

int SumOfA(){ //A[0]~A[n-1]の和を返す
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += A[i];
  }
  return sum;
}

int main(){
  int lb, ub;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 1 - 1; //答えとしてありえる最小値は1
  ub = 1000000000; //答えとしてありえる最大値は定数なら10^4 x 10^5 = 10^9
  //ub = SumOfA(); //1人がすべての仕事をするときが最大なので，答えとしてあり得る最大値はsum(a)
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
