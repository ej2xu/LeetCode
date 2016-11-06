class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int dec = 1;
    while (x/dec >= 10)
      dec *= 10;
    while (dec >= 10 && x/dec%10 == x%10) {
      x /= 10;
      dec /= 100;
    }
    return dec < 10;
  }
};

//gaurav5's solution constructing the lower half in a sum
class Solution {
public:
  bool isPalindrome(int x) {
    if(x<0 || x && !(x%10)) return false;
    int sum=0;
    while(x>sum) {
        sum = sum*10+x%10;
        x = x/10;
    }
    return x==sum || x==sum/10;
  }
};
