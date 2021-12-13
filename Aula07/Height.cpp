#include <iostream>
#include <queue>
using namespace std;

int main(){
    int CN, N, x;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin>>CN;
    while(CN--){
        cin>>N;
        int n = 0;
        while(n++ < N){
            cin>>x;
            pq.push(x);
        }
        while (!pq.empty()) {
            if(pq.size() == 1)
                cout<<pq.top()<<endl;
            else
                cout<<pq.top()<<" ";
            pq.pop();
        }
    }

    return 0;
}