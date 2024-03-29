/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:01:07 by jenavarr          #+#    #+#             */
/*   Updated: 2023/02/03 19:03:32 by jenavarr         ###   ########.fr       */
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
	int				final_index;
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
void	swap_s(t_stack *dest, t_stack *ori);
void	swapswap(t_stack *a, t_stack *b);
void	choose_swap(t_stack *a, t_stack *b);
void	push(t_stack *dest, t_stack *ori);
void	push_s(t_stack *dest, t_stack *ori);
void	how_push(t_stack *dest, t_stack *ori, int node, int brother);
void	rotate(t_stack *stack);
void	rotate_s(t_stack *dest, t_stack *ori);
void	rotaterotate(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_s(t_stack *dest, t_stack *ori);
void	rrr(t_stack *a, t_stack *b);
//|--------------UTILS FUNCS--------------|
void	empty_stack(t_stack *stack);
int		empty_stacks(t_stack *a, t_stack *b);
void	first_last(t_node *node_a, t_stack *a, t_node *node_b, t_stack *b);
int		ft_error(t_stack *a, t_stack *b);
int		ft_is_ordered(t_stack *stack);
//|--------------DEBUGGING FUNCS--------------|
void	debug_stack(t_stack *stack);
void	debug_simulation(t_stack *a);
void	debug_node(t_node *n);
int		debug_error(t_stack *stack, int node);
//|--------------ALGORITHM--------------|
void	algorithm(t_stack *a, t_stack *b);
//|--------------LOCATE NODES--------------|
t_node	*get_node(t_stack *s, int index);
int		smaller_1(t_stack *stack, int exclude);
int		bigger_1(t_stack *stack, int exclude);
t_node	*closer_1(int one, int two, t_stack *s, int inverted);
t_node	*get_num_in_pos(t_stack *s, int pos);
int		next_1(t_stack *s, int index);
int		prev_1(t_stack *s, int index);
t_node	*closers_1(t_stack *s, t_node *biggest);
//|--------------SIMULATION FUNCS--------------|
int		how_many_moves(int index, int len);
int		both_moves(int closer1, int closer2, int len);
void	reindex(t_stack *s);
void	finalindexation(t_stack *s);
//|--------------CASES FUNCS--------------|
int		few_swap(t_stack *a, t_stack *b);
int		few_rotate(t_stack *a, t_stack *b, t_node *smaller);
int		do_rotate(t_stack *a, t_stack *b, int index);
//|--------------MATH FUNCS--------------|
int		ft_abs(int num);
int		v(t_stack *s, int index);
//|--------------FIVE RANDOM NUMBERS ALGORITHM--------------|
void	choose_pushes(t_stack *a, t_stack *b, int s1, int b1);
void	three_random(t_stack *a, t_stack *b);
void	five_random(t_stack *a, t_stack *b, int closer_one);
//|--------------ONE HUNDRED RANDOM NUMBERS ALGORITHM--------------|
void	one_hundred_random(t_stack *a, t_stack *b, int chunk_size);
void	send_to_b(t_stack *a, t_stack *b, t_node *t, int csize);
void	back_to_a(t_stack *a, t_stack *b, int b1, int b2);
// void	smallest_first(t_stack *a, t_stack *b, t_node *t2, t_node *t3);
// void	smallest2_first(t_stack *a, t_stack *b, t_node *t2, t_node *t3);
void	sort_top(t_stack *a, t_stack *b, int s1);
void	sort_top_2(t_stack *a, t_stack *b, int s1);
#endif
