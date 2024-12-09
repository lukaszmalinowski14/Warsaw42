#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define OUTPUT_FILE "files_list.txt"

int main(void)
{
	DIR *dir;
	struct dirent *entry;
	FILE *output;

	// Otwórz bieżący katalog
	dir = opendir(".");
	if (!dir)
	{
		perror("Nie można otworzyć katalogu");
		return EXIT_FAILURE;
	}

	// Otwórz plik wyjściowy do zapisu
	output = fopen(OUTPUT_FILE, "w");
	if (!output)
	{
		perror("Nie można otworzyć pliku wyjściowego");
		closedir(dir);
		return EXIT_FAILURE;
	}

	// Przeglądaj pliki w katalogu
	while ((entry = readdir(dir)) != NULL)
	{
		// Sprawdź, czy nazwa pliku kończy się na ".c"
		if (strstr(entry->d_name, ".c") != NULL)
		{
			fprintf(output, "%s\n", entry->d_name); // Zapisz nazwę do pliku
		}
	}

	// Zamknij katalog i plik wyjściowy
	closedir(dir);
	fclose(output);

	printf("Nazwy plików .c zapisano do pliku: %s\n", OUTPUT_FILE);
	return EXIT_SUCCESS;
}