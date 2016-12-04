/ you can use includes, for example:
#include <algorithm>
#include <set>
#include <map>
#include <utility>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    //std::sort(A.begin(), A.end());
    /*
    std::multiset<int> mset(A.begin(), A.end());
    //std::set<int> set(A.begin(), A.end());
    //cout << mset.size();
    for (auto it = mset.begin(); it != mset.end(); it++) {
        if (mset.count(*it)%2)
           return *it;
        // if (std::count(A.begin(), A.end(), *it)%2)
          //  return *it;
    }
    */
    std::map<int, size_t> mp;
    for (auto it = A.begin(); it != A.end(); it++) {
        //if (mp.find(*it) == std::unordered_map::end)
        auto el = mp.insert(std::pair<int, size_t>(*it, 0));
        el.first->second += 1;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if ((it->second)%2)
            return it->first;
    }
}
