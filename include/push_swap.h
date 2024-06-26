/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 03:15:56 by nesuvya           #+#    #+#             */
/*   Updated: 2024/04/26 08:58:30 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <limits.h>
# include "utils.h"
# include "printf.h"
# include "gnl.h"

typedef struct s_stack
{
	int				n;
	int				order;
	struct s_stack	*next;
	struct s_stack	*previous;
}		t_stack;

int		ft_is_sorted(t_stack *a);
t_stack	*ft_checked_args(int argc, char **argv, int *size);

void	ft_go_to_next_stack(t_stack *start, t_stack **next);
void	ft_clear_stack(t_stack **stack);
void	ft_clear_stacks(t_stack **a, t_stack **b);

typedef struct s_mkstack
{
	t_stack	*stack;
	t_stack	*next;
	int		max;
	int		i;
	int		j;
}	t_mkstack;

int		ft_get_order(int new, t_mkstack *aux, int size);
int		ft_is_int_valid(t_valid_int *v, char *splited,
			t_mkstack *aux, int size);
int		ft_in_stack(int arg, t_stack *s);
int		ft_add_new_stack(char *splited, t_mkstack *aux, int *size);

typedef struct s_operations
{
	int					op;
	struct s_operations	*next;
	struct s_operations	*previous;
}	t_operations;

int		ft_are_indep(int op1, int op2);
int		ft_annule_ops(int op1, int op2);

void	ft_synthetise_ops(t_operations **ops);
int		ft_add_operation(int op, t_operations **operations);
void	ft_print_op(int op);
void	ft_print_operations(t_operations *operations);

typedef struct s_sort
{
	int				size;
	int				size_a;
	int				size_b;
	t_operations	*ops;
	t_stack			*a;
	t_stack			*b;
	int				add_chunk;
	int				size_chunk;
	int				nbr_chunks;
}		t_sort;

void	ft_init_sort(t_sort *sort, t_stack *a, int size);
void	ft_push_back_to_a(t_sort *sort);
void	ft_push_to_b(t_sort *sort);
void	ft_sort_three(t_sort *sort);
void	ft_sort(t_sort *s);

int		ft_push(t_stack **a, t_stack **b);
int		ft_swap(t_stack *a);
int		ft_rotate(t_stack **a);
int		ft_reverse_rotate(t_stack **a);
int		ft_double_swap(t_sort *sort);
int		ft_double_rotate(t_sort *sort);
int		ft_double_reverse_rotate(t_sort *sort);

int		ft_do_op(t_sort *sort, int op);
void	ft_do_operation(t_sort *sort, int op);

typedef struct s_chunk
{
	int	min_chunk;
	int	max_chunk;
	int	chunk;
	int	min_next_chunk;
	int	max_next_chunk;
}	t_chunk;

int		ft_bottom_distance_to_chunk(t_stack *a, int size_a,
			int chunk_min, int chunk_max);
int		ft_top_distance_to_chunk(t_stack *a, int size_a,
			int chunk_min, int chunk_max);

#endif
