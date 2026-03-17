#ifndef	MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <termcap.h>
#include <readline/readline.h>
#include <readline/history.h>
// < infile grep . | < infile > outfile wc -l < infile2 > outfile2 | wc -l > outfile
typedef enum	e_token_type
{
    WORD,
    PIPE,
    REDIR_OUT_TRUNCT, 	// >
    REDIR_OUT_APPEND,	// >>
    REDIR_IN,			// <
    HEREDOC,			// <<
	ENVIRONMENT,
}				t_token_type;

typedef struct	s_token
{
    char            *value;
    t_token_type    type;
    struct s_token  *next;
	int				fd;
}				t_token;

typedef struct	s_exec_info
{
	char	*str;
	t_token	*start;
	t_token	*end;
	int		fd_in;
	int		fd_out;
	int		command_number;
}				t_exec_info;

typedef struct s_data
{
	int		**pipes;
	pid_t	*pids;
	char	**envp;
}	t_data;

//free.c
void	ft_free_arr(void **array);
void	ft_free_r(void **array, int i);

//pipes.c
int	ft_find_pipes(t_token *head);
int ft_create_pipes_and_pids(int number, t_data *data);
int ft_setup_pipes(t_data *data, int nmb_of_pipes, int i);

//dummy.c
t_token	*ft_get_head();
t_token	*create_token(char *value, t_token_type type, int fd);

//helper.c
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);

//childs.c
int	ft_child_process(t_token *head, t_data *data, int nmb_of_pipes, int i);

//split.c
char	**ft_split(const char *str, char c);

//ft_strjoin.c
char	*ft_strjoin(char const *s1, char const *s2);

//redirection.c
int ft_handle_in(int *fd_in, t_token *curr);
int ft_handle_in_heredoc(int *fd_in, t_token *curr);
int ft_handle_out_app(int *fd_out, t_token *curr);
int ft_handle_out_trunc(int *fd_out, t_token *curr);
int ft_apply_redirection(int *fd_in, int *fd_out, t_token *curr, char **str);

//executable.c
char *ft_relative_executable(char *command);
char *ft_make_executable(char *executable, char **envp);
#endif