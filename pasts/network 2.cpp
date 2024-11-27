#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll mod = 1e9 + 7;
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}
void selectSort(int arr[], int n)
{
//pos_min is short for position of min
        int pos_min,temp;

        for (int i=0; i < n-1; i++)
        {
            pos_min = i;//set pos_min to the current index of array
                
                for (int j=i+1; j < n; j++)
                {

                if (arr[j] < arr[pos_min])
                   pos_min=j;
        //pos_min will keep track of the index that min is in, this is needed when a swap happens
                }
                
        //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
            if (pos_min != i)
            {
                 temp = arr[i];
                 arr[i] = arr[pos_min];
                 arr[pos_min] = temp;
            }
			for(int i=0;i<n;i++){
				cout<<arr[i]<<" ";
			}
			cout<<'\n';
        }
}
bool is_sorted(int a[],int n,int l,int r){
	for(int i=l;i<r-1;i++){
		if(a[i]>a[i+1]){
			return false;
		}
	}
	return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	while (n--)
	{
		ll a,b,c,r;
		cin>>a>>b>>c>>r;
		if(a>b){
			int temp=a;
			a=b;
			b=temp;
		}
		ll d =c+r;
		c = c-r;
		ll total = (b - a) + (d - c); 
		ll intersection = max(min(b, d) - max(a, c), 0LL);  
		ll t = b-a;

	   cout <<max(0LL,t-intersection)<< "\n";
	}
	
	
	

}
    
    
