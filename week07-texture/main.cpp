#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * quad;///TODO: Quad
void init()///copy �� http://hackmd.io/@jsyeh/opengl
{
    IplImage * img = cvLoadImage("back.jpg"); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    quad = gluNewQuadric();///TODO: Quad
}   ///�̫�@�����/�̭��n, �ҶK�ϼv������Ƴ��]�w�n
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�۰���ܫ�
        glRotatef(90, 1,0,0);
        glRotatef(angle, 0,0,1);///�۰���ܫ�
        gluQuadricTexture(quad, 1);
        gluSphere(quad, 0.5, 30, 30);///glutSolidTeapot(0.3);
    glPopMatrix();///�۰���ܫ�
    ///glutSolidTeapot(0.3);
    glutSwapBuffers();
    angle++;
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week07 texture");
    glutDisplayFunc(display);
    glutIdleFunc(display);///�����S�ƭ��e(�n���e�~�|��)
    glEnable(GL_DEPTH_TEST);///TODO: ��3D���`�״���(�e���|�\���᭱)
    init();///�W����OpenGL���]�n��, �~�]�w OpenCV ���K�Ϩ� OpenGL�W��
    glutMainLoop();
}
