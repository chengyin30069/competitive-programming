//I love Treap!!!
//best case: O(NlogN) worst case: O(N^2) average case: O(NlogN)
#include<stdio.h>
#include<stdlib.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
typedef struct node
{
    int l,r;
    int val,pri,num;
}Treap;
Treap treap[200005];
int root=-1,counter=0;
int siz(int now)
{
    if(now==-1)return 0;
    return treap[now].num;
}
void pull(int now)
{
    treap[now].num=siz(treap[now].l)+siz(treap[now].r)+1;
}
int merge(int a,int b)
{
    //printf("%d %d\n",a,b);
    if(a==-1||b==-1)return (a==-1)?b:a;
    else if(treap[a].pri>treap[b].pri)
    {
        treap[a].r=merge(treap[a].r,b);
        pull(a);
        return a;
    }
    else
    {
        treap[b].l=merge(a,treap[b].l);
        pull(b);
        return b;
    }
}
void split_size(int rt,int *a,int *b,int val)
{
    //printf("%d %d %d\n",rt,*a,*b);
    if(rt==-1)
    {
        *a=*b=-1;
        return;
    }
    if(siz(treap[rt].l)+1>val)
    {
        *b=rt;
        split_size(treap[rt].l,a,&treap[*b].l,val);
        pull(*b);
    }
    else
    {
        *a=rt;
        split_size(treap[rt].r,&treap[*a].r,b,val-siz(treap[rt].l)-1);
        pull(*a);
    }
}
void dfs(int now)
{
    if(now==-1)return;
    dfs(treap[now].l);
    printf("%d ",treap[now].val);
    dfs(treap[now].r);
}
signed main()
{
    char op;
    while(scanf(" %c",&op)!=EOF)
    {
        if(op=='A')
        {
            int p,v;
            scanf("%d %d",&p,&v);
            p++;
            if(siz(root)+1<p)
            {
                printf("Invalid insertion\n");
                continue;
            }
            treap[counter].val=v;
            treap[counter].l=treap[counter].r=-1;
            treap[counter].pri=rand();
            treap[counter].num=1;
            if(p==1)
            {
                root=merge(counter,root);
            }
            else if(siz(root)+1==p)
            {
                root=merge(root,counter);
            }
            else
            {
                int a,b;
                split_size(root,&a,&b,p-1);
                root=merge(a,merge(counter,b));
            }
            counter++;
        }
        else
        {
            int p;
            scanf("%d",&p);
            p++;
            if(siz(root)<p)
            {
                printf("Invalid deletion\n");
                continue;
            }
            if(siz(root)==p)
            {
                int a,b;
                split_size(root,&a,&b,p-1);
                root=a;
            }
            else if(p==1)
            {
                int a,b;
                split_size(root,&a,&b,1);
                root=b;
            }
            else
            {
                int a,b,c;
                split_size(root,&a,&c,p);
                split_size(a,&a,&b,p-1);
                root=merge(a,c);
            }
        }
        //dfs(root);
        //printf("\n");
    }
    dfs(root);
    printf("\n");
}
