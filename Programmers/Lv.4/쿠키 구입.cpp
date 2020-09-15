#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int MAX = 2002;
int solution(vector<int> cookie) {
    int answer = 0;
    int sum[MAX];
    int s = 0;
    for(int i=0;i<cookie.size();i++)
    {
        sum[i] = s;
        s += cookie[i];        
    }
    sum[cookie.size()] = s;
    for(int m=1;m<cookie.size();m++)
    {
        for(int l = m - 1;l >= 0;l--)
        {
            int temp = sum[m] - sum[l];
            if(answer > temp)
                continue;
            for(int r = m+1;r <= cookie.size();r++)
            {
                int temp2 = sum[r] - sum[m];
                if(temp == temp2)
                {
                    answer = max(answer,temp);
                    break;
                }                    
                else if(temp < temp2)
                    break;
            }
        }
    }
    return answer;
}