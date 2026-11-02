#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat r1 = 1.0, r2 = 0.5, r3 = 0.5;
GLfloat b1 = 1.0, b2 = 1.0, b3 = 1.0;
GLfloat t1 = 1.0, t2 = 0.5, t3 = 0.0;

void change(void);
void display(void);

void top()
{
    glBegin(GL_TRIANGLES);
    glColor3f(r1, r2, r3);
    glVertex2f(100.0, 400.0);
    glVertex2f(150.0, 400.0);
    glVertex2f(125.0, 450.0);
    glEnd();
    glFlush();
}

void body()
{
    glBegin(GL_QUADS);
    glColor3f(b1, b2, b3);
    glVertex2f(100.0, 400.0);
    glVertex2f(150.0, 400.0);
    glVertex2f(150.0, 250.0);
    glVertex2f(100.0, 250.0);
    glEnd();
    glFlush();
}

void tail()
{
    glBegin(GL_TRIANGLES);

    glColor3f(t1, t2, t3);
    glVertex2f(100.0, 250.0);
    glVertex2f(150.0, 250.0);
    glVertex2f(75.0, 100.0);

    glVertex2f(100.0, 250.0);
    glVertex2f(150.0, 250.0);
    glVertex2f(175.0, 100.0);

    glEnd();
    glFlush();
}

void display()
{
    char key;
    glClear(GL_COLOR_BUFFER_BIT);
    top();
    body();
    tail();
    printf("Press C to change color and Q to quit: ");
    scanf(" %c", &key);

    if (key == 'c' || key == 'C')
        change();

    if (key == 'q' || key == 'Q')
        exit(0);
}

void change()
{
    int x;

    do
    {
        printf("\n1. Top\n2. Body\n3. Tail\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &x);

        switch (x)
        {
            case 1:
                printf("Enter RGB components for the top (0 to 1): ");
                scanf("%f %f %f", &r1, &r2, &r3);
                break;

            case 2:
                printf("Enter RGB components for the body (0 to 1): ");
                scanf("%f %f %f", &b1, &b2, &b3);
                break;

            case 3:
                printf("Enter RGB components for the tail (0 to 1): ");
                scanf("%f %f %f", &t1, &t2, &t3);
                break;

            case 4:
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (x != 4);
    glutPostRedisplay();
}

void myinit()
{
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Rocket");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}