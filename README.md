Type help for instructions on how to use fish
egarlasc@c3r6s7 ~/p/42_libft (main)> cd
egarlasc@c3r6s7 ~> cd Desktop/
egarlasc@c3r6s7 ~/Desktop> ll
Permissions Size User     Date Modified Name
drwxr-xr-x     - egarlasc 28 May 13:48  cao
drwxr-xr-x     - egarlasc 28 May 12:00  libftvog
drwxr-xr-x     - egarlasc 28 May 13:37  nnsisamai
.rw-r--r--   46k egarlasc 26 May 17:20  libft.c
.rwxr-xr-x  1.1k egarlasc 12 Apr 18:04  PrismLauncher
.rw-r--r--  9.4k egarlasc 28 May 13:47  README(1).md
egarlasc@c3r6s7 ~/Desktop> cat README\(1\).md
*This project has been created as part of the 42 curriculum by egarlasc.*

---

# libft

## Description

**libft** is the foundational project of the 42 curriculum. Its goal is to build a personal C library by

The library is compiled as a static archive (`libft.a`) and can be linked to any future project in place

The project is split into three parts:

- **Part 1** — Re-implementations of standard libc functions (memory, strings, character checks).
- **Part 2** — Additional utility functions not found in libc (split, join, map, output to fd, etc.).
- **Part 3** — A complete linked-list module built around the `t_list` type.

---

## Instructions

### Requirements

- A C compiler: `cc` (or `gcc` / `clang`)
- GNU `make`

### Compilation

Clone the repository and navigate into it, then run:

```bash
# Compile the mandatory part
make

# Clean object files
make clean

# Remove object files and the archive
make fclean

# Rebuild everything from scratch
make re
```

This produces `libft.a` in the project root.

### Linking to another project

```bash
cc main.c -L. -lft -I. -o my_program
```

Or, inside another project's Makefile:

```makefile
LIBFT_DIR = path/to/libft

$(LIBFT_DIR)/libft.a:
        make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
        $(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
```

### Usage in code

```c
#include "libft.h"

int main(void)
{
    char *s = ft_strdup("Hello, 42!");
    ft_putendl_fd(s, 1);
    free(s);
    return (0);
}
```

---

## Library Description

### File overview

```
libft/
├── libft.h          # Header — all prototypes and the t_list struct
├── Makefile
└── ft_*.c           # One source file per function
```

### Part 1 — Libc re-implementations

#### Character checks & conversions

| Function | Prototype | Description |
|---|---|---|
| `ft_isalpha` | `int ft_isalpha(int c)` | Returns non-zero if `c` is a letter |
| `ft_isdigit` | `int ft_isdigit(int c)` | Returns non-zero if `c` is a decimal digit |
| `ft_isalnum` | `int ft_isalnum(int c)` | Returns non-zero if `c` is alphanumeric |
| `ft_isascii` | `int ft_isascii(int c)` | Returns non-zero if `c` fits in the ASCII set (0–127) |
| `ft_isprint` | `int ft_isprint(int c)` | Returns non-zero if `c` is a printable character |
| `ft_toupper` | `int ft_toupper(int c)` | Converts `c` to uppercase; returns `c` unchanged if not a lett
| `ft_tolower` | `int ft_tolower(int c)` | Converts `c` to lowercase; returns `c` unchanged if not a lett

#### Memory functions

| Function | Prototype | Description |
|---|---|---|
| `ft_memset` | `void *ft_memset(void *s, int c, size_t n)` | Fills the first `n` bytes of `s` with byte
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Sets the first `n` bytes of `s` to zero |
| `ft_memcpy` | `void *ft_memcpy(void *dst, const void *src, size_t n)` | Copies `n` bytes from `src` to
| `ft_memmove` | `void *ft_memmove(void *dst, const void *src, size_t n)` | Copies `n` bytes from `src` t
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Returns a pointer to the first occurr
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares the first `n` bytes
| `ft_calloc` | `void *ft_calloc(size_t count, size_t size)` | Allocates `count * size` zero-initialised

#### String functions

| Function | Prototype | Description |
|---|---|---|
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Returns the number of characters before the null term
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | Copies `src` into `dst` w
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | Appends `src` to `dst`, b
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | Finds the first occurrence of `c` in `s` |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Finds the last occurrence of `c` in `s` |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Lexicographically compares
| `ft_strnstr` | `char *ft_strnstr(const char *h, const char *n, size_t len)` | Locates substring `n` in
| `ft_strdup` | `char *ft_strdup(const char *s)` | Returns a malloc'd copy of `s` |
| `ft_atoi` | `int ft_atoi(const char *str)` | Converts the initial portion of `str` to an `int` |

---

### Part 2 — Additional utility functions

#### String utilities

| Function | Prototype | Description |
|---|---|---|
| `ft_substr` | `char *ft_substr(const char *s, unsigned int start, size_t len)` | Returns a malloc'd sub
| `ft_strjoin` | `char *ft_strjoin(const char *s1, const char *s2)` | Returns a malloc'd string that is t
| `ft_strtrim` | `char *ft_strtrim(const char *s1, const char *set)` | Returns a malloc'd copy of `s1` wi
| `ft_split` | `char **ft_split(const char *s, char c)` | Splits `s` by delimiter `c`; returns a NULL-ter
| `ft_itoa` | `char *ft_itoa(int n)` | Returns a malloc'd string representing the integer `n` |
| `ft_strmapi` | `char *ft_strmapi(const char *s, char (*f)(unsigned int, char))` | Applies `f` to each c
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | Applies `f` to each char

#### Output to file descriptor

| Function | Prototype | Description |
|---|---|---|
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Writes character `c` to file descriptor `fd` |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Writes string `s` to file descriptor `fd` |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Writes string `s` followed by a newline to `f
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Writes integer `n` to file descriptor `fd` |

---

### Bonus — Linked list module

All bonus functions operate on the following type, defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

`content` holds a pointer to any data; `next` points to the following node (or `NULL` at the end).

| Function | Prototype | Description |
|---|---|---|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Allocates and returns a new node |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Inserts `new` at the beginning of the list |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Appends `new` at the end of the list |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | Returns the number of nodes in the list |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Returns the last node |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees the node's content with `del`, then frees the node |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes and frees every node in the list |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Applies `f` to the content of every node |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Returns a new list built by applying `f` to each node's content |

---

## Resources

### Documentation & references

- [C standard library reference — cppreference.com](https://en.cppreference.com/w/c)
- [The C Programming Language, 2nd ed. — Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language)
- [Linux man pages — man7.org](https://man7.org/linux/man-pages/)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- [Understanding static libraries in C](https://www.cs.dartmouth.edu/~campbell/cs50/buildlib.html)

### Articles & tutorials

- [Memory layout of C programs — GeeksforGeeks](https://www.geeksforgeeks.org/memory-layout-of-c-program/)
- [Linked lists in C — Learn-C.org](https://www.learn-c.org/en/Linked_lists)
- [Makefile tutorial — makefiletutorial.com](https://makefiletutorial.com)

### Use of AI

AI assistance (Claude by Anthropic) was used during this project for the following purposes:

- **Debugging**: identifying subtle edge cases (e.g. integer overflow in `ft_atoi`, overlap handling in `ft_memmove`).
- **Understanding behaviour**: clarifying the expected output of certain libc functions by cross-referencing man pages and asking questions in plain language.
- **This README**: the structure and content of this file were produced with AI assistance.

All code was written and reviewed manually in accordance with the 42 Norm. AI was not used to generate any `.c` or `.h` files submitted as part of the project.
