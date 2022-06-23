#include <stdio.h>
#include <math.h>

int n;
int k;
int A[100000];

int
p (int m)
{
  int i;
  int s = 0;
  for (i = 1; i <= n; i++)
    {
      s += (A[i]+m-1) / m;
    }
  return s <= k;
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
  //volume 0 means that no one is able to bring back apples,so infeasible
  
  //if n=k=1,a[1]=1,then 0+1=1 is feasible

  lb = 0;
  
  //10^9 is not smaller than any member of A[i]s, so feasible

  //if n=k=1,A[1]=10^9,then 10^9-1 is unfeasible
  
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
