
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (char c : s) {
        if (isalnum(c)) result += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && st.top() != '(' &&
                  (precedence(st.top()) > precedence(c) ||
                  (precedence(st.top()) == precedence(c) && c != '^'))) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

string infixToPrefix(string s) {
    reverse(s.begin(), s.end());

    for (char& c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string result = infixToPostfix(s);
    reverse(result.begin(), result.end());
    return result;
}

double calculate(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    }
    return 0;
}

double getValue(char c) {
    if (isdigit(c)) return c - '0';
    double value;
    cout << "Enter value of " << c << ": ";
    cin >> value;
    return value;
}

double evaluatePostfix(string s) {
    stack<double> st;

    for (char c : s) {
        if (isalnum(c) && !isdigit(c)) st.push(getValue(c));
        else if (isdigit(c)) st.push(c - '0');
        else {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            st.push(calculate(a, b, c));
        }
    }

    return st.top();
}

double evaluatePrefix(string s) {
    stack<double> st;

    for (int i = static_cast<int>(s.size()) - 1; i >= 0; i--) {
        char c = s[i];

        if (isalnum(c) && !isdigit(c)) st.push(getValue(c));
        else if (isdigit(c)) st.push(c - '0');
        else {
            double a = st.top(); st.pop();
            double b = st.top(); st.pop();
            st.push(calculate(a, b, c));
        }
    }

    return st.top();
}

int main() {
    int choice;
    string expression;

    do {
        cout << "\n1.Infix to Postfix\n2.Infix to Prefix\n";
        cout << "3.Evaluate Postfix\n4.Evaluate Prefix\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter expression (no spaces): ";
            cin >> expression;

            switch (choice) {
            case 1:
                cout << "Postfix: " << infixToPostfix(expression) << endl;
                break;
            case 2:
                cout << "Prefix: " << infixToPrefix(expression) << endl;
                break;
            case 3:
                cout << "Result: " << evaluatePostfix(expression) << endl;
                break;
            case 4:
                cout << "Result: " << evaluatePrefix(expression) << endl;
                break;
            }
        }
    } while (choice != 5);

    return 0;
}
