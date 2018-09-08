#ifndef INNER_H
# define INNER_H

# include "myargs.h"
# include "libmyrbtree.h"

typedef struct				s_token {
	t_args_arger	pre_effect,
	void			*pre_args;
	t_s_rbt			*continue_pattern;
	t_args_arger	post_effect;
	void			*post_args;
}							t_s_tk;

typedef struct				s_string_chunk {
	char	*cs;
	size_t	len;
}							t_s_schk;

/*
**limits parsing recursion :
*/
# define MAX_TOKEN_DEPTH 30

# define BAD_INPUT__TOO_DEEP 1
# define BAD_INPUT__NO_MATCH 2

# define ARGER_SUCCESS 0

int					consume(
	t_s_rbt		*parse_tree,
	t_s_args_ps *parsee
	t_args_ef	*p_ef);

int					init(
	t_s_args_reg	*reg_str,
	t_s_rbt			*p_ret);

int					register(
	t_s_args_reg const	*tk_str,
	t_s_rbt				*p_ret);

int					tear_down(
	t_s_rbt		*parse_tree);

#endif
