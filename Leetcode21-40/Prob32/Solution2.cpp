class Solution {
public: 
    int longestValidParentheses(string s) {
    	int res = 0;
    	stack<int> stackPar;
    	for (int i = 0; i < s.size(); i++) {
        	// if is a match
        	if (s[i] == ')' && !stackPar.empty() && s[stackPar.top()] == '(') {
            		stackPar.pop();
            		if (stackPar.empty())
                		res = i + 1;
            		else
                		res = max(res, i - stackPar.top());
        	} else {
            		stackPar.push(i);
        	}
    	}
    	return res;
    }
};
