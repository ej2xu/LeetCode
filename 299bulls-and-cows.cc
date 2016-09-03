class Solution {
public:
    string getHint(string secret, string guess) {
      int count[10] = {}, bull = 0, cow = 0;
      for (int i=0; i < secret.size(); i++)
        if (secret[i] == guess[i])
          bull++;
        else {
          if (count[secret[i]-'0']++ < 0)
            cow++;
          if (count[guess[i]-'0']-- > 0)
            cow++;
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};
