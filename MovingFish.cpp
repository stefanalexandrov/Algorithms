// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> upstream;
    upstream.reserve(A.size());
    vector<int> downstream;
    downstream.reserve(A.size());
    
    for (int i = B.size()-1; i >= 0; i--) {
        if (B[i] == 0)
            upstream.push_back(A[i]);
        else {
            int size = A[i];
            downstream.push_back(size);
            for (int j = upstream.size()-1; j >= 0; j--) {
                if (upstream[j] < size && upstream.size() != 0)
                    upstream.pop_back();
                else {
                    downstream.pop_back();
                    break;
                }
            }
        }
    }
    return upstream.size() + downstream.size();
}
