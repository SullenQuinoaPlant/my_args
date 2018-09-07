#ifndef MYARGS_H
# define MYARGS_H

/*
** modify :
** t_args_public_pointer_effective_arg_side_effects t_appease
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
}					t_s_aaps;

/*
**t_a_arger:
** return < 0 on system errors,
** 0 on success,
** > 0 on our errors
*/
typedef int			(*t_a_arger)(t_s_aaps *parse_state, t_appease *arg_effects);

typedef struct		s_args_register_argument_type {
	char		*name;
	t_aarger	affect;

}					t_s_a_rat;



#endif
