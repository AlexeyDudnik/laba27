#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class FibonacciArray {
private:
    vector<int> arr;
    int size;
public:
    FibonacciArray(const  vector<int>& arr) : arr(arr), size(arr.size()) {
        if (!isValidFibonacci()) {
            throw invalid_argument("Invalid Fibonacci");
        }
    }
    bool isValidFibonacci() const {
        if (size < 3) {
            return false;
        }
        for (int i = 2; i < size; ++i) {
            if (arr[i] != arr[i - 1] + arr[i - 2]) {
                return false;
            }
        }
        return true;
    }
    void printArray() const {
        cout << "Fibonacci true: ";
        for (int i = 0; i < size; ++i) {
             cout << arr[i] << " ";
        }
         cout <<  endl;
    }
};
int main() {
    try {
        vector<int> validFibonacci = { 0, 1, 1, 2, 3, 5, 8 };
        FibonacciArray validArray(validFibonacci);
        validArray.printArray();
        vector<int> invalidFibonacci = { 0, 1, 1, 2, 4, 5, 8 };
        FibonacciArray invalidArray(invalidFibonacci);
        invalidArray.printArray();
    }
    catch (const  invalid_argument& iskl) {
        cout << "Caught exception: " << iskl.what() << endl;
    }
    return 0;
}
