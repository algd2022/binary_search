#include <stdio.h>

int n;
int k;
int A[100000];

// a[start+1] + ... + a[i] <= max を満たす最大の start <= i <= n-1
// ただし i = start の場合は式が成り立つと考える
int take(int n, int a[], int max, int start){
  int i;
  int sum = 0;
  for (i = start+1; i < n; i++){
    sum = sum + a[i];
    if (sum > max) return i-1;
  }
  return n-1;
}

// x時間以下と仕事量を制限したとき働ける
int p(int n, int a[], int k, int x){
  int i;
  int comp = -1;
  for (i = 0; i < k; i++){
    comp = take(n, a, x, comp);
  }
  if (comp == n-1) return 1; //働けるとき1働けないとき0
  else return 0;
}
// 単調性(p(x)=1/\p(x+1)=0となることがない):x時間以下で働ければx+1時間以下で働ける

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0; // 0+1時間以下で...働けるケース:n=1,a=[1],k=1
  ub = 1000000000; //=(10^4)*(10^5) (10^4)*(10^5)-1時間以下で...働けないケース:n=10^5,a=[10^4,10^4...10^4],k=1
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (p(n, A, k, mid)){
      ub = mid;
    } else {
      lb = mid;
    }
  }

//x時間以下で働ける最小のxはそのときの一番仕事量が多い人の仕事量である
//なぜならそのときの一番仕事量の多い人の仕事量はx時間以下でありx時間未満の値yならy時間以下で働けているので
//xが...時間以下で働ける最小の値であることに反する
  printf("%d\n", ub);
  return 0;
}