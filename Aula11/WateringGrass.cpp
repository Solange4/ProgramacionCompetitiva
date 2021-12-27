#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct Intervalo{
    double a;
    double b;
    int index;

    bool operator < (Intervalo x) const {
        return a < x.a;
    }
};

int main(){
    vector<int> cover;
    bool posible;
	int n,l, mejor;
	double w, maxx; 
	while (cin >> n >> l >> w){
		Intervalo intervalos[n];
		for (int i=0;i<n;i++){
            double x, r;
			cin >> x >> r; 
			if (r >= w/2){
				double p = sqrt(r*r -w*w/4);
				intervalos[i].a = x - p;
				intervalos[i].b = x + p;
				intervalos[i].index = i;
			}
			else {
				intervalos[i].a = -1;
				intervalos[i].b = -1;
				intervalos[i].index = i;
			}
		}
		double A = 0;
		double B = l;

        sort(intervalos,intervalos+n); 
        int it = 0;
        cover.clear();
        posible = true;
        while (intervalos[it].b < A){
            it++;
            if (it == n){
                posible = false;
                break;
            }
        }
        if (A == B && posible){
            if (intervalos[it].a <= A && intervalos[it].b >= A)
                cover.push_back(intervalos[it].index);
            else posible = false;
        }
        while (A < B && posible){
            if (it == n){
                posible = false;
                break;
            }
            maxx = -1;
            mejor = -1;
            while (intervalos[it].a <= A){
                if (intervalos[it].b - A > maxx){
                    maxx = intervalos[it].b - A;
                    mejor = it;
                }
                it++;
                if (it == n) break;
            }
            if (mejor == -1){
                posible = false;
                break;
            }
            cover.push_back(intervalos[mejor].index);
            A = intervalos[mejor].b;
        }
        if (!posible)
            cout<<"-1"<<endl;
        else{
            cout<<cover.size()<<endl;
        }
	}
    return 0;
}