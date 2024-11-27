#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;
#define int long long

const int MAXN = 1e6 + 2;
int lg[MAXN + 1];

void preprocess(){
    lg[1] = 0;
    for(int i = 2; i <= MAXN; i++)
        lg[i] = lg[i / 2] + 1;
}

// int st[26][MAXN + 1];

/* Define Function to build sparse table */
void buildSparseTable(vector<int> &arr, int n, vector<vector<int>> &sparse)
{
    for (int i = 0; i < n; i++)
        sparse[0][i] = arr[i];
 
    /* Build sparse table*/
    for (int m = 1; m < 26; m++)
        for (int i = 0; i <= n - (1 << m); i++)
 
            /* Updating the value of gcd. */
            sparse[m][i] = __gcd(sparse[m - 1][i],
                                 sparse[m - 1][i + (1 << (m - 1))]);
}
 
/* Query Processed */
int query(int L, int R, vector<vector<int>> &sparse)
{
    /* The maximum power of range that is less than 2 */
    int m = (int)lg[R - L + 1];
    return __gcd(sparse[m][L], sparse[m][R - (1 << m) + 1]);
}


int32_t main(){
    preprocess();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x: a)
            cin >> x;

        vector<vector<int>> sparse(26, vector<int>(n + 1));
        buildSparseTable(a, n, sparse);
        

        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int low = 0;
            int high = i;
            int ansind = i;

            while(low <= high){
                int mid = (low + high) / 2;
                int d = query(mid, i, sparse);
                if(d % a[i] == 0){
                    high = mid - 1;
                    ansind = mid;
                }else{
                    low = mid + 1;
                }
            }
            int num = (i - ansind) + 1;
            ans += num;
        }
        cout << ans << endl;
        
    }
    
}
