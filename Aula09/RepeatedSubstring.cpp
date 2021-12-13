#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 8;
int sa[maxn], tam[maxn];
int _rank[maxn], t1[maxn], t2[maxn], c[maxn];
string s;

void construirSA(const int &n, int m){
    int *x = t1, *y = t2, p, j;
    for(int i = 0; i < m; i++) 
        c[i] = 0;
    for(int i = 0; i < n; i++) 
        ++ c[x[i] = s[i]];
    for(int i = 1; i < m; i++) 
        c[i] += c[i - 1];
    for(int i = n - 1; i >= 0; i--) 
        sa[-- c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1){
        p = 0;
        for(int i = n - k; i < n; i++) 
            y[p ++] = i;
        for(int i = 0; i < n; i++) 
            if(sa[i] >= k) 
                y[p ++] = sa[i] - k;
        for(int i = 0; i < m; i++) 
            c[i] = 0;
        for(int i = 0; i < n; i++) 
            ++ c[x[y[i]]];
        for(int i = 1; i < m; i++) 
            c[i] += c[i - 1];
        for(int i = n - 1; i >= 0; i--) 
            sa[--c[x[y[i]]]] = y[i];
        swap(x, y), p = 1, x[sa[0]] = 0;
        for(int i = 1; i < n; i++)
            x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k]) ? p - 1 : p ++;
        if(p >= n) 
            break;
        m = p;
    }
    int k = 0;
    for(int i = 0; i < n; i++)
        _rank[sa[i]] = i;
    for(int i = 0; i < n; i++){
        if(k) 
            --k; 
        if(!_rank[i]) 
            continue;
        j = sa[_rank[i] - 1];
        while(s[i + k] == s[j + k])
            k++;
        tam[_rank[i]] = k;
    }
}


int main(){
    int casos, n, sz, o, rpta;
    cin >> casos;
    while(casos--){
        cin >> s;
        sz = s.size();
        n = sz;
        construirSA(n+1, 256);
        rpta = o = 0;
        for(int i = 2; i <= n; i++){
            rpta += max(0, tam[i] - o);
            o = tam[i];
        }
        cout << rpta << "\n";
    }
    return 0;
}