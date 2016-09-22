class Solution {
public:
  vector<int> diffWaysToCompute(string input) {
    vector<int> nums;
    vector<char> ops;
    int i = 0;
    while (true) {
      int num = 0;
      while (i < input.size() && isdigit(input[i]))
        num = num * 10 + input[i++] - '0';
      nums.push_back(num);
      if (i < input.size())
        ops.push_back(input[i++]);
      else break;
    }
    int n = nums.size();
    vector<vector<vector<int>>> res(n, vector<vector<int>>(n));
    for (i = 0; i < n; i++)
      res[i][i].push_back(nums[i]);
    for (i = n-2; i >= 0; i--)  // for (int j = 1; j < n; j++)
      for (int j = i+1; j < n; j++) // for (i = j-1; i >= 0; i--)
        for (int k = i; k < j; k++)
          for (int left: res[i][k])
            for (int right: res[k+1][j])
              res[i][j].push_back(operate(ops[k], left, right));
    return res[0][n-1];
  }
private:
  int operate(char op, int l, int r) {
    switch (op) {
      case '+': return l + r;
      case '-': return l - r;
      default: return l * r;
    }
  }
};

// recursive solution from discussion
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        map<string, vector<int>> cache;
        return diffWaysToCompute(input, 0, input.size()-1, cache);
    }
private:
    vector<int> diffWaysToCompute(string& input, int start, int end, map<string, vector<int>>& cache) {
        string key=to_string(start)+to_string(end);
        if(cache.count(key)) return cache[key];
        vector<int> result;
        int num=0;
	    for(int i=start; i<=end; ++i) {
	        if(input[i]!='+' && input[i]!='-' && input[i]!='*')
	            num=num*10+(input[i]-'0');
		    else{
    		    vector<int> left=diffWaysToCompute(input, start, i-1, cache);
    		    vector<int> right=diffWaysToCompute(input, i+1, end, cache);
    		    for(auto l:left){
    		        for(auto r: right){
    		            if(input[i]=='+')
    		                result.push_back(l+r);
    		            else if(input[i]=='-')
    		                result.push_back(l-r);
    		            else if(input[i]=='*')
    		                result.push_back(l*r);
    		        }
    		    }
		    }
        }
        if(result.size()==0) result.push_back(num); //only single number
        return cache[key]=result;
    }
};

vector<int> diffWaysToCompute(string input) {
    vector<int> output;
    for (int i=0; i<input.size(); i++) {
        char c = input[i];
        if (ispunct(c))
            for (int a : diffWaysToCompute(input.substr(0, i)))
                for (int b : diffWaysToCompute(input.substr(i+1)))
                    output.push_back(c=='+' ? a+b : c=='-' ? a-b : a*b);
    }
    return output.size() ? output : vector<int>{stoi(input)};
}
