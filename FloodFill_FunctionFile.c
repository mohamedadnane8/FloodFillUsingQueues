#include "queues.h"

typedef struct s{
    coordinates x,y;
}Coordinate_t;

Coordinate_t QueueList[MAXROW*MAXCOL];
QueueItem picture[MAXCOL][MAXROW];

int Rear,Front ;

// these are for the QueueList
void newQueue(){
    Rear = Front = 0;
}

void makeOriginal(){

    for(int i = 0;i < MAXCOL;i++){
        for(int j = 0;j <MAXROW;j++)
            scanf("%d",&picture[i][j]);
    }   
}

void enqueue(coordinates x1, coordinates y1){
    if(isFull())
        return;
    QueueList[Rear].x = x1;
    QueueList[Rear].y = y1;
    Rear++;
}

coordinates dequeue(coordinates *x1 ,coordinates y){
    if(isEmpty())
        return INVALID;
    *x1 = QueueList[Front].x;
    return QueueList[Front++].y;  
}

pixel_t returnPixel(coordinates x,coordinates y){

    if(isBigSmall(x,y)){
        printf("Sorry wrong input %d\n",picture[y][x]);
        return INVALID;
    }
    return picture[y][x];
}
void unconnect(coordinates x1,coordinates y1){
    picture[y1][x1] = 0;
}
int checkPixel(coordinates x1,coordinates y1, pixel_t pixel){
    if(isBigSmall(x1,y1)){
        return 0;
    }
    if(picture[y1][x1] == pixel){
        return 1;
    }else return 0;
}
void print(){
    for(int i = 0;i < MAXCOL;i++){
        for(int j = 0;j <MAXROW;j++)
            printf("%d",picture[i][j]);
    printf("\n");
    }
}

int isEmpty(){
    return Rear == Front;
}

int isFull(){  
    return Rear == MAXROW*MAXCOL;
}

int isBigSmall(coordinates x,coordinates y){
    return !((x > -1 && x < MAXROW) && (y > -1 && y <MAXCOL));
}
