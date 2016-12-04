// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    if (A.size() == 0)
        return 0;
    sort(A.begin(), A.end());
    auto begin = find_if(A.begin(), A.end(), [](int el) {return el > 0;});
    if (begin == A.end())
        return 0;
    long long sum = 0;
    for (auto it = begin; it < A.end()-2; it++) {
        sum = long(*it) + *(it+1);
        if (sum > *(it+2))
            return 1;   
    }
    return 0;
}
