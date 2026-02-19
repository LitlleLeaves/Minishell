typedef enum e_token_type
{
    WORD,
    PIPE,
    REDIR_OUT,
    REDIR_APPEND,
    REDIR_IN,
    HEREDOC
} t_token_type;

typedef struct s_token
{
    char            *value;
    t_token_type    type;
    struct s_token  *next;
} t_token;

