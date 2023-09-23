#include"head.h"

vector<City> initCities() {
    vector<City> cities;
    cities.push_back(City(0,0));
    cities.push_back(City(1,2));
    cities.push_back(City(2,18));
    cities.push_back(City(4,3));
    cities.push_back(City(5,12));
    cities.push_back(City(6,8));
    cities.push_back(City(8,4));
    cities.push_back(City(7,9));
    cities.push_back(City(10,10));
    cities.push_back(City(8,11));
    return cities;
}

vector<vector<double>> initPheromones() {
    vector<vector<double>> pheromones(numCities, vector<double>(numCities, 1.0)); // 初始化为1.0
    return pheromones;
}


double distance(const City& city1, const City& city2) {
    int dx = city1.x - city2.x;
    int dy = city1.y - city2.y;
    return sqrt(dx * dx + dy * dy);
}




double calculateTourLength(const vector<int>& tour, const vector<City>& cities) {
    double length = 0.0;
    for (int i = 0; i < tour.size() - 1; ++i) {
        int city1 = tour[i];
        int city2 = tour[i + 1];
        length += distance(cities[city1], cities[city2]);
    }
    // 回到起点城市
    int firstCity = tour[0];
    int lastCity = tour[tour.size() - 1];
    length += distance(cities[lastCity], cities[firstCity]);
    return length;
}



void updatePheromones(vector<vector<double>>& pheromones, const vector<Ant>& ants) {
    const double rho = 0.1; // 信息素挥发率

    // 信息素挥发，降低所有路径上的信息素浓度
    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            pheromones[i][j] *= (1.0 - rho);
        }
    }

    // 蚂蚁路径上的信息素增加
    for (const Ant& ant : ants) {
        double antDeltaPheromone = 1.0 / ant.tourLength; // 每只蚂蚁在路径上留下的信息素
        for (int i = 0; i < numCities - 1; ++i) {
            int city1 = ant.tour[i];
            int city2 = ant.tour[i + 1];
            pheromones[city1][city2] += antDeltaPheromone;
            pheromones[city2][city1] += antDeltaPheromone; // 信息素矩阵是对称的
        }
    }
}



// 蚁群算法实现函数
ALLBest antColonyOptimization(const vector<City>& cities, vector<vector<double>>& pheromones)
{
    ALLBest best2{};
    best2.bestTourLength = numeric_limits<double>::max(); // 初始化为一个较大的值
    best2.bestTour = {}; // 初始化为空路径
    const int maxIterations = 1000;
    vector<Ant> ants(numAnts); // 
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        // 蚂蚁移动的逻辑
        for (int i = 0; i < numAnts; ++i) { // 对于每只蚂蚁
            while (ants[i].tour.size() < numCities) { // 当蚂蚁访问城市数量不足时
                int currentCity = ants[i].tour.back(); // 当前城市为已访问过的最后一个城市
                int nextCity = -1; // 下一个城市的索引，初始化为-1

                // 计算下一个城市的选择概率
                double totalProbability = 0.0; // 总概率初始化为0
                vector<double> probabilities(numCities, 0.0); // 初始化每个城市的概率为0

                for (int candidateCity = 0; candidateCity < numCities; ++candidateCity) { // 对于每个未访问的城市
                    if (!ants[i].visited[candidateCity]) { // 如果该城市未被访问过
                        double pheromone = pheromones[currentCity][candidateCity]; // 获取当前城市到该城市的信息素浓度
                        double distanceToCity = distance(cities[currentCity], cities[candidateCity]); // 获取当前城市到该城市的距离
                        double probability = pow(pheromone, alpha) * pow(1.0 / distanceToCity, beta); // 计算选择该城市的概率
                        probabilities[candidateCity] = probability; // 将该城市的概率保存到概率向量中
                        totalProbability += probability; // 更新总概率
                    }
                }

                // 使用轮盘赌法选择下一个城市
                double randomValue = (rand() / (RAND_MAX + 1.0)) * totalProbability; // 生成0~1之间的随机数
                double cumulativeProbability = 0.0; // 累计概率初始化为0

                for (int candidateCity = 0; candidateCity < numCities; ++candidateCity) { // 对于每个未访问的城市
                    if (!ants[i].visited[candidateCity]) { // 如果该城市未被访问过
                        cumulativeProbability += probabilities[candidateCity]; // 累加概率
                        if (cumulativeProbability >= randomValue) { // 如果累计概率大于等于随机数
                            nextCity = candidateCity; // 选择该城市为下一个城市
                            break;
                        }
                    }
                }
                // 将下一个城市添加到路径中
                ants[i].tour.push_back(nextCity); // 将下一个城市的索引添加到路径中
                ants[i].visited[nextCity] = true; // 标记该城市为已访问

            }
        }
        // 计算蚂蚁们的路径长度
        for (int i = 0; i < numAnts; ++i) {
            ants[i].tourLength = calculateTourLength(ants[i].tour, cities); // 计算蚂蚁i的路径长度
        }
        for (int i = 0; i < numAnts; ++i) {
            if (ants[i].tourLength < best2.bestTourLength) { // 如果蚂蚁i的路径比当前最优路径更短
                best2.bestTourLength = ants[i].tourLength; // 更新最优路径长度
                best2.bestTour = ants[i].tour; // 更新最优路径
            }
        }
        // 更新信息素
        updatePheromones(pheromones, ants); // 更新信息素浓度

    }
    cout << "Best tour length: " << best2.bestTourLength << endl; // 输出最优路径长度
    cout << "Best tour: ";
    for (auto city : best2.bestTour) 
    { // 输出最优路径
        cout << city << " ";
    }
    cout << endl;
    return best2;
}

