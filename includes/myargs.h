#ifndef MYARGS_H
# define MYARGS_H

/*
** modify :
** t_args_ef
** in myargs_t_appease.h if wanted.
** defaults to (void*)
*/
# include "myargs_t_args_ef.h"

/*
**t_s_args_ps:
** args: all args array, as passed to main
** argsc: all args count, as passed to main
** argsi: index of current argument
** argp: pointer to first unused char within string of current argument
*/
typedef struct		s_args_arg_parse_state {
	char		*args[];
	int			argsc;
	int			argsi;
	char		*argp;
	t_s_args_ef	*effects;
}					t_s_args_ps;

/*
**t_a_arger:
** return < 0 on system errors,
** 0 on success,
** > 0 on our errors
*/
typedef int			(*t_args_arger)(
	void *foo_args,
	t_s_args_ps *parse_state);

typedef struct		s_args_register_token {
	char const		*pattern;
	t_args_arger	pre_effect;
	void			*pre_args;
	t_s_args_reg	*continue_pattern_str;
	t_args_arger	post_effect;
	void			*post_args;
}					t_s_args_reg;

/*
**functions:
*/

int					args_process_input(
	int					argc,
	char				*argv[],
	t_s_args_reg const	*register_tokens_str,
	t_args_ef			*p_ef);

# define ARGS_SYS_ERR -1
# define ARGS_SUCCESS 0
# define ARGS_BAD_INPUT 1
# define ARGS_ARGER_ERROR 2

#endif
