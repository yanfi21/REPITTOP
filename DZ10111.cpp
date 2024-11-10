#include <iostream>
#include <vector>
#include <unordered_map>

void findDuplicates(const std::vector<int>& arr) {
    std::unordered_map<int, int> countMap;
    for (int num : arr) countMap[num]++;
    
    std::cout << "Повторяющиеся значения: ";
    for (const auto& pair : countMap) 
        if (pair.second > 1) std::cout << pair.first << " ";
    std::cout << std::endl;
}

int main() {
    findDuplicates({1, 2, 3, 4, 2, 5, 3, 6, 7, 1});
    return 0;
}
