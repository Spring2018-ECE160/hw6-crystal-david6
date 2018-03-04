#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINES 10000
#define MAXSTORAGE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char s[]);
void writelines(char *lineptr[], int nlines, int show_lines);
int getline_(char *, int);


int main(int argc, char *argv[])
{
    char s[MAXSTORAGE];
    char s2[MAXSTORAGE];
    int nlines;         
    int show_lines;     
    int i = 0;
    
    while (--argc > 0 && (*++argv)[0] == '-')
        while (isdigit(*++argv[0]))
            s2[i++] = *argv[0];
    
    s2[i] = '\0';
    
    show_lines = strlen(s2) ? atoi(s2) : 10;
    
    if ((nlines = readlines(lineptr, MAXLINES, s)) >= 0) {
        writelines(lineptr, nlines, show_lines);
        return 0;
    } else {
        printf("error: input too big\n");
        return 1;
    }
}

int getline_(char s[], int lim) {
    int c=0;
    int i;
    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        for (; s[i-1] == ' ' || s[i-1] == '\t'; --i)
            ;
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


#define MAXLEN  1000 

int readlines(char *lineptr[], int maxlines, char *s)
{
    int len, nlines, total;
    char line[MAXLEN];
    
    nlines = total = 0;
    while((len = getline_(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (total + len) > MAXSTORAGE)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(s, line);
            lineptr[nlines++] = s;
            s += len;
            total += len;
        }
    }
    return nlines;
}


void writelines(char *lineptr[], int nlines, int show_lines)
{
    while (nlines-- > 0)
        if (nlines < show_lines)
            printf("%s\n", *lineptr++);
        else
            lineptr++;
}
