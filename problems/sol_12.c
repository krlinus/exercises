/*
12. Given an array of integers possibly containing negative numbers, find the
contiguous subarray with the maximum sum
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  scanf("%d",&N);

  int b,e,g; /* begin, end, gains */
  b=g=0;
  e=-1;
  int B,E,G; /*known "good" values of b,e,g*/
  B=E=G=0;
  do{
   int n=0;
   scanf("%d",&n);
   e++;
   if(g + n <= 0) { //when gains are wiped out, time to restart
     b=e;
     g=0;
   } else {
     if(g==0) b=e;
     g += n;
     if(g > G) {
       G=g;
       B=b;
       E=e;
     }
   }
  }while(--N > 0);
  printf("B=%d, E=%d, G=%d\n",B,E,G);
  return 0;
}

