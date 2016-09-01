class Solution {
public:
  bool containsDuplicate(vector<int>& a) {
    unordered_set<int> s;
    for (auto i: a) {
      if (s.find(i) != s.end())
        return true;
      s.insert(i);
    }
    return false;
  }
};
