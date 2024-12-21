/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:41:35 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/25 14:41:35 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h> // For INT_MAX

// Function prototype
int ft_closest_in_chunck(t_list *lst, t_chunck *chunck1, t_chunck *chunck2, int *from_top, int *from_bottom);

typedef struct {
    char *sequence; // Sequence of "top" or "bottom" decisions
    int cost;       // Total number of moves
} Solution;

// Recursive function
Solution recursive_backtracking(t_list *lst_a, t_chunck *chunck1, t_chunck *chunck2, char *current_seq, int current_cost, int depth, int max_depth) {
    Solution result;
    result.sequence = NULL;
    result.cost = INT_MAX;

    // Base case: No more elements in chunks
    if (ft_is_empty(chunck1) && ft_is_empty(chunck2)) {
        result.sequence = strdup(current_seq); // Duplicate the current sequence
        result.cost = current_cost;
        return result;
    }

    // Calculate costs for top and bottom
    int from_top, from_bottom;
    ft_closest_in_chunck(lst_a, chunck1, chunck2, &from_top, &from_bottom);

    // Initialize variables to store solutions for both branches
    Solution top_solution = {NULL, INT_MAX};
    Solution bottom_solution = {NULL, INT_MAX};

    // Try the "top" option
    if (from_top < INT_MAX) { // Only consider valid "top" moves
        char *next_seq_top = strdup(current_seq);
        strcat(next_seq_top, "top, ");
        t_list *new_lst_a = simulate_move(lst_a, "top", chunck1, chunck2); // Simulate move
        top_solution = recursive_backtracking(new_lst_a, chunck1, chunck2, next_seq_top, current_cost + from_top, depth + 1, max_depth);
        free(next_seq_top);
    }

    // Try the "bottom" option
    if (from_bottom < INT_MAX) { // Only consider valid "bottom" moves
        char *next_seq_bottom = strdup(current_seq);
        strcat(next_seq_bottom, "bottom, ");
        t_list *new_lst_a = simulate_move(lst_a, "bottom", chunck1, chunck2); // Simulate move
        bottom_solution = recursive_backtracking(new_lst_a, chunck1, chunck2, next_seq_bottom, current_cost + from_bottom, depth + 1, max_depth);
        free(next_seq_bottom);
    }

    // Choose the better solution
    if (top_solution.cost < bottom_solution.cost) {
        result = top_solution;
        free(bottom_solution.sequence); // Free the unneeded sequence
    } else {
        result = bottom_solution;
        free(top_solution.sequence); // Free the unneeded sequence
    }

    return result;
}

// Wrapper function
Solution find_minimum_moves(t_list *lst_a, t_chunck *chunck1, t_chunck *chunck2) {
    char *initial_seq = strdup(""); // Start with an empty sequence
    Solution result = recursive_backtracking(lst_a, chunck1, chunck2, initial_seq, 0, 0, INT_MAX);
    free(initial_seq);
    return result;
}
