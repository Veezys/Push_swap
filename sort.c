/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:28:52 by breadyma          #+#    #+#             */
/*   Updated: 2021/12/08 20:06:15 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	write (1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b == NULL || ((*stack_b)->next == NULL))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	write (1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (*stack_a == NULL || *stack_b == NULL || (*stack_b)->next == NULL
		|| (*stack_a)->next == NULL)
		return ;
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	*stack_a = (*stack_a)->next;
	tmp_a->next = (*stack_a)->next;
	(*stack_a)->next = tmp_a;
	*stack_b = (*stack_b)->next;
	tmp_b->next = (*stack_b)->next;
	(*stack_b)->next = tmp_b;
	write (1, "ss\n", 3);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_a == NULL)
	{
		tmp->next = NULL;
		*stack_a = tmp;
	}
	else
	{
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	write (1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_b == NULL)
	{
		tmp->next = NULL;
		*stack_b = tmp;
	}
	else
	{
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	write (1, "pb\n", 3);
}
