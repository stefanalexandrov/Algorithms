// you can use includes, for example:
// #include <algorithm>
#include <stack>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool compare(char a, char b) {
    switch (a) {
        case ')':
            if (b == '(')
                return true;
            break;
        case '}':
            if (b == '{')
                return true;
            break;
        case ']':
            if (b == '[')
                return true; 
    }
    return false;
}

int solution(string &S) {
    // write your code in C++11 (g++ 4.8.2)
    if (S.size() == 0)
        return 1;
        
    int half_size = S.size()/2 + 1;
    vector<char> opening;
    opening.reserve(half_size);
    //stack<char> closing;
    
    for (char ch: S) {
        //cout << ch << " ";
        if (ch == '(' || ch == '{' || ch == '[') {
            if (opening.size() > half_size)
                return 0;
            opening.push_back(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (!compare(ch, opening.back()))
                return 0;
            else {
               //closing.push(ch);
               if (opening.size() == 0)
                    return 0;
                opening.pop_back();
            }
        }
        //cout << opening.size() << ", ";
    }
    if (opening.size() == 0)
        return 1;
    else
        return 0;
}
