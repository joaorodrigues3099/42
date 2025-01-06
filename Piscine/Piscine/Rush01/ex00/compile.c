#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str) //counts the string's lenght
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_grid_size(char *str) //checks if the size of the argument is valid, allows for 4x4, 5x5 and 6x6 grids
{
	int	i;

	i = 4;
	while (i <= 6)
	{
		if (ft_strlen(str) == (i * 4 * 2 - 1)) //ft_strlen
			return (i);
		i++;
	}
	return (0);
}

int	**ft_alloc_clues(int **clues, int size)
{
	int	i;

	clues = (int **)malloc(sizeof(int *) * 4); //allocates memory for 4 int pointers
	if (!clues)
		return (0); //if no memory available
	i = 0;
	while (i < 4) //allocates 4 memory 
	{
		clues[i] = (int *)malloc(sizeof(int) * size); //allocates memory = size for every array of clues (pointer)
		if (!clues[i])
			return (0); //if no memory return 0
		i++;
	}
	return (clues); //return clues
}

int	**ft_set_clues(char *str, int **clues, int size)
{
	int	i;	//lopp variables
	int	j;	

	i = 0; //goes through string
	j = 0; //counts clues
	while (str[i]) //while string is different than '\0'
	{
		if (!(str[i] >= '0' && str[i] <= '9')) //check if value sis between 0 and 9
			return (0); //return 0 if there is not. This string is not correctly inputed!
		else
		{
			clues[(i - j) / size][(i - j) % size] = str[i] - 48; //allocates the clues in the clues array previously reserved (malloc)
			i++;
			if (str[i] != ' ' && str[i] != '\0') //return 0 if the character after the number is neither a space or null. String is not correct!
				return (0);
			else
			{
				if (str[i]) //if string is different than '\0' go to next number
					i++;
				j++;
			}
		}
	}
	return (clues); //return filled clues array
}

int	**ft_input(char *str)
{
	int	**clues;
	int	size;

	size = ft_grid_size(str); //counts size again
	clues = 0;
	if (size)
	{
		clues = ft_alloc_clues(clues, size); //ft_alloc_clues
		clues = ft_set_clues(str, clues, size); //ft_set:clues
		return (clues); //return filled clues array
	}
	else
		return (0); //if size is null return 0
}

int	ft_grid_size(char *str);

int	**ft_set_start_grid(int **grid, int size) //creates empty grid
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	return (grid);
}

int	**ft_set_grid(int **grid, int size) 
{
	int	row;

	grid = (int **)malloc(sizeof(int *) * size); //same as we did for the clues, this time for the grid
	if (!grid)
		return (0);
	row = 0;
	while (row < size)
	{
		grid[row] = (int *)malloc(sizeof(int) * size);
		if (!grid[row])
			return (0);
		row++;
	}
	return (grid);
}

int	ft_is_height_not_there(int **grid, int tab[], int height) //checks if the value inputed is already in same row or col
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (i < tab[2])
	{
		if (grid[i][tab[1]] == height || grid[tab[0]][i] == height)
			c++;
		i++;
	}
	if (c > 0)
		return (0);
	else
		return (1);
}

//clue -> from left to right, the number of the tallest boxesclue
//height -> the height of the box to be placed
//int c -> the count of the highest boxes seen
//int highest -> the current highest boxes seen
int	ft_is_valid_left(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = 0;
	while (i <= tab[1])
	{
		if (grid[tab[0]][i] > hightest)
		{
			hightest = grid[tab[0]][i];
			c++; //count height
		}
		i++;
	}
	grid[tab[0]][tab[1]] = 0;
	if ((tab[1] == tab[2] - 1 && c != clue) //compares height of current block with clue
		|| (tab[1] != tab[2] - 1 && c > clue))
		return (0);
	else if ((tab[1] == tab[2] - 1 && c == clue)
		|| (tab[1] != tab[2] - 1 && c <= clue))
		return (1);
	return (0);
}

//(grid[tab[0]][i] > hightest)
//the current col is greater than the current highest box seen
int	ft_is_valid_right(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	if (tab[1] != tab[2] - 1)
		return (1);
	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = tab[2] - 1;
	while (i >= 0)
	{
		if (grid[tab[0]][i] > hightest)
		{
			hightest = grid[tab[0]][i];
			c++;
		}
		i--;
	}
	grid[tab[0]][tab[1]] = 0;
	if (tab[1] == tab[2] - 1 && c != clue)
		return (0);
	else if (tab[1] == tab[2] - 1 && c == clue)
		return (1);
	return (0);
}

