class Solution {
public:
  vector<int> diffWaysToCompute(string input) {
    vector<int> nums;
    vector<char> ops;
    while (true) {
      int num = 0;
      while (j < input.size() && isdigit(input[j]))
        num = num * 10 + input[j++] - '0';
      nums.push_back(num);
      if (j < input.size())
        op.push_back(input[j++]);
      else break;
    }
  }
};
