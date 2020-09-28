#include <bits/stdc++.h>

using namespace std;

struct w_int {
    bool exist;
    int x_min;
    int y_min;
    int x_max;
    int y_max;
};
const int MAX = 201;
vector<vector<int>> set_board(int n,vector<vector<int>> board)
{
    for(int i=0;i<n;i++)    
        for(int j=0;j<n;j++)        
            if(board[j][i] == 0)
                board[j][i] = -1;
            else
                break;    
    return board;
}
bool check(vector<vector<int>>& board_temp,vector<w_int>& table,int k)
{
    for(int x = table[k].x_min;x <= table[k].x_max;x++)
    {
        for(int y = table[k].y_min;y <= table[k].y_max;y++)
        {
            if(board_temp[x][y] != k && board_temp[x][y] != -1)
            {                
                return false;
            }
        }        
    }
    return true;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    vector<w_int> table (201,{false,INT_MAX,INT_MAX,INT_MIN,INT_MIN});    //도형 value
    vector<int> list;   //도형 list
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j] != 0)
            {
                int el = board[i][j];
                if(!table[el].exist)
                    list.push_back(el);
                table[el].exist = true;
                table[el].x_min = min(table[el].x_min,i);
                table[el].y_min = min(table[el].y_min,j);
                table[el].x_max = max(table[el].x_max,i);
                table[el].y_max = max(table[el].y_max,j);
            }
        }
    }
    //start
    int count = 1;
    while(count != 0)
    {
        count = 0;
        vector<vector<int>> board_temp = set_board(n,board);
        for(int i=0;i<list.size();i++)
        {
            int k = list[i];
            if(table[k].exist)
            {
                if(check(board_temp,table,k))
                {
                    count++;
                    table[k].exist= false;
                    for(int x = table[k].x_min;x <= table[k].x_max;x++)
                    {
                        for(int y = table[k].y_min;y <= table[k].y_max;y++)  
                        {
                            board[x][y] = 0;
                        }
                    }                    
                }
            }
        }        
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << board[i][j] <<" ";
            }
            cout << endl;
        }
        cout << endl;*/
        answer += count;
    }
    
    
    return answer;
}
