#include <GL/glut.h>
#include <cmath>
#include <ctime>

GLint Delta = 0; //�ð�
GLint sw = 0; //����� ����
GLint sww = 0; //����
GLint color = 0; //������
GLint colortime = 0; //���������� Ÿ�̸�
GLfloat jp = 0; //ĳ���Ͱ� �����̴°�ó�� ���Ʒ�
GLfloat angle = 0; // 360ȸ��
GLfloat redX = 1; //��� �پ������� Ÿ�̸�
GLfloat x = 0.0; // ��

float increment = 1.0;
float Move;
float Time;
float Timesec = 0.665;
float Xmove = 0;
float h_Delta = 0;
float h_increment = 1.0f;
float h_time;
float h_Move;
float hun_Move;
float h_a;
float h_angle; // ȸ�� ����

bool stop = false;
bool isAnimating = true; // �ִϸ��̼� ����

GLfloat MyVertices[8][3] = {
    {-0.5,-0.5,0.5},
    {-0.5,0.5,0.5},
    {0.5,0.5,0.5},
    {0.5,-0.5,0.5},
    {-0.5,-0.5,-0.5},
    {-0.5,0.5,-0.5},
    {0.5,0.5,-0.5},
    {0.5,-0.5,-0.5} };

GLfloat h_colors[6][4] = {
    {0.1,0.1,0.1,1}, // �ո� (������)
    {0.1,0.1,0.1,1}, // �޸� (�ʷϻ�)
    {0.1,0.1,0.1,1}, // ���ʸ� (�Ķ���)
    {0.1,0.1,0.1,1}, // �����ʸ� (�����)
    {0.1,0.1,0.1,1}, // ���ʸ� (��ȫ��)
    {0.1,0.1,0.1,1}  // �Ʒ��ʸ� (ȸ��)
};

void elevator1();
void elevatorIn();
void elevatorClose();
void Entrance();
void Entrance1();
void EntranceOut1();
void doorset();
void wall();
void door();
void coffee();
void elevatorOpen();

//------22124992 ������ ---------------------------------------------------------

//â�� ���
void h_window() {
    glTranslatef(0, -0.1, 0.0);
    glColor3f(0, 0.5, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.4);
    glVertex2f(0.3, -0.4);
    glVertex2f(-0.3, -0.4);
    glVertex2f(-0.3, 0.4);
    glEnd();
    //â����
    glPushMatrix();
    glTranslatef(0, 0.4, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0.8);
    glVertex2f(0.31, 0.015);
    glVertex2f(0.31, -0.015);
    glVertex2f(-0.31, -0.015);
    glVertex2f(-0.31, 0.015);
    glEnd();
    glPopMatrix();
    //â�� �߰�
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0.8);
    glVertex2f(0.3, 0.015);
    glVertex2f(0.3, -0.015);
    glVertex2f(-0.3, -0.015);
    glVertex2f(-0.3, 0.015);
    glEnd();
    glPopMatrix();
    //â�� ����
    glPushMatrix();
    glTranslatef(-0.3, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0.8);
    glVertex2f(0.01, 0.4);
    glVertex2f(0.01, -0.4);
    glVertex2f(-0.01, -0.4);
    glVertex2f(-0.01, 0.4);
    glEnd();
    glPopMatrix();
    //â�� ������
    glPushMatrix();
    glTranslatef(0.3, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0.8);
    glVertex2f(0.01, 0.4);
    glVertex2f(0.01, -0.4);
    glVertex2f(-0.01, -0.4);
    glVertex2f(-0.01, 0.4);
    glEnd();
    glPopMatrix();

    //�ǹ� 1��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.6, 0.8, 0.9, 0.45);
    glTranslatef(-0.19, -0.25, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(-0.1, -0.15);
    glVertex2f(-0.1, 0.15);
    glEnd();
    glPopMatrix();

    //�ǹ� 1�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.25, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.2, -0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.15, -0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 4�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.15, -0.325, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 5�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.25, -0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 6�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.2, -0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 7�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.15, -0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.8, 0.9, 0.5);
    glTranslatef(0.05, -0.23, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.17);
    glVertex2f(0.1, -0.17);
    glVertex2f(-0.1, -0.17);
    glVertex2f(-0.1, 0.17);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 1��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.0, -0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 2��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.1, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 3��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.07, -0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 4��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.0, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 5��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.02, -0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 6��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.1, -0.125, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.8, 0.9, 0.7);
    glTranslatef(0.24, -0.25, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.15);
    glVertex2f(0.05, -0.15);
    glVertex2f(-0.05, -0.15);
    glVertex2f(-0.05, 0.15);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 1��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.25, -0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 2��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.22, -0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 3��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.27, -0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 4��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.21, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();


    //�ϴ�
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.82, 0.85, 0.7);
    glTranslatef(0.1, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.7, 0.8, 0.8);
    glTranslatef(0.15, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.75, 0.82, 0.85);
    glTranslatef(0.15, 0.31, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.82, 0.85, 0.5);
    glTranslatef(-0.2, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.8, 0.8, 0.7);
    glTranslatef(-0.17, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.82, 0.85, 0.75);
    glTranslatef(-0.17, 0.26, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.82, 0.85, 0.7);
    glTranslatef(0.2, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.8, 0.8, 0.75);
    glTranslatef(0.19, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.85, 0.9, 0.6);
    glTranslatef(0.17, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 1��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.3);
    glTranslatef(0.2, 0.13, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 2��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.25);
    glTranslatef(0.18, 0.13, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 3��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.2);
    glTranslatef(0.2, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 4��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.3);
    glTranslatef(0.13, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 5��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.25);
    glTranslatef(0.13, 0.32, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 6��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.35);
    glTranslatef(0.15, 0.32, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 7��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.5);
    glTranslatef(-0.2, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 8��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.6);
    glTranslatef(-0.2, 0.23, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 9��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.55);
    glTranslatef(-0.18, 0.23, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();
}

void elevator1() {
    glTranslatef(0, 0, 0);
    glColor3f(0.5, 0.6, 0.65);
    glBegin(GL_POLYGON);
    glVertex2f(-0.24, -0.5);
    glVertex2f(-0.24, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.24, -0.5);
    glEnd();

    //��ǻ�� �ν� ���� �׵θ�
    glPushMatrix();
    glTranslatef(-0.24, -0.2, 0);
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.3);
    glVertex2f(0.01, -0.3);
    glVertex2f(-0.01, -0.3);
    glVertex2f(-0.01, 0.3);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� ������ �׵θ�
    glPushMatrix();
    glTranslatef(0.24, -0.2, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.3);
    glVertex2f(0.01, -0.3);
    glVertex2f(-0.01, -0.3);
    glVertex2f(-0.01, 0.3);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� ���� �׵θ�
    glPushMatrix();
    glTranslatef(0, 0.1, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.25, 0.005);
    glVertex2f(0.25, -0.005);
    glVertex2f(-0.25, -0.005);
    glVertex2f(-0.25, 0.005);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� �߰� �׵θ�
    glPushMatrix();
    glTranslatef(0, -0.2, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.005, 0.3);
    glVertex2f(0.005, -0.3);
    glVertex2f(-0.005, -0.3);
    glVertex2f(-0.005, 0.3);
    glEnd();
    glPopMatrix();

    //���� �� ������
    glPushMatrix();
    glTranslatef(0, -0.1, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.24, 0.25);
    glVertex2f(-0.24, 0.4);
    glVertex2f(0.24, 0.4);
    glVertex2f(0.24, 0.25);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(0.01, -0.07, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.265);
    glVertex2f(-0.01, 0.335);
    glVertex2f(0.0, 0.335);
    glVertex2f(0.0, 0.265);
    glEnd();
    glPopMatrix();
}

void h_elevatorIn() {

    //�Ͼ� ���
    glTranslatef(0, 0, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.24, -0.5);
    glVertex2f(-0.24, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.24, -0.5);
    glEnd();

    //���� ȸ�� ��
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.18, -0.45);
    glVertex2f(-0.18, 0.05);
    glVertex2f(0.18, 0.05);
    glVertex2f(0.18, -0.45);
    glEnd();
    glPopMatrix();

    //�Ʒ� �ٴ�
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(-0.24, -0.5);
    glVertex2f(-0.18, -0.45);
    glVertex2f(0.18, -0.45);
    glVertex2f(0.24, -0.5);
    glEnd();
    glPopMatrix();

    //��
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex2f(-0.18, 0.05);
    glVertex2f(-0.24, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.18, 0.05);
    glEnd();
    glPopMatrix();

    //���� �� ����
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.3, 0.3, 1);
    glBegin(GL_QUADS);
    glVertex2f(-0.13, 0);
    glVertex2f(-0.13, -0.2);
    glVertex2f(0.13, -0.2);
    glVertex2f(0.13, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.08, 0);
    glScalef(0.42, 0.25, 0);
    h_window();
    glEnd();
    glPopMatrix();

    //���� ���� �׵θ�
    glPushMatrix();
    glTranslatef(-0.24, -0.2, 0);
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.3);
    glVertex2f(0.01, -0.3);
    glVertex2f(-0.01, -0.3);
    glVertex2f(-0.01, 0.3);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� ������ �׵θ�
    glPushMatrix();
    glTranslatef(0.24, -0.2, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.3);
    glVertex2f(0.01, -0.3);
    glVertex2f(-0.01, -0.3);
    glVertex2f(-0.01, 0.3);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� ���� �׵θ�
    glPushMatrix();
    glTranslatef(0, 0.1, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.25, 0.005);
    glVertex2f(0.25, -0.005);
    glVertex2f(-0.25, -0.005);
    glVertex2f(-0.25, 0.005);
    glEnd();
    glPopMatrix();

    //���� �� ������
    glPushMatrix();
    glTranslatef(0, -0.1, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.24, 0.25);
    glVertex2f(-0.24, 0.4);
    glVertex2f(0.24, 0.4);
    glVertex2f(0.24, 0.25);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(0.01, -0.07, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.265);
    glVertex2f(-0.01, 0.335);
    glVertex2f(0.0, 0.335);
    glVertex2f(0.0, 0.265);
    glEnd();
    glPopMatrix();
}

void drawCubeEdges() {
    glColor3f(0.0f, 0.0f, 0.0f); // �� ���� (������)
    glBegin(GL_LINES);

    // �ո� ��
    glVertex3fv(MyVertices[0]); glVertex3fv(MyVertices[1]);
    glVertex3fv(MyVertices[1]); glVertex3fv(MyVertices[2]);
    glVertex3fv(MyVertices[2]); glVertex3fv(MyVertices[3]);
    glVertex3fv(MyVertices[3]); glVertex3fv(MyVertices[0]);

    // �޸� ��
    glVertex3fv(MyVertices[4]); glVertex3fv(MyVertices[5]);
    glVertex3fv(MyVertices[5]); glVertex3fv(MyVertices[6]);
    glVertex3fv(MyVertices[6]); glVertex3fv(MyVertices[7]);
    glVertex3fv(MyVertices[7]); glVertex3fv(MyVertices[4]);

    // ���ʸ� ��
    glVertex3fv(MyVertices[0]); glVertex3fv(MyVertices[4]);
    glVertex3fv(MyVertices[3]); glVertex3fv(MyVertices[7]);

    // �����ʸ� ��
    glVertex3fv(MyVertices[1]); glVertex3fv(MyVertices[5]);
    glVertex3fv(MyVertices[2]); glVertex3fv(MyVertices[6]);

    // �Ʒ��ʸ� ��
    glVertex3fv(MyVertices[0]); glVertex3fv(MyVertices[4]);
    glVertex3fv(MyVertices[1]); glVertex3fv(MyVertices[5]);

    glEnd();
}

void Ten() {


    glColor3f(1.0, 0.84, 0); //���ڰ� ��
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.25);
    glVertex2f(-0.1, -0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(0.1, -0.25);
    glEnd();


    glPushMatrix();
    glColor3f(1.0, 0.84, 0); //���ڰ� �Ʒ�
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, -0.4);
    glVertex2f(-0.05, -0.08);
    glVertex2f(0.05, -0.08);
    glVertex2f(0.05, -0.4);
    glEnd();
    glPopMatrix();

}

void Death3() {


    glBegin(GL_POLYGON);
    glColor3fv(h_colors[0]); // �ո� ����
    glVertex3fv(MyVertices[0]);
    glVertex3fv(MyVertices[1]);
    glVertex3fv(MyVertices[2]);
    glVertex3fv(MyVertices[3]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(h_colors[1]); // �޸� ����
    glVertex3fv(MyVertices[4]);
    glVertex3fv(MyVertices[5]);
    glVertex3fv(MyVertices[6]);
    glVertex3fv(MyVertices[7]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(h_colors[2]); // ���ʸ� ����
    glVertex3fv(MyVertices[0]);
    glVertex3fv(MyVertices[3]);
    glVertex3fv(MyVertices[7]);
    glVertex3fv(MyVertices[4]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(h_colors[3]); // �����ʸ� ����
    glVertex3fv(MyVertices[1]);
    glVertex3fv(MyVertices[5]);
    glVertex3fv(MyVertices[6]);
    glVertex3fv(MyVertices[2]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(h_colors[4]); // ���ʸ� ����
    glVertex3fv(MyVertices[3]);
    glVertex3fv(MyVertices[2]);
    glVertex3fv(MyVertices[6]);
    glVertex3fv(MyVertices[7]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(h_colors[5]); // �Ʒ��ʸ� ����
    glVertex3fv(MyVertices[0]);
    glVertex3fv(MyVertices[1]);
    glVertex3fv(MyVertices[5]);
    glVertex3fv(MyVertices[4]);
    glEnd();
    glEnd();

}

void Dong() {


    //�Ӹ�
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.03, 0.1, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();


    //�� (��� ���)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();

    //�� (��� ���)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();


    //���� (����)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //���� (����)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();


    //�Ӹ�ī��
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //�Ӹ�ī��
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //�Ӹ�ī��
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.0305, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.035, 0);
    glEnd();
    glPopMatrix();

    //�� (����)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.06, 0.05, 0.0);
    glColor3f(0.8, 0.1, 0.1);
    glutSolidSphere(0.02, 30, 20);
    glEnd();
    glPopMatrix();

    //�� (��)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.055, 0.05, 0.0);
    glColor3f(0.8, 0.3, 0);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();
}

void h_charater() {

    //����
    glPushMatrix();
    glRotatef(-30, 0, 0, 1);
    glTranslatef(-0.5, -0.6, 0);
    glColor3f(0.9, 0.5, 0.0);
    glScalef(0.65, 1.4, 0.1);
    glutSolidSphere(0.1, 20, 10);
    glEnd();
    glPopMatrix();

    //�Ӹ�
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.65, -0.15, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();

    //����
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-1.13, -0.23, 0.0);
    glScalef(4, 4, 1);
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(0.11, 0);
    glVertex2f(0.1, 0.02);
    glVertex2f(0.14, 0.02);
    glVertex2f(0.13, 0);
    glEnd();
    glPopMatrix();

    //��
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.77, -0.2, 0.0);
    glScalef(1, 1, 1);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, 0.02);

    glVertex2f(0.12, 0);
    glVertex2f(0.14, 0.02);
    glEnd();
    glPopMatrix();

    //���� (����) ��
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.67, -0.13, 0.0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.015, 30, 20);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //���� (����) ��
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.63, -0.13, 0.0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.015, 30, 20);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //�����ָ�
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.78, -0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glLineWidth(0.7);
    glBegin(GL_LINES);
    glVertex2f(0.16, 0.0);
    glVertex2f(0.1, 0.0);

    glVertex2f(0.16, 0.01);
    glVertex2f(0.1, 0.01);
    glEnd();
    glPopMatrix();

    //����1
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.75, -0.3, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //����2
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.73, -0.25, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

}

void Face() {

    //�Ӹ�
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.65, -0.15, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();

    //����
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-1.13, -0.23, 0.0);
    glScalef(4, 4, 1);
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(0.11, 0);
    glVertex2f(0.1, 0.02);
    glVertex2f(0.14, 0.02);
    glVertex2f(0.13, 0);
    glEnd();
    glPopMatrix();

    //��
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.77, -0.2, 0.0);
    glScalef(1, 1, 1);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, 0.02);

    glVertex2f(0.12, 0);
    glVertex2f(0.14, 0.02);
    glEnd();
    glPopMatrix();

    //���� (����) ��
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.67, -0.13, 0.0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.015, 30, 20);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //���� (����) ��
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.63, -0.13, 0.0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.015, 30, 20);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //�����ָ�
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.78, -0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glLineWidth(0.7);
    glBegin(GL_LINES);
    glVertex2f(0.16, 0.0);
    glVertex2f(0.1, 0.0);

    glVertex2f(0.16, 0.01);
    glVertex2f(0.1, 0.01);
    glEnd();
    glPopMatrix();

}

void h_leftarm() {

    //���� �� ���κ�
    glPushMatrix();
    glTranslatef(-0.63, -0.27, 0.0);
    glRotatef(60, 0, 0, 1);
    glColor3f(0, 0, 0.7);
    glScalef(0.3, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //������ ������
    glPushMatrix();
    glTranslatef(-0.57, -0.3, 0.0);
    glRotatef(40, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.15, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //������
    glPushMatrix();
    glTranslatef(-0.56, -0.36, 0.0);
    glRotatef(10, 0, 0, 1);
    glColor3f(0.7, 0.7, 0.7);
    glScalef(0.1, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.3);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.3);
    glEnd();
    glPopMatrix();

}

void h_rightarm() {

    //��������
    glPushMatrix();
    glTranslatef(-0.8, -0.25, 0.0);
    glRotatef(140, 0, 0, 1);
    glColor3f(0, 0, 0.7);
    glScalef(0.3, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� ��
    glPushMatrix();
    glTranslatef(-0.82, -0.3, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.15, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();
}//1

void h_leftleg() {
    //���� �ٸ� ���κ�
    glPushMatrix();
    glTranslatef(-0.8, -0.4, 0.0);
    glRotatef(-15, 0, 0, 1);
    glColor3f(0.4, 0.7, 0.9);
    glScalef(0.3, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� �ٸ� �Ʒ��κ�
    glPushMatrix();
    glTranslatef(-0.8, -0.5, 0.0);
    glRotatef(190, 0, 0, 1);
    glColor3f(0.4, 0.7, 0.9);
    glScalef(0.2, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� �Ź�
    glPushMatrix();
    glTranslatef(-0.8, -0.56, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.25, 0.1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

}//1

void h_rightleg() {
    //���� �ٸ� ���κ�
    glPushMatrix();
    glTranslatef(-0.7, -0.4, 0.0);
    glRotatef(25, 0, 0, 1);
    glColor3f(0.4, 0.7, 0.9);
    glScalef(0.3, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� �ٸ� �Ʒ��κ�
    glPushMatrix();
    glTranslatef(-0.7, -0.5, 0.0);
    glRotatef(150, 0, 0, 1);
    glColor3f(0.4, 0.7, 0.9);
    glScalef(0.2, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� �Ź�
    glPushMatrix();
    glTranslatef(-0.72, -0.55, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.25, 0.1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

}//1

void Sun() {

    glColor3f(1.0, 1.0, 0.0); // �����(��)
    glTranslatef(0.8, 0.5, 0.0);
    glutSolidSphere(0.1, 50, 50);

}

void Hospital() {

    glColor3f(0.9, 0.9, 0.9); //����
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, -0.5);
    glVertex2f(-0.9, -0.5);
    glVertex2f(-0.9, -0.3);
    glVertex2f(-0.7, -0.3);
    glVertex2f(-0.7, -0.1);
    glVertex2f(-0.5, -0.1);
    glVertex2f(-0.5, -0.3);
    glVertex2f(-0.3, -0.3);
    glVertex2f(-0.3, -0.5);
    glEnd();

    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-0.15, -0.05, 0);
    glColor3f(0.0, 1.0, 0.3); // ���� ǥ��1
    glBegin(GL_QUADS);
    glVertex2f(-0.65, -0.3);
    glVertex2f(-0.65, -0.1);
    glVertex2f(-0.55, -0.1);
    glVertex2f(-0.55, -0.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-0.15, -0.05, 0);
    glColor3f(0.0, 1.0, 0.3);
    glBegin(GL_QUADS); // ���� ǥ��2
    glVertex2f(-0.7, -0.25);
    glVertex2f(-0.7, -0.15);
    glVertex2f(-0.5, -0.15);
    glVertex2f(-0.5, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //���� â�� 1
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.85, -0.35, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.85, -0.35);

    glVertex2f(-0.85, -0.35);
    glVertex2f(-0.75, -0.35);

    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.75, -0.45);

    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.85, -0.45);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //���� â�� 2
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.7, -0.35, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.85, -0.35);

    glVertex2f(-0.85, -0.35);
    glVertex2f(-0.75, -0.35);

    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.75, -0.45);

    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.85, -0.45);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    //���� â�� 3
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.7, -0.5, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.85, -0.35);

    glVertex2f(-0.85, -0.35);
    glVertex2f(-0.75, -0.35);

    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.75, -0.45);

    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.85, -0.45);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //���� â�� 4
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.85, -0.5, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.85, -0.35);

    glVertex2f(-0.85, -0.35);
    glVertex2f(-0.75, -0.35);

    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.75, -0.45);

    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.85, -0.45);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //���� â�� 5
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.05, -0.35, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.85, -0.35);

    glVertex2f(-0.85, -0.35);
    glVertex2f(-0.75, -0.35);

    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.75, -0.45);

    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.85, -0.45);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //���� â�� 6
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(0.1, -0.35, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.85, -0.35);

    glVertex2f(-0.85, -0.35);
    glVertex2f(-0.75, -0.35);

    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.75, -0.45);

    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.85, -0.45);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //���� â�� 7
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.05, -0.5, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.85, -0.35);

    glVertex2f(-0.85, -0.35);
    glVertex2f(-0.75, -0.35);

    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.75, -0.45);

    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.85, -0.45);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //���� â�� 8
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(0.1, -0.5, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.85, -0.35);

    glVertex2f(-0.85, -0.35);
    glVertex2f(-0.75, -0.35);

    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.75, -0.45);

    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.85, -0.45);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //���� �Ա�
    glColor3f(0.3, 0.8, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.65, -0.5);
    glVertex2f(-0.55, -0.5);
    glVertex2f(-0.55, -0.35);
    glVertex2f(-0.65, -0.35);
    glEnd();
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.65, -0.5);
    glVertex2f(-0.55, -0.5);

    glVertex2f(-0.55, -0.35);
    glVertex2f(-0.55, -0.5);

    glVertex2f(-0.65, -0.5);
    glVertex2f(-0.65, -0.35);

    glVertex2f(-0.55, -0.35);
    glVertex2f(-0.65, -0.35);

    glVertex2f(-0.6, -0.5);
    glVertex2f(-0.6, -0.35);

    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //���� �Ա� ������1
    glTranslatef(-0.62, -0.43, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.01, 20, 20);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    //���� �Ա� ������2
    glTranslatef(-0.58, -0.43, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.01, 20, 20);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.9, -0.5);
    glVertex2f(-0.9, -0.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.9, -0.3);
    glVertex2f(-0.7, -0.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.3);
    glVertex2f(-0.7, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.1);
    glVertex2f(-0.5, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.5, -0.1);
    glVertex2f(-0.5, -0.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.5, -0.3);
    glVertex2f(-0.3, -0.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.3, -0.3);
    glVertex2f(-0.3, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.3, -0.5);
    glVertex2f(-0.9, -0.5);
    glEnd();
    glPopMatrix();

}

void h_Wall() {

    glColor4f(0.75, 0.26, 0.16, 1.0); // ������ �߹�
    glBegin(GL_POLYGON);
    glVertex2f(0.45, -0.67);
    glVertex2f(0.45, 0.67);
    glVertex2f(0.7, 0.67);
    glVertex2f(0.7, -0.67);
    glEnd();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //âƲ
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0.45, -0.67);
    glVertex2f(0.45, 0.67);

    glVertex2f(0.7, 0.67);
    glVertex2f(0.7, -0.67);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.2, 0);
    glVertex2f(0 + 0.45, 0.1);
    glVertex2f(0 + 0.45, -0.6);
    glVertex2f(-0.23 + 0.45, -0.6);
    glVertex2f(-0.23 + 0.45, 0.1);
    glEnd();
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //âƲ
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0 + 0.45, 0.1);
    glVertex2f(0 + 0.45, -0.6);

    glVertex2f(-0.23 + 0.45, -0.6);
    glVertex2f(-0.23 + 0.45, 0.1);

    glVertex2f(-0.23 + 0.45, -0.6);
    glVertex2f(0 + 0.45, -0.6);

    glVertex2f(0 + 0.45, 0.1);
    glVertex2f(-0.23 + 0.45, 0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2 + 0.45, -0.27, 0.0);
    glColor3f(0, 0, 0);
    glutSolidSphere(0.02, 20, 10);
    glPopMatrix();

    /* glPushMatrix();
     glColor4f(0.92, 0.41, 0.12, 0.3); // ������ �ȹ�
     glBegin(GL_POLYGON);
     glVertex2f(0.5, -0.67);
     glVertex2f(0.5, -0.00);
     glVertex2f(0.65, -0.00);
     glVertex2f(0.65, -0.67);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glColor3f(0.0, 0.0, 0.0); //âƲ
     glLineWidth(5.0);
     glBegin(GL_LINES);
     glVertex2f(0.5, -0.67);
     glVertex2f(0.5, -0.00);

     glVertex2f(0.5, -0.00);
     glVertex2f(0.65, -0.00);

     glVertex2f(0.65, -0.00);
     glVertex2f(0.65, -0.67);

     glVertex2f(0.5, -0.67);
     glVertex2f(0.85, -0.67);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glColor3f(0.6, 0.3, 0.1); // ���� �߹�
     glBegin(GL_POLYGON);
     glVertex2f(0.65, -0.67);
     glVertex2f(0.65, -0.00);
     glVertex2f(0.85, -0.00);
     glVertex2f(0.85, -0.67);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glColor4f(0.6, 0.7, 0.1, 0.9); //������ ���� ǥ��
     glLineWidth(4.0);
     glBegin(GL_LINES);
     glVertex2f(0.65, -0.3);
     glVertex2f(0.85, -0.3);

     glVertex2f(0.75, -0.00);
     glVertex2f(0.75, -0.67);

     glEnd();
     glPopMatrix();

     glPushMatrix();
     glColor3f(0.0, 0.0, 0.0); //âƲ
     glLineWidth(5.0);
     glBegin(GL_LINES);
     glVertex2f(0.65, -0.67);
     glVertex2f(0.65, -0.00);

     glVertex2f(0.65, -0.00);
     glVertex2f(0.85, -0.00);

     glVertex2f(0.85, -0.00);
     glVertex2f(0.85, -0.67);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glColor3f(0.0, 0.0, 0.0); //âƲ
     glLineWidth(5.0);
     glBegin(GL_LINES);
     glVertex2f(0.45, -0.67);
     glVertex2f(0.45, 0.67);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glColor3f(0.0, 0.0, 0.0); //âƲ
     glLineWidth(5.0);
     glBegin(GL_LINES);
     glVertex2f(0.7, -0.00);
     glVertex2f(0.7, 0.67);
     glEnd();
     glPopMatrix();
     */
}//1

