#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define endl "\n"
#define FOR(i,x,y) for(int i=x;i<y;i++)
#define INF 1e16
#define Yuubari_chan_kawaii ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N=2e5+5;
int n,dfn[N],son[N],top[N],num[N],dep[N],p[N];
vector<int>path[N];
struct node
{
     int mx,sum;
}seg[N<<2];
void update(int x,int l,int r,int qx,int val)
{
     if(l==r)
     {
          seg[x].mx=seg[x].sum=val;
          return;
     }
     int mid=(l+r)>>1;
     if(qx<=mid)update(x<<1,l,mid,qx,val);
     else update(x<<1|1,mid+1,r,qx,val);
     seg[x].mx=max(seg[x<<1].mx,seg[x<<1|1].mx);
     seg[x].sum=seg[x<<1].sum+seg[x<<1|1].sum;
}
int big(int x,int l,int r,int ql,int qr)
{
     if(ql<=l&&r<=qr)return seg[x].mx;
     int mid=(l+r)>>1;
     int res=-INF;
     if(ql<=mid)res=max(res,big(x<<1,l,mid,ql,qr));
     if(mid<qr)res=max(res,big(x<<1|1,mid+1,r,ql,qr));
     return res;
}
int ask(int x,int l,int r,int ql,int qr)
{
     if(ql<=l&&r<=qr)return seg[x].sum;
     int mid=(l+r)>>1;
     int res=0;
     if(ql<=mid)res+=ask(x<<1,l,mid,ql,qr);
     if(mid<qr)res+=ask(x<<1|1,mid+1,r,ql,qr);
     return res;
}
void dfs1(int now)
{
     son[now]=-1;
     num[now]=1;
     for(auto i:path[now])
     {
          if(!dep[i])
          {
               dep[i]=dep[now]+1;
               p[i]=now;
               dfs1(i);
               num[now]+=num[i];
               if(son[now]==-1||num[i]>num[son[now]])son[now]=i;
          }
     }
}
int cnt;
void dfs2(int now,int t)
{
     top[now]=t;
     cnt++;
     dfn[now]=cnt;
     if(son[now]==-1)return;
     dfs2(son[now],t);
     for(auto i:path[now])
          if(i!=p[now]&&i!=son[now])
               dfs2(i,i);
}
int path_big(int x,int y)
{
     int res=-INF;
     while(top[x]!=top[y])
     {
          if(dep[top[x]]<dep[top[y]])swap(x,y);
          res=max(res,big(1,1,n,dfn[top[x]],dfn[x]));
          x=p[top[x]];
     }
     if(dfn[x]>dfn[y])swap(x,y);
     res=max(res,big(1,1,n,dfn[x],dfn[y]));
     return res;
}
int path_sum(int x,int y)
{
     int res=0;
     while(top[x]!=top[y])
     {
          if(dep[top[x]]<dep[top[y]])swap(x,y);
          res+=ask(1,1,n,dfn[top[x]],dfn[x]);
          x=p[top[x]];
     }
     if(dfn[x]>dfn[y])swap(x,y);
     res+=ask(1,1,n,dfn[x],dfn[y]);
     return res;
}
void buildTree()
{
     FOR(i,0,n-1)
     {
          int a,b;cin>>a>>b;
          path[a].pb(b);
          path[b].pb(a);
     }
}
void buildHLD(int root)
{
     dep[root]=1;
     dfs1(root);
     dfs2(root,root);
     FOR(i,1,n+1)
     {
          int now;cin>>now;
          update(1,1,n,dfn[i],now);
     }
}
void solve()
{
     cin>>n;
     buildTree();
     buildHLD(1);
     int q;cin>>q;
     while(q--)
     {
          string now;cin>>now;
          if(now=="CHANGE")
          {
               int x,y;cin>>x>>y;
               update(1,1,n,dfn[x],y);
          }
          else if(now=="QMAX")
          {
               int x,y;cin>>x>>y;
               cout<<path_big(x,y)<<endl;
          }
          else
          {
               int x,y;cin>>x>>y;
               cout<<path_sum(x,y)<<endl;
          }
     }
}
signed main()
{
     Yuubari_chan_kawaii
     solve();
}
