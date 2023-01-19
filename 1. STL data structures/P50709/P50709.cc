#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pqueue;
    char c;
    while (cin >> c) {
        if (c == 'S') {
            int number;
            cin >> number;
            pqueue.push(number);
        }
        else if (pqueue.empty()) {
            cout << "error!" << endl;
            if (c == 'D' or c == 'I') {
                int num;
                cin >> num;
            }
        }
        else if (c == 'A') cout << pqueue.top() << endl;
        else if (c == 'R') pqueue.pop();
        else if (c == 'I') {
            int increment;
            cin >> increment;
            int value = pqueue.top();
            pqueue.pop();
            pqueue.push(value + increment);
        }
        else {
            int decrement;
            cin >> decrement;
            int value = pqueue.top();
            pqueue.pop();
            pqueue.push(value - decrement);
        }
    }
}