void End() {

    glTranslatef(-0.6, 0.5, 0.0);
    glBegin(GL_LINE_LOOP);//T
    glColor3f(1, 1, 1);
    glVertex2f(0.0, -0.4);
    glVertex2f(0.1, -0.4);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.3, 0.1);
    glVertex2f(-0.2, 0.1);
    glVertex2f(-0.2, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();

    glPushMatrix();
    glTranslatef(0.4, -0.1, 0.0);
    glBegin(GL_LINE_LOOP);//H
    glColor3f(1, 1, 1);
    glVertex2f(0.0, -0.3);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.4, -0.1);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.5, -0.3);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.4, 0.0);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.0, 0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0, -0.0, 0.0);
    glBegin(GL_LINE_LOOP);//E1
    glColor3f(1, 1, 1);
    glVertex2f(0.0, -0.4);
    glVertex2f(0.5, -0.4);
    glVertex2f(0.5, -0.3);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.1, -0.2);
    glVertex2f(0.5, -0.2);
    glVertex2f(0.5, -0.1);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, 0.1);
    glVertex2f(0.0, 0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.6, 0.0);
    glBegin(GL_LINE_LOOP);//E2
    glColor3f(1, 1, 1);
    glVertex2f(0.0, -0.4);
    glVertex2f(0.5, -0.4);
    glVertex2f(0.5, -0.3);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.1, -0.2);
    glVertex2f(0.5, -0.2);
    glVertex2f(0.5, -0.1);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, 0.1);
    glVertex2f(0.0, 0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8, -1.0, 0.0);
    glBegin(GL_LINE_LOOP);//N
    glColor3f(1, 1, 1);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.1, 0.4);
    glVertex2f(0.4, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.4, 0.5);
    glVertex2f(0.4, 0.1);
    glVertex2f(0.1, 0.5);
    glVertex2f(0.0, 0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.4, -0.75, 0.0);
    glScalef(1.1, 0.9, 1.0);
    glBegin(GL_LINE_LOOP);//D ��
    glColor3f(1, 1, 1);
    glVertex2f(0.0, -0.3);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.4, 0.0);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.0, 0.3);
    glEnd();

    glBegin(GL_LINE_LOOP);//D ��
    glColor3f(1, 1, 1);
    glVertex2f(0.1, -0.2);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.1, 0.2);
    glEnd();
    glPopMatrix();
}

void Home() {

    glColor3f(0.65, 0.16, 0.16);//�� �ٴ�Ʋ
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, 0.0);
    glVertex2f(-0.25, 0.05);
    glVertex2f(0.25, 0.05);
    glVertex2f(0.25, 0.0);
    glEnd();
    glPushMatrix(); //�� �ٴ�Ʋ �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glVertex2f(-0.25, 0.0);
    glVertex2f(-0.25, 0.05);

    glVertex2f(0.25, 0.05);
    glVertex2f(0.25, 0.0);

    glVertex2f(0.25, 0.0);
    glVertex2f(-0.25, 0.0);

    glVertex2f(-0.25, 0.05);
    glVertex2f(0.25, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //�� ��ü �Ʒ�
    glColor3f(1.0, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.05);
    glVertex2f(-0.22, 0.35);
    glVertex2f(0.22, 0.35);
    glVertex2f(0.22, 0.05);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //�� ��ü �Ʒ� �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glVertex2f(-0.22, 0.35);
    glVertex2f(-0.22, 0.05);

    glVertex2f(0.22, 0.05);
    glVertex2f(0.22, 0.35);

    glVertex2f(-0.22, 0.05);
    glVertex2f(0.22, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�� ��ü ��
    glColor3f(1.0, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.35);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.22, 0.35);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //�� ��ü �� �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glVertex2f(-0.22, 0.35);
    glVertex2f(0.0, 0.5);

    glVertex2f(0.0, 0.5);
    glVertex2f(0.22, 0.35);
    glEnd();
    glPopMatrix();

    glPushMatrix();//�� ���� ��
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.35);
    glVertex2f(-0.27, 0.35);
    glVertex2f(0.0, 0.55);
    glVertex2f(0.0, 0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();//�� ���� ����
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.0, 0.55);
    glVertex2f(0.27, 0.35);
    glVertex2f(0.22, 0.35);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�� ���� �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);

    glVertex2f(0.0, 0.5);
    glVertex2f(0.22, 0.35);

    glVertex2f(0.22, 0.35);
    glVertex2f(0.27, 0.35);

    glVertex2f(0.27, 0.35);
    glVertex2f(0.0, 0.55);

    glVertex2f(0.0, 0.55);
    glVertex2f(-0.27, 0.35);

    glVertex2f(-0.27, 0.35);
    glVertex2f(-0.22, 0.35);

    glVertex2f(-0.22, 0.35);
    glVertex2f(0.0, 0.5);

    glEnd();
    glPopMatrix();

    glPushMatrix(); //�� ��
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.17, 0.05);
    glVertex2f(-0.17, 0.2);
    glVertex2f(-0.07, 0.2);
    glVertex2f(-0.07, 0.05);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //�� ������
    glTranslatef(-0.09, 0.125, 0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //�� �� �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glVertex2f(-0.17, 0.05);
    glVertex2f(-0.17, 0.2);

    glVertex2f(-0.07, 0.2);
    glVertex2f(-0.07, 0.05);

    glVertex2f(-0.07, 0.2);
    glVertex2f(-0.17, 0.2);

    glVertex2f(-0.17, 0.05);
    glVertex2f(-0.07, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�� â��
    glColor3f(0.68, 0.85, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(-0.04, 0.1);
    glVertex2f(-0.04, 0.2);
    glVertex2f(0.18, 0.2);
    glVertex2f(0.18, 0.1);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //�� â�� �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glVertex2f(-0.04, 0.1);
    glVertex2f(-0.04, 0.2);

    glVertex2f(0.18, 0.2);
    glVertex2f(0.18, 0.1);

    glVertex2f(0.18, 0.2);
    glVertex2f(-0.04, 0.2);

    glVertex2f(0.18, 0.1);
    glVertex2f(-0.04, 0.1);

    glVertex2f(0.18, 0.15); //â ���μ�
    glVertex2f(-0.04, 0.15);

    glVertex2f(0.065, 0.1); //â ���μ�
    glVertex2f(0.065, 0.2);

    glEnd();
    glPopMatrix();

    glPushMatrix();//�� �� ���׶�� â��
    glTranslatef(0.0, 0.325, 0);
    glLineWidth(5.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireSphere(0.07, 20, 20);
    glColor3f(0.68, 0.85, 0.9);
    glutSolidSphere(0.07, 20, 20);

    glEnd();
    glPopMatrix();

}

void Cloud() {

    glLineWidth(6.0); //����
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);

    glVertex2f(0.0, 0.62);
    glVertex2f(0.2, 0.62);

    glVertex2f(-0.1, 0.6);
    glVertex2f(0.15, 0.6);

    glVertex2f(0.0, 0.58);
    glVertex2f(0.3, 0.58);

    glVertex2f(-0.05, 0.56);
    glVertex2f(0.25, 0.56);

    glVertex2f(0.0, 0.54);
    glVertex2f(0.2, 0.54);

    glVertex2f(-0.08, 0.52);
    glVertex2f(0.15, 0.52);
    glEnd();

}

void Picture1() {

    glColor3f(0.9, 0.4, 0.2); //���� Ʋ
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.7); // ���� �� ���
    glBegin(GL_POLYGON);
    glVertex2f(-0.075, -0.075);
    glVertex2f(-0.075, 0.075);
    glVertex2f(0.075, 0.075);
    glVertex2f(0.075, -0.075);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0); //���� ���
    glutWireSphere(0.05, 10, 30);
    glEnd();
    glPopMatrix();

}

void Picture2() {

    glColor3f(0.9, 0.4, 0.2); //���� Ʋ
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5); // ���� �� ���
    glBegin(GL_POLYGON);
    glVertex2f(-0.075, -0.075);
    glVertex2f(-0.075, 0.075);
    glVertex2f(0.075, 0.075);
    glVertex2f(0.075, -0.075);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.52, 0.12, 0.0);
    glScalef(0.8, 0.8, 1.0);
    Face();
    glEnd();
    glPopMatrix();

}

void Picture3() {

    glColor3f(0.9, 0.4, 0.2); //���� Ʋ
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5); // ���� �� ���
    glBegin(GL_POLYGON);
    glVertex2f(-0.075, -0.075);
    glVertex2f(-0.075, 0.075);
    glVertex2f(0.075, 0.075);
    glVertex2f(0.075, -0.075);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.02, -0.09, 0.0);
    glScalef(0.8, 0.8, 1.0);
    Dong();
    glEnd();

    glPopMatrix();

}

void Picture4() {

    glColor3f(0.9, 0.4, 0.2); //���� Ʋ
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5); // ���� �� ���
    glBegin(GL_POLYGON);
    glVertex2f(-0.075, -0.075);
    glVertex2f(-0.075, 0.075);
    glVertex2f(0.075, 0.075);
    glVertex2f(0.075, -0.075);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.02, -0.09, 0.0);
    glScalef(0.8, 0.8, 1.0);
    Dong();
    glEnd();

    glPopMatrix();

}

void Death() {

    glColor3f(0.1, 0.1, 0.1); // ��
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, -0.5);
    glVertex2f(-0.15, -0.0);
    glVertex2f(0.15, -0.0);
    glVertex2f(0.15, -0.5);
    glEnd();

    glPushMatrix();
    glColor3f(1.0, 0.84, 0); //���ڰ� ��
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.25);
    glVertex2f(-0.1, -0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(0.1, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 0.84, 0); //���ڰ� �Ʒ�
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, -0.4);
    glVertex2f(-0.05, -0.08);
    glVertex2f(0.05, -0.08);
    glVertex2f(0.05, -0.4);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3); //�Ѽ�
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-0.15, -0.5);
    glVertex2f(-0.15, 0.0);

    glVertex2f(0.15, 0.0);
    glVertex2f(0.15, -0.5);

    glVertex2f(0.15, 0.0);
    glVertex2f(-0.15, 0.0);

    glVertex2f(0.15, -0.5);
    glVertex2f(-0.15, -0.5);
    glEnd();
    glPopMatrix();

}

void Death2() {

    glColor3f(0.1, 0.1, 0.1); // ��
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, -0.5);
    glVertex2f(-0.15, -0.0);
    glVertex2f(0.15, -0.0);
    glVertex2f(0.15, -0.5);
    glEnd();

    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3); //�Ѽ�
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-0.15, -0.5);
    glVertex2f(-0.15, 0.0);

    glVertex2f(0.15, 0.0);
    glVertex2f(0.15, -0.5);

    glVertex2f(0.15, 0.0);
    glVertex2f(-0.15, 0.0);

    glVertex2f(0.15, -0.5);
    glVertex2f(-0.15, -0.5);
    glEnd();
    glPopMatrix();

}

void Tv() {

    glColor3f(0.45, 0.25, 0); //���� ���
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.2, 0.1);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.0, 0.15, 0); //���� ��1
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, -0.025);
    glVertex2f(-0.15, -0.075);
    glVertex2f(0.15, -0.075);
    glVertex2f(0.15, -0.025);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.15, 0); //���� ��2
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, 0.025);
    glVertex2f(-0.15, 0.075);
    glVertex2f(0.15, 0.075);
    glVertex2f(0.15, 0.025);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);//Ƽ�� Ʋ
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, 0.1);
    glVertex2f(-0.25, 0.4);
    glVertex2f(0.25, 0.4);
    glVertex2f(0.25, 0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);//Ƽ�� ȭ��
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.15);
    glVertex2f(-0.2, 0.35);
    glVertex2f(0.2, 0.35);
    glVertex2f(0.2, 0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //������
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�2
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.2, 0.1);

    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, -0.1);

    glVertex2f(-0.2, 0.1);
    glVertex2f(0.2, 0.1);

    glVertex2f(-0.2, -0.1);
    glVertex2f(0.2, -0.1);

    glEnd();
    glPopMatrix();

}

void h_Box() {

    glColor4f(0.4, 0.2, 0.0, 0.75); //�ڽ� �ո�
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.5);
    glVertex2f(-0.1, -0.3);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.1, -0.5);
    glEnd();

    glPushMatrix(); //�ڽ� ��
    glBegin(GL_POLYGON);
    glColor4f(0.4, 0.2, 0.0, 0.75);
    glVertex2f(0.1, -0.5);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.35, -0.3);
    glVertex2f(0.35, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�ڽ� �۾�1
    glBegin(GL_LINES);
    glColor4f(1.0, 0.0, 0.0, 0.3);
    glLineWidth(5.0);
    glVertex2f(0.239, -0.4);
    glVertex2f(0.279, -0.4);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�ڽ� �۾�2
    glBegin(GL_LINES);
    glColor4f(1.0, 0.0, 0.0, 0.3);
    glLineWidth(5.0);
    glVertex2f(0.229, -0.39);
    glVertex2f(0.289, -0.39);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�ڽ� �۾�3
    glBegin(GL_LINES);
    glColor4f(1.0, 0.0, 0.0, 0.3);
    glLineWidth(5.0);
    glVertex2f(0.219, -0.38);
    glVertex2f(0.299, -0.38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�ڽ� �۾�4
    glBegin(GL_LINES);
    glColor4f(1.0, 0.0, 0.0, 0.3);
    glLineWidth(5.0);
    glVertex2f(0.209, -0.37);
    glVertex2f(0.309, -0.37);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�ڽ� ��� ��
    glRotatef(60, 0, 0, 1);
    glTranslatef(-0.46, -0.03, 0);
    glBegin(GL_LINES);
    glColor4f(0.0, 1.0, 0.0, 0.3);
    glLineWidth(7.0);
    glVertex2f(0.25, -0.36);
    glVertex2f(0.3, -0.36);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�ڽ� ������
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(0.1, -0.5);
    glVertex2f(0.1, -0.3);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�ڽ� ����
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.0);
    glVertex2f(-0.03, -0.5);
    glVertex2f(-0.03, -0.3);
    glVertex2f(0.03, -0.3);
    glVertex2f(0.03, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�ڽ� �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(-0.1, -0.3);
    glVertex2f(0.35, -0.3);

    glVertex2f(-0.1, -0.5);
    glVertex2f(0.35, -0.5);

    glVertex2f(-0.1, -0.5);
    glVertex2f(-0.1, -0.3);

    glVertex2f(0.35, -0.5);
    glVertex2f(0.35, -0.3);
    glEnd();
    glPopMatrix();

}

void Carge() {

    glColor3f(1.0, 1.0, 1.0); //�ܼ�Ʈ ��
    glScalef(0.5, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, -0.1);
    glVertex2f(-0.05, 0.1);
    glVertex2f(0.05, 0.1);
    glVertex2f(0.05, -0.1);
    glEnd();

    glPushMatrix(); //�ܼ�Ʈ �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(-0.05, -0.1);
    glVertex2f(-0.05, 0.1);

    glVertex2f(0.05, 0.1);
    glVertex2f(0.05, -0.1);

    glVertex2f(0.05, 0.1);
    glVertex2f(-0.05, 0.1);

    glVertex2f(-0.05, -0.1);
    glVertex2f(0.05, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�ܼ�Ʈ Ʋ
    glScalef(0.8, 0.8, 1.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.05, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�ܼ�Ʈ ����1
    glTranslatef(0.02, 0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�ܼ�Ʈ ����2
    glTranslatef(-0.02, 0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

}

void Mountain() {

    glColor3f(0.65, 0.27, 0.07); //�� ��ü
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.1, 0.2);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.2, -0.1);
    glEnd();
    glPushMatrix(); //�� �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.1, 0.2);

    glVertex2f(0.1, 0.2);
    glVertex2f(0.2, -0.1);

    glVertex2f(-0.1, 0.2);
    glVertex2f(0.1, 0.2);

    glVertex2f(0.2, -0.1);
    glVertex2f(-0.2, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();//�� ���츮
    glTranslatef(0.0, 0.2, 0.0);
    glScalef(1.7, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireSphere(0.07, 20, 20); //�� ��
    glColor3f(0.8, 0.8, 0.8);
    glutSolidSphere(0.07, 20, 20);
    glEnd();
    glPopMatrix();

}

void Hotel() {
    //ȸ�� ��ü
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.3);
    glVertex2f(-0.2, 0.3);
    glVertex2f(0.2, 0.3);
    glVertex2f(0.2, -0.3);
    glEnd();
    glPushMatrix();//ȸ�� ��ü �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(-0.2, -0.3);
    glVertex2f(-0.2, 0.3);

    glVertex2f(0.2, 0.3);
    glVertex2f(0.2, -0.3);

    glVertex2f(-0.2, 0.3);
    glVertex2f(0.2, 0.3);

    glVertex2f(0.2, -0.3);
    glVertex2f(0.2, -0.3);
    glEnd();
    glPopMatrix();


    glPushMatrix();//ȸ�� ��
    glColor3f(1.0, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, -0.3);
    glVertex2f(-0.05, -0.15);
    glVertex2f(0.05, -0.15);
    glVertex2f(0.05, -0.3);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);//�� ������
    glBegin(GL_LINES);
    glLineWidth(0.5);
    glVertex2f(-0.00, -0.3);
    glVertex2f(-0.00, -0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();//ȸ�� �� �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(-0.05, -0.3);
    glVertex2f(-0.05, -0.2);

    glVertex2f(0.05, -0.2);
    glVertex2f(0.05, -0.3);

    glVertex2f(-0.05, -0.3);
    glVertex2f(0.05, -0.3);

    glVertex2f(-0.05, -0.2);
    glVertex2f(0.05, -0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02, -0.25, 0);
    glColor3f(0.0, 0.0, 0.0);//������1
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.02, -0.25, 0);
    glColor3f(0.0, 0.0, 0.0);//������2
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //ȸ�� ����
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.07, -0.15);
    glVertex2f(-0.07, -0.2);
    glVertex2f(0.07, -0.2);
    glVertex2f(0.07, -0.15);
    glEnd();
    glPopMatrix();
    glPushMatrix();//ȸ�� ���� �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(-0.07, -0.15);
    glVertex2f(-0.07, -0.2);

    glVertex2f(0.07, -0.2);
    glVertex2f(0.07, -0.15);

    glVertex2f(-0.07, -0.15);
    glVertex2f(0.07, -0.15);

    glVertex2f(-0.07, -0.2);
    glVertex2f(0.07, -0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();//ȸ�� ����
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.3);
    glVertex2f(-0.22, 0.35);
    glVertex2f(0.22, 0.35);
    glVertex2f(0.22, 0.3);
    glEnd();
    glPopMatrix();
    glPushMatrix();//ȸ�� ���� �Ѽ�
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(-0.22, 0.3);
    glVertex2f(-0.22, 0.35);

    glVertex2f(0.22, 0.35);
    glVertex2f(0.22, 0.3);

    glVertex2f(-0.22, 0.3);
    glVertex2f(0.22, 0.3);

    glVertex2f(-0.22, 0.35);
    glVertex2f(0.22, 0.35);
    glEnd();
    glPopMatrix();

    glPushMatrix();//ȸ�� ����1
    glColor3f(0.0, 0.75, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0.25);
    glVertex2f(0.2, 0.25);
    glVertex2f(0.2, 0.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0.25);

    glVertex2f(0.2, 0.25);
    glVertex2f(0.2, 0.2);

    glVertex2f(-0.2, 0.25);
    glVertex2f(0.2, 0.25);

    glVertex2f(-0.2, 0.2);
    glVertex2f(0.2, 0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();//ȸ�� ����1.1
    glTranslatef(0, -0.1, 0);
    glColor3f(0.0, 0.75, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0.25);
    glVertex2f(0.2, 0.25);
    glVertex2f(0.2, 0.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0.25);

    glVertex2f(0.2, 0.25);
    glVertex2f(0.2, 0.2);

    glVertex2f(-0.2, 0.25);
    glVertex2f(0.2, 0.25);

    glVertex2f(-0.2, 0.2);
    glVertex2f(0.2, 0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();//ȸ�� ����1.2
    glTranslatef(0, -0.2, 0);
    glColor3f(0.0, 0.75, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0.25);
    glVertex2f(0.2, 0.25);
    glVertex2f(0.2, 0.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0.25);

    glVertex2f(0.2, 0.25);
    glVertex2f(0.2, 0.2);

    glVertex2f(-0.2, 0.25);
    glVertex2f(0.2, 0.25);

    glVertex2f(-0.2, 0.2);
    glVertex2f(0.2, 0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();//ȸ�� ����1.3
    glTranslatef(0, -0.3, 0);
    glColor3f(0.0, 0.75, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0.25);
    glVertex2f(0.2, 0.25);
    glVertex2f(0.2, 0.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0.25);

    glVertex2f(0.2, 0.25);
    glVertex2f(0.2, 0.2);

    glVertex2f(-0.2, 0.25);
    glVertex2f(0.2, 0.25);

    glVertex2f(-0.2, 0.2);
    glVertex2f(0.2, 0.2);
    glEnd();
    glPopMatrix();

}

void Bird() {

    glTranslatef(-0.14, 0.0 + h_Move * 0.001, 0);
    glScalef(1.5, 0.6, 1.0);
    glColor3f(0.0, 0.7, 0.9); //����
    glutSolidSphere(0.1, 20, 20);
    glEnd();

    glPushMatrix(); //�Ӹ�
    glScalef(0.8, 1.5, 1.0);
    glTranslatef(-0.14, 0.0 + h_Move * 0.001, 0);
    glColor3f(0.0, 0.0, 0.88);
    glutSolidSphere(0.04, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //��(��)
    glTranslatef(-0.13, 0.01 + h_Move * 0.001 * 0.001, 0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //��(��)
    glTranslatef(-0.135, 0.01 + h_Move * 0.001, 0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.005, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //�θ�
    glScalef(0.2, 0.2, 1.0);
    glRotatef(5, 0, 0, 1);
    glTranslatef(-0.7, -0.05 + h_Move * 0.001, 0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(-0.2, 0.0);
    glVertex2f(0.0, -0.1);
    glVertex2f(0.0, 0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //����
    glScalef(0.4, 0.1, 1.0);
    glTranslatef(0.3, 0.2 + h_Move * 0.001, 0);
    glRotatef(65, 0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.9);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 0.1);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //����
    glTranslatef(0.01, 0.045, 0);
    glRotatef(10 + h_Move * 2, 0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.9);
    glVertex2f(-0.05, 0.0);
    glVertex2f(0.05, 0.0);
    glVertex2f(0.0, 0.17);
    glEnd();
    glPopMatrix();

}

void Bone() {
    glPushMatrix();
    glTranslatef(-0.8, 0.85, 0);
    glScalef(0.4, 0.4, 0);
    //�Ӹ�
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.2, 20, 20);
    glEnd();

    //��1(����)
    glPushMatrix();
    glTranslatef(0.12, -0.14, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.07, 20, 20);
    glEnd();
    glPopMatrix();

    //��(��)
    glPushMatrix();
    glTranslatef(-0.12, -0.14, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.07, 20, 20);
    glEnd();
    glPopMatrix();

    //��(���)
    glPushMatrix();
    glScalef(0.7, 0.6, 1.0);
    glTranslatef(0.11, 0.15, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(0.1, -0.1);
    glVertex2f(-0.0, 0.0);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.3, 0.1);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.27, 0.21, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.06, 20, 20);
    glEnd();
    glPopMatrix();

    //��(����)
    glPushMatrix();
    glScalef(0.7, 0.6, 1.0);
    glTranslatef(0.31, -0.26, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(-0.0, -0.0);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.1, 0.3);
    glVertex2f(0.1, 0.1);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.27, -0.14, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.06, 20, 20);
    glEnd();
    glPopMatrix();

    //��(�»�)
    glPushMatrix();
    glScalef(0.7, 0.6, 1.0);
    glTranslatef(-0.18, 0.05, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(-0.0, -0.0);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.1, 0.3);
    glVertex2f(0.1, 0.1);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.255, 0.21, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.06, 20, 20);
    glEnd();
    glPopMatrix();

    //��(����)
    glPushMatrix();
    glScalef(0.7, 0.6, 1.0);
    glTranslatef(-0.41, -0.16, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(0.1, -0.1);
    glVertex2f(-0.0, 0.0);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.3, 0.1);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.27, -0.14, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.06, 20, 20);
    glEnd();
    glPopMatrix();

    //��(��)
    glPushMatrix();
    glTranslatef(-0.07, -0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.05, 20, 20);
    glEnd();
    glPopMatrix();

    //��(����)
    glPushMatrix();
    glTranslatef(0.07, -0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.05, 20, 20);
    glEnd();
    glPopMatrix();

    //��
    glPushMatrix();
    glScalef(0.8, 1.5, 1.0);
    glTranslatef(-0.00, -0.06, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.02, 20, 20);
    glEnd();
    glPopMatrix();

    //�̻�
    glPushMatrix();
    glScalef(0.8, 0.45, 1.0);
    glTranslatef(0.00, -0.43, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.0);
    glVertex2f(-0.2, 0.2);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.2, -0.0);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //�̻� ǥ��
    glBegin(GL_LINES);
    glVertex2f(-0.1, 0.0);
    glVertex2f(-0.1, 0.1);

    glVertex2f(0.0, 0.1);
    glVertex2f(0.0, 0.0);

    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();

}

void Tree() {

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 1.3);

    glVertex2f(0.0, 0.2);
    glVertex2f(0.2, 0.3);

    glVertex2f(0.2, 0.3);
    glVertex2f(0.2, 0.4);

    glVertex2f(0.2, 0.3);
    glVertex2f(0.3, 0.2);

    glVertex2f(0.0, 0.3);
    glVertex2f(-0.4, 0.5);

    glVertex2f(-0.2, 0.4);
    glVertex2f(-0.2, 0.5);

    glVertex2f(-0.2, 0.4);
    glVertex2f(-0.3, 0.3);

    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.5, 0.4);

    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.5, 0.6);

    glVertex2f(0.0, 0.4);
    glVertex2f(0.4, 0.7);

    glVertex2f(0.4, 0.7);
    glVertex2f(0.5, 0.6);

    glVertex2f(0.4, 0.7);
    glVertex2f(0.5, 0.8);

    glVertex2f(0.0, 0.5);
    glVertex2f(-0.3, 0.8);

    glVertex2f(-0.2, 0.7);
    glVertex2f(-0.2, 0.8);

    glVertex2f(-0.2, 0.7);
    glVertex2f(-0.3, 0.6);

    glVertex2f(0.0, 0.6);
    glVertex2f(0.3, 0.9);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.3, 1.0);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.2, 0.8);
    glVertex2f(0.3, 0.7);

    glVertex2f(0.1, 0.7);
    glVertex2f(0.1, 0.8);

    glVertex2f(0.0, 0.9);
    glVertex2f(-0.3, 1.0);

    glVertex2f(-0.3, 1.0);
    glVertex2f(-0.4, 0.9);

    glVertex2f(-0.3, 1.0);
    glVertex2f(-0.3, 1.1);

    glVertex2f(-0.3, 1.0);
    glVertex2f(-0.5, 1.1);

    glVertex2f(0.0, 1.0);
    glVertex2f(0.4, 1.2);

    glVertex2f(0.2, 1.1);
    glVertex2f(0.2, 1.0);

    glVertex2f(0.4, 1.2);
    glVertex2f(0.4, 1.3);

    glVertex2f(0.0, 1.1);
    glVertex2f(-0.2, 1.3);

    glVertex2f(0.0, 1.2);
    glVertex2f(0.1, 1.3);

    glVertex2f(0.1, 1.4);
    glVertex2f(0.1, 1.3);

    glVertex2f(0.2, 1.2);
    glVertex2f(0.1, 1.3);

    glEnd();

    glPushMatrix(); //����
    glScalef(1.0, 0.5, 1.0);
    glTranslatef(-0.5, 2.22, 0);
    glColor3f(0.00, 1.00, 0.00);
    glutSolidSphere(0.07, 20, 20);
    glEnd();
    glPopMatrix();

    /*glPushMatrix(); //���� ǥ��
    glScalef(0.5, 1.0, 1.0);
    glTranslatef(-1.0, 1.11, 0);
    glLineWidth(2.2);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(-0.1,0.0);
    glVertex2f(0.1, 0.0);
    glEnd();
    glPopMatrix();
    */

}

