/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:46:48 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/13 08:46:59 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 *	creation d un nouveau token
 */

static t_token	*ft_create_token(e_token type, char *value)
{
	t_token	*new;

	new = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);	// exit faillure avec message error malloc
	new->type = type;
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

/*
 *	ajout du token a la liste chainee
 */

void	ft_append_token(t_token **head, e_token type, char *value)
{
	t_token *new;
	t_token	*current;

	new = ft_create_token(type, value);
	if (!head)
		return ;
	if (!*head)
		*head = new;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}