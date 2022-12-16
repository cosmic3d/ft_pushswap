/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:01:07 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/16 20:50:35 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

//|--------------BRING LIBRARIES--------------|

# include "../lib/ft_libft/libft.h"
# include "../lib/ft_printf/inc/ft_printf.h"
# include <unistd.h>
# include <limits.h>

//|--------------MOVEMENT MACROS--------------|

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

//|--------------STACK AND NODE STRUCTURES--------------|

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

//|--------------INPUT CHECKING--------------|
int		check_input(char **str, int argc);
int		check_digits(char**str);
int		check_int(char **s);
int		check_limits_when_10(char *str, int sign);
int		check_dups(char	**s, int argc);
//|--------------INIT STACKS--------------|
int		ft_init_a(t_stack *a, int len, char **s);
int		ft_init_b(t_stack *b);
int		ft_stack_values(t_stack *stack, int len, char id);
t_node	*ft_newnode(int nbr, int ind);
//|--------------MOVEMENT FUNCS--------------|
void	swap(t_stack *stack);
void	swap_a(t_stack *a, t_stack *b);
void	swap_b(t_stack *a, t_stack *b);
void	swapswap(t_stack *a, t_stack *b);
void	push(t_stack *dest, t_stack *ori);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	rotate_a(t_stack *a, t_stack *b);
void	rotate_b(t_stack *a, t_stack *b);
void	rotaterotate(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_a(t_stack *a, t_stack *b);
void	reverse_rotate_b(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
//|--------------UTILS FUNCS--------------|
void	empty_stack(t_stack *stack);
int		empty_stacks(t_stack *a, t_stack *b);
void	first_last(t_node *node_a, t_stack *a, t_node *node_b, t_stack *b);
int		ft_error(t_stack *a, t_stack *b);
int		ft_is_ordered(t_stack *stack);
//|--------------DEBUGGING FUNCS--------------|
void	debug_stack(t_stack *stack);
//|--------------ALGORITHM--------------|
void	algorithm(t_stack *a, t_stack *b);
//|--------------FIVE RANDOM NUMBERS ALGORITHM--------------|
void	three_random(t_stack *a, t_stack *b);
void	five_random(t_stack *a, t_stack *b);
//|--------------LOCATE NODES--------------|
int		check_smaller(t_stack *stack, int exclude);
int		check_bigger(t_stack *stack, int exclude);
//|--------------SIMULATION FUNCS--------------|
int		how_many_moves(int index, int len);
int		both_moves(int closer1, int closer2, int len);
void	which_pair(t_stack *a);
#endif
