
#include <GL/GLUT.h>
#include <time.h>
#include <sstream>
#include "stdlib.h"   
#include <iostream>
using namespace std;
#include <Windows.h>
#include <MMSystem.h>



GLint walkX = 0, walkY = 0, lookX = 0, lookY = 0;


int refreshMills = 15;
int  ScreenWindowWidth = 800;
int  ScreenWindowHeight = 600;

int WorldWidth = 60;
int WorldHeight = 50;
int WorldDeep = 120;

//trangle position
GLfloat  kpos = 4;
GLfloat  Jpos = -25.0;
GLfloat  Lpos = 2.0;


GLfloat anglePyramid = 0.0f;


void renderBitmapString(float x, float y, void* font, const char* string) {
    const char* c; glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void draw_Background() {

    glClear(GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.7);
    glVertex3f(30, -30, -30);
    glVertex3f(-30, -30, -30);


    glColor3f(0.1, 0.0, 0.4);
    glVertex3f(-30, 30, -30);
    glVertex3f(30, 30, -30);
    glEnd();
}

void draw_BackgroundForFrame() {

    glClear(GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.7);
    glVertex3f(45, -45, -45);
    glVertex3f(-45, -45, -45);

    glColor3f(0.1, 0.0, 0.4);
    glVertex3f(-30, 30, -30);
    glVertex3f(30, 30, -30);
    glEnd();
}

void InterGame() { //background 

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(10, -40);
    glVertex2f(-7, -40);
    glVertex2f(-7, -30);
    glVertex2f(10, -30);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    renderBitmapString(-5.5,-34, (void*)GLUT_BITMAP_HELVETICA_18, " - TO START THE GAME -");
    renderBitmapString(-5.5, -38, (void*)GLUT_BITMAP_HELVETICA_18, "- PRESS HOME BOTTON -");
}

void Obj() {

    glPushMatrix();
    glTranslatef(Jpos, Lpos, kpos); //it's location
    glRotatef(anglePyramid, 1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    // Front
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Right
    glColor3f(0.0f, 1.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back
    glColor3f(0.0f, 0.0f, 1.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Left
    glColor3f(0.5f, 0.0f, 0.5f);       // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();

    glPopMatrix();

}

void hit() {

    // BAR NO.1
    if (Jpos == -23) {
 
        if ((Jpos >= -23) && (Jpos <= 22) && (Lpos <= 30) && (Lpos >= 3)) {
            exit(0);
        }
 

        if ((Jpos >= -23) && (Jpos <= 22) && (Lpos <= 1) && (Lpos >= -40)) {
            exit(0);


        }

    }

    // BAR NO.2
    if (Jpos == -20) {
       
        if ((Jpos >= -20) && (Jpos <= 19) && (Lpos <= 30) && (Lpos >= -4)) {
            exit(0);
        }
      
        if ((Jpos >= -20) && (Jpos <= 19) && (Lpos <= -7) && (Lpos >= -40)) {
            exit(0);

        }

    }


    // BAR NO.3
    if (Jpos == -17) {
        
        if ((Jpos >= -17) && (Jpos <= 16) && (Lpos <= 30) && (Lpos >= 4)) {
            exit(0);
        }
         
        if ((Jpos >= -17) && (Jpos <= 16) && (Lpos <= 1) && (Lpos >= -40)) {
            exit(0);
        }
    }


    // BAR NO.4
    if (Jpos == -14) {
    
        if ((Jpos >= -14) && (Jpos <= 13) && (Lpos <= 30) && (Lpos >= 7)) {
            exit(0);
        }

     
        if ((Jpos >= -14) && (Jpos <= 13) && (Lpos <= 4) && (Lpos >= -40)) {
            exit(0);
        }
    }


    // BAR NO.5
    if (Jpos == -11) {
     
        if ((Jpos >= -11) && (Jpos <= 10) && (Lpos <= 30) && (Lpos >= -2)) {
            exit(0);
        }

      
        if ((Jpos >= -11) && (Jpos <= 10) && (Lpos <= -4) && (Lpos >= -40)) {
            exit(0);
        }
    }


    // BAR NO.6
    if (Jpos == -8) {
    
        if ((Jpos >= -8) && (Jpos <= 7) && (Lpos <= 30) && (Lpos >= 10)) {
            exit(0);
        }
 
        if ((Jpos >= -8) && (Jpos <= 7) && (Lpos <= 8) && (Lpos >= -40)) {
            exit(0);

        }
    }


    // BAR NO.7
    if (Jpos == -5) {
        
        if ((Jpos >= -5) && (Jpos <= 4) && (Lpos <= 30) && (Lpos >= 4)) {
            exit(0);
        }

        if ((Jpos >= -5) && (Jpos <= 4) && (Lpos <= 2) && (Lpos >= -40)) {
            exit(0);
        }
    }


    // The Green Box

    if (Jpos == 1) {
        if ((Jpos >= 1) && (Jpos <= 2) && (Lpos <= 3) && (Lpos >= 1)) {

            renderBitmapString(20, 15, (void*)GLUT_BITMAP_HELVETICA_18, "- YOU WIN ! -");
        }

    }
    glutPostRedisplay();

}

void Bars() {
    //  1 Buttom coulmn
    glBegin(GL_QUADS);
    glColor3f(0, 0.6, 0.6);
    glVertex2f(-22, 0);//up right
    glVertex2f(-22, -40);//botom right
    glVertex2f(-23, -40);//botom left
    glVertex2f(-23, 0);//up left
    glEnd();


    //  1 up coulmn

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.5);
    glVertex2f(-22, 5);//up right
    glVertex2f(-22, 30);//botom right
    glVertex2f(-23, 30);//botom left
    glVertex2f(-23, 5);//up left
    glEnd();



    //################################################
    glBegin(GL_QUADS);
    glColor3f(0, 0.6, 0.6);
    // 2 Buttom coulmn
    glVertex2f(-16, -15);//up right
    glVertex2f(-16, -40);//botom right
    glVertex2f(-17, -40);//botom left
    glVertex2f(-17, -15);//up left
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.5);
    //2 up coulmn
    glVertex2f(-16, -10);//up right
    glVertex2f(-16, 30);//botom right
    glVertex2f(-17, 30);//botom left
    glVertex2f(-17, -10);//up left
    glEnd();

    //################################################

    glBegin(GL_QUADS);
    glColor3f(0, 0.6, 0.6);
    // 3 Buttom coulmn
    glVertex2f(-10, -0);//up right
    glVertex2f(-10, -40);//botom right
    glVertex2f(-11, -40);//botom left
    glVertex2f(-11, -0);//up left
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.5);
    // 3 up coulmn
    glVertex2f(-10, 6);//up right
    glVertex2f(-10, 30);//botom right
    glVertex2f(-11, 30);//botom left
    glVertex2f(-11, 6);//up left
    glEnd();

    //################################################

    glBegin(GL_QUADS);
    glColor3f(0, 0.6, 0.6);
    // 4 Buttom coulmn
    glVertex2f(-4, 7);//up right
    glVertex2f(-4, -40);//botom right
    glVertex2f(-5, -40);//botom left
    glVertex2f(-5, 7);//up left
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.5);
    // 4 up coulmn
    glVertex2f(-4, 12);//up right
    glVertex2f(-4, 30);//botom right
    glVertex2f(-5, 30);//botom left
    glVertex2f(-5, 12);//up left
    glEnd();

    //################################################

    glBegin(GL_QUADS);
    glColor3f(0, 0.6, 0.6);
    // 5 Buttom coulmn
    glVertex2f(2, -10);//up right
    glVertex2f(2, -40);//botom right
    glVertex2f(1, -40);//botom left
    glVertex2f(1, -10);//up left
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.5);
    // 5 up coulmn
    glVertex2f(2, -6);//up right
    glVertex2f(2, 30);//botom right
    glVertex2f(1, 30);//botom left
    glVertex2f(1, -6);//up left
    glEnd();

    //################################################

    glBegin(GL_QUADS);
    glColor3f(0, 0.6, 0.6);
    // 6 Buttom coulmn
    glVertex2f(8, 14);//up right
    glVertex2f(8, -40);//botom right
    glVertex2f(7, -40);//botom left
    glVertex2f(7, 14);//up left
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.5);
    // 6 up coulmn
    glVertex2f(8, 18);//up right
    glVertex2f(8, 30);//botom right
    glVertex2f(7, 30);//botom left
    glVertex2f(7, 18);//up left
    glEnd();

    //################################################
    glBegin(GL_QUADS);
    glColor3f(0, 0.6, 0.6);
    // 7 Buttom coulmn
    glVertex2f(13, 2);//up right
    glVertex2f(13, -40);//botom right
    glVertex2f(14, -40);//botom left
    glVertex2f(14, 2);//up left
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.5);

    // 7 up coulmn
    glVertex2f(13, 6);//up right
    glVertex2f(13, 30);//botom right
    glVertex2f(14, 30);//botom left
    glVertex2f(14, 6);//up left

    glEnd();
    hit();
}

