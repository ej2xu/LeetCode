class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& p) {
    sort(p.begin(), p.end(), [](pair<int, int> &left, pair<int, int> &right) {
      if (left.second != right.second)
        return left.second < right.second;
      return left.first > right.first;
    });
    list<pair<int, int>> res;
    for (auto person: p) {
      int n = person.second;
      auto it = res.begin();
      while (n) {
        if (it->first >= person.first)
          n--;
        it++;
      }
      res.insert(it, person);
    }
    return vector<pair<int, int>>(res.begin(), res.end());
  }
};
