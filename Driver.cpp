#include "pch.h"
#include<iostream>
#include<fstream>
#include<chrono>
#include<conio.h>
#include<random>
#include<algorithm>
#include<ctime>

using namespace std;
using namespace std::chrono;

void random_array(int arr[], int size);           // Function to generate random array of given size
void insrtionSort(int arr[], int startIndex, int endIndex);

int main() {

	const int SIZE_OF_ARRAY = 30000;
	int rand_arr[SIZE_OF_ARRAY];
  
	fstream outfile;          // Objest to store sorted array in a csv file
	random_array(rand_arr, SIZE_OF_ARRAY);
  
	auto start = steady_clock::now();
	insrtionSort(rand_arr, 0, SIZE_OF_ARRAY);
	auto end = steady_clock::now();
	auto time_calculated = duration_cast<nanoseconds>(end - start);

	cout << "\n\n The time taken be inertion sort on random array of size 10000 in nanoseconds is : " << time_calculated.count() << endl << endl;
	
  outfile.open("RandomSortedArray.csv", ios::out | ios::app);
  
  // Store the sorted array in to file "RandomSortedArray.csv"
	for (int i = 0; i < SIZE_OF_ARRAY ; i++) {
		outfile << rand_arr[i] << endl;
	}

	outfile.close();
  // To hold the terminal
  _getch();

	return 0;
}

void random_array(int arr[], int size) {
	std::random_device r;
	std::mt19937 eng(r());
	std::uniform_int_distribution<int> distribution(1, 1000);
	for (int i = 0; i < size; i++) {
		arr[i] = distribution(eng);
	}
}

void insrtionSort(int arr[], int startIndex, int endIndex) {
	int i = 0 , key = 0, j = 2;
	for (j = startIndex; j < endIndex; j++) {
		key = arr[j];
		i = j - 1;
		while (i > startIndex - 1 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i--;
		}
	}
}
