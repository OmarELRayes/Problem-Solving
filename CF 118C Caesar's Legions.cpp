#include <bits/stdc++.h>
using namespace std;
int n1,n2,k1,k2;
long long memo[101][101][11][11];
long long dp(int f,int h,int fk,int fh){
    if(fk >k1  || fh > k2 || f < 0 || h < 0  )
        return 0;
    if(f == 0 && h == 0)
        return 1;
    long long &ret = memo[f][h][fk][fh];
    if(ret != -1)
        return ret;
    return ret = (  dp(f-1,h,fk+1,0) + dp(f,h-1,0,fh+1) )%100000000;
}
int main()
{
    memset(memo,-1,sizeof memo);
    cin >> n1>>n2>>k1>>k2;
    cout << dp(n1,n2,0,0);
}
