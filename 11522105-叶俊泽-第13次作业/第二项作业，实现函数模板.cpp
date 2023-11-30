#include<iostream>
#include<cmath>
using namespace std;

template<typename T>
T WHOMAX(int value, T* size) {
    T max = size[0];
    for (int i = 0; i < value; i++) {
        if (size[i] >= max)
            max = size[i];
    }
    return max;
}

int main() {
    int N = 0;
    cout << "please input the size of the array: ";
    cin >> N;
    cout << endl;

    int* a = new int[N];
    double* b = new double[N];

    cout << "please input the elements of the array: (int)" << endl;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cout << endl;

    cout << "please input the elements of the array: (double)" << endl;
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    cout << endl;

    cout << "The max element of the int array is " << WHOMAX(N, a) << endl;
    cout << "The max element of the double array is " << WHOMAX(N, b) << endl;

    delete[] a;
    delete[] b;

    return 0;
}
