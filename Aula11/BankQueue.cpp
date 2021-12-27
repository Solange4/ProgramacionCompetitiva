#include <stdio.h>  
#include <vector>
#include <algorithm> 
#include <iostream>

using namespace std; 

struct Persona{
    int dinero;
    int tiempo;
    Persona(int d, int t){
        dinero = d;
        tiempo = t;
    }
};
bool comparedinero(const Persona &a, const Persona &b){
        return a.dinero >= b.dinero;
}
void queuePersona(vector<int> &v, Persona c){
    int i = c.tiempo;
    
    while(i >= 0){
        if(v[i] == 0){
            v[i] = c.dinero;
            return;
        }  
        i--; 
    }
}
int main(){ 
    int N, T;
    int suma = 0;
    int i = 0;
    cin>>N>>T;
    vector<int> cola(T);
    vector<Persona> dinero;
    for(int i = 0; i < N; i++){
        int ci, ti;
        cin>>ci>>ti;
        Persona c(ci, ti);
        dinero.push_back(c); 
    }
    sort(dinero.begin(), dinero.end(), comparedinero);
    while(i < dinero.size()){
        queuePersona(cola, dinero[i]);
        i++;
    }
    for(int i = 0; i < cola.size(); i++){
        suma += cola[i];
    }
    cout<<suma<<endl;
    return 0;
}