#include <bits/stdc++.h>

using namespace std;

struct trie {    
    int count;
    trie* next[26];
    trie() {
        this->count = 0;
        for(int i=0;i<26;i++)
            this->next[i] = NULL;
    };
};
int solution(vector<string> words) {
    int answer = 0;
    //trie?
    //construct
    trie* top = new trie();
    for(int i=0;i<words.size();i++)
    {
        trie* temp = top;
        for(auto c : words[i])
        {            
            if(temp->next[c - 'a'] == NULL)          
                temp->next[c - 'a'] = new trie();
            temp = temp -> next[c - 'a'];
            temp -> count++;
        }
    }
    
    //find
    for(int i=0;i<words.size();i++)
    {
        trie* temp = top;
        int num = 0;
        for(auto c : words[i])
        {
            temp = temp -> next[c - 'a'];
            num++;
            if(temp->count == 1)
            {
                break;
            }            
        }
        answer += num;
    }    
    
    return answer;
}
