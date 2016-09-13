#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long int LL;

bitset<600000> criba;
vector <int> pr;
void generarCriba( int n ){
	criba.set();//Establece todos a 1
	criba.set(0, 0);
	criba.set(1, 0); //0 y 1 no son primos y tenemos, [0 0 1 1 1 1...]
	pr.push_back(2);
	for(int i=4; i<=n; i+=2) criba[i]=0; //Colocando los pares a 0
	for(int i=3; i<=n; i+=2){
		if( criba[i] ){
			pr.push_back(i);
			for(LL k=i*i; k>0 && k<=n; k+=i)
				criba[k]=0;
		}
	}
}

int main(){
	int T, N, K, cont, dist, divr;
	long long int res;
	generarCriba( 500010 );
	scanf("%d", &T);
	vector <int> fc;
	set <int> dv, ans;
	set <int>::iterator it;
	while( T-- ){
		scanf("%d %d", &N, &K);
		cont = 0;
		while( N > 1 && cont<pr.size() ){
			while( N % pr[cont] == 0 ){
				fc.push_back(pr[cont]);
				// cout<<pr[cont]<<" ";
				N /= pr[cont];
			}
			cont++;
		}
		// cout<<endl;

		dist = fc.size();
		// fc = 2 2 3
		// 0 hasta 7, 000 hasta 111
		for(int i=1; i<(1<<dist); i++){
			divr = 1;
			for(int k=0; k<dist; k++)
				if( i & (1<<k) ) divr *= fc[k];

			if( divr % K != 0 ) ans.insert(divr);
		}
		res = 0LL;
		for( it = ans.begin(); it!= ans.end(); it++ )
			res += *it;
		if( res > 0LL ) cout<<++res<<endl;
		else cout<<res<<endl;
		fc.clear(); ans.clear();
	}
	return 0;
}
