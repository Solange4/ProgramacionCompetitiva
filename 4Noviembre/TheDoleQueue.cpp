#include <stdio.h>
#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

int main() {
    int N, K, M;
    int array[1000];
    while(cin >> N >> K >> M && N!=0&& K!=0&& M!=0) {
        int e = 0, f = N - 1;
        for(int i = 0;i < N; i++)
            array[i] = i + 1;
        int c = 0;
        while(c < N) {
            int i = K;
            int a,b;
            while (i > 0){
                if(array[e] > 0) i--;
                if(i == 0) a = e;
                e = (e + 1) % N;
            }
            i = M;
            while(i > 0) {
                if(array[f] > 0) i--;
                if(i == 0) b = f;
                f = (f + N - 1) % N;
            }
            if(c > 0)
                cout <<",";
            if(a != b) {
                cout<<array[a]<<" "<<array[b];
                c += 2;
            } 
            else {
                cout<<array[a];
                c++;
            }
            array[a] = array[b] = 0;
        }
        cout <<endl;
    }

    return 0;
}