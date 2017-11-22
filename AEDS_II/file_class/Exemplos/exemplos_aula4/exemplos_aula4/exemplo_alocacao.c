#include<stdio.h>
#include<stdlib.h>

void aloca(int *x, int n) 
{ 
  x=(int *)malloc(n*sizeof(int));
  x[0] = 20;
} 


int main() 
{ 
  int *a;	
  aloca(a, 10); 
  a[1] = 40;
} 



// void aloca(int **x, int n) 
// { 
//   *x=(int *)malloc(n*sizeof(int));
//   *x[0] = 20;
// } 

// int main() 
// { 
//   int *a;	
//   aloca(&a, 10); 
//   a[1] = 40;
// } 