// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++11 (g++ 4.8.2)
    if (A == B && B == K)
        return 1;
        if (A == B && B == 1)
            return 0;
        if (A == B && B == 0)
            return 1;
    int result = B/K - A/K;
    (A%K) ? 1 :result++; 
    return result;
}
