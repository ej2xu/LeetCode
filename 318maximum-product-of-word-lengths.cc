class Solution {
public:
  int maxProduct(vector<string>& words) {
    vector<int> wbits;
    int res = 0;
    for (auto &w: words) {
      int cur = 0;
      for (char c: w)
        cur |= 1 << c-'a';
      int i = 0;
      for (int wb: wbits) {
        if (!(wb & cur))
          res = max(res, int(w.size() * words[i].size()));
        i++;
      }
      wbits.push_back(cur);
    }
    return res;
  }
};

unordered_map<int,int> maxlen;
int result = 0;
for (string word : words) {
    int mask = 0;
    for (char c : word)
        mask |= 1 << (c - 'a');
    maxlen[mask] = max(maxlen[mask], (int) word.size());
    for (auto maskAndLen : maxlen)
        if (!(mask & maskAndLen.first))
            result = max(result, (int) word.size() * maskAndLen.second);
}
return result;
}
