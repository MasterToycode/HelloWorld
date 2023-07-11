#include <iostream>
using namespace std;
//�ṹ�嶨�壺
struct HashNode
{
    int key;  // ��ֵ
    int data;  // ����
};

void linearProbing(int& index, int m)
{
    index = (index + 1) % m;  // ����̽����ɢ��
}

//��ϣ��Ĵ���������
void createHashTable(HashNode* hashTable, int m, int p, int n)
{
    // ��ʼ����ϣ��
    for (int i = 0; i < m; i++)
    {
        hashTable[i].key = -1;  // �����йؼ�����Ϊ-1��ʾ��
        hashTable[i].data = -1;
    }
    // �������ݲ������ϣ��
    for (int i = 0; i < n; i++)
    {
        int key, data;
        cin >> key >> data;//�տ�ʼ��û��ֱ�ӽ����ݴ����ϣ��
        int index = key % p;  // ��ϣ���������ϣ��ַ
        // �����ͻ
        while (hashTable[index].key != -1) //��ʼֵ������-1��˵���Ѿ������ݴ��룡
        {
            linearProbing(index, m);  // ����̽����ɢ��
        }
        // ����¼�����ϣ��
        hashTable[index].key = key;
        hashTable[index].data = data;
    }
}

//����̽����ɢ�к�����
// �ڹ�ϣ���в���ָ���ؼ��֣������Ƿ���ҳɹ�
// ������
//   hashTable - ��ϣ������
//   m - ��ϣ���С
//   key - �����ҵĹؼ���
//   index - ���ҽ���Ĺ�ϣ��ַ
// ����ֵ��
//   �Ƿ���ҳɹ�
bool searchHashTable(HashNode* hashTable, int m, int key, int& index)
{
    index = key % m;  // ��ϣ���������ϣ��ַ
    // �ڹ�ϣ���в��ҹؼ���
    while (hashTable[index].key != -1) //�ؼ��ֲ�Ϊ-1��˵���������ݲ��ܽ���ѭ����������
    {
        if (hashTable[index].key == key) //�ؼ�����ͬ
        {
            return true;
        }
        linearProbing(index, m);  // ��ͻ��������̽�ⷨ��û���ҵ���Ӧ�Ĺؼ�ֵ�����ڳ�ͻ���������ң�
    }
    return false;
}

//������
int main() {
    //�����ϣ���С����ϣ��������p�����ݸ���n
    int m, p, n;
    cin >> m >> p >> n;

    //������ϣ��
    HashNode* hashTable = new HashNode[m];
    createHashTable(hashTable, m, p, n);

    //��������ҵĹؼ���
    int key;
    cin >> key;

    int index;
    //���ҹؼ����ڹ�ϣ���е�λ��
    if (searchHashTable(hashTable, m, key, index))
    {
        cout << "Find " << index << endl;
        //�����Ӧ�ļ�ֵ��
        cout << hashTable[index].key << " " << hashTable[index].data << endl;
    }
    else
    {
        cout << "NotFind" << endl;
    }

    //�ͷŹ�ϣ����ڴ�
    delete[] hashTable;
    return 0;
}