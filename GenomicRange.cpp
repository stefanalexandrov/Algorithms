// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int NucImpact(char ch) {
    switch (ch) {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return -1;
    }
}
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> genom;
    vector<int> As;
    vector<int> Cs;
    vector<int> Gs;
    vector<int> result;

    for (int i = 0; i < S.size(); i++) {
        genom.push_back(NucImpact(S[i]));
        switch (genom[i]) {
            case 1:
                As.push_back(i);
                break;
            case 2:
                Cs.push_back(i);
                break;
            case 3:
                Gs.push_back(i);
                break;     
        }
    }
    sort(As.begin(), As.end());
    sort(Cs.begin(), Cs.end());
    sort(Gs.begin(), Gs.end());
    
    bool found = false;
    result.assign(P.size(), -1);
    for (int i = 0; i < P.size(); i++) {
        int lb = P[i];
        int ub = Q[i];
        auto compare = [lb, ub](int el) {return (el >= lb && el <= ub);};
        int min_impact = 4;
        
        if (!found) {
            auto it = find_if(As.begin(), As.end(),compare);
            if (it != As.end()) {
                    min_impact = 1;
                    found = true;
            }
        }           
        if (!found) {
            auto it = find_if(Cs.begin(), Cs.end(),compare);
            if (it != Cs.end()) {
                    min_impact = 2;
                    found = true;
            }
        }
        if (!found) {
            auto it = find_if(Gs.begin(), Gs.end(),compare);
            if (it != Gs.end()) {
                    min_impact = 3;
            }
        }
        found = false;
        
        /*
        bool done = false;
        for (int j = P[i]; j <= Q[i]; j++) {
            switch (genom[j]) {
                case 1: 
                    min_impact = 1;
                    done = true;
                    break;
                case 2: 
                    min_impact = 2;
                    break;
                case 3: 
                    min_impact = 3;
                    break;
            }
            if (done)
                break;
        }
        */
        
        result[i] = min_impact;       
    }
    return result;
}


// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int NucImpact(char ch) {
    switch (ch) {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return -1;
    }
}
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> genom;
    vector<int> As;
    vector<int> Cs;
    vector<int> Gs;
    vector<int> Ts;
    vector<int> result;

    for (int i = 0; i < S.size(); i++) {
        genom.push_back(NucImpact(S[i]));
        switch (genom[i]) {
            case 1:
                As.push_back(i);
                break;
            case 2:
                Cs.push_back(i);
                break;
            case 3:
                Gs.push_back(i);
                break;
            case 4:
                Ts.push_back(i);
                break; 
        }
    }
    sort(As.begin(), As.end());
    sort(Cs.begin(), Cs.end());
    sort(Gs.begin(), Gs.end());
    sort(Ts.begin(), Ts.end());
    
    int check_first = 0;
    if (S.size()/As.size() < 2) {
        check_first = 1;
    } else if (S.size()/Cs.size() < 2) {
        check_first = 2;
    } else if (S.size()/Gs.size() < 2) {
        check_first = 3;
    }
    
    
    bool found = false;
    result.assign(P.size(), -1);
    for (int i = 0; i < P.size(); i++) {
        int lb = P[i];
        int ub = Q[i];
        auto compare = [lb, ub](int el) {return (el >= lb && el <= ub);};
        int min_impact = 4;
        
        switch (check_first) {
        case 0:
        case 1:
            if (!found) {
                auto it = find_if(As.begin(), As.end(),compare);
                if (it != As.end()) {
                    min_impact = 1;
                    found = true;
                }
            }           
            if (!found) {
                auto it = find_if(Cs.begin(), Cs.end(),compare);
                if (it != Cs.end()) {
                    min_impact = 2;
                    found = true;
                }
            }
            if (!found) {
                auto it = find_if(Gs.begin(), Gs.end(),compare);
                if (it != Gs.end()) {
                    min_impact = 3;
                }
            }
            break;
        case 2:
            min_impact = 2;
            if (!found) {
                auto it = find_if(As.begin(), As.end(),compare);
                if (it != As.end()) {
                    min_impact = 1;
                    found = true;
                }
            }           
            if (!found) {
                auto it = find_if(Gs.begin(), Gs.end(),compare);
                if (it != Gs.end()) {
                    min_impact = 3;
                }
            }
            if (!found) {
                auto it = find_if(Ts.begin(), Ts.end(),compare);
                if (it != Ts.end()) {
                    min_impact = 4;
                }
            }
            break;
        case 3:
            min_impact = 3;
            if (!found) {
                auto it = find_if(As.begin(), As.end(),compare);
                if (it != As.end()) {
                    min_impact = 1;
                    found = true;
                }
            }           
            if (!found) {
                auto it = find_if(Cs.begin(), Cs.end(),compare);
                if (it != Cs.end()) {
                    min_impact = 2;
                    found = true;
                }
            }
            if (!found) {
                auto it = find_if(Ts.begin(), Ts.end(),compare);
                if (it != Ts.end()) {
                    min_impact = 4;
                }
            }
        }
        found = false;        
        result[i] = min_impact;       
    }
    return result;
}


// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int NucImpact(char ch) {
    switch (ch) {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return -1;
    }
}
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> genom;
    vector<int> As;
    vector<int> Cs;
    vector<int> Gs;
    vector<int> Ts;
    vector<int> result;

    for (int i = 0; i < S.size(); i++) {
        genom.push_back(NucImpact(S[i]));
        switch (genom[i]) {
            case 1:
                As.push_back(i);
                break;
            case 2:
                Cs.push_back(i);
                break;
            case 3:
                Gs.push_back(i);
                break;
            case 4:
                Ts.push_back(i);
                break; 
        }
    }
    sort(As.begin(), As.end());
    sort(Cs.begin(), Cs.end());
    sort(Gs.begin(), Gs.end());
    sort(Ts.begin(), Ts.end());
    
    int check_first = 0;
    if (As.size() && S.size()/As.size() < 2) {
        check_first = 1;
    } else if (Cs.size() && S.size()/Cs.size() < 2) {
        check_first = 2;
    } else if (Gs.size() && S.size()/Gs.size() < 2) {
        check_first = 3;
    }
    
    bool found = false;
    result.assign(P.size(), -1);
    for (int i = 0; i < P.size(); i++) {
        int lb = P[i];
        int ub = Q[i];
        auto compare = [lb, ub](int el) {return (el >= lb && el <= ub);};
        int min_impact = 4;
        
        switch (check_first) {
        case 0:
        case 1:
            if (!found) {
                auto it = find_if(As.begin(), As.end(),compare);
                if (it != As.end()) {
                    min_impact = 1;
                    found = true;
                }
            }           
            if (!found) {
                auto it = find_if(Cs.begin(), Cs.end(),compare);
                if (it != Cs.end()) {
                    min_impact = 2;
                    found = true;
                }
            }
            if (!found) {
                auto it = find_if(Gs.begin(), Gs.end(),compare);
                if (it != Gs.end()) {
                    min_impact = 3;
                }
            }
            break;
        case 2:
            min_impact = 2;
            if (!found) {
                auto it = find_if(As.begin(), As.end(),compare);
                if (it != As.end()) {
                    min_impact = 1;
                    found = true;
                }
            }           
            if (!found) {
                auto it = find_if(Gs.begin(), Gs.end(),compare);
                if (it != Gs.end()) {
                    min_impact = 3;
                    found = true;
                }
            }
            if (!found) {
                auto it = find_if(Ts.begin(), Ts.end(),compare);
                if (it != Ts.end()) {
                    min_impact = 4;
                }
            }
            if (min_impact > 2) {
                auto it = find_if(Cs.begin(), Cs.end(),compare);
                if (it != Cs.end()) {
                    min_impact = 2;
                }
            }
            break;
        case 3:
            min_impact = 3;
            if (!found) {
                auto it = find_if(As.begin(), As.end(),compare);
                if (it != As.end()) {
                    min_impact = 1;
                    found = true;
                }
            }           
            if (!found) {
                auto it = find_if(Cs.begin(), Cs.end(),compare);
                if (it != Cs.end()) {
                    min_impact = 2;
                    found = true;
                }
            }
            if (!found) {
                auto it = find_if(Ts.begin(), Ts.end(),compare);
                if (it != Ts.end()) {
                    min_impact = 4;
                }
            }
            if (min_impact > 3) {
                auto it = find_if(Gs.begin(), Gs.end(),compare);
                if (it != Gs.end()) {
                    min_impact = 3;
                }   
            }
            break;
        }
        found = false;        
        result[i] = min_impact;       
    }
    return result;
}
