#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void line()
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}

void point()
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);
    glEnd();
    glFlush();
}

void main_menu(int id)
{
    switch (id)
    {
        case 1:
            exit(0);
            break;

        default:
            break;
    }
}

void sub_menu(int id)
{
    switch (id)
    {
        case 1:
            line();
            break;

        case 2:
            point();
            break;

        default:
            break;
    }
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hierarchical Menu");
    glutDisplayFunc(myDisplay);
    myinit();
    /* Create submenu */
    int subMenu = glutCreateMenu(sub_menu);
    glutAddMenuEntry("Line", 1);
    glutAddMenuEntry("Point", 2);
    /* Create main menu */
    glutCreateMenu(main_menu);
    glutAddMenuEntry("Quit", 1);
    glutAddSubMenu("Primitive", subMenu);
    /* Attach menu to right mouse button */
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}