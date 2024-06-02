#include <iostream>
#include <vector>
#include <optional>
using namespace std;

optional<vector<int>> howSum(int targetSum, const vector<int>& numbers) {
    if (targetSum == 0) return vector<int>{};
    if (targetSum < 0) return nullopt;

    for (int num : numbers) {
        int remainder = targetSum - num;
        auto remainderResult = howSum(remainder, numbers);
        if (remainderResult.has_value()) {
            remainderResult->push_back(num);
            return remainderResult;
        }
    }
    return nullopt;
}

int main() {
    int targetSum = 7;
    vector<int> numbers = {5,4,3,7};
    auto result = howSum(targetSum, numbers);
    if (result.has_value()) {
        cout << "Combination found: ";
        for (int num : result.value()) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No combination found" << endl;
    }

    return 0;
}
