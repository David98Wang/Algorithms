#include<bits/stdc++.h>
using namespace std;
vector<int>path[501];
vector<int>rPath[501];
vector<int>trop;
int n,m;
bool inTrop[501];

bool isAcyclic(int remA,int remB)
{
    trop.clear();
    //cout<<remA<<" "<<remB<<endl;
    for(int i=0;i<path[remA].size();i++)
    {
        if(path[remA][i]==remB)
            path[remA].erase(path[remA].begin()+i);
    }
    for(int i=0;i<rPath[remB].size();i++)
    {
        if(rPath[remB][i]==remA)
            rPath[remB].erase(rPath[remB].begin()+i);
    }
    for(int i=0;i<=500;i++)
        inTrop[i] = false;
    for(int i=1;i<=n;i++){
        if(rPath[i].size()==0)
        {
            trop.push_back(i);
            inTrop[i]=true;
        }
    }
    if(trop.size()==0)return false;
    int previ = 0;
    while(trop.size()!=n)
    {
        int cur = trop.size();
        for(int i=previ;i<trop.size();i++)
        {
            for(int j=0;j<path[trop[i]].size();j++)
            {
                if(!inTrop[path[trop[i]][j]])
                {
                    inTrop[path[trop[i]][j]] = true;
                    trop.push_back(path[trop[i]][j]);
                }
                else
                {
                    return false;
                }
            }
        }
        if(cur==trop.size())return false;
        previ = cur;
    }
    path[remA].push_back(remB);
    rPath[remB].push_back(remA);
    return true;
}
bool hasCycle()
{

}
int main()
{

    cin>>n>>m;
    int in,in1;
    for(int i=0;i<m;i++)
    {
        cin>>in>>in1;
        path[in].push_back(in1);
        rPath[in1].push_back(in);
    }
    if(isAcyclic(0,0))
        cout<<"YES"<<endl;
    else
    {
        for(int i=1;i<=n;i++)
            for(int j=0;j<path[i].size();j++)
        {
            if(isAcyclic(i,path[i][j]))
            {

                cout<<"YES"<<endl;
                return 0;
            }
        }
        cout<<"NO"<<endl;
    }
    return 0;
}
