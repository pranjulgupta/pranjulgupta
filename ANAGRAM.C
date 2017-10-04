#include<stdio.h>
#include<conio.h>
int anagram(char[],char[]);
int main()
{
char a[30],b[30];
int flag;
//clrscr();
printf("entre the 2 string:\n");
gets(a);
gets(b);
flag=anagram(a,b);
if(flag==1)
printf("string is anagram");
else
printf("string is not anagram");
//getch();
}
int anagram(char a[],char b[])
{ int i=0,n1[26]={0},n2[26]={0};
while(a[i]!='\0')
{
n1[a[i]-'a']++;
i++;
}
i=0;
while(b[i]!='\0')
{
n2[b[i]-'a']++;
i++;
}
for(i=0;i<26;i++)
{if(n1[i]!=n2[i])
return 0;
}
return 1;
}
