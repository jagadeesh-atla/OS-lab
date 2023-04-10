#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int arr[n]; int temp;
	int best = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sum = max(temp, sum+temp);
		best = max(best, sum);
	}	
	cout << "largest Sum is " << best;
	return 0;
}
