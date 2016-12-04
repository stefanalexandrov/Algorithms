// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    // write your code in C++11 (g++ 4.8.2)
    int result = 0;
    vector<int> blocks;
    blocks.reserve(H.size());
    blocks.push_back(0);
    for (int h: H) {
        while (blocks.back() > h)
            blocks.pop_back();
        if (blocks.back() == h)
            continue;
        blocks.push_back(h);
        result++;
    }
    return result;
}
