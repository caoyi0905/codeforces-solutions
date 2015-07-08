#include <bits/stdc++.h>
using namespace std;
char ch;
int n,w,h,t;
set<int> x,y,*s;
set<int>::iterator l,r;
multiset<int> lx,ly,*ls;
int main(){
    ios::sync_with_stdio(false);
    cin>>w>>h>>n;
    x.insert(0);x.insert(w);
    y.insert(0);y.insert(h);
    lx.insert(w);ly.insert(h);
    for(int j=1;j<=n;j++){
        cin>>ch>>t;
        if(ch=='H') {s=&y; ls=&ly;} else {s=&x; ls=&lx;}
        s->insert(t);
        l=r=s->find(t);
        l--; r++;
        ls->erase(ls->find(*r-*l));
        ls->insert(t-*l);ls->insert(*r-t);
        cout<<(long long)*lx.rbegin()**ly.rbegin()<<endl;
    }
}
