#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
 
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#define f first
#define s second
#define ll long long
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define y1 qwqwqwqw
 
using namespace std;
 
const int maxn = 5e5 + 11;
const ll mod = 998244353;
 
long long n, m, k, x, f[maxn];
ll res, T;
vector < pair <ll, ll> > v;
ll a[maxn], Z;
int main() {
	scanf("%I64d%I64d%I64d", &n, &k, &m);
	for (int i = 1; i <= n; i++) {
	 	scanf("%I64d", &a[i]);
	}
 
	int ok = 0;
	v.pb(mp(1, a[1]));
	for (int i = 2; i <= n; i++) {
	 	if (a[i - 1] == a[i]) 
	 		v[v.size() - 1].f++;
	 	else {
	 	    if (v.back().f >= k) {
	 	     	ok = 1;
	 	     	v.pop_back();
	 	    }
 
	 	    if (!v.empty() && v.back().s == a[i]) 
	 			v[v.size() - 1].f++;
	 		else
	 			v.pb(mp(1, a[i]));
	 	}
	}
	if (v.back().f >= k) {
	 	 ok = 1;
	 	 v.pop_back();
	}
 
 
	ll sum = 0;
	for (int i = 0; i < v.size(); i++) {
	 	sum += v[i].f;
	}
 
 
	if (v.size() == 0) {
	 	cout << 0;
	 	return 0;
	}
	if (v.size() == 1) {
	    if (ok == 1 && v[0].s == a[n] && v[0].s == a[1]) {
	     	cout << v[0].f;
	     	return 0;
	    }
	    T = (k + v[0].f - 1) / v[0].f;
	    m -= (m / T) * T;
	    cout << m * 1ll * v[0].f; 
		return 0;
	}
 
	if (v[0].s != v.back().s || v[0].f + v.back().f < k) {
	 	cout  <<  sum *1ll * m ;
	 	return 0;
	}
 
	if (v.size() == 2) {
	 	cout << m * 1ll * sum;
		return 0;
	}
	if (v.size() > 3) {
	
		ll cur = 0;
		int pos = -1;
		for (int i = 0; i < v.size() / 2; i++) {
		 	if (v[i].s != v[v.size() - i - 1].s || v[i].f + v[v.size() - i - 1].f < k) {
		 		pos = i;
		 		break;
		   }
		   cur += v[i].f;
		   cur += v[v.size() - i - 1].f;
		}
		if (pos == -1) {
		 	cout << 0;
		 	return 0;
		}
		
		cout << sum * 1ll * m - (m - 1) * cur;
 
		return 0; 			
	}
 
	T = (v[1].f + k - 1) / v[1].f;
 
    Z = (m)/ (T); 
    
    m -= Z * (T);
 
    if (m) {
   		cout << m * 1ll * v[1].f + v[0].f + v[2].f << endl;
   	} else {
   		cout << 0; 	
   	}
 
 
   	}
