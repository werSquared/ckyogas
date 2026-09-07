#include <stdio.h>
#include <stdlib.h>

void main(char* file) {
    FILE *file = fopen(file, "r");
    if (file == NULL) {   
        printf("external.fileSys: something went wrong with trying to open %s.", file);
        printf("This could be triggered by two things: the file either doesn't exist");
        printf("--or the file's permissions blocked Kyogas.");
        fclose(file); // this might be redundant but better safe than sorry
        return 1;
    }
    else {
        // you should probably read the file into memory in main and then pass that data into the function
        // as opposed to making the function a bit dirtier/less pure by having it open the file too

        // I believe in Kyogas you read the file as lines so if you want to repeat it you could (probably) use this:
        
        // char buffer[256]; // 256 lines maximum -- May be too small.
        // while (fgets(buffer, sizeof(buffer), file) != NULL) {
        //     do something with the line--
        //     my advice is to have your actual parse function take one line at a time
        //
        //     parse(buffer)
        // }
        
        // parseShitOrSomethingIdk(file); // shouldn't this be a pointer? 
        
        printf("Everything went according to plan!");
        fclose(file);
        return 0;
    }
}

string file = *argv[1];

if (file == NULL) {
    printf("You must provide a file for Kyogas to parse. Ensure the file is present in the current directory.");
    exit();
}

main(*argv[1]);


