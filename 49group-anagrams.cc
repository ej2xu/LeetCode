class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> anamap;
    for (auto s: strs) {
      string ssort = s;
      sort(ssort.begin(), ssort.end());
      auto it = anamap.find(ssort);
      if (it == anamap.end())
        anamap[ssort] = vector<string> {s};
      else
        it->second.push_back(s);
    }
    for (auto &p: anamap)
      res.push_back(p.second);
    return res;
  }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        for(auto &v : strs) {
            string tmp(v);
            sort(tmp.begin(), tmp.end());
            hashMap[tmp].push_back(v);
        }
        vector<vector<string>> result(hashMap.size());
        int k = 0;
        for(auto it = hashMap.begin(); it != hashMap.end(); ++it, ++k)
            result[k].swap(it->second);
        return result;
    }
};
