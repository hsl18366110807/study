执行用时 :20 ms, 在所有 C++ 提交中击败了77.23%的用户
内存消耗 :11.6 MB, 在所有 C++ 提交中击败了15.70%的用户
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
          if (tokens[i] != "+" && tokens[i] != "/" && tokens[i] != "-" && tokens[i] != "*") s.push(atoi(tokens[i].c_str()));
		else if (tokens[i] ==  "+") {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int c = b + a;
			s.push(c);
		}
		else if (tokens[i] == "-") {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int c = b - a;
			s.push(c);
		}
		else if (tokens[i] ==  "*") {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int c = b * a;
			s.push(c);
		}
		else if (tokens[i] == "/") {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int c = b / a;
			s.push(c);
		}
		}
        return s.top();
        }
    
};