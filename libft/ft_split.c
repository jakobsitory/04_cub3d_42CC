/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:59:06 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:25:08 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Counts the number of words in a string, separated by a specified character.
 * 
 * @param s The string to count words in.
 * @param c The character used as a separator.
 * @return The number of words in the string.
 */
int	ft_words_in_str(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

/**
 * Frees all allocated memory in an array of strings and the array itself.
 * 
 * @param arr The array of strings to free.
 */
void	ft_freeall(char **arr)
{
	int	i;

	i = 0;
	while (arr)
		free(arr[i++]);
	free (arr);
}

/**
 * Allocates and copies a substring into a new string, freeing allocated memory on failure.
 * 
 * @param pos The starting position in the string from which to copy.
 * @param len The number of characters to copy.
 * @param words An array of strings to be freed in case of allocation failure.
 * @return A pointer to the newly allocated string, or NULL if allocation fails.
 */
char	*ft_writestr(char *pos, int len, char **words)
{
	char	*word;

	word = (char *) malloc (len + 1);
	if (word == NULL)
	{	
		ft_freeall(words);
		return (NULL);
	}
	ft_strlcpy(word, pos, len + 1);
	return (word);
}

/**
 * Searches for the first character in a string that is not equal to a specified character.
 * 
 * @param s The string to search.
 * @param c The character to compare against, represented as an int.
 * @return A pointer to the first character in `s` that is not `c`, or NULL if no such character exists.
 */
char	*ft_strnchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{	
		if (s[i] != (char) c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

/**
 * Splits a string into words separated by occurrences of a specified character.
 * 
 * This function allocates and returns an array of strings obtained by splitting `s`
 * using the character `c` as a delimiter. The array is terminated by a NULL pointer.
 * 
 * @param s The string to split.
 * @param c The delimiter character.
 * @return An array of strings representing the words in `s`. NULL if an allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**words;
	int		wordlen;
	char	*pos;

	count = ft_words_in_str(s, c);
	words = (char **) ft_calloc (count + 1, sizeof(char *));
	if (!words)
		return (NULL);
	pos = (char *) s;
	i = 0;
	wordlen = 0;
	while (i + 1 <= count)
	{
		pos = ft_strnchr(&pos[wordlen], c);
		if (ft_strchr(pos, c))
			wordlen = ft_strchr(pos, c) - pos;
		else
			wordlen = ft_strlen(pos);
		words[i] = ft_writestr(pos, wordlen, words);
		i++;
	}
	words[count] = 0;
	return (words);
}
