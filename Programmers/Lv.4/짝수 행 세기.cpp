#include <bits/stdc++.h>

using namespace std;


/*
dp로 풀릴듯?
n - 1열가지 짝수가 0개 = r 개
n - 1열까지 짝수가 1개만 나오는 수 => n열에서 r - 1개?
n - 1열까지 짝수가 2개만 나오는 수 => n열에서 r - 2개
n - 1열까지 짝수가 3개만 나오는 수 => n열에서 r - 3개
    ...
n - 1열까지 짝수가 r개만 나오는 수 => n열에서 0개
case 1.
dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 6; dp[0][3] = 0; dp[0][4] = 0;
dp[1][0] = 0; dp[1][1] = 0; dp[1][2] = 6; dp[1][3] = 0; dp[1][4] = 0;
dp[2][0] = 6; dp[2][1] = 0; dp[2][2] = 6 * 4; dp[2][3] = 0; dp[2][4] = 6;
case 3.
dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 6; dp[0][3] = 0; dp[0][4] = 0;
dp[1][0] = 0; dp[1][1] = 6 * 2; dp[1][2] = 0; dp[1][3] = 6 * 2;dp[1][4] = 0;

case 4.
dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0; dp[0][3] = 10; dp[0][4] = 0; dp[0][5] = 0;
dp[1][0] = 10; dp[1][1] = ...
nCr를 이용하고, n - 1의 열에서, +2 단위로 nCr의 단위가 달라짐.
시작은 n 열의 1의 개수인 y, 총 행의 개수 r
j - y부터 시작해서 += 2단위로 행함. j + y까지 진행하고, dp[n - 1][x] * nCr(x,t) * nCr(r - x,y - t);
t++;

*/
int solution(vector<vector<int>> a) {
    int answer = -1;
    int n = a[0].size();
    int r = a.size();
    long long dv = 10000000 + 19;
    vector<int> count (n,0);
    for(int i=0;i<r;i++)    
        for(int j=0;j<n;j++)        
            if(a[i][j] == 1)
                count[j]++;
    
    //nCr 구하기  
    vector<vector<long long>> ncr (r + 1,vector<long long> (r + 1,0));
    ncr[0][0] = 1;
    for(int i=1;i<=r;i++)
    {
        ncr[i][0] = 1;
        ncr[i][i] = 1;
        for(int j=1;j<i;j++)
        {
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % dv;
        }
    }
    
    //dp
    vector<vector<long long>> dp (n,vector<long long>(r + 1,0));
    //init      
    dp[0][r - count[0]] = ncr[r][count[0]];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=r;j++)
        {
            int t = 0;
            for(int k = j - count[i];k <= j + count[i];k+=2)
            {
                if(k >= 0 && k <= r)
                {
                    dp[i][j] = (dp[i][j] + ((dp[i - 1][k] * ncr[k][t]) % dv) * ncr[r - k][count[i] - t])% dv;                    
                }
                t++;
            }
        }
    }
    answer = dp[n - 1][r] % dv;
    return answer;
}