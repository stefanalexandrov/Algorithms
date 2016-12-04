// you can use includes, for example:
// #include <algorithm>
#include <array>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void update_v(vector<int>& B, int max) {
    for (auto it = B.begin(); it !=B.end(); it++)
                *it = max;
}
vector<int> solution(int N, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> counters;
    counters.assign(N, 0);
    int max_counter = 0;
    bool update = false;
    int add = 0;
    for (int el: A) {
        if (el <= N && el >= 1) {
            if (update) {
                update_v(counters, max_counter);
                update = false;
            }
            if (++counters[el-1] > max_counter)
                max_counter = counters[el-1];
        }
        else
            update = true;   
    }
    if (update)
        update_v(counters, max_counter);
    return counters;
}

// you can use includes, for example:
#include <algorithm>
#include <map>
#include <utility>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> result;
    result.assign(N, 0);
    int maximum = 0;
    map<int, int> occurances;
    auto update = find(A.begin(), A.end(), N+1);
    auto last_update = A.begin();
    while (update != A.end()) {
        for (auto it = last_update; it != update; it++) {
            if (*it < N+1) {
                auto el = occurances.insert(pair<int, int>(*it, 1));
                if (el.second == false)
                    el.first->second++; 
            }
        }
        int tmp_max = 0;
        for (auto i: occurances) {
            if (i.second > tmp_max)
                tmp_max = i.second;
                //cout << i.first << " " << i.second << "\n";
        }
        maximum += tmp_max;
        //cout << maximum << "\n";
        occurances.clear();
        last_update = update;
        update = find(last_update+1, A.end(), N+1);
    }
    result.assign(N, maximum);
    
    for (auto it = last_update; it != A.end(); it++)
        if (*it < N+1)
            result[(*it)-1]++;
    
    return result;
}
