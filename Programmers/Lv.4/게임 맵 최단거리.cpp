#include<vector>
#include <iostream>
using namespace std;

struct pos_int {
    int x,y;
};
int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maps[i][j] == 0)
                maps[i][j] = 1;
            else
                maps[i][j] = 0;
        }
    }        
    vector<pos_int> list;
    list.push_back({0,0});
    int count = 2;
    while(!list.empty())
    {
        vector<pos_int> n_list;
        for(auto t : list)
        {
            int x = t.x;
            int y = t.y;
            if(x - 1 >= 0 && maps[x - 1][y] == 0)
            {
                n_list.push_back({x - 1,y});
                maps[x - 1][y] = count;
            }                
            if(y - 1 >= 0 && maps[x][y - 1] == 0)
            {
                n_list.push_back({x,y - 1});
                maps[x][y - 1] = count;
            }                
            if(x + 1 < n && maps[x + 1][y] == 0)
            {
                n_list.push_back({x + 1,y});
                maps[x + 1][y] = count;
            } 
            if(y + 1< m && maps[x][y + 1] == 0)
            {
                n_list.push_back({x,y + 1});
                maps[x][y + 1] = count;
            }
        }
        /*for(int i=0;i<n;i++)
        {   
            for(int j=0;j<m;j++)
            {
                cout << maps[i][j] <<" ";
            }
            cout << endl;
        }
        cout << endl;*/
        
        count++;
        list = n_list;
    }
    
    answer = maps[n - 1][m - 1];
    if(answer == 0)
        answer = -1;
    return answer;
}