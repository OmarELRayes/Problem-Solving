#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int t , w , arr[1001],memo[1001][3][31];
int dp(int ind , int pos , int walk){
    if(ind == t)
        return 0;
    int &ret = memo[ind][pos][walk];
    if(ret != -1)
        return ret;
    if(pos != 2){ // if under tree 1
        if(arr[ind] == 1 )
            ret = max(ret,1+dp(ind+1,1,walk));
        else
            ret = max(ret,dp(ind+1,1,walk));

        if(walk && arr[ind] == 1)
            ret = max(ret,1+dp(ind+1,2,walk-1));
        else if(walk && arr[ind] != 1)
            ret = max(ret,dp(ind+1,2,walk-1));
    }
    if(pos != 1){ // if under tree 2
            if(arr[ind] == 2)
                ret = max(ret,1+dp(ind+1,2,walk));
            else
                ret = max(ret,dp(ind+1,2,walk));
            if(walk && arr[ind] == 2)
                ret = max(ret,1+dp(ind+1,1,walk-1));
            else if(walk && arr[ind] != 2)
                ret = max(ret,dp(ind+1,1,walk-1));
    }
    return ret;
}
int main()
{
    cin >> t >> w;
    for(int i=0; i<t; i++)
        cin >> arr[i];
    memset(memo,-1,sizeof memo);
    cout << dp(0,0,w);
}
