/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:42:46 by breadyma          #+#    #+#             */
/*   Updated: 2021/12/09 18:33:31 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_set
{
	int	count;
	int	len_a;
	int	len_b;
	int	len;
	int	flags;
}	t_set;

typedef struct s_stack
{
	int				order;
	int				num;
	int				flag;
	int				len_a;
	int				len_b;
	struct s_stack	*next;
}	t_stack;

void	ft_free_list(t_stack **stack);
void	ft_add_back(t_stack **stack, t_stack *new);
void	ft_stack_list(int *nums, int i);

int		*ft_sort(int *numbers, int len);
int		ft_intlen(int *num);
int		ft_check_sort(int *num, int len);
int		ft_find_max(t_stack **stack);

void	ft_sa(t_stack **stack);
void	ft_sb(t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack);
void	ft_rb(t_stack **stack);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack);
void	ft_rrb(t_stack **stack);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_stack_sort_few(t_stack **stack_a, t_stack **stack_b, t_set *set);
void	ft_sort_three(t_stack **stack_a);
void	ft_sort_b(t_stack **stack_a, t_stack **stack_b, t_set *set);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **stack_b, t_stack **stack_a);
void	ft_big_sort(t_stack **stack_a, t_stack **stack_b, t_set *set);
void	ft_big_sort_stack_b(t_stack **stack_a, t_stack **stack_b, t_set *set);
void	ft_bez_bileta_a(t_stack **stack_a, t_set *set, int i);
void	ft_bez_bileta_b(t_stack **stack_a, t_stack **stack_b, t_set *set);
void	ft_bez_bileta_b_two(t_stack **stack_a, t_stack **stack_b, t_set *set);
void	ft_chek_void(char **argv);

void	ft_bez_bileta_last(t_stack **stack_a, t_stack **stack_b, t_set *set);

t_stack	*ft_last(t_stack **stack);

void	printlist(t_stack **stack, t_stack **stack_b);

#endif