#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int price;
    int weight;
    double valuePerWeight;
};

bool compare(Item& a, Item& b) {
    return a.valuePerWeight > b.valuePerWeight; // ����λ������ֵ�ݼ�����
}

int FractionalKnapsack(vector<Item>& items, int capacity) {
    int totalValue = 0;
    sort(items.begin(), items.end(), compare); // ����λ������ֵ�ݼ�����

    for (int i = 0; i < items.size(); i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            totalValue += items[i].price;
            capacity -= items[i].weight;
        }
        else {
            totalValue += (items[i].price * capacity) / items[i].weight;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };
    int capacity = 50;

    for (auto& item : items) {
        item.valuePerWeight = (double)item.price / item.weight;
    }

    int maxPrice = FractionalKnapsack(items, capacity);

    cout << "��������Ʒ������ܼ۸�Ϊ��" << maxPrice << endl;

    return 0;
}
