#include "complete.h"

char** complete(char *path, char *input) {
    DIR *dir;
    struct dirent *entry;
    char **output = NULL;
    int count = 0;
    dir = opendir(path);
    if (dir == NULL) {
        return NULL;
    }
    while ((entry = readdir(dir)) != NULL) {
        if(strstr(entry->d_name, input) == entry->d_name) {
            char **temp = realloc(output, sizeof(char*) * (count + 2));  // +2 to account for NULL termination
            if (temp == NULL) {
                // If realloc fails, free previously allocated memory
                for (int i = 0; i < count; i++) {
                    free(output[i]);
                }
                free(output);
                closedir(dir);
                return NULL;
            }
            output = temp;
            output[count] = malloc(strlen(entry->d_name) + 1);
            strcpy(output[count], entry->d_name);
            count++;
        }
    }
    closedir(dir);

    if (count == 0) {
        return NULL;
    }

    output[count] = NULL;  // Add NULL termination
    return output;
}

char* auto_complete(char *input) {
    char **t = complete("/usr/bin", input);
    if (t == NULL) {
        printf("No match found\n");
        return NULL;
    }

    if (t[1] == NULL) {  // Only one match
        char *result = strdup(t[0]);
        free(t[0]);
        free(t);
        return result;
    }

    printf("\nMultiple matches found: ");
    for (int i = 0; t[i] != NULL; i++) {
        printf("%s\t", t[i]);
        free(t[i]);  // Free each string
    }
    free(t);  // Free the array

    return NULL;
}
