#include <stdio.h>
#include <GL/glut.h>
float angle[20]={},diff=2;
float angleOld[20]={},angleNew[20]={};
int angleID=0; ///現在要改第幾個
int oldX=0;
FILE*fout=NULL;
FILE*fin=NULL;
void timer(int t)
{
    glutTimerFunc(30,timer,t+1);
    if(t%10==0)///每10frame，就讀一筆新資料
    {
        for(int i=0;i<20;i++) angleOld[i]=angleNew[i];
        ///讀新資料之前先把資料備份
        if(fin==NULL) fin=fopen("angle.txt","r");
        for(int i=0;i<20;i++) fscanf(fin,"%f",&angleNew[i]);
        ///再讀入新資料
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
    oldX=x;///當mouse按下去時，記下位置
}
void motion(int x, int y)
{
    angle[angleID]+=x-oldX;///用x-oldX
    oldX=x;///再更新位置
    glutPostRedisplay();///現在這個比較好，以前會用display()重畫

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
        glutSolidTeapot(0.3);///身體
        glPushMatrix();
            glTranslatef(-0.3,0,0);///(3)掛在正確的地方
            glRotatef(angle[0],0,0,1);///(2)旋轉
            glTranslatef(-0.3,0,0);///(1)把關節旋轉中心放到畫面中心
            glutSolidTeapot(0.3);///左手臂(重疊了)
            glPushMatrix();
                glTranslatef(-0.3,0,0);///(3)掛在正確的地方
                glRotatef(angle[1],0,0,1);///(2)旋轉
                glTranslatef(-0.3,0,0);///(1)把關節旋轉中心放到畫面中心
                glutSolidTeapot(0.3);///左手肘(重疊了)
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3,0,0);///(3)掛在正確的地方
            glRotatef(-angle[2],0,0,1);///(2)旋轉
            glTranslatef(0.3,0,0);///(1)把關節旋轉中心放到畫面中心
            glutSolidTeapot(0.3);///右手臂(重疊了)
            glPushMatrix();
                glTranslatef(0.3,0,0);///(3)掛在正確的地方
                glRotatef(-angle[3],0,0,1);///(2)旋轉
                glTranslatef(0.3,0,0);///(1)把關節旋轉中心放到畫面中心
                glutSolidTeapot(0.3);///右手肘(重疊了)
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
    glutKeyboardFunc(keyboard); ///整合
    glutTimerFunc(0,timer,0);
    glutDisplayFunc(display);
    glutMainLoop();
}
