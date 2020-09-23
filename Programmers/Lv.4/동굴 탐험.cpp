#include <bits/stdc++.h>

using namespace std;


/*
bfs
0부터 시작
출입금지방을 만나면 멈추고, 출입해제방을만나면 출입금지방을 해제함
bfs가 끝났을때 가지 못한 방이 있으면 false, 모두 갔으면 true
*/
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    vector<vector<int>> room(n,vector<int>());  //room 통로
    vector<int> check(n,0);     //0일때 아직 방문안함, 1일때 방문함, 2일때 출입해제방,3일때 출입금지방,4일때 출입금지대기
    vector<int> entry(n,0);     //출입해제방
    for(int i=0;i<path.size();i++)
    {
        room[path[i][0]].push_back(path[i][1]);
        room[path[i][1]].push_back(path[i][0]);
    }
    for(int i=0;i<order.size();i++)
    {
        check[order[i][0]] = 2;
        check[order[i][1]] = 3;
        entry[order[i][0]] = order[i][1];
    }
    
    vector<int> list;
    list.push_back(0);  //init
    if(check[0]==3)
        return false;
    else if(check[0] == 2)
        check[entry[0]] = 0;
    check[0] = 1;    
    while(!list.empty())
    {
        vector<int> n_list;
        for(auto r : list)
        {
            for(int i=0;i<room[r].size();i++)
            {
                int next = room[r][i];
                if(check[next] == 0)
                {
                    check[next] = 1;
                    n_list.push_back(next);
                }
                else if(check[next] == 1)
                {
                    //nothing;
                }
                else if(check[next] == 2)
                {
                    check[next] = 1;
                    n_list.push_back(next);
                    if(check[entry[next]] == 4)
                    {
                        check[entry[next]] = 1;
                        n_list.push_back(entry[next]);
                    }
                    else
                        check[entry[next]] = 0;                    
                }
                else if(check[next] == 3)
                {
                    check[next] = 4;
                }
            }
        }
        list = n_list;
    }
    for(auto t : check)
    {
        if(t != 1)
            return !answer;
    }
    
    return answer;
}
