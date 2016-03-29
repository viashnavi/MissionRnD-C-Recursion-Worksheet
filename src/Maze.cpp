/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>

int validxy(int*maze ,int x, int y,int prex,int prey,int rows,int columns){
	if (prex == x && prey == y)
		return 0;
	if (x >= 0 && y >= 0 && x<rows && y<columns && (maze[(x*columns)+y] == 1))
		return 1;
	return 0;
}

void p_exists(int* maze, int rows, int cloumns, int x1, int y1, int x2, int y2, int prex, int prey, int* rv){
	
	if (validxy(maze, x1 - 1, y1, prex,prey,rows, cloumns)){
		if ((x1 - 1 == x2) && (y1 == y2)){
			*rv = 1;
			return;
		}
		p_exists(maze, rows, cloumns, x1 - 1, y1, x2, y2, x1, y1, rv);
	}
	if (validxy(maze, x1 + 1, y1, prex, prey, rows, cloumns)){
		if ((x1 + 1 == x2) && (y1 == y2)){
			*rv = 1;
			return;
		}
		p_exists(maze, rows, cloumns, x1 + 1, y1, x2, y2, x1, y1, rv);
	}
	if (validxy(maze, x1, y1 - 1, prex, prey, rows, cloumns)){
		if ((x1 == x2) && (y1 - 1 == y2)){
			*rv = 1;
			return;
		}
		p_exists(maze, rows, cloumns, x1, y1 - 1, x2, y2, x1, y1, rv);
	}
	if (validxy(maze, x1, y1 + 1, prex, prey,rows, cloumns)){
		if ((x1 == x2) && (y1 + 1 == y2)){
			*rv = 1;
			return;
		}
		p_exists(maze, rows, cloumns, x1, y1 + 1, x2, y2, x1, y1, rv);
	}
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows > 0 && columns > 0 && x1>=0 && x2>=0 && y1>=0 && y2>=0 && x1<rows && x2<rows && y1<columns && y2<columns){
		if (maze[(x1*columns) + y1] == 1 && maze[(x2*columns) + y2] == 1){
			if (rows == 1){
				for (int i = y1; i <= y2; i++)
					if (maze[i] == 0)
						return 0;
				return 1;
			}
			else if (columns == 1){
				for (int i = x1; i <= x2; i++)
					if (maze[i] == 0)
						return 0;
					return 1;
			}
			else{
				int rv = 0;
				p_exists(maze, rows, columns, x1, y1, x2, y2, x1, y1, &rv);
				return rv;
			}
		}
	}
	return 0;
}
