#include <bits/stdc++.h>
using namespace std;
int s,n,memo[2001][2001];
pair<int,int> arr[2001];
int dp(int ind , int siz){
    if(ind == n)
        return 0;
    int &ret = memo[ind][siz];
    ret = max(ret,dp(ind+1,siz));
    if(siz+arr[ind].first <=s)
        ret = max(ret,arr[ind].second+dp(ind+1,siz+arr[ind].first));
    return ret;
}
int main()
{
    cin >> s >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i].first >> arr[i].second;
    memset(memo,-1,sizeof memo);
    cout << dp(0,0);
}
