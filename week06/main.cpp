#include <GL/glut.h>
float angle=0;
void hand()
{
    glPushMatrix();
        glScalef(0.5,0.1,0.1);///�j�p
        glColor3f(0,0,1);///�C��
        glutSolidCube(1);///���
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1); glutSolidCube(0.5);

    ///�k�b��
    glPushMatrix();///�ƥ��x�}
        glTranslatef(0.25,0.25,0);///�N�F���Ӳ���k�W
        glRotatef(angle,0,0,1);///����
        glTranslatef(0.25,0,0);///�N����b�߲��쩳��
        hand();///�I�shand(�W���u)
        glPushMatrix();
            glTranslatef(0.25,0,0);///�������k����
            glRotatef(angle,0,0,1);
            glTranslatef(0.25,0,0);
            hand();///hand(�U���u)
        glPopMatrix();
    glPopMatrix();///����x�}

    ///���b��
    glPushMatrix();///�ƥ��x�}
        glTranslatef(-0.25,0.25,0);///�N�F���Ӳ��쥪�W
        glRotatef(-angle,0,0,1);///����
        glTranslatef(-0.25,0,0);///�N����b�߲��쩳��
        hand();///�I�shand(�W���u)
        glPushMatrix();
            glTranslatef(-0.25,0,0);///������������
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.25,0,0);
            hand();///hand(�U���u)
        glPopMatrix();
    glPopMatrix();///����x�}

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
