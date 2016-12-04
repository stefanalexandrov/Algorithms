// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> A;
    A.assign(S.size(), 0);
    vector<int> C;
    C.assign(S.size(), 0);
    vector<int> G;
    G.assign(S.size(), 0);
    
    vector<int> Asum;
    Asum.assign(S.size()+1, 0);
    vector<int> Csum;
    Csum.assign(S.size()+1, 0);
    vector<int> Gsum;
    Gsum.assign(S.size()+1, 0);
    
    for (int i = 0; i < S.size(); i++) {
        switch(S[i]) {
            case 'A':
                A[i]++;
                break;
            case 'C':
                C[i]++;
                break;
            case 'G':
                G[i]++;   
        }
    }
    
    for (int i = 1; i < S.size()+1; i++) {
        Asum[i] = Asum[i-1] + A[i-1];
        Csum[i] = Csum[i-1] + C[i-1];
        Gsum[i] = Gsum[i-1] + G[i-1];
    }
    
    vector<int> result;
    result.assign(P.size(), -1);
    
    for (int i = 0; i < result.size(); i++) {
        int lb = P[i];
        int ub = Q[i];
        if ((Asum[ub+1] - Asum[lb+1] + A[lb]) > 0) 
            result[i] = 1;
        else if ((Csum[ub+1] - Csum[lb+1] + C[lb]) > 0) 
            result[i] = 2;
        else if ((Gsum[ub+1] - Gsum[lb+1] + G[lb]) > 0) 
            result[i] = 3;
        else
            result[i] = 4;
    }
    return result;
}
