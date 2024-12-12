/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalinow <lmalinow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:52:57 by lmalinow          #+#    #+#             */
/*   Updated: 2024/12/12 20:17:15 by lmalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int ft_check_separator(char s, char c)
{
	return (s == c);
}
static int ft_strlen_sep(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && !ft_check_separator(str[i], c))
		i++;
	return (i);
}

static int ft_count_strings(char *str, char c)
{
	size_t i;
	size_t count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_check_separator(str[i], c))
			i++;
		if (str[i])
			count++;
		while (str[i] && !ft_check_separator(str[i], c))
			i++;
	}
	return (count);
}
static char *ft_word(char *str, char c)
{
	size_t len_word;
	size_t i;
	char *word;

	i = 0;
	len_word = ft_strlen_sep(str, c);
	word = malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
char **ft_split(char const *s, char c)
{
	size_t word_count;
	char **strings;

	if (!s)
		return (NULL);
	word_count = ft_count_strings((char *)s, c);
	strings = malloc(sizeof(char *) * (word_count + 1));
	if (!strings)
		return (NULL);
	size_t i = 0;
	while (*s)
	{
		while (*s && ft_check_separator(*s, c))
			s++;
		if (*s)
		{
			strings[i] = ft_word((char *)s, c);
			if (!strings[i])
			{
				while (i > 0)
					free(strings[--i]);
				free(strings);
				return (NULL);
			}
			i++;
		}
		while (*s && !ft_check_separator(*s, c))
			s++;
	}
	strings[i] = NULL;

	return (strings);
}

// int main(void)
// {
// 	char **words;
// 	char *s1 = "Hello#World#Bis!";
// 	words = ft_split(s1, '#');
// 	int i = 0;
// 	while (words[i])
// 	{
// 		printf("%s\n", words[i]);
// 		free(words[i]); // Uwalnianie pamięci dla każdego słowa
// 		i++;
// 	}
// 	free(words); // Uwalnianie pamięci dla tablicy wskaźników
// 	return (0);
// }
