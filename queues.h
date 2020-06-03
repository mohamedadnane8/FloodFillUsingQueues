#include <stdio.h>

#define MAXCOL 4
#define MAXROW 5
#define INVALID -99

typedef int coordinates;
typedef int pixel_t;
typedef int QueueItem;


void newQueue();

void makeOriginal();
void print();

void enqueue(coordinates x1, coordinates y2);
coordinates dequeue(coordinates* x1 ,coordinates y);

pixel_t returnPixel(coordinates x,coordinates y);
void unconnect(coordinates x1,coordinates y1);
int checkPixel(coordinates x1,coordinates y1, pixel_t pixel);


int isEmpty();
int isFull();
int isBigSmall(coordinates x,coordinates y);

