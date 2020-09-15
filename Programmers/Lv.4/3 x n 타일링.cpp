#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
n       result
2       n(2) = 3
4       n(2) * n(2) + 2                                         2
6       n(4) * n(2) + n(2) * 2 + 2    =>41                      8
8       n(6) * n(2) + n(4) * 2 + n(2) * 2 + 2                   30
n       n(n - 2) * n(2) + n(n - 4) * 2 + n(n - 6) * 2 ... + 2
.       .
.       .
*/

long long arr[5001];
const long long mod = 1000000007;

int solution(int n) {
    int answer = 0;
    //init
    arr[2] = 3;
    for(int i=4;i<=n;i+=2)
    {
        arr[i] = arr[i - 2] * arr[2];
        arr[i] %= mod;
        for(int j = 4; i - j > 0; j+=2)
        {
            arr[i] += arr[i - j] * 2;
            arr[i] %= mod;
        }
        arr[i] +=2;
    }
    answer = arr[n];
    return answer;
}