#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


/*
최대시간은 => 가장높은값 * n
최소시간은 => 가장낮은값 * n
이분탐색
*/
int solution(int n, vector<int> cores) {
    int answer = 0;
    //int left = *min_element(cores.begin(),cores.end()) * n / cores.size();
    int left = 0;
    int right = *max_element(cores.begin(),cores.end()) * n / cores.size();
    int count;
    while(left < right)
    {
        int mid = (left + right) / 2;
        count = 0;
        vector<int> list;
        for(int i=0;i<cores.size();i++)
        {
            count += mid / cores[i];
            if(mid % cores[i] != 0)
                count++;
            else
                list.push_back(i + 1);
        }
        if(count >= n)
            right = mid;
        else if(count < n && count + list.size() >= n)
        {
            left = mid;
            break;
        }            
        else
            left = mid + 1;
    }
    
    int time = left;
    vector<int> list;
    for(int i=0;i<cores.size();i++)
        if(time % cores[i] ==0)
            list.push_back(i + 1);
    answer = list[n - count - 1];
    
    
    return answer;
}