void PolarView(GLfloat radius, GLfloat elevation, GLfloat azimuth, GLfloat twist) {

    glTranslatef(0.0, 0.0, -radius);
    glRotatef(-twist, 0.0, 0.0, 1.0);
    glRotatef(-elevation, 1.0, 0.0, 0.0);
    glRotatef(-azimuth, 0.0, 1.0, 0.0);

}

void h_door() {

    //��1
    glPushMatrix();
    //glTranslatef(1.5 - h_Delta * 0.004, 0, 0.0);  //���
    glTranslatef(3.0, 0.0, 0);
    glRotatef(180, 0, 1, 0);
    glTranslatef(-1, 0.0, 0);
    h_Wall();
    glPopMatrix();
    //��2
    glPushMatrix();
    glTranslatef(0.6, 0.0, 0);
    h_Wall();
    glPopMatrix();
    //��
}

void h_elevatorOpen() {
    if (Delta < 3930) {
        elevator1();
    }
}

void h_backGround1() {

    glPushMatrix();
    glTranslatef(4.5 - h_Delta * 0.006, 0, 0.0);  //���
    glColor3f(0.0 - h_Delta * 0.0007, 0.8 - h_Delta * 0.0007, 0.8 - h_Delta * 0.0007);
    glBegin(GL_POLYGON);
    glVertex2f(-2.50, -0.5);
    glVertex2f(-2.50, 0.67);
    glVertex2f(5.0, 0.67);
    glVertex2f(5.0, -0.5);
    glEnd();

    glPushMatrix();
    glColor3f(0.7, 1, 0.6);  // ȸ�� (���� )
    glBegin(GL_POLYGON);
    glVertex2f(-6.50, -0.5);
    glVertex2f(-6.50, 0.5);
    glVertex2f(-3.0, 0.5);
    glVertex2f(-3.0, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);  // ȸ�� (�Ʒ� ��� )
    glBegin(GL_POLYGON);
    glVertex2f(-6.50, -0.67);
    glVertex2f(-6.50, -0.5);
    glVertex2f(-3.0, -0.5);
    glVertex2f(-3.0, -0.67);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6, 0.75, 0.95);  // ȸ�� (�� ��� )
    glBegin(GL_POLYGON);
    glVertex2f(-6.50, 0.5);
    glVertex2f(-6.50, 0.67);
    glVertex2f(-3.0, 0.67);
    glVertex2f(-3.0, 0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); // �� �Ѽ�
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-9.5, 0.5);
    glVertex2f(-2.5, 0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); // �Ʒ� �Ѽ�
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-10.5, -0.5);
    glVertex2f(20.0, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);  // �ٴ�
    glBegin(GL_POLYGON);
    glVertex2f(-3.0, -0.67);
    glVertex2f(-3.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, -0.67);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, -0.5);
    glVertex2f(20.0, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.3, 0.1); // ���(����)
    glBegin(GL_QUADS);
    glVertex2f(1.2, -0.5); // ���� �ϴ�
    glVertex2f(3.5, -0.5);  // ���� �ϴ�
    glVertex2f(3.5, 0.67);   // ���� �ϴ� (�ظ�)
    glVertex2f(1.2, 0.67);  // ���� �ϴ� (�ظ�)
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9); // �ٴ�(����)
    glBegin(GL_QUADS);
    glVertex2f(1.2, -0.5); // ���� �ϴ�
    glVertex2f(3.5, -0.5);  // ���� �ϴ�
    glVertex2f(3.5, -0.67);   // ���� �ϴ� (�ظ�)
    glVertex2f(1.2, -0.67);  // ���� �ϴ� (�ظ�)
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, -0.5);
    glVertex2f(20.0, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.25, 0.175, 0.1); // ����(����)
    glBegin(GL_QUADS);
    glVertex2f(3.5, -0.5); // ���� �ϴ�
    glVertex2f(20.0, -0.5);  // ���� �ϴ�
    glVertex2f(20.0, -0.67);   // ���� �ϴ� (�ظ�)
    glVertex2f(3.5, -0.67);  // ���� �ϴ� (�ظ�)
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1, 0.1, 0.3); // ���(����)
    glBegin(GL_POLYGON);
    glVertex2f(3.5, -0.5); // ���� �ϴ�
    glVertex2f(3.5, 0.67);  // ���� �ϴ�
    glVertex2f(20.0, 0.67);   // ���� �ϴ� (�ظ�)
    glVertex2f(20.0, -0.5);  // ���� �ϴ� (�ظ�)
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //�Ѽ�
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, -0.5);
    glVertex2f(20.0, -0.5);
    glEnd();
    glPopMatrix();

    //��ü��

    // ������ (��ö)
    glPushMatrix();
    glTranslatef(-4.9, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    h_elevatorIn();
    h_elevatorOpen();
    glPopMatrix();

    // �Ѿ�� ��1
    glPushMatrix();
    glTranslatef(-3.5, 0.0, 1);
    glScalef(1.0, 1.0, 0);
    glRotatef(180, 0, 1, 0);
    Entrance();
    glPopMatrix();


    //Ƽ��
    glPushMatrix();
    glTranslatef(-4.2, -0.4, 0);
    Tv();
    glPopMatrix();

    //Ŀ�Ǹӽ�
    glPushMatrix();
    glTranslatef(-3.6, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    coffee();
    glPopMatrix();

    //����
    glPushMatrix();
    glTranslatef(0.5, 0.65, 0);
    glScalef(2.3, 2.3, 0);
    Hospital();
    glPopMatrix();

    //�ڽ�
    glPushMatrix();
    glTranslatef(2.5, 0.0, 0);
    h_Box();
    glPopMatrix();
    //�ܼ�Ʈ
    glPushMatrix();
    glTranslatef(3.2, -0.3, 0);
    Carge();
    glPopMatrix();

    //���� 1
    glPushMatrix();
    glTranslatef(0.2, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //���� 2
    glPushMatrix();
    glTranslatef(-0.35, -0.05, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //���� 3
    glPushMatrix();
    glTranslatef(4.2, -0.05, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //���� 4
    glPushMatrix();
    glTranslatef(4.75, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //���� 5
    glPushMatrix();
    glTranslatef(5.25, -0.05, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //���� 6
    glPushMatrix();
    glTranslatef(6.15, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //����
    glPushMatrix();
    glTranslatef(5.8, -0.5, 0);
    glScalef(0.5, 0.5, 1);
    Tree();
    glPopMatrix();
    //ȸ��
    glPushMatrix();
    glTranslatef(-2.0, -0.08, 0);
    glScalef(1.4, 1.4, 0);
    Hotel();
    glPopMatrix();
    //��
    glPushMatrix();
    glTranslatef(0.3, -0.5, 0);
    glScalef(1.5, 1.5, 0);
    Home();
    glPopMatrix();
    //Ƽ��
    glPushMatrix();
    glTranslatef(2.0, -0.4, 0);
    Tv();
    glPopMatrix();
    //����1
    glPushMatrix();
    glTranslatef(1.8, 0.4, 0);
    Picture1();
    glPopMatrix();
    //����2
    glPushMatrix();
    glTranslatef(3, 0.4, 0);
    glScalef(1.5, 1.5, 0);
    Picture2();
    glPopMatrix();
    //����3
    glPushMatrix();
    glTranslatef(2.6, -0.0, 0);
    glScalef(1.0, 1.0, 0);
    Picture3();
    glPopMatrix();
    //��
    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(-1.0 - h_Delta * 0.002, 0.75 + h_Delta * 0.0001, 0);
    Bird();
    glPopMatrix();
    //��2
    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(1.0 - h_Delta * 0.002, 0.5 + h_Delta * 0.0001, 0);
    Bird();
    glPopMatrix();
    //������ ��
    glPushMatrix();
    glTranslatef(5.0, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    Sun();
    glPopMatrix();
    // �� ��
    glPushMatrix();
    glTranslatef(5.0, 0, 0.0);
    Death2();
    glPopMatrix();
    //�� �Ѳ�
    glPushMatrix();
    glTranslatef(4.7 + h_a, 0, 0);
    Death();
    glPopMatrix();


    //���
    if (h_Delta > 3 && h_Delta < 1610) {
        glPushMatrix();
        glTranslatef(-4.3 + h_Delta * 0.0062, 0.003 * h_Move, 0);
        h_charater();
        glPushMatrix(); //�����ٸ� ����
        glRotatef(0.1 * h_Move, 0, 0, 1);
        h_leftleg();
        glPopMatrix();

        glPushMatrix(); //�޴ٸ� ����
        glRotatef(0.1 * -h_Move, 0, 0, 1);
        h_rightleg();
        glPopMatrix();

        glPushMatrix(); //�� ����
        glRotatef(0, 0, 0, 1);
        h_rightarm();
        glPopMatrix();

        glPushMatrix(); //�� ����
        glRotatef(0.1 * h_Move, 0, 0, 1);
        h_leftarm();
        glPopMatrix();
        glPopMatrix();
    }
    // �Ѿ�� ��2
    glPushMatrix();
    glTranslatef(-3.5, 0.0, -1);
    glScalef(1.0, 1.0, 0);
    glRotatef(180, 0, 1, 0);
    Entrance1();
    glPopMatrix();
    h_door();
    glPopMatrix();
}

void h_backGround2() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ȭ�� �����
    glClearColor(0.1f, 0.1f, 0.3f, 1.0f); // RGB ��
    glPushMatrix();
    glScalef(1.0, 1.4, 1.0);
    Death3();
    drawCubeEdges();

    glPushMatrix();
    glTranslatef(-0.0, 0.45, -0.5);
    glScalef(1.8, 1.7, 1.0);
    Ten();
    glPopMatrix();

    if (h_Delta > 1800) {
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glRotatef(-90, 0, 0, 1);
        glTranslatef(-0.08, 0.01, -0.5);
        glScalef(0.4, 0.5, 1.0);
        End();
        glPopMatrix();
    }
    glPopMatrix();

}


//------ 22124769 �ǵ�ö ---------------------------------------------------------

void window() {
    //â�� ���
    glTranslatef(0, -0.1, 0.0);
    glColor3f(0, 0.5, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.4);
    glVertex2f(0.3, -0.4);
    glVertex2f(-0.3, -0.4);
    glVertex2f(-0.3, 0.4);
    glEnd();
    //â����
    glPushMatrix();
    glTranslatef(0, 0.4, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0);
    glVertex2f(0.31, 0.015);
    glVertex2f(0.31, -0.015);
    glVertex2f(-0.31, -0.015);
    glVertex2f(-0.31, 0.015);
    glEnd();
    glPopMatrix();
    //â�� �߰�
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0);
    glVertex2f(0.3, 0.015);
    glVertex2f(0.3, -0.015);
    glVertex2f(-0.3, -0.015);
    glVertex2f(-0.3, 0.015);
    glEnd();
    glPopMatrix();
    //â�� ����
    glPushMatrix();
    glTranslatef(-0.3, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0);
    glVertex2f(0.01, 0.4);
    glVertex2f(0.01, -0.4);
    glVertex2f(-0.01, -0.4);
    glVertex2f(-0.01, 0.4);
    glEnd();
    glPopMatrix();
    //â�� ������
    glPushMatrix();
    glTranslatef(0.3, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0);
    glVertex2f(0.01, 0.4);
    glVertex2f(0.01, -0.4);
    glVertex2f(-0.01, -0.4);
    glVertex2f(-0.01, 0.4);
    glEnd();
    glPopMatrix();

    //�ǹ� 1��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.6, 0.8, 0.9, 0.45);
    glTranslatef(-0.19, -0.25, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(-0.1, -0.15);
    glVertex2f(-0.1, 0.15);
    glEnd();
    glPopMatrix();

    //�ǹ� 1�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.25, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.2, -0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.15, -0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 4�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.15, -0.325, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 5�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.25, -0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 6�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.2, -0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 7�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.15, -0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.8, 0.9, 0.5);
    glTranslatef(0.05, -0.23, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.17);
    glVertex2f(0.1, -0.17);
    glVertex2f(-0.1, -0.17);
    glVertex2f(-0.1, 0.17);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 1��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.0, -0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 2��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.1, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 3��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.07, -0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 4��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.0, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 5��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.02, -0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 6��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.1, -0.125, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.8, 0.9, 0.7);
    glTranslatef(0.24, -0.25, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.15);
    glVertex2f(0.05, -0.15);
    glVertex2f(-0.05, -0.15);
    glVertex2f(-0.05, 0.15);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 1��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.25, -0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 2��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.22, -0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 3��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.27, -0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 4��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.21, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();


    //�ϴ�
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.82, 0.85, 0.7);
    glTranslatef(0.1, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.7, 0.8, 0.8);
    glTranslatef(0.15, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.75, 0.82, 0.85);
    glTranslatef(0.15, 0.31, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.82, 0.85, 0.5);
    glTranslatef(-0.2, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.8, 0.8, 0.7);
    glTranslatef(-0.17, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.82, 0.85, 0.75);
    glTranslatef(-0.17, 0.26, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.82, 0.85, 0.7);
    glTranslatef(0.2, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.8, 0.8, 0.75);
    glTranslatef(0.19, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.85, 0.9, 0.6);
    glTranslatef(0.17, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 1��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.3);
    glTranslatef(0.2, 0.13, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 2��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.25);
    glTranslatef(0.18, 0.13, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 3��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.2);
    glTranslatef(0.2, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 4��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.3);
    glTranslatef(0.13, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 5��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.25);
    glTranslatef(0.13, 0.32, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 6��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.35);
    glTranslatef(0.15, 0.32, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 7��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.5);
    glTranslatef(-0.2, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 8��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.6);
    glTranslatef(-0.2, 0.23, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 9��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.55);
    glTranslatef(-0.18, 0.23, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();
}

void window2() {
    //â�� ���
    glTranslatef(0, -0.1, 0.0);
    glColor3f(0, 0.5, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.4);
    glVertex2f(0.3, -0.4);
    glVertex2f(-0.3, -0.4);
    glVertex2f(-0.3, 0.4);
    glEnd();
    //â����
    glPushMatrix();
    glTranslatef(0, 0.4, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0.8);
    glVertex2f(0.31, 0.015);
    glVertex2f(0.31, -0.015);
    glVertex2f(-0.31, -0.015);
    glVertex2f(-0.31, 0.015);
    glEnd();
    glPopMatrix();
    //â�� �߰�
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0.8);
    glVertex2f(0.3, 0.015);
    glVertex2f(0.3, -0.015);
    glVertex2f(-0.3, -0.015);
    glVertex2f(-0.3, 0.015);
    glEnd();
    glPopMatrix();
    //â�� ����
    glPushMatrix();
    glTranslatef(-0.3, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0.8);
    glVertex2f(0.01, 0.4);
    glVertex2f(0.01, -0.4);
    glVertex2f(-0.01, -0.4);
    glVertex2f(-0.01, 0.4);
    glEnd();
    glPopMatrix();
    //â�� ������
    glPushMatrix();
    glTranslatef(0.3, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0.8);
    glVertex2f(0.01, 0.4);
    glVertex2f(0.01, -0.4);
    glVertex2f(-0.01, -0.4);
    glVertex2f(-0.01, 0.4);
    glEnd();
    glPopMatrix();

    //�ǹ� 1��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.6, 0.8, 0.9, 0.45);
    glTranslatef(-0.19, -0.25, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(-0.1, -0.15);
    glVertex2f(-0.1, 0.15);
    glEnd();
    glPopMatrix();

    //�ǹ� 1�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.25, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.2, -0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.15, -0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 4�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.15, -0.325, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 5�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.25, -0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 6�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.2, -0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 7�� â��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(-0.15, -0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.8, 0.9, 0.5);
    glTranslatef(0.05, -0.23, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.17);
    glVertex2f(0.1, -0.17);
    glVertex2f(-0.1, -0.17);
    glVertex2f(-0.1, 0.17);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 1��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.0, -0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 2��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.1, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 3��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.07, -0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 4��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.0, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 5��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.02, -0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 2�� â�� 6��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.1, -0.125, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.8, 0.9, 0.7);
    glTranslatef(0.24, -0.25, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.15);
    glVertex2f(0.05, -0.15);
    glVertex2f(-0.05, -0.15);
    glVertex2f(-0.05, 0.15);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 1��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.25, -0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 2��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.22, -0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 3��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.27, -0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�ǹ� 3�� â�� 4��
    glPushMatrix();
    glColor3f(0.6, 0.8, 0.7);
    glTranslatef(0.21, -0.35, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();


    //�ϴ�
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.82, 0.85, 0.7);
    glTranslatef(0.1, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.7, 0.8, 0.8);
    glTranslatef(0.15, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.75, 0.82, 0.85);
    glTranslatef(0.15, 0.31, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.82, 0.85, 0.5);
    glTranslatef(-0.2, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.8, 0.8, 0.7);
    glTranslatef(-0.17, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.82, 0.85, 0.75);
    glTranslatef(-0.17, 0.26, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.75, 0.82, 0.85, 0.7);
    glTranslatef(0.2, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.8, 0.8, 0.75);
    glTranslatef(0.19, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.85, 0.9, 0.6);
    glTranslatef(0.17, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 1��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.3);
    glTranslatef(0.2, 0.13, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 2��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.25);
    glTranslatef(0.18, 0.13, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 3��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.2);
    glTranslatef(0.2, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 4��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.3);
    glTranslatef(0.13, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 5��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.25);
    glTranslatef(0.13, 0.32, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 6��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.35);
    glTranslatef(0.15, 0.32, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 7��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.5);
    glTranslatef(-0.2, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 8��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.6);
    glTranslatef(-0.2, 0.23, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();

    //�����ȿ� ���� 9��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 0.55);
    glTranslatef(-0.18, 0.23, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.01);
    glVertex2f(0.01, -0.01);
    glVertex2f(-0.01, -0.01);
    glVertex2f(-0.01, 0.01);
    glEnd();
    glPopMatrix();
}

void computer() {
    //��ǻ�� �ν�
    glTranslatef(0, 0, 0);
    glColor3f(0.5, 0.6, 0.65);
    glBegin(GL_POLYGON);
    glVertex2f(-0.24, -0.5);
    glVertex2f(-0.24, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.24, -0.5);
    glEnd();

    //��ǻ�� �ν� ������ �� �ٸ��� �ؾߵ� (!)
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.5, 0.55, 0.55);
    glBegin(GL_QUADS);
    glVertex2f(0, -0.5);
    glVertex2f(0, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.24, -0.5);
    glEnd();
    glPopMatrix();


    //��ǻ�� �ν� ���� �׵θ�
    glPushMatrix();
    glTranslatef(-0.24, -0.2, 0);
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.3);
    glVertex2f(0.01, -0.3);
    glVertex2f(-0.01, -0.3);
    glVertex2f(-0.01, 0.3);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� ������ �׵θ�
    glPushMatrix();
    glTranslatef(0.24, -0.2, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.3);
    glVertex2f(0.01, -0.3);
    glVertex2f(-0.01, -0.3);
    glVertex2f(-0.01, 0.3);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� ���� �׵θ�
    glPushMatrix();
    glTranslatef(0, 0.1, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.25, 0.005);
    glVertex2f(0.25, -0.005);
    glVertex2f(-0.25, -0.005);
    glVertex2f(-0.25, 0.005);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� �߰� �׵θ�
    glPushMatrix();
    glTranslatef(0, -0.2, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.005, 0.3);
    glVertex2f(0.005, -0.3);
    glVertex2f(-0.005, -0.3);
    glVertex2f(-0.005, 0.3);
    glEnd();
    glPopMatrix();

    //��ǻ�� �޸� (���)
    glPushMatrix();
    glTranslatef(-0.06, -0.12, 0);
    glColor3f(0.95, 0.95, 0.95);
    glBegin(GL_QUADS);
    glVertex2f(-0.15, 0.12);
    glVertex2f(-0.15, 0.2);
    glVertex2f(-0.07, 0.2);
    glVertex2f(-0.07, 0.12);
    glEnd();
    glPopMatrix();

    //��ǻ�� �޸� (�����)
    glPushMatrix();
    glTranslatef(-0.02, -0.15, 0);
    glColor3f(0.9, 0.9, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.15, 0.12);
    glVertex2f(-0.15, 0.2);
    glVertex2f(-0.1, 0.2);
    glVertex2f(-0.1, 0.12);
    glEnd();
    glPopMatrix();

    //��ǻ�� ���̺� ���� ���� �κ�
    glPushMatrix();
    glTranslatef(0, -0.2, 0);
    glColor3f(0.85, 0.75, 0.6);
    glBegin(GL_QUADS);
    glVertex2f(-0.23, -0.03);
    glVertex2f(-0.23, 0);
    glVertex2f(0.12, 0);
    glVertex2f(0.12, -0.03);
    glEnd();
    glPopMatrix();

    //��ǻ�� ���̺� ������ ��ο� �κ�
    glPushMatrix();
    glTranslatef(0.2, -0.2, 0);
    glColor3f(0.7, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(-0.1, -0.03);
    glVertex2f(-0.1, 0);
    glVertex2f(0.03, 0);
    glVertex2f(0.03, -0.03);
    glEnd();
    glPopMatrix();

    //��ǻ�� ����� �����ϴ� �ϴܺ�
    glPushMatrix();
    glTranslatef(0.15, -0.19, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-0.07, -0.01);
    glVertex2f(-0.07, 0);
    glVertex2f(0, 0);
    glVertex2f(0, -0.01);
    glEnd();
    glPopMatrix();

    //��ǻ�� ����� �����ϴ� �ϴܺ�(�߾�)
    glPushMatrix();
    glTranslatef(0.107, -0.2, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0, 0.03);
    glVertex2f(0.015, 0.03);
    glVertex2f(0.015, 0);
    glEnd();
    glPopMatrix();

    //��ǻ�� �����
    glPushMatrix();
    glTranslatef(0.02, -0.57, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0.02, 0.4);
    glVertex2f(0.02, 0.52);
    glVertex2f(0.17, 0.52);
    glVertex2f(0.17, 0.4);
    glEnd();
    glPopMatrix();

    //��ǻ�� ����� �� ȭ��
    glPushMatrix();
    glTranslatef(0.02, -0.5, 0);
    glColor3f(0, 0, 0.65);
    glBegin(GL_QUADS);
    glVertex2f(0.035, 0.35);
    glVertex2f(0.035, 0.43);
    glVertex2f(0.155, 0.43);
    glVertex2f(0.155, 0.35);
    glEnd();
    glPopMatrix();

    //��ǻ�� ����� �� ȭ�� ���α׷��� 1��
    glPushMatrix();
    glTranslatef(0.06, -0.152, 0);
    glColor3f(0.5, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.005, 0.05);
    glVertex2f(0.005, 0.07);
    glVertex2f(0.025, 0.07);
    glVertex2f(0.025, 0.05);
    glEnd();
    glPopMatrix();

    //��ǻ�� ����� �� ȭ�� ���α׷��� 2��
    glPushMatrix();
    glTranslatef(0.09, -0.152, 0);
    glColor3f(0.5, 0.5, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.005, 0.05);
    glVertex2f(0.005, 0.07);
    glVertex2f(0.025, 0.07);
    glVertex2f(0.025, 0.05);
    glEnd();
    glPopMatrix();


    //��ǻ�� ����� �� ȭ�� ���α׷��� 3��
    glPushMatrix();
    glTranslatef(0.059, -0.18, 0);
    glColor3f(0, 0.5, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.005, 0.05);
    glVertex2f(0.005, 0.07);
    glVertex2f(0.025, 0.07);
    glVertex2f(0.025, 0.05);
    glEnd();
    glPopMatrix();


    //��ǻ�� ����� �� �޸�
    glPushMatrix();
    glTranslatef(0.18, -0.19, 0);
    glColor3f(0.8, 0.8, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 0.1);
    glVertex2f(0.0, 0.13);
    glVertex2f(0.027, 0.13);
    glVertex2f(0.027, 0.1);
    glEnd();
    glPopMatrix();
}

void chair() {
    //���� ����
    glTranslatef(0, 0, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-0.13, -0.32);
    glVertex2f(-0.13, -0.1);
    glVertex2f(0, -0.1);
    glVertex2f(0, -0.32);
    glEnd();
    //���� ���� ������ �׵θ�
    glPushMatrix();
    glTranslatef(-0.05, 0, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, -0.32);
    glVertex2f(0.05, -0.1);
    glVertex2f(0.07, -0.1);
    glVertex2f(0.07, -0.32);
    glEnd();
    glPopMatrix();

    //���� �Ӹ���ħ ������ ��ħ
    glPushMatrix();
    glTranslatef(-0.065, 0.015, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, -0.115);
    glVertex2f(0.05, -0.1);
    glVertex2f(0.07, -0.1);
    glVertex2f(0.07, -0.115);
    glEnd();
    glPopMatrix();

    //���� �Ӹ���ħ ���� ��ħ
    glPushMatrix();
    glTranslatef(-0.165, 0.015, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, -0.115);
    glVertex2f(0.05, -0.1);
    glVertex2f(0.07, -0.1);
    glVertex2f(0.07, -0.115);
    glEnd();
    glPopMatrix();

    //���� �Ӹ� ��ħ��
    glPushMatrix();
    glTranslatef(0, 0.085, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-0.14, -0.12);
    glVertex2f(-0.14, -0.17);
    glVertex2f(0.02, -0.17);
    glVertex2f(0.02, -0.12);
    glEnd();
    glPopMatrix();

    //���� �Ӹ� ��ħ�� ����ǥ��
    glPushMatrix();
    glTranslatef(0, 0.085, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.005, -0.12);
    glVertex2f(-0.005, -0.17);
    glVertex2f(0.025, -0.17);
    glVertex2f(0.025, -0.12);
    glEnd();
    glPopMatrix();

    //���� �ȹ��� 1��
    glPushMatrix();
    glTranslatef(0, -0.12, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(0.01, -0.12);
    glVertex2f(0.01, -0.14);
    glVertex2f(0.12, -0.14);
    glVertex2f(0.12, -0.12);
    glEnd();
    glPopMatrix();

    //���� �ȹ��� 2��
    glPushMatrix();
    glTranslatef(0, -0.13, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(0.01, -0.12);
    glVertex2f(0.01, -0.14);
    glVertex2f(0.11, -0.14);
    glVertex2f(0.11, -0.12);
    glEnd();
    glPopMatrix();

    //���� ���
    glPushMatrix();
    glTranslatef(0, -0.17, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(0.01, -0.12);
    glVertex2f(0.01, -0.15);
    glVertex2f(0.095, -0.15);
    glVertex2f(0.095, -0.12);
    glEnd();
    glPopMatrix();

    //���� ���� ����κ�
    glPushMatrix();
    glTranslatef(-0.015, -0.19, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, -0.13);
    glVertex2f(-0.01, -0.15);
    glVertex2f(0.01, -0.15);
    glVertex2f(0.01, -0.13);
    glEnd();
    glPopMatrix();

    //���� �ؿ� ���
    glPushMatrix();
    glTranslatef(-0.015, -0.21, 0);
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, -0.13);
    glVertex2f(-0.01, -0.25);
    glVertex2f(0.01, -0.25);
    glVertex2f(0.01, -0.13);
    glEnd();
    glPopMatrix();

    //���� ���� ���� ���� �κ�
    glPushMatrix();
    glTranslatef(-0.015, -0.32, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.07, -0.13);
    glVertex2f(-0.07, -0.15);
    glVertex2f(0.07, -0.15);
    glVertex2f(0.07, -0.13);
    glEnd();
    glPopMatrix();

    //���� ����
    glPushMatrix();
    glTranslatef(-0.015, -0.34, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.08, -0.13);
    glVertex2f(-0.08, -0.16);
    glVertex2f(-0.06, -0.16);
    glVertex2f(-0.06, -0.13);
    glEnd();
    glPopMatrix();

    //���� �߰�
    glPushMatrix();
    glTranslatef(-0.015, -0.34, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, -0.13);
    glVertex2f(-0.01, -0.16);
    glVertex2f(0.01, -0.16);
    glVertex2f(0.01, -0.13);
    glEnd();
    glPopMatrix();

    //���� ������
    glPushMatrix();
    glTranslatef(-0.015, -0.34, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(0.08, -0.13);
    glVertex2f(0.08, -0.16);
    glVertex2f(0.06, -0.16);
    glVertex2f(0.06, -0.13);
    glEnd();
    glPopMatrix();
}

void coffee() {
    glTranslatef(0, 0, 0);
    glColor3f(0.6, 0.4, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-0.1, -0.5);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, -0.5);
    glEnd();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.5, 0.3, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0.2, -0.5);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.35, 0.1);
    glVertex2f(0.35, -0.5);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� �׵θ�
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.55, 0.35, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.19, -0.5);
    glVertex2f(0.19, 0.1);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, -0.5);
    glEnd();
    glPopMatrix();

    //���Ǳ� Ŀ�Ǹ�� �簢��
    glPushMatrix();
    glTranslatef(-0.05, -0.15, 0);
    glColor3f(0.35, 0.25, 0.15);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, 0.2);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.2, 0);
    glEnd();
    glPopMatrix();

    //���Ǳ� Ŀ�Ǹ�� �簢��
    glPushMatrix();
    glTranslatef(-0.05, -0.15, 0);
    glColor3f(0.35, 0.25, 0.15);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, 0.2);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.2, 0);
    glEnd();
    glPopMatrix();

    //Ŀ�Ǹ��
    glPushMatrix();
    glTranslatef(0.05, -0.05, 0);
    glColor3f(0.8, 0.8, 0.8);
    glutSolidTeapot(0.05);
    glEnd();
    glPopMatrix();

    //Ŀ�Ǹ�� �׵θ� 1 (��)
    glPushMatrix();
    glTranslatef(-0.45, 0.56, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.51);
    glVertex2f(0.4, -0.52);
    glVertex2f(0.6, -0.52);
    glVertex2f(0.6, -0.51);
    glEnd();
    glPopMatrix();

    //Ŀ�Ǹ�� �׵θ� 2 (�Ʒ�)
    glPushMatrix();
    glTranslatef(-0.45, 0.36, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.51);
    glVertex2f(0.4, -0.52);
    glVertex2f(0.6, -0.52);
    glVertex2f(0.6, -0.51);
    glEnd();
    glPopMatrix();

    //Ŀ�Ǹ�� �׵θ� 3 (��)
    glPushMatrix();
    glTranslatef(-0.45, 0.36, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.51);
    glVertex2f(0.4, -0.31);
    glVertex2f(0.41, -0.31);
    glVertex2f(0.41, -0.51);
    glEnd();
    glPopMatrix();

    //Ŀ�Ǹ�� �׵θ� 4 (��)
    glPushMatrix();
    glTranslatef(-0.25, 0.36, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.52);
    glVertex2f(0.4, -0.31);
    glVertex2f(0.41, -0.31);
    glVertex2f(0.41, -0.52);
    glEnd();
    glPopMatrix();

    //���Ǳ� �ؿ� ��ư (������)
    glPushMatrix();
    glTranslatef(-0.05, -0.15, 0);
    glColor3f(0.6, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0, -0.1);
    glVertex2f(0, -0.05);
    glVertex2f(0.2, -0.05);
    glVertex2f(0.2, -0.1);
    glEnd();
    glPopMatrix();

    //���Ǳ� �ؿ� ��ư(�����)
    glPushMatrix();
    glTranslatef(-0.05, -0.22, 0);
    glColor3f(0.6, 0.6, 0);
    glBegin(GL_QUADS);
    glVertex2f(0, -0.1);
    glVertex2f(0, -0.05);
    glVertex2f(0.2, -0.05);
    glVertex2f(0.2, -0.1);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 1)
    glPushMatrix();
    glTranslatef(-0.04, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 2)
    glPushMatrix();
    glTranslatef(-0.01, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 3)
    glPushMatrix();
    glTranslatef(0.02, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 4)
    glPushMatrix();
    glTranslatef(0.05, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 5)
    glPushMatrix();
    glTranslatef(0.08, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 6)
    glPushMatrix();
    glTranslatef(0.11, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 1)
    glPushMatrix();
    glTranslatef(-0.04, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 2)
    glPushMatrix();
    glTranslatef(-0.01, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 3)
    glPushMatrix();
    glTranslatef(0.02, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 4)
    glPushMatrix();
    glTranslatef(0.05, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 5)
    glPushMatrix();
    glTranslatef(0.08, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 6)
    glPushMatrix();
    glTranslatef(0.11, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //Ŀ���Ա�
    glPushMatrix();
    glTranslatef(0.005, -0.3, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0, -0.15);
    glVertex2f(0, -0.05);
    glVertex2f(0.1, -0.05);
    glVertex2f(0.1, -0.15);
    glEnd();
    glPopMatrix();

    //Ŀ���Ա��� Ŀ��
    glPushMatrix();
    glTranslatef(0.05, -0.4, 0);
    glColor3f(0.8, 0.8, 0.8);
    glutSolidTeapot(0.02);
    glEnd();
    glPopMatrix();

    //���Ǳ� ���� �׵θ�
    glPushMatrix();
    glTranslatef(0, 0.62, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.105, -0.51);
    glVertex2f(-0.105, -0.52);
    glVertex2f(0.355, -0.52);
    glVertex2f(0.355, -0.51);
    glEnd();
    glPopMatrix();

    //���Ǳ� �� �׵θ�
    glPushMatrix();
    glTranslatef(0, 0.01, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.105, -0.51);
    glVertex2f(-0.105, -0.52);
    glVertex2f(0.355, -0.52);
    glVertex2f(0.355, -0.51);
    glEnd();
    glPopMatrix();

    //���Ǳ� ���� �׵θ�
    glPushMatrix();
    glTranslatef(0.005, 0.0, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.105, -0.51);
    glVertex2f(-0.105, 0.1);
    glVertex2f(-0.115, 0.1);
    glVertex2f(-0.115, -0.51);
    glEnd();
    glPopMatrix();

    //���Ǳ� ������ �׵θ�
    glPushMatrix();
    glTranslatef(0.46, 0.0, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.105, -0.51);
    glVertex2f(-0.105, 0.1);
    glVertex2f(-0.115, 0.1);
    glVertex2f(-0.115, -0.51);
    glEnd();
    glPopMatrix();
}

