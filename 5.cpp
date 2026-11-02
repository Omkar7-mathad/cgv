#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void drawsquare()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(30, 0);
    glVertex2f(30, 30);
    glVertex2f(0, 30);
    glEnd();
    glFlush();
}
void mymouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        drawsquare();

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        exit(0);
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Square");
    myinit();
    glutDisplayFunc(display);
    glutMouseFunc(mymouse);
    glutMainLoop();
    return 0;
}