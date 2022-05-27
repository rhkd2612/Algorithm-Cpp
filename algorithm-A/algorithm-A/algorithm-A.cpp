#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define SMAX 1000005
#define PMAX 10005

vector<int> res;
string s, p;
int n, m;
int pi[PMAX];

void init() {
	cin >> s;
	cin >> p;
	n = s.length();
	m = p.length();
}

void getPI() {
	int i, j = 0;
	pi[0] = 0;

	for (i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
}

void kmp() {
	int j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				res.push_back(i - m + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
}

void print() {
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	getPI();
	kmp();
	print();
	return 0;
}