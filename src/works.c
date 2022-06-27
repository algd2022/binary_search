#include <stdio.h>
#include <stdbool.h>
#include <string.h>

unsigned int n;
unsigned int k;
unsigned int A[100000];


int s(){
  int sum = 0;
  for(int j = 0; j < n; j++){
    sum += A[j];
  }
  return sum;
}

int m(unsigned int B[]){
  int max = 0;
  for(int j = 0; j < n; j++){
    if(max <= B[j]) max = B[j];
  }
  return max;
}

//人の入れ替わりがk-1回起こるようにする
int p(int m){
  int sum = 0;
  int people = 1;
  for(int a = 0; a < n; a++){
    //a=0から足すだけだとｍの最小値が求まらないため、
    //0からn-1まで全てを出発点にする必要がある。
    sum += A[a];
    if(sum > m){
      sum = 0;
      people++;
    }
  }
  return (long long int) people <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = m(A) - 1;
  ub = s();
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  
  printf("%d\n", ub);
  return 0;
}
