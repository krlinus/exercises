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
 

