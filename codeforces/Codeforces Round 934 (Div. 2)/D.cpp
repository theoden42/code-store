

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;

const int MAX_N = 1e6 + 5;

template<const unsigned &MOD>
struct _m_uint {
    unsigned val;

    _m_uint(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = unsigned(v);
    }

    _m_uint(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = unsigned(v);
    }

    _m_uint(int v) : _m_uint(int64_t(v)) {}
    _m_uint(unsigned v) : _m_uint(uint64_t(v)) {}

    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _m_uint& operator+=(const _m_uint &other) {
        val = val < MOD - other.val ? val + other.val : val - (MOD - other.val);
        return *this;
    }

    _m_uint& operator-=(const _m_uint &other) {
        val = val < other.val ? val + (MOD - other.val) : val - other.val;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    _m_uint& operator*=(const _m_uint &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    _m_uint& operator/=(const _m_uint &other) {
        return *this *= other.inv();
    }

    friend _m_uint operator+(const _m_uint &a, const _m_uint &b) { return _m_uint(a) += b; }
    friend _m_uint operator-(const _m_uint &a, const _m_uint &b) { return _m_uint(a) -= b; }
    friend _m_uint operator*(const _m_uint &a, const _m_uint &b) { return _m_uint(a) *= b; }
    friend _m_uint operator/(const _m_uint &a, const _m_uint &b) { return _m_uint(a) /= b; }

    _m_uint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_uint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_uint operator++(int) { _m_uint before = *this; ++*this; return before; }
    _m_uint operator--(int) { _m_uint before = *this; --*this; return before; }

    _m_uint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    friend bool operator==(const _m_uint &a, const _m_uint &b) { return a.val == b.val; }
    friend bool operator!=(const _m_uint &a, const _m_uint &b) { return a.val != b.val; }
    friend bool operator<(const _m_uint &a, const _m_uint &b) { return a.val < b.val; }
    friend bool operator>(const _m_uint &a, const _m_uint &b) { return a.val > b.val; }
    friend bool operator<=(const _m_uint &a, const _m_uint &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_uint &a, const _m_uint &b) { return a.val >= b.val; }

    static const int SAVE_INV = int(1e6) + 5;
    static _m_uint save_inv[SAVE_INV];

    static void prepare_inv() {
        // Ensures that MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    _m_uint inv() const {
        if (save_inv[1] == 0)
            prepare_inv();

        if (val < SAVE_INV)
            return save_inv[val];

        _m_uint product = 1;
        unsigned v = val;

        do {
            product *= MOD - MOD / v;
            v = MOD % v;
        } while (v >= SAVE_INV);

        return product * save_inv[v];
    }

    _m_uint pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _m_uint a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _m_uint &m) {
        return os << m.val;
    }
};

template<const unsigned &MOD> _m_uint<MOD> _m_uint<MOD>::save_inv[_m_uint<MOD>::SAVE_INV];

uint64_t random_address() { char *p = new char; delete p; return uint64_t(p); }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

// P = 2^32 - 13337 is a safe prime: both P and (P - 1) / 2 are prime.
const unsigned HASH_P = unsigned(-13337);
using hash_int = _m_uint<HASH_P>;

const uint64_t HASH_P2 = uint64_t(HASH_P) * HASH_P;
const int HASH_COUNT = 2;

// Avoid multiplication bases near 0 or P - 1.
uniform_int_distribution<unsigned> MULT_DIST(unsigned(0.1 * HASH_P), unsigned(0.9 * HASH_P));
const hash_int HASH_MULT[] = {MULT_DIST(rng), MULT_DIST(rng)};
const hash_int HASH_INV[] = {1 / HASH_MULT[0], 1 / HASH_MULT[1]};

vector<hash_int> hash_pow[] = {{1}, {1}};

const int INF = int(1e9) + 5;

template<typename T_string = string>
struct string_hash {
    // TODO: decide whether BUILD_REVERSE = true is needed.
    static const bool BUILD_REVERSE = true;

    static uint64_t hash(const T_string &str) {
        uint64_t result = 0;

        for (int h = 0; h < HASH_COUNT; h++) {
            uint64_t value = 1;

            for (const auto &x : str)
                value = (uint64_t(HASH_MULT[h]) * value + x) % HASH_P;

            result += value << (32 * h);
        }

        return result;
    }

    T_string str;
    vector<hash_int> _prefix[HASH_COUNT];
    vector<hash_int> _inv_prefix[HASH_COUNT];

    string_hash() {
        build({});
    }

    string_hash(const T_string &_str) {
        build(_str);
    }

    int length() const {
        return int(_prefix[0].size()) - 1;
    }

    template<typename T_char>
    void add_char(const T_char &c) {
        str.push_back(c);

        for (int h = 0; h < HASH_COUNT; h++) {
            _prefix[h].push_back(HASH_MULT[h] * _prefix[h].back() + c);

            if (hash_pow[h].size() < _prefix[h].size())
                hash_pow[h].push_back(HASH_MULT[h] * hash_pow[h].back());

            if (BUILD_REVERSE)
                _inv_prefix[h].push_back((_inv_prefix[h].back() + c) * HASH_INV[h]);
        }
    }

