#include <iostream>
using namespace std;

class Area {
	
	public:
		int x1;
		int y1;
		int x2;
		int y2;
		int nula;

		Area() { 
			nula = 0;
		};
		
		void intercalar(Area area2);
		
		void ler_do_teclado();
		void imprimir_no_monitor();
		void zerar();
		
	private:
		void intercalarX(Area area2);
		void intercalarY(Area area2);
		
};

void Area::intercalar(Area area2) { 
	if (! nula) {
		intercalarX(area2);
		intercalarY(area2);		
	}
}

void Area::intercalarX(Area area2) {
	if ( (x1 > area2.x2) || (x2 < area2.x1) ) { 
		nula=1;
	} else {
		if ( x2 > area2.x2 ) {
			x2 = area2.x2;
		} 
		if ( x1 < area2.x1) {
			x1 = area2.x1;
		}
	}
}

void Area::intercalarY(Area area2) {
	if ( (y1 < area2.y2) || (y2 > area2.y1) ) {
		nula=1;
	} else {
		if ( y1 > area2.y1 ) {
			y1 = area2.y1;
		} 
		if (y2 < area2.y2) {
			y2 = area2.y2;
		}
	}
	
}

void Area::ler_do_teclado() {
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
}

void Area::imprimir_no_monitor() {
	if (! nula) {
		cout << x1  << " " << y1 << " "
			 << x2  << " " << y2 << "\n";
	} else {
		cout << "nenhum\n";
	}
}

void Area::zerar() {
	nula = 0;
}


int main(){

	int n, i = 0;
	int count =1;
	
	Area reserva;
	Area area2;
	
	cin >> n;
	
	while (n > 0) {
		
		reserva.zerar();
		area2.zerar();
		
		cout << "Teste " << count << "\n";
		reserva.ler_do_teclado();
		
		for (i=2; i<=n;i++){ 
			area2.ler_do_teclado();
			reserva.intercalar(area2);
		}
		
		reserva.imprimir_no_monitor();
		
		cout << "\n";
		
		count++;
		cin >> n;
		
	}
	
	return 0;
}
