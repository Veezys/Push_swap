/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:14:35 by breadyma          #+#    #+#             */
/*   Updated: 2021/12/09 19:24:55 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = (*stack)->order;
	while (tmp)
	{
		if (tmp->order > max)
			max = tmp->order;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_bez_bileta_a(t_stack **stack_a, t_set *set, int i)
{
	if (i == 1)
	{
		(*stack_a)->flag = -1;
		ft_ra(stack_a);
		set->count++;
	}
	else if (i == 2)
	{
		ft_sa(stack_a);
		(*stack_a)->flag = -1;
		ft_ra(stack_a);
		set->count++;
	}
}

void	ft_bez_bileta_b(t_stack **stack_a, t_stack **stack_b, t_set *set)
{
	if ((*stack_b)->order == set->count)
	{
		(*stack_b)->flag = -1;
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
		set->len_b--;
		set->len_a++;
		set->count++;
	}
	else if ((*stack_b)->next && (*stack_b)->next->order == set->count)
		ft_bez_bileta_b_two(stack_a, stack_b, set);
}

void	ft_bez_bileta_b_two(t_stack **stack_a, t_stack **stack_b, t_set *set)
{
	if ((*stack_b)->next && (*stack_b)->next->order == set->count)
	{
		ft_sb(stack_b);
		(*stack_b)->flag = -1;
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
		set->len_b--;
		set->len_a++;
		set->count++;
	}
}
