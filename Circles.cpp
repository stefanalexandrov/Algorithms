// you can use includes, for example:
#include <algorithm>
#include <utility>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    //sort(A.begin(), A.end());
    using LongPair = pair<long long, long long>;
    vector<LongPair> boundaries;
    boundaries.assign(A.size(), LongPair(0, 0));
    
    for (int i = 0; i < A.size(); i++) {
        boundaries[i] = LongPair(i-long(A[i]), i+long(A[i]));
    }
    auto comp = [] (LongPair a, LongPair b) {return a.second < b.second;};
    sort(boundaries.begin(), boundaries.end(), comp);
    
    unsigned long result = 0;
    
    for (auto it = boundaries.rbegin(); it != boundaries.rend(); it++) {
        //cout << it->first << " " << it->second << ", ";
        int right = it->second;
        int left = it->first;
        for (auto it2 = it+1; it2 != boundaries.rend() && it2->second >= left; it2++) {
            result++;
        }
    }
    if (result > 10000000)
        return -1;
    return result;
    /*
    vector<int> intersect;
    intersect.assign(A.size(), 0);
    
    for (int i = 0; i < A.size(); i++) {
        for (int j = i+1; j < (i + A[i] + 1) && j < A.size(); j++)
            intersect[j]++;
        for (int j = i; j > (i - A[i] - 1) && j != -1; j--)
            intersect[j]++;
    }
    //sort(intersect.begin(), intersect.end());
    long result = 0;
    int prev = 0;
    for (int el: intersect) {
        cout << el << " ";
        if (el > 1 && prev != el)
            result += el -1; 
    }
    return result;
    */
}