void coffee1() {
    glTranslatef(0, 0, 0);
    glColor3f(0.1, 0.2, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.1, -0.5);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, -0.5);
    glEnd();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.1, 0.2, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0.2, -0.5);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.35, 0.1);
    glVertex2f(0.35, -0.5);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� �׵θ�
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.1, 0.1, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.19, -0.5);
    glVertex2f(0.19, 0.1);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, -0.5);
    glEnd();
    glPopMatrix();

    //���Ǳ� Ŀ�Ǹ�� �簢��
    glPushMatrix();
    glTranslatef(-0.05, -0.15, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, 0.2);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.2, 0);
    glEnd();
    glPopMatrix();

    //Ŀ�Ǹ��
    glPushMatrix();
    glTranslatef(0.05, -0.05, 0);
    glColor3f(0.1, 0.1, 0.9);
    glutSolidTeapot(0.05);
    glEnd();
    glPopMatrix();

    //Ŀ�Ǹ�� �׵θ� 1 (��)
    glPushMatrix();
    glTranslatef(-0.45, 0.56, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.51);
    glVertex2f(0.4, -0.52);
    glVertex2f(0.6, -0.52);
    glVertex2f(0.6, -0.51);
    glEnd();
    glPopMatrix();

    //Ŀ�Ǹ�� �׵θ� 2 (�Ʒ�)
    glPushMatrix();
    glTranslatef(-0.45, 0.36, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.51);
    glVertex2f(0.4, -0.52);
    glVertex2f(0.6, -0.52);
    glVertex2f(0.6, -0.51);
    glEnd();
    glPopMatrix();

    //Ŀ�Ǹ�� �׵θ� 3 (��)
    glPushMatrix();
    glTranslatef(-0.45, 0.36, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.51);
    glVertex2f(0.4, -0.31);
    glVertex2f(0.41, -0.31);
    glVertex2f(0.41, -0.51);
    glEnd();
    glPopMatrix();

    //Ŀ�Ǹ�� �׵θ� 4 (��)
    glPushMatrix();
    glTranslatef(-0.25, 0.36, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.52);
    glVertex2f(0.4, -0.31);
    glVertex2f(0.41, -0.31);
    glVertex2f(0.41, -0.52);
    glEnd();
    glPopMatrix();

    //���Ǳ� �ؿ� ��ư (������)
    glPushMatrix();
    glTranslatef(-0.05, -0.15, 0);
    glColor3f(0.6, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0, -0.1);
    glVertex2f(0, -0.05);
    glVertex2f(0.2, -0.05);
    glVertex2f(0.2, -0.1);
    glEnd();
    glPopMatrix();

    //���Ǳ� �ؿ� ��ư(�����)
    glPushMatrix();
    glTranslatef(-0.05, -0.22, 0);
    glColor3f(0.6, 0.6, 0);
    glBegin(GL_QUADS);
    glVertex2f(0, -0.1);
    glVertex2f(0, -0.05);
    glVertex2f(0.2, -0.05);
    glVertex2f(0.2, -0.1);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 1)
    glPushMatrix();
    glTranslatef(-0.04, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 2)
    glPushMatrix();
    glTranslatef(-0.01, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 3)
    glPushMatrix();
    glTranslatef(0.02, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 4)
    glPushMatrix();
    glTranslatef(0.05, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 5)
    glPushMatrix();
    glTranslatef(0.08, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (���� 6)
    glPushMatrix();
    glTranslatef(0.11, -0.235, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 1)
    glPushMatrix();
    glTranslatef(-0.04, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 2)
    glPushMatrix();
    glTranslatef(-0.01, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 3)
    glPushMatrix();
    glTranslatef(0.02, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 4)
    glPushMatrix();
    glTranslatef(0.05, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 5)
    glPushMatrix();
    glTranslatef(0.08, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //���Ǳ� ��� ��ư (�Ʒ� 6)
    glPushMatrix();
    glTranslatef(0.11, -0.305, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, 0.0);
    glVertex2f(0, 0.02);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, 0.0);
    glEnd();
    glPopMatrix();

    //Ŀ���Ա�
    glPushMatrix();
    glTranslatef(0.005, -0.3, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0, -0.15);
    glVertex2f(0, -0.05);
    glVertex2f(0.1, -0.05);
    glVertex2f(0.1, -0.15);
    glEnd();
    glPopMatrix();

    //Ŀ���Ա��� Ŀ��
    glPushMatrix();
    glTranslatef(0.05, -0.4, 0);
    glColor3f(0.1, 0.1, 0.9);
    glutSolidTeapot(0.02);
    glEnd();
    glPopMatrix();

    //���Ǳ� ���� �׵θ�
    glPushMatrix();
    glTranslatef(0, 0.62, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.105, -0.51);
    glVertex2f(-0.105, -0.52);
    glVertex2f(0.355, -0.52);
    glVertex2f(0.355, -0.51);
    glEnd();
    glPopMatrix();

    //���Ǳ� �� �׵θ�
    glPushMatrix();
    glTranslatef(0, 0.01, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.105, -0.51);
    glVertex2f(-0.105, -0.52);
    glVertex2f(0.355, -0.52);
    glVertex2f(0.355, -0.51);
    glEnd();
    glPopMatrix();

    //���Ǳ� ���� �׵θ�
    glPushMatrix();
    glTranslatef(0.005, 0.0, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.105, -0.51);
    glVertex2f(-0.105, 0.1);
    glVertex2f(-0.115, 0.1);
    glVertex2f(-0.115, -0.51);
    glEnd();
    glPopMatrix();

    //���Ǳ� ������ �׵θ�
    glPushMatrix();
    glTranslatef(0.46, 0.0, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.105, -0.51);
    glVertex2f(-0.105, 0.1);
    glVertex2f(-0.115, 0.1);
    glVertex2f(-0.115, -0.51);
    glEnd();
    glPopMatrix();

}

void meetingroom() {
    //���÷� ��ü ���
    glTranslatef(0, 0.0, 0.0);
    glColor3f(0.3, 0.4, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.67);
    glVertex2f(-0.7, 0.5);
    glVertex2f(0.7, 0.5);
    glVertex2f(0.7, -0.5);
    glEnd();

    //��������Ʈ
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.35, -0.275);
    glVertex2f(-0.35, 0.3);
    glVertex2f(0.525, 0.3);
    glVertex2f(0.525, -0.275);
    glEnd();
    glPopMatrix();

    //��������Ʈ ���� �׵θ�
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.35, 0.3);
    glVertex2f(-0.35, 0.285);
    glVertex2f(0.525, 0.285);
    glVertex2f(0.525, 0.3);
    glEnd();
    glPopMatrix();

    //��������Ʈ ������ �׵θ�
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0.525, -0.275);
    glVertex2f(0.525, 0.3);
    glVertex2f(0.535, 0.3);
    glVertex2f(0.535, -0.275);
    glEnd();
    glPopMatrix();

    //���÷� �ٴ�
    glPushMatrix();
    glColor3f(0.7, 0.6, 0.55);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.67);
    glVertex2f(-0.7, -0.5);
    glVertex2f(0.7, -0.5);
    glVertex2f(0.7, -0.67);
    glEnd();
    glPopMatrix();

    //���÷� �ٴ��׵θ�
    glPushMatrix();
    glColor3f(0.6, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.51);
    glVertex2f(-0.7, -0.5);
    glVertex2f(0.7, -0.5);
    glVertex2f(0.7, -0.51);
    glEnd();
    glPopMatrix();

    //���÷� �����׵θ�
    glPushMatrix();
    glColor3f(0.6, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.5);
    glVertex2f(-0.7, 0.5);
    glVertex2f(-0.69, 0.5);
    glVertex2f(-0.69, -0.5);
    glEnd();
    glPopMatrix();

    //���÷� �������׵θ�
    glPushMatrix();
    glColor3f(0.6, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.69, -0.5);
    glVertex2f(0.69, 0.5);
    glVertex2f(0.7, 0.5);
    glVertex2f(0.7, -0.5);
    glEnd();
    glPopMatrix();

    //���÷� �����׵θ�
    glPushMatrix();
    glColor3f(0.6, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, 0.49);
    glVertex2f(-0.7, 0.5);
    glVertex2f(0.7, 0.5);
    glVertex2f(0.7, 0.49);
    glEnd();
    glPopMatrix();

    //���÷� �߾� ���̺�
    glPushMatrix();
    glColor3f(0.4, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.55);
    glVertex2f(-0.5, -0.3);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.1, -0.55);
    glEnd();
    glPopMatrix();

    //���÷� �߾� ���̺�(�ȿ� �׸���)
    glPushMatrix();
    glColor3f(0.25, 0.15, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.48, -0.55);
    glVertex2f(-0.48, -0.32);
    glVertex2f(0.08, -0.32);
    glVertex2f(0.08, -0.55);
    glEnd();
    glPopMatrix();

    //���÷� �߾� ���̺�(������)
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.55);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.3, -0.3);
    glVertex2f(0.3, -0.55);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.35, -0.1, 0);
    chair();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.05, -0.1, 0);
    chair();
    glPopMatrix();

    //��ǥ��
    glPushMatrix();
    glColor3f(0.4, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.55);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.55);
    glEnd();
    glPopMatrix();

    //��ǥ�� ���κ�
    glPushMatrix();
    glColor3f(0.4, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.4, -0.25);
    glVertex2f(0.55, -0.25);
    glVertex2f(0.55, -0.3);
    glEnd();
    glPopMatrix();

    //��ǥ�� ���κ�(����)
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.25);
    glVertex2f(0.6, -0.275);
    glVertex2f(0.6, -0.3);
    glEnd();
    glPopMatrix();

    //��ǥ��(����)
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.55, -0.55);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.6, -0.55);
    glEnd();
    glPopMatrix();

    //��ǥ�� (����) 1
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.42, -0.55);
    glVertex2f(0.42, -0.29);
    glVertex2f(0.43, -0.29);
    glVertex2f(0.43, -0.55);
    glEnd();
    glPopMatrix();

    //��ǥ�� (����) 2
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.52, -0.55);
    glVertex2f(0.52, -0.29);
    glVertex2f(0.53, -0.29);
    glVertex2f(0.53, -0.55);
    glEnd();
    glPopMatrix();

    //��ǥ�� (����) 3
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.29);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.29);
    glEnd();
    glPopMatrix();

    //��ǥ�� (����) 4
    glPushMatrix();
    glColor3f(0.3, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.4, -0.31);
    glVertex2f(0.6, -0.31);
    glVertex2f(0.6, -0.3);
    glEnd();
    glPopMatrix();

    //��ǥ�� ��Ʈ��
    glPushMatrix();
    glColor3f(0.66, 0.66, 0.66);
    glBegin(GL_POLYGON);
    glVertex2f(0.43, -0.25);
    glVertex2f(0.41, -0.2);
    glVertex2f(0.51, -0.2);
    glVertex2f(0.53, -0.25);
    glEnd();
    glPopMatrix();

    //��ǥ�� ��Ʈ��(����)
    glPushMatrix();
    glColor3f(0.77, 0.77, 0.77);
    glBegin(GL_POLYGON);
    glVertex2f(0.53, -0.25);
    glVertex2f(0.51, -0.2);
    glVertex2f(0.52, -0.2);
    glVertex2f(0.54, -0.25);
    glEnd();
    glPopMatrix();

    //��ǥ�� ����ũ
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.54, -0.25);
    glVertex2f(0.54, -0.22);
    glVertex2f(0.55, -0.22);
    glVertex2f(0.55, -0.25);
    glEnd();
    glPopMatrix();

    //��ǥ�� ����ũ
    glPushMatrix();
    glTranslatef(0.695, 0.36, 0);
    glRotatef(280, 0, 0, 1);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.54, -0.25);
    glVertex2f(0.54, -0.22);
    glVertex2f(0.55, -0.22);
    glVertex2f(0.55, -0.25);
    glEnd();
    glPopMatrix();

    //��ǥ�� ����ũ
    glPushMatrix();
    glTranslatef(0.57, -0.215, 0);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.3, 0.3, 0.1);
    glutSolidSphere(0.03, 50, 10);
    glEnd();
    glPopMatrix();




}
//������ ���� ����

//������ ������ ���������� �Ѿ�� �� ���������� ��
void elevator() {
    glTranslatef(0, 0, 0);
    glColor3f(0.5, 0.6, 0.65);
    glBegin(GL_POLYGON);
    glVertex2f(-0.24, -0.5);
    glVertex2f(-0.24, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.24, -0.5);
    glEnd();

    //��ǻ�� �ν� ���� �׵θ�
    glPushMatrix();
    glTranslatef(-0.24, -0.2, 0);
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.3);
    glVertex2f(0.01, -0.3);
    glVertex2f(-0.01, -0.3);
    glVertex2f(-0.01, 0.3);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� ������ �׵θ�
    glPushMatrix();
    glTranslatef(0.24, -0.2, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.3);
    glVertex2f(0.01, -0.3);
    glVertex2f(-0.01, -0.3);
    glVertex2f(-0.01, 0.3);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� ���� �׵θ�
    glPushMatrix();
    glTranslatef(0, 0.1, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.25, 0.005);
    glVertex2f(0.25, -0.005);
    glVertex2f(-0.25, -0.005);
    glVertex2f(-0.25, 0.005);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� �߰� �׵θ�
    glPushMatrix();
    glTranslatef(0, -0.2, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.005, 0.3);
    glVertex2f(0.005, -0.3);
    glVertex2f(-0.005, -0.3);
    glVertex2f(-0.005, 0.3);
    glEnd();
    glPopMatrix();

    //���� �� ������
    glPushMatrix();
    glTranslatef(0, -0.1, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.24, 0.25);
    glVertex2f(-0.24, 0.4);
    glVertex2f(0.24, 0.4);
    glVertex2f(0.24, 0.25);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(-0.02, -0.07, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.3);
    glVertex2f(-0.01, 0.33);
    glVertex2f(0.0, 0.33);
    glVertex2f(0.0, 0.3);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(0.3, 0.27, 0);
    glRotatef(90, 0, 0, 1);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.28);
    glVertex2f(-0.01, 0.33);
    glVertex2f(0, 0.33);
    glVertex2f(0, 0.28);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(0.3, 0.23, 0);
    glRotatef(90, 0, 0, 1);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.28);
    glVertex2f(-0.01, 0.33);
    glVertex2f(0, 0.33);
    glVertex2f(0, 0.28);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(0.3, 0.19, 0);
    glRotatef(90, 0, 0, 1);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.28);
    glVertex2f(-0.01, 0.33);
    glVertex2f(0, 0.33);
    glVertex2f(0, 0.28);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(0.02, -0.11, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.3);
    glVertex2f(-0.01, 0.33);
    glVertex2f(0.0, 0.33);
    glVertex2f(0.0, 0.3);
    glEnd();
    glPopMatrix();
}

