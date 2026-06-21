/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_collect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:00:35 by chgomez           #+#    #+#             */
/*   Updated: 2026/02/16 14:32:18 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	collect_heredocs(t_cmd *cmds, t_data *data)
{
	t_redir	*redir;

	while (cmds)
	{
		redir = cmds->redirs;
		while (redir)
		{
			if (redir->type == redir_heredoc)
			{
				redir->fd = handle_heredoc(redir->file,
						redir->quoted, data);
				if (redir->fd < 0)
					return (-1);
			}
			redir = redir->next;
		}
		cmds = cmds->next;
	}
	return (0);
}