void GreenObjWIN() {
    glBegin(GL_QUADS);
    glColor3f(0.9 , 0.9 ,0.9);
    glVertex2f(23, 6);
    glVertex2f(28, 6);
    glVertex2f(28, 0);
    glVertex2f(23, 0);
    glEnd();
}

void DisplayTheFirstFrame(void) {
    draw_BackgroundForFrame();
    InterGame();
    glutSwapBuffers();
    glutPostRedisplay();
}

void DisplayTheGame(void)
{
   
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    draw_Background();
    Bars();
    GreenObjWIN();


    glPushMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial(GL_FRONT, GL_EMISSION);
    glEnable(GL_COLOR_MATERIAL);
    GLfloat lightpos[] = { 0, 0, 0, -1 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-1, 1, 0);
    glTranslatef(walkX, walkY, 0);
    Obj();
    glPopMatrix();

    anglePyramid += 0.1f;

    glutSwapBuffers();
    glutPostRedisplay();
  
}

void myReshape(int width, int height)
{
    ScreenWindowWidth = width;
    ScreenWindowHeight = height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WorldWidth / 2, WorldWidth / 2,
        -WorldHeight / 2, WorldWidth / 2,
        -WorldDeep / 2, WorldDeep / 2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -30, 0, 0, 0, -100, 0, 1, 0);
}

void interact(int key, int x, int y) 
{
    if (key == GLUT_KEY_UP) { walkY += 1; Lpos++; }
    if (key == GLUT_KEY_DOWN) { walkY -= 1; Lpos--; }
    if (key == GLUT_KEY_RIGHT) { walkX += 1; Jpos++; }
    if (key == GLUT_KEY_LEFT) { walkX -= 1; Jpos--; }
    if (key == GLUT_KEY_HOME) {
        glutDisplayFunc(DisplayTheGame);
    }



}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    PlaySound(TEXT("getout"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("GET OUT");
    glutDisplayFunc(DisplayTheFirstFrame);
    glutSpecialFunc(interact);
    glutReshapeFunc(myReshape);
    glutMainLoop();
    return 0;
}

