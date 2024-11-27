#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;

	cin >> t;
	while(t!=0)
	{
        string s;
        cin >> s;//enter string
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string st = "selena";
        string str = "gomez";
        int i = 0,j=0;
        int k = 0;
        int m = 0;
        int c1 = 0;
        int c2 = 0;
        int c;

        int l1 = s.length();
        int l2 = st.length();
        int l3 = str.length();
        int p;
        for(i =0;i<l1;){
            j=0, c=0 ;
            while(s[i]==st[j] && i < l1 && j<l2)
            {
                c++;
                i++;
                j++;  
            }
            if(c==l2)
            {
                c1++;
                c=0;
                p=i;
                for(k=p;k<l1;){
                    m=0,c=0;
                    
                    while(s[k]==str[m]&&k<l1&&m<l3)
                    {
                        c++;
                        k++;
                        m++;
                        
                    }
                    if(c==l3)
                    {
                        c2++;
                        c=0;
                    }
                    else
                    {
                        k++;
                    }
                }
            }
            else
            {
                i++;
            }
        }
        cout<<c2<<endl;
        t--;
	}
	return 0;
}