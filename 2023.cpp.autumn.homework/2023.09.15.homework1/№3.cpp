#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;
	cout << ((n / 10) * (n / 10 + 1)) * 100 + 25;
	return 0;
}