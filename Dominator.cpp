// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    if (A.size() == 0)
        return -1;
    if (A.size() == 1)
        return 0;
    vector<int> stack;
    stack.reserve(A.size());
    stack.push_back(A[0]);
    int halfandOne = A.size()/2+1;
    for (int i = 1; i < A.size(); i++) {
        stack.push_back(A[i]);
        if (stack.size() >= 2 && stack.back() != stack[stack.size()-2]) {
            stack.pop_back();
            stack.pop_back();
        }
        if (stack.size() >= halfandOne)
            break;
    }
    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (stack.size() > 0 &&stack.back() == A[i])
            count++;
        if (count >= halfandOne)
            return i;
    }
    return -1;
}
