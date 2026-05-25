/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:39:40 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/25 13:50:55 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
** is_sep — controlla se il carattere 'c' è uguale al separatore 'sep'.
** Ritorna 1 (vero) se c è il separatore, 0 (falso) altrimenti.
** Usata da alloc_word per sapere dove finisce una parola.
*/
static int	is_sep(char c, char sep)
{
	return (c == sep);
}

/*
** word_count — conta quante parole ci sono nella stringa 's',
** usando 'sep' come separatore.
**
** Funziona così:
**   - Salta tutti i separatori consecutivi (es: ",,,")
**   - Se trova un carattere non-separatore, è l'inizio di una parola → count++
**   - Avanza fino alla fine di quella parola
**   - Ripete finché non arriva a '\0'
**
** Esempio: "mela,,banana,pera" con sep=',' → ritorna 3
*/
static size_t	word_count(const char *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		/* Salta i separatori (anche multipli consecutivi) */
		while (s[i] == sep)
			i++;
		/* Se dopo i separatori siamo a fine stringa, usciamo */
		if (s[i] == '\0')
			break ;
		/* Abbiamo trovato l'inizio di una parola */
		count++;
		/* Avanziamo fino alla fine della parola */
		while (s[i] && s[i] != sep)
			i++;
	}
	return (count);
}

/*
** free_all — libera tutta la memoria allocata in caso di errore.
**
** Se malloc fallisce a metà del lavoro, abbiamo già allocato alcune stringhe.
** Questa funzione le libera tutte (da res[i] fino a res[0]),
** poi libera l'array stesso, e ritorna NULL.
**
** Parametri:
**   res → l'array di stringhe da liberare
**   i   → indice dell'ultima stringa allocata (inclusa)
*/
static void	*free_all(char **res, int i)
{
	while (i >= 0)
		free(res[i--]);
	free(res);
	return (NULL);
}

/*
** alloc_word — alloca e ritorna una copia della prossima parola in 'str'.
**
** Una "parola" va dall'inizio di 'str' fino al primo 'sep' (o a '\0').
** Non modifica 'str', lavora solo con indici/lunghezza.
**
** Esempio: str = "banana,pera", sep = ','
**          → alloca e ritorna "banana"
*/
static char	*alloc_word(const char *str, char sep)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = 0;
	/* Calcola la lunghezza della parola (fino al sep o a '\0') */
	while (str[len] && !is_sep(str[len], sep))
		len++;
	/* Alloca len+1 caratteri (il +1 è per il '\0' finale) */
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	/* Copia la parola carattere per carattere */
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0'; /* Terminatore della stringa */
	return (word);
}

/*
** ft_split — funzione principale.
**
** Prende una stringa 's' e la divide in un array di sottostringhe,
** usando il carattere 'c' come separatore.
**
** Ritorna:
**   - Un array di stringhe allocato dinamicamente, terminato da NULL
**   - NULL se 's' è NULL o se malloc fallisce
**
** Esempio:
**   ft_split("mela,banana,pera", ',')
**   → ["mela", "banana", "pera", NULL]
*/
char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	/* Alloca l'array: word_count parole + 1 slot per il NULL finale */
	res = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		/* Salta i separatori */
		while (*s == c)
			s++;
		/* Se siamo su un carattere valido, è l'inizio di una parola */
		if (*s)
		{
			res[i] = alloc_word(s, c);
			if (!res[i])
				return (free_all(res, i - 1)); /* malloc fallita: pulizia e NULL */
			i++;
			/* Avanza oltre la parola appena copiata */
			while (*s && *s != c)
				s++;
		}
	}
	res[i] = NULL; /* Terminatore dell'array */
	return (res);
}

/* ************************************************************************** */
/*                             MAIN DI TEST                                   */
/*                                                                            */
/* Uso: ./ft_split "stringa" "separatore"                                     */
/* Il separatore deve essere un singolo carattere.                             */
/*                                                                            */
/* Esempi:                                                                    */
/*   ./ft_split "mela,banana,pera" ","                                        */
/*   ./ft_split "  hello   world  " " "                                       */
/*   ./ft_split "aXbXcX" "X"                                                  */
/*   ./ft_split "" ","          → array vuoto con solo NULL                   */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	char	**result;
	char	sep;
	int		i;

	/* Controlla che l'utente abbia passato esattamente 2 argomenti */
	if (argc != 3)
	{
		printf("Uso: %s \"stringa\" \"separatore\"\n", argv[0]);
		printf("Esempio: %s \"mela,banana,pera\" \",\"\n", argv[0]);
		return (1);
	}

	/* Il separatore è il primo carattere del secondo argomento */
	sep = argv[2][0];

	printf("Stringa:    \"%s\"\n", argv[1]);
	printf("Separatore: '%c'\n\n", sep);

	/* Chiama ft_split */
	result = ft_split(argv[1], sep);

	/* Controlla se ha ritornato NULL */
	if (!result)
	{
		printf("ft_split ha ritornato NULL.\n");
		return (1);
	}

	/* Stampa le parole trovate */
	i = 0;
	while (result[i])
	{
		printf("result[%d] = \"%s\"\n", i, result[i]);
		i++;
	}
	printf("result[%d] = NULL\n", i);
	printf("\nTotale parole trovate: %d\n", i);

	/* Libera la memoria */
	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);

	return (0);
}
