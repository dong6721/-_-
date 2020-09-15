#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
/*
C++ 코드에서 효율성 테스트 1,5번 빼고는 통과하지 못한다.
2020/4/7 이후 테스트케이스가 바뀌면서 범위만 바뀌고 통과시간은 그대로라서 발생한문제인듯?
여기서 더 시간을 줄이려면 소수판별법 알고리즘을 새로 구현해서 홀수에서 소수일경우를 빠르게 찾는경우 말고는 없는듯 함.
*/
long long max_block = 10000000;
vector<int> solution(long long begin, long long end) {
    vector<int> answer ;
    if(begin == 1)
    {
        answer.push_back(0);
        begin++;
    }
    for(long long i = begin; i <= end;i++)
    {
        if(i % 2 == 0)
        {
            //짝수
            int dec = 1;            
            for(int j = 2;j <= sqrt(i);j++)
            {
                if(i % j == 0 && i / j <= max_block)
                {
                    dec = i / j;                    
                    break;                                       
                }
            }
            answer.push_back(dec);
        }
        else
        {
            //홀수
            int dec = 1;
            for(int j =3;j <= sqrt(i);j += 2)
            {
                if(i % j == 0 && i / j <= max_block)
                {
                    dec = i / j;
                    break;
                }
            }
            answer.push_back(dec);
        }        
    }
    return answer;
}