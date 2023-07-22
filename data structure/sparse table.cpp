#include <bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
const int N=2e5+5;
struct sparse_table
{
     vector<vector<int>>sp;
     void pre(vector<int>a)
     {
          int n=sz(a);
          sp=vector<vector<int>>(n,vector<int>(40));
          for(int i=0;i<n;i++)sp[i][0]=a[i];
          for(int j=1;(1<<j)<=n;j++)
               for(int i=0;i+(1<<j)<=n;i++)
                    sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
     }
     int small(int l,int r)
     {
          int k=log(r-l+1)/log(2.0);
          return min(sp[l][k],sp[r-(1<<k)+1][k]);
     }
};
int main()
{

    return 0;
}
