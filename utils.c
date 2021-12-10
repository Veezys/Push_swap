/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:36:42 by breadyma          #+#    #+#             */
/*   Updated: 2021/12/09 18:34:02 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_sort_few(t_stack **stack_a, t_stack **stack_b, t_set *set)
{
	t_stack	*tmp;
	t_stack	*b;

	b = *stack_b;
	tmp = *stack_a;
	if (set->len_a == 2)
		ft_sa(stack_a);
	if (set->len_a == 3)
		ft_sort_three(stack_a);
	if (set->len_a == 4)
		ft_sort_four(stack_a, stack_b);
	if (set->len_a == 5)
		ft_sort_five(stack_a, stack_b);
	if (set->len_a > 5)
		ft_big_sort(stack_a, stack_b, set);
}

t_stack	*ft_createlist(int num)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = num;
	stack->flag = 0;
	stack->order = 0;
	stack->next = 0;
	return (stack);
}

void	fullstack(t_stack **stack, int *nums, int len)
{
	int		i;
	t_stack	*new;
	t_stack	*lst;

	lst = *stack;
	i = 1;
	while (i < len)
	{
		new = ft_createlist(nums[i]);
		ft_add_back(&lst, new);
		i++;
	}
}

void	ft_order(t_stack **stack, int *sortnums, int len)
{
	int		i;
	t_stack	*new;

	new = *stack;
	i = 0;
	while (new)
	{
		i = 0;
		while (i < len)
		{
			if (sortnums[i] == new->num)
			{
				new->order = i;
				new = new->next;
				break ;
			}
			i++;
		}
	}
}

void	ft_stack_list(int *nums, int len)
{
	t_stack	*stack;
	t_stack	*stack_b;
	t_set	set;
	int		i;
	int		*sortnums;

	set.count = 0;
	i = 0;
	set.len_a = len;
	set.len_b = 0;
	set.len = len;
	stack_b = NULL;
	stack = ft_createlist(nums[0]);
	fullstack(&stack, nums, len);
	sortnums = ft_sort(nums, len);
	ft_order(&stack, sortnums, len);
	ft_stack_sort_few(&stack, &stack_b, &set);
	free(sortnums);
	ft_free_list(&stack);
	ft_free_list(&stack_b);
}