int	ft_is_valid_top(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = 0;
	while (i <= tab[0])
	{
		if (grid[i][tab[1]] > hightest)
		{
			hightest = grid[i][tab[1]];
			c++;
		}
		i++;
	}
	grid[tab[0]][tab[1]] = 0;
 	if ((tab[0] == tab[2] - 1 && c != clue)
		|| (tab[1] != tab[2] - 1 && c > clue))
		return (0);
	else if ((tab[0] == tab[2] - 1 && c == clue)
		|| (tab[0] != tab[2] - 1 && c <= clue))
		return (1);
	return (0);
}

int	ft_is_valid_bottom(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	if (tab[0] != tab[2] - 1)
		return (1);
	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = tab[2] - 1;
	while (i >= 0)
	{
		if (grid[i][tab[1]] > hightest)
		{
			hightest = grid[i][tab[1]];
			c++;
		}
		i--;
	}
	grid[tab[0]][tab[1]] = 0;
	if (tab[0] == tab[2] - 1 && c != clue)
		return (0);
	else if (tab[0] == tab[2] - 1 && c == clue)
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display(int **grid, int size) //
{
	int	i; //line number
	int	j; //col number

	i = 0;
	while (i < size) //while reaches 4th line
	{
		j = 0;
		while (j < size) //while reaches 4th col
		{
			ft_putchar(grid[i][j] + 48); //writes number from solved grid
			if (j < size - 1) //checks if we reached the last digit of the line
				ft_putchar(' '); //if its not the last digit, give a space
			j++; //next digit
		}
		ft_putchar('\n'); //jump line
		i++;
	}
}

int	*ft_find_empty_cell(int **grid, int size)
{
	int	row; 
	int	col;
	int	*res; 

	res = (int *)malloc(sizeof(int) * 2); //reserved space for 2 ints col and row
	if (!res)
		return (0); //if no available space, return 0
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (grid[row][col] == 0) //return first empty cell that it encounters
			{
				res[0] = row;
				res[1] = col;
				return (res);
			}
			col++;
		}
		row++;
	}
	return (0);
}

//check if the grid is completely filled - no empty cells
int	ft_grid_is_complete(int **grid, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (grid[row][col] == 0)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

//check if the number satisfies all the required conditions
int	ft_comb_is_valid(int **grid, int **clues, int tab[], int height) //combverif.c
{
	if (!ft_is_height_not_there(grid, tab, height)) //check duplicates
	{
		return (0);
	}
	if (!ft_is_valid_left(grid, clues[2][tab[0]], tab, height)) 
	{
		return (0);
	}
	if (!ft_is_valid_right(grid, clues[3][tab[0]], tab, height))
	{
		return (0);
	}
	if (!ft_is_valid_top(grid, clues[0][tab[1]], tab, height))
	{
		return (0);
	}
	if (!ft_is_valid_bottom(grid, clues[1][tab[1]], tab, height))
	{
		return (0);
	}
	return (1); //if it passes all validations, return 1
}

int	**ft_solver(int **grid, int **clues, int size)
{
	int	*zero_index;
	int	i;
	int	tab[3];

	if (ft_grid_is_complete(grid, size))
	{
		return (grid);
	}
	zero_index = ft_find_empty_cell(grid, size); //find empty cell
	tab[0] = zero_index[0]; //gives row coordinate to array
	tab[1] = zero_index[1]; //gives col coordinate to array
	tab[2] = size; //gives size to the array
	i = 1;
	while (i <= size)
	{
		if (ft_comb_is_valid(grid, clues, tab, i)) //ft_comb_is_valid
		{
			grid[zero_index[0]][zero_index[1]] = i; //put the number in the previously checked row and col
			if (ft_solver(grid, clues, size)) //recursive calls the own function
				return (grid); //retun solved grid
			grid[zero_index[0]][zero_index[1]] = 0;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	**grid;
	int	**clues;
	int	size;

	if (argc == 2) //check if there's just one inputed argument
	{
		size = ft_grid_size(argv[1]); //input.c 
		clues = ft_input(argv[1]); //input.c
		grid = 0;
		grid = ft_set_grid(grid, size); //others.c
		grid = ft_set_start_grid(grid, size); //other.c
		if (clues) //if there is valid clues
			grid = ft_solver(grid, clues, size); //ft_solver
		if (!grid || !clues)
			write(1, &"Error\n", 6);
		else
			ft_display(grid, size);
	}
	else
		write(1, &"Error\n", 6);
}
