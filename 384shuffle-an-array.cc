class Solution {
public:
  Solution(vector<int> nums) : sec(nums) {}

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return sec; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    auto res = sec;
    for (int i = 1; i < res.size(); i++)
      swap(res[rand()%(i+1)], res[i]);
    return res;
  }
private:
  vector<int> sec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
