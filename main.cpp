#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElements(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result array with -1
    stack<int> s; // Stack to store indices of elements
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i]; // Update the result for elements with smaller value
            s.pop();
        }
        s.push(i); // Push the current index onto the stack
    }
    
    return result;
}

int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;
    
    vector<int> arr(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    vector<int> result = nextGreaterElements(arr);
    
    cout << "Next greater elements: ";
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}
