/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:27:38 by breadyma          #+#    #+#             */
/*   Updated: 2021/12/08 19:23:53 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	last = ft_last(stack);
	*stack = (*stack)->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	last = ft_last(stack);
	*stack = (*stack)->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*last_a;
	t_stack	*last_b;
	t_stack	*tmp_b;

	if (*stack_a == NULL || *stack_b == NULL || (*stack_b)->next == NULL
		|| (*stack_a)->next == NULL)
		return ;
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	last_a = ft_last(stack_a);
	last_b = ft_last(stack_b);
	*stack_a = (*stack_a)->next;
	last_a->next = tmp_a;
	tmp_a->next = NULL;
	*stack_b = (*stack_b)->next;
	last_b->next = tmp_b;
	tmp_b->next = NULL;
	write (1, "rr\n", 3);
}

void	ft_rra(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*prelast;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	prelast = *stack;
	while (prelast->next->next)
		prelast = prelast->next;
	tmp = prelast->next;
	prelast->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*prelast;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	prelast = *stack;
	while (prelast->next->next)
		prelast = prelast->next;
	tmp = prelast->next;
	prelast->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	write(1, "rrb\n", 4);
}
