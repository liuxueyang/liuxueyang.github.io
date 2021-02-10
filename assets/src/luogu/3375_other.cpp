#include <stdio.h>
#include <string.h>

const int N = 1000010;
int next[N];

char s1[N], s2[N];

// 不知道这个人写的错在哪里了
// 看来下标从 0 开始太麻烦了。

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void gennext(int *next,char *s2)
{
  next[0]=0;
  int len=-1;
  for(int i = 1;i < strlen(s2); i++)
    {
      while(len!=-1&&s2[i]!=s2[len])//注意啦！！ len若可以为0 则开始会被卡住  //不匹配但是小了没准可以
        //针对一个 i （及i处的真前后缀匹配）(i trasverse through the whole)  用while 往前跳
        len=next[len];
      if(len != -1 && s2[i]==s2[len]){
        len++;
      }
      if (len == -1) next[i] = 0;
      else
        next[i] = len; //匹配了就+1；
    }
}

void kmp(char *s1, char *s2)
{
  int i=0,j=0;
  for( i = 0;i < strlen(s1);i++)//i一直动着 ，没必要匹配成功了，i在回去，j会自动调整的
    {

      while(j && s1[i]!=s2[j])//调整移动时 i 不变
        {
          j=next[j];
        }

      if(j != -1 &&s1[i]==s2[j])
        {
          j++;
        }
      if (j == -1) j = 0;
      if(j==strlen(s2))
        {
          printf("%d\n",int(i-strlen(s2)+2) );
          j = next[j-1];
        }
    }
}

int main(int argc, char** argv) {
#ifdef _DEBUG
  freopen("3375.in", "r", stdin);
#endif

  scanf("%s",s1);
  scanf("%s",s2);
  gennext(next, s2);
  kmp(s1,s2);
  for(int i=0;i<strlen(s2);i++)
    {
      printf("%d ",next[i]);
    }
  printf("\n");

  return 0;
}
