#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char word[200]; 
  int i, len;
  unsigned long long mult = 1;
  
  do{
    mult = 1;
    scanf("%s",word);
    len = strlen(word);
    for(i = 1; i <= len; i++){
      mult = mult*i;
    }
    cout << mult << endl;
  }while(1);
  return 0;
}