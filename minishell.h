#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>
# include <setjmp.h>
# include "libft.h"

# include <stdio.h> //!!!!!!

# define IS_TRUE 1
# define CWD_BUF_SIZE 1024
# define BUILTIN_NUM 2

static sigjmp_buf 				sig_env;
static volatile sig_atomic_t	jmp_flag = 0;

typedef struct s_minishell	t_minishell;

typedef void (*builtin_func) (t_minishell *);

struct		 		s_minishell
{
	int				argc;
	char			*line;
	char			**args;
	char			**cmds;
	char			*cmd_path;
	char			*home;
	char			*oldpwd;
	char			**env;
	char			**builtin_name;
	builtin_func	*funct_tab;
};


void		builtin_cd(t_minishell *msh);
void		builtin_exit(t_minishell *msh);

#endif
