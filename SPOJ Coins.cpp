#include <bits/stdc++.h>
using namespace std;
int n , memo[10000000];
long long dp(long long v){
    if(v<1e7)
        return memo[v];
    return max(v,dp(v/2)+dp(v/3)+dp(v/4));
}
int main()
{
    for(int i=1; i<=1e7; i++)
        memo[i] = max(i,memo[i/2]+memo[i/3]+memo[i/4]);

    while(cin >> n)
        cout << dp(n) << endl;

}
