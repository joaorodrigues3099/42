#ifndef ERROR_CODES_H
#define ERROR_CODES_H

# define PINK "\033[38;2;231;133;190m"
# define RESET "\033[0m"

typedef struct s_game t_game;

enum e_error
{
	E_OK = 0,
	E_MEMORY_ALLOC = 1000,
	E_INVALID_FD = 2000,
	E_INVALID_FILE = 2001,
	E_INVALID_TYPE = 2002,
	E_INVALID_FORMAT = 2003,
	E_MAP_NOT_RECTANGLE = 3000,
	E_MAP_NOT_SURROUNDED = 3001,
	E_MULTIPLE_STARTS = 3002,
	E_MULTIPLE_EXITS = 3003,
	E_INVALID_CHARACTER = 3004,
	E_NO_START = 3005,
	E_NO_EXIT = 3006,
	E_NO_COLLECTIBLE = 3007,
	E_OBSTRUCTED_PATH = 3008
};

int		ft_print_error(int err_code);
void	ft_free_exit(const t_game *game, int err_code);

#endif //ERROR_CODES_H
