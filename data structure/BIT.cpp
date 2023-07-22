#include<bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;
const int N=2e5+5;
struct BIT
{
     vector<int>v;
     int n;
     void init(int _n)
     {
          n=_n;
          v=vector<int>(n+5);
     }
     void add(int pos,int val)
     {
          while(pos<=n)
          {
               v[pos]+=val;
               pos+=lowbit(pos);
          }
     }
     int ask(int pos)
     {
          int res=0;
          while(pos)
          {
               res+=v[pos];
               pos-=lowbit(pos);
          }
          return res;
     }
};
int main()
{

    return 0;
}
