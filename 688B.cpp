#include<bits/stdc++.h>
using namespace std;
char ch[100010];
int main()
{
    scanf("%s",ch);
    int i=0;
    while(ch[i]){
        printf("%c",ch[i]);
        i++;
    }
    i--;
    while(i>=0){
        printf("%c",ch[i]);
        i--;
    }
}
