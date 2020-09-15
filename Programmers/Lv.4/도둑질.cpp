#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int> maxval;
    maxval.push_back(money[0]);
    maxval.push_back(money[1]);
    for(int i=2;i<money.size()-1;i++)
    {
        maxval.push_back(money[i]);
        int val = max(maxval[i-2],maxval[i-3]);      
        maxval[i] += val;
    }
    int first = *max_element(maxval.begin(),maxval.end());
    cout << first << endl;
    maxval.clear();    
    maxval.push_back(0);
    maxval.push_back(money[1]);
    for(int i=2;i<money.size();i++)
    {
        maxval.push_back(money[i]);
        int val = max(maxval[i-2],maxval[i-3]);      
        maxval[i] += val;
    }
    int second = *max_element(maxval.begin(),maxval.end());
    return max(first,second);
}