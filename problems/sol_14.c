<<<<<<< HEAD
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

=======

/*
12. Given a non-negative integer num, repeatedly add all its digits until the result has only 1 digit
*/

#include <stdio.h>
#include <string.h>

void to_str(int n, char *str) {
  int i=0;
  while(n) {
    int t = n % 10;
    str[i] = t + '0';
    i++;
    n /= 10;
  }
  str[i]='\0';
}

int warp(char *strnum) {
  int l;
  int res=0;
  while((l=strlen(strnum)) > 1) {
    res=0;
    for(int i=0;i<l;++i) {
      res += strnum[i] - '0';
    }
    to_str(res,strnum);
  }
  return res;
}

int main() {
  char numbuf[1000];
  scanf("%s",numbuf);
  printf("%d\n",warp(numbuf));
  return 0;
}
 
>>>>>>> b87a14e2fafaf81bc6c34f48704ca50d99f18917
