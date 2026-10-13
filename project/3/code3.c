#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
int IsPalindrome(char str[])
 {
    char stack[MAXSIZE];
    int top = -1;  
     int len = strlen(str);
    int i, mid;    
     mid = len / 2;
    for(i = 0; i < mid; i++)
    {
        stack[++top] = str[i];
    }
    if(len % 2 == 1)
        i = mid + 1;
    else
        i = mid;
    while(top != -1)
    {
        if(stack[top--] != str[i++])
        {
            return 0;  
         }
    }
    return 1; 
}
int main()
 {
    char s[MAXSIZE];
    printf("请输入字符串：");
    scanf("%s", s);
    if(IsPalindrome(s))
        printf("是回文\n");
    else
        printf("不是回文\n");
    return 0;
 }