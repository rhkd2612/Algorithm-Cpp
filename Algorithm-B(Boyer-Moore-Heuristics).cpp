#include <iostream>
#include <string>
#include <vector>

using namespace std;

// save result
vector<int> res;

// input sentence s, pattern p
string s, p;
// size of string s & p
int n, m;
// last occurance function
int loFunc[27];

void init() {
	cin >> s;
	cin >> p;
	n = s.length();
	m = p.length();

	// last occurance function initialize default value
	for (int i = 0; i < 27; i++)
		loFunc[i] = -1;
}

void getLastOccuranceFunction() {
	for (int i = 0; i < m; i++) {
		if (p[i] == 'X')
			continue;
		loFunc[p[i] - 'a'] = i;
	}
}

// get boyer-moore
void boyerMoore() {
	int i = m - 1, j = m - 1;
	int length = 0;

	while (i <= n - 1) {
		if (s[i] == p[j] || p[j] == 'X') {
			// add result
			if (j == 0) {
				res.push_back(i - j);
				cout << "1 ";
				length = 0;
				i += m;
				j = m - 1;
			}
			else {
				// check string
				length++;
				i--;
				j--;
			}
		}
		else {
			int l = loFunc[s[i] - 'a'];

			// if l not exists
			if (l == -1) {
				i += m;
				cout << m - length << ' ';
				length = 0;
				j = m - 1;
				continue;
			}

			// min check
			if (j > 1 + l) {
				i = i + m - (1 + l);
				cout << m - (1 + l) - length << ' ';
			}
			else {
				i = i + m - j;
				cout << m - j - length << ' ';
			}
			
			length = 0;
			j = m - 1;
		}
	}

	cout << '\n';
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
	getLastOccuranceFunction();
	boyerMoore();
	print();

	return 0;
}