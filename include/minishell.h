/*
** EPITECH PROJECT, 2020
** Code_cd
** File description:
** my_cd
*/

#ifndef MY_CD_H_
    #define MY_CD_H_
    #include "my.h"
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/wait.h>
    #include <stddef.h>
    #include <stdbool.h>

    #define COMMANDS {"cd", "pwd", "ls"}
    #define POINTEUR {int (*pt)(int) = &ok, "ok2", "ok3"}

void my_pwd(char const *line);
char *parse_path(char *path);
int my_ls(char **env, char **argv);
char *my_strcopy(char *str);
char *search_command(char **env, char *line_env, int to_cmp);
char *parse_path_for_ls(char *path);

typedef struct ls_path {
    int test;
    int i;
    int j;
    int s;
    char *path;
    char *parse_path;
} ls_path_t;

typedef struct linked_list {
    char *env;
    int nodes;
    struct linked_list *next;
} linked_list_l;

typedef struct path_command {
    char *path;
    char *good_path;
    bool command;
} path_command_t;

typedef struct tree_s {
    void *data;
    struct tree_s *left;
    struct tree_s *right;
} tree_t;

void my_cd(const char *path, char **env, linked_list_l *menv);
int limitp(char a, char *limit);
int check_operators(char *buffer, char *sep);
char **str_to_tab(linked_list_l *env);
linked_list_l *create_list(char **env);
void add_node_at_back(linked_list_l **env_in_list, char *env, int args);
void print_linked_list(linked_list_l *n_node);
void check_command(path_command_t *p_command, char const *line);
void execute_command(linked_list_l *menv, char const *line, char *p);
char *parse_line(char const *l);
char **str_to_word_tab(char const *line);
char *my_strcat_sec(char *dest, char const *src);
int without_space(char const *line, int i);
char *parse_my_line(char const *line);
int instr(char *s, char c);
int nb_lines(char *str, char *sep);
char **str_to_array(char *str, char *separator);
void separator_cmd(char *line, linked_list_l *my_env);
void my_command(char const *l, linked_list_l *menv);
int instr(char *s, char c);
void other_command(char const *line, linked_list_l *menv);
char *parse_left_env(char const *str);
char *my_strcat(char *dest, char const *str);
char *f_strcat(char *dest, char const *str);
void remove_node(linked_list_l **list, char *data);
char *add_equal(char *params);
char *fill_line_env(char **params);
int cpt_params(char **params);
int check_operators(char *buffer, char *sep);
char **parse_operators(char *buffer, char *sep);
char *creat_parse_line(char *str, char **cmd);
void display_error(int nb);
int my_isalpha(char c);
void change_old_pwd(linked_list_l **menv, char *my_pwd);
tree_t *create_tree(void *data);
void add_branch(tree_t **tree, tree_t *branch);
int get_tree_depth(tree_t **tree);
void in_order_browsing(tree_t **tree, int layer);
void pre_order_browsing(tree_t **tree, int layer);
void post_order_browsing(tree_t **tree, int layer);

#endif /* !MY_CD_H_ */
