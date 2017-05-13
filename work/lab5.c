#include <unistd.h>
#include <stdio.h>

int main(int argc, char ** argv, char ** env){
    char ** ptr;
    printf("Main process:\n");  
    printf("\tArguments:\n");
    for( ptr = argv; *ptr; ++ptr )
        printf("\t\t%s\n", *ptr);
    printf("\n");
    printf("\tEnvironment:\n");
    for( ptr = env; *ptr; ++ptr )
        printf("\t\t%s\n", *ptr);
    printf("\n");
    switch( fork() ){
        case -1:
            fprintf(stderr, "forkng error\n");
            return 1;
        case 0:
            wait();
            break;
        default:
            printf("Child process:\n");  
            printf("\tArguments:\n");
            for( ptr = argv; *ptr; ++ptr )
                printf("\t\t%s\n", *ptr);
            printf("\n");
            printf("\tEnvironment:\n");
            for( ptr = env; *ptr; ++ptr )
                printf("\t\t%s\n", *ptr);
            printf("\n");
        break;
    }
    return 0;
}
