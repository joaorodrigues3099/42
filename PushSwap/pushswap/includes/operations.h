#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "../libft/includes/linklist.h"

void	ft_sa(t_list **lst_a, int print);
void	ft_sb(t_list **lst_b, int print);
void	ft_ss(t_list **lst_a, t_list **lst_b);

void	ft_pb(t_list **lst_a, t_list **lst_b);
void	ft_pa(t_list **lst_a, t_list **lst_b);

void	ft_ra(t_list **lst_a, int print);
void	ft_rb(t_list **lst_b, int print);
void	ft_rr(t_list **lst_a, t_list **lst_b);

void	ft_rra(t_list **lst_a, int print);
void	ft_rrb(t_list **lst_b, int print);
void	ft_rrr(t_list **lst_a, t_list **lst_b);

#endif //OPERATIONS_H
