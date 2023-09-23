#include"head.h"
int main() {
    srand(time(nullptr));
    vector<City> cities = initCities();
    int numIterations = 10; // 设定需要多少次独立模拟
    ALLBest best1 = {};
    best1.bestTourLength = numeric_limits<double>::max(); // 初始化为一个较大的值
    best1.bestTour = {}; // 初始化为空路径
    best1.bestTourLength = INFINITY;
    for (int iteration = 0; iteration < numIterations; ++iteration)
    {
        vector<vector<double>> pheromones = initPheromones();
        vector<Ant> ants(numAnts);
        ALLBest currentBest = antColonyOptimization(cities, pheromones);

        // 比较并更新最佳结果
        if (currentBest.bestTourLength < best1.bestTourLength) {
            best1.bestTourLength = currentBest.bestTourLength;
            best1.bestTour = currentBest.bestTour;
        }

        for (int i = 0; i < numAnts; ++i) {
            ants[i].tour.clear(); // 清空蚂蚁的路径
            for (int j = 0; j < numCities; ++j) {
                ants[i].visited[j] = false; // 重置城市访问状态
            }
            ants[i].tourLength = 0.0; // 重置路径长度
        }

    }
    // 输出整体最优解
    cout << "Overall Best tour length: " << best1.bestTourLength << endl;
    cout << "Overall Best tour: ";
    for (auto city : best1.bestTour)
    {
        cout << city << " ";
    }
    cout << endl;

}
