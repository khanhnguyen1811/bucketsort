#include <iostream>
#include <vector>

#include <algorithm>
#include <cmath>

using namespace std; 
const int B_size = 10; 
void printarray(float arr[], int n){
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void Bucketsort(float arr[], int n){
	//khai bao mang bucket.
	vector<float> bucket[B_size]; 

	int i, j;
	float max, devider; 
	//find max.
	max = arr[0]; 
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	//cal devider. 
	devider = ceil(float(max + 1) / B_size);
	for (i = 0; i < n; i++)
	{
		j = floor(arr[i] / devider); 
		bucket[j].push_back(arr[i]); 
	}
	//sort the bucket with size. 
	for (i = 0; i < B_size; i++)
	{
		sort(bucket[i].begin(), bucket[i].end());
	}

	//rearrange. 
	int id = 0; 
	for (i = 0; i < B_size; i++)
	{
		for (j = 0; j < bucket[i].size(); j++)
		{
			arr[id++] = bucket[i][j]; 
		}
	}
}
int main(){
	float arr[100]; int i, n; 
	cout << "nhap size: "; cin >> n; 
	for (i = 0; i < n; i++)
	{
		cin >> arr[i]; 
	}
	//call negative, positive.
	float neg[10], pos[10]; int j = 0, k = 0, l = 0; 
	for (i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			neg[j] = arr[i];
			neg[j] = abs(neg[j]);
			j++;
		}
		else
		{
			pos[k] = arr[i]; 
			k++; 
		}
	}

	Bucketsort(neg, j); 
	cout << "mang so am: "; 
	printarray(neg, j); 
	cout << "\n"; 
	Bucketsort(pos, k); 
	cout << "mang so duong: "; 
	printarray(pos, k);
	cout << "\n"; 
	//ghep mang. 
	l = j - 1; 
	for (i = 0; i < j; i++)
	{
		arr[i] = neg[l]; 
		arr[i] -= neg[l] * 2; 
		l--; 
	}
	l = 0;
	for (i= j; i < n; i++)
	{
		arr[i] = pos[l++];
	}
	cout << "mang arr dc xep: "; printarray(arr, n); 
	cout << "\n"; 
	return 0;
}