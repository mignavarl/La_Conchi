#include "env.h"
#include <stdlib.h>
#include <string.h>

// Implementación de las funciones

t_env *init_env(char **envp)
{
    t_env *env_list = NULL;
    int i = 0;

    while (envp[i])
    {
        char *equal_sign = strchr(envp[i], '=');
        if (equal_sign)
        {
            t_env *new_env = malloc(sizeof(t_env));
            new_env->key = strndup(envp[i], equal_sign - envp[i]);
            new_env->value = strdup(equal_sign + 1);
            new_env->next = env_list;
            env_list = new_env;
        }
        i++;
    }
    return env_list;
}

void add_env_var(t_env **env_list, char *key, char *value)
{
    t_env *new_var = malloc(sizeof(t_env));
    new_var->key = strdup(key);
    new_var->value = strdup(value);
    new_var->next = *env_list;
    *env_list = new_var;
}

char *get_env_var(t_env *env_list, char *key)
{
    while (env_list)
    {
        if (strcmp(env_list->key, key) == 0)
            return env_list->value;
        env_list = env_list->next;
    }
    return NULL;
}

void free_env(t_env *env_list)
{
    t_env *tmp;
    while (env_list)
    {
        tmp = env_list;
        env_list = env_list->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
    }
}
