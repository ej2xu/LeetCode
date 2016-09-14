class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& a) {
    vector<vector<int>> res;
    int n = a.size(), i = 0;
    if (n<3) return res;
    sort(a.begin(), a.end());
    while(true) {
      int j=i+1, k=n-1, s=-a[i];
      while(j<k) {
        while (k>j+1 && a[j]+a[k]>s) k--;
        if (a[j]+a[k]==s) {
          res.push_back(vector<int> {-s, a[j], a[k]});
          k--;
        }
        while (a[j]==a[++j] && j<k);
      }
      while (a[i]==a[++i] && i<j-1);
      if (i==j-1) break;
    }
    return res;
  }
};

//MaskRay's solutions
class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> r;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ) {
      int j = i+1, k = n-1, s = -a[i], old;
      while (j < k) {
        if (a[j]+a[k] < s) j++;
        else if (a[j]+a[k] > s) k--;
        else {
          r.push_back(vector<int>{a[i], a[j], a[k]});
          old = a[j];
          while (++j < k && a[j] == old);
          k--;
        }
      }
      old = a[i];
      while (++i < n && a[i] == old);
    }
    return r;
  }
};

//lunzige
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> results;
		map<int, int> counts;
		for (auto i : nums) {
			auto it = counts.find(i);
			if (it == counts.end())	{
				counts.insert(make_pair(i, 1));
			}
			else {
				it->second++;
			}
		}
		int size = counts.size();
		auto keys = new int[size];
		auto values = new int[size];
		{
			int index = 0;
			for (auto p : counts) {
				keys[index] = p.first;
				values[index] = p.second;
				index++;
			}
		}

		for (int i = 0; i < size; i++) {
			auto a = keys[i];
			for (int j = i; j < size; j++) {
				auto b = keys[j];
        if (a == b && values[i] < 2) continue;

				auto c = -(a + b);
				if (c < b) break;

				if (c == b && values[j] < 2) continue;
				if (c == a && values[i] < 3) continue;
				if (counts.find(c) == counts.end()) continue;

				results.push_back({ a, b, c });
			}
		}
		delete[] keys;
		delete[] values;
		return move(results);
    }
};
