#include<iostream>
#include <vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<chrono>
#include <cstdlib>
#include <ctime>
#include <functional> 
#include <random>
#include <fstream>
using namespace std;
void shellsort(vector<int>& L, long long int& moves, long long int& comparisons);


void swap(int& a, int& b);
void HeapAdjust(vector<int>& L, int s, int m, long long int& moves, long long int& comparisons);
void HeapSort(vector<int>& L, int len, long long int& moves, long long int& comparisons);


int Quick_Sort(vector<int>& L, int low, int high, long long int& moves, long long int& comparisons);
void QuickSort(vector<int>& L, int low, int high, long long int& moves, long long int& comparisons);


int getDigit(int number, int digit);
void radixSort(vector<int>& nums, long long int& moves, long long int& comparisons);


void Insertsort(vector<int>& L, long long int& moves, long long int& comparisons);


void Explation();
void GenerateRandomNumbers(vector<int>& numbers,int size, int t);
void printHorizontalLine();


double measureSortingTime1(vector<int> arr, long long int& moves, long long int& comparisons);
double measureSortingTime2(vector<int> arr, int len, long long int& moves, long long int& comparisons);
double measureSortingTime3(vector<int> arr, int low, int high, long long int& moves, long long int& comparisons);
double measureSortingTime4(vector<int> arr, long long int& moves, long long int& comparisons);
double measureSortingTime5(vector<int> arr, long long int& moves, long long int& comparisons);


void OutPut(long long int& moves, long  long int& comparisons, double& SortingTime);


void generateRandomNumbersToFile(string& filename, int count, int t);
void readDataFromFile(string& filename, vector<int>& data);

