//memset
#include <iostream>
using namespace std;
int main(){
	int v[1000];
	memset(v, -1, sizeof(v));
	return 0;
}
//Ordenar un vector estático
#include <cstdio>
#include <algorithm>

using namespace std;

void mostrar( int v[], int n ){
	for( int i=0; i<n; i++ ) printf("%d ",v[i] );
	printf("\n");
}

bool comp( int a, int b ){
	//Para ordenar descendentemente
	return a > b; // Si a > b entonces a irá primero
}

int main(){
	int n, v[1000010];
	scanf("%d", &n);
	for( int i=0; i<n; i++ ) scanf("%d", &v[i]);
	sort(v, v+n); // (!!), Ordenando ascendentemente
	mostrar(v, n);
	sort(v, v+n, comp); // Ordenando descendentemente
	mostrar(v, n);
	return 0;
}

//Ordenar un vector dinámico
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void mostrar( vector<int> v ){
	int n = v.size();
	for( int i=0; i<n; i++ ) printf("%d ", v[i] );
	printf("\n");
}

bool comp( int a, int b ){
	//Para ordenar descendentemente
	return a > b; // Si a > b entonces a irá primero
}

int main(){
	vector<int> v;
	int n, x;
	scanf("%d", &n);
	for( int i=0; i<n; i++ ) scanf("%d", &x), v.push_back(x);
	sort( v.begin(), v.end() ); // (!!), Ordenando ascendentemente
	mostrar(v);
	sort(v.begin(), v.end(), comp); // Ordenando descendentemente
	mostrar(v);
	return 0;
}

//Ordenar un vector dinámico de struct Punto
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Punto {
	int x, y;
	Punto(int _x, int _y) { x = _x; y = _y; }
};

void mostrar( vector<Punto> v ){
	int n = v.size();
	for( int i=0; i<n; i++ ) printf("%d %d\n", v[i].x, v[i].y );
}

bool compasc( Punto p, Punto q ){
	if( p.x == q.x ) return p.y < q.y;// p.y irá primero
	return p.x < q.x;
}
bool compdesc( Punto p, Punto q ){
	if( p.x == q.x ) return p.y > q.y;//p.y irá primero
	return p.x > q.x;
}

int main(){
	vector<Punto> v;
	int n, a, b;
	scanf("%d", &n);
	for( int i=0; i<n; i++ ) scanf("%d %d", &a, &b), v.push_back(Punto(a, b));
	sort( v.begin(), v.end(), compasc ); // (!!), Ordenando ascendentemente por x
	mostrar(v); printf("\n");
	sort(v.begin(), v.end(), compdesc); // Ordenando descendentemente por x
	mostrar(v);
	return 0;
}
//LOWER BOUND
#include <cstdio>

int LowerBound( int v[], int a, int b, int x ){
	// [a, ?, ?, ?, ?], b
	// [4, 5, 7, 7, 8]
	// Retorna el primer elemento que sea mayor o igual que x
	// Si todos son menores retorna b, o sea la SIGUIENTE posición al final
	// Si el vector es [4, 5, 7, 7, 8], debemos mandar con LowerBound(v, 0, 5, 7),
	// el segundo parámetro es la posición SIGUIENTE al final, no el final, 
	// el primer valor sí es la primera posición
	int mid;
	while( a < b ){
		mid = (b+a)/2;
		if( v[mid] >= x ){
			b = mid;
		} else{
			a = mid+1;
		}
	}
	return a;
}

int main(){
	int v[1010], n, x;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	scanf("%d", &x);
	printf("LB: %d", LowerBound(v, 0, n, x) );
	return 0;
}
//UPPER BOUND
#include <cstdio>

int UpperBound( int v[], int a, int b, int x ){
	// [a, ?, ?, ?, ?], b
	// [4, 5, 7, 7, 8]
	// Retorna el primer elemento que sea estrictamente mayor que x
	// Si todos son menores retorna b, o sea la SIGUIENTE posición al final
	// Si el vector es [4, 5, 7, 7, 8], debemos mandar con UpperBound(v, 0, 5, 7),
	// el segundo parámetro es la posición SIGUIENTE al final, no el final, 
	// el primer valor sí es la primera posición
	int mid;
	while( a < b ){
		mid = (b+a)/2;
		if( v[mid] > x ){
			b = mid;
		} else{
			a = mid+1;
		}
	}
	return a;
}

int main(){
	int v[1010], n, x;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	scanf("%d", &x);
	printf("UB: %d", UpperBound(v, 0, n, x) );
	return 0;
}
//LOGARITMOS
#include <cstdio>
#include <cmath>

int main(){
	double s=0;
	int n = 100000;
	//scanf("%d", &n);
	for( int i=1; i<=n; i++ ) {
		s += log2(i);
	}
	//s = log(n);   // log(n)   es en base e
	//s = log2(n);  // log2(n)  es en base 2
	//s = log10(n); // log10(n) es en base 10
	printf("%.7f\n", s );
	return 0;
}

//Esponenciación modular, halla la potencia de un número
//elevado a la n, módulo M, result = (a^b) mod M

#include <cstdio>
#include <iostream>

using namespace std;

int FastPowMod( int a, int b, int M ){
	int d = 1;
	for(int i=30; i>=0; i--){
		d = ( d * d ) % M;
		if( b & 1<<i )
			d = ( d * a ) % M;
	}
	return d;
}

int main(){
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	cout<<FastPowMod(a, b, n);
	return 0;
}

//INFINITO en Entero de 32 bits
#define INF 0x7FFFFFFF //Esto es un cero y 31 unos (!)

//msg
#define msg(a) cout<<#a<<" : "<<a<<endl;
//ESTO ES DESPUÉS DE YACUIBA
//Invertir una cadena
#include <iostream>

using namespace std;

int main(){
	string s;cin>>s;
	reverse( s.begin(), s.end() ); cout<<s<<endl;
	reverse( s.begin()+1, s.end()-2 ); cout<<s<<endl;
	return 0;
}
//Equivalencias para paridad
Par:  	i%2 == 0 ó !( i & 1 )
Impar: 	i%2 != 0 ó 	  i & 1
				    &		  |
000010 000001 000000 000011
000100 000001 000000 000101
000110 000001 000000 000111
001000 000001 000000 001001
001010 000001 000000 001011
001100 000001 000000 001101
001110 000001 000000 001111
010000 000001 000000 010001

000001 000001 000001 000001
000011 000001 000001 000011
000101 000001 000001 000101
000111 000001 000001 000111
001001 000001 000001 001001
001011 000001 000001 001011
001101 000001 000001 001101
001111 000001 000001 001111
//-----------
Esto dió Compilation error en UVa:
while( (cin>>n>>s) == 1 )

Con esto funcionó:
while( (cin>>n>>s) )
//Equivalencia entre character e integer
char c = '1';
int n = c-48; //n = 1

//Este es un set de estructuras
struct TNodo{
	int L, R, a;
	TNodo(int _L, int _R, int _a){
		L = _L; R = _R; a = _a;
	}

	bool operator < (const TNodo N) const{
		return L < N.L;
	}
};
set <TNodo> s;
