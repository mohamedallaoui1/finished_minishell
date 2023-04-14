/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallaoui <mallaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 01:41:56 by aerraoui          #+#    #+#             */
/*   Updated: 2023/04/14 03:37:50 by mallaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	ft_export2(int flag, t_list *env, char **p)
{
	int	i;
	int	j;

	i = 1;
	while (p[i])
	{
		j = ft_check_export(p[i]);
		if (j == 0)
		{
			ft_printf(2, "bash: export: `%s': not a valid identifier\n", p[i]);
			flag = 1;
			i++;
		}
		else
			exportwork(p[i++], j, env);
	}
	return (flag);
}

int	ft_cd2(int fd, int check, char **p, t_list *env)
{
	char	*home;
	char	pwd[1024];

	(void)fd;
	(void)p;
	home = gethome(env);
	getcwd(pwd, sizeof(pwd));
	if (home)
		return (free(home), ft_changedir(&env, home, pwd));
	else
	{
		(ft_printf(2, "bash: cd: HOME not set\n"), g_glob.exit_status = 1);
		if (check)
			exit(g_glob.exit_status);
		return (free(home), -2);
	}
}

void	normfunc(t_list **node, char *old)
{
	t_list	*head;

	head = *node;
	if (head->cont)
		free(head->cont);
	free(head->content);
	head->cont = ft_strdup(old);
	head->content = ft_join("OLDPWD=", old);
}

void	delet_node(char *p, t_list **env)
{
	t_list	*prec;
	t_list	*cournt;

	cournt = *env;
	if (!ft_cmp(p, cournt->name))
	{
		prec = cournt;
		cournt = cournt->next;
		ft_lstdelone1(prec, free);
		return ;
	}
		prec = cournt;
		cournt = cournt->next;
	while (cournt)
	{
		if (!ft_cmp(p, cournt->name))
		{
			prec->next = cournt->next;
			ft_lstdelone1(cournt, free);
			return ;
		}
		prec = cournt;
		cournt = cournt->next;
	}
}
