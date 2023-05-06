#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

// 初始时n个点的坐标, 代表n种草的坐标, 注意是n个点草的品种不一样, 
// 每天每种品种的草每株都会围绕周围8个坐标生长一圈, 
// 求多少天过后能够至少找到坐标系中一点至少有m种草生长, 注意这里是有一点有至少m个品种的草
struct Coordinate {
    int x;
    int y;
};

bool operator==(const Coordinate& a, const Coordinate& b) {
    return a.x == b.x && a.y == b.y;
}

struct CoordinateHash {
    std::size_t operator()(const Coordinate& coord) const {
        return std::hash<int>()(coord.x) ^ std::hash<int>()(coord.y);
    }
};

std::vector<Coordinate> generateNeighbors(const Coordinate& coord) {
    std::vector<Coordinate> neighbors;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0)) {
                neighbors.push_back({coord.x + i, coord.y + j});
            }
        }
    }
    return neighbors;
}

int calculateDays(std::vector<Coordinate>& seeds, int m, int n) {
    std::unordered_map<Coordinate, std::set<int>, CoordinateHash> grid;
    int days = 0;

    for (int i = 0; i < n; i++) {
        grid[seeds[i]].insert(i);
    }

    while (days < n * n) {
        std::unordered_map<Coordinate, std::set<int>, CoordinateHash> nextGrid(grid);

        // 对于每个种子位置，将周围的八个方向都种上相应的草
        for (const auto& item : grid) {
            for (const auto& species : item.second) {
                std::vector<Coordinate> neighbors = generateNeighbors(item.first);
                for (const auto& neighbor : neighbors) {
                    nextGrid[neighbor].insert(species);
                    if (nextGrid[neighbor].size() >= m) {
                        return days + 1;
                    }
                }
            }
        }

        days++;
        grid = nextGrid;
    }

    return -1;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Coordinate> seeds(n);
    for (int i = 0; i < n; i++) {
        std::cin >> seeds[i].x >> seeds[i].y;
    }

    int days = calculateDays(seeds, m, n);
    if (days == -1) {
        std::cout << "在 " << n * n << " 天内没有出现 " << m << " 种草" << std::endl;
    } else {
        std::cout << "在第 " << days << " 天出现了 " << m << " 种草" << std::endl;
    }

    return 0;
}
