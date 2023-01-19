#include <iostream>
#include <queue>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    priority_queue<int, vector<int>, greater<int>> pqueue;
    int minimum, maximum;
    double average = 0;

    string command;
    while (cin >> command) {
        if (command == "number") {
            int number;
            cin >> number;
            pqueue.push(number);

            int size = pqueue.size();
            if (size == 1) {
                maximum = number;
                average = number;
            }
            else {
                if (number > maximum) maximum = number;
                average = (average*(size-1) + number)/double(size);
            }
        }
        else if (not pqueue.empty()) {
            int number = pqueue.top();
            pqueue.pop();

            int size = pqueue.size();
            if (not pqueue.empty()) average = (average*(size+1) - number)/double(size);
        }

        if (pqueue.empty()) {
            average = 0;
            cout << "no elements" << endl;
        }
        else {
            minimum = pqueue.top();
            cout << "minimum: " << minimum << ", maximum: " << maximum << ", average: " << average << endl;
        }
    }
}