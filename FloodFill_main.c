#include "queues.h"

int main() {
     pixel_t pixel = INVALID;
     coordinates x, y;
     makeOriginal();
     newQueue();

     printf("This is what you have made:\n");
     print();
     //will have to repeat this until he does not put an invalid choice
     while(pixel == INVALID){
          printf(">> y :  ");
          scanf("%d",&y);
          printf(">> x :  ");
          scanf("%d",&x);

          pixel = returnPixel(x,y);
     }
     
     printf("The pixel = %d \n",pixel);
     
     if (checkPixel(x,y,pixel) == 1){
          unconnect(x,y);
     }
     //check every pixel if its neighbors are the the same 
     // x-1,y+1   x,y+1    x+1,y+1       
     // x-1,y     x,y        x+1,y
     // x-1,y-1   x,y-1    x+1,y-1 
     while(y != INVALID){
          if (checkPixel(x-1,y-1,pixel)== 1){
               //it enqueues  
               enqueue(x-1,y-1);
               unconnect(x+1,y-1);
               
          }
          if (checkPixel(x-1,y+1,pixel) == 1){

               enqueue(x-1,y+1);
               unconnect(x-1,y+1);

          }
          if (checkPixel(x-1,y,pixel) == 1){
               enqueue(x-1,y);
               unconnect(x-1,y);
          }
          if (checkPixel(x,y+1,pixel) == 1){
               enqueue(x,y+1);
               unconnect(x,y+1);

          }          
          if (checkPixel(x,y-1,pixel) == 1){
               enqueue(x,y-1);
               unconnect(x,y-1);

          }    
          if (checkPixel(x+1,y+1,pixel)== 1){
               enqueue(x+1,y+1);
               unconnect(x+1,y+1);

          }
          if (checkPixel(x+1,y,pixel) == 1){
               enqueue(x+1,y);
               unconnect(x+1,y);

          }
          if (checkPixel(x+1,y-1,pixel) == 1){
               enqueue(x+1,y-1);
               unconnect(x+1,y-1);

          }

          y = dequeue(&x,y);
     }
     printf("The Result\n");
     print();
}
