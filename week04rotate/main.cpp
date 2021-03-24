#include <GL/glut.h>
int n=0,vx[3000],vy[3000];
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle,0,0,1);
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<n;i++)
        {
            glVertex2f((vx[i]-150)/150.0,-(vy[i]-150)/150.0);
        }
        glEnd();
    glPopMatrix();///釋放矩陣
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
    angle+=10;
    display();
}
void motion(int x,int y)
{   ///把x,y值存起來
    vx[n]=x;vy[n]=y;
    n++;
    display();///邊動邊畫
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week04-mouse");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///呼叫keyboard函式，按按鍵就會旋轉
    glutMotionFunc(motion);

    glutMainLoop();
}
