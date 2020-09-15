#include <stack>
#include <iostream>
#include <algorithm>

/*
3개일때
min,max : *++ => 5
6개일때
min: **++++ => 13
max: *++*++ => 17
9개일때
min: ***++++++ => 33
max: *++*++*++ => 53
12개일때
min: ****++++++++ => 
max: *++*++*++*++ => 

*/


using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int answer;
//dfs
/*void solve(int val,stack<int> list,int n)
{
    if(list.empty() && val == n)
    {
        answer++;
        return;
    }
    else if(val > n)
        return ;
    else
    {
        //* 넣기
        list.push(0);
        solve(val * 3,list,n);
        list.pop();
        //+ 넣기
        if(!list.empty())
        {            
            list.top()++;
            if(list.top() == 2)
                list.pop();
            solve(val + 1,list,n);
        }
    }
    return ;
}*/
void dfs(int n,int r,int max_r)
{
    if(r > max_r)
        return ;
    if(n == 1)
    {
        if(r == 0) 
        {
            answer++;
            return ;
        }
        else
            return ;
    }
    if(r >= 2 && n % 3 == 0)    //*나올때
        dfs(n / 3,r - 2,max_r - 2);
    dfs(n - 1,r + 1,max_r); //+나올때
}
int solution(int n) {    
    answer = 0;
    long long left, right;
	int count = 1;
	left = 5;
	right = 5;
	while (right < n)
	{
		count++;
		right = (right * 3) + 2;
		left = pow(3, count) + count * 2;
	}
	if (n < left || n % 2 == 0)
		return 0;
    dfs(n - 2,2,count * 2);
    return answer;
}