#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
using namespace std;

const int maxn = 1e6+10;
int n, m, num;
int s[maxn];
int sa[maxn], tamanio[maxn], x[maxn], y[maxn], rk[maxn], tong[maxn], str[maxn];
char st[maxn];

void construirSA(){
	for(int i = 0; i <= m; i++)
        tong[i] = 0;
	for(int i = 0; i <= 2*n; i++) 
        y[i] = x[i] = 0;
    for(int i = 1; i <= n; i++) 
        tong[x[i] = s[i]] ++;
    for(int i = 2; i <= m; i++) 
        tong[i] += tong[i-1];
    for(int i = n; i; i--) 
        sa[tong[x[i]]--] = i;
    for(int k = 1; k <= n; k <<= 1) {
        int num = 0;
        for(int i = n-k+1; i <= n; i++) 
            y[++num] = i;
        for(int i = 1; i <= n; i++) {
            if(sa[i] <= k) 
                continue;
            y[++num] = sa[i] - k;
        }
        for(int i = 0; i <= m; i++) 
            tong[i] = 0;
        for(int i = 1; i <= n; i++) 
            tong[x[i]]++;
        for(int i = 2; i <= m; i++) 
            tong[i] += tong[i-1];
        for(int i = n; i; i--) 
            sa[tong[x[y[i]]]--] = y[i], y[i] = 0;
    	for(int i = 0; i <= 2*num; i++){
    		int temp = x[i];
    		x[i] = y[i];
    		y[i] = temp;
		}
        x[sa[1]] = 1, num = 1;
        for(int i = 2; i <= n; i++) 
            x[sa[i]] = (y[sa[i]] == y[sa[i-1]] && y[sa[i] + k] == y[sa[i-1] + k]) == 1 ? num : ++ num;
        if(n == num) return;
        m = num;
    }
}

void tam() {
    for(int i = 1; i <= n; i++) 
        rk[sa[i]] = i;
    for(int i = 1, k = 0; i <= n; i++) {
        if(rk[i] == 1) 
            continue;
        if(k) 
            k--;
        int j = sa[rk[i]-1];
        while(i + k <= n && j + k <= n && s[i+k] == s[j+k]) 
            k++;
        tamanio[rk[i]] = k;
    }
}

bool check(int x)  {
	int cont = 0;
	bool mp[105] = {0};
	for(int i = 1; i <= n; i++){
		if(tamanio[i] >= x){
			if(!mp[str[sa[i-1]]])
				cont++, mp[str[sa[i-1]]] = 1;
			if(!mp[str[sa[i]]])
				cont++, mp[str[sa[i]]] = 1;
			if(cont > num/2)
				return true;
		}
		else{
			cont = 0;
			for(int i = 1; i <= num; i++)
				mp[i] = 0;
		}
	}
	return false;
}

void Solucion() { 
    construirSA();
    tam();
	int l = 1, r = 1005, ans = -1;
	while(l <= r){
		int m = l+r>>1;
		if(check(m)){
			ans = m;
			l = m+1;
		}
		else
			r = m-1;
	}
	if(ans == -1)
		puts("?");
	else{
		int cont = 0;
		bool mp[105] = {0};
		bool flag = false;
		for(int i = 1; i <= n; i++){ 
			if(tamanio[i] >= ans){
				if(!mp[str[sa[i-1]]])
					cont++, mp[str[sa[i-1]]] = 1;
				if(!mp[str[sa[i]]])
					cont++, mp[str[sa[i]]] = 1;
				if(cont == num/2+1){
					if(!flag){
						for(int j = sa[i]; j <= sa[i]+ans-1; j++)
							putchar(s[j]+'a'-1);
						putchar('\n');
						flag = true;
					}
				}
			}
			else{
				flag = false;
				cont = 0;
				for(int i = 1; i <= num; i++)
					mp[i] = 0;
			}
		}
	}
}

signed main(){
	while(~scanf("%d", &num)) {
		if(num == 0)
			break;
		int len = 0;
		for(int i = 1; i <= num; i++){
			scanf("%s", st+1);
			int lent = strlen(st+1);
			for(int j = len+1; j <= len+lent; j++){
				s[j] = st[j-len]-'a'+1; 
				str[j] = i;
			}
			len += lent;
			s[++len] = i+100;
		}
		n = len;
		m = 300; 
		Solucion();
		putchar('\n');
	}
    return 0;
}
