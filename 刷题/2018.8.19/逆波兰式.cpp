ִ����ʱ :20 ms, ������ C++ �ύ�л�����77.23%���û�
�ڴ����� :11.6 MB, ������ C++ �ύ�л�����15.70%���û�
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