#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();
    vector<int> dp (n,0);
    vector<int> dp2 (n,0);
    if(n <= 3)
    {
        return *max_element(sticker.begin(),sticker.end());
    }
    //0번째,1번째 확정
    dp[0] = sticker[0];
    dp[1] = 0;
    dp[2] = sticker[0] + sticker[2];
    dp2[0] = 0;
    dp2[1] = sticker[1];
    dp2[2] = 0;
    for(int i=3;i<n;i++)
    {
        dp[i] = sticker[i] + max(dp[i - 2],dp[i - 3]);
        dp2[i] = sticker[i] + max(dp2[i - 2],dp2[i - 3]);
    }
    int a = max(dp[n - 2],dp[n - 3]);
    int b = max(dp2[n - 1],dp2[n - 2]);
    a = max(a,b);
    
    //-1번째 확정
    reverse(sticker.begin(),sticker.end());
    dp[0] = sticker[0];
    dp[1] = 0;
    dp[2] = sticker[0] + sticker[2];
    for(int i=3;i<n;i++)
    {
        dp[i] = sticker[i] + max(dp[i - 2],dp[i - 3]);
    }
    b = max(dp[n - 2],dp[n - 3]);   
    answer = max(a,b);
    return answer;
}