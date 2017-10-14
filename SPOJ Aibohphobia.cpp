#include <bits/stdc++.h>
using namespace std;
string s;
int memo[6100][6100];
int dp(int i , int j){
    if(i >= j)
        return 0;
    int &ret = memo[i][j];
    if(ret != -1)
        return ret;
    if(s[i] == s[j])
        return dp(i+1,j-1);
    ret = 1 + min(dp(i+1,j),dp(i,j-1));
    return ret;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        memset(memo,-1,sizeof memo);
        cout << dp(0,s.size()-1) << endl;
    }
}
