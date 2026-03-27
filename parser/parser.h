#ifndef	MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stdbool.h>

typedef enum	e_token_type
{
    COMMAND,
    PIPE,
    REDIR_OUT_TRUNC, 	// >
    REDIR_OUT_APP,		// >>
    REDIR_IN,			// <
    HEREDOC,			// <<

	ENVIRONMENT,
}				t_token_type;

typedef struct	s_token
{
    char            *value;
    t_token_type    type;
    struct s_token  *next;
}				t_token;


//main
int		main_loop(void);

//read
char	*get_line(void);
char	*readline (const char *prompt);

//tokens
t_token	*classify_and_make(char *line);
t_token	*tokenize_input(char *str);
int		check_delimeters(char c);
t_token *if_redirection(int start, char *line, t_token_type type);
//t_token	*if_pipe(char *line);
t_token	*if_word(int start, char *line);
t_token	*make_new_token(char *value, t_token_type type);
int		index_to_next_delimetre(char *line, int index);

//ft_helpers
char	*ft_strdup(char const *str);
int		ft_strlen(char const *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *str, int start, int length);

//errorhandler

#endif