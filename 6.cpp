#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

GLsizei wh = 500, ww = 500;
GLfloat size = 3.0;

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void drawsquare(int x, int y)
{
    y = wh - y;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(x + size, y + size);
    glVertex2f(x - size, y + size);
    glVertex2f(x - size, y - size);
    glVertex2f(x + size, y - size);
    glEnd();
    glFlush();
}

void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        drawsquare(x, y);

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        exit(0);
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
    glMatrixMode(GL_MODELVIEW);
    ww = w;
    wh = h;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Square");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    glutMainLoop();
    return 0;
}