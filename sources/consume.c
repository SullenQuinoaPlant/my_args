#include "inner.h"

static int			do_match(
	t_s_args_reg const *match,
	t_s_args_ps parsee)
{
	int		r;

	r = 0;
-	if (match->pre_effect &&
		(r = (*match->pre_effect)(match->pre_args, parsee)))
		r = r < ARGER_SUCCESS ? ARGS_SYS_ERR : ARGS_ARGER_ERROR;
	if (match->continue_pattern && !r)
		r = args_consume(rank + 1, match->continue_pattern, parsee);
	if (match->post_effect && !r &&
		(r = (*match->post_effect)(match->post_args, parsee)))
		r = r < ARGER_SUCCESS ? ARGS_SYS_ERR : ARGS_ARGER_ERROR;
	return (r);
}

static t_s_args_reg	*find_best_match(
	t_s_rbt const *tokens,
	t_s_args_ps *parsee)
{
	t_s_schk		try;
	t_s_args_reg	*tmp;
	t_s_args_reg	*match;
	int				r;
	
	match = 1;
	while (match)
	{
		match = 0;
		try = (t_s_schk){parsee->argp, 1};
		while ((r = rbtn_retrieve(&try, tokens, &tmp)) == RBT_SUCCESS)
		{
			match = tmp;
			try.len++;
		}
	}
	try.len--;
	if (match && *(parsee->argp += try.len - 1))
		parsee->argp++;
	return (match);
}

int					args_consume(
	int rank,
	t_s_rbt const *tokens,
	t_s_args_ps *parsee)
{
	t_s_args_reg	*match;
	int				r;

	if (rank == MAX_TOKEN_DEPTH)
		return (BAD_INPUT__TOO_DEEP);
	r = 0;
	while (parsee->argsi < parsee->argsc && !r &&
		(match = find_best_match(tokens, parsee)))
		r = do_match(match, parsee);	
	return (r);
}
