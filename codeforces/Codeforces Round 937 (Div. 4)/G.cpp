

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
const ll MOD = 1e9 + 7;


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

#define int long long

int dp[16][16][(1 << 16)];

void solve() {
    int n;
    cin >> n;
    vector<string> gs(n), hs(n);
    for(int i = 0; i < n; i++){
    	cin >> gs[i] >> hs[i];
    }


    string_hash st;

    vector<uint64_t> g(n), h(n);
    for(int i = 0; i < n; i++){
    	g[i] = st.hash(gs[i]);
    	h[i] = st.hash(hs[i]);
    }


    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		for(int k = 0; k < (1 << n); k++){
    			dp[i][j][k] = -1;
    		}
    	}
    }

    for(int j = 0; j < n; j++){
    	dp[0][j][1 << j] = 1;
    }


    for(int i = 1; i < n; i++){
    	for(int j = 0; j < n; j++){
    		for(int k = 0; k < (1 << n); k++){
    			if(dp[i - 1][j][k] == -1)
    				continue;
    			dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
    			for(int l = 0; l < n; l++){
    				if(k >> l & 1)
    					continue;
    				if(g[l] == g[j] || h[l] == h[j]){
    					int nw = (k | (1 << l));
    					dp[i][l][nw] = max(dp[i][l][nw], dp[i - 1][j][k] + 1);
    				}
    			}
    		}	
    	}
    }

   	// // for(int i = 0; i < n; i++) 
    // for(int j = 0; j < n; j++){
    // 	for(int k = 0; k < (1 << n); k++){
    // 		debug(3, j, k);
    // 		cout << dp[3][j][k] << "\n";
    // 	}
    // }

    int mx = 0;
    for(int j = 0; j < n; j++){
    	for(int k = 0; k < (1 << n); k++){
    		mx = max(mx, dp[n - 1][j][k]);
    	}
    }

    int ans = n - mx;

    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}