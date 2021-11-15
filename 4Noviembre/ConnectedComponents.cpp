#include<iostream>
#include<stack>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>

int main(){
    int nodos,aristas;
    int casos;
    std::cin>>casos;
    for (int i=1; i<=casos; i--){
        std::cin>>nodos>>aristas;
        char matrix[nodos][nodos];
        memset(matrix,'#',sizeof(matrix));
        char u,p;
        for(int i=0;i<nodos;i++)
            matrix[i][0]=i+97;
        while(aristas--){
            std::cin>>u>>p;
            int z=u-97,Z=p-97;
            matrix[z][Z]=p;
            matrix[Z][z]=u;
        }
        std::cout<<"Case #"<<i<<":"<<std::endl;
        int v[nodos];
        memset(v,-1,sizeof(v));
        int contador=0;
        for(int i=0;i<nodos;i++){
            bool conectado=false;
            std::stack<char> t;
            if(v[i]==-1){
                t.push(i+97);
                contador++;
                v[i]=1;
                conectado=true;
            }
            std::stack<char>copia;
            int CP=0;
            while(!t.empty()){
                char d=t.top();
                if(CP!=0)
                   copia.push(d);
                else 
                    std::cout<<d<<",";
                t.pop();
                CP++;
                for(int j=0;j<nodos;j++){
                    if(matrix[d-97][j]!='#'){
                        if(v[matrix[d-97][j]-97]==-1){
                            conectado=true;
                            v[matrix[d-97][j]-97]=1;
                            t.push(matrix[d-97][j]);
                        }
                    }
                }
            }
            std::vector<char> s;
            while(!copia.empty()){
                char tp=copia.top();
                s.push_back(tp);copia.pop();
            }
            sort(s.begin(),s.end());
            for(int i=0;i<s.size();i++)
                std::cout<<s[i]<<",";
            if(conectado)
                std::cout<<std::endl;
        }
        std::cout<<contador<<" connected components"<<std::endl;
    }
    return 0;
}