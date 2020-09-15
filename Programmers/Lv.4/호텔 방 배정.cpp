#include <bits/stdc++.h>


using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long,long long> room;
    for(int i=0;i<room_number.size();i++)
    {
        long long t = room_number[i];
        if(room.find(t) == room.end())
        {
            room.insert(pair<long long,long long>(t,t + 1));
            answer.push_back(t);
        }
        else
        {
            while(room.find(t) != room.end())
            {
                long long a = t;
                t = room[t];
                room[a] = room_number[i];
            }                        
            room.insert(pair<long long,long long>(t,t + 1));
            room[room_number[i]] = t + 1;
            answer.push_back(t);
        } 
    }
    return answer;
}