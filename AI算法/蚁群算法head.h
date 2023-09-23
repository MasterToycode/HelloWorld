/*
��Ϣ�ػӷ��ʣ�

��Ϣ�ػӷ��ʿ�������Ϣ����ÿ�ε����еĽ��ͳ̶ȡ�
ͨ������С�Ļӷ��ʣ���0.1�����������㷨��̽���ԣ��������ϸ���س����µ�·�����ϴ�Ļӷ��ʣ���0.5����ߣ����ܻ�ӿ���Ϣ�صĸ����ٶȣ�����̽������������������֪����Ϣ��

����㷢����Ⱥ�㷨�����������ֲ����Ž⣬���Կ��ǽ��ͻӷ��ʣ��������㷨��̽���ԡ�
����㷨����̽���Զ��޷��ں���ʱ���������������ʶ���߻ӷ��ʣ��Լ�����Ϣ�ص���ɢ��

һ�ֳ��������������㷨�ĳ�ʼ�׶�ʹ�ýϸߵĻӷ��ʣ�Ȼ���ں����׶��𽥽���������ƽ��̽�������á�


����ʽ���ӣ�

����ʽ���ӣ�alpha��beta��������������ѡ����һ������ʱ����Ϣ�غ�����ʽ��Ϣ�����ӳ̶ȡ�
ͨ����alpha�������Ϣ�ص����ӣ�beta���������ʽ��Ϣ����������ۣ������ӡ�

����ʽ���ӵĺ���ֵȡ������������ʡ�����������������Ϣ�ص�ָ�������Կ�������alpha��
������������������ʽ��Ϣ�����Կ�������beta��

ͨ����������һ����Χ�ڳ��Բ�ͬ��alpha��betaֵ����ȷ����Щֵ���ض������ϱ�����á�
���͵ķ�Χ������0��2֮���ֵ��

���գ���Ⱥ�㷨��һ������ʽ�㷨��ͨ����Ҫ���ж��ʵ��Ͳ���������
���ҵ����ض������ϱ�����õĲ�����ϡ���Ҫ����Ҫ������������ʺ�ʵ��Ӧ����ѡ�����ֵ��
�������Ż��㷨�Ի����ѽ����
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include<random>
using namespace std;
// ���нṹ�壬��¼���е�����
struct City {
    int x, y;
    City(int x, int y) : x(x), y(y) {}
};

struct ALLBest {
    vector<int> bestTour; // ��ʼ������·��
    double bestTourLength ; // ��ʼ������·������Ϊ���ֵ
};


const int numCities = 10; // ��������
const int numAnts = 1000; // ��������
const double evaporationRate = 0.1; // ��Ϣ�ػӷ���
const double alpha = 1.0; // ��Ϣ����Ҫ�̶Ȳ���
const double beta = 2.0; // ����ʽ������Ҫ�̶Ȳ���

// ������
class Ant {
public:
    vector<int> tour; // ��¼�����߹��ĳ��б������
    bool visited[numCities]; // ��¼�����Ƿ񱻷��ʹ�
    double tourLength; // ��¼�����߹���·������

    Ant() {
        for (int i = 0; i < numCities; ++i) {
            visited[i] = false;
        }
        int startCity = rand() % numCities; // ���ѡ��һ��������
        tour.push_back(startCity); // �������м���·��
        visited[startCity] = true; // ��ǳ���Ϊ�ѷ���
        tourLength = 0.0;
    }
};

vector<City> initCities();
vector<vector<double>> initPheromones();
double distance(const City& city1, const City& city2);
double calculateTourLength(const vector<int>& tour, const vector<City>& cities);
void updatePheromones(vector<vector<double>>& pheromones, const vector<Ant>& ants);
ALLBest antColonyOptimization(const vector<City>& cities, vector<vector<double>>& pheromones);
