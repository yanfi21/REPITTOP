#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(m));

    for (auto& row : matrix) 
        for (double& elem : row) std::cin >> elem;

    double maxOfMins = std::numeric_limits<double>::lowest();
    for (const auto& row : matrix) {
        double minInRow = *std::min_element(row.begin(), row.end());
        maxOfMins = std::max(maxOfMins, minInRow);
    }

    std::cout << "Максимум среди минимумов: " << maxOfMins << std::endl;
    return 0;
}
