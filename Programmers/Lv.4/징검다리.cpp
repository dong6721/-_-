#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = distance;
    sort(rocks.begin(),rocks.end());
    
    int min = 1;
    int max = distance;
    while(min <= max)
    {
        int mid = (min + max) / 2;
        int count = 0;
        int last = 0;
        for(int i=0;i<rocks.size() + 1;i++)
        {
            int dist;
            if(i == rocks.size())
                dist = distance - rocks[i - 1];
            else
                dist = rocks[i] - last;
            
            if(dist < mid)
                count++;
            else if(i != rocks.size())
                last = rocks[i];                
        }
        if(count > n)
            max = mid - 1;
        else
        {
            min = mid + 1;
            answer = mid;
        }     
                       
    }
    
    return answer;
}