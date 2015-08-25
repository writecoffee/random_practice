////////////////////////////////////////////////////////////////////////
// (detailed description could be find in 6.3.pdf.)
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
static int a, b, e;
static char *jug_1 = new char[3];
static char *jug_2 = new char[3];

void euclid(int a, int b, int &quotient, int &remainder) {
	assert(a >= b);
	quotient = a / b;
	remainder = a % b;
}

pair<int, int> ext_euclidean(int a, int b, int &gcd) {
	assert(a >= b);

	vector<int> r, q, s, t; int j = 0;
	s.push_back(1); s.push_back(0);
	t.push_back(0); t.push_back(1);
	r.push_back(a); r.push_back(b);
	q.push_back(0);	// dummy node

	while (r.back() != 0) {
		int quotient, remainder;
		euclid(r[j], r[j + 1], quotient, remainder);
		q.push_back(quotient);
		r.push_back(remainder);

		if (j != 0 && j != 1) {
			s.push_back(s[j - 2] - q[j - 1] * s[j - 1]); 
			t.push_back(t[j - 2] - q[j - 1] * t[j - 1]);
		}
		
		++j;
	}

	r.pop_back(); gcd = r.back();
	return make_pair(s[j - 2] - q[j - 1] * s[j - 1], t[j - 2] - q[j - 1] * t[j - 1]);
}

inline void fill(char *dest, int q) {
	cout << "fill up " << dest << " with " << q << " quart" << endl;
}

inline void transfer(char *from, char *dest, int q) {
	cout << "transfer " << q << " quart from " << from << " to " << dest << endl;
}

inline void dump(char *which) {
	cout << "dump " << which << endl;
}

void gen_sequence(int s, int t) {
	assert((s < 0 && t > 0) || (s > 0 && t < 0));
	int cnt_1 = 0, cnt_2 = 0, cnt_p = 0, ta, tb, tt;
	char *tj1, *tj2;

	s < 0 ? (ta = a, tb = b, tt = t, tj1 = jug_1, tj2 = jug_2) : 
		(ta = b, tb = a, tt = s, tj2 = jug_1, tj1 = jug_2);

	for (int j = 0; j < e; ++j) {
		for (int i = 0; i < tt; ++i) {
			cnt_1 += tb;
			cnt_2 = 0;
			cnt_p = tb;

			if (cnt_1 > ta) {
				cnt_2 = cnt_1 - ta;
				cnt_1 = cnt_2;
				cnt_p = tb - cnt_2;
				cnt_2 = 0;
	
				fill(tj2, tb);
				transfer(tj2, tj1, cnt_p);
				dump(tj1);
				transfer(tj2, tj1, cnt_1);
			} else {
				fill(tj2, tb);
				transfer(tj2, tj1, cnt_p);
			}

			if (cnt_1 == e) { return; }
		}
	}
}

void tc1() {
	a = 5, b = 3, e = 4; int gcd;
	jug_1[0] = a + '0'; jug_1[1] = 'Q'; jug_1[2] = 0;
	jug_2[0] = b + '0'; jug_2[1] = 'Q'; jug_2[2] = 0;

	pair<int, int> coef = ext_euclidean(a, b, gcd);
	cout << "tc1" << endl;
	cout << "x=" << coef.first << " y=" << coef.second << " GCD=" << gcd << endl;
	if (gcd == 1) { gen_sequence(coef.first, coef.second); } 
	else { cout << "Cannot assure appropriate sequence would be generated! BYE!" << endl; }
}

void tc2() {
	a = 5, b = 4, e = 3; int gcd;
	jug_1[0] = a + '0'; jug_1[1] = 'Q'; jug_1[2] = 0;
	jug_2[0] = b + '0'; jug_2[1] = 'Q'; jug_2[2] = 0;

	pair<int, int> coef = ext_euclidean(a, b, gcd);
	cout << "tc2" << endl;
	cout << "x=" << coef.first << " y=" << coef.second << " GCD=" << gcd << endl;
	if (gcd == 1) { gen_sequence(coef.first, coef.second); } 
	else { cout << "Cannot assure appropriate sequence would be generated! BYE!" << endl; }
}

int main() {
	tc1(); tc2();
	return 0;
}
