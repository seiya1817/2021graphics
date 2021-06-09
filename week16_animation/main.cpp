#include <stdio.h>
#include <GL/glut.h>
float angle[20]={},diff=2;
float angleOld[20]={},angleNew[20]={};
int angleID=0; ///�F��Ҫ�ĵڎׂ�
int oldX=0;
FILE*fout=NULL;
FILE*fin=NULL;
void timer(int t)
{
    glutTimerFunc(30,timer,t+1);
    if(t%10==0)///ÿ10frame�����xһ�P���Y��
    {
        for(int i=0;i<20;i++) angleOld[i]=angleNew[i];
        ///�x���Y��֮ǰ�Ȱ��Y�ς��
        if(fin==NULL) fin=fopen("angle.txt","r");
        for(int i=0;i<20;i++) fscanf(fin,"%f",&angleNew[i]);
        ///���x�����Y��
    }
    float alpha=(t%10)/10.0;
    for(int i=0;i<20;i++)
    {
        angle[i]=alpha*angleNew[i]+(1-alpha)*angleOld[i];
    }
    glutPostRedisplay();
}
void mouse(int button, int state,int x,int y)
{
    oldX=x;///��mouse����ȥ�r��ӛ��λ��
}
void motion(int x, int y)
{
    angle[angleID]+=x-oldX;///��x-oldX
    oldX=x;///�ٸ���λ��
    glutPostRedisplay();///�F���@�����^�ã���ǰ����display()�خ�

//    if(fout==NULL) fout=fopen("angle.txt","w+");
//    for(int i=0;i<20;i++) fprintf(fout,"%.1f",angle[i]);
//    fprintf(fout,"\n");
//    for(int i=0;i<20;i++) printf("%.1f",angle[i]);
//    printf("\n");
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;

    if(key=='s')///save
    {
        if(fout==NULL) fout=fopen("angle.txt","w+");
        for(int i=0;i<20;i++) fprintf(fout,"%.1f",angle[i]);
        fprintf(fout,"\n");
        for(int i=0;i<20;i++) printf("%.1f",angle[i]);
        printf("\n");
    }
    if(key=='r')///read
    {
        if(fin==NULL) fin=fopen("angle.txt","r");
        for(int i=0;i<20;i++) fscanf(fin,"%f",&angle[i]);
        glutPostRedisplay();
    }
    if(key=='p')///play
    {

    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glutSolidTeapot(0.3);///���w
        glPushMatrix();
            glTranslatef(-0.3,0,0);///(3)�������_�ĵط�
            glRotatef(angle[0],0,0,1);///(2)���D
            glTranslatef(-0.3,0,0);///(1)���P�����D���ķŵ���������
            glutSolidTeapot(0.3);///���ֱ�(�دB��)
            glPushMatrix();
                glTranslatef(-0.3,0,0);///(3)�������_�ĵط�
                glRotatef(angle[1],0,0,1);///(2)���D
                glTranslatef(-0.3,0,0);///(1)���P�����D���ķŵ���������
                glutSolidTeapot(0.3);///������(�دB��)
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3,0,0);///(3)�������_�ĵط�
            glRotatef(-angle[2],0,0,1);///(2)���D
            glTranslatef(0.3,0,0);///(1)���P�����D���ķŵ���������
            glutSolidTeapot(0.3);///���ֱ�(�دB��)
            glPushMatrix();
                glTranslatef(0.3,0,0);///(3)�������_�ĵط�
                glRotatef(-angle[3],0,0,1);///(2)���D
                glTranslatef(0.3,0,0);///(1)���P�����D���ķŵ���������
                glutSolidTeapot(0.3);///������(�دB��)
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16 animation");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard); ///����
    glutTimerFunc(0,timer,0);
    glutDisplayFunc(display);
    glutMainLoop();
}
