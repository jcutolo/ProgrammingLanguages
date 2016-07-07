// Author:      Joshua Cutolo, Joshua Pinos & Hunter Childress
// Professor:   Albert Chan
// Course:      CSC 322
// Date:        4/26/2015
//=======================================================================
// Project:     C++
// Description: Implements the in-place heap sort algorithm in C++.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "math.h"
#include <cstdlib>

using namespace std;

// Function to return an integer as a string variable.
string to_String(int n) {
	stringstream stm;
	stm << n;
	return stm.str();
}

// Function for computing the left child's index with a given parent index.
int leftChildIndex(int index)
{
	return 2 * index + 1;
}

// Function for computing the right child's index with a given parent index.
int rightChildIndex(int index)
{
	return 2 * index + 2;
}

// Function for reversing the heap.
void reverseHeap(int data[], int array_size)
{
	int j, temp;
	int size = array_size;

	for (j = 0; j < array_size / 2; j++)
	{
		temp = data[j];
		data[j] = data[array_size - j - 1];
		data[array_size - j - 1] = temp;
	}
}

// Funtion for sifting in the heap.
void siftDown(int data[], int root, int bottom)
{
	int done, maxChild, temp;

	done = 0;
	while ((root * 2 <= bottom) * (!done))
	{
		if (root * 2 == bottom)
		{
			maxChild = root * 2;
		}
		else if (data[root * 2] > data[root * 2 + 1]) 
		{
			maxChild = root * 2;
		}
		else 
		{
			maxChild = root * 2 + 1;
		}
		if (data[root] < data[maxChild])
		{
			temp = data[root];
			data[root] = data[maxChild];
			data[maxChild] = temp;
			root = maxChild;
		}
		else 
		{
			done = 1;
		}
	}
}

// Function for sorting the input array using the in-place heap sort algorithm.
void heapify(int data[], int array_size) 
{
	int i, temp;
	int size = array_size;

	for (i = (array_size / 2) - 1; i >= 0; i--)
	{
		siftDown(data, i, array_size);
	}
	for (i = array_size - 1; i >= 1; i--)
	{
		temp = data[0];
		data[0] = data[i];
		data[i] = temp;
		siftDown(data, 0, i - 1);
	}
	for(i = 0; i < array_size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
	
	reverseHeap(data, size);
}

// Function for creating the visual binary heap tree.
string drawTree(int i, int count, int h_array[],string result)
{
	string tmp_string = result;
	if (rightChildIndex(i) < count)
	{
		tmp_string=drawTree(rightChildIndex(i), count, h_array,result);
	}
	int space = floor(log2(i+1));
	int s = space-floor(log2(i+1));
	int height = floor(log2(count));
	while (space >= 0)
	{
		tmp_string.append("\t");
		space--;
	}
	tmp_string += to_String((h_array[i]));
	while (s >= -1)
	{
		tmp_string.append("\n");
		s--;
	}

	if (leftChildIndex(i) < count)
	{
		tmp_string.append(drawTree(leftChildIndex(i), count, h_array,result));
	}
	return tmp_string;
}

// Function to start algorithm. Responsible for IO operations and preprocessing of text data.
string heapSortAlgorithm()
{
	string filename;
	cout << "Example file path = C:/Users/User/Documents/data.txt\n";
	cout << "What is the data path to your file?--> ";
	cin >> filename;
	ifstream fin(filename.c_str());
	string Line;
	stringstream iss;
	int token;
	int count = 0;
	int i = 0;
	int size = 5;
	int increment = 5;
	int *heap;
	heap = (int *)malloc(size*sizeof(int));
	while (getline(fin, Line))
	{
		iss << Line;

		while (iss.good())
		{
			iss >> token;
			if (count == size)
			{
				heap = (int *)realloc(heap, (size + increment)*sizeof(int));
				size = size + increment;
				heap[count] = token;
			}
			else
			{
				heap[count] = token;
			}
			count++;
		}
		iss.clear();
		iss.str("");

	}
	int heap_height = floor(log2(count));
	heapify(heap,count);
	string heapTree=drawTree(0 , count , heap , "");
	free(heap);
	return heapTree;
}

// Main function. Displays binary heap tree.  
int main()
{
	string tree;
	tree = heapSortAlgorithm();
	cout << tree << endl;
	cout << "Press any key and enter to quit...";
	int exit;
	cin>>exit;
	return 0;
}













