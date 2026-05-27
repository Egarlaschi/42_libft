/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_commenti.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:35:07 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/26 14:35:21 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ===========================================================================
** PANORAMICA GENERALE
** ===========================================================================
** ft_split divide una stringa 's' in sottostringe usando 'c' come delimitatore.
** Esempio: ft_split("ciao mondo bello", ' ')
**          → ["ciao", "mondo", "bello", NULL]
**
** Il risultato è un array di stringhe allocato dinamicamente,
** terminato da un puntatore NULL (come argv in main).
**
** Le tre funzioni statiche sono "helper": non sono visibili fuori da questo
** file (static = scope limitato al file). Sono strumenti interni di ft_split.
** ===========================================================================
*/

/*
** ---------------------------------------------------------------------------
** count_words — conta quante parole ci sono nella stringa
** ---------------------------------------------------------------------------
** Parametri:
**   s → la stringa da analizzare (es: "  ciao  mondo  ")
**   c → il carattere delimitatore (es: ' ')
**
** Ritorna:
**   il numero di parole trovate (es: 2)
**
** Come funziona:
**   Usa una variabile 'in_word' come "flag" (bandierina) booleana:
**   - 0 = siamo fuori da una parola (in un separatore o all'inizio)
**   - 1 = siamo dentro una parola
**
**   Scorre la stringa carattere per carattere con while (*s):
**   - se il carattere NON è il delimitatore E siamo FUORI parola:
**       → siamo entrati in una nuova parola! alza la bandierina (in_word=1)
**          e incrementa il contatore
**   - se il carattere È il delimitatore:
**       → siamo usciti dalla parola, abbassa la bandierina (in_word=0)
**
**   Questo gestisce automaticamente i delimitatori multipli consecutivi
**   (es: "ciao   mondo" conta comunque solo 2 parole).
** ---------------------------------------------------------------------------
*/
static size_t	count_words(char const *s, char c)
{
	size_t	count;   /* numero di parole trovate finora */
	int		in_word; /* flag: 1 se stiamo leggendo una parola, 0 altrimenti */

	count = 0;
	in_word = 0;
	while (*s) /* continua finché non arriviamo al '\0' finale */
	{
		if (*s != c && !in_word) /* carattere NON delimitatore + eravamo fuori parola */
		{
			in_word = 1; /* ora siamo dentro una parola */
			count++;     /* troviamo una nuova parola: incrementa il contatore */
		}
		else if (*s == c) /* carattere delimitatore: usciamo dalla parola */
			in_word = 0;
		s++; /* vai al carattere successivo (incremento del puntatore) */
	}
	return (count);
}

/*
** ---------------------------------------------------------------------------
** free_array — libera la memoria in caso di errore
** ---------------------------------------------------------------------------
** Parametri:
**   strs  → l'array di stringhe già allocato
**   count → quante stringhe sono già state allocate (e vanno liberate)
**
** Ritorna:
**   NULL (sempre) — così può essere usata direttamente con return(free_array(...))
**
** Come funziona:
**   Quando durante fill_array una malloc fallisce, dobbiamo liberare tutta
**   la memoria già allocata prima di uscire, altrimenti si crea un memory leak.
**
**   Libera prima ogni singola stringa (strs[0], strs[1], ..., strs[count-1])
**   con un loop, poi libera l'array esterno che le conteneva.
**
**   Restituire NULL permette di scrivere:
**       return (free_array(strs, i - 1));
**   invece di:
**       free_array(strs, i - 1);
**       return (NULL);
** ---------------------------------------------------------------------------
*/
static void	*free_array(char **strs, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count) /* itera su tutte le stringhe già allocate */
	{
		free(strs[i]); /* libera la singola stringa i-esima */
		i++;
	}
	free(strs); /* libera l'array esterno (il "contenitore" dei puntatori) */
	return (NULL); /* ritorna NULL per segnalare il fallimento al chiamante */
}

