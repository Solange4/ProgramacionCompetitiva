#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
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
 
void constuirLCP() {
    for (long long i = 0, k = 0; i < N; i++) 
        if (pos[i] != N-1) {
            long long j = sa[pos[i] + 1];
            while (S[i + k] == S[j + k])
                k++;
            lcp[pos[i]] = k;
            if (k)
                k--;
        }
}

pair<long long,long long> seg[mxN*10];
long long mark[mxN*10];
 
void push(long long k) {
    if (mark[k]) {
        mark[k] = 0;
        seg[2*k].first = seg[2*k + 1].first = seg[k].first/2;
        seg[2*k].second = seg[2*k + 1].second = 0;
        mark[2*k] = mark[2*k + 1] = 1;
    }   
}
 
void actualizar(long long v, long long a, long long b, long long k, long long x, long long y) {
    if (b < x || a > y) 
        return;
    if (a<=x && b>=y) {
        seg[k].second += v;
        return;
    }
    long long h = min(b,y) - max(a,x) + 1;
    push(k); 
    seg[k].first += h*v;
    long long d = (x+y)/2;
    actualizar(v, a, b, 2*k, x, d);
    actualizar(v, a, b, 2*k + 1, d + 1, y);
}
long long assign(long long v, long long a, long long b, long long k, long long x, long long y) {
    if (b < x || a > y) 
        return seg[k].first + (y - x + 1)*seg[k].second;
    if (a <= x && b >= y) {
        seg[k].first = (y-x+1)*v;
        seg[k].second = 0;
        mark[k] = 1; 
        return seg[k].first;
    }
    push(k); 
    long long d = (x+y)/2;
    seg[2*k].second += seg[k].second,  seg[2*k + 1].second += seg[k].second;
    seg[k].second = 0;
    seg[k].first = assign(v, a, b, 2*k, x, d) + assign(v, a, b, 2*k + 1, d + 1, y);
    return seg[k].first;
}
long long sum(long long a, long long b, long long k, long long x, long long y) {
    if (b < x || a > y) 
        return 0;
    if (a <= x && b >= y) 
        return seg[k].first + (y-x+1)*seg[k].second;
    push(k); 
    seg[k].first += (y-x+1)*seg[k].second;
    seg[2*k].second += seg[k].second, seg[2*k + 1].second += seg[k].second;
    seg[k].second = 0;
    long long d = (x+y)/2;
    return sum(a, b, 2*k, x, d) + sum(a, b, 2*k + 1, d + 1, y);
}


int main(){
    cin>>S; N = S.size();
    suffix();
    constuirLCP();
    long long k; cin>>k;

    k = N*(N+1)/2 - k + 1; //pos from last
    long long K = 1<<(long long) ceil(log2(N+1));
    long long cur = 0;
    for (long long i = N-1; i >= 0; i--) {
        actualizar(1, 1, N-sa[i], 1, 0, K-1);
        long long prev = (i ? lcp[i-1] : 0);
        long long l = prev+1, r = N-sa[i];
        long long ans = -1;
        while (l <= r) {
            long long m = l + (r-l)/2;
            if (cur + sum(m, N-sa[i], 1, 0, K-1) >= k) {
                ans = m; l = m + 1;
            }
            else r = m - 1;
        }
        if (ans != -1) 
            return cout << S.substr(sa[i], ans), 0;
        cur += sum(prev+1, N-sa[i], 1, 0, K-1);
        assign(0, prev+1, N-sa[i], 1, 0, K-1);
    }
}