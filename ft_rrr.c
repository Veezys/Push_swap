/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:22:25 by breadyma          #+#    #+#             */
/*   Updated: 2021/12/09 18:34:09 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*prelast_a;
	t_stack	*tmp_b;
	t_stack	*prelast_b;

	prelast_a = *stack_a;
	prelast_b = *stack_b;
	while (prelast_a->next->next)
		prelast_a = prelast_a->next;
	while (prelast_b->next->next)
		prelast_b = prelast_b->next;
	tmp_a = prelast_a->next;
	tmp_b = prelast_b->next;
	prelast_a->next = NULL;
	prelast_b->next = NULL;
	tmp_a->next = *stack_a;
	tmp_b->next = *stack_b;
	*stack_a = tmp_a;
	*stack_b = tmp_b;
	write (1, "rrr\n", 4);
}

void	ft_chek_void(char **argv)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}
