//Permute Digits
#include<bits/stdc++.h>
using namespace std;


int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    vector<int>digA;
    for(int i=0;i<a.size();i++)
    {
        digA.push_back(a[i]-'0');
    }
    sort(digA.begin(),digA.end());
    vector<int>res;
    vector<int>::iterator it,itt;
    bool guarenteSmaller = false;
    if(a.size()<b.size())
    {
        for(int i=digA.size()-1;i>=0;i--)
            cout<<digA[i];
        cout<<endl;
        return 0;
    }
    int hasSmall = 0;
    for(int i=0;i<b.size()&&digA.size()>0&&res.size()<a.size();i++)
    {
        //cout<<i<<" "<<hasSmall<<endl;
        if(!guarenteSmaller)
        {
            it = upper_bound(digA.begin(),digA.end(),b[i]-'0');
            if(it!=digA.begin() && digA[0]<*(it-1))
                hasSmall = i;
            else if(it==digA.begin())
            {
                int temp = res[hasSmall];
                while(res.size()>hasSmall)
                {
                    digA.push_back(res[res.size()-1]);
                    res.erase(res.end()-1);
                }
                sort(digA.begin(),digA.end());
                it = lower_bound(digA.begin(),digA.end(),temp);
                it--;
                i = hasSmall-1;
                res.push_back(*it);
                digA.erase(it);
                guarenteSmaller = true;
                //for(int i=0;i<digA.size();i++)
                    //cout<<digA[i]<<endl;
                continue;
            }
            /*if(it==digA.begin() && *it > b[i] - '0')
            {
                for(int j=i-1;j>=0;j--)
                {
                    it = upper_bound(digA.begin(),digA.end(),res[j]);
                    if(it==digA.begin())
                    {
                        digA.push_back(res[j]);
                        res.erase(res.begin()+j);
                        continue;
                    }

                    it--;
                    int temp =res[j];
                    res[j]=*it;
                    *it = temp;
                    sort(digA.begin(),digA.end());
                    it = upper_bound(digA.begin(),digA.end(),b[i]-'0');
                    i=j;
                    guarenteSmaller = true;
                    break;
                }
            }*/
            it--;
            if(guarenteSmaller)
            {
                i--;
                continue;
            }
            if((*it) < (b[i]-'0'))
                guarenteSmaller = true;
            //cout<<digA.end()-it<<endl;
            res.push_back((*it));
            digA.erase(it);
        }
        else if(digA.size()>0)
        {
            it = digA.end()-1;
            //cout<<*it<<endl;
            res.push_back(*it);
            digA.erase(it);
        }
    }
    for(int i=0;i<a.size();i++)
        cout<<res[i];
    cout<<endl;
    return 0;
}
