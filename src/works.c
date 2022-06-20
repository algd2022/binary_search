#include <stdio.h>

int n;
int k;
int A[100000];


int max_work(int m) {
    int j, work_per = 0, member = 1;
    for (j = 0; j < n; j++) {           
        if (A[j] > m) {                 //矛盾
            member = 100001;  //必ずmember > k　
            break;      
        }

        if (A[j] + work_per > m) {      //交代
            member = member + 1;
            work_per = A[j];    
        }
        else {                          //継続
            work_per = work_per + A[j]; 
        }
    }

    return (long long int) member <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  int h, sum_work = 0;
  for (h = 0; h < n; h++) {
      sum_work = sum_work + A[h];
  }

  lb = 0;            //x:取りうる最小1 = 返り値0
  ub = sum_work;   //x:取りうる最大sum_work = 返り値1


  while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (max_work(mid)) {
          ub = mid;
      }
      else {
          lb = mid;
      }
  }

  printf("%d\n", ub);       //上から抑える
  return 0;
}
