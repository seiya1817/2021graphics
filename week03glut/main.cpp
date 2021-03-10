#include <GL/glut.h>
#include <math.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<30;i++)
    {
        float a=3.1415928*2/30*i;
        glVertex2f(0.5+0.1*cos(a),0.3*sin(a));
    }
    glEnd();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week03-circle");///�ثe�S�}3D�\��A�᭱�e���|�\��e���e���A�����T

    glutDisplayFunc(display);

    glutMainLoop();
}
