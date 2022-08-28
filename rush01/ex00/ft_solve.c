/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:24:30 by soumanso          #+#    #+#             */
/*   Updated: 2021/09/12 21:56:33 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

static void	ft_swap(t_ui *a, t_ui *b)
{
	t_ui	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static t_ui	ft_permute(t_board *board, t_ui row, t_ui col)
{
	t_ui	i;

	if (row == BOARD_SIZE)
	{
		if (ft_sudoku_check (board) && ft_check_board (board))
		{
			ft_print_board (board);
			return (1);
		}
		return (0);
	}
	else
	{
		i = col;
		while (i < BOARD_SIZE)
		{
			ft_swap (&board->numbers[col][row], &board->numbers[i][row]);
			if (ft_permute (board, row, col + 1))
				return (1);
			if (ft_permute (board, row + 1, 0))
				return (1);
			ft_swap (&board->numbers[col][row], &board->numbers[i++][row]);
		}
	}
	return (0);
}

t_ui	ft_solve(t_board *board)
{
	int	col;
	int	row;

	row = 0;
	while (row < BOARD_SIZE)
	{
		col = 0;
		while (col < BOARD_SIZE)
		{
			board->numbers[col][row] = ((col + row) % BOARD_SIZE) + 1;
			col += 1;
		}
		row += 1;
	}
	return (ft_permute (board, 0, 0));
}
