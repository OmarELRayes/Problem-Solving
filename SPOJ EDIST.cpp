#include <bits/stdc++.h>
using namespace std;
string a ,b;
int memo[2001][2001];
int dp(int i,int j){
    if(i == a.size())
        return b.size() - j;
    if(j == b.size())
        return a.size() - i;
    int &ret = memo[i][j];
    if(ret != -1)
        return ret;
    if(a[i] == b[j])
        return dp(i+1,j+1);
    ret = 1 + min(dp(i+1,j),min(dp(i+1,j+1),dp(i,j+1)));
    return ret;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(memo,-1,sizeof memo);
        cout << dp(0,0)<<endl;
    }
}
