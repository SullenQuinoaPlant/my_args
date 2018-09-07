#ifndef MYARGS_H
# define MYARGS_H

/*
** modify :
** t_args_ef
** in myargs_t_appease.h if wanted.
** defaults to (void*)
*/
# include "myargs_t_appease.h"

/*
**t_s_aaps:
** args: all args array, as passed to main
** argsc: all args count, aspassed to main
** argsi: index of current argument
** argi: index of first unused char within string of current argument
*/
typedef struct		s_args_arg_parse_state {
	char		*args[];
	int			argsc;
	int			argsi;
	char		*argi;
}					t_s_args_ps;

/*
**t_a_arger:
** return < 0 on system errors,
** 0 on success,
** > 0 on our errors
*/
typedef int			(*t_args_arger)(
	t_s_aaps *parse_state,
	void *foo_args,
	t_args_ef *effects);

typedef struct		s_args_register_token {
	char			*pattern;
	t_args_arger	pre_effect;
	void			*pre_args;
	t_s_rbt			*continue_parse;
	t_args_arger	post_effect;
	void			*post_args;
}					t_s_args_reg;

/*
**functions:
*/

int					args_register(
	t_s_args_reg	tokens[],
	size_t			ar_sz,
	t_s_rbt			*p_ret);

int					args_consume(
	t_s_rbt *tokens,
	t_s_args_ps *parsee);

dif