/*
** ---------------------------------------------------------------------------
** fill_array — riempie l'array con le sottostringe trovate
** ---------------------------------------------------------------------------
** Parametri:
**   s    → la stringa originale da dividere
**   c    → il carattere delimitatore
**   strs → l'array già allocato (con count_words + 1 slot)
**
** Ritorna:
**   strs compilato correttamente, oppure NULL in caso di errore malloc
**
** Come funziona:
**   Scorre 's' carattere per carattere:
**
**   CASO 1 — carattere NON delimitatore (*s != c):
**     → Siamo all'inizio di una parola!
**     1. Misura la lunghezza della parola con un altro while interno:
**        conta i caratteri finché non trova un delimitatore o il '\0'
**     2. Chiama ft_substr(s, 0, len) per copiare la parola in una nuova stringa
**        (ft_substr alloca memoria e copia 'len' caratteri a partire da s[0])
**     3. Salva il risultato in strs[i] e incrementa i
**     4. Se ft_substr ha restituito NULL (malloc fallita), chiama free_array
**        per pulire tutto e ritorna NULL
**     5. Sposta 's' di 'len' posizioni per saltare la parola appena letta
**
**   CASO 2 — carattere delimitatore (*s == c):
**     → Salta semplicemente il delimitatore con s++
**
**   Alla fine del loop, imposta l'ultimo elemento a NULL:
**   strs[i] = NULL → questo è il "terminatore" dell'array, come '\0' nelle stringhe
** ---------------------------------------------------------------------------
*/
static char	**fill_array(char const *s, char c, char **strs)
{
	size_t	i;   /* indice corrente nell'array strs (quale slot stiamo riempiendo) */
	size_t	len; /* lunghezza della parola corrente */

	i = 0;
	while (*s) /* scorre tutta la stringa fino al '\0' */
	{
		if (*s != c) /* trovato l'inizio di una nuova parola */
		{
			/* misura la lunghezza della parola:
			** conta i caratteri finché non trova un delimitatore o la fine */
			len = 0;
			while (s[len] && s[len] != c)
				len++;

			/* ft_substr(stringa, indice_inizio, lunghezza_massima)
			** alloca e restituisce una nuova stringa con i primi 'len' caratteri
			** a partire da s[0] — in pratica, copia la parola corrente */
			strs[i] = ft_substr(s, 0, len);

			/* controlla se ft_substr ha fallito (ritorna NULL se malloc fallisce)
			** nota: i++ viene eseguito DOPO aver usato i, quindi free_array
			** riceve (i - 1) come numero di stringhe da liberare, che corrisponde
			** agli indici 0..i-1 già riempiti prima di questo fallimento */
			if (!strs[i++])
				return (free_array(strs, i - 1));

			/* sposta il puntatore s in avanti di 'len' posizioni
			** per saltare la parola appena estratta */
			s += len;
		}
		else
			s++; /* è un delimitatore: saltalo e vai al carattere successivo */
	}

	/* terminatore dell'array: il NULL finale segnala la fine,
	** esattamente come il '\0' nelle stringhe C */
	strs[i] = NULL;
	return (strs);
}

/*
** ---------------------------------------------------------------------------
** ft_split — funzione principale (pubblica)
** ---------------------------------------------------------------------------
** Parametri:
**   s → la stringa da dividere
**   c → il carattere separatore/delimitatore
**
** Ritorna:
**   Un array di stringhe (char **) terminato da NULL, oppure NULL in caso
**   di errore o se s è NULL.
**
** Come funziona (orchestrazione delle funzioni helper):
**
**   1. Controllo di sicurezza: se s è NULL non c'è niente da fare → ritorna NULL
**
**   2. Alloca l'array esterno:
**      - count_words(s, c) conta le parole → es: 3
**      - +1 per il NULL terminatore finale
**      - sizeof(char *) è la dimensione di UN puntatore (tipicamente 8 byte su 64-bit)
**      - malloc alloca count_words+1 slot, ognuno grande quanto un puntatore
**      - es: per 3 parole → malloc(4 * 8) = 32 byte
**
**   3. Controlla che malloc non abbia fallito
**
**   4. Chiama fill_array per riempire l'array con le sottostringe reali
**      e ritorna il risultato (che può essere l'array pieno oppure NULL se
**      fill_array ha incontrato un errore interno)
**
** Schema memoria finale (esempio con "ciao mondo"):
**
**   strs → [ ptr0 | ptr1 | NULL ]
**              |       |
**           "ciao"  "mondo"
** ---------------------------------------------------------------------------
*/
char	**ft_split(char const *s, char c)
{
	char	**strs; /* array di puntatori a stringhe (il risultato finale) */

	if (!s) /* s è NULL? non possiamo fare nulla */
		return (NULL);

	/* alloca l'array di puntatori:
	** (numero di parole + 1 per il NULL terminatore) slot,
	** ognuno grande come un puntatore a char */
	strs = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!strs) /* malloc ha fallito (memoria esaurita)? */
		return (NULL);

	/* delega il riempimento a fill_array e ritorna il risultato */
	return (fill_array(s, c, strs));
}
