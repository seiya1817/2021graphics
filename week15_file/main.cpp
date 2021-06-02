#include <stdio.h>
#include <GL/glut.h>
float angle[20]={},diff=2;
int angleID=0; ///�{�b�n��ĴX��
void timer(int t)
{
    glutTimerFunc(30,timer,t+1);
    angle[angleID]+=diff;
    if(angle[angleID]>90) diff=-2;
    if(angle[angleID]<0) diff=+2;
    glutPostRedisplay();///�{�b�o�Ӥ���n�A�H�e�|��display()���e
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='1') angleID=1;
    if(key=='0') angleID=0;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot(0.3);///����
        glPushMatrix();
            glTranslatef(-0.3,0,0);///(3)���b���T���a��
            glRotatef(angle[0],0,0,1);///(2)����
            glTranslatef(-0.3,0,0);///(1)�����`���त�ߩ��e������
            glutSolidTeapot(0.3);///�����u(���|�F)
            glPushMatrix();
                glTranslatef(-0.3,0,0);///(3)���b���T���a��
                glRotatef(angle[0],0,0,1);///(2)����
                glTranslatef(-0.3,0,0);///(1)�����`���त�ߩ��e������
                glutSolidTeapot(0.3);///����y(���|�F)
            glPopMatrix();
        glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week15 file");

    glutKeyboardFunc(keyboard); ///��X
    glutTimerFunc(0,timer,0);
    glutDisplayFunc(display);
    glutMainLoop();
}
