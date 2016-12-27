class Solution {
public:
    bool isValid(string s) {
        bool result=true;
        stack<char> parentStack;
        for(int i=0;i<s.size();i++){
            switch(s[i]){
            
                case '(':   parentStack.push('(');
                            break;
                            
                case '{':   parentStack.push('{');
                            break;
                            
                case '[':   parentStack.push('[');
                            break;
                            
                case ')':   if(parentStack.size()==0 || parentStack.top() !='(')  
                                return false;
                            parentStack.pop();    
                            break;
                
                case '}':   if(parentStack.size()==0 || parentStack.top() !='{')  
                                return false;
                            parentStack.pop(); 
                            break;
                            
                case ']':   if(parentStack.size()==0 || parentStack.top() !='[')  
                                return false;
                            parentStack.pop();  
                            break;
                default:    break;     
                        
            }
        }
        if(parentStack.size()!=0) return false;
        return result;
    }
};