#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int pila[1000000];
int N,K;

int comparar(const void *a, const void *b){
	return (*(int*)a-*(int*)b);
}

int main(){
	int a,b;
	cin>>N>>K;
	for(int i = 0; i < K; i++){
		cin>>a>>b;
		++pila[a-1];
		--pila[b];
	}
	for(int i = 1; i < N; i++)
		pila[i]+=pila[i-1];
	qsort(pila,N,sizeof(int),comparar);
	cout<<pila[N/2]<<endl;
	return 0;
}