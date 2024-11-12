#ifndef ENV_H
#define ENV_H

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
} t_env;

// Declaraciones de funciones
t_env *init_env(char **envp);
void add_env_var(t_env **env_list, char *key, char *value);
char *get_env_var(t_env *env_list, char *key);
void update_env_var(t_env **env_list, char *key, char *value);
void remove_env_var(t_env **env_list, char *key);
void free_env(t_env *env_list);
int		env_lstsize(t_env *lst);

#endif // ENV_H

