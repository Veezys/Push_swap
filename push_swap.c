/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:32:09 by breadyma          #+#    #+#             */
/*   Updated: 2021/12/09 18:33:14 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_repeat(int	*numbers, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < len)
	{
		j = 1;
		j += i;
		while (j < len)
		{
			if (numbers[i] == numbers[j])
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int	*ft_translate(char **array)
{
	int		i;
	int		*numbers;
	int		len;

	i = 0;
	len = 0;
	while (array[i])
		i++;
	numbers = (int *)malloc(sizeof(int) * i);
	i = -1;
	while (array[++i])
		numbers[i] = ft_atoi(array[i]);
	if (ft_check_sort(numbers, i) == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	ft_check_repeat(numbers, i);
	return (numbers);
}

void	ft_check(char *stack)
{
	int		i;

	i = 0;
	while (stack[i])
	{
		if (ft_isdigit(stack[i]) != 1 && stack[i] != ' '
			&& stack[i] != '\0' && stack[i] != '-')
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		else
			i++;
	}
}

char	*ft_connect(char **argv, int argc)
{
	int		i;
	char	*args;

	i = 1;
	args = ft_strdup(argv[i]);
	if (argc > 2)
	{
		i = 2;
		while (argv[i])
		{
			args = ft_strjoin(args, " ");
			args = ft_strjoin(args, argv[i]);
			i++;
		}
	}
	return (args);
}

int	main(int argc, char **argv)
{
	char			*stack;
	char			**array;
	int				i;
	int				*nums;

	if (argc > 1)
	{
		ft_chek_void(argv);
		stack = ft_connect(argv, argc);
		ft_check(stack);
		array = ft_split(stack, ' ');
		free(stack);
		i = 0;
		nums = ft_translate(array);
		while (array[i])
			free(array[i++]);
		free(array);
		ft_stack_list(nums, i);
	}
	return (0);
}
