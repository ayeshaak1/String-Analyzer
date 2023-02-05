#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    // check if poem file was passed or not
    if (argc < 2) {
        printf("Pass the poem file");
        return 0;
    }

    // open file and check if file exists
    FILE *fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("File name '%s' could not be found\n", argv[1]);
        return 0;
    }

    // create local var
    int totalWords = 0, numLines = 0, wordCount = 0;
    int *words = NULL;
    char line[MAX_LINE_LENGTH];

    // check each line in the file
    while (fgets(line, MAX_LINE_LENGTH, fptr) != NULL) {
        // reset the count for each line
	wordCount = 0;
	// split line and space into separate words
        char *word = strtok(line, " ");
        while (word != NULL) {
            wordCount++;
            word = strtok(NULL, " ");
        }

	// add the current word count to the total
        totalWords += wordCount;
	// increase the number of lines
        numLines++;
	// reallocate memory for words to add number of lines
        words = realloc(words, sizeof(int) * numLines);
	// assign the wordCount to the new "box"
        words[numLines-1] = wordCount;
    }

    // if only one line
    if (numLines == 1) {
        printf("%d words on %d line\n", totalWords, numLines);
    }
    // if there are more lines, add 's' to line
    else {
        printf("%d words on %d lines\n", totalWords, numLines);
    }

    // print number of words on each line
    for (int i = 0; i < numLines; i++) {
        printf("%d ", words[i]);
    }

    fclose(fptr);
    free(words);

    return 0;
}
