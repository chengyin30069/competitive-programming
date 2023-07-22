/*

Paul_Liao,Cookie197,pixelcat,balbit,wty2016,nathanlee726 are my idols

https://imgur.com/rzV8Lqv
My waifu~~<3

§Ú¶W¹q
     ---Paul_Liao
(sorce:https://imgur.com/4O6u9ke)

*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
#define float double
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define endl "\n"
#define REP(x) for(int i=0;i<x;i++)
#define FOR(i,x,y) for(int i=x;i<y;i++)
#define INF 1e16
#define p2(x) (int)(x*x)
#define lowbit(x) x&-x
#define MOD Mod1
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define Yuubari_chan_kawaii ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
template<class T>using deset=tree<T,null_type,greater<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T>using inset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T,class TT>using um=unordered_map<T,TT>;
template<class T,class TT>using fm=gp_hash_table<T,TT>;
typedef trie<string,null_type,trie_string_access_traits<string>,pat_trie_tag,trie_prefix_search_node_update> tr;
template<class T>using pbds_pq=__gnu_pbds::priority_queue<T,greater<T>,pairing_heap_tag>;
template<class T>using std_pq=std::priority_queue<T,vector<T>,greater<T>>;
template<class T>void output(const T&hs){for(auto i:hs)cout<<i<<" ";cout<<endl;}
template<class T>void outpair(const T&hs){for(auto i:hs)cout<<i.F<<" "<<i.S<<endl;cout<<endl;}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
const int Mod1=1000000007,Mod2=998244353,N=5e5+5;
int fpow(int x,int y,int mod){
     if(y==0)return 1;
     if(y==1)return x;
     int z=fpow(x,y/2,mod);
     int w=(z*z)%mod;
     if(y%2==1)return (w*x)%mod;
     return w;
}
int n,m,s,t,par[N],p_i[N],dis[N];
bool vis[N];
struct edge
{
     int to,cap,rev,cost;
};
vector<edge>path[N];
void add(int a,int b,int c,int d)
{
     edge now;
     now.to=b,now.cap=c,now.rev=sz(path[b]),now.cost=d;
     path[a].pb(now);
     now.to=a,now.cap=0,now.rev=sz(path[a])-1,now.cost=-d;
     path[b].pb(now);
}
void spfa()
{
     FOR(i,0,n*2+5)dis[i]=INF,vis[i]=0;
     dis[s]=0;
     queue<int>q;q.push(s);
     while(q.size())
     {
          int now=q.front();
          q.pop();
          vis[now]=0;
          for(int i=0;i<sz(path[now]);i++)
          {
               edge e=path[now][i];
               if(e.cap>0&&dis[e.to]>dis[now]+e.cost)
               {
                    dis[e.to]=dis[now]+e.cost;
                    par[e.to]=now;
                    p_i[e.to]=i;
                    if(vis[e.to]==0)
                    {
                         vis[e.to]=1;
                         q.push(e.to);
                    }
               }
          }
     }
}
pii flow()
{
     int flow=0,cost=0;
     while(true)
     {
          spfa();
          if(dis[t]==INF)break;
          int mn=INF;
          for(int i=t;i!=s;i=par[i])mn=min(mn,path[par[i]][p_i[i]].cap);
          flow+=mn;cost+=dis[t]*mn;
          for(int i=t;i!=s;i=par[i])
          {
               path[par[i]][p_i[i]].cap-=mn;
               path[i][path[par[i]][p_i[i]].rev].cap+=mn;
          }
     }
     return mp(flow,cost);
}
void solve()
{

}
signed main()
{
     Yuubari_chan_kawaii
     solve();
}

