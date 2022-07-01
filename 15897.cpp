#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long int result = 0;
long long int n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	result = n;
	
	for (long long int i = 2, j; i < n; i = j + 1) {
		int c = (n - 1) / i + 1;
		j = (n - 1) / ((n-1)/i);
		result += c * (j - i + 1);
	}

	if (n != 1)
		result++;

	cout << result << '\n';

	return 0;
}