#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

#include <C:/Users/Acer/Downloads/C/SpriteLoaderDemo/wall.ppm>

int width=1000; //Screen width
int height=500; //Screen height

void drawSprites(int rgbArray[],int imageWidth,int imageHeight){
 int x;
 int y;
 for(y=0;y<imageWidth;y++){
  for(x=0;x<imageHeight;x++){
   int pixel=(y*imageHeight+x)*3;
   int red=rgbArray[pixel+0];
   int green=rgbArray[pixel+1];
   int blue=rgbArray[pixel+2];
   if(red==200 && green==0 && blue==255){
   	x++;
   }
   else{
    glPointSize(8);
    glBegin(GL_POINTS);
    glColor3ub(red, green, blue);
    glVertex2i(x*8,y*8);
    glEnd();
   }
  }         
 }
} 
void init(){
 glClearColor(0.3,0.3,0.3,0);
 gluOrtho2D(0,width,height,0);
}

void userDisplay(){
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 //---------------------Objects---------------------
 //-----------------------Draw----------------------
 drawSprites(Wall,40,40);
 glutSwapBuffers();
 glutPostRedisplay();
}

void main(int argc, char** argv){ 
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
 glutInitWindowSize(width,height);
 glutCreateWindow("OpenGL");
 init();
 glutDisplayFunc(userDisplay);
 glutMainLoop();
}