    void pop_char() {
        str.pop_back();

        for (int h = 0; h < HASH_COUNT; h++) {
            _prefix[h].pop_back();

            if (BUILD_REVERSE)
                _inv_prefix[h].pop_back();
        }
    }

    void build(const T_string &_str) {
        str = {};
        str.reserve(_str.size());

        for (int h = 0; h < HASH_COUNT; h++) {
            hash_pow[h].reserve(_str.size() + 1);
            _prefix[h] = {0};
            _prefix[h].reserve(_str.size() + 1);

            if (BUILD_REVERSE) {
                _inv_prefix[h] = {0};
                _inv_prefix[h].reserve(_str.size() + 1);
            }
        }

        for (auto &c : _str)
            add_char(c);
    }

    uint64_t _single_hash(int h, int start, int end) const {
        // Convert everything to `uint64_t` for speed. Note: we add hash_pow[length] to fix strings that start with 0.
        uint64_t power = uint64_t(hash_pow[h][end - start]);
        return (power + uint64_t(_prefix[h][end]) + HASH_P2 - uint64_t(_prefix[h][start]) * power) % HASH_P;
    }

    uint64_t substring_hash(int start, int end) const {
        assert(0 <= start && start <= end && end <= length());
        return _single_hash(0, start, end) + (HASH_COUNT > 1 ? _single_hash(1, start, end) << 32 : 0);
    }

    uint64_t complete_hash() const {
        return substring_hash(0, length());
    }

    uint64_t _reverse_single_hash(int h, int start, int end) const {
        // Convert everything to `uint64_t` for speed. Note: we add hash_pow[length] to fix strings that start with 0.
        uint64_t power = uint64_t(hash_pow[h][end - start]);
        return (power + uint64_t(_inv_prefix[h][end]) * power + HASH_P - uint64_t(_inv_prefix[h][start])) % HASH_P;
    }

    uint64_t reverse_substring_hash(int start, int end) const {
        assert(0 <= start && start <= end && end <= length());
        return _reverse_single_hash(0, start, end) + (HASH_COUNT > 1 ? _reverse_single_hash(1, start, end) << 32 : 0);
    }

    uint64_t reverse_complete_hash() const {
        return reverse_substring_hash(0, length());
    }

    bool equal(int start1, int start2, int length) const {
        return substring_hash(start1, start1 + length) == substring_hash(start2, start2 + length);
    }

    bool is_palindrome(int start, int end) const {
        return substring_hash(start, end) == reverse_substring_hash(start, end);
    }

    int compare(int start1, int start2, int max_length = INF) const;
};


template<typename T, bool maximum_mode = false>
struct RMQ {
	int n = 0;
	vector<vector<T>> range_min;
	RMQ(const vector<T> &values = {}) {
		if (!values.empty())
			build(values);
	}
	static int highest_bit(int x) {
		return x == 0 ? -1 : 31 - __builtin_clz(x);
	}
	static T better(T a, T b) {
		return maximum_mode ? max(a, b) : min(a, b);
	}
	void build(const vector<T> &values) {
		n = int(values.size());
		int levels = highest_bit(n) + 1;
		range_min.resize(levels);
		for (int k = 0; k < levels; k++)
			range_min[k].resize(n - (1 << k) + 1);
		if (n > 0)
			range_min[0] = values;

		for (int k = 1; k < levels; k++)
			for (int i = 0; i <= n - (1 << k); i++)
				range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
	}
	void show() const {
		for (int i = 0; i < int(range_min.size()); i++) {
			for (int j = 0; j < int(range_min[0].size()); j++) {
				cout << range_min[i][j] << " \n"[j + 1 == range_min[0].size()];
			}
		}
	}
	T query_value(int from, int to) const {
		assert(0 <= from && from <= to && to <= n - 1);
		int lg = highest_bit(to - from + 1);
		return better(range_min[lg][from], range_min[lg][to - (1 << lg) + 1]);
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    string_hash hasher(s);

    vector<vector<int>> f(n + 1, vector<int>(26));
    for(int i = 1; i <= n; i++){
    	f[i].assign(all(f[i - 1]));
    	f[i][s[i - 1] - 'a'] += 1;
    }

    vector<int> check(n + 1);
    for(int i = 1; i <= n - 2; i++){
    	if(s[i - 1] == s[i + 1]){
    		check[i] = 1;
    	}
    }

    RMQ<int> rmq(check);

    for(int i = 1; i <= q; i++){
    	int l, r;
    	cin >> l >> r;
    	vector<int> sum(26);
    	for(int i = 0; i < 26; i++){
    		sum[i] = f[r][i] - f[l - 1][i];
    	}
    	int flag = 0;
    	int len = r - l + 1;
    	for(int i = 0; i < 26; i++){
    		if(sum[i] == len){
    			flag = 1;
    			break;
    		}
    	}
    	ll ans = (1ll * len * (len - 1)) / 2 - 1;
    	if(flag){
    		ans = 0;
    	} else if(len >= 3) {
    		int c = rmq.query_value(l, r - 2);
    		if(c == 1){
    			int mx = (len - 1) / 2;
    			ans = (1ll * mx * (mx + 1));
    		}
    	}

    	if(!hasher.is_palindrome(l - 1, r)){
    		ans += len;
    	}

    	cout << ans << "\n";
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}