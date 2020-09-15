#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
첫번째 vector
각 words의 길이 순
두번째 vector
각 words의 사전단어 순
세번째 vector
words 배열
*/

/*vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer (queries.size(),0);
    sort(words.begin(),words.end());
    size_t max_length = 0;
    string post = words[0];
    for(int i=1;i<words.size();i++)
    {
        //중복 단어 제거 && 최대길이 측정
        if(post == words[i])
            words[i] = "0";
        else
            post = words[i];
        max_length = max(max_length,words[i].length());
    }
    //list 정리
    vector<vector<vector<string>>> list (max_length + 1,vector<vector<string>> (52,vector<string> ()));
    vector<int> length_number(max_length + 1,0);
    for(int i=0;i<words.size();i++)
    {
        if(words[i] == "0")
            continue;
        else
        {
            list[words[i].length()][words[i].front() - 'a'].push_back(words[i]);
            list[words[i].length()][words[i].back() - 'a' + 26].push_back(words[i]);
            length_number[words[i].length()]++;
        }
    }
    //queries 찾기
    for(int i=0;i<queries.size();i++)
    {
        if(queries[i].length() > max_length)
            continue;
        else if(queries[i].front() == '?' && queries[i].back() == '?')
        {
            answer[i] += length_number[queries[i].length()];
            continue;
        }
        if(queries[i].front() != '?')
        {
            vector<string> temp = list[queries[i].length()][queries[i].front() - 'a'];
            string qr = queries[i].substr(0,queries[i].find('?'));
            int start = 1;
            size_t pos;
            for(int j=0;j<temp.size();j++)
            {
                pos = temp[j].find(qr);
                if(pos == 0)
                {
                    start = j;
                    break;
                }                
            }
            for(int j = start;j<temp.size();j++)
            {
                pos = temp[j].find(qr);
                answer[i]++;
                if(pos == string::npos)
                    break;
            }
        }
        else
        {                  
            vector<string> temp = list[queries[i].length()][queries[i].back() - 'a' + 26];
            size_t pos = queries[i].rfind('?') + 1;
            string qr = queries[i].substr(pos);            
            for(auto str : temp)
            {
                size_t pos2 = str.rfind(qr);
                if(pos2 == pos)
                    answer[i]++;                
            }
        }
    }
    
    return answer;
}*/

/*
trie
*/
struct trie {
    int number;
    trie* next[26];
    trie() {
        this->number = 0;
        for(int i=0;i<26;i++)
            this->next[i] = NULL;
    };
};
const int MAX = 10001;
int words_length[MAX];

int search(string qr,trie* node)
{
    trie* temp = node;
    for(auto s : qr)
    {
        if(s == '?')
            break;
        else if(temp->next[s-'a'] == NULL)
            return 0;
        else
            temp = temp->next[s-'a'];
    }    
    return temp->number;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer (queries.size(),0);
    fill_n(words_length,MAX,0);
    vector<trie*> topt;
	for (int i = 0; i < MAX; i++)
		topt.push_back(new trie());
	vector<trie*> backt;
	for (int i = 0; i < MAX; i++)
		backt.push_back(new trie());
    //words setting
    for(auto str : words)
    {
        words_length[str.length()]++;
        trie* temp = topt[str.length()];
        //정방향
        for(auto s : str)
        {
            if(temp->next[s-'a'] == NULL)
            {
                temp->next[s-'a'] = new trie();
            }
            temp = temp->next[s-'a'];            
            temp->number++;
        }
        //역방향
        temp = backt[str.length()];
        reverse(str.begin(),str.end());
        for(auto s : str)
        {
            if(temp->next[s-'a'] == NULL)
            {
                temp->next[s-'a'] = new trie();
            }
            temp = temp->next[s-'a'];            
            temp->number++;
        }
    }
    
    //찾기
    for(int i=0;i<queries.size();i++)
    {
        string qr =queries[i];
        if(qr.front() == '?' && qr.back() == '?')
        {
            //length
            answer[i] = words_length[qr.length()];
        }
        else if(qr.back() == '?')
        {
            //정방향
            answer[i] = search(qr,topt[qr.length()]);
        }
        else if(qr.front() == '?')
        {
            //역방향
            reverse(qr.begin(),qr.end());
            answer[i] = search(qr,backt[qr.length()]);
        }
    }
    
    return answer;
}