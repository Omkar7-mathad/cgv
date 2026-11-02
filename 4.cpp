#include <GL/glut.h>
#include <stdlib.h>

#define FACE  1
#define EYE   2
#define EAR   3
#define NOSE  4
#define MOUTH 5

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    /* Face display list */
    glNewList(FACE, GL_COMPILE);
        glBegin(GL_LINE_LOOP);
            glVertex2f(20, 10);
            glVertex2f(70, 10);
            glVertex2f(70, 70);
            glVertex2f(20, 70);
        glEnd();
    glEndList();

    /* Eye display list */
    glNewList(EYE, GL_COMPILE);
        glBegin(GL_LINE_LOOP);
            glVertex2f(30, 50);
            glVertex2f(40, 50);
            glVertex2f(40, 60);
            glVertex2f(30, 60);
        glEnd();
    glEndList();

    /* Ear display list */
    glNewList(EAR, GL_COMPILE);
        glBegin(GL_LINE_LOOP);
            glVertex2f(10, 40);
            glVertex2f(20, 40);
            glVertex2f(20, 50);
            glVertex2f(10, 50);
        glEnd();
    glEndList();

    /* Nose display list */
    glNewList(NOSE, GL_COMPILE);
        glBegin(GL_LINE_LOOP);
            glVertex2f(40, 30);
            glVertex2f(50, 30);
            glVertex2f(50, 40);
            glVertex2f(40, 40);
        glEnd();
    glEndList();

    /* Mouth display list */
    glNewList(MOUTH, GL_COMPILE);
        glBegin(GL_LINE_LOOP);
            glVertex2f(35, 15);
            glVertex2f(55, 15);
            glVertex2f(55, 20);
            glVertex2f(35, 20);
        glEnd();
    glEndList();

    /* Draw face */
    glCallList(FACE);

    /* Draw left eye */
    glCallList(EYE);

    /* Draw right eye */
    glPushMatrix();
        glTranslatef(20, 0, 0);
        glCallList(EYE);
    glPopMatrix();

    /* Draw left ear */
    glCallList(EAR);

    /* Draw right ear */
    glPushMatrix();
        glTranslatef(60, 0, 0);
        glCallList(EAR);
    glPopMatrix();
    /* Draw nose and mouth */
    glCallList(NOSE);
    glCallList(MOUTH);

    glFlush();
}

void myinit(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Human Face Using Display Lists");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
