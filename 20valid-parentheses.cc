class Solution {
public:
    bool isValid(string s) {
      stack<char> parens;
      char tmp;
      for (auto c: s)
        switch(c) {
          case '(': case '[': case '{':
            parens.push(c);
            break;
          case ')': case ']': case '}':
            if (parens.empty() || (tmp = parens.top(), c != tmp+1 && c != tmp+2))
              return false;
            parens.pop();
        }
      return parens.empty();
    }
};
