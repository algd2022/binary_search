#include <stdio.h>
#include <math.h>

int n;
int k;
int A[100000];



int
p (int m)
{
int i=1;//index of assignment to be finished
int person=1;//number of people who attended the work
int s=0;
  //while there is assignment undone and personel available
  while(i<=n&&person<=k){
  // every person works continuously until working hours would 
  //surpass m to finish the next assignment
    if(s+A[i]<=m){
    s+=A[i];
    i++;
    }
    else{
        person+=1;
        s=0;
    }
  }
  // the negation of the looping condition is i>n or person>k
  // it requires no more than k people to finish the work
  if(i>n){
      return person<=k;
}
  // if there are no personel available and there is assignment left, then 
  //m is not feasible
  else{
      return 0;
  }
}
int
main ()
{
  int i, lb, ub;
  scanf ("%d%d", &n, &k);
  for (i = 1; i <= n; i++)
    {
      scanf ("%d", &A[i]);
    }
  //0 means no assignment can be finished, so infeasible
  
  //if n=k=1,A[1]=1, then 1 is feasible
    
  lb = 0;
  
  //10^9 is not smaller than the sum of required time of all assignments,so feasible
  
  //if n=10^4,k=1,for all i in J_n,A[i]=10^5,then 10^9-1 is infeasible
  
  ub = pow(10,9);
  while (ub - lb > 1)
    {
      int mid = (ub + lb) / 2;
      if (p (mid))
	{
	  ub = mid;
	}
      else
	{
	  lb = mid;
	}
    }
  printf ("%d\n", ub);
  return 0;
}
