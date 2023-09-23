#include"head.h"
int main() {
    srand(time(nullptr));
    vector<City> cities = initCities();
    int numIterations = 10; // �趨��Ҫ���ٴζ���ģ��
    ALLBest best1 = {};
    best1.bestTourLength = numeric_limits<double>::max(); // ��ʼ��Ϊһ���ϴ��ֵ
    best1.bestTour = {}; // ��ʼ��Ϊ��·��
    best1.bestTourLength = INFINITY;
    for (int iteration = 0; iteration < numIterations; ++iteration)
    {
        vector<vector<double>> pheromones = initPheromones();
        vector<Ant> ants(numAnts);
        ALLBest currentBest = antColonyOptimization(cities, pheromones);

        // �Ƚϲ�������ѽ��
        if (currentBest.bestTourLength < best1.bestTourLength) {
            best1.bestTourLength = currentBest.bestTourLength;
            best1.bestTour = currentBest.bestTour;
        }

        for (int i = 0; i < numAnts; ++i) {
            ants[i].tour.clear(); // ������ϵ�·��
            for (int j = 0; j < numCities; ++j) {
                ants[i].visited[j] = false; // ���ó��з���״̬
            }
            ants[i].tourLength = 0.0; // ����·������
        }

    }
    // ����������Ž�
    cout << "Overall Best tour length: " << best1.bestTourLength << endl;
    cout << "Overall Best tour: ";
    for (auto city : best1.bestTour)
    {
        cout << city << " ";
    }
    cout << endl;

}
