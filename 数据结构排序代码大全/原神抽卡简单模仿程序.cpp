#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));  // 设置随机数种子为当前时间

    int totalEvents;  // 要进行的抽奖次数

    cout << "请输入要进行的抽奖次数: ";
    cin >> totalEvents;

    cout << "抽奖开始！" << endl;

    for (int event = 1; event <= totalEvents; event++) {
        int currentAttempt = 1;  // 当前抽奖次数
        double probability = 0.006; // 当前抽中A或B的概率，初始为0.6%

        cout << "第 " << event << " 次抽奖：" << endl;

        while (currentAttempt <= 90) {
            int randomNumber = rand() % 1000 + 1;  // 生成1到1000之间的随机数

            if (randomNumber <= probability * 1000) {
                if (randomNumber % 2 == 0) {
                    cout << "第 " << currentAttempt << " 次抽奖，恭喜您抽中了物品 A！" << endl;
                }
                else {
                    cout << "第 " << currentAttempt << " 次抽奖，恭喜您抽中了物品 B！" << endl;
                }
                break;
            }
            else {
                cout << "第 " << currentAttempt << " 次抽奖，很遗憾没有抽中任何物品。" << endl;
            }

            if (currentAttempt == 70) {
                // 从第71次开始概率递增6%
                probability = 0.006;
            }
            else if (currentAttempt > 70) {
                // 每次递增6%
                probability += 0.00006;
                if (probability > 0.99) {
                    probability = 0.99;  // 确保概率不超过99%
                }
            }

            currentAttempt++;
        }

        if (currentAttempt > 90) {
            cout << "抽奖次数已达到90次，退出抽奖。" << endl;
            break;
        }
    }

    cout << "抽奖结束！" << endl;

    return 0;
}