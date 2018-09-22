//Too Easy Problems
#include<bits/stdc++.h>
using namespace std;
long long n,T;
int in,in1;
vector<pair<int,pair<int,int> > >byScore;
vector<pair<int,pair<int,int> > >byTime;
vector<int> res;
int bestTime=0;
bool isPossible(int score)
{
    vector<pair<int,pair<int,int> > >::iterator it = upper_bound(byTime.begin(),byTime.end(),make_pair(0,make_pair(score,2147483647)));
    vector<int> tempRes;
    tempRes.clear();
    int curTime = 0;
    int qc = 0;
    //cout<<it-byTime.begin()<<endl;
    while(it!=byTime.end())
    {
        if(it==byTime.end())break;
        //cout<<it-byTime.begin()<<" "<<curTime<<endl;
        if(curTime + (it->first) <= T)
        {
            if(it->second.first<score)
            {
                it++;
                continue;
            }
            tempRes.push_back(it->second.second);
            curTime += it->first;
            qc++;
            it++;
            //cout<<"END: "<<it-byTime.begin()<<" "<<curTime<<endl;
        }
        else
            break;
        if(score == qc)
            break;
    }
    if(qc>=score)
    {
        bestTime = curTime;
       res.clear();
       for(int i=0;i<tempRes.size();i++)
            res.push_back(tempRes[i]);
       return true;
    }

    return false;
}

int main()
{

    cin>>n>>T;

    for(int i=0;i<n;i++)
    {
        cin>>in>>in1;
        byScore.push_back(make_pair(in,make_pair(in1,i+1)));
        byTime.push_back(make_pair(in1,make_pair(in,i+1)));
    }
    sort(byScore.begin(),byScore.end());
    sort(byTime.begin(),byTime.end());
    int low = 0, high = n, mid;
    //cout<<isPossible(2)<<endl;
    while(low<high)
    {
        //cout<<low<<" "<<high<<endl;
        mid = (high+low+1)/2;
        bool curPoss = isPossible(mid);
        if(curPoss)
            low = mid;
        else
            high = mid-1;
        mid = (high+low)/2;
    }
    cout<<mid<<endl;
    /*sort(res.begin())
    for(int i=0;i<byTime.size();i++)
    {
        if(find(res.begin(),res.end(),byTime[i].second.second)!=res.end())
            continue;
        if(byTime[i].first + bestTime > T)
            break;
        res.push_back(byTime[i].second.second);
        bestTime += byTime[i].first;
    }*/
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
}
