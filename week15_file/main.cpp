#include <stdio.h>
#include <GL/glut.h>
float angle[20]={},diff=2;
int angleID=0; ///現在要改第幾個
void timer(int t)
{
    glutTimerFunc(30,timer,t+1);
    angle[angleID]+=diff;
    if(angle[angleID]>90) diff=-2;
    if(angle[angleID]<0) diff=+2;
    glutPostRedisplay();///現在這個比較好，以前會用display()重畫
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='1') angleID=1;
    if(key=='0') angleID=0;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot(0.3);///身體
        glPushMatrix();
            glTranslatef(-0.3,0,0);///(3)掛在正確的地方
            glRotatef(angle[0],0,0,1);///(2)旋轉
            glTranslatef(-0.3,0,0);///(1)把關節旋轉中心放到畫面中心
            glutSolidTeapot(0.3);///左手臂(重疊了)
            glPushMatrix();
                glTranslatef(-0.3,0,0);///(3)掛在正確的地方
                glRotatef(angle[0],0,0,1);///(2)旋轉
                glTranslatef(-0.3,0,0);///(1)把關節旋轉中心放到畫面中心
                glutSolidTeapot(0.3);///左手肘(重疊了)
            glPopMatrix();
        glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week15 file");

    glutKeyboardFunc(keyboard); ///整合
    glutTimerFunc(0,timer,0);
    glutDisplayFunc(display);
    glutMainLoop();
}
