/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:23:48 by byan              #+#    #+#             */
/*   Updated: 2022/01/15 07:30:01 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != '\0' && s[i] != c)
			i++;
		cnt++;
	}
	return (cnt);
}

static int	free_all(char **words, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(words[i++]);
	free(words);
	return (0);
}

static char	*split_word(char const *s, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *) malloc(sizeof(char) * (len + 1));
	if (word == 0)
		return (0);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	start_split(char const *s, char c, char **words)
{
	int	index;
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		index = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		words[count] = split_word(s + index, i - index);
		if (words[count] == 0)
		{
			free_all(words, count);
			return ;
		}
		count++;
	}
	words[count] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**answer;

	answer = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (answer == 0)
		return (0);
	start_split(s, c, answer);
	return (answer);
}
