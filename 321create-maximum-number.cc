class Solution {
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    vector<int> res;
    for (int i = max(k-n, 0); i <= k && i <= m; i++)
      res = max(res, merge(maxNumber(nums1, i),maxNumber(nums2, k-i)));
    return res;
  }

  vector<int> merge(vector<int> nums1, vector<int> nums2) {
    vector<int> res;
    auto m = nums1.end(), n = nums2.end(), i = nums1.begin(), j = nums2.begin();
    while (i != m && j != n)
      res.push_back(lexicographical_compare(i, m, j, n) ? *j++ : *i++);
    if (j == n)
      res.insert(res.end(), i, nums1.end());
    if (i == m)
      res.insert(res.end(), j, nums2.end());
    return res;
  }

  vector<int> maxNumber(vector<int>& a, int k) {
    int n = a.size();
    vector<int> res(k, 0);
    for (int i = 0, j = 0; i < n; i++) {
      while (n-i>k-j && j && res[j-1] < a[i]) j--;
      if (j < k) res[j++] = a[i];
    }
    return res;
  }
};

//optimized version https://discuss.leetcode.com/topic/36805/c-16ms-fastest-beats-97
class Solution {
public:
    #define MIN(a,b) (a<b?a:b)
    #define MAX(a,b) (a>b?a:b)
    const int soi = sizeof(int);
    // create max number of length t from single non-empty vector
    void getMax(int* num, int n, int* result, int k, int& sortedn) {
    	const int need2drop = n-k;
    	for (int i = 0, j = 0; i < n; ++i) {
    		int n = num[i];
    		while (i-j < need2drop && j && result[j-1] < n) j--;
    		if (i-j == need2drop) {
    			sortedn = MAX(1, j);
    			while (j < k) result[j++] = num[i++];
    			return;
    		}
    		if (j < k) result[j++] = n;
    	}
    }
    // create max number of different length from single vector
    void dp(int *num, int len, int& sortedLen, int minL, int maxL, int *res, int k){
    	int j, *head, *prevhead = res;
    	getMax(num, len, res, maxL, sortedLen);
    	for (int l = maxL; l > MAX(minL, 1); l--) {
    		head = prevhead + k;
    		memcpy(head, prevhead, l*soi);
    		for (j = sortedLen; j < l; ++j) {
    			if (head[j] > head[j-1]){
    				sortedLen = MAX(1, j-1);
    				memcpy(head + j - 1, prevhead + j, soi*(l - j));
    				break;
    			}
    		}
    		if (j == l) sortedLen = l;
    		prevhead = head;
    	}
    }
    // merge max number created from single vector
    void merge(int* num1, int len1, int* num2, int len2, int* result, int& resSize){
    	int i = 0, j = 0, k = 0;
    	while (i < resSize){
    		if (j < len1 && k < len2){
    			if (num1[j] > num2[k])
    				result[i++] = num1[j++];
    			else if (num1[j] < num2[k])
    				result[i++] = num2[k++];
    			else{
    				int remaining1 = len1 - j, remaining2 = len2 - k, tmp = num1[j];
    				int flag = memcmp(num1 + j, num2 + k, sizeof(int) * MIN(remaining1, remaining2));
    				flag = (flag == 0 ? (remaining1>remaining2 ? 1 : -1) : flag);
    				int * num = flag > 0 ? num1 : num2;
    				int & cnt = flag > 0 ? j : k;
    				int len = flag > 0 ? len1 : len2;
    				while (num[cnt]==tmp && cnt < len && i<resSize) result[i++] = num[cnt++];
    			}
    		}
    		else if (j < len1) result[i++] = num1[j++];
    		else result[i++] = num2[k++];
    	}
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
    	int m = nums1.size(), n = nums2.size(), step = k*soi;
    	int minL1 = MAX(0, k-n), maxL1 = MIN(k, m), minL2 = k-maxL1, maxL2 = k-minL1, range = maxL1-minL1+1;
    	int *res = new int[range*k*2 + 2*k], *dp1 = res+k, *dp2 = res+range*k+k, *tmp=res+range*2*k+k;
    	memset(res, 0, step);
    	int sortedm = 1, sortedn = 1;
    	if (!m) getMax(&nums2[0], n, res, k, sortedn);
    	else if (!n) getMax(&nums1[0], m, res, k, sortedn);
    	else {
    		dp(&nums1[0], m, sortedm, minL1, maxL1, dp1, k);
    		dp(&nums2[0], n, sortedn, minL2, maxL2, dp2, k);
    		if (sortedm+sortedn >= k){
    			merge(dp1 + k*(maxL1 - sortedm), sortedm, dp2 + k*(maxL2 - sortedn), sortedn, tmp, k);
    			vector<int> resv(tmp, tmp + k);
    			delete[] res;
    			return resv;
    		}
    		for (int i = minL1; i <= maxL1; ++i){
    			merge(dp1+k*(maxL1-i), i, dp2+k*(maxL2-k+i), (k-i), tmp, k);
    			if (memcmp(res, tmp, step) < 0) memcpy(res, tmp, step);
    		}
    	}
    	vector<int> resv(res, res + k);
    	delete[] res;
    	return resv;
    }
};
