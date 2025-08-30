#include <iostream>
#include <cmath>   // for pow (power of numbers like 2^3 = 8)
using namespace std;

// ---------------------------
// Step 1: Create a stack class
// ---------------------------
class Stack {
private:
    int arr[100];   // our stack is just an array that can hold 100 digits
    int top;        // this tells us where the top is

public:
    // constructor (starts with empty stack)
    Stack() {
        top = -1;   // -1 means stack is empty
    }

    // put (push) a number on top of the stack
    void push(int value) {
        if (top < 99) {   // check if stack is not full
            top++;
            arr[top] = value;
        } else {
            cout << "Stack overflow! Too many numbers.\n";
        }
    }

    // take (pop) the number from top of the stack
    int pop() {
        if (top >= 0) {   // check if stack is not empty
            int value = arr[top];
            top--;
            return value;
        } else {
            cout << "Stack underflow! Nothing to pop.\n";
            return -1; // error value
        }
    }

    // check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }
};

// ------------------------------------------
// Step 2: Convert Binary (0s and 1s) to Decimal
// ------------------------------------------
int binaryToDecimal(string binary) {
    Stack s;

    // push each digit into stack
    for (int i = 0; i < binary.length(); i++) {
        int bit = binary[i] - '0';  // convert character '0' or '1' to int 0 or 1
        s.push(bit);
    }

    int decimalValue = 0;
    int weight = 0;  // starts from rightmost digit with weight 0

    // pop from stack and calculate decimal
    while (!s.isEmpty()) {
        int bit = s.pop();
        decimalValue += bit * pow(2, weight);
        weight++;
    }

    return decimalValue;
}

// ---------------------------
// Step 3: Main program
// ---------------------------
int main() {
    string binary;

    cout << "Enter a binary number (like 1010): ";
    cin >> binary;

    int result = binaryToDecimal(binary);

    cout << "The equivalent decimal number is: " << result << endl;

    return 0;
}
