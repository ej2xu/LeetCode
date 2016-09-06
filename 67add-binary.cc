class Solution {
public:
    string addBinary(string a, string b) {
      int m=a.size(), n=b.size(), l=max(m,n);
      string s(l+1, ' ');
      int carry=0;
      for (int i=0; i<l;i++) {
        int sum = (i<m ? a[m-i-1]-'0' : 0) + (i<n ? b[n-i-1]-'0' : 0) + carry;
        s[l-i] = '0'+sum%2;
        carry = sum/2;
      }
      if (carry) {
        s[0] = '1';
        return s;
      }
      return s.substr(1);
    }
};

//a cleaner Solution
public:
    string addBinary(string a, string b)
    {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        return s;
    }
};
