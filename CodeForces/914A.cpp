#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int n)
{
    int t = sqrt(n);
    return t*t == n;
}
int main()
{
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
        cin>>num[i];
    sort(num,num+n);
    for(int i=n-1;i>=0;i--)
    {
        if(!isPerfectSquare(num[i]))
        {
            cout<<num[i]<<endl;
            return 0;
        }
    }
}
