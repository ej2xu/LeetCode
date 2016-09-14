class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> freq;
      for (int num: nums)
        freq[num]++;
      vector<int> res;
      priority_queue<pair<int, int>> pq;
      for (auto &x: freq) {
        pq.push({x.second, x.first});
        if (pq.size() > freq.size()-k) {
          res.push_back(pq.top().second);
          pq.pop();
        }
      }
      return res;
    }
};

//bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> freq;
      int mfreq = 0, last;
      for (int num: nums)
        mfreq = max(mfreq, ++freq[num]);
      vector<int> freqc(mfreq+1, 0);
      for (auto &x: freq)
        freqc[x.second]++;
      for (int i = mfreq; k > 0; i--)
        k -= freqc[last=i];
      vector<int> res;
      for (auto &x: freq)
        if (x.second >= last)
          res.push_back(x.first);
      return res;
    }
};
