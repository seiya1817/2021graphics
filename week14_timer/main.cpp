#include <GL/glut.h>
float angle=0;
void drawArm1()
{
    glPushMatrix();
        glScalef(1,0.5,0.5);
        glColor3f(0,1,0); glutSolidCube(0.2);
    glPopMatrix();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1); glutSolidCube(0.4);
        glPushMatrix();
            glTranslatef(-0.2,0.2,0);///(3)掛上肩膀
            glRotatef(angle,0,0,1);///(2)轉動
            glTranslatef(-0.1,0,0);///(1)先把旋轉中心移到手臂關節
            drawArm1();///綠色手臂
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int diff=2;
void timer(int t)
{
    glutTimerFunc(30,timer,t+1);
    if(angle>90) diff=-2;
    if(angle<0) diff=2;
    angle+=diff;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14 timer");

    glutDisplayFunc(display);
    glutTimerFunc(3000,timer,0);
    glutMainLoop();
}
