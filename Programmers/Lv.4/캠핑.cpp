#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(vector<int> a,vector<int> b)
{
    if(a[1] == b[1]) 
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(),data.end(),compare);
    for(int i=0;i < n;i++)
    {
        int x1 = data[i][0];
        int y1 = data[i][1];
        for(int j = i;j < n;j++)
        {
            int x2 = data[j][0];
            int y2 = data[j][1];
            if(x1 == x2 || y1 == y2)
                continue;
            else
            {
                bool check = true;
                for(int k = i + 1;k < j;k++)
                {
                    int x3 = data[k][0];
                    int y3 = data[k][1];
                    if(y1 == y3)
                        continue;
                    if(x3 < x1)
                    {
                        if(x3 > x2 && y3 < y2)
                        {
                            check = false;
                            break;
                        }                
                    }           
                    else if (x3 > x1)
                    {
                        if(x3 < x2 && y3 < y2)
                        {
                            check = false;
                            break;
                        }            
                    }
                    else
                        continue;
                }
                if(check)
                {
                    //cout << x1 << y1 << " " << x2 << y2 << endl;
                    answer++;
                }
            }
        }
    }
    
    return answer;
}