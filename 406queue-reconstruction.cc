class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& p) {
    sort(p.begin(), p.end(), [](pair<int, int> &left, pair<int, int> &right) {
      return left.second < right.second || left.second == right.second && left.first > right.first;
    });
    list<pair<int, int>> res;
    for (auto &person: p) {
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


class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& p) {
    sort(p.begin(), p.end(), [](pair<int, int> &left, pair<int, int> &right) {
      return left.first > right.first || left.first == right.first && left.second < right.second;
    });
    list<pair<int, int>> res;
    for (auto &person: p)
      res.insert(next(res.begin(),person.second), person);
    return vector<pair<int, int>>(res.begin(), res.end());
  }
};
