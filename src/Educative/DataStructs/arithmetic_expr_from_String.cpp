#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

float StrToNumber(string &str, int idx1, int idx2) {
	return stof(string(str, idx1, idx2-idx1));
}

stack<float> ReverseStack(stack<float> &stack1) {
	stack <float> stack2;
	while(!stack1.empty()) {
		stack2.push(stack1.top());
		stack1.pop();
	}
	return stack2;
}

stack<char> ReverseStack(stack<char> &stack1) {
	stack <char> stack2;
	while(!stack1.empty()) {
		stack2.push(stack1.top());
		stack1.pop();
	}
	return stack2;
}

void GenerateStacks(string expr, stack<char> &ops_stack, stack<float> &nos_stack) {
	int index = 0;
	for(int i=0; i < expr.size(); i++) {
		if(expr[i] == '/' || expr[i] == '*' || expr[i] == '-' || expr[i] == '+') {
			ops_stack.push(expr[i]);
			nos_stack.push(StrToNumber(expr, index, i));
			index = i+1;
		}
	}
	nos_stack.push(StrToNumber(expr, index, expr.size()));
}

void OperationsOnStack(char op, stack<float> &nos_stack) {
	float temp = nos_stack.top();
	nos_stack.pop();

	switch(op) {
		case '/':
			temp /= nos_stack.top();
			break;
		case '*':
			temp *= nos_stack.top();
			break;
		case '-':
			temp -= nos_stack.top();
			break;
		case '+':
			temp += nos_stack.top();
			break;
		default:
			cout << "Invalid operation!" << endl;
	}
	nos_stack.pop();
    nos_stack.push(temp);
}

void PrintStack(stack<float> nos_stack) {
    while(!nos_stack.empty()) {
        float temp = nos_stack.top();
        cout << temp << " ";
        nos_stack.pop();
    }
    cout << endl;
}

void PrintStack(stack<char> nos_stack) {
    while(!nos_stack.empty()) {
        char temp = nos_stack.top();
        cout << temp << " ";
        nos_stack.pop();
    }
    cout << endl;
}

// Transfer second stack into first stack
void TransferStack(stack<float> &stack1, stack<float> &stack2) {
    while(!stack2.empty()) {
        float f = stack2.top();
        stack1.push(f);
        stack2.pop();
    }
}

// Transfer second stack into first stack
void TransferStack(stack<char> &stack1, stack<char> &stack2) {
    while(!stack2.empty()) {
        char f = stack2.top();
        stack1.push(f);
        stack2.pop();
    }
}

void ConditionalTransfer(char op, stack<float> &nos_stack1, stack<float> &nos_stack2, stack<char> &ops_stack1, stack<char> &ops_stack2) {
    while(!ops_stack1.empty()) {
        if(ops_stack1.top() != op) {
            char c = ops_stack1.top();
            ops_stack2.push(c);
            ops_stack1.pop();

            float f = nos_stack1.top();
            nos_stack2.push(f);
            nos_stack1.pop();
        } 
        else
            break;
    }
}

double Evaluate(string expr){
	stack<float> nos_stack1;
	stack<float> nos_stack2;
	stack<char> ops_stack1;
	stack<char> ops_stack2;
	stack<char> desired_ops;

	desired_ops.push('+');
	desired_ops.push('-');
	desired_ops.push('*');
	desired_ops.push('/');

	GenerateStacks(expr, ops_stack1, nos_stack1);
    ops_stack1 = ReverseStack(ops_stack1);
    nos_stack1 = ReverseStack(nos_stack1);

	while(!ops_stack1.empty()) {
		// Empty stacks 1 into stacks2 until desired operation is found or stacks 1 is empty
		if(ops_stack1.top() != desired_ops.top())
            ConditionalTransfer(desired_ops.top(), nos_stack1, nos_stack2, ops_stack1, ops_stack2);

		if(ops_stack1.empty()) {

			// Transfer back into stacks 1
            TransferStack(ops_stack1, ops_stack2);
            TransferStack(nos_stack1, nos_stack2);
			// Pop the desired operation as it couldnt be found in the operations stack
			desired_ops.pop();
		}

		if(ops_stack1.top() == desired_ops.top()){
			// Performing the arithmetic
			OperationsOnStack(ops_stack1.top(), nos_stack1);
			ops_stack1.pop();

			// Transfer back into stacks 1
			TransferStack(ops_stack1, ops_stack2);
            TransferStack(nos_stack1, nos_stack2);

		}
        PrintStack(ops_stack1);
        PrintStack(nos_stack1);
    }
    
	return nos_stack1.top();

}

int main(int argc, char const *argv[])
{
    double result = Evaluate("400-100+200*10-4/2");
    return 0;
}
