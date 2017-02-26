#include <iostream>

// cout << "PRINTÁVEL"
// cin >> VAR_LEGíVEL

using namespace std;
 
int main()
{
	int n, x, y;
	
	int t, i, j;
	
	cin >> t;
	for (i=1; i<=t;i++){ 
		cin >> n;
		cin >> x;
		cin >> y;
		
		for (j=x; j<=n; j+=x) {
			if (!(j%y == 0))
				cout << j << " ";
		}
		
		cout << endl;
		
	}
	
	return 0;
}
