#include <bits/stdc++.h>
using namespace std;
int memo[26][625];
string s;
int dp(int ind , int prev){
    if(ind==s.size())
        return 1;
    int &ret = memo[ind][prev];
    if(ret != -1)
        return ret;
    ret = 0;
    int cur =0;
    for(int i=ind; i<s.size(); i++)
    {
        cur += s[i]-'0';
        if(cur >= prev)
            ret += dp(i+1,cur);
    }
    return ret;
}
int main()
{
    int cnt=0;
    while(cin >> s && s[0] != 'b'){
            memset(memo,-1,sizeof memo);
            cout <<++cnt<<". " <<dp(0,0) << endl;
    }

}
