class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int i = 0, j = 0;
      for (; i<nums.size();i++)
        if (nums[i] != val)
          nums[j++] = nums[i];
      return j;
    }
};

//solution swapping front matching element to the end
int removeElement(int A[], int n, int elem) {
    int i = 0;
    while (i < n) {
        if (A[i] == elem) {
            A[i] = A[n - 1];
            n--;
        }
        else
            i++;
    }
    return n;
}
