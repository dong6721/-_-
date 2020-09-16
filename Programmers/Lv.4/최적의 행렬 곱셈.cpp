#include <bits/stdc++.h>
using namespace std;
/*
dp?
5 3 10 6
A = 5 * 3 * 10
B = 3 * 10 * 6
A + 5 * 10 * 6, B + 5 * 3 * 6

4개
3,10 10,12 12,5 5,7
3 10 12 5 7=>a
A = [0][1] = 3 * 10 * 12
B = [1][2] = 10 * 12 * 5
C = [2][3] = 12 * 5 * 7
D = [0][2] = min(A + a[0] * a[2] * a[3],B + a[0] * a[1] * a[3])
E = [1][3] = min(B + a[1] * a[3] * a[4],C + a[1] * a[2] * a[4])
F = [0][3] = min(D + [3][3] +  a[0] * a[3] * a[4],E + [0][0] + a[0] * a[1] * a[4],A + C + a[0] * a[2] * a[4])
*/


int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    int n =matrix_sizes.size();
    //sort    
    vector<int> arr;
    arr.push_back(matrix_sizes[0][0]);
    for(int i=0;i<n;i++)
    {
        arr.push_back(matrix_sizes[i][1]);
    }
    vector<vector<int>> dp (n,vector<int> (n,0));
    for(int k=1;k<n;k++)
    {
        for(int i=0;i + k < n;i++)
        {
            int j = i + k;
            if( i == j)
                continue;
            dp[i][j] = INT_MAX;
            for(int m = i;m < j;m++)
                dp[i][j] = min(dp[i][j],dp[i][m] + dp[m + 1][j] + arr[i] * arr[m + 1] * arr[j + 1]);
        }
    }
    answer = dp[0][n - 1];
        
    return answer;
}