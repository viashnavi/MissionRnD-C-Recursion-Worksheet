/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include<malloc.h>
#include "stdafx.h"


int abs(int num){
	if (num < 0){
		return num*-1;
	}
	return num;
}

int correct(int* x, int i, int j){

	if (i == 0){
		return 1;
	}
	else{
		int k;
		for (k = 0; k < i; k++){
			if ((x[k] == j) || (abs(x[k] - j) == abs(k - i))){
				return 0;
			}
		}
	}
	return 1;
}

void solve_n(int* x, int start, int n, int* var){
	int i;
	for (i = 0; i < n; i++){
		if (x[n - 1] == -1){
			if (correct(x, start, i)){
				x[start] = i;
				if (start == (n - 1)){
					*var = 1;
					return;
				}
				else{
					solve_n(x, start + 1, n, var);
				}
			}
		}
	}
}

int solve_nsnipers(int *battlefield, int n){
	if (battlefield){
		int i;
		int* x = (int*)malloc(sizeof(int)*n);
		for (i = 0; i < n; i++){
			x[i] = -1;
		}
		int var;
		solve_n(x, 0, n, &var);
		if (var == 1){
			for (i = 0; i<n; i++){
				int temp = (i * n) + x[i];
				battlefield[temp] = 1;
			}
			return 1;
		}
	}
	return 0;
}
