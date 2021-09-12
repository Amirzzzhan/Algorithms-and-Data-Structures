#define ll long long
#define se second
#define fi first
#define pb push_back
#define in insert
#define need_for_speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include<bits/stdc++.h>
using namespace std;
//int mod = 1000000007;
template<typename T> 
void print(T &v){
//	cout << v.size() << '\n';
	for(auto i : v) cout << i << ' ';
	cout << '\n';
}
const unsigned int N = 200000;
vector<int> fact(N+1,1); 
const int mod = 998244353;
int binpow(int a, int n){ 
	int res = 1;
	while(n > 0){
		if (n & 1){
			res = a * 1LL * res % mod;
		}
		a = a * 1LL * a % mod;
		n >>= 1;
	}
	return res;
}
int inv(int a){
	return binpow(a,mod - 2);
}
int C(int n, int r){
	return fact[n] * 1LL * inv(fact[r]) % mod * 1LL * inv(fact[n-r]) % mod;
}
int P(int n, int r){
	return fact[n] * 1LL * inv(fact[n-r]) % mod;
}
void solve(){
}
 
int main(){
	need_for_speed
	ll t = 1;
	fact[1] = 1;
	for(int i = 2; i <= N; i++){
		fact[i] = (i * 1LL * fact[i-1]) % mod;
	}
	cin >> t;
	while(t--) solve();
}

