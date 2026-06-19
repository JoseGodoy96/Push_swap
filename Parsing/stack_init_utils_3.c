/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 22:03:36 by jgodoy-m          #+#    #+#             */
/*   Updated: 2025/08/12 12:00:47 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	ft_count_words(char	*s, char c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		if (s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

char	*copy_word(char *s, int start, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_words_dup(char **matrix, char *s, char c)
{
	int	i;
	int	k;
	int	start;
	int	len;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			len = 0;
			while (s[i] != '\0' && s[i] != c)
			{
				len++;
				i++;
			}
			matrix[k++] = copy_word(s, start, len);
		}
	}
	matrix[k] = NULL;
	return (matrix);
}

char	**ft_split(char	*s, char c)
{
	char	**matrix;
	int		size;

	size = ft_count_words(s, c);
	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	if (!matrix)
		return (NULL);
	matrix = ft_words_dup(matrix, s, c);
	return (matrix);
}
