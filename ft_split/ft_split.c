/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:36:42 by aaltinto          #+#    #+#             */
/*   Updated: 2023/07/11 12:37:14 by aaltinto         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

unsigned int	wordcounter(const char *s, char delimiter)
{
	unsigned int	word;

	word = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			while (*s != delimiter && *s)
				s++;
			word++;
		}
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**dest;
	unsigned int	lc;
	unsigned int	wc;

	if (!s)
		return (NULL);
	dest = (char **)ft_calloc(wordcounter(s, c) + 1, sizeof(char *));
	if (!dest)
		return (ft_malloc_error(dest));
	wc = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			lc = 0;
			while (*s != c && *s && ++lc)
				s++;
			dest[wc++] = (char *)ft_calloc(lc + 1, sizeof(char));
			ft_strlcpy(dest[wc -1], s - lc, lc + 1);
		}
	}
	return (dest);
}

int main()
{
	char const s[] = "yusuf emre ozden cok mutsuz.";

	char **dest = ft_split(s,' ');
	 
	int i = 0;

	while(dest[i])
	{
		printf("%s\n",dest[i]);
		i++;
	}
}