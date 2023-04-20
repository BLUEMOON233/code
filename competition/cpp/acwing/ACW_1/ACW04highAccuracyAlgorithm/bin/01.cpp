#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

// vector<int> add(vector<int>& A, vector<int>& B) {
//     if (A.size() < B.size())
//         return add(B, A);
//     vector<int> C;
//     int t = 0;
//     for (int i = 0; i < A.size(); i++) {
//         t += A[i];
//         if (i < B.size())
//             t += B[i];
//         C.push_back(t % 10);
//         t /= 10;
//     }
//     if (t)
//         C.push_back(t);
//     return C;
// }
vector<int> add(vector<int>& A, vector<int>& B) {
	if (A.size() < B.size())
		return add(B, A);
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++) {
		t += A[i];
		if (i < B.size())
			t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if (t) C.push_back(t);
	return C;
}
// vector<int> sub(vector<int>& A, vector<int>& B) {
//     vector<int> C;
//     for (int i = 0, t = 0; i < A.size(); i++) {
//         t = A[i] - t;
//         if (i < B.size())
//             t -= B[i];
//         C.push_back((t + 10) % 10);
//         if (t < 0)
//             t = 1;
//         else
//             t = 0;
//     }
//     while (C.size() > 1 && C.back() == 0)
//         C.pop_back();
//     return C;
// }
vector<int> sub(vector<int>& A, vector<int>& B) {
	vector<int> C;
	for (int i = 0, t = 0; i < A.size(); i++) {
		t = A[i] - t;
		if (i < B.size())
			t -= B[i];
		C.push_back((t + 10) % 10);
		if (t < 0)
			t = 1;
		else
			t = 0;
	}
	while (C.size() > 1 && C.back() == 0)
		C.pop_back();
	return C;
}
// vector<int> mul(vector<int>& A, int b) {
//     vector<int> C;
//     int t = 0;
//     for (int i = 0; i < A.size() || t; i++) {
//         if (i < A.size())
//             t += A[i] * b;
//         C.push_back(t % 10);
//         t /= 10;
//     }
//     while (C.size() > 1 && C.back() == 0)
//         C.pop_back();
//     return C;
// }
vector<int> mul(vector<int>& A, int b) {
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || t; i++) {
		if (i < A.size())
			t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	while (C.size() > 1 && C.back() == 0)
		C.pop_back();
	return C;
}
// vector<int> div(vector<int>& A, int b, int& r) {
//     vector<int> C;
//     r = 0;
//     for (int i = A.size() - 1; i >= 0; i--) {
//         r = r * 10 + A[i];
//         C.push_back(r / b);
//         r %= b;
//     }
//     reverse(C.begin(), C.end());
//     while (C.size() > 1 && C.back() == 0)
//         C.pop_back();
//     return C;
// }
int r;
vector<int> div(vector<int>& A, int b, int& r) {
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--) {
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0)
		C.pop_back();
	return C;
}

int main() {
	ios::sync_with_stdio(false);
	vector<int> A, B, C;
	string a, b;
	cin >> a >> b;
	// string a;
	// cin >> a;
	for (int i = a.size() - 1; i >= 0; i--)
		A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--)
		B.push_back(b[i] - '0');
	// int b;
	// cin >> b;
	// int re = 0;
	// int& r = re;
	C = add(A, B);
	for (int i = C.size() - 1; i >= 0; i--)
		cout << C[i];
	cout << endl;
}
