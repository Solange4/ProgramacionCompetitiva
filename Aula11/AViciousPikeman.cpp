#include <iostream>
using namespace std;

int comp(const void *p, const void *q) {
    int *a = (int *) p;
    int *b = (int *) q;
    return *a - *b;
}

int main() {
    long n, t, a, b, c;
    long ti[10000];
    cin >>n>>t>>a>>b>>c>>ti[0];
    for (int i = 1; i < n; i++)
        ti[i] = ((a * ti[i-1] + b) % c) + 1;
    qsort(ti, n, sizeof(long), comp);
    int p = 0;
    int s = 0;
    int t_p = 0;
    for (int i = 0; i < n; i++) {
        if (t_p + ti[i] <= t) {
            p = (p + ti[i] + t_p) % 1000000007;
            t_p += ti[i];
            s++;
        } 
        else 
            break;
    }
    cout <<s<<" "<<p<<endl;
    return 0;
}