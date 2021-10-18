// Ejercicio 1
#include <iostream>
using namespace std;

bool Anagrama(string a, string b){
    /*  Función que identifica si dos strings son anagramas o no. Un anagrama es 
        una palabra que resulta de la transposición de letras de otra palabra.
    */
    bool flag = true;
    int pos1 = 0;
    while (pos1 < a.length() && flag){
        int pos2 = 0;
        bool found = false;
        while (pos2 < b.length() && !found){
            if(a[pos1] == b[pos2])
                found = true;
            else
                pos2 += 1;
        }
        if (found)
            pos1 += 1;
        else
            flag = false;
    }
    return flag;
}

void EsAnagramaa(string a, string b){
    if(Anagrama(a,b))
        cout<<"Si es anagrama"<<endl;
    else
        cout<<"No es anagrama"<<endl;
}
int main(){
    // Caso prueba 1:
    // Entrada: Trama Marta
    // Salida: Si es anagrama
    string a1 = "trama";
    string a2 = "marta";
    EsAnagramaa(a1,a2);
    // Caso prueba 2:
    // Entrada: Amor Roma
    // Salida: Si es anagrama
    string b1 = "amor";
    string b2 = "roma";
    EsAnagramaa(b1,b2);
    // Caso prueba 3:
    // Entrada: Hola Como
    // Salida: No es anagrama
    string c1 = "hola";
    string c2 = "como";
    EsAnagramaa(c1,c2);
    return 0;
}