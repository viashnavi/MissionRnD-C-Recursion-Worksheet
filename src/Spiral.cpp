/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void recurse(int rows, int columns, int **input_array, int* arr, int start, int ptr, int min){
	if (start < min){
		for (int i = start; i < columns - start; i++){
			printf("%d%d\n", start, i);
			arr[ptr++] = input_array[start][i];
		}
		for (int i = 1 + start; i < rows - 1 - start; i++){
			printf("%d%d\n", i, columns - 1 - start);
			arr[ptr++] = input_array[i][columns - 1 - start];
		}
		for (int i = columns - 1 - start; i >= 0 + start; i--){
			printf("%d%d\n", rows - 1 - start, i);

			arr[ptr++] = input_array[rows - 1 - start][i];
		}
		for (int i = rows - 2 - start; i > start; i--){
			printf("%d%d\n", i, start);
			arr[ptr++] = input_array[i][start];
		}
		recurse(rows, columns, input_array, arr, start + 1, ptr, min);
	}
}

int *spiral(int rows, int columns, int **input_array)
{
	if (rows > 0 && columns > 0 && input_array != NULL){
		int min = (rows > columns) ? columns : rows;
		min = (min / 2) + (min % 2);
		int* arr = (int*)malloc(sizeof(int)*((columns + 1)*(rows + 1)));
		recurse(rows, columns, input_array, arr, 0, 0, min);
		return arr;
	}
	return NULL;
}

