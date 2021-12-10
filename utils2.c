/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:00:26 by breadyma          #+#    #+#             */
/*   Updated: 2021/12/09 15:58:14 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_order(t_stack **stack_a, t_stack **stack_b, int order)
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
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (order == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (order == 4)
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		min;
	int		pos;
	int		i;

	i = 0;
	tmp = *stack_a;
	min = tmp->num;
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
	ft_sort_order(stack_a, stack_b, pos);
	ft_sort_four(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_free_list(t_stack **stack)
{
	t_stack	*new;

	if (!(*stack))
		return ;
	while ((*stack))
	{
		new = (*stack)->next;
		free((*stack));
		*stack = new;
	}
	*stack = NULL;
}

t_stack	*ft_last(t_stack **stack)
{
	t_stack	*lst;

	lst = *stack;
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_add_back(t_stack **stack, t_stack *new)
{	
	t_stack	*lastlist;

	lastlist = ft_last(stack);
	if (*stack == NULL)
		*stack = new;
	else
		lastlist->next = new;
}
