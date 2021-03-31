#include <GL/glut.h>
float angle=0;
void hand()
{
    glPushMatrix();
        glScalef(0.5,0.1,0.1);///大小
        glColor3f(0,0,1);///顏色
        glutSolidCube(1);///方塊
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1); glutSolidCube(0.5);

    ///右半邊
    glPushMatrix();///備份矩陣
        glTranslatef(0.25,0.25,0);///將東西整個移到右上
        glRotatef(angle,0,0,1);///旋轉
        glTranslatef(0.25,0,0);///將旋轉軸心移到底邊
        hand();///呼叫hand(上手臂)
        glPushMatrix();
            glTranslatef(0.25,0,0);///直直往右移動
            glRotatef(angle,0,0,1);
            glTranslatef(0.25,0,0);
            hand();///hand(下手臂)
        glPopMatrix();
    glPopMatrix();///釋放矩陣

    ///左半邊
    glPushMatrix();///備份矩陣
        glTranslatef(-0.25,0.25,0);///將東西整個移到左上
        glRotatef(-angle,0,0,1);///旋轉
        glTranslatef(-0.25,0,0);///將旋轉軸心移到底邊
        hand();///呼叫hand(上手臂)
        glPushMatrix();
            glTranslatef(-0.25,0,0);///直直往左移動
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.25,0,0);
            hand();///hand(下手臂)
        glPopMatrix();
    glPopMatrix();///釋放矩陣

    glutSwapBuffers();
    angle++;
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week04-mouse");

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
}
