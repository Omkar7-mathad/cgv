#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
GLfloat theta = 0.0f;
void display()
{
    GLfloat angle = theta * 3.141f/180.0f;
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0, 0.4, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-cos(angle), -sin(angle));
    glVertex2f(sin(angle), -cos(angle));
    glVertex2f(cos(angle), sin(angle));
    glVertex2f(-sin(angle), cos(angle));
    glEnd();
    glFlush();
}

void idle()
{
    theta += 0.1f;
    if (theta >= 360.0f)
        theta -= 360.0f;
    glutPostRedisplay();
}

void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        glutIdleFunc(idle);
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        glutIdleFunc(NULL);
}

void myKey(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        exit(0);
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2, 2, -2, 2);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Rotating Square");
    myinit();
    glutMouseFunc(myMouse);
    glutKeyboardFunc(myKey);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}