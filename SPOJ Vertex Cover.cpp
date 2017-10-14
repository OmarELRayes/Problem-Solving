#include <bits/stdc++.h>
using namespace std;
int n ,memo[100001][3];
vector< vector<int> > arr(100001);
int dp(int ind ,int parent, int flag){
    int &ret = memo[ind][flag];
    if(ret != -1)
        return ret;
    int option1=1 , option2=0;
    if(!flag)
        option2 = 1e6;
    for(int i=0; i<arr[ind].size(); i++){
        if(arr[ind][i] == parent)
            continue;
        option1 += dp(arr[ind][i],ind,1);
        if(flag)
            option2  += dp(arr[ind][i],ind,0);
    }
    ret = min(option1,option2);
    return ret;
}
int main()
{
    cin >> n;
    int a , b;
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    memset(memo,-1,sizeof memo);
    cout << dp(1,0,1);
}
