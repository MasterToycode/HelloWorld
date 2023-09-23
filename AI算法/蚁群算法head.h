/*
信息素挥发率：

信息素挥发率控制了信息素在每次迭代中的降低程度。
通常，较小的挥发率（如0.1）可以增加算法的探索性，允许蚂蚁更多地尝试新的路径。较大的挥发率（如0.5或更高）可能会加快信息素的更新速度，减少探索，更侧重于利用已知的信息。

如果你发现蚁群算法过于收敛到局部最优解，可以考虑降低挥发率，以增加算法的探索性。
如果算法过于探索性而无法在合理时间内收敛，可以适度提高挥发率，以加速信息素的消散。

一种常见的做法是在算法的初始阶段使用较高的挥发率，然后在后续阶段逐渐降低它，以平衡探索和利用。


启发式因子：

启发式因子（alpha和beta）控制了蚂蚁在选择下一个城市时对信息素和启发式信息的重视程度。
通常，alpha代表对信息素的重视，beta代表对启发式信息（如距离或代价）的重视。

启发式因子的合适值取决于问题的性质。如果问题更依赖于信息素的指导，可以考虑增加alpha。
如果问题更依赖于启发式信息，可以考虑增加beta。

通常，建议在一定范围内尝试不同的alpha和beta值，以确定哪些值在特定问题上表现最好。
典型的范围可以是0到2之间的值。

最终，蚁群算法是一种启发式算法，通常需要进行多次实验和参数调整，
以找到在特定问题上表现最好的参数组合。重要的是要根据问题的性质和实际应用来选择参数值，
并不断优化算法以获得最佳结果。
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include<random>
using namespace std;
// 城市结构体，记录城市的坐标
struct City {
    int x, y;
    City(int x, int y) : x(x), y(y) {}
};

struct ALLBest {
    vector<int> bestTour; // 初始化最优路径
    double bestTourLength ; // 初始化最优路径长度为最大值
};


const int numCities = 10; // 城市数量
const int numAnts = 1000; // 蚂蚁数量
const double evaporationRate = 0.1; // 信息素挥发率
const double alpha = 1.0; // 信息素重要程度参数
const double beta = 2.0; // 启发式因子重要程度参数

// 蚂蚁类
class Ant {
public:
    vector<int> tour; // 记录蚂蚁走过的城市编号序列
    bool visited[numCities]; // 记录城市是否被访问过
    double tourLength; // 记录蚂蚁走过的路径长度

    Ant() {
        for (int i = 0; i < numCities; ++i) {
            visited[i] = false;
        }
        int startCity = rand() % numCities; // 随机选择一个起点城市
        tour.push_back(startCity); // 将起点城市加入路径
        visited[startCity] = true; // 标记城市为已访问
        tourLength = 0.0;
    }
};

vector<City> initCities();
vector<vector<double>> initPheromones();
double distance(const City& city1, const City& city2);
double calculateTourLength(const vector<int>& tour, const vector<City>& cities);
void updatePheromones(vector<vector<double>>& pheromones, const vector<Ant>& ants);
ALLBest antColonyOptimization(const vector<City>& cities, vector<vector<double>>& pheromones);
