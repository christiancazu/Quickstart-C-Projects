#include <iostream>			/* input, output */
#include <conio.h>			/* getch */
#include <stdlib.h>			/* srand, rand */
#include <time.h>				/* time */
#include <stdlib.h>			/* new, delete pointers buffer */

using namespace std;

#pragma region Global variables(declaration)

int rows, columns, **matrix;				/* matrix params */
int minRange = 0, maxRange = 9;			/* range for random numbers */

#pragma endregion

#pragma region Function prototype(declaration)

void formatMatrix();			/* show matrix values */
void setMatrix();					/* setting matrix values */
void printMatrix();				/* initialize matrix dimentions */

#pragma endregion

int main()
{
	formatMatrix();
	setMatrix();
	printMatrix();

	delete[] matrix;
	getch();
	return 0;
}

#pragma region Functions

void printMatrix()
{

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			cout << *(*(matrix + i) + j) << ' ';
		}
		cout << '\n';
	}
}

void formatMatrix()
{

	cout << "Indique cantidad de filas: " << '\n';
	cin >> rows;
	cout << "Indique cantidad de columnas: " << '\n';
	cin >> columns;

	matrix = new int *[rows];

	for (size_t i = 0; i < rows; i++)
		matrix[i] = new int[columns];
}

void setMatrix()
{

	srand(time(NULL));

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			*(*(matrix + i) + j) = rand() % (maxRange - minRange + 1) + minRange;
}

#pragma endregion
