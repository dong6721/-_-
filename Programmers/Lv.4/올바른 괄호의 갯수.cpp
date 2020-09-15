#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct w_int {
    int used;
    int remain;
    w_int(int a,int b){
        used = a;
        remain = b;
    }
};
int solution(int n) {
    int answer = 0;
    //bfs
    vector<w_int> list;
    list.push_back(w_int(1,n - 1));
    while(!list.empty())
    {
        vector<w_int> n_list;
        for(auto t : list)
        {
            if(t.remain == 0)
            {
                answer++;
                continue;
            }            
            if(t.remain > 0)
                n_list.push_back(w_int(t.used + 1,t.remain - 1));
            if(t.used > 0)
                n_list.push_back(w_int(t.used - 1,t.remain));
        }
        list = n_list;
    }
    return answer;
}