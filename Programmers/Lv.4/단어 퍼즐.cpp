#include <bits/stdc++.h>

using namespace std;

/*
trie 로 사용가능한 단어조각 dictionary 를 작성
O(1)로 접근가능하게함.
bfs로 현재 position에서 5개 뒤까지 봐서 NULL이거나 값이 없으면 out

*/
struct dic {
    int value;
    dic* next[26];
    dic() {
        this->value = 0;
        for(int i=0;i<26;i++)
            this->next[i] = NULL;
    };
};
int solution(vector<string> strs, string t)
{
    int answer = -1;
    dic* top = new dic();
    for(auto s : strs)
    {
        dic* temp = top;
        for(auto c : s)
        {
            if(temp->next[c - 'a'] == NULL)
            {
                temp->next[c - 'a'] = new dic();
            }
            temp = temp->next[c - 'a'];
        }
        temp->value = 1;
    }
    //bfs
    vector<int> list;
    list.push_back(0);
    int count = 0;
    vector<bool> check(t.length(),false);
    while(!list.empty())
    {        
        vector<int> n_list;
        for(auto l : list)
        {            
            int pos = l;
            if(check[pos])
                continue;
            check[pos] = true;
            dic* temp = top;
            if(pos == t.length())
            {
                n_list.clear();
                answer = count;
                break;
            }
            for(int i=0;i<5;i++)
            {
                if(pos + i == t.length())
                    break;
                if(temp->next[t[pos + i] - 'a'] == NULL)
                    break;
                else
                {
                    temp = temp->next[t[pos + i] - 'a'];
                    if(temp->value == 1)                    
                        n_list.push_back(pos + i + 1);                                                                                               
                }
            }
        }
        list = n_list;
        count++;
    }
    
    return answer;
}
