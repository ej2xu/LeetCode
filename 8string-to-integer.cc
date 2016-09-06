class Solution {
public:
    int myAtoi(string str) {
      int i = 0, res = 0, tail, tmpres;
      bool neg;
      while (isspace(str[i]))
        i++;
      neg = (str[i]=='-');
      if (str[i]=='+' || str[i]=='-')
        i++;
      while(isdigit(str[i])) {
        tail = str[i++]-'0';
        if (neg) {
          if (res < (INT_MIN+tail)/10)
            return INT_MIN;
          res = res * 10 - tail;
        } else {
          if (res > (INT_MAX-tail)/10)
            return INT_MAX;
          res = res * 10 + tail;
        }
      }
      return res;
    }
};
