#include<bits/stdc++.h>
using namespace std;
const int MAXN=2002;
const double eps=1e-8;
struct point
{
    double x,y;
    int id;
    bool operator < (point b)const
    {
        return x==b.x?y<b.y:x<b.x;
    }
};
point pp[MAXN];
int tot;  //tot指去重后的点数
bool zero(double k)
{
    if(fabs(k)<eps)
        return 1;
    return 0;
}
double cross(point p0,point p1,point p2) //计算叉积  p0p1 X p0p2
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double dis(point p1,point p2)  //计算 p1p2的 距离
{
    return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}
bool cmp(point p1,point p2) //极角排序函数 ， 角度相同则距离小的在前面
{
    double tmp=cross(pp[0],p1,p2);
    if(tmp>0.0) return true;
    else if(zero(tmp)&&dis(pp[0],p1)<dis(pp[0],p2)) return true;
    else return false;
}
void init(int n) //输入，并把  最左下方的点放在 pp[0]  。并且进行极角排序
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&pp[i].x,&pp[i].y);
        pp[i].id=i;
    }
    sort(pp,pp+n);
    sort(pp+1,pp+n,cmp);
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        init(n);
        int tmp=0;
        for(int i=n-2;i>0;i--)
            if(cross(pp[0],pp[n-1],pp[i])!=0){
                tmp=i;
                break;
            }
        reverse(pp+tmp+1,pp+n);
        for(int i=0;i<n;i++) printf("%d ",pp[i].id);
        puts("");
    }
}

