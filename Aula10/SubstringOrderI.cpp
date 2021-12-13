#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long mxN = 1e5+5;
long long sa[mxN], pos[mxN], tmp[mxN], lcp[mxN];
long long gap, N;
string S;
 
bool comp(long long x, long long y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}
 
void suffix() {
    for (long long i = 0; i < N; i++)
        sa[i] = i, pos[i] = S[i];
    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+N, comp);
        for (long long i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]);
        for (long long i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}
 
void construirLCP() {
    for (long long i = 0, k = 0; i < N; i++) if (pos[i] != N-1) {
        long long j = sa[pos[i] + 1];
        while (S[i + k] == S[j + k])
            k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}
 
int main(){

    cin>>S; N = S.size();
    suffix();
    construirLCP();
    long long k; cin>>k;
    long long prev = 0;
    long long cur = 0;
    for (long long i = 0; i < N; i++) {
        if (cur + (N-sa[i]) - prev >= k) {
            long long j = prev;
            string ans = S.substr(sa[i], j);
            while (cur < k) {
                ans += S[sa[i]+j];
                cur++;
                j++;
            }
            return cout << ans, 0;
        }
        cur += (N-sa[i]) - prev;
        prev = lcp[i];
    }
}