// Problem#: 1136
// Submission#: 3586681
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<algorithm>
#include<stdio.h>
#define RANGE 100005
#define INF 0x7fffffff
using namespace std;
struct node
{
    int l,r,sum;            //当前节点左边界、右边界、元素总和
    int lmn,rmn,lmax,rmax;  //从左边界开始连续到第lmn位置元素和，有最大值lmax
                            //从右边界开始连续到第rmn位置元素和，有最大值rmax
    int lson,rson;          //节点左儿子和右儿子的编号
    int sl,sr,smax;         //当前序列从sl到sr能取得最大连续值smax
}nn[RANGE*6];               //输入的线段树需要的空间为2*N（开3*N的数组)，计算时建立新树，故翻倍
int n,m,a[RANGE*2];
int nnum;                   //每次解决查询时，建立新的线段树节点的开始下标

void computeMax(int index, int ls, int rs)//计算index节点的sum,sl,sr,smax,lmn,lmax,rmn,rmax
{
     int tmp;
     nn[index].sum=nn[ls].sum+nn[rs].sum;

     nn[index].smax=nn[ls].smax;
     nn[index].sl=nn[ls].sl;
     nn[index].sr=nn[ls].sr;
     tmp=nn[ls].rmax+nn[rs].lmax;
     if(tmp>nn[index].smax || (tmp==nn[index].smax && nn[ls].rmn<nn[index].sl))
     {
        nn[index].smax=nn[ls].rmax+nn[rs].lmax;
        nn[index].sl=nn[ls].rmn;
        nn[index].sr=nn[rs].lmn;
     }
     if(nn[rs].smax>nn[index].smax)
     {
        nn[index].smax=nn[rs].smax;
        nn[index].sl=nn[rs].sl;
        nn[index].sr=nn[rs].sr;
     }

     //计算当前节点的lmax与rmax
     tmp=nn[ls].sum+nn[rs].lmax;
     if(tmp>nn[ls].lmax)
     {
         nn[index].lmax=tmp;
         nn[index].lmn=nn[rs].lmn;
     }
     else
     {
         nn[index].lmax=nn[ls].lmax;
         nn[index].lmn=nn[ls].lmn;
     }
     tmp=nn[rs].sum+nn[ls].rmax;
     if(tmp>=nn[rs].rmax)//注意等于号
     {
         nn[index].rmax=tmp;
         nn[index].rmn=nn[ls].rmn;
     }
     else
     {
         nn[index].rmax=nn[rs].rmax;
         nn[index].rmn=nn[rs].rmn;
     }
}
int compute(int l, int r, int index)
{
    if(l==nn[index].l && r==nn[index].r)
     return index;

    int ls=index*2;     //左二子标号
    int rs=index*2+1;   //右儿子标号
    if(r<=nn[ls].r)
        return compute(l,r,ls);
    else if(l>=nn[rs].l)
        return compute(l,r,rs);
    else
    {
        int nindex=nnum++;
        nn[nindex].l=l; nn[nindex].r=r;
        nn[nindex].lson=compute(l,nn[ls].r,ls);
        nn[nindex].rson=compute(nn[ls].r+1,r,rs);
        computeMax(nindex, nn[nindex].lson, nn[nindex].rson);
        return nindex;
    }
}
void buildTree(int l, int r, int index)
{
     nn[index].l = l;
     nn[index].r = r;
     if(l==r)
     {
         nn[index].sum=nn[index].smax=nn[index].lmax=nn[index].rmax=a[l];
         nn[index].lmn=nn[index].rmn=nn[index].sl=nn[index].sr=l;
         return;
     }
     int mid=(l+r)/2;
     int ls,rs;   //左右儿子编号
     ls=index*2; rs=index*2+1;
     buildTree(l,mid,ls);
     buildTree(mid+1,r,rs);

     computeMax(index, ls, rs);
}
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
     scanf("%d",&a[i]);
    buildTree(1,n,1);
    for(int i=1;i<=m;++i)
    {
        int tmpa,tmpb;
        scanf("%d%d",&tmpa,&tmpb);
        nnum=3*n+1;
        int nindex = compute(tmpa,tmpb,1);
        printf("%d %d %d\n", nn[nindex].sl, nn[nindex].sr, nn[nindex].smax);
    }
}                                 