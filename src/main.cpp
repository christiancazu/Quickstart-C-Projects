#include <iostream>			// input, output
#include <stdlib.h>			// srand, rand
#include <time.h>				// time
#include <stdlib.h>			// new, delete pointers buffer

using namespace std;

#pragma region Global variables(declaration)

struct Node
{
	int value;
	Node *right;
	Node *down;
};

int rows, columns, **matrix;	// matrix params
int minRange = 0, maxRange = 9;		// range for random numbers
Node *tree = NULL;

#pragma endregion

#pragma region Function prototype(declaration)

void setMatrixFormat();	// show matrix values
void setMatrixValues();	// setting matrix values
void printMatrix();			// initialize matrix dimentions
Node *makeNode(int);		// node maker				
void setTree();					// setter tree
void printRoad(Node*);	

#pragma endregion

int main()
{
	setMatrixFormat();
	setMatrixValues();
	cout << "\nmatrix :" << '\n';
	printMatrix();
	cout << "\nsetting tree with nodes :" << '\n';
	setTree();
	//printRoad(tree);

	delete[] matrix;
	system("pause");
	return 0;
}

#pragma region Functions definition

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

void setMatrixFormat()
{
	cout << "Indique cantidad de filas: " << '\n';
	cin >> rows;
	cout << "Indique cantidad de columnas: " << '\n';
	cin >> columns;

	matrix = new int *[rows];

	for (size_t i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
	}

}

void setMatrixValues()
{
	srand(time(NULL));
	
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++) 
			*(*(matrix + i) + j) = rand() % (maxRange - minRange + 1) + minRange;
}


Node *makeNode(int value) 
{
	Node *node = new Node();
	node->value = value;
	node->right = NULL;
	node->down = NULL;

	return node;
}

void setTree() 
{
	// initialize tree
	tree = makeNode(**matrix);
	Node *aux;
	aux = tree;
	
	for (size_t r = 0; r < rows; r++)
	{
		for (size_t c = 0; c < columns; c++)
		{
			if (c < columns - 1)
			{
				aux->right = makeNode(matrix[r][c + 1]);
			}
			if (r < rows - 1)
			{
				aux->down = makeNode(matrix[r + 1][c]);
			}
			cout << "\ncurrent node: " << aux->value;
			if(aux->right != NULL)
				cout << " to-right: " << aux->right->value;
			else cout << " to-right:  ";
			if(aux->down != NULL)
				cout << " to-down: " << aux->down->value;
			else cout << " to-down:  ";
			if(aux->right != NULL)
			aux = aux->right;	
		}
		aux = tree->down;
		cout << "\n-----------------------\n";
		for(size_t z = 0; z < r; z++)
			aux = aux->down;
	}
} 

void printRoad(Node *tree) {
	if(tree == NULL) {
		return;
	}	
	else {
			//cout<< "\ncurrent tree " << tree->value;
			printRoad(tree->down);	
			printRoad(tree->right);			
	}
	//cout<< "\ntree finish" << tree->value;
	return;
}

#pragma endregion
