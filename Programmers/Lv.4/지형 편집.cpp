#include <bits/stdc++.h>
using namespace std;


/*
P와 Q의 값에 의존해서, O(n^2)의 복잡도로 끝내야 할 것 같다.
이분탐색해서 적당한 값 찾기
*/


long long search(vector<vector<long long>>& land,long long P,long long Q,long long target)
{
    int n =land.size();
    long long val = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(target > land[i][j])
                val += (target - land[i][j]) * P;
            else
                val += (land[i][j] - target) * Q;
        }
    }
    return val;
}

long long solution(vector<vector<int> > land, int P, int Q) {
    long long answer = 0;
    int n = land.size();
    long long left = INT_MAX;  
    long long right = INT_MIN;
    vector<vector<long long>> land2 (n,vector<long long> (n,0));
    //get min,max;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            land2[i][j] = land[i][j];
            left = min(left,land2[i][j]);
            right = max(right,land2[i][j]);
        }
    }
    //이분탐색?
    while(left < right)
    {
        long long mid = (left + right) / 2;
        long long mid_val = search(land2,P,Q,mid);
        long long mid_val2 = search(land2,P,Q,mid + 1);
        if(mid_val2 > mid_val)
            right = mid;
        else
            left = mid + 1;
    }    
    answer = search(land2,P,Q,left);
    
    
    return answer;
}
