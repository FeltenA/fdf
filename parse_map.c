/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:43:57 by afelten           #+#    #+#             */
/*   Updated: 2022/09/18 19:54:40 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    free_map(int **map);
int	join_map(int ***map, int *line);

int	count_num(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (line[0] >= '0' && line[0] <= '9')
		count++;
	while (line[i] != '\0' && line[i + 1] != '\0')
	{
		if (line[i] == ' ' && line[i + 1] >= '0' && line[i + 1] <= '9')
			count++;
		i++;
	}
	return (count);
}

void get_values(char *line, int **num_line)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (line[0] >= '0' && line[0] <= '9')
	{
		(*num_line)[j] = ft_atoi(line[0]);
		j++;
	}
	while (line[i] != '\0' && line[i + 1] != '\0')
	{
		if (line == '0' && line[i + 1] >= '0' && line[i + 1] <= '9')
		{
			(*num_line)[j] = ft_atoi(line[i + 1]);
			j++;
		}
		i++;
	}
}

int *parse_line(int fd)
{
	char *line;
	int	*num_line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	num_line = malloc((count_num(line) + 1) * sizeof(int));
	if (!num_line)
	{
		free(line);
		return (0);
	}
	num_line[0] = count_num(line);
	get_values(line, &num_line);
	free(line);
	return (num_line);
}

int	convert_map(int ***map, int fd)
{
	int	*line;

	line = parse_line(fd);
	while (line)
	{
		if (!join_map(map, line))
		{
			free(line);
			free_map(map);
			return (0);
		}
		free(line);
		line = parse_line(fd);
	}
	return (1);
}

int	**parse_map(char *file)
{
	int	**map;
	int	fd;

	fd = open(file, "RD_ONLY");
	if (fd < 0)
		return (0);
	map = malloc(sizeof(int *));
	if (!map)
	{
		close(fd);
		return (0);
	}
	map[0] = 0;
	if (!convert_map(&map, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (map);
}