void elevatorIn() {

    //�Ͼ� ���
    glTranslatef(0, 0, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.24, -0.5);
    glVertex2f(-0.24, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.24, -0.5);
    glEnd();

    //���� ȸ�� ��
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.18, -0.45);
    glVertex2f(-0.18, 0.05);
    glVertex2f(0.18, 0.05);
    glVertex2f(0.18, -0.45);
    glEnd();
    glPopMatrix();

    //�Ʒ� �ٴ�
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(-0.24, -0.5);
    glVertex2f(-0.18, -0.45);
    glVertex2f(0.18, -0.45);
    glVertex2f(0.24, -0.5);
    glEnd();
    glPopMatrix();

    //��
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex2f(-0.18, 0.05);
    glVertex2f(-0.24, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.18, 0.05);
    glEnd();
    glPopMatrix();

    //���� �� ����
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.3, 0.3, 1);
    glBegin(GL_QUADS);
    glVertex2f(-0.13, 0);
    glVertex2f(-0.13, -0.2);
    glVertex2f(0.13, -0.2);
    glVertex2f(0.13, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.08, 0);
    glScalef(0.42, 0.25, 0);
    window2();
    glEnd();
    glPopMatrix();

    //���� ���� �׵θ�
    glPushMatrix();
    glTranslatef(-0.24, -0.2, 0);
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.3);
    glVertex2f(0.01, -0.3);
    glVertex2f(-0.01, -0.3);
    glVertex2f(-0.01, 0.3);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� ������ �׵θ�
    glPushMatrix();
    glTranslatef(0.24, -0.2, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.3);
    glVertex2f(0.01, -0.3);
    glVertex2f(-0.01, -0.3);
    glVertex2f(-0.01, 0.3);
    glEnd();
    glPopMatrix();

    //��ǻ�� �ν� ���� �׵θ�
    glPushMatrix();
    glTranslatef(0, 0.1, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.25, 0.005);
    glVertex2f(0.25, -0.005);
    glVertex2f(-0.25, -0.005);
    glVertex2f(-0.25, 0.005);
    glEnd();
    glPopMatrix();

    //���� �� ������
    glPushMatrix();
    glTranslatef(0, -0.1, 0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.24, 0.25);
    glVertex2f(-0.24, 0.4);
    glVertex2f(0.24, 0.4);
    glVertex2f(0.24, 0.25);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(-0.02, -0.07, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.3);
    glVertex2f(-0.01, 0.33);
    glVertex2f(0.0, 0.33);
    glVertex2f(0.0, 0.3);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(0.3, 0.27, 0);
    glRotatef(90, 0, 0, 1);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.28);
    glVertex2f(-0.01, 0.33);
    glVertex2f(0, 0.33);
    glVertex2f(0, 0.28);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(0.3, 0.23, 0);
    glRotatef(90, 0, 0, 1);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.28);
    glVertex2f(-0.01, 0.33);
    glVertex2f(0, 0.33);
    glVertex2f(0, 0.28);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(0.3, 0.19, 0);
    glRotatef(90, 0, 0, 1);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.28);
    glVertex2f(-0.01, 0.33);
    glVertex2f(0, 0.33);
    glVertex2f(0, 0.28);
    glEnd();
    glPopMatrix();

    //���� �� ������ �� ����
    glPushMatrix();
    glTranslatef(0.02, -0.11, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.01, 0.3);
    glVertex2f(-0.01, 0.33);
    glVertex2f(0.0, 0.33);
    glVertex2f(0.0, 0.3);
    glEnd();
    glPopMatrix();
}

void elevatorClose() {
    if (Delta < 3660) {
        elevatorIn();
    }
}

void elevatorOpen() {
    if (Delta < 3710) {
        elevator();
    }
}

void Entrance() {

    //�����ʺ� ����

    //���� ������ ��
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-1, -0.5);
    glVertex2f(-1, 0.67);
    glVertex2f(-0.95, 0.67);
    glVertex2f(-0.95, -0.5);
    glEnd();
    glPopMatrix();

    //���� �Ա�
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, -0.5);
    glVertex2f(-0.95, 0.05);
    glVertex2f(-0.75, 0);
    glVertex2f(-0.75, -0.5);
    glEnd();
    glPopMatrix();

    //���Թ�
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.68, 0.85, 0.95, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-1.1, -0.5);
    glVertex2f(-1.1, 0);
    glVertex2f(-0.9, 0);
    glVertex2f(-0.9, -0.5);
    glEnd();
    glPopMatrix();

    //���Թ� ���� �׵θ� (��ο��)
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-1.1, 0);
    glVertex2f(-1.1, 0.02);
    glVertex2f(-0.9, 0.02);
    glVertex2f(-0.9, 0);
    glEnd();
    glPopMatrix();

    //���Թ� ���� �׵θ� (������)
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-1.09, 0);
    glVertex2f(-1.09, 0.012);
    glVertex2f(-0.9, 0.012);
    glVertex2f(-0.9, 0);
    glEnd();
    glPopMatrix();


    //���Թ� �Ʒ��� �׵θ� (������)
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-1.1, -0.5);
    glVertex2f(-1.1, -0.45);
    glVertex2f(-0.9, -0.45);
    glVertex2f(-0.9, -0.5);
    glEnd();
    glPopMatrix();

    //���Թ� �Ʒ��� �׵θ� (��ο��)
    glPushMatrix();
    glColor3f(0.55, 0.6, 0.65);
    glBegin(GL_POLYGON);
    glVertex2f(-1.09, -0.5);
    glVertex2f(-1.09, -0.46);
    glVertex2f(-0.9, -0.46);
    glVertex2f(-0.9, -0.5);
    glEnd();
    glPopMatrix();

    //���Թ� ������ �׵θ�
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9, 0);
    glVertex2f(-0.9, -0.5);
    glVertex2f(-0.91, -0.5);
    glVertex2f(-0.91, 0);
    glEnd();
    glPopMatrix();

    //���Թ� ������ (������)
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-1.08, -0.3);
    glVertex2f(-1.08, -0.2);
    glVertex2f(-1.06, -0.2);
    glVertex2f(-1.06, -0.3);
    glEnd();
    glPopMatrix();

    //���Թ� ������ (��ο��)
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-1.073, -0.3);
    glVertex2f(-1.073, -0.208);
    glVertex2f(-1.06, -0.208);
    glVertex2f(-1.06, -0.3);
    glEnd();
    glPopMatrix();
}

void Entrance1() {
    glPushMatrix();
    glTranslatef(0, 0, 0);
    //�����ʺ� ����
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.67);
    glVertex2f(-0.7, 0.67);
    glVertex2f(-0.5, 0.67);
    glVertex2f(-0.5, -0.67);
    glEnd();

    //������ ��������
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.75, -0.67);
    glVertex2f(-0.75, 0.67);
    glVertex2f(-0.7, 0.67);
    glVertex2f(-0.7, -0.67);
    glEnd();
    glPopMatrix();

    //���� â��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.68, 0.85, 0.95, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.25);
    glVertex2f(-0.95, 0.45);
    glVertex2f(-0.75, 0.41);
    glVertex2f(-0.75, 0.21);
    glEnd();
    glPopMatrix();

    //���� â�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.25);
    glVertex2f(-0.95, 0.45);
    glVertex2f(-0.91, 0.445);
    glVertex2f(-0.91, 0.24);
    glEnd();
    glPopMatrix();

    //���� â�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.77, 0.21);
    glVertex2f(-0.77, 0.415);
    glVertex2f(-0.75, 0.41);
    glVertex2f(-0.75, 0.205);
    glEnd();
    glPopMatrix();

    //���� â�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.91, 0.24);
    glVertex2f(-0.91, 0.26);
    glVertex2f(-0.75, 0.22);
    glVertex2f(-0.75, 0.195);
    glEnd();
    glPopMatrix();

    //���� ������ ��
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.45);
    glVertex2f(-0.95, 0.67);
    glVertex2f(-0.75, 0.67);
    glVertex2f(-0.75, 0.41);
    glEnd();
    glPopMatrix();

    //���� ������ ��
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.05);
    glVertex2f(-0.95, 0.25);
    glVertex2f(-0.75, 0.2);
    glVertex2f(-0.75, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

//������ ������ ����
void EntranceOut1() {
    glPushMatrix();
    glTranslatef(0, 0, 0);
    //�����ʺ� ����
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.67);
    glVertex2f(-0.7, 0.67);
    glVertex2f(-0.5, 0.67);
    glVertex2f(-0.5, -0.67);
    glEnd();

    //������ ��������
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.75, -0.67);
    glVertex2f(-0.75, 0.67);
    glVertex2f(-0.7, 0.67);
    glVertex2f(-0.7, -0.67);
    glEnd();
    glPopMatrix();

    //���� â��
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.68, 0.85, 0.95, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.25);
    glVertex2f(-0.95, 0.45);
    glVertex2f(-0.75, 0.41);
    glVertex2f(-0.75, 0.21);
    glEnd();
    glPopMatrix();

    //���� â�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.25);
    glVertex2f(-0.95, 0.45);
    glVertex2f(-0.91, 0.445);
    glVertex2f(-0.91, 0.24);
    glEnd();
    glPopMatrix();

    //���� â�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.77, 0.21);
    glVertex2f(-0.77, 0.415);
    glVertex2f(-0.75, 0.41);
    glVertex2f(-0.75, 0.205);
    glEnd();
    glPopMatrix();

    //���� â�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.91, 0.24);
    glVertex2f(-0.91, 0.26);
    glVertex2f(-0.75, 0.22);
    glVertex2f(-0.75, 0.195);
    glEnd();
    glPopMatrix();

    //���� ������ ��
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.45);
    glVertex2f(-0.95, 0.67);
    glVertex2f(-0.75, 0.67);
    glVertex2f(-0.75, 0.41);
    glEnd();
    glPopMatrix();

    //���� ������ ��
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.05);
    glVertex2f(-0.95, 0.25);
    glVertex2f(-0.75, 0.2);
    glVertex2f(-0.75, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void Door() {
    // �� ��ü (����)
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-1.5, -0.5);
    glVertex2f(-1.5, 0.2);
    glVertex2f(-1.0, 0.2);
    glVertex2f(-1.0, -0.5);

    // �� ���� �׵θ� (£������)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.5, -0.5);
    glVertex2f(-1.5, 0.2);
    glVertex2f(-1.49, 0.2);
    glVertex2f(-1.49, -0.5);

    // �� ������ �׵θ� (£������)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.99, -0.5);
    glVertex2f(-0.99, 0.2);
    glVertex2f(-1.0, 0.2);
    glVertex2f(-1.0, -0.5);

    // �� â�� �Ʒ� �׵θ� (£������)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, -0.25);
    glVertex2f(-1.45, -0.26);
    glVertex2f(-1.05, -0.26);
    glVertex2f(-1.05, -0.25);

    // �� â�� �� �׵θ� (£������)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, 0.15);
    glVertex2f(-1.45, 0.14);
    glVertex2f(-1.05, 0.14);
    glVertex2f(-1.05, 0.15);

    // �� â�� �Ʒ� ������ (£������)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, -0.35);
    glVertex2f(-1.45, -0.27);
    glVertex2f(-1.43, -0.27);
    glVertex2f(-1.43, -0.35);

    //�� â��
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, -0.23);
    glVertex2f(-1.45, 0.13);
    glVertex2f(-1.05, 0.13);
    glVertex2f(-1.05, -0.23);

    //�� â�� ���� (����)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, -0.23);
    glVertex2f(-1.45, 0.13);
    glVertex2f(-1.43, 0.13);
    glVertex2f(-1.43, -0.23);

    //�� â�� ���� (������)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.05, -0.23);
    glVertex2f(-1.05, 0.13);
    glVertex2f(-1.07, 0.13);
    glVertex2f(-1.07, -0.23);

    //�� â�� ���� (��)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, 0.13);
    glVertex2f(-1.45, 0.12);
    glVertex2f(-1.05, 0.12);
    glVertex2f(-1.05, 0.13);

    //�� â�� ���� (�Ʒ�)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, -0.23);
    glVertex2f(-1.45, -0.22);
    glVertex2f(-1.05, -0.22);
    glVertex2f(-1.05, -0.23);
    glEnd();

    //�� �� â�� �ΰ� (���� ���)
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, -0.25);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, -0.25);
    glEnd();
    glPopMatrix();

    //�� �� â��
    glPushMatrix();
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-0.76, -0.22);
    glVertex2f(-0.76, 0.17);
    glVertex2f(-0.24, 0.17);
    glVertex2f(-0.24, -0.22);
    glEnd();
    glPopMatrix();

    //�� �� â�� ���� ����
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.77, -0.22);
    glVertex2f(-0.77, 0.17);
    glVertex2f(-0.755, 0.17);
    glVertex2f(-0.755, -0.22);
    glEnd();
    glPopMatrix();

    //���� â�� ���� ����
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.77, 0.17);
    glVertex2f(-0.77, 0.18);
    glVertex2f(-0.52, 0.18);
    glVertex2f(-0.52, 0.17);
    glEnd();
    glPopMatrix();

    //���� â�� �Ʒ��� ����
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.77, -0.22);
    glVertex2f(-0.77, -0.23);
    glVertex2f(-0.52, -0.23);
    glVertex2f(-0.52, -0.22);
    glEnd();
    glPopMatrix();

    //���� â�� ������ ����
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.535, -0.22);
    glVertex2f(-0.535, 0.17);
    glVertex2f(-0.52, 0.17);
    glVertex2f(-0.52, -0.22);
    glEnd();
    glPopMatrix();

    //������ â�� ���� ����
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.47, -0.22);
    glVertex2f(-0.47, 0.17);
    glVertex2f(-0.455, 0.17);
    glVertex2f(-0.455, -0.22);
    glEnd();
    glPopMatrix();

    //������ â�� ������ ����
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.225, -0.22);
    glVertex2f(-0.225, 0.17);
    glVertex2f(-0.24, 0.17);
    glVertex2f(-0.24, -0.22);
    glEnd();
    glPopMatrix();

    //������ â�� �Ʒ��� ����
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.47, -0.22);
    glVertex2f(-0.47, -0.23);
    glVertex2f(-0.225, -0.23);
    glVertex2f(-0.225, -0.22);
    glEnd();
    glPopMatrix();

    //������ â�� ���� ����
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.47, 0.17);
    glVertex2f(-0.47, 0.18);
    glVertex2f(-0.225, 0.18);
    glVertex2f(-0.225, 0.17);
    glEnd();
    glPopMatrix();

    //�� �� â�� �ΰ� �߰� �β��� �׵θ�
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.52, -0.25);
    glVertex2f(-0.52, 0.2);
    glVertex2f(-0.47, 0.2);
    glVertex2f(-0.47, -0.25);
    glEnd();
    glPopMatrix();

    //������ â�� ���� �ڹ���
    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(-0.455, -0.05);
    glVertex2f(-0.455, 0);
    glVertex2f(-0.435, 0);
    glVertex2f(-0.435, -0.05);
    glEnd();
    glPopMatrix();

    //������ â�� �ڹ���
    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(-0.455, -0.0);
    glVertex2f(-0.455, -0.035);
    glVertex2f(-0.425, -0.035);
    glVertex2f(-0.425, -0.0);
    glEnd();
    glPopMatrix();

    //������ â�� �ڹ��� �׵θ�
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.455, -0.0);
    glVertex2f(-0.455, -0.01);
    glVertex2f(-0.425, -0.01);
    glVertex2f(-0.425, -0.0);
    glEnd();
    glPopMatrix();

    //������ â�� �ڹ��� �׵θ�
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.455, -0.05);
    glVertex2f(-0.455, -0.04);
    glVertex2f(-0.435, -0.04);
    glVertex2f(-0.435, -0.05);
    glEnd();
    glPopMatrix();

    //������ â�� �ڹ��� �׵θ�
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.435, -0.04);
    glVertex2f(-0.435, -0.03);
    glVertex2f(-0.425, -0.03);
    glVertex2f(-0.425, -0.04);
    glEnd();
    glPopMatrix();

    //������ â�� �ڹ��� �׵θ�
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.43, -0.04);
    glVertex2f(-0.43, -0);
    glVertex2f(-0.42, -0);
    glVertex2f(-0.42, -0.04);
    glEnd();
    glPopMatrix();

    //���̺�
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, -0.275);
    glVertex2f(-0.8, -0.5);
    glVertex2f(-0.2, -0.5);
    glVertex2f(-0.2, -0.275);
    glEnd();
    glPopMatrix();

    //���̺� ���� �� (��)
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.82, -0.28);
    glVertex2f(-0.82, -0.27);
    glVertex2f(-0.18, -0.27);
    glVertex2f(-0.18, -0.28);
    glEnd();
    glPopMatrix();

    //���̺� ���� ������ (�Ʒ�)
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.815, -0.28);
    glVertex2f(-0.815, -0.29);
    glVertex2f(-0.185, -0.29);
    glVertex2f(-0.185, -0.28);
    glEnd();
    glPopMatrix();

    //���̺� �׵θ� (��)
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.79, -0.3);
    glVertex2f(-0.79, -0.49);
    glVertex2f(-0.78, -0.49);
    glVertex2f(-0.78, -0.3);
    glEnd();
    glPopMatrix();

    //���̺� �׵θ� (��)
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.22, -0.3);
    glVertex2f(-0.22, -0.49);
    glVertex2f(-0.21, -0.49);
    glVertex2f(-0.21, -0.3);
    glEnd();
    glPopMatrix();

    //���̺� �׵θ� (��)
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.79, -0.31);
    glVertex2f(-0.79, -0.3);
    glVertex2f(-0.21, -0.3);
    glVertex2f(-0.21, -0.31);
    glEnd();
    glPopMatrix();

    //���̺� �׵θ� (�Ʒ�)
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.79, -0.49);
    glVertex2f(-0.79, -0.48);
    glVertex2f(-0.21, -0.48);
    glVertex2f(-0.21, -0.49);
    glEnd();
    glPopMatrix();

    //���̺� �߰� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.505, -0.3);
    glVertex2f(-0.505, -0.48);
    glVertex2f(-0.485, -0.48);
    glVertex2f(-0.485, -0.3);
    glEnd();
    glPopMatrix();

    //���̺� ������ (��)
    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_QUADS);
    glVertex2f(-0.53, -0.375);
    glVertex2f(-0.53, -0.425);
    glVertex2f(-0.515, -0.425);
    glVertex2f(-0.515, -0.375);
    glEnd();
    glPopMatrix();

    //���̺� ������ (��)�Ʒ�����
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-0.53, -0.425);
    glVertex2f(-0.53, -0.435);
    glVertex2f(-0.515, -0.435);
    glVertex2f(-0.515, -0.425);
    glEnd();
    glPopMatrix();

    //���̺� ������ (��)������
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-0.53, -0.365);
    glVertex2f(-0.53, -0.375);
    glVertex2f(-0.515, -0.375);
    glVertex2f(-0.515, -0.365);
    glEnd();
    glPopMatrix();

    //���̺� ������ (��)
    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_QUADS);
    glVertex2f(-0.475, -0.375);
    glVertex2f(-0.475, -0.425);
    glVertex2f(-0.46, -0.425);
    glVertex2f(-0.46, -0.375);
    glEnd();
    glPopMatrix();

    //���̺� ������ (��)�Ʒ�����
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-0.475, -0.425);
    glVertex2f(-0.475, -0.435);
    glVertex2f(-0.46, -0.435);
    glVertex2f(-0.46, -0.425);
    glEnd();
    glPopMatrix();

    //���̺� ������ (��)������
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-0.475, -0.365);
    glVertex2f(-0.475, -0.375);
    glVertex2f(-0.46, -0.375);
    glVertex2f(-0.46, -0.365);
    glEnd();
    glPopMatrix();

    //���� â�� (�������)
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-1.5, 0.22);
    glVertex2f(-1.5, 0.48);
    glVertex2f(-0.2, 0.48);
    glVertex2f(-0.2, 0.22);
    glEnd();
    glPopMatrix();

    //���� â�� (�������)
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-1.5, 0.21);
    glVertex2f(-1.5, 0.48);
    glVertex2f(-0.2, 0.48);
    glVertex2f(-0.2, 0.21);
    glEnd();
    glPopMatrix();

    //���� â�� 1��
    glPushMatrix();
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-1.48, 0.23);
    glVertex2f(-1.48, 0.46);
    glVertex2f(-1.18, 0.46);
    glVertex2f(-1.18, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 1�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.48, 0.23);
    glVertex2f(-1.48, 0.46);
    glVertex2f(-1.47, 0.46);
    glVertex2f(-1.47, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 1�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.19, 0.23);
    glVertex2f(-1.19, 0.46);
    glVertex2f(-1.18, 0.46);
    glVertex2f(-1.18, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 1�� �׵θ� �Ʒ�
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.48, 0.23);
    glVertex2f(-1.48, 0.24);
    glVertex2f(-1.18, 0.24);
    glVertex2f(-1.18, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 1�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.48, 0.45);
    glVertex2f(-1.48, 0.46);
    glVertex2f(-1.18, 0.46);
    glVertex2f(-1.18, 0.45);
    glEnd();
    glPopMatrix();

    //���� â�� 2��
    glPushMatrix();
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-1.16, 0.23);
    glVertex2f(-1.16, 0.46);
    glVertex2f(-0.86, 0.46);
    glVertex2f(-0.86, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 2�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.16, 0.23);
    glVertex2f(-1.16, 0.46);
    glVertex2f(-1.15, 0.46);
    glVertex2f(-1.15, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 2�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85, 0.23);
    glVertex2f(-0.85, 0.46);
    glVertex2f(-0.86, 0.46);
    glVertex2f(-0.86, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 2�� �׵θ� �Ʒ�
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.16, 0.23);
    glVertex2f(-1.16, 0.24);
    glVertex2f(-0.86, 0.24);
    glVertex2f(-0.86, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 2�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.16, 0.45);
    glVertex2f(-1.16, 0.46);
    glVertex2f(-0.86, 0.46);
    glVertex2f(-0.86, 0.45);
    glEnd();
    glPopMatrix();

    //���� â�� 3��
    glPushMatrix();
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-0.84, 0.23);
    glVertex2f(-0.84, 0.46);
    glVertex2f(-0.54, 0.46);
    glVertex2f(-0.54, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 3�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.84, 0.23);
    glVertex2f(-0.84, 0.46);
    glVertex2f(-0.83, 0.46);
    glVertex2f(-0.83, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 3�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.53, 0.23);
    glVertex2f(-0.53, 0.46);
    glVertex2f(-0.54, 0.46);
    glVertex2f(-0.54, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 3�� �׵θ� �Ʒ�
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.84, 0.23);
    glVertex2f(-0.84, 0.24);
    glVertex2f(-0.54, 0.24);
    glVertex2f(-0.54, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 3�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.84, 0.45);
    glVertex2f(-0.84, 0.46);
    glVertex2f(-0.54, 0.46);
    glVertex2f(-0.54, 0.45);
    glEnd();
    glPopMatrix();

    //���� â�� 4��
    glPushMatrix();
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-0.52, 0.23);
    glVertex2f(-0.52, 0.46);
    glVertex2f(-0.22, 0.46);
    glVertex2f(-0.22, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 4�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.52, 0.23);
    glVertex2f(-0.52, 0.46);
    glVertex2f(-0.51, 0.46);
    glVertex2f(-0.51, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 4�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.21, 0.23);
    glVertex2f(-0.21, 0.46);
    glVertex2f(-0.22, 0.46);
    glVertex2f(-0.22, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 4�� �׵θ� �Ʒ�
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.52, 0.23);
    glVertex2f(-0.52, 0.24);
    glVertex2f(-0.22, 0.24);
    glVertex2f(-0.22, 0.23);
    glEnd();
    glPopMatrix();

    //â�� 4�� �׵θ� ��
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.52, 0.45);
    glVertex2f(-0.52, 0.46);
    glVertex2f(-0.22, 0.46);
    glVertex2f(-0.22, 0.45);
    glEnd();
    glPopMatrix();
}

void miketable() {
    //��ǥ��
    glPushMatrix();
    glColor3f(0.4, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.55);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.55);
    glEnd();
    glPopMatrix();

    //��ǥ�� ���κ�
    glPushMatrix();
    glColor3f(0.4, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.4, -0.25);
    glVertex2f(0.55, -0.25);
    glVertex2f(0.55, -0.3);
    glEnd();
    glPopMatrix();

    //��ǥ�� ���κ�(����)
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.25);
    glVertex2f(0.6, -0.275);
    glVertex2f(0.6, -0.3);
    glEnd();
    glPopMatrix();

    //��ǥ��(����)
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.55, -0.55);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.6, -0.55);
    glEnd();
    glPopMatrix();

    //��ǥ�� (����) 1
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.42, -0.55);
    glVertex2f(0.42, -0.29);
    glVertex2f(0.43, -0.29);
    glVertex2f(0.43, -0.55);
    glEnd();
    glPopMatrix();

    //��ǥ�� (����) 2
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.52, -0.55);
    glVertex2f(0.52, -0.29);
    glVertex2f(0.53, -0.29);
    glVertex2f(0.53, -0.55);
    glEnd();
    glPopMatrix();

    //��ǥ�� (����) 3
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.29);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.29);
    glEnd();
    glPopMatrix();

    //��ǥ�� (����) 4
    glPushMatrix();
    glColor3f(0.3, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.4, -0.31);
    glVertex2f(0.6, -0.31);
    glVertex2f(0.6, -0.3);
    glEnd();
    glPopMatrix();

    //��ǥ�� ��Ʈ��
    glPushMatrix();
    glColor3f(0.66, 0.66, 0.66);
    glBegin(GL_POLYGON);
    glVertex2f(0.43, -0.25);
    glVertex2f(0.41, -0.2);
    glVertex2f(0.51, -0.2);
    glVertex2f(0.53, -0.25);
    glEnd();
    glPopMatrix();

    //��ǥ�� ��Ʈ��(����)
    glPushMatrix();
    glColor3f(0.77, 0.77, 0.77);
    glBegin(GL_POLYGON);
    glVertex2f(0.53, -0.25);
    glVertex2f(0.51, -0.2);
    glVertex2f(0.52, -0.2);
    glVertex2f(0.54, -0.25);
    glEnd();
    glPopMatrix();

    //��ǥ�� ����ũ
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.54, -0.25);
    glVertex2f(0.54, -0.22);
    glVertex2f(0.55, -0.22);
    glVertex2f(0.55, -0.25);
    glEnd();
    glPopMatrix();

    //��ǥ�� ����ũ
    glPushMatrix();
    glTranslatef(0.695, 0.36, 0);
    glRotatef(280, 0, 0, 1);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.54, -0.25);
    glVertex2f(0.54, -0.22);
    glVertex2f(0.55, -0.22);
    glVertex2f(0.55, -0.25);
    glEnd();
    glPopMatrix();

    //��ǥ�� ����ũ
    glPushMatrix();
    glTranslatef(0.57, -0.215, 0);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.3, 0.3, 0.1);
    glutSolidSphere(0.03, 50, 10);
    glEnd();
    glPopMatrix();
}

