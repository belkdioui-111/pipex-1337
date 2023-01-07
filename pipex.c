/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:25:47 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/01/04 08:22:36 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pros(int *pipefd, char **argv, t_list *data)
{	
	int		check;
	char	**path;

	path = get_path(data->envp);
	check = 0;
	data->fd[0] = open(argv[1], O_RDONLY | O_CREAT, 0644);
	if (data->fd[0] == -1)
	{
		perror(ft_strjoin("pipex: ", argv[1]));
		exit(EXIT_FAILURE);
	}	
	if ((ft_strchr(argv[2], '\'')) || ft_strchr(argv[2], '\"'))
		check = exec_s_d_quotes_c(pipefd, data, path, argv[2]);
	if ((argv[2][0] == '.' && argv[2][1] == '/') || (argv[2][0] == '/'))
		exec_path_c(pipefd, data, argv[2]);
	check = exec_nor_cmd_c(argv[2], path, data, pipefd);
	free_all(path);
	if (check != 1)
		cmd_not_f(argv[2]);
}

void	parr_pro(int *pipefd, char **argv, t_list *data)
{
	int		check;
	char	**path;

	check = 0;
	path = get_path(data->envp);
	data->fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd[1] == -1)
	{
		perror(ft_strjoin("pipex: ", argv[4]));
		exit(EXIT_FAILURE);
	}
	if ((ft_strchr(argv[3], '\'')) || ft_strchr(argv[3], '\"'))
		check = exec_s_d_quotes_p(pipefd, data, path, argv[3]);
	if ((argv[3][0] == '.' && argv[3][1] == '/') || (argv[3][0] == '/'))
		exec_path_p(pipefd, data, argv[3]);
	check = exec_nor_cmd_p(argv[3], path, data, pipefd);
	free_all(path);
	if (check != 1)
		cmd_not_f(argv[3]);
}

void	my_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	int		pid;
	int		pipefd[2];
	t_list	data;

	data.envp = envp;
	if (argc != 5)
		my_exit("syntax : ./pipex file1 cmd1 cmd2 file2");
	if (pipe(pipefd) < 0)
		my_exit("./pipex: can not establish pipe");
	pid = fork();
	if (pid == -1)
		my_exit("./pipex: can not make child process");
	else if (pid == 0)
		child_pros(pipefd, argv, &data);
	else if (pid > 0)
		parr_pro(pipefd, argv, &data);
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
