#include <iostream>
using namespace std;
char maze[100][100];
class Pare
{
public :
	int pare;
	Pare()
	{
		pare = 0;
	}
};
struct mazePos // record the coordinate of now and current char
{
	int col;
	int row;
	char value;
};
template<class T> // stack implementation
class stack
{
private:
	int capacity;
	T *array;
public:
	int top;
	stack(int s)
	{
		capacity = s;
		array = new T[s];
		top = 0;
	}
	void push(T newItem)
	{
		*(array + top) = newItem;
		top++;
	}
	T pop()
	{
		T existItem;
		top--;
		existItem = *(array + top);
		return existItem;
	}
	T Top()
	{
		T existItem;
		existItem = *(array + top - 1);
		return existItem;
	}
	bool isEmpty()
	{
		return top == 0;
	}
};
////////////////////////////////expressionValid//////////////////////////////////
Pare pareBalance;
bool expressionValid(char currentChar, char nextChar)
{
	if (currentChar >= '1' && currentChar <= '9')
	{
		if (nextChar == '(')
			return false;
		else
			return true;
	}
	else if (currentChar == '*' || currentChar == '/' || currentChar == '+' || currentChar == '-')
	{
		if (nextChar == ')' || nextChar == '*' || nextChar == '/' || nextChar == '+' || nextChar == '-')
			return false;
		else
			return true;
	}
	else if (currentChar == '(')
	{
		if (nextChar == ')' || nextChar == '*' || nextChar == '/' || nextChar == '+' || nextChar == '-')
			return false;
		else
			return true;
	}
	else if(currentChar == ')')
	{
		if (nextChar == '('  || (nextChar >= '1' && nextChar <= '9') )
			return false;
		else
			return true;
	}
	else
		return false;
}
mazePos Maze;
stack<int> visitedX(500); // to mark the visited x
stack<int> visitedY(500); // to mark the visited y
bool IsnVisit(int y, int x)
{
	bool isnVisit = true; // not visit
	int i, j, col, row;
	j = visitedX.top;
	for (i = 0; i < j; i++)
	{
		col = visitedX.Top(); row = visitedY.Top();
		if ((col == x) && (row == y))
			isnVisit &= false;
		else
			isnVisit &= true;
		visitedX.top--; visitedY.top--;
	}
	visitedX.top = j; visitedY.top = j;
	return isnVisit;
}
bool path(int row, int col, int height, int width)
{
	Maze.row = row;
	Maze.col = col;
	Maze.value = maze[row][col];
	visitedY.push(row); visitedX.push(col);
	if (row == 0 && col == 0) // to check if initial pos is valid
	{
		if(maze[row][col] == '+' || maze[row][col] == '-' || maze[row][col] == '*' || maze[row][col] == '/' || maze[row][col] == ')')
			return false;
	}
	if (maze[row][col] == '(')
		pareBalance.pare++;
	else if (maze[row][col] == ')')
		pareBalance.pare--;
	if (pareBalance.pare < 0)
	{
		Maze.row = visitedY.pop(); Maze.col = visitedX.pop();
		pareBalance.pare++;
		return false;
	}
	if ((row == height - 1) && (col == width - 1))
	{
		if (maze[row][col] == '+' || maze[row][col] == '-' || maze[row][col] == '*' || maze[row][col] == '/')
		{
			Maze.row = visitedY.pop(); Maze.col = visitedX.pop();
			return false;
		}
		else if (pareBalance.pare == 0)
			return true;
		else
		{
			if (pareBalance.pare > 0)
				pareBalance.pare++;
			Maze.row = visitedY.pop(); Maze.col = visitedX.pop();
			return false;
		}
	}
	// down
	if ((row + 1 < height) && (expressionValid(maze[row][col], maze[row + 1][col])) && IsnVisit(row + 1, col))
		if (path(row + 1, col, height, width))
			return true;
	// right
	if ((col + 1 < width) && (expressionValid(maze[row][col], maze[row][col + 1])) && IsnVisit(row, col + 1))
		if (path(row, col + 1, height, width))
			return true;
	// left
	if ((col - 1 >= 0) && (expressionValid(maze[row][col], maze[row][col - 1])) && IsnVisit(row, col - 1))
		if (path(row, col - 1, height, width))
			return true;
	// up
	if ((row - 1 >= 0) && (expressionValid(maze[row][col], maze[row-1][col])) && IsnVisit(row-1, col))
		if (path(row-1, col, height, width))
			return true;
	if (maze[row][col] == '(')
		pareBalance.pare--;
	else if (maze[row][col] == ')')
		pareBalance.pare++;
	Maze.row = visitedY.pop(); Maze.col = visitedX.pop();
	return false;
}
int priority(char op)
{
	switch (op)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}
int main(void)
{
	int height, width, matrixNum, n;
	int count = 0;
	cin >> matrixNum;
	cout << matrixNum << endl;

	while (matrixNum != count)
	{
		cin >> width; cout << width << endl;
		cin >> height; cout << height << endl;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cin >> maze[i][j];
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << maze[i][j] << " ";
			cout << endl;
		}
		if (path(0, 0, height, width)) //go find sol
		{
			n = visitedX.top;
			char infix[10000] = {'\0'};
			int *row = new int[n]; int *col = new int[n];
			cout << "Yes" << endl;
			for (int i = 0; i < n; i++)
			{
				row[i] = visitedY.pop(); col[i] = visitedX.pop();
			}
			int j = 0;
			for (int i = n - 1; i >= 0; i--)
			{
				infix[j] = maze[row[i]][col[i]];
				j++;
			}
			for (int i = 0; i < n; i++)
			{
				switch (infix[i])
				{
				case '+': case '-':  case '*': case '/':
					cout << " " << infix[i] << " ";
					break;
				case ')':
					cout << " " << infix[i];
					break;
				case '(':
					cout << infix[i] << " ";
					break;
				case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
					cout << infix[i];
					break;
				}
			}
			cout << " " << endl;
			stack<char> operatorStack(int(height * width / 2));
			stack<char> operandStack(int(height * width / 2));
			///////////////////infixToPostfix///////////////////
			for (int i = 0; i < n; i++)
			{
				switch (infix[i])
				{
				case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
					cout << infix[i];
					break;
				case '+': case '-':  case '*': case '/':
					cout << " ";
					if (!operatorStack.isEmpty())
					{
						for (; priority(operatorStack.Top()) >= priority(infix[i]); operatorStack.pop())
							cout << operatorStack.Top() << " ";
						operatorStack.push(infix[i]);
					}
					else
						operatorStack.push(infix[i]);
					break;
				case ')':
					for (; operatorStack.Top() != '('; operatorStack.pop())
						cout << " " << operatorStack.Top();
					operatorStack.pop();
					break;
				case '(':
					operatorStack.push(infix[i]);
					break;
				}
			}
			while (!operatorStack.isEmpty())
				cout << " " << operatorStack.pop();
			///////////////////infixToPostfix///////////////////
			cout << " " << endl;
			delete[] row; delete[] col;
		}
		else
			cout << "No" << endl;
		count++;
	}
	system("pause");
	return 0;
}