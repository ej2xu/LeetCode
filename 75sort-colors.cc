class Solution {
public:
    void sortColors(vector<int>& a) {
      int i = 0, j = 0, n = a.size()-1;
      while (j <= n)
        if (!a[j])
          swap(a[i++], a[j++]);
        else if (a[j] == 2)
          swap(a[j], a[n--]);
        else j++;
    }
};
