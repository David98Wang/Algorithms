#include<bits/stc++.h>
#define MAXN 1000001
using namespace std;
int n;
struct node{
    int index;
    vector<int>child;
    int parent;
};
int n;
vector<int>mp[MAXN];
int main()
{
    cin>>n;
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    queue<int>q;
    q.push_back(1);
    while(!q.empty())
    {

    }
}
