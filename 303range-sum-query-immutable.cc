class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int> &nums) {
      int sum = 0;
      for (int num : nums) {
        sum += num;
        nums.push_back(sum);
      }
    }

    int sumRange(int i, int j) {
      return i ? sums[j] - sums[i-1] : sums[j];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
