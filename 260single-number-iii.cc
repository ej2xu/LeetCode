class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int k = accumulate(a.begin(), a.end(), 0, bit_xor<int>());
    k &= -k;
    vector<int> res(2, 0);
    for (int num: nums)
      if (k & num)
        res[0] ^= num;
      else
        res[1] ^= num;
    return res;
  }
};