void classroom() {
    //�ٴ�
    glColor3f(0.65, 0.5, 0.39);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.67);
    glVertex2f(-0.7, -0.5);
    glVertex2f(1.3, -0.5);
    glVertex2f(1.3, -0.67);
    glEnd();

    //�ٴ� - �߰� �׵θ�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.5);
    glVertex2f(-0.7, -0.51);
    glVertex2f(1.3, -0.51);
    glVertex2f(1.3, -0.5);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.62);
    glVertex2f(-0.7, -0.63);
    glVertex2f(1.3, -0.63);
    glVertex2f(1, -0.62);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.57);
    glVertex2f(-0.7, -0.56);
    glVertex2f(0.7, -0.56);
    glVertex2f(0.7, -0.57);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.56);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.51, -0.5);
    glVertex2f(-0.51, -0.56);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0, -0.56);
    glVertex2f(0, -0.5);
    glVertex2f(0.01, -0.5);
    glVertex2f(0.01, -0.56);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.56);
    glVertex2f(0.4, -0.5);
    glVertex2f(0.41, -0.5);
    glVertex2f(0.41, -0.56);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.56);
    glVertex2f(0.4, -0.5);
    glVertex2f(0.41, -0.5);
    glVertex2f(0.41, -0.56);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.6, -0.62);
    glVertex2f(0.6, -0.56);
    glVertex2f(0.61, -0.56);
    glVertex2f(0.61, -0.62);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.3, -0.62);
    glVertex2f(0.3, -0.56);
    glVertex2f(0.31, -0.56);
    glVertex2f(0.31, -0.62);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, -0.62);
    glVertex2f(-0.3, -0.56);
    glVertex2f(-0.31, -0.56);
    glVertex2f(-0.31, -0.62);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.65, -0.62);
    glVertex2f(-0.65, -0.56);
    glVertex2f(-0.66, -0.56);
    glVertex2f(-0.66, -0.62);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.44, -0.63);
    glVertex2f(-0.44, -0.67);
    glVertex2f(-0.45, -0.67);
    glVertex2f(-0.45, -0.63);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, -0.63);
    glVertex2f(0.15, -0.67);
    glVertex2f(0.16, -0.67);
    glVertex2f(0.16, -0.63);
    glEnd();

    //�ٴ� ���̵�
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.47, -0.63);
    glVertex2f(0.47, -0.67);
    glVertex2f(0.48, -0.67);
    glVertex2f(0.48, -0.63);
    glEnd();

    //�߰� (ĥ��)
    glColor3f(0, 0.3, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.3);
    glVertex2f(0.5, 0.3);
    glVertex2f(0.5, -0.2);
    glEnd();

    //�߰� (ĥ��) ����
    glColor3f(0, 0.5, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.3);
    glVertex2f(-0.25, 0.3);
    glVertex2f(-0.25, -0.2);
    glEnd();

    //�߰� (ĥ��) ���� �޸� 1
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.47, -0.1);
    glVertex2f(-0.47, 0);
    glVertex2f(-0.3, 0);
    glVertex2f(-0.3, -0.1);
    glEnd();

    //�߰� (ĥ��) ���� �޸� 2
    glColor3f(0.9, 0.9, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.1);
    glVertex2f(-0.3, 0.03);
    glVertex2f(-0.37, 0.03);
    glVertex2f(-0.37, 0.1);
    glEnd();

    //�߰� (ĥ��) ������
    glColor3f(0, 0.5, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.29, -0.2);
    glVertex2f(0.29, 0.3);
    glVertex2f(0.5, 0.3);
    glVertex2f(0.5, -0.2);
    glEnd();

    //�߰� (ĥ��) ������ �޸� 1
    glColor3f(0.9, 0.9, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.33, 0.1);
    glVertex2f(0.33, 0.2);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.4, 0.1);
    glEnd();

    //�߰� (ĥ��) ������ �޸� 2
    glColor3f(0.9, 0.9, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.36, -0.1);
    glVertex2f(0.36, -0.02);
    glVertex2f(0.43, -0.02);
    glVertex2f(0.43, -0.1);
    glEnd();

    //�߰� �׵θ� (��)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.3);
    glVertex2f(-0.52, 0.3);
    glVertex2f(-0.52, -0.2);
    glEnd();

    //�߰� �׵θ� (��)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(0.48, -0.2);
    glVertex2f(0.48, 0.3);
    glVertex2f(0.5, 0.3);
    glVertex2f(0.5, -0.2);
    glEnd();

    //�߰� �׵θ� (������ ����)
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.5, -0.22);
    glVertex2f(0.5, 0.32);
    glVertex2f(0.52, 0.32);
    glVertex2f(0.52, -0.22);
    glEnd();

    //�߰� �׵θ� (��)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52, 0.3);
    glVertex2f(-0.52, 0.32);
    glVertex2f(0.5, 0.32);
    glVertex2f(0.5, 0.3);
    glEnd();

    //�߰� �׵θ� (�Ʒ�)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52, -0.22);
    glVertex2f(-0.52, -0.2);
    glVertex2f(0.5, -0.2);
    glVertex2f(0.5, -0.22);
    glEnd();

    //���� - �߰� �׵θ� (ĥ�� ��)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, -0.2);
    glVertex2f(-0.25, 0.3);
    glVertex2f(-0.27, 0.3);
    glVertex2f(-0.27, -0.2);
    glEnd();

    //���� - �߰� �׵θ� ����(ĥ�� ��)
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, -0.2);
    glVertex2f(-0.25, 0.3);
    glVertex2f(-0.23, 0.3);
    glVertex2f(-0.23, -0.2);
    glEnd();

    //�߰� - ������ �׵θ� (ĥ�� ��)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(0.25, -0.2);
    glVertex2f(0.25, 0.3);
    glVertex2f(0.27, 0.3);
    glVertex2f(0.27, -0.2);
    glEnd();

    //�߰� - ������ �׵θ� ����(ĥ�� ��)
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.27, -0.2);
    glVertex2f(0.27, 0.3);
    glVertex2f(0.29, 0.3);
    glVertex2f(0.29, -0.2);
    glEnd();

    //ĥ�� �� ����
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52, -0.22);
    glVertex2f(-0.52, -0.21);
    glVertex2f(0.52, -0.21);
    glVertex2f(0.52, -0.22);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.4, 0.05, 0);
    miketable();
    glEnd();
    glPopMatrix();

    //Ƽ��
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_POLYGON);
    glVertex2f(-0.65, 0.1);
    glVertex2f(-0.65, 0.4);
    glVertex2f(-0.15, 0.4);
    glVertex2f(-0.15, 0.1);
    glEnd();

    //Ƽ�� �� ����
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.41, 0.4);
    glVertex2f(-0.41, 0.5);
    glVertex2f(-0.38, 0.5);
    glVertex2f(-0.38, 0.4);
    glEnd();

    //Ƽ�� �� ȭ��
    glColor3f(0, 0.1, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-0.625, 0.125);
    glVertex2f(-0.625, 0.3725);
    glVertex2f(-0.1725, 0.3725);
    glVertex2f(-0.1725, 0.125);
    glEnd();

    //Ƽ�� �� ȭ��
    glColor3f(0, 0.2, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(-0.615, 0.135);
    glVertex2f(-0.615, 0.3625);
    glVertex2f(-0.475, 0.3625);
    glVertex2f(-0.275, 0.135);
    glEnd();

}

// ��濡 ģ��
void backcharater() {

    //����
    glTranslatef(-0.5, -0.25, 0);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(1, 1.7, 0.1);
    glutSolidSphere(0.1, 20, 10);
    glEnd();

    //������Ÿ�� 1
    glPushMatrix();
    glTranslatef(-0.12, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, 0.02);
    glVertex2f(0.14, 0.02);
    glEnd();
    glPopMatrix();

    //������Ÿ�� 2
    glPushMatrix();
    glTranslatef(-0.12, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //������Ÿ�� 3
    glPushMatrix();
    glTranslatef(-0.12, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.12, -0.06);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //����
    glPushMatrix();
    glTranslatef(-0.175, -0.01, 0.0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0.12, 0);
    glVertex2f(0.12, 0.02);
    glVertex2f(0.16, 0.02);
    glVertex2f(0.16, 0);
    glEnd();
    glPopMatrix();

    //���� �� �̸�
    glPushMatrix();
    glTranslatef(-0.16, -0.0005, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(0.12, 0);
    glVertex2f(0.12, 0.01);
    glVertex2f(0.14, 0.01);
    glVertex2f(0.14, 0);
    glEnd();
    glPopMatrix();

    //�Ӹ�
    glPushMatrix();
    glTranslatef(0, 0.1, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();


    //�� (��� ���)
    glPushMatrix();
    glTranslatef(-0.03, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();

    //�� (��� ���)
    glPushMatrix();
    glTranslatef(0.02, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();


    //���� (����)
    glPushMatrix();
    glTranslatef(-0.03, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //���� (����)
    glPushMatrix();
    glTranslatef(0.02, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //�� (����)
    glPushMatrix();
    glTranslatef(0, 0.05, 0.0);
    glColor3f(0.8, 0.1, 0.1);
    glutSolidSphere(0.02, 30, 20);
    glEnd();
    glPopMatrix();
}

void backleftarm() {

    //���� �� �Ʒ��κ�
    glPushMatrix();
    glTranslatef(-0.6, -0.22, 0.0);
    glRotatef(330, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.3, 0.6, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();
}

void backrightarm() {
    //�������� �Ʒ��κ�
    glPushMatrix();
    glTranslatef(-0.42, -0.22, 0.0);
    glRotatef(30, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.3, 0.6, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();
}

void backleftleg() {
    //���� �ٸ� ���κ�
    glPushMatrix();
    glTranslatef(-0.55, -0.45, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.3, 1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� �Ź�
    glPushMatrix();
    glTranslatef(-0.55, -0.55, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.25, 0.1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();
}

void backrightleg() {
    //������ �ٸ� ���κ�
    glPushMatrix();
    glTranslatef(-0.45, -0.45, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.3, 1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //������ �Ź�
    glPushMatrix();
    glTranslatef(-0.45, -0.55, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.25, 0.1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

}

void book() {
    glPushMatrix();
    glTranslatef(-0.685, -0.2, 0.0);
    glColor3f(0.8, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.12, 0);
    glVertex2f(0.12, 0.1);
    glVertex2f(0.18, 0.08);
    glVertex2f(0.18, -0.02);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.625, -0.2, 0.0);
    glColor3f(0.65, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.12, -0.02);
    glVertex2f(0.12, 0.08);
    glVertex2f(0.18, 0.1);
    glVertex2f(0.18, 0);
    glEnd();
    glPopMatrix();
}

void friends() {
    glPushMatrix();
    backcharater();
    glPopMatrix();

    glPushMatrix();
    backleftarm();
    glPopMatrix();

    glPushMatrix();
    backrightarm();
    glPopMatrix();

    glPushMatrix();
    backleftleg();
    glPopMatrix();

    glPushMatrix();
    backrightleg();
    glPopMatrix();

    glPushMatrix();
    book();
    glPopMatrix();

    glEnd();
}

void backGround() {


    glTranslatef(6, 0, 0);
    glPushMatrix();//�����޺κ�
    glColor3f(0.9, 0.9, 0.5); // ȸ��
    glBegin(GL_POLYGON);
    glVertex2f(5.0, 0.67);
    glVertex2f(5.0, -0.67);
    glVertex2f(10.0, -0.67);
    glVertex2f(10.0, 0.67);
    glEnd();
    glPopMatrix();

    //�б� �ٴ�
    glColor3f(0.75, 0.65, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5);
    glVertex2f(-1.0, -0.67);
    glVertex2f(-7.0, -0.67);
    glVertex2f(-7.0, -0.5);

    //�б�
    //�ٴ� - �߰� ȭ�� �׵θ�
    glPushMatrix();
    glColor3f(0.5, 0.3, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.51);
    glVertex2f(-1.0, -0.5);
    glVertex2f(-7.0, -0.5);
    glVertex2f(-7.0, -0.51);  // ���� �ϴ� (�ظ�)
    glPopMatrix();

    //�б� �߰�
    glPushMatrix(); //�߰�
    glColor3f(0.85, 0.85, 0.85); //
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5); // ���� �ϴ�
    glVertex2f(-1.0, 0.5);
    glVertex2f(-7.0, 0.5);
    glVertex2f(-7.0, -0.5);  // ���� �ϴ� (�ظ�)
    glPopMatrix();

    //�б�
    //�߰� - �� ȭ�� �׵θ�
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.1); // ȸ��
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, 0.49); // ���� �ϴ�
    glVertex2f(-1.0, 0.5);
    glVertex2f(-7.0, 0.5);
    glVertex2f(-7.0, 0.49);  // ���� �ϴ� (�ظ�)
    glPopMatrix();

    //�б� ��
    glPushMatrix(); // ��
    glColor3f(0.4, 0.4, 0.4); //
    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.5); // ���� �ϴ�
    glVertex2f(-1.0, 0.67);
    glVertex2f(-7.0, 0.67);
    glVertex2f(-7.0, 0.5);  // ���� �ϴ� (�ظ�)
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-5, 0, 0);
    Door();
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, 0, 0);
    Door();
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.4, 0, 0);
    friends();
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-4.95, 0, 0);
    coffee1();
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.4, 0, 0);
    classroom();
    glEnd();
    glPopMatrix();

    //ȸ�� �ٴ�
    glColor3f(0.5, 0.55, 0.6); // ȸ��
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5); // ���� �ϴ�
    glVertex2f(-1.0, -0.67);
    glVertex2f(5.0, -0.67);
    glVertex2f(5.0, -0.5);  // ���� �ϴ� (�ظ�)

    //�ٴ� - �߰� ȭ�� �׵θ�
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3); // ȸ��
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.51); // ���� �ϴ�
    glVertex2f(-1.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, -0.51);  // ���� �ϴ� (�ظ�)
    glPopMatrix();

    glPushMatrix(); //�߰�
    glColor3f(0.7, 1, 0.6); //
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5); // ���� �ϴ�
    glVertex2f(-1.0, 0.5);
    glVertex2f(5.0, 0.5);
    glVertex2f(5.0, -0.5);  // ���� �ϴ� (�ظ�)
    glPopMatrix();

    //�߰� - �� ȭ�� �׵θ�
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1); // ȸ��
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, 0.49); // ���� �ϴ�
    glVertex2f(-1.0, 0.5);
    glVertex2f(5.0, 0.5);
    glVertex2f(5.0, 0.49);  // ���� �ϴ� (�ظ�)
    glPopMatrix();

    glPushMatrix(); // ��
    glColor3f(0.6, 0.75, 0.95); //
    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.5); // ���� �ϴ�
    glVertex2f(-1.0, 0.67);
    glVertex2f(5.0, 0.67);
    glVertex2f(5.0, 0.5);  // ���� �ϴ� (�ظ�)
    glPopMatrix();
    glEnd();

    //ȸ��
    glPushMatrix();//â��
    glTranslatef(0, 0, 0.0);
    window();
    glPopMatrix();

    glPushMatrix();//â��
    glTranslatef(1, 0, 0.0);
    window();
    glPopMatrix();

    glPushMatrix();//â��
    glTranslatef(2, 0, 0.0);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 0, 0);
    computer();
    chair();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7, 0, 0);
    computer();
    chair();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.5, 0, 0);
    coffee();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.7, 0, 0.0);
    meetingroom();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.7, 0, 0.0);
    elevator();
    elevatorClose();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.5, 0, 0.0);
    elevatorIn();
    elevatorOpen();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.5, 0, 0);
    Entrance();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, 0, 0);
    Entrance();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7, 0, 0);
    glRotatef(180, 0, 1, 0);
    Entrance();
    glPopMatrix();

    glPopMatrix();
}

void charater1() {
    //����
    glTranslatef(-0.5, -0.25, 0);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(1, 1.7, 0.1);
    glutSolidSphere(0.1, 20, 10);
    glEnd();

    //�����Ÿ�� 1
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, 0.02);
    glVertex2f(0.14, 0.02);
    glEnd();
    glPopMatrix();

    //�����Ÿ�� 2
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //�����Ÿ�� 3
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.12, -0.06);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //�Ӹ�
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.1, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();


    //�� (��� ���)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();

    //�� (��� ���)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();


    //���� (����)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //���� (����)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();


    //�Ӹ�ī��
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //�Ӹ�ī��
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //�Ӹ�ī��
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.0305, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.035, 0);
    glEnd();
    glPopMatrix();

    //�� (����)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.06, 0.05, 0.0);
    glColor3f(0.8, 0.1, 0.1);
    glutSolidSphere(0.02, 30, 20);
    glEnd();
    glPopMatrix();

    //�� (��)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.055, 0.05, 0.0);
    glColor3f(0.8, 0.3, 0);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();
}

