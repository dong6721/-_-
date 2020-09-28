#include <bits/stdc++.h>

using namespace std;

long long search(int mid,vector<int>& food_times,long long k)
{
    long long t = 0;
    for(int i=0;i<food_times.size();i++)
    {
        if(mid > food_times[i])
            t += food_times[i];
        else
            t += mid;
    }
    return t;
}
int solution(vector<int> food_times, long long k) {
    int answer = -1;    
    /*long long min_val = *min_element(food_times.begin(),food_times.end());
    long long n = food_times.size();
    while(k >= min_val * n)
    {
        long long n_min_val = INT_MAX;
        long long count = 0;
        for(int i= 0;i<food_times.size();i++)
        {
            if(food_times[i] != 0)
            {                
                food_times[i] -= min_val;
                if(food_times[i] != 0)
                    n_min_val = min(n_min_val,(long long)food_times[i]);
                else
                    count++;
            }
        }
        if(n - count == 0)
            return -1;        
        k -= min_val * n;
        min_val = n_min_val;
        n -= count;
    }
    k %= n;
    for(int i=0;i<food_times.size();i++)
    {
        if(food_times[i] != 0)
        {
            if(k == 0)
                return i + 1;
            k--;
        }
    }*/
    
    //이분탐색?
    int left = 0;
    int right = *max_element(food_times.begin(),food_times.end());    
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(search(mid,food_times,k) > k)
            right = mid;
        else
            left = mid + 1;
    }    
    
    long long t = k - search(left - 1,food_times,k);
    for(int i=0;i<food_times.size();i++)
    {        
        if(food_times[i] > left - 1)
        {
            if(t == 0)
            {
                answer = i + 1;
                break;
            }
            t--;
        }            
    }
    return answer;
}
