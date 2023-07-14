#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int price; // 物品的价值
    int weight; // 物品的重量
    double valuePerWeight; // 物品的单位重量价值
};

// 自定义比较函数，按单位重量价值递减排序
bool compare(Item& a, Item& b) {
    return a.valuePerWeight > b.valuePerWeight;
}

// 分数背包问题函数
int FractionalKnapsack(vector<Item>& items, int capacity) {
    int totalValue = 0;
    sort(items.begin(), items.end(), compare); // 按单位重量价值递减排序

    for (int i = 0; i < items.size(); i++) {
        if (capacity == 0) // 如果背包容量已经为0，跳出循环
            break;

        if (items[i].weight <= capacity) { // 如果该物品可以全部放入背包
            totalValue += items[i].price; // 更新总价值
            capacity -= items[i].weight; // 更新背包容量
        }
        else { // 如果该物品只能部分放入背包
            totalValue += (items[i].price * capacity) / items[i].weight; // 更新总价值
            break; // 跳出循环
        }
    }

    return totalValue; // 返回总价值
}

int main() {
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };
    int capacity = 50;

    for (auto& item : items) {
        item.valuePerWeight = (double)item.price / item.weight;
    }

    int maxPrice = FractionalKnapsack(items, capacity);

    cout << "背包中物品的最大总价格为：" << maxPrice << endl;

    return 0;
}
