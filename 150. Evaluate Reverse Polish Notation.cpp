class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Stack to store operands during evaluation
        stack<int> operandStack;
      
        // Process each token in the RPN expression
        for (const auto& token : tokens) {
            // Check if token is a number (multi-digit or positive single digit)
            if (token.size() > 1 || isdigit(token[0])) {
                // Push the number onto the stack
                operandStack.push(stoi(token));
            } else {
                // Token is an operator, pop two operands from stack
                // Note: Order matters - second operand is popped first
                int secondOperand = operandStack.top();
                operandStack.pop();
                int firstOperand = operandStack.top();
                operandStack.pop();
              
                // Perform the operation based on the operator
                if (token[0] == '+') {
                    operandStack.push(firstOperand + secondOperand);
                } else if (token[0] == '-') {
                    operandStack.push(firstOperand - secondOperand);
                } else if (token[0] == '*') {
                    operandStack.push(firstOperand * secondOperand);
                } else {  // Division operator '/'
                    operandStack.push(firstOperand / secondOperand);
                }
            }
        }
      
        // The final result is the only element left in the stack
        return operandStack.top();
    }
};
