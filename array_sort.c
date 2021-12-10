/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:08:58 by breadyma          #+#    #+#             */
/*   Updated: 2021/12/09 18:44:53 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_order_four(t_stack **stack_a, t_stack **stack_b, int order)
{
	if (order == 0)
		ft_pb(stack_a, stack_b);
	else if (order == 1)
	{
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (order == 2)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (order == 3)
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		pos;
	int		min;
	int		i;

	tmp = *stack_a;
	min = tmp->num;
	i = 0;
	while (tmp)
	{
		if (min < tmp->num)
			tmp = tmp->next;
		else
		{
			min = tmp->num;
			pos = i;
			tmp = tmp->next;
		}
		i++;
	}
	ft_stack_order_four(stack_a, stack_b, pos);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (tmp->num > tmp->next->num && tmp->next->num > tmp->next->next->num)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (tmp->num > tmp->next->num && tmp->num > tmp->next->next->num)
		ft_ra(stack_a);
	else if (tmp->num < tmp->next->num && tmp->num > tmp->next->next->num)
		ft_rra(stack_a);
	else if (tmp->num > tmp->next->num && tmp->num < tmp->next->next->num)
		ft_sa(stack_a);
	else if (tmp->num < tmp->next->num && tmp->num < tmp->next->next->num)
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
}

int	ft_check_sort(int *num, int len)
{
	int	i;

	i = 0;
	while (i < (len - 1))
	{
		if (num[i] > num[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	*ft_sort(int *numbers, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (ft_check_sort(numbers, len) && len > 1)
	{
		if (numbers[i] > numbers[i + 1])
		{
			tmp = numbers[i];
			numbers[i] = numbers[i + 1];
			numbers[i + 1] = tmp;
		}
		i++;
		if (i == (len - 1))
			i = 0;
	}
	return (numbers);
}
