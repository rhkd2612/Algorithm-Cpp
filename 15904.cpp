#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define mod 1000000007

queue<char> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	q.push('U');
	q.push('C');
	q.push('P');
	q.push('C');

	string str;

	getline(cin,str);

	int idx = 0;

	while (!q.empty() && idx < str.length()) {
		if (str[idx++] == q.front()) {
			q.pop();
		}
	}

	if (q.empty())
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";

	return 0;
}