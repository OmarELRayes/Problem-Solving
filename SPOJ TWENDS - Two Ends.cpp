#include <bits/stdc++.h>
using namespace std;
int arr[1000] , n,memo[1000][1000],tempI,tempJ;
int dp(int i,int j){
    if(i>j)
        return 0;
    int &ret = memo[i][j];
    if(ret != -1)
        return ret;
    int option1 =0, option2 =0;
    //choosing right end
    if(arr[i] >= arr[j-1])
        option1 = arr[j] + dp(i+1,j-1);
    else
        option1 = arr[j] + dp(i,j-2);

    //choosing left end
    if(arr[j] > arr[i+1])
        option2 = arr[i] + dp(i+1,j-1);
    else
        option2 = arr[i] + dp(i+2,j);
    ret = max(option1,option2);
    return ret;
}
int main()
{
    int cnt=0;
    while(cin >>n && n){
            int sum =0;
            cnt++;
        for(int i=0; i<n; i++){
                cin >> arr[i];
                sum += arr[i];
            }
        memset(memo,-1,sizeof memo);
        int res = dp(0,n-1);
        cout << "In game "<<cnt<<", the greedy strategy might lose by as many as "<< res - (sum-res) << " points." << endl;
    }

}
