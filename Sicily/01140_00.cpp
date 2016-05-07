// Problem#: 1140
// Submission#: 3587451
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 30005;
int N,K;
int head[MAX],next[MAX*2],V[MAX*2],edge;
int prt[MAX],cnt[MAX],minID[MAX],ans[MAX];
bool del[MAX],vis[MAX];
void addEdge(int u,int v)
{
    V[edge] = v;
    next[edge] = head[u];
    head[u] = edge++;
}
void init(int x,int fa)//预处理以x为根的情况
{
    cnt[x] = 1;
    prt[x] = fa;
    minID[x] = x;
    for(int e = head[x];e != -1;e = next[e])
    {
        int y = V[e];
        if(fa == y || del[y])   continue;
        init(y,x);
        cnt[x] += cnt[y];
        minID[x] = min(minID[x],minID[y]);
    }
}
void dfs(int x,int fa,int flag)
{
    del[x] = 1;
    for(int e = head[x];e != -1;e = next[e])
    {
        int y = V[e];
        if(fa == y || del[y] || y == flag)  continue;
        dfs(y,x,flag);
    }
}
void solve()
{
    int flag,_max,_min;
    for(int i = 1;i < K;++i)
    {
        int root = 1;
        while(del[root])    root++;
        init(root,0);
        _max = 0;
        _min = MAX;
        for(int i = 1;i <= N;++i)
        {
            if(i == root ||del[i])  continue;
            int t1 = cnt[root] - cnt[i];
            int t2 = cnt[i];
            if(t1 == t2)
            {
                _max = t1;
                flag = i;
                _min = minID[root];
                break;
            }
            if(t1 > _max && t1*2 <= cnt[root])
            {
                flag = i;
                _max = t1;
                _min = minID[root];
            }
            if(t2 >= _max && t2*2 <= cnt[root])
            {
                if(t2 == _max && minID[i] < _min)
                {
                    _max = t2;
                    flag = i;
                    _min = minID[i];
                }
                else if(t2 > _max)
                {
                    _max = t2;
                    flag = i;
                    _min = minID[i];
                }
            }
        }
        if(cnt[flag] >= cnt[root] - cnt[flag])
        {
            ans[i] = cnt[root] - cnt[flag];
            dfs(root,0,flag);
        }
        else
        {
            ans[i] = cnt[flag];
            dfs(flag,prt[flag],prt[flag]);
        }
    }
    ans[K] = N;
    for(int i = 1;i < K;++i)
    {
        printf("%d ",ans[i]);
        ans[K] -= ans[i];
    }
    printf("%d\n",ans[K]);
}
int main()
{
    int u,v;
    memset(head,-1,sizeof(head));
    scanf("%d%d",&N,&K);
    for(int i = 1;i < N;++i)
    {
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    solve();
}                                 