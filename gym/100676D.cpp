#include<bits/stdc++.h>
using namespace std;
char a[11][11];
int dx[]={1,1,1,4,4,4,7,7,7};
int dy[]={1,4,7,1,4,7,1,4,7};
bool check(string s){
    for(int i=1;i<=9;i++)
        if(s.find(char('0'+i))==std::string::npos) return 0;
    return 1;
}
bool judge(){
    int i,j;
    for(i=1;i<=9;i++){
        string s="";
        for(j=1;j<=9;j++) s+=a[i][j];
        if(!check(s)) return 0;
    }
    for(i=1;i<=9;i++){
        string s="";
        for(j=1;j<=9;j++) s+=a[j][i];
        if(!check(s)) return 0;
    }
    for(int k=0;k<9;k++){
        string s="";
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                s+=a[i+dx[k]][j+dy[k]];
        if(!check(s)) return 0;
    }
    return 1;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        for(int i=1;i<=9;i++) cin>>a[i]+1;
        puts(judge()?"Valid":"Invalid");
    }
}
