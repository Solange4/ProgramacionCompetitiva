#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int n, t;
string s;
int SA[90001], LCP[90001];
int tmp[90001], poz[90001];

bool comparar(int i, int j){
    if (poz[i] != poz[j]) return (poz[i] < poz[j]);
    i += t;
    j += t;
    if (i < n && j < n) return (poz[i] < poz[j]);
    else return (i > j);
}

void construirSA(){
    for (int i=0;i<n;i++){
        SA[i] = i;
        poz[i] = s[i];
    }
    for (t = 1 ; t < 2*n+1; t *= 2){
        sort(SA, SA + n, comparar);
        for (int i=0;i<n-1;i++){
            tmp[i+1] = tmp[i];
            if (comparar(SA[i],SA[i+1])) tmp[i+1]++;
        }
        for (int i=0;i<n;i++)
            poz[SA[i]] = tmp[i];
        if (tmp[n-1] == n-1) 
            break;
    }
}
void construirLCP(){
    int k = 0;
    for (int i=0;i<n;i++){
        if (poz[i] != n-1){
            int j = SA[poz[i]+1];
            while (s[i+k] == s[j+k]) 
                k++;
            LCP[poz[i]] = k;
            if (k > 0)
                k--;
        }
    }
}
int main(){
    n = 7;
    s = "ABABBAB";
    construirSA();
    construirLCP();
    for (int i=0;i<n;i++) printf("%d ",LCP[i]);
    printf("\n");
    return 0;
}