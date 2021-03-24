#include <GL/glut.h>
int n=0,vx[3000],vy[3000];
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�ƥ��x�}
        glRotatef(angle,0,0,1);
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<n;i++)
        {
            glVertex2f((vx[i]-150)/150.0,-(vy[i]-150)/150.0);
        }
        glEnd();
    glPopMatrix();///����x�}
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
    angle+=10;
    display();
}
void motion(int x,int y)
{   ///��x,y�Ȧs�_��
    vx[n]=x;vy[n]=y;
    n++;
    display();///�����e
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week04-mouse");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///�I�skeyboard�禡�A������N�|����
    glutMotionFunc(motion);

    glutMainLoop();
}
