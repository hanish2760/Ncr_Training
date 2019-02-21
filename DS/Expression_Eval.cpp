
#include <iostream>
#include<string>
#include<stack>
using namespace std;
class Expression_Eval {


	string infixExpression;
	string postfixExpression;
	int len;
public:
	Expression_Eval() {
		len = 0;

	}
	friend istream& operator >> (istream& cin, Expression_Eval& e);
	bool isBalanced() {
		stack<char> stck;
		int flag=-1;	
		for (int i = 0; i<len; i++) {
			char c = infixExpression[i];
			flag = 0;
			switch (c) {

			case '(':
			case '[':
			case '{':
				stck.push(c);
				break;
			case ')':
			case ']':
			case '}':
				if (stck.empty()) {
					flag = 1;
				}
				else {
					if (stck.top() == '(' && c == ')')stck.pop();
					else if (stck.top() == '[' && c == ']')stck.pop();
					else if (stck.top() == '{'&& c == '}')stck.pop();
					else flag = 1;
				}
				break;

			default:break;

			}
			if (flag == 1)break;
		}

		if (flag == 1)return false;
		if (!stck.empty())return false;
		if (flag == 0)return true;
	}
	bool isOp(char op) {
		switch (op) {

		case '+':
		case '-':
		case '/':
		case'*':
			return true;
			break;
		default: return false;
			break;
		}
		return false;
	}
	bool ispara(char op) {
		switch (op) {

		case '{':
		case '(':
		case '[':
		case '}':
		case ')':
		case ']':
			return true;
			break;
		default: return false;	
			break;
		}
		return false;
	}
	int getprecedence(char op) {
		switch (op) {
		
		case '[':
			return -3; 
		case '{':
			return -2;
		case '(':
			return -1;
		
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			break;
		}
		return -999;
	}
	bool isoperand(char op) {
		if (op <= '9'&&op >= '0')return true;
		return false;
	}
	/*
	
	5+5*6-7
	s -,55*+
	*/
	bool infixToPostfix() {

		stack<char> stck;
		char op=' ';
		for (int i = 0; i < len; i++) {
			op = infixExpression[i];
			if (op >= '0' && op <= '9') {
				postfixExpression.append(1, op);

			}
			else if(isOp(op)) {
				if (i + 1 == len)return false;
				if (i == 0)return false;
				if (!(isoperand(infixExpression[i - 1]) && isoperand(infixExpression[i + 1])))return false;
				if (stck.empty()) {
					stck.push(op);
				}
				else  {
					while (1) {
						if (stck.empty()) {
							stck.push(op);
							break;
						}
						if (getprecedence(op) > getprecedence(stck.top())) {
							stck.push(op);
							break;
						}
						char ch = stck.top();
						stck.pop();
						postfixExpression.append(1, ch);
						
					}
				}
			}
			else if (ispara(op)) {
				if (op == '( ' || op == '{' || op == '[')stck.push(op);
				else {
					while (1) {

						if (stck.empty()) {

							break;
						}
						if (ispara(op)) {
							stck.pop();
							break;
						}
						postfixExpression.append(1,stck.top());
						stck.pop();


					}

				}
			}
			else {
				return false;
			}





		}
		while (!stck.empty()) {
			postfixExpression.append(1, stck.top());
			stck.pop();
		}
		return true;
		
	}

	int eval() {
		if (isBalanced()) {
			if (infixToPostfix()) {


			}
			else {
				cout << "\n Invalid Expression\n";
			}
		}
		else {
			
		}
		return -1;
	}
	void dispaly() {
		cout << "\n" << infixExpression<<endl;
		cout << postfixExpression << endl;
	}
};

istream& operator >> (istream& cin, Expression_Eval& e) {
	cin >> e.infixExpression;
	e.len = e.infixExpression.length();
	e.postfixExpression = "";
	return cin;
}
int main()
{
	Expression_Eval e;
	
	while (1) {
		cin >> e;
		int res = e.eval();
		e.dispaly();
	}

	getchar();
	return 0;
}
