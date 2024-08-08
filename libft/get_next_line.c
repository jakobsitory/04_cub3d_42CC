/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:32:02 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:54:47 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Shortens a string by removing the content up to and including the first newline character.
 * 
 * @param line The original string to be shortened.
 * @return A new string that starts after the first newline in `line`, or NULL under certain conditions.
 */
char	*shorten(char *line)
{
	char	*rest;
	int		rest_len;

	rest = NULL;
	if (!ft_strchr(line, '\n') || ft_strlen(line) == 1)
	{
		free (line);
		return (NULL);
	}
	if (0 == ft_strchr(line, '\n') - line - ft_strlen(line) + 1)
	{
		free (line);
		return (NULL);
	}
	rest_len = ft_strlen(ft_strchr(line, '\n'));
	rest = (char *) malloc (rest_len + 1);
	if (!rest)
		return (NULL);
	ft_strlcpy(rest, ft_strchr(line, '\n') + 1, rest_len);
	free (line);
	return (rest);
}

/**
 * Extracts a line from a string, including the newline character.
 * 
 * @param line The original string from which to extract the line.
 * @return A new string containing the extracted line, or NULL if memory allocation fails.
 */
char	*extract(char *line)
{
	char	*result;

	result = NULL;
	if (!ft_strchr(line, '\n') || (ft_strlen(line) == 1 && BUFFER_SIZE > 1))
	{
		result = (char *) malloc (ft_strlen(line) + 1);
		if (!result)
			return (NULL);
		ft_strlcpy(result, line, ft_strlen(line) + 1);
	}
	else
	{
		result = (char *) malloc (ft_strchr(line, '\n') - line + 2);
		if (!result)
			return (NULL);
		ft_strlcpy(result, line, ft_strchr(line, '\n') - line + 2);
	}
	return (result);
}

/**
 * Helper function to append buffer content to a line until a newline is found.
 * returns the updated line.
 * 
 * @param fd The file descriptor from which to read.
 * @param r_len Pointer to an integer that stores the read length.
 * @param line The initial line to which buffer content is appended.
 * @param buffer The buffer used for reading from `fd`.
 * @return The updated line after appending buffer content, or NULL if memory allocation fails.
 */
char	*al_helper(int fd, int *r_len, char *line, char *buffer)
{
	char	*new_line;

	if (!line)
	{
		line = (char *) malloc (1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	while ((*r_len) > 0)
	{
		buffer[(*r_len)] = '\0';
		new_line = ft_strjoin(line, buffer);
		free (line);
		if (ft_strchr(new_line, '\n'))
			break ;
		line = new_line;
		(*r_len) = read(fd, buffer, BUFFER_SIZE);
	}
	return (new_line);
}

/**
 * Reads from a file descriptor and appends the content to a line until a newline is found.
 * 
 * @param fd The file descriptor from which to read.
 * @param r_len Pointer to an integer that stores the read length.
 * @param line The initial line to which the read content is appended.
 * @return The updated line after reading and appending content, or NULL in case of errors.
 */
char	*add_line(int fd, int *r_len, char *line)
{
	char	*buffer;
	char	*new_line;

	new_line = 0;
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	(*r_len) = read(fd, buffer, BUFFER_SIZE);
	if ((*r_len) == 0)
		new_line = line;
	else if ((*r_len) > 0)
		new_line = al_helper(fd, r_len, line, buffer);
	if ((*r_len) < 0)
	{
		free (line);
		free (new_line);
		free (buffer);
		return (NULL);
	}
	free(buffer);
	return (new_line);
}

/**
 * Retrieves the next line from a file descriptor, including the newline character.
 * 
 * @param fd The file descriptor from which to read.
 * @return The next line from the file descriptor, or NULL if no more lines are available or in case of errors.
 */
char	*get_next_line(int fd)
{
	static char	*line;
	int			*r_len;
	int			read_len;
	char		*result;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r_len = &read_len;
	read_len = 1;
	if (!line || !ft_strchr(line, '\n'))
		line = add_line(fd, r_len, line);
	if (line && read_len >= 0)
	{
		result = extract(line);
		line = shorten(line);
	}
	else if (read_len < 0)
		free (line);
	return (result);
}
