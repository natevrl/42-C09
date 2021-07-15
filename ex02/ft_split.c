/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:10:05 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/15 21:51:00 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char	*str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_split_copy(char *str, int fin, int debut)
{
	int		taille;
	int		i;
	char	*tab;

	i = 0;
	taille = fin - debut;
	tab = malloc(taille * sizeof(char) + 1);
	if (!tab)
		return (NULL);
	while (debut < fin)
	{
		tab[i] = str[debut];
		debut++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

void	init_var(int *i, int *f, int *charset_end)
{
	*i = -1;
	*f = 0;
	*charset_end = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		f;
	int		charset_end;
	char	**tab_de_tab;

	init_var(&i, &f, &charset_end);
	tab_de_tab = malloc(100 * sizeof(char *));
	if (!tab_de_tab)
		return (NULL);
	if (is_in_charset(str[0], charset))
		f = -1;
	while (str[++i])
	{
		if (i == ft_strlen(str) - 1)
			tab_de_tab[f] = ft_split_copy(str, i + 1, charset_end);
		j = 0;
		if (is_in_charset(str[i], charset))
		{
			while (is_in_charset(str[++i], charset))
				j++;
			tab_de_tab[f++] = ft_split_copy(str, (i - 1) - j, charset_end);
			charset_end = i--;
		}
	}
	tab_de_tab[f + 1] = 0;
	return (tab_de_tab);
}

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    (void)argc;
    char **res = ft_split(argv[1], argv[2]);
    int i = 0;
    while (res[i])
    {
        printf("t[%d] = %s\n", i, res[i]);
        i++;
    }
    printf("%s",res[i]);
}
