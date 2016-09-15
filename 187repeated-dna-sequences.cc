class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    int t = 0, i = 0, l = s.size();
    if (l <= 10) return res;
    unordered_map<int, int> seqtable;
    while (i < 9)
      t = t<<2 | (s[i++]-64)%5;
    while (i < l)
      if (seqtable[t = t<<2 & 0xfffff | (s[i++]-64)%5]++ == 1)
        res.push_back(s.substr(i-10, 10));
    return res;
  }
};

//MaskRay's rolling hash
class Solution {
public:
  vector<string> findRepeatedDnaSequences(string a) {
    unsigned i = 0, n = a.size(), t = 0;
    unordered_map<unsigned, unsigned> m;
    vector<string> r;
    while (i < min(9u, n))
      t = t<<3 | a[i++]&7;
    while (i < n)
      if (m[t = t<<3 & 0x3fffffff | a[i++]&7]++ == 1)
        r.push_back(a.substr(i-10, 10));
    return r;
  }
};
