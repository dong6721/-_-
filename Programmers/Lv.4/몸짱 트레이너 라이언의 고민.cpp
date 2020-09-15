#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//brute force


enum state {
    START,END
};
struct n_time {
    int val;
    int state;
};
bool compare(n_time a,n_time b)
{
    if(a.val == b.val)
        return a.state < b.state;
    else
        return a.val < b.val;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {
    int answer = 0;
    
    //겹치는 손님 구하기
    vector<n_time> list;
    int work = 0;
    int max_val = 0;    //겹치는 손님
    for(int i=0;i<m;i++)
    {
        list.push_back({timetable[i][0],START});
        list.push_back({timetable[i][1],END});
    }
    sort(list.begin(),list.end(),compare);
    for(auto t : list)
    {
        if(t.state == START)
            work++;
        else
            work--;
        max_val = max(max_val,work);
    }
    
    if(max_val < 2)
        return 0;
    //거리 구하기  
    for(int start = 0;start < n;start++)
    {
        vector<vector<int>> people (1,{0,0});
        int k = start;
        people[0][1] = k;
        for(int distance = 0;distance < 2 * (n - 1);distance++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=k;j<n;j++)
                {
                    bool check = true;
                    for(auto t : people)
                    {
                        int x = t[0];
                        int y = t[1];
                        if(abs(i - x) + abs(j - y) <= distance)
                        {
                            check =false;
                            break;
                        }
                    }
                    if(check)
                        people.push_back({i,j});
                }
                k=0;                
            }
            /*cout << distance + 1 << ":" << people.size() <<" ";
            for(auto t : people)
                cout << t[0] << "," << t[1] << " ";
            cout << endl;*/
            
            if(people.size() >= max_val)
                answer = max(answer,distance + 1);
            people = vector<vector<int>>(1,{0,start});
        }
    }
    
    return answer;
}