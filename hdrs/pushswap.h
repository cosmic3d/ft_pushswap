/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:01:07 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/29 14:31:30 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../lib/ft_libft/libft.h"
# include "../lib/ft_printf/inc/ft_printf.h"
# include <unistd.h>
# include <limits.h>

# define PA		(char *)"pa\n"
# define PB		(char *)"pb\n"
# define SA		(char *)"sa\n"
# define SB		(char *)"sb\n"
# define SS		(char *)"ss\n"
# define RA		(char *)"ra\n"
# define RB		(char *)"rb\n"
# define RR		(char *)"rr\n"
# define RRA	(char *)"rra\n"
# define RRB	(char *)"rrb\n"
# define RRR	(char *)"rrr\n"

typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*next;
	struct s_node	*back;
}t_node;

typedef struct s_stack
{
	int		len;
	t_node	*first;
	t_node	*last;
	char	id;
}t_stack;

int		check_input(char **str, int argc);
int		check_digits(char**str);
int		check_int(char **s);
int		check_limits_when_10(char *str, int sign);
int		check_dups(char	**s, int argc);
void	ft_init_a(t_stack *a, int len, char **s);
void	ft_init_b(t_stack *b);
t_node	*ft_newnode(int nbr, int ind);
void	swap(t_stack *stack);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swapswap(t_stack *a, t_stack *b);
void	push(t_stack *dest, t_stack *ori);
void	empty_stack(t_stack *stack);
void	reset_node(t_node *node);
void    first_last(t_node *node, t_stack *stack);
void	debug_stack(t_stack *stack);
void	rotate(t_stack *stack);
void	rotaterotate(t_stack *a, t_stack *b);
void    reverse_rotate(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);

#endif
