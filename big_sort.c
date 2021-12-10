/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:58:53 by breadyma          #+#    #+#             */
/*   Updated: 2021/12/09 19:24:46 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last_stack(t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_second_sort(t_stack **stack_a, t_stack **stack_b, t_set *set)
{
	int	flag;

	while (set->count < set->len)
	{
		if (set->len_b > 0)
			ft_big_sort_stack_b(stack_a, stack_b, set);
		if (set->len_b == 0)
		{
			flag = (*stack_a)->flag;
			while ((*stack_a)->flag == flag && (*stack_a)->flag != -1)
			{
				if ((*stack_a)->order == set->count)
					ft_bez_bileta_a(stack_a, set, 1);
				else if ((*stack_a)->next && (*stack_a)->next->order
					== set->count)
					ft_bez_bileta_a(stack_a, set, 2);
				else
				{
					ft_pb(stack_a, stack_b);
					set->len_a--;
					set->len_b++;
				}
			}
		}
	}
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b, t_set *set)
{
	(*stack_b)->flag = set->flags;
	ft_pa(stack_a, stack_b);
	set->len_b--;
	set->len_a++;
}

void	ft_big_sort_stack_b(t_stack **stack_a, t_stack **stack_b, t_set *set)
{
	int		max;
	int		mid;
	int		count;

	max = ft_find_max(stack_b);
	mid = (max - set->count) / 2 + set->count;
	set->flags++;
	count = set->len_b;
	while (set->len_b > 0)
	{
		if ((*stack_b)->order == set->count)
			ft_bez_bileta_b(stack_a, stack_b, set);
		else if ((*stack_b)->order > mid)
			ft_push_a(stack_a, stack_b, set);
		else
			ft_rb(stack_b);
		if (count == 0 && set->len_b != 0)
		{
			max = ft_find_max(stack_b);
			mid = (max - set->count) / 2 + set->count;
			count = set->len_b + 1;
			set->flags++;
		}
		count--;
	}
}

void	ft_big_sort(t_stack **stack_a, t_stack **stack_b, t_set *set)
{
	int	max;
	int	mid;
	int	i;

	max = set->len_a - 1;
	mid = max / 2;
	i = set->len_a;
	set->flags = 0;
	while (i > 0)
	{
		if ((*stack_a)->order > mid)
			ft_ra(stack_a);
		else
		{
			ft_pb(stack_a, stack_b);
			set->len_a--;
			set->len_b++;
		}
		i--;
	}
	ft_second_sort(stack_a, stack_b, set);
}
