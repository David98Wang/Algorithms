//Almost Acyclic Graph
#include<bits/stdc++.h>
#define N 510
using namespace std;
vector<int>path[N];
int in[N],in2[N];
int n,m;

bool isAcyclic()
{
    queue<int>trop;
    int cnt = 0;
    for(int i=1; i<=n; i++)
        if(in[i]<=0)
        {
            trop.push(i);
            cnt++;
        }
    while(!trop.empty())
    {
        //cout<<trop.size()<<endl;
        int cur = trop.front();
        trop.pop();
        for(int i=0; i<path[cur].size(); i++)
        {
            int cur1 = path[cur][i];
            in[cur1]--;
            if(in[cur1]==0)
            {
                //cout<<cur1<<endl;
                trop.push(cur1);
                cnt++;
            }
        }
    }
    return (cnt==n);
}

int main()
{
    cin>>n>>m;
    int temp,temp1;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&temp,&temp1);
        path[temp].push_back(temp1);
        in2[temp1]++;
    }
    for(int i=1; i<=n; i++)
    {
        memcpy(in,in2,sizeof(in));
        in[i]--;
        if(isAcyclic())
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
