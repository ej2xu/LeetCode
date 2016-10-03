class Solution {
public:
  int longestPalindrome(string s) {
    int l[26] = {0}, u[26] = {0};
    for (auto c: s)
      if (islower(c))
        l[c-'a']++;
      else
        u[c-'A']++;
    bool odd = false;
    int sum = 0;
    for (int i = 0; i < 26; i++) {
      if (l[i]&1 || u[i]&1) odd = true;
      sum += (l[i]&0xFFFFFFFE) + (u[i]&0xFFFFFFFE);
    }
    return odd ? sum+1 : sum;
  }
};

int longestPalindrome(string s) {
    int odds = 0;
    for (char c='A'; c<='z'; c++)
        odds += count(s.begin(), s.end(), c) & 1;
    return s.size() - odds + (odds > 0);
}
