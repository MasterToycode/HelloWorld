#include"Phone.h"
void ReadStringFromConsole(char* buffer, int bufferSize) {
    char c;
    int i = 0;
    while (i < bufferSize) {
        scanf_s("%c",&c);
        // 如果遇到换行符或回车符，停止读取
        if (c == '\n') 
        {
            break;
        }
        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0'; // 手动添加终止符
}

int main() {
    PhoneBook contacts[3];

    for (int i = 0; i < 3; i++) {
        char name[100] ;
        char phoneNum[100];
        char address[100];

        cout << "请输入通讯人员 " << (i + 1) << " 的信息：" << endl;

        cout << "姓名: ";
        ReadStringFromConsole(name, sizeof(name));
        
        cout << endl;
        cout << "电话号码: ";
        ReadStringFromConsole(phoneNum, sizeof(phoneNum));
        cout << endl;
        cout << "地址: ";
        ReadStringFromConsole(address, sizeof(address));
        cout << endl;
        contacts[i] = PhoneBook(name, phoneNum, address);
    }

    for (int i = 0; i < 3; i++) 
    {
        cout << "通讯人员 " << (i + 1) << " 的信息：" << endl;
        contacts[i].Display();
        cout << endl;
    }

    return 0;
}
