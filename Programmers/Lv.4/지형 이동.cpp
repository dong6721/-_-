#include <bits/stdc++.h>

using namespace std;
struct w_int {
    int area;
    int area2;
    int dist;
};
const int max_val = 10001;
int table[300][300];

bool compare(w_int a,w_int b)
{
    return a.dist < b.dist;
}
int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int n = land.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)        
            table[i][j] = 0;            
    int area = 1;
    
    //지역 나누기 bfs
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {  
            if(table[i][j] == 0)
            {
                table[i][j] = area;
                vector<pair<int,int>> list;
                list.push_back({i,j});
                for(int i=0;i<list.size();i++)
                {
                    int r = list[i].first;
                    int c = list[i].second;
                    if(r - 1 >= 0 && table[r - 1][c] == 0 && abs(land[r][c] - land[r - 1][c]) <= height)
                    {
                        table[r - 1][c] = area;
                        list.push_back({r - 1,c});
                    }
                    if(c - 1 >= 0 && table[r][c - 1] == 0 && abs(land[r][c] - land[r][c - 1]) <= height)
                    {
                        table[r][c - 1] = area;
                        list.push_back({r,c - 1});
                    }
                    if(r + 1 < n && table[r + 1][c] == 0 && abs(land[r][c] - land[r + 1][c]) <= height)
                    {
                        table[r + 1][c] = area;
                        list.push_back({r + 1,c});
                    }
                    if(c + 1 < n && table[r][c + 1] == 0 && abs(land[r][c] - land[r][c + 1]) <= height)
                    {
                        table[r][c + 1] = area;
                        list.push_back({r,c + 1});
                    }
                }  
                area++;
            } 
        }
    }
        
    //지역 별 최소 값 구하기
    vector<w_int> map;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j + 1 < n && table[i][j] != table[i][j + 1])
            {
                int a1 = min(table[i][j],table[i][j + 1]);
                int a2 = max(table[i][j],table[i][j + 1]);
                map.push_back({a1,a2,abs(land[i][j] - land[i][j + 1])});                
            }
            if(i + 1 < n && table[i][j] != table[i + 1][j])
            {
                int a1 = min(table[i][j],table[i + 1][j]);
                int a2 = max(table[i][j],table[i + 1][j]);
                map.push_back({a1,a2,abs(land[i][j] - land[i + 1][j])});
            }
        }
    }
    
    //최소 비용 찾기
    sort(map.begin(),map.end(),compare);
    vector<int> gr(area,0);
    int pos = 1;
    for(auto t : map)
    {
        int a1 = t.area;
        int a2 = t.area2;
        int dist = t.dist;
        if(gr[a1] == 0 && gr[a2] == 0)
        {
            gr[a1] = pos;
            gr[a2] = pos;
            pos++;
        }
        else if(gr[a1] == gr[a2])
        {
            continue;
        }
        else if(gr[a1] != 0 && gr[a2] != 0 && gr[a1] != gr[a2])
        {
            int temp = min(gr[a1],gr[a2]);
            int temp2 = max(gr[a1],gr[a2]);
            for(int j=1;j<gr.size();j++)            
                if(gr[j] == temp2)
                    gr[j] = temp;
        }
        else
        {
            int temp = max(gr[a1],gr[a2]);
            gr[a1] = temp;
            gr[a2] = temp;
        }
        answer += dist;
    }
    
    
    return answer;
}