#include<bits/stdc++.h>
using namespace std;
#define MAXN 20001
vector<pair<long long,int> >path[MAXN];
long long ticket[MAXN];
long long price[MAXN];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        path[a].push_back(make_pair(c,b));
        path[b].push_back(make_pair(c,a));
    }
    for(int i=1;i<=n;i++)
        cin>>ticket[i];
    for(int i=1;i<=n;i++)
    {
        memset(price,0,sizeof(price));
        price[i] = 0;
        queue<int>next;
        next.push(i);
        long long curMin = ticket[i];
        
        while(!next.empty())
        {
            int cur = next.front();
            //cout<<cur<<endl;
            next.pop();
            if(price[cur] >= curMin)continue;
            for(int j=0;j<path[cur].size();j++)
            {
                if(price[cur] + 2 * path[cur][j].first>=curMin)
                    continue;
                if(price[path[cur][j].second]<=price[cur] + 2* path[cur][j].first)
                price[path[cur][j].second] = price[cur]  + 2 * path[cur][j].first;
                curMin = min(curMin,price[path[cur][j].second]+ticket[path[cur][j].second]);
                next.push(path[cur][j].second);
            }
        }
        cout<<curMin<<" ";
    }
    
}