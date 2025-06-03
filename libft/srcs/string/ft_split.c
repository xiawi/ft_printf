/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:13:51 by weyap             #+#    #+#             */
/*   Updated: 2025/05/22 09:13:51 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdelimited(char const *s, char c);
static int	delimitedlen(char const *s, char c);
static void	*godfree(char **arr, int size);

/*
 *	ft_split - splits a string into an array of strings using a delimiter
 *
 *	parameters
 *		s - string to be split
 *		c - character delimiter
 *
 *	variables
 *	 	delimited_count - number of substrings between delimiters
 *		arr - dynamically allocated array of split strings
 *		index - current index to insert into `arr`
 *		str_len - length of the current substring
 *		delimited - temporary pointer to the current substring
 *
 *	function calls
 *		countdelimited - counts how many substrings exist
 *		malloc - allocates memory from the heap
 *		delimitedlen - gets the length of the current substring
 *		ft_substr - duplicates a substring
 *		godfree - frees memory in case of error
 *
 *	return
 *		`arr` if no allocation fails, otherwise NULL
 */
char	**ft_split(char const *s, char c)
{
	int		delimited_count;
	char	**arr;
	int		index;
	int		str_len;
	char	*delimited;

	delimited_count = countdelimited(s, c);
	arr = (char **)malloc(sizeof(char *) * (delimited_count + 1));
	if (arr)
	{
		index = 0;
		while (delimited_count--)
		{
			while (*s == c)
				s++;
			str_len = delimitedlen(s, c);
			delimited = ft_substr(s, 0, str_len);
			if (!delimited)
				return (godfree(arr, index));
			arr[index++] = delimited;
			s += str_len;
		}
		arr[index] = NULL;
	}
	return (arr);
}

/*
 *	countdelimited - counts number of delimited strings
 *
 *	parameters
 *		s - string to count the number of delimited strings
 *		c - character delimiter
 *
 *	variables
 *		count - number of delimited strings in `s`
 *
 *	return
 *		`count`
 */
static int	countdelimited(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			count++;
			s += delimitedlen(s, c);
		}
	}
	return (count);
}

/*
 *	delimitedlen - calculates the length of the first delimited string
 *
 *	parameters
 * 		s - string to calculate the length of the first delimited string
 * 		c - character delimiter
 *
 *	variables
 *		len - length of delimited string
 *
 *	return
 *		`len`
 */
static int	delimitedlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

/*
 *	godfree - frees everything
 *
 *	parameters
 *		arr - the array to be freed
 *		size - the number of contents to be freed from `arr`
 *
 *	variables
 *		index - `arr` index
 *
 *	function calls
 *		free - frees dynamically allocated memory back to the heap
 *
 *	return
 *		NULL
 *
 *	notes
 *		[145-147]
 *			loops through `arr` up to the `size`th element, freeing each
 *			element before freeing `arr` itself
 */
static void	*godfree(char **arr, int size)
{
	int	index;

	index = 0;
	while (index < size)
		free(arr[index++]);
	free(arr);
	return (NULL);
}
