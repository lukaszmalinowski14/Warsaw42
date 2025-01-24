#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_line
{
	char *str;
	size_t l;
} s_line;

void ft_copy_str(s_line **line)
{
	// Upewnij się, że wskaźnik jest ważny
	if (*line == NULL)
	{
		return;
	}

	// Uwolnij poprzednią zawartość (jeśli istnieje)
	if ((*line)->str != NULL)
	{
		free((*line)->str);
	}

	// Przydziel pamięć dla nowego łańcucha znaków
	(*line)->str = strdup("O"); // strdup tworzy kopię łańcucha znaków
	if ((*line)->str == NULL)
	{
		// Obsłuż błąd alokacji pamięci
		return;
	}

	(*line)->l = 1; // Długość nowego łańcucha znaków
}

char *get_next_line(int fd)
{
	s_line line;
	line.l = 0;
	line.str = malloc(1);
	line.str = "H";

	ft_copy_str(&line);

	printf("%s\n", line.str);
	printf("%zu\n", line.l);

	// Zwróć wskaźnik na łańcuch znaków (jeśli jest potrzebny)
	return line.str;
}

int main()
{
	get_next_line(0); // Przykładowe wywołanie funkcji
	return 0;
}
