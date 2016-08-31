class Solution {
public:
    string convertToTitle(int n) {
      string result = "";
      while (n>0) {
        result += 'A'-1+(n%26 ? n%26 : 26);
        n = (n-1)/26;
      }
      reverse(result.begin(), result.end());
      return result;
    }
};
