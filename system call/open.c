#include <stdio.h>
#include <dirent.h>
#include <stdlib.h> // Added for the exit() function

int main() {
    struct dirent *dptr;
    char buff[256];
    DIR *dirp; // Added a pointer type to DIR
    printf("Enter directory name: ");
    scanf("%s", buff);
    
    if ((dirp = opendir(buff)) == NULL) { // Corrected the comparison and added parentheses
        printf("Error opening directory.\n");
        exit(1);
    }
    
    while ((dptr = readdir(dirp)) != NULL) { // Added parentheses and corrected comparison
        printf("%s\n", dptr->d_name);
    }
    
    closedir(dirp);
    return 0;
}
