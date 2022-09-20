

void    free_map(int **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int	join_map(int ***map, int *line)
{
	int	count;
	int **cpy;

	count = 0;
	while ((*map)[count])
		count++;
	cpy = malloc((count + 1) * sizeof(int *));
	if (!cpy)
		return (0);
	count = 0;
	while ((*map)[count])
	{
		cpy[count] = (*map)[count];
		count++;
	}
	cpy[count] = 0;
	free(*map);
	*map = cpy;
	return (1);
}