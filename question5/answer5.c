#include <stdio.h>

struct mountain{
    char *name;
    int height;
} mountains[]={
    "Chomolungma", 8848,
    "Qogir", 8611,
    "Kangchenjunga", 8586,
    "Lhotse", 8516,
    "Makalu", 8485,
};

int getaverage(struct mountain list[]);
void heightmax(struct mountain list[]);

int main(){
    printf("average value= %d\n", getaverage(mountains));
    heightmax(mountains);
    return 0;
}

int getaverage(struct mountain list[]){
    int i;
    int sum=0;
    for (i=0; i<sizeof(mountains); i++) {
        sum=sum+list[i].height;
    }
    return sum/sizeof(mountains);
}

void heightmax(struct mountain list[]){
    int i, *max;
    max= &list[i].height;
    i++;
    for (int j=0; j<sizeof(mountains); j++) {
        if (*max<list[i].height) {
            max= &list[i].height;
        }
        i++;
    }
    printf("highest height: %d", *max);
}

