#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table{
    char* keyword;
    int count;

};

void compare(char* linewords, struct table*abc, int i)
{
    
    if (strcmp(linewords, abc[i].keyword) == 0)
                {
                    abc[i].count += 1;
                }
}
void splistring(char* line, int argc, struct table* abc)
{
    int i;
    char * linewords = strtok(line, " ");
        while(linewords != NULL)
        {                    
            for(i=0; i<argc-1; i++)
            {
                if(strstr(linewords, "\n"))
                {
                    linewords[strlen(linewords)- 1] = '\0';
                }   
               compare(linewords, abc, i);
            }
            linewords = strtok(NULL, " ");
        }
}
void display (struct table*abc, int argc)
{
    int i;
    for(i=0; i<argc-1; i++)
    {
        printf("%s %d\n", abc[i].keyword, abc[i].count);
    }
}

int main(int argc, char** argv)
{
    int i;
    struct table* abc = (struct table*) malloc(argc* sizeof(struct table));
    for(i=0; i<argc-1; i++)
    {
     abc[i].keyword = argv[i+1]; 
     abc[i].count = 0;
    }
    char *line=NULL;
    size_t maxlen=0;
    ssize_t n;
    while ( (n = getline(&line, &maxlen, stdin)) > 0)
    {
       splistring(line, argc, abc); 
    }
    display(abc, argc);
    free(line);

    return 0;    
}