void leftarm1() {
    //���� �� ���κ�
    glPushMatrix();
    glTranslatef(-0.05, 0, 0.0);
    glRotatef(330, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.25, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� �� �Ʒ��κ�
    glPushMatrix();
    glTranslatef(-0.055, -0.05, 0.0);
    glRotatef(40, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.4, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //�޼�
    glPushMatrix();
    glTranslatef(-0.035, -0.075, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.165, 0.165, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();
}

void rightarm1() {

    //�������� ���κ�
    glPushMatrix();
    glTranslatef(0.1, -0.01, 0.0);
    glRotatef(30, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.25, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //�������� �Ʒ��κ�
    glPushMatrix();
    glTranslatef(0.14, -0.05, 0.0);
    glRotatef(70, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //������
    glPushMatrix();
    glTranslatef(0.185, -0.065, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.165, 0.165, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();
}

void leftleg1() {
    //���� �ٸ� ���κ�
    glPushMatrix();
    glTranslatef(-0.02, -0.1, 0.0);
    glRotatef(25, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.3, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� �ٸ� �Ʒ��κ�
    glPushMatrix();
    glTranslatef(-0.02, -0.15, 0.0);
    glRotatef(150, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.2, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� �Ź�
    glPushMatrix();
    glTranslatef(-0.03, -0.19, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.25, 0.1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();
}

void rightleg1() {
    //������ �ٸ� ���κ�
    glPushMatrix();
    glTranslatef(0.05, -0.1, 0.0);
    glRotatef(30, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.3, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //������ �ٸ� ���κ�
    glPushMatrix();
    glTranslatef(0.04, -0.15, 0.0);
    glRotatef(120, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.15, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //������ �Ź�
    glPushMatrix();
    glTranslatef(0.02, -0.175, 0.0);
    glRotatef(350, 0, 0, 1);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.25, 0.1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

}

// ĳ����
void charater() {

    //����
    glTranslatef(-0.5, -0.25, 0);
    glColor3f(0, 0, 0.5);
    glScalef(1, 1.7, 0.1);
    glutSolidSphere(0.1, 20, 10);
    glEnd();

    //�����Ÿ�� 1
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, 0.02);
    glVertex2f(0.14, 0.02);
    glEnd();
    glPopMatrix();

    //�����Ÿ�� 2
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //�����Ÿ�� 3
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.12, -0.06);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //�Ӹ�
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.1, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();


    //�� (��� ���)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();

    //�� (��� ���)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();


    //���� (����)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //���� (����)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();


    //�Ӹ�ī��
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //�Ӹ�ī��
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //�Ӹ�ī��
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.0305, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.035, 0);
    glEnd();
    glPopMatrix();

    //�� (����)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.06, 0.05, 0.0);
    glColor3f(0.8, 0.1, 0.1);
    glutSolidSphere(0.02, 30, 20);
    glEnd();
    glPopMatrix();

    //�� (��)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.055, 0.05, 0.0);
    glColor3f(0.8, 0.3, 0);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();
}

void leftarm() {
    //���� �� ���κ�
    glPushMatrix();
    glTranslatef(-0.05, 0, 0.0);
    glRotatef(330, 0, 0, 1);
    glColor3f(0, 0, 0.7);
    glScalef(0.25, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� �� �Ʒ��κ�
    glPushMatrix();
    glTranslatef(-0.055, -0.05, 0.0);
    glRotatef(40, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.4, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //�޼�
    glPushMatrix();
    glTranslatef(-0.035, -0.075, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.165, 0.165, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();
}

void rightarm() {

    //�������� ���κ�
    glPushMatrix();
    glTranslatef(0.1, -0.01, 0.0);
    glRotatef(30, 0, 0, 1);
    glColor3f(0, 0, 0.7);
    glScalef(0.25, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //�������� �Ʒ��κ�
    glPushMatrix();
    glTranslatef(0.14, -0.05, 0.0);
    glRotatef(70, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //������
    glPushMatrix();
    glTranslatef(0.185, -0.065, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.165, 0.165, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();
}

void leftleg() {
    //���� �ٸ� ���κ�
    glPushMatrix();
    glTranslatef(-0.02, -0.1, 0.0);
    glRotatef(25, 0, 0, 1);
    glColor3f(0, 0, 0.5);
    glScalef(0.3, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� �ٸ� �Ʒ��κ�
    glPushMatrix();
    glTranslatef(-0.02, -0.15, 0.0);
    glRotatef(150, 0, 0, 1);
    glColor3f(0, 0, 0.5);
    glScalef(0.2, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //���� �Ź�
    glPushMatrix();
    glTranslatef(-0.03, -0.19, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.25, 0.1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();
}

void rightleg() {
    //������ �ٸ� ���κ�
    glPushMatrix();
    glTranslatef(0.05, -0.1, 0.0);
    glRotatef(30, 0, 0, 1);
    glColor3f(0, 0, 0.5);
    glScalef(0.3, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //������ �ٸ� ���κ�
    glPushMatrix();
    glTranslatef(0.04, -0.15, 0.0);
    glRotatef(120, 0, 0, 1);
    glColor3f(0, 0, 0.5);
    glScalef(0.15, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //������ �Ź�
    glPushMatrix();
    glTranslatef(0.02, -0.175, 0.0);
    glRotatef(350, 0, 0, 1);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.25, 0.1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

}

void charaterMain2() {

    glTranslatef(0, 0, 0);
    charater1();
    glPushMatrix();
    glRotatef(-Move, 0, 0, 1);
    leftleg1();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    rightleg1();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-Move, 0, 0, 1);
    leftarm1();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Move - 5, 0, 0, 1);
    rightarm1();
    glPopMatrix();
}

void charaterMain() {

    glTranslatef(0, 0, 0);
    charater();
    glPushMatrix();
    glRotatef(-Move, 0, 0, 1);
    leftleg();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    rightleg();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-Move, 0, 0, 1);
    leftarm();
    glPopMatrix();

    glPushMatrix();
    glRotatef(Move - 5, 0, 0, 1);
    rightarm();
    glPopMatrix();
}

void Heart() {
    //��Ʈ ���
    glPushMatrix();
    glScalef(1 + jp * 0.0005, 1 + jp * 0.0005, 0);
    glPushMatrix();
    glTranslatef(-1.02, 0.84, 0);
    glColor3f(0.8, 0, 0);
    glRotatef(35, 0, 0, 1);
    glScalef(0.6, 1, 0);
    glutSolidSphere(0.1, 20, 10);
    glEnd();
    glPopMatrix();

    //��Ʈ ���
    glPushMatrix();
    glTranslatef(-0.962, 0.84, 0);
    glColor3f(0.8, 0, 0);
    glRotatef(325, 0, 0, 1);
    glScalef(0.6, 1, 0);
    glutSolidSphere(0.1, 20, 10);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void Heartbackgound() {

    glTranslatef(0.2, 0, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, 0.74);
    glVertex2f(-0.8, 0.94);
    glVertex2f(0.7, 0.94);
    glVertex2f(0.7, 0.74);
    glEnd();
    glPushMatrix();
    glColor3f(0.8, 0, 0);

    if (redX > -1.48) {
        redX = -Delta * 0.00027;
    }

    else if (redX >= -1.48) {
        glColor3f(0.8, 0.8, 0.8);
    }

    glBegin(GL_QUADS);
    glVertex2f(-0.79, 0.75);
    glVertex2f(-0.79, 0.93);
    glVertex2f(redX + 0.69, 0.93);
    glVertex2f(redX + 0.69, 0.75);
    glEnd();
    glPopMatrix();
    if (h_Delta < 1605) {
        Heart();
    }
    else {
        glTranslatef(-0.2, 0, 0);
        Bone();
    }

}

//------ 22125027 �ְ��� ---------------------------------------------------------

void drawHalfSphere() {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0);

    int numSegments = 1100;
    for (int i = 0; i <= numSegments; i++) {
        float angle = 3.14 * i / numSegments;
        float x = cos(angle);
        float y = sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void bloks() {
    glPushMatrix();//A���
    glTranslatef(0, 0.3, 0.0);
    glColor3f(0.6, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, 0.15);
    glVertex2f(0.15, -0.15);
    glVertex2f(-0.15, -0.15);
    glVertex2f(-0.15, 0.15);
    glEnd();
    glColor3f(0.6, 0.4, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.13, 0.13);
    glVertex2f(0.13, -0.13);
    glVertex2f(-0.13, -0.13);
    glVertex2f(-0.13, 0.13);
    glEnd();
    glBegin(GL_LINE_LOOP);//A
    glColor3f(0.6, 0, 0);
    glVertex2f(-0.07, -0.1);
    glVertex2f(-0.07, 0.1);
    glVertex2f(0.07, 0.1);
    glVertex2f(0.07, -0.1);
    glVertex2f(0.02, -0.1);
    glVertex2f(0.02, 0);
    glVertex2f(-0.02, 0);
    glVertex2f(-0.02, -0.1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.6, 0, 0);
    glVertex2f(-0.02, 0.06);
    glVertex2f(-0.02, 0.03);
    glVertex2f(0.02, 0.03);
    glVertex2f(0.02, 0.06);
    glEnd();
    glPopMatrix();

    glPushMatrix();//F���
    glTranslatef(0.15, 0, 0.0);
    glColor3f(0, 0.6, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, 0.15);
    glVertex2f(0.15, -0.15);
    glVertex2f(-0.15, -0.15);
    glVertex2f(-0.15, 0.15);
    glEnd();
    glColor3f(0.6, 0.4, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.13, 0.13);
    glVertex2f(0.13, -0.13);
    glVertex2f(-0.13, -0.13);
    glVertex2f(-0.13, 0.13);
    glEnd();
    glScalef(0.7, 0.7, 0);
    glBegin(GL_LINE_LOOP);//F
    glColor3f(0, 0.6, 0);
    glVertex2f(-0.07, -0.15);
    glVertex2f(-0.07, 0.15);
    glVertex2f(0.1, 0.15);
    glVertex2f(0.1, 0.08);
    glVertex2f(-0.02, 0.08);
    glVertex2f(-0.02, 0);
    glVertex2f(0.1, 0);
    glVertex2f(0.1, -0.05);
    glVertex2f(-0.02, -0.05);
    glVertex2f(-0.02, -0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();//E���
    glTranslatef(-0.15, 0, 0.0);
    glColor3f(0.8, 0.8, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, 0.15);
    glVertex2f(0.15, -0.15);
    glVertex2f(-0.15, -0.15);
    glVertex2f(-0.15, 0.15);
    glEnd();
    glColor3f(0.6, 0.4, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.13, 0.13);
    glVertex2f(0.13, -0.13);
    glVertex2f(-0.13, -0.13);
    glVertex2f(-0.13, 0.13);
    glEnd();
    glScalef(0.7, 0.7, 0);
    glBegin(GL_LINE_LOOP);//E
    glColor3f(0.8, 0.8, 0);
    glVertex2f(-0.02, -0.03);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.1, 0.03);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.02, 0.09);
    glVertex2f(0.1, 0.09);
    glVertex2f(0.1, 0.15);
    glVertex2f(-0.07, 0.15);
    glVertex2f(-0.07, -0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(0.1, -0.09);
    glVertex2f(-0.02, -0.09);
    glEnd();
    glPopMatrix();
}

void car() {
    //��ü
    glColor3f(0.2, 0.2, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0.2, 0);
    glVertex2f(0.2, 0.13);
    glVertex2f(0.1, 0.13);
    glVertex2f(0.1, 0.2);
    glVertex2f(-0.1, 0.2);
    glVertex2f(-0.1, 0.13);
    glVertex2f(-0.2, 0.13);
    glVertex2f(-0.2, 0);
    glEnd();
    //â��
    glColor3f(0, 0, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.13);
    glVertex2f(0.01, 0.18);
    glVertex2f(0.08, 0.18);
    glVertex2f(0.08, 0.13);
    glEnd();
    //â��
    glColor3f(0, 0, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.01, 0.13);
    glVertex2f(-0.01, 0.18);
    glVertex2f(-0.08, 0.18);
    glVertex2f(-0.08, 0.13);
    glEnd();
    //����Ʈ
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, 0.1);
    glVertex2f(0.15, 0.06);
    glVertex2f(0.18, 0.06);
    glVertex2f(0.18, 0.1);
    glEnd();
    //����1
    glPushMatrix();
    glTranslatef(-0.12, 0.0, 0.0);
    glRotatef(-angle, 0, 0, 1);
    glColor3f(0, 0, 0);
    glutSolidSphere(0.04, 20, 10);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(0.03, 0.01);
    glVertex2f(0.03, -0.01);
    glVertex2f(-0.03, -0.01);
    glVertex2f(-0.03, 0.01);
    glEnd();
    glPopMatrix();
    //����12
    glPushMatrix();
    glTranslatef(0.12, 0.0, 0.0);
    glRotatef(-angle, 0, 0, 1);
    glColor3f(0, 0, 0);
    glutSolidSphere(0.04, 20, 10);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(0.03, 0.01);
    glVertex2f(0.03, -0.01);
    glVertex2f(-0.03, -0.01);
    glVertex2f(-0.03, 0.01);
    glEnd();
    glPopMatrix();
}

void robot() {
    //����
    glColor3f(0.2, 0.5, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.2, 0.15);
    glVertex2f(0.2, -0.15);
    glVertex2f(-0.2, -0.15);
    glVertex2f(-0.2, 0.15);
    glEnd();

    glColor3f(0, 0.8, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, 0.05);
    glVertex2f(-0.17, 0.05);
    glVertex2f(-0.17, 0.1);
    glEnd();

    glColor3f(0, 0.8, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.02);
    glVertex2f(0.1, 0.03);
    glVertex2f(-0.17, 0.03);
    glVertex2f(-0.17, -0.02);
    glEnd();

    glColor3f(0.8, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, -0.02);
    glVertex2f(0.12, 0.03);
    glVertex2f(0.17, 0.03);
    glVertex2f(0.17, -0.02);
    glEnd();

    glColor3f(0.8, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0.1);
    glVertex2f(0.12, 0.05);
    glVertex2f(0.17, 0.05);
    glVertex2f(0.17, 0.1);
    glEnd();

    glPushMatrix();
    glTranslatef(0.07, -0.08, 0.0);
    glColor3f(0, 0.6, 0.6);
    glutSolidSphere(0.04, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1, -0.08, 0.0);
    glColor3f(0, 0.6, 0.6);
    glutSolidSphere(0.04, 20, 10);
    glPopMatrix();
    //����
    glPushMatrix();
    glTranslatef(-0.18, 0.13, 0.0);
    glRotatef(70 - sww * 0.6, 0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.55, 0.25);
    glVertex2f(0.00, 0.02);
    glVertex2f(0.0, -0.02);
    glVertex2f(-0.2, -0.02);
    glVertex2f(-0.2, 0.02);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.5, 0.2);
    glVertex2f(-0.22, 0.03);
    glVertex2f(-0.22, -0.03);
    glVertex2f(-0.17, -0.03);
    glVertex2f(-0.17, 0.03);
    glEnd();
    glPopMatrix();

    //������
    glPushMatrix();
    glTranslatef(0.18, 0.13, 0.0);
    glRotatef(70 - sww * 0.7, 0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.55, 0.25);
    glVertex2f(0.00, 0.02);
    glVertex2f(0.0, -0.02);
    glVertex2f(0.2, -0.02);
    glVertex2f(0.2, 0.02);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.5, 0.2);
    glVertex2f(0.22, 0.03);
    glVertex2f(0.22, -0.03);
    glVertex2f(0.17, -0.03);
    glVertex2f(0.17, 0.03);
    glEnd();
    glPopMatrix();

    //������
    glPushMatrix();
    glTranslatef(0.1, -0.15, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.55, 0.25);
    glVertex2f(0.03, 0.0);
    glVertex2f(0.03, -0.1);
    glVertex2f(-0.03, -0.1);
    glVertex2f(-0.03, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.5, 0.2);
    glVertex2f(0.04, -0.1);
    glVertex2f(0.04, -0.14);
    glVertex2f(-0.04, -0.14);
    glVertex2f(-0.04, -0.1);
    glEnd();
    glPopMatrix();
    //������
    glPushMatrix();
    glTranslatef(-0.1, -0.15, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.55, 0.25);
    glVertex2f(0.03, 0.0);
    glVertex2f(0.03, -0.1);
    glVertex2f(-0.03, -0.1);
    glVertex2f(-0.03, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.5, 0.2);
    glVertex2f(0.04, -0.1);
    glVertex2f(0.04, -0.14);
    glVertex2f(-0.04, -0.14);
    glVertex2f(-0.04, -0.1);
    glEnd();
    glPopMatrix();
    //��
    glPushMatrix();
    glTranslatef(0, 0.15, 0.0);
    glRotatef(20 - sww * 0.4, 0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.55, 0.25);
    glVertex2f(0.05, 0.02);
    glVertex2f(0.05, -0.02);
    glVertex2f(-0.05, -0.02);
    glVertex2f(-0.05, 0.02);
    glEnd();
    //�Ӹ�
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.5, 0.2);
    glVertex2f(0.15, 0.02);
    glVertex2f(0.15, 0.15);
    glVertex2f(-0.15, 0.15);
    glVertex2f(-0.15, 0.02);
    glEnd();
    //���׳�
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.6, 0.3);
    glVertex2f(0.01, 0.2);
    glVertex2f(0.01, 0.15);
    glVertex2f(-0.01, 0.15);
    glVertex2f(-0.01, 0.2);
    glEnd();
    //���׳� ���ٸ�
    glPushMatrix();
    glTranslatef(0, 0.2, 0.0);
    glColor3f(0, color, 0);
    glScaled(0.8, 0.5, 0);
    glutSolidSphere(0.03, 20, 10);
    glPopMatrix();
    //��
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0, 0);
    glVertex2f(0.03, 0.03);
    glVertex2f(0.03, 0.05);
    glVertex2f(-0.03, 0.05);
    glVertex2f(-0.03, 0.03);
    glEnd();
    //��
    glPushMatrix();
    glTranslatef(-0.07, 0.08, 0.0);
    glColor3f(color, 0, 0);
    glutSolidSphere(0.03, 20, 10);
    glPopMatrix();
    //��
    glPushMatrix();
    glTranslatef(0.07, 0.08, 0.0);
    glColor3f(color, 0, 0);
    glutSolidSphere(0.03, 20, 10);
    glPopMatrix();

    glPopMatrix();
}

void flower() {
    glColor3f(0.6, 0.3, 0.3);//ȭ��
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.1, 0.05);
    glEnd();

    glPushMatrix();//��
    glTranslatef(0, 0.125, 0.0);
    glColor3f(0, 1, 0);
    glScaled(0.5, 3, 0);
    glutSolidCube(0.05);
    glPopMatrix();

    glPushMatrix();//��
    glTranslatef(0, 0.2, 0.0);
    glPushMatrix();//�߽�
    glColor3f(1, 1, 0);
    glutSolidCube(0.05);
    glPopMatrix();//�߽�


    glRotatef(angle, 0, 0, 1);
    glPushMatrix();//��1
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//��1

    glPushMatrix();//��2
    glRotatef(90, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//��2

    glPushMatrix();//��3
    glRotatef(-90, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//��3

    glPushMatrix();//��4
    glRotatef(180, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//��4
    glPopMatrix();//��

}

void feeding_bottle() {
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.03, 0.06);
    glVertex2f(-0.03, 0.06);
    glVertex2f(-0.03, -0.06);
    glVertex2f(0.03, -0.06);
    glEnd();

    glColor3f(0.7, 0.9, 1);
    glBegin(GL_POLYGON);
    glVertex2f(0.03, 0.06);
    glVertex2f(-0.03, 0.06);
    glVertex2f(-0.025, 0.08);
    glVertex2f(0.025, 0.08);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.1);
    glVertex2f(-0.01, 0.1);
    glVertex2f(-0.01, 0.08);
    glVertex2f(0.01, 0.08);
    glEnd();
}

void slide() {
    glColor3f(0.8, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.14, 0.2);
    glVertex2f(0.0, 0.2);
    glVertex2f(0.4, -0.2);
    glVertex2f(0.54, -0.2);
    glEnd();

    glColor3f(0.3, 0.7, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.14, 0.2);
    glVertex2f(0.14, -0.2);
    glVertex2f(0.04, -0.2);
    glVertex2f(0, -0.1);
    glVertex2f(-0.04, -0.2);
    glVertex2f(-0.14, -0.2);
    glVertex2f(-0.14, 0.2);
    glVertex2f(-0.1, 0.25);
    glVertex2f(0.1, 0.25);
    glEnd();

    glColor3f(0.3, 0.3, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.18);
    glVertex2f(0.1, 0.05);
    glVertex2f(-0.1, 0.05);
    glVertex2f(-0.1, 0.18);
    glEnd();
}

void baby() {
    glPushMatrix();
    glTranslatef(-0.5, -0.4 + jp * 0.001, 0.0);
    glPushMatrix();//����
    glRotatef(10.0, 0.0, 0.0, 1);
    glPushMatrix();
    glColor3f(1, 0.72, 0.52);
    glScalef(1.3, 1, 1.0);
    glutSolidSphere(0.1, 20, 10);
    glPopMatrix();

    glPushMatrix();//������
    glRotatef(90.0, 0.0, 0.0, 1);
    glColor3f(0.9, 0.9, 0.9);
    glScalef(0.1, 0.13, 1.0);
    drawHalfSphere();
    glPopMatrix();
    glPopMatrix();//����

    glPushMatrix();//��1
    glRotatef(-sww, 0.0, 0.0, 1);
    glPushMatrix();
    glTranslatef(0.1, -0.06, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.5, 1, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glTranslatef(0.1, -0.11, 0.0);
    glScalef(0.5, 0.5, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();//��1

    glPushMatrix();//��2
    glRotatef(sww - 50, 0.0, 0.0, 1);
    glPushMatrix();
    glTranslatef(0.1, -0.06, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.5, 1, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();
    glTranslatef(0.1, -0.11, 0.0);
    glScalef(0.5, 0.5, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();//��2

    glPushMatrix();//�ٸ�1
    glRotatef(-30 - sww * 0.25, 0, 0.0, 1);
    glPushMatrix();
    glTranslatef(-0.05, -0.1, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.8, 1.3, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(30, 0.0, 0.0, 1);
    glTranslatef(-0.15, -0.11, 0.0);
    glScalef(1, 0.6, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.13, -0.19, 0.0);
    glScalef(0.5, 0.8, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();
    glPopMatrix();//�ٸ�1

    glPushMatrix();//������
    glRotatef(90.0, 0.0, 0.0, 1);
    glColor3f(0.9, 0.9, 0.9);
    glScalef(0.1, 0.13, 1.0);
    drawHalfSphere();
    glPopMatrix();

    glPushMatrix();//�ٸ�2
    glRotatef(-38 + sww * 0.25, 0, 0.0, 1);
    glPushMatrix();
    glTranslatef(-0.05, -0.1, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.8, 1.3, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(30, 0.0, 0.0, 1);
    glTranslatef(-0.15, -0.11, 0.0);
    glScalef(1, 0.6, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.13, -0.19, 0.0);
    glScalef(0.5, 0.8, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();
    glPopMatrix();//�ٸ�2

    glPushMatrix();//�Ӹ�
    glTranslatef(0.15, 0.1, 0.0);
    glRotatef(-sww * 0.3, 0.0, 0.0, 1);
    glColor3f(1, 0.72, 0.52);
    glutSolidSphere(0.1, 20, 10);

    glPushMatrix();//�Ӹ�ī��
    glTranslatef(0, 0.1, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.05, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(0.072, -0.052, 0.0);
    glColor3f(1, 0.68, 0);
    glutSolidSphere(0.025, 20, 10);

    glTranslatef(0.021, -0.01, 0.0);
    glColor3f(1, 0.68, 0);
    glutSolidSphere(0.018, 20, 10);
    glPopMatrix();

    glPushMatrix();//��
    glTranslatef(0.02, -0.01, 0.0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.02, 20, 10);
    glColor3f(0, 0, 0);
    glutSolidSphere(0.016, 20, 10);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void boy() {
    glPushMatrix();
    glTranslatef(-0.5, -0.35 + jp * 0.001, 0.0);
    glRotatef(-sww * 0.1, 0.0, 0.0, 1);
    glPushMatrix();//����
    glTranslatef(0.02, 0.0, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1);
    glPushMatrix();
    glColor3f(0, 0.2, 0.5);
    glScalef(0.4, 0.3, 1.0);
    glutSolidSphere(0.3, 20, 10);
    glPopMatrix();

    glPushMatrix();//����
    glRotatef(90.0, 0.0, 0.0, 1);
    glColor3f(0.9, 0.9, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glPopMatrix();
    glPopMatrix();//����

    glPushMatrix();//��1
    glTranslatef(0, 0.02, 0.0);
    glRotatef(-sww, 0.0, 0.0, 1);
    glPushMatrix();
    glTranslatef(0.1, 0.06, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.5, 1, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glTranslatef(0.1, 0.12, 0.0);
    glScalef(0.5, 0.5, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();//��1

    glPushMatrix();//��2
    glTranslatef(0, 0.02, 0.0);
    glRotatef(sww - 50, 0.0, 0.0, 1);
    glPushMatrix();
    glTranslatef(0.1, 0.06, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.5, 1, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();
    glTranslatef(0.1, 0.12, 0.0);
    glScalef(0.5, 0.5, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();//��2

    glPushMatrix();//�ٸ�1
    glRotatef(10 - sww * 0.5, 0, 0.0, 1);
    glPushMatrix();
    glTranslatef(0, -0.1, 0.0);
    glColor3f(0, 0.2, 0.5);
    glScalef(0.8, 1.3, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.03, -0.15, 0.0);
    glRotatef(40, 0.0, 0.0, 1);
    glScalef(1, 0.6, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(10, 0.0, 0.0, 1);
    glTranslatef(-0.1, -0.19, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.5, 0.8, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();
    glPopMatrix();//�ٸ�1

    glPushMatrix();//�ٸ�2
    glRotatef(20 + sww * 0.5, 0, 0.0, 1);
    glPushMatrix();
    glTranslatef(0, -0.1, 0.0);
    glColor3f(0, 0.2, 0.5);
    glScalef(0.8, 1.3, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.03, -0.15, 0.0);
    glRotatef(40, 0.0, 0.0, 1);
    glScalef(1, 0.6, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(10, 0.0, 0.0, 1);
    glTranslatef(-0.1, -0.19, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.5, 0.8, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();
    glPopMatrix();//�ٸ�2

    glPushMatrix();//�Ӹ�
    glRotatef(-sww * 0.1, 0.0, 0.0, 1);
    glScalef(0.95, 0.95, 1.0);
    glTranslatef(0.05, 0.2, 0.0);
    glColor3f(1, 0.72, 0.52);
    glutSolidSphere(0.1, 20, 10);

    glPushMatrix();//�Ӹ�ī��
    glTranslatef(0, 0.1, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.05, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//�Ӹ�ī��
    glTranslatef(0, 0.1, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0.02, 0.05, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//��
    glTranslatef(0.072, -0.052, 0.0);
    glColor3f(1, 0.1, 0.1);
    glScaled(0.8, 1, 1);
    glutSolidSphere(0.018, 20, 10);
    glPopMatrix();

    glPushMatrix();//��
    glTranslatef(0.02, -0.01, 0.0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.02, 20, 10);
    glColor3f(0, 0, 0);
    glutSolidSphere(0.016, 20, 10);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();


}

void photobaby() {
    glPushMatrix();
    glPushMatrix();//����
    glRotatef(10.0, 0.0, 0.0, 1);
    glPushMatrix();
    glColor3f(1, 0.72, 0.52);
    glScalef(1.3, 1, 1.0);
    glutSolidSphere(0.1, 20, 10);
    glPopMatrix();

    glPushMatrix();//������
    glRotatef(90.0, 0.0, 0.0, 1);
    glColor3f(0.9, 0.9, 0.9);
    glScalef(0.1, 0.13, 1.0);
    drawHalfSphere();
    glPopMatrix();
    glPopMatrix();//����

    glPushMatrix();//��1
    glPushMatrix();
    glTranslatef(0.1, -0.06, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.5, 1, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glTranslatef(0.1, -0.11, 0.0);
    glScalef(0.5, 0.5, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();//��1

    glPushMatrix();//��2
    glRotatef(-50, 0.0, 0.0, 1);
    glPushMatrix();
    glTranslatef(0.1, -0.03, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.5, 1, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();
    glTranslatef(0.1, -0.07, 0.0);
    glScalef(0.5, 0.5, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();//��2

    glPushMatrix();//�ٸ�1
    glRotatef(-30, 0, 0.0, 1);
    glPushMatrix();
    glTranslatef(-0.05, -0.1, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.8, 1.3, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(30, 0.0, 0.0, 1);
    glTranslatef(-0.15, -0.11, 0.0);
    glScalef(1, 0.6, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.13, -0.19, 0.0);
    glScalef(0.5, 0.8, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();
    glPopMatrix();//�ٸ�1

    glPushMatrix();//�ٸ�2
    glRotatef(-38, 0, 0.0, 1);
    glPushMatrix();
    glTranslatef(-0.05, -0.1, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.8, 1.3, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(30, 0.0, 0.0, 1);
    glTranslatef(-0.15, -0.11, 0.0);
    glScalef(1, 0.6, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.13, -0.19, 0.0);
    glScalef(0.5, 0.8, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();
    glPopMatrix();//�ٸ�2

    glPushMatrix();//�Ӹ�
    glTranslatef(0.15, 0.1, 0.0);
    glRotatef(0, 0.0, 0.0, 1);
    glColor3f(1, 0.72, 0.52);
    glutSolidSphere(0.1, 20, 10);

    glPushMatrix();//�Ӹ�ī��
    glTranslatef(0, 0.1, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.05, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(0.072, -0.052, 0.0);
    glColor3f(1, 0.68, 0);
    glutSolidSphere(0.025, 20, 10);

    glTranslatef(0.021, -0.01, 0.0);
    glColor3f(1, 0.68, 0);
    glutSolidSphere(0.018, 20, 10);
    glPopMatrix();

    glPushMatrix();//��
    glTranslatef(0.02, -0.01, 0.0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.02, 20, 10);
    glColor3f(0, 0, 0);
    glutSolidSphere(0.016, 20, 10);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void photoflower() {
    glColor3f(0.6, 0.3, 0.3);//ȭ��
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.1, 0.05);
    glEnd();

    glPushMatrix();//��
    glTranslatef(0, 0.125, 0.0);
    glColor3f(0, 1, 0);
    glScaled(0.5, 3, 0);
    glutSolidCube(0.05);
    glPopMatrix();

    glPushMatrix();//��
    glTranslatef(0, 0.2, 0.0);
    glPushMatrix();//�߽�
    glColor3f(1, 1, 0);
    glutSolidCube(0.05);
    glPopMatrix();//�߽�

    glRotatef(45, 0, 0, 1);
    glPushMatrix();//��1
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//��1

    glPushMatrix();//��2
    glRotatef(90, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//��2

    glPushMatrix();//��3
    glRotatef(-90, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//��3

    glPushMatrix();//��4
    glRotatef(180, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//��4
    glPopMatrix();//��
}

void photo() {
    //����
    glColor3f(0.7, 0.5, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.22, 0.17);
    glVertex2f(0.22, -0.17);
    glVertex2f(-0.22, -0.17);
    glVertex2f(-0.22, 0.17);
    glEnd();

    glColor3f(0.9, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0.2, 0.15);
    glVertex2f(0.2, -0.15);
    glVertex2f(-0.2, -0.15);
    glVertex2f(-0.2, 0.15);
    glEnd();
    //�ٴ�
    glColor3f(0.7, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.2, -0.15);
    glVertex2f(-0.2, -0.15);
    glVertex2f(-0.2, -0.1);
    glEnd();
    //��
    glPushMatrix();
    glTranslatef(0.12, -0.07, 0);
    glScalef(0.4, 0.4, 0);
    photoflower();
    glPopMatrix();
    //�ֱ�
    glPushMatrix();
    glTranslatef(0, -0.05, 0);
    glScalef(0.6, 0.6, 0);
    glRotatef(180, 0, 1, 0);
    photobaby();
    glPopMatrix();
}

void LIFEGAME() {
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.45, 0.25, 0.0);
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);//L
    glVertex2f(-0.03, -0.09);
    glVertex2f(0.1, -0.09);
    glVertex2f(0.1, -0.15);
    glVertex2f(-0.1, -0.15);
    glVertex2f(-0.1, 0.15);
    glVertex2f(-0.03, 0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.25, 0.25, 0.0);
    glBegin(GL_LINE_LOOP);//I
    glVertex2f(-0.03, 0.15);
    glVertex2f(0.03, 0.15);
    glVertex2f(0.03, -0.15);
    glVertex2f(-0.03, -0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.07, 0.25, 0.0);
    glBegin(GL_LINE_LOOP);//F
    glVertex2f(-0.07, -0.15);
    glVertex2f(-0.07, 0.15);
    glVertex2f(0.1, 0.15);
    glVertex2f(0.1, 0.08);
    glVertex2f(-0.02, 0.08);
    glVertex2f(-0.02, 0);
    glVertex2f(0.1, 0);
    glVertex2f(0.1, -0.05);
    glVertex2f(-0.02, -0.05);
    glVertex2f(-0.02, -0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, 0.25, 0.0);
    glBegin(GL_LINE_LOOP);//E
    glVertex2f(-0.02, -0.03);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.1, 0.03);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.02, 0.09);
    glVertex2f(0.1, 0.09);
    glVertex2f(0.1, 0.15);
    glVertex2f(-0.07, 0.15);
    glVertex2f(-0.07, -0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(0.1, -0.09);
    glVertex2f(-0.02, -0.09);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.35, 0.2, 0.0);
    glBegin(GL_LINE_LOOP);//I
    glVertex2f(-0.02, 0.1);
    glVertex2f(0.02, 0.1);
    glVertex2f(0.02, -0.1);
    glVertex2f(-0.02, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.2, 0.0);
    glBegin(GL_LINE_LOOP);//S
    glVertex2f(0.05, -0.1);
    glVertex2f(0.05, 0.03);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.02, 0.05);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, 0.1);
    glVertex2f(-0.07, 0.1);
    glVertex2f(-0.07, -0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(0.02, -0.05);
    glVertex2f(-0.07, -0.05);
    glVertex2f(-0.07, -0.1);
    glVertex2f(-0.07, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, -0.3, 0.0);
    glBegin(GL_LINE_LOOP);//A
    glVertex2f(-0.07, -0.1);
    glVertex2f(-0.07, 0.1);
    glVertex2f(0.07, 0.1);
    glVertex2f(0.07, -0.1);
    glVertex2f(0.02, -0.1);
    glVertex2f(0.02, 0);
    glVertex2f(-0.02, 0);
    glVertex2f(-0.02, -0.1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.02, 0.06);
    glVertex2f(-0.02, 0.03);
    glVertex2f(0.02, 0.03);
    glVertex2f(0.02, 0.06);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.31, -0.25, 0.0);
    glBegin(GL_LINE_LOOP);//G
    glVertex2f(-0.1, -0.15);
    glVertex2f(-0.1, 0.15);
    glVertex2f(0.1, 0.15);
    glVertex2f(0.1, 0.03);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.04, 0.1);
    glVertex2f(-0.04, 0.1);
    glVertex2f(-0.04, -0.1);
    glVertex2f(0.04, -0.1);
    glVertex2f(0.04, -0.07);
    glVertex2f(0.0, -0.07);
    glVertex2f(0.0, -0.01);
    glVertex2f(0.1, -0.01);
    glVertex2f(0.1, -0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.08, -0.25, 0.0);
    glBegin(GL_LINE_LOOP);//A
    glVertex2f(-0.1, -0.15);
    glVertex2f(-0.1, 0.15);
    glVertex2f(0.1, 0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(0.04, -0.15);
    glVertex2f(0.04, 0);
    glVertex2f(-0.04, 0);
    glVertex2f(-0.04, -0.15);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.04, 0.1);
    glVertex2f(-0.04, 0.05);
    glVertex2f(0.04, 0.05);
    glVertex2f(0.04, 0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.17, -0.25, 0.0);
    glBegin(GL_LINE_LOOP);//M
    glVertex2f(0.07, -0.15);
    glVertex2f(0.13, -0.15);
    glVertex2f(0.13, 0.15);
    glVertex2f(-0.13, 0.15);
    glVertex2f(-0.13, -0.15);
    glVertex2f(-0.07, -0.15);
    glVertex2f(-0.07, 0.09);
    glVertex2f(-0.04, 0.09);
    glVertex2f(-0.04, -0.15);
    glVertex2f(0.04, -0.15);
    glVertex2f(0.04, 0.09);
    glVertex2f(0.07, 0.09);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, -0.25, 0.0);
    glBegin(GL_LINE_LOOP);//E
    glVertex2f(-0.02, -0.03);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.1, 0.03);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.02, 0.09);
    glVertex2f(0.1, 0.09);
    glVertex2f(0.1, 0.15);
    glVertex2f(-0.07, 0.15);
    glVertex2f(-0.07, -0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(0.1, -0.09);
    glVertex2f(-0.02, -0.09);
    glEnd();
    glPopMatrix();
}

void LIFEGAME2() {
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.45, 0.25, 0.0);
    glLineWidth(9);
    glBegin(GL_LINE_LOOP);//L
    glVertex2f(-0.03, -0.09);
    glVertex2f(0.1, -0.09);
    glVertex2f(0.1, -0.15);
    glVertex2f(-0.1, -0.15);
    glVertex2f(-0.1, 0.15);
    glVertex2f(-0.03, 0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.25, 0.25, 0.0);
    glBegin(GL_LINE_LOOP);//I
    glVertex2f(-0.03, 0.15);
    glVertex2f(0.03, 0.15);
    glVertex2f(0.03, -0.15);
    glVertex2f(-0.03, -0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.07, 0.25, 0.0);
    glBegin(GL_LINE_LOOP);//F
    glVertex2f(-0.07, -0.15);
    glVertex2f(-0.07, 0.15);
    glVertex2f(0.1, 0.15);
    glVertex2f(0.1, 0.08);
    glVertex2f(-0.02, 0.08);
    glVertex2f(-0.02, 0);
    glVertex2f(0.1, 0);
    glVertex2f(0.1, -0.05);
    glVertex2f(-0.02, -0.05);
    glVertex2f(-0.02, -0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, 0.25, 0.0);
    glBegin(GL_LINE_LOOP);//E
    glVertex2f(-0.02, -0.03);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.1, 0.03);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.02, 0.09);
    glVertex2f(0.1, 0.09);
    glVertex2f(0.1, 0.15);
    glVertex2f(-0.07, 0.15);
    glVertex2f(-0.07, -0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(0.1, -0.09);
    glVertex2f(-0.02, -0.09);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.35, 0.2, 0.0);
    glBegin(GL_LINE_LOOP);//I
    glVertex2f(-0.02, 0.1);
    glVertex2f(0.02, 0.1);
    glVertex2f(0.02, -0.1);
    glVertex2f(-0.02, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.2, 0.0);
    glBegin(GL_LINE_LOOP);//S
    glVertex2f(0.05, -0.1);
    glVertex2f(0.05, 0.03);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.02, 0.05);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, 0.1);
    glVertex2f(-0.07, 0.1);
    glVertex2f(-0.07, -0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(0.02, -0.05);
    glVertex2f(-0.07, -0.05);
    glVertex2f(-0.07, -0.1);
    glVertex2f(-0.07, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, -0.3, 0.0);
    glBegin(GL_LINE_LOOP);//A
    glVertex2f(-0.07, -0.1);
    glVertex2f(-0.07, 0.1);
    glVertex2f(0.07, 0.1);
    glVertex2f(0.07, -0.1);
    glVertex2f(0.02, -0.1);
    glVertex2f(0.02, 0);
    glVertex2f(-0.02, 0);
    glVertex2f(-0.02, -0.1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.02, 0.06);
    glVertex2f(-0.02, 0.03);
    glVertex2f(0.02, 0.03);
    glVertex2f(0.02, 0.06);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.31, -0.25, 0.0);
    glBegin(GL_LINE_LOOP);//G
    glVertex2f(-0.1, -0.15);
    glVertex2f(-0.1, 0.15);
    glVertex2f(0.1, 0.15);
    glVertex2f(0.1, 0.03);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.04, 0.1);
    glVertex2f(-0.04, 0.1);
    glVertex2f(-0.04, -0.1);
    glVertex2f(0.04, -0.1);
    glVertex2f(0.04, -0.07);
    glVertex2f(0.0, -0.07);
    glVertex2f(0.0, -0.01);
    glVertex2f(0.1, -0.01);
    glVertex2f(0.1, -0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.08, -0.25, 0.0);
    glBegin(GL_LINE_LOOP);//A
    glVertex2f(-0.1, -0.15);
    glVertex2f(-0.1, 0.15);
    glVertex2f(0.1, 0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(0.04, -0.15);
    glVertex2f(0.04, 0);
    glVertex2f(-0.04, 0);
    glVertex2f(-0.04, -0.15);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.04, 0.1);
    glVertex2f(-0.04, 0.05);
    glVertex2f(0.04, 0.05);
    glVertex2f(0.04, 0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.17, -0.25, 0.0);
    glBegin(GL_LINE_LOOP);//M
    glVertex2f(0.07, -0.15);
    glVertex2f(0.13, -0.15);
    glVertex2f(0.13, 0.15);
    glVertex2f(-0.13, 0.15);
    glVertex2f(-0.13, -0.15);
    glVertex2f(-0.07, -0.15);
    glVertex2f(-0.07, 0.09);
    glVertex2f(-0.04, 0.09);
    glVertex2f(-0.04, -0.15);
    glVertex2f(0.04, -0.15);
    glVertex2f(0.04, 0.09);
    glVertex2f(0.07, 0.09);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, -0.25, 0.0);
    glBegin(GL_LINE_LOOP);//E
    glVertex2f(-0.02, -0.03);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.1, 0.03);
    glVertex2f(-0.02, 0.03);
    glVertex2f(-0.02, 0.09);
    glVertex2f(0.1, 0.09);
    glVertex2f(0.1, 0.15);
    glVertex2f(-0.07, 0.15);
    glVertex2f(-0.07, -0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(0.1, -0.09);
    glVertex2f(-0.02, -0.09);
    glEnd();
    glPopMatrix();
}

void floor() {
    glColor3f(0.5, 0.3, 0); // �ٴ�
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, -0.67);
    glVertex2f(-1.0, -0.67);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0);
    glVertex2f(-1.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, -0.52);
    glVertex2f(-1.0, -0.52);
    glEnd();
}

void floor2() {
    glColor3f(1, 0.8, 4); // �ٴ�
    glBegin(GL_QUADS);
    glVertex2f(10.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, -0.67);
    glVertex2f(10.0, -0.67);
    glEnd();
    glColor3f(0.9, 0.7, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(10.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, -0.52);
    glVertex2f(10.0, -0.52);
    glEnd();
}

void k_window() {
    glTranslatef(0, 0.2, 0.0);
    glColor3f(0, 0.5, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, 0.2);
    glVertex2f(0.15, -0.2);
    glVertex2f(-0.15, -0.2);
    glVertex2f(-0.15, 0.2);
    glEnd();

    glPushMatrix();
    glTranslatef(0, 0.2, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0);
    glVertex2f(0.15, 0.015);
    glVertex2f(0.15, -0.015);
    glVertex2f(-0.15, -0.015);
    glVertex2f(-0.15, 0.015);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.2, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0);
    glVertex2f(0.15, 0.015);
    glVertex2f(0.15, -0.015);
    glVertex2f(-0.15, -0.015);
    glVertex2f(-0.15, 0.015);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.14, 0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0);
    glVertex2f(0.01, 0.2);
    glVertex2f(0.01, -0.2);
    glVertex2f(-0.01, -0.2);
    glVertex2f(-0.01, 0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.14, 0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0);
    glVertex2f(0.01, 0.2);
    glVertex2f(0.01, -0.2);
    glVertex2f(-0.01, -0.2);
    glVertex2f(-0.01, 0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0);
    glVertex2f(0.15, 0.01);
    glVertex2f(0.15, -0.01);
    glVertex2f(-0.15, -0.01);
    glVertex2f(-0.15, 0.01);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0);
    glVertex2f(0.01, 0.2);
    glVertex2f(0.01, -0.2);
    glVertex2f(-0.01, -0.2);
    glVertex2f(-0.01, 0.2);
    glEnd();
    glPopMatrix();
}

void table() {
    glColor3f(0.45, 0.25, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.2, 0.15);
    glVertex2f(0.2, -0.15);
    glVertex2f(-0.2, -0.15);
    glVertex2f(-0.2, 0.15);
    glEnd();

    glPushMatrix();
    glTranslatef(0, 0.15, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.2, 0);
    glVertex2f(0.23, 0.015);
    glVertex2f(0.23, -0.015);
    glVertex2f(-0.23, -0.015);
    glVertex2f(-0.23, 0.015);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.06, 0.0);
    glColor3f(0.4, 0.2, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.18, 0.05);
    glVertex2f(0.18, -0.05);
    glVertex2f(-0.18, -0.05);
    glVertex2f(-0.18, 0.05);
    glEnd();
    glColor3f(0, 0, 0);
    glutSolidSphere(0.01, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.06, 0.0);
    glColor3f(0.4, 0.2, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.18, 0.05);
    glVertex2f(0.18, -0.05);
    glVertex2f(-0.18, -0.05);
    glVertex2f(-0.18, 0.05);
    glEnd();
    glColor3f(0, 0, 0);
    glutSolidSphere(0.01, 20, 10);
    glPopMatrix();
}

void k_Tv() {

    glColor3f(0.45, 0.25, 0); //���� ���
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.2, 0.1);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.0, 0.15, 0); //���� ��1
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, -0.025);
    glVertex2f(-0.15, -0.075);
    glVertex2f(0.15, -0.075);
    glVertex2f(0.15, -0.025);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.15, 0); //���� ��2
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, 0.025);
    glVertex2f(-0.15, 0.075);
    glVertex2f(0.15, 0.075);
    glVertex2f(0.15, 0.025);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);//Ƽ�� Ʋ
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, 0.1);
    glVertex2f(-0.25, 0.4);
    glVertex2f(0.25, 0.4);
    glVertex2f(0.25, 0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);//Ƽ�� ȭ��
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.15);
    glVertex2f(-0.2, 0.35);
    glVertex2f(0.2, 0.35);
    glVertex2f(0.2, 0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //������
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();



}

void clock1() {
    glColor3f(0.45, 0.25, 0);
    glutSolidCube(0.17);

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glutSolidCube(0.15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glutSolidCube(0.015);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.04, 0, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.02, 0.005);
    glVertex2f(0.02, -0.005);
    glVertex2f(-0.02, -0.005);
    glVertex2f(-0.02, 0.005);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.04, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.005, 0.02);
    glVertex2f(0.005, -0.02);
    glVertex2f(-0.005, -0.02);
    glVertex2f(-0.005, 0.02);
    glEnd();
    glPopMatrix();
}

void clock2() {
    glColor3f(0.45, 0.25, 0);
    glutSolidCube(0.17);

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glutSolidCube(0.15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glutSolidCube(0.015);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.04, 0, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.02, 0.005);
    glVertex2f(0.02, -0.005);
    glVertex2f(-0.02, -0.005);
    glVertex2f(-0.02, 0.005);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.04, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.005, 0.02);
    glVertex2f(0.005, -0.02);
    glVertex2f(-0.005, -0.02);
    glVertex2f(-0.005, 0.02);
    glEnd();
    glPopMatrix();
}

void table2() {
    glColor3f(0.8, 0.5, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.5, 0.15);
    glVertex2f(0.5, 0.05);
    glVertex2f(-0.5, 0.05);
    glVertex2f(-0.5, 0.15);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.4, 0, 0.0);
    glColor3f(0.75, 0.45, 0.05);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(-0.05, 0.05);
    glVertex2f(-0.05, -0.15);
    glVertex2f(0.05, -0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, 0, 0.0);
    glColor3f(0.75, 0.45, 0.05);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.05);
    glVertex2f(-0.05, 0.05);
    glVertex2f(-0.05, -0.15);
    glVertex2f(0.05, -0.15);
    glEnd();
    glPopMatrix();
}

void door() {
    glColor3f(0.3, 0.2, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, -0.67);
    glVertex2f(0, -0.67);
    glVertex2f(0, 0.67);
    glVertex2f(0.15, 0.67);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.2, 0);
    glVertex2f(0, 0.1);
    glVertex2f(0, -0.6);
    glVertex2f(-0.23, -0.6);
    glVertex2f(-0.23, 0.1);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.2, -0.27, 0.0);
    glColor3f(0, 0, 0);
    glutSolidSphere(0.02, 20, 10);
    glPopMatrix();
}

void k_door() {
    glColor3f(0.3, 0.2, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, -0.67);
    glVertex2f(0, -0.67);
    glVertex2f(0, 0.67);
    glVertex2f(0.15, 0.67);
    glEnd();
}

void wall() {
    glColor3f(0.3, 0.2, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, -0.67);
    glVertex2f(0, -0.67);
    glVertex2f(0, 0.67);
    glVertex2f(0.15, 0.67);
    glEnd();
}

void wallline() {
    glBegin(GL_QUADS);
    glVertex2f(-0.05, -0.5);
    glVertex2f(0.05, -0.5);
    glVertex2f(0.05, 0.67);
    glVertex2f(-0.05, 0.67);
    glEnd();
}

void walllines() {
    glPushMatrix();//����
    glTranslatef(-0.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(0, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(0.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(1, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(1.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(2, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(2.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(3, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(3.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(4, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(4.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(5, 0, 0.0);
    wallline();
    glPopMatrix();
}

void background() {
    glColor3f(0.8, 0.6, 0.5); //��
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, 0.67);
    glVertex2f(-1.0, 0.67);
    glEnd();

    glPushMatrix();//����
    glColor3f(0.75, 0.55, 0.45);
    walllines();
    glPopMatrix();

    glPushMatrix();//â��
    glTranslatef(-0.5, 0, 0.0);
    k_window();
    glPopMatrix();

    glPushMatrix();//â��
    glTranslatef(0.8, 0, 0.0);
    k_window();
    glPopMatrix();

    glPushMatrix();//â��
    glTranslatef(2.1, 0, 0.0);
    k_window();
    glPopMatrix();

    glPushMatrix();//â��
    glTranslatef(3.4, 0, 0.0);
    k_window();
    glPopMatrix();

    glPushMatrix();//���̺�
    glTranslatef(-0.3, -0.35, 0.0);
    table();
    glPopMatrix();

    glPushMatrix();//���̺�
    glTranslatef(1.8, -0.35, 0.0);
    table();
    glTranslatef(0.1, 0.2, 0.0);
    glColor3f(0.5, 0.4, 0.3);
    glutSolidTeapot(0.05);
    glPopMatrix();

    glPushMatrix();//���̺�
    glTranslatef(4, -0.35, 0.0);
    table();
    glPopMatrix();

    glPushMatrix();//Tv
    glTranslatef(2.7, -0.4, 0.0);
    k_Tv();
    glPopMatrix();

    glPushMatrix();//�ð�
    glTranslatef(0.2, 0.2, 0.0);
    clock1();
    glPopMatrix();

    glPushMatrix();//�ð�
    glTranslatef(2.9, 0.2, 0.0);
    clock1();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(0, -0.474, 0.0);
    glRotatef(-90, 0, 0, 1);
    feeding_bottle();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(3.5, -0.45, 0.0);
    feeding_bottle();
    glPopMatrix();

    glPushMatrix();//��
    glTranslatef(-0.3, -0.136, 0.0);
    flower();
    glPopMatrix();

    glPushMatrix();//��
    glTranslatef(4, -0.136, 0.0);
    flower();
    glPopMatrix();
}

void background2() {
    glColor3f(0.79, 1, 0.29); //����
    glBegin(GL_QUADS);
    glVertex2f(10.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, 0.67);
    glVertex2f(10.0, 0.67);
    glEnd();

    glPushMatrix();//����
    glTranslatef(5.8, 0, 0.0);
    glColor3f(0.74, 0.95, 0.24);
    walllines();
    glPopMatrix();

    glPushMatrix();//���̺�
    glTranslatef(5.8, -0.35, 0.0);
    table2();
    glPopMatrix();


    glPushMatrix();//���̺�
    glTranslatef(8.6, -0.35, 0.0);
    table2();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(8.7, -0.15, 0.0);
    feeding_bottle();
    glPopMatrix();

    glPushMatrix();//�κ�
    glTranslatef(7.8, -0.36, 0.0);
    glScalef(0.5, 0.5, 0);
    robot();
    glPopMatrix();

    glPushMatrix();//�κ�
    glTranslatef(5.5, -0.09, 0.0);
    glRotatef(180, 0, 1, 0);
    glScalef(0.4, 0.4, 0);
    robot();
    glPopMatrix();

    glPushMatrix();//��
    glTranslatef(6, -0.17, 0.0);
    glScalef(0.6, 0.6, 0);
    flower();
    glPopMatrix();

    glPushMatrix();//��
    glTranslatef(5 + Delta * 0.002, -0.49, 0.0);
    glScalef(0.6, 0.6, 0);
    car();
    glPopMatrix();

    glPushMatrix();//���
    glTranslatef(6.6, -0.48, 0.0);
    glScalef(0.4, 0.4, 0);
    bloks();
    glPopMatrix();

    glPushMatrix();//���
    glTranslatef(9.2, -0.48, 0.0);
    glScalef(0.4, 0.4, 0);
    bloks();
    glPopMatrix();

    glPushMatrix();//����
    glTranslatef(7.3, 0.2, 0.0);
    photo();
    glPopMatrix();

    glPushMatrix();//�ð�
    glTranslatef(8.8, 0.2, 0.0);
    clock2();
    glPopMatrix();
}

void kangwoo() {
    glPushMatrix();
    glTranslatef(-Delta * 0.006, 0, 0.0);
    glPushMatrix();
    floor();//�ٴ�1
    glPopMatrix();

    glPushMatrix();
    floor2();//�ٴ�2
    glPopMatrix();

    glPushMatrix();
    background();//���1
    glPopMatrix();

    glPushMatrix();
    background2();//���2
    glPopMatrix();
    glPopMatrix();



    //���
    glPushMatrix();
    Heartbackgound();
    glPopMatrix();
}

void dongcheol() {
    glPushMatrix();
    if (Delta >= 3496 && Delta <= 3680) {
        glTranslatef(-10, 0, 0);
    }
    else glTranslatef(11 - Delta * 0.006, 0, 0);

    backGround();

    glPushMatrix();
    glTranslatef(3.5, 0, 0);
    Entrance();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.5, 0, 0);
    Entrance();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5, 0, 0);
    Entrance1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.5, 0, 0);
    Entrance1();
    glPopMatrix();
    glPopMatrix();
}

void boymove() {
    //�ֱ� >> �ҳ�
    if (Delta < 935) {
        glPushMatrix();
        baby();
        glPopMatrix();
    }

    else if (Delta < 1720) {
        glPushMatrix();
        boy();
        glPopMatrix();
    }
    else if (Delta < 2730) {
        glPushMatrix();
        charaterMain2();
        glPopMatrix();
    }

    else if (Delta < 3660) {
        if (Delta > 3496 && Delta < 3670) {
            Xmove += 0.024;
        }
        glPushMatrix();
        glTranslatef(Xmove, 0, 0);
        charaterMain();
        glPopMatrix();
    }
}

void doorset() {
    if (Delta > 900) {
        glPushMatrix();
        glTranslatef(-Delta * 0.006 + 5 + 0.15, 0, 0.0);
        glRotatef(180, 0, 1, 0);
        door();
        glPopMatrix();
    }
    else {
        glPushMatrix();
        glTranslatef(-Delta * 0.006 + 5, 0, 0.0);
        k_door();
        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(-Delta * 0.006 + 13.8, 0, 0.0);
    wall();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-Delta * 0.006 + 16.5, 0, 0.0);
    Entrance1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-Delta * 0.006 + 10.5, 0, 0.0);
    Entrance1();
    glPopMatrix();
}

void hun() {
    glPushMatrix();
    glTranslatef(0, 0.003 * hun_Move, 0);
    h_charater();
    glPushMatrix(); //�����ٸ� ����
    glRotatef(0.1 * hun_Move, 0, 0, 1);
    h_leftleg();
    glPopMatrix();

    glPushMatrix(); //�޴ٸ� ����
    glRotatef(0.1 * -hun_Move, 0, 0, 1);
    h_rightleg();
    glPopMatrix();

    glPushMatrix(); //�� ����
    glRotatef(0, 0, 0, 1);
    h_rightarm();
    glPopMatrix();

    glPushMatrix(); //�� ����
    glRotatef(0.1 * hun_Move, 0, 0, 1);
    h_leftarm();
    glPopMatrix();
    glPopMatrix();
}//�Ҿƹ���

void mydisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 800, 800);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    kangwoo();
    dongcheol();
    boymove();
    doorset();

    if (Delta < 400) { //LIFE is A GAME
        glColor3f(0, 0, 0);
        LIFEGAME2();
        glColor3f(0.9, 0.9, 0.9);
        LIFEGAME();
    }

    glPushMatrix();
    Heartbackgound();
    glPopMatrix();
    if (Delta > 3680) {
        if (h_Delta > 1670) {
            PolarView(0, h_angle, h_angle, 0);
            h_backGround2();
        }
        else {
            h_backGround1();
        }

    }
    glFlush();
}

void MyTimer(int Value) {
    Delta = Delta + 4;

    sw = sw + 2;
    if (sw < 30) sww = sww + 4;
    else if (sw < 60) sww = sww - 4;
    else { sw = 0; sww = 0; }

    jp = jp + 0.5;
    if (jp == 5) jp = 0;

    angle = angle + 2;

    if (angle == 360) {
        angle = 0;
    }

    colortime = colortime + 4;
    if (colortime == 100) {
        colortime = 0;
    }
    else if (colortime < 50) color = 0;
    else if (colortime < 100) color = 1;

    //��
    Move += increment;
    if (Move > 10.0f) {
        Move = 10.0f;
        increment = -1.0f;
    }
    if (Move < 0.0f) {
        Move = 0.0f;
        increment = 1.0f;
    }

    //��
    if (Delta > 3930) {
        if (stop) {
            h_a += 0.05f; // �ʴ� 0.1�� �̵�
            if (h_a >= 0.3f) {
                h_a = 0.3f; // ��ġ�� 1�� �ʰ����� �ʵ��� ����
                stop = false; // �̵� ����
            }
        }
        else {
            // 10�ʰ� ������ �̵� ����
            if (h_Delta >= 1610) {
                stop = true; // �̵� ����
            }
        }
        h_Move += h_increment;
        if (h_Move > 10.0f) {
            h_Move = 10.0f;
            h_increment = -1.0f;
        }
        if (h_Move < 0.0f) {
            h_Move = 0.0f;
            h_increment = 1.0f;
        }
        if (isAnimating) {
            h_angle += 0.18f; // ���� ����
            if (h_angle >= 90.0f) {
                h_angle = 90.0f; // ������ 90���� �����ϸ� ����
                isAnimating = false; // �ִϸ��̼� ���� ����
            }
            glutPostRedisplay(); // ȭ�� ����
        }
        h_Delta = h_Delta + 4;
    }

    hun_Move += h_increment;
    if (hun_Move > 10.0f) {
        hun_Move = 10.0f;
        h_increment = -1.0f;
    }
    if (hun_Move < 0.0f) {
        hun_Move = 0.0f;
        h_increment = 1.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(40, MyTimer, 1);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("LIFE is A GAME!");

    glutDisplayFunc(mydisplay);

    glutTimerFunc(40, MyTimer, 1);

    glutMainLoop();

    return 0;

}
