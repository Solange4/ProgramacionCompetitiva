#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
 
int max(int a, int b){
    return (a > b)? a : b;
}
int LongestCommonS( char *X, char *Y, int m, int n ){
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + LongestCommonS(X, Y, m-1, n-1);
    else
        return max(LongestCommonS(X, Y, m, n-1), LongestCommonS(X, Y, m-1, n));
}

int main(){
    //Case 1
    char X1[] = "abcdefghij";
    char Y1[] = "cdgi";
    int m1 = strlen(X1);
    int n1 = strlen(Y1);
    cout<<LongestCommonS( X1, Y1, m1, n1 )<<endl;    
    //Case 2
    char X2[] = "abdace";
    char Y2[] = "babce";
    int m2 = strlen(X2);
    int n2 = strlen(Y2);
    cout<<LongestCommonS( X2, Y2, m2, n2 )<<endl;     
    return 0;
}
