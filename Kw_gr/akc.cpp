#include <GL/glut.h>
#include <cmath>
#include <ctime>

GLint Delta = 0; //시간
GLint sw = 0; //끊기는 스윙
GLint sww = 0; //스윙
GLint color = 0; //색조절
GLint colortime = 0; //색조절위한 타이머
GLfloat jp = 0; //캐릭터가 움직이는것처럼 위아래
GLfloat angle = 0; // 360회전
GLfloat redX = 1; //목숨 줄어들기위한 타이머
GLfloat x = 0.0; // 맵

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
float h_angle; // 회전 각도

bool stop = false;
bool isAnimating = true; // 애니메이션 상태

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
    {0.1,0.1,0.1,1}, // 앞면 (빨간색)
    {0.1,0.1,0.1,1}, // 뒷면 (초록색)
    {0.1,0.1,0.1,1}, // 왼쪽면 (파란색)
    {0.1,0.1,0.1,1}, // 오른쪽면 (노란색)
    {0.1,0.1,0.1,1}, // 위쪽면 (자홍색)
    {0.1,0.1,0.1,1}  // 아래쪽면 (회색)
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

//------22124992 안현수 ---------------------------------------------------------

//창문 배경
void h_window() {
    glTranslatef(0, -0.1, 0.0);
    glColor3f(0, 0.5, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.4);
    glVertex2f(0.3, -0.4);
    glVertex2f(-0.3, -0.4);
    glVertex2f(-0.3, 0.4);
    glEnd();
    //창문위
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
    //창문 중간
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
    //창문 왼쪽
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
    //창문 오른쪽
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

    //건물 1번
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

    //건물 1번 창문
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

    //건물 2번 창문
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

    //건물 3번 창문
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

    //건물 4번 창문
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

    //건물 5번 창문
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

    //건물 6번 창문
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

    //건물 7번 창문
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

    //건물 2번
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

    //건물 2번 창문 1번
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

    //건물 2번 창문 2번
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

    //건물 2번 창문 3번
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

    //건물 2번 창문 4번
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

    //건물 2번 창문 5번
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

    //건물 2번 창문 6번
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

    //건물 3번
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

    //건물 3번 창문 1번
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

    //건물 3번 창문 2번
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

    //건물 3번 창문 3번
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

    //건물 3번 창문 4번
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


    //하늘
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

    //구름안에 점들 1번
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

    //구름안에 점들 2번
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

    //구름안에 점들 3번
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

    //구름안에 점들 4번
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

    //구름안에 점들 5번
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

    //구름안에 점들 6번
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

    //구름안에 점들 7번
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

    //구름안에 점들 8번
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

    //구름안에 점들 9번
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

    //컴퓨터 부스 왼쪽 테두리
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

    //컴퓨터 부스 오른쪽 테두리
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

    //컴퓨터 부스 위쪽 테두리
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

    //컴퓨터 부스 중간 테두리
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

    //엘베 위 전광판
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

    //엘베 위 전광판 안 숫자
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

    //하얀 배경
    glTranslatef(0, 0, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.24, -0.5);
    glVertex2f(-0.24, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.24, -0.5);
    glEnd();

    //안쪽 회색 벽
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

    //아래 바닥
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

    //위
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

    //엘베 안 유리
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

    //엘베 왼쪽 테두리
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

    //컴퓨터 부스 오른쪽 테두리
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

    //컴퓨터 부스 위쪽 테두리
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

    //엘베 위 전광판
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

    //엘베 위 전광판 안 숫자
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
    glColor3f(0.0f, 0.0f, 0.0f); // 선 색상 (검은색)
    glBegin(GL_LINES);

    // 앞면 선
    glVertex3fv(MyVertices[0]); glVertex3fv(MyVertices[1]);
    glVertex3fv(MyVertices[1]); glVertex3fv(MyVertices[2]);
    glVertex3fv(MyVertices[2]); glVertex3fv(MyVertices[3]);
    glVertex3fv(MyVertices[3]); glVertex3fv(MyVertices[0]);

    // 뒷면 선
    glVertex3fv(MyVertices[4]); glVertex3fv(MyVertices[5]);
    glVertex3fv(MyVertices[5]); glVertex3fv(MyVertices[6]);
    glVertex3fv(MyVertices[6]); glVertex3fv(MyVertices[7]);
    glVertex3fv(MyVertices[7]); glVertex3fv(MyVertices[4]);

    // 왼쪽면 선
    glVertex3fv(MyVertices[0]); glVertex3fv(MyVertices[4]);
    glVertex3fv(MyVertices[3]); glVertex3fv(MyVertices[7]);

    // 오른쪽면 선
    glVertex3fv(MyVertices[1]); glVertex3fv(MyVertices[5]);
    glVertex3fv(MyVertices[2]); glVertex3fv(MyVertices[6]);

    // 아래쪽면 선
    glVertex3fv(MyVertices[0]); glVertex3fv(MyVertices[4]);
    glVertex3fv(MyVertices[1]); glVertex3fv(MyVertices[5]);

    glEnd();
}

void Ten() {


    glColor3f(1.0, 0.84, 0); //십자가 위
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.25);
    glVertex2f(-0.1, -0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(0.1, -0.25);
    glEnd();


    glPushMatrix();
    glColor3f(1.0, 0.84, 0); //십자가 아래
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
    glColor3fv(h_colors[0]); // 앞면 색상
    glVertex3fv(MyVertices[0]);
    glVertex3fv(MyVertices[1]);
    glVertex3fv(MyVertices[2]);
    glVertex3fv(MyVertices[3]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(h_colors[1]); // 뒷면 색상
    glVertex3fv(MyVertices[4]);
    glVertex3fv(MyVertices[5]);
    glVertex3fv(MyVertices[6]);
    glVertex3fv(MyVertices[7]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(h_colors[2]); // 왼쪽면 색상
    glVertex3fv(MyVertices[0]);
    glVertex3fv(MyVertices[3]);
    glVertex3fv(MyVertices[7]);
    glVertex3fv(MyVertices[4]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(h_colors[3]); // 오른쪽면 색상
    glVertex3fv(MyVertices[1]);
    glVertex3fv(MyVertices[5]);
    glVertex3fv(MyVertices[6]);
    glVertex3fv(MyVertices[2]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(h_colors[4]); // 위쪽면 색상
    glVertex3fv(MyVertices[3]);
    glVertex3fv(MyVertices[2]);
    glVertex3fv(MyVertices[6]);
    glVertex3fv(MyVertices[7]);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(h_colors[5]); // 아래쪽면 색상
    glVertex3fv(MyVertices[0]);
    glVertex3fv(MyVertices[1]);
    glVertex3fv(MyVertices[5]);
    glVertex3fv(MyVertices[4]);
    glEnd();
    glEnd();

}

void Dong() {


    //머리
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.03, 0.1, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();


    //눈 (흰색 배경)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();

    //눈 (흰색 배경)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();


    //눈알 (검정)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //눈알 (검정)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();


    //머리카락
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //머리카락
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //머리카락
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.0305, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.035, 0);
    glEnd();
    glPopMatrix();

    //입 (빨강)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.06, 0.05, 0.0);
    glColor3f(0.8, 0.1, 0.1);
    glutSolidSphere(0.02, 30, 20);
    glEnd();
    glPopMatrix();

    //입 (안)
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(0.055, 0.05, 0.0);
    glColor3f(0.8, 0.3, 0);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();
}

void h_charater() {

    //몸통
    glPushMatrix();
    glRotatef(-30, 0, 0, 1);
    glTranslatef(-0.5, -0.6, 0);
    glColor3f(0.9, 0.5, 0.0);
    glScalef(0.65, 1.4, 0.1);
    glutSolidSphere(0.1, 20, 10);
    glEnd();
    glPopMatrix();

    //머리
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.65, -0.15, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();

    //수염
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

    //입
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

    //눈알 (검정) 왼
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.67, -0.13, 0.0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.015, 30, 20);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //눈알 (검정) 오
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.63, -0.13, 0.0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.015, 30, 20);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //팔자주름
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

    //단추1
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.75, -0.3, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //단추2
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.73, -0.25, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

}

void Face() {

    //머리
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.65, -0.15, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();

    //수염
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

    //입
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

    //눈알 (검정) 왼
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.67, -0.13, 0.0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.015, 30, 20);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //눈알 (검정) 오
    glPushMatrix();
    glRotatef(0, 0, 0, 1);
    glTranslatef(-0.63, -0.13, 0.0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.015, 30, 20);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //팔자주름
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

    //왼쪽 팔 윗부분
    glPushMatrix();
    glTranslatef(-0.63, -0.27, 0.0);
    glRotatef(60, 0, 0, 1);
    glColor3f(0, 0, 0.7);
    glScalef(0.3, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //지팡이 손잡이
    glPushMatrix();
    glTranslatef(-0.57, -0.3, 0.0);
    glRotatef(40, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.15, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //지팡이
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

    //뒷짐손위
    glPushMatrix();
    glTranslatef(-0.8, -0.25, 0.0);
    glRotatef(140, 0, 0, 1);
    glColor3f(0, 0, 0.7);
    glScalef(0.3, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //뒷짐 손
    glPushMatrix();
    glTranslatef(-0.82, -0.3, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.15, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();
}//1

void h_leftleg() {
    //왼쪽 다리 윗부분
    glPushMatrix();
    glTranslatef(-0.8, -0.4, 0.0);
    glRotatef(-15, 0, 0, 1);
    glColor3f(0.4, 0.7, 0.9);
    glScalef(0.3, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //왼쪽 다리 아랫부분
    glPushMatrix();
    glTranslatef(-0.8, -0.5, 0.0);
    glRotatef(190, 0, 0, 1);
    glColor3f(0.4, 0.7, 0.9);
    glScalef(0.2, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //왼쪽 신발
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
    //오른 다리 윗부분
    glPushMatrix();
    glTranslatef(-0.7, -0.4, 0.0);
    glRotatef(25, 0, 0, 1);
    glColor3f(0.4, 0.7, 0.9);
    glScalef(0.3, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //오른 다리 아랫부분
    glPushMatrix();
    glTranslatef(-0.7, -0.5, 0.0);
    glRotatef(150, 0, 0, 1);
    glColor3f(0.4, 0.7, 0.9);
    glScalef(0.2, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //오른 신발
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

    glColor3f(1.0, 1.0, 0.0); // 노란색(해)
    glTranslatef(0.8, 0.5, 0.0);
    glutSolidSphere(0.1, 50, 50);

}

void Hospital() {

    glColor3f(0.9, 0.9, 0.9); //병원
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
    glColor3f(0.0, 1.0, 0.3); // 병원 표시1
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
    glBegin(GL_QUADS); // 병원 표시2
    glVertex2f(-0.7, -0.25);
    glVertex2f(-0.7, -0.15);
    glVertex2f(-0.5, -0.15);
    glVertex2f(-0.5, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //병원 창문 1
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.85, -0.35, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //겉선
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
    //병원 창문 2
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.7, -0.35, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //겉선
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
    //병원 창문 3
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.7, -0.5, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //겉선
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
    //병원 창문 4
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.85, -0.5, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //겉선
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
    //병원 창문 5
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.05, -0.35, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //겉선
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
    //병원 창문 6
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(0.1, -0.35, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //겉선
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
    //병원 창문 7
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-0.05, -0.5, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //겉선
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
    //병원 창문 8
    glColor3f(0.5, 0.55, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(0.1, -0.5, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.75, -0.45);
    glVertex2f(-0.75, -0.35);
    glVertex2f(-0.85, -0.35);
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //겉선
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
    //병원 입구
    glColor3f(0.3, 0.8, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.65, -0.5);
    glVertex2f(-0.55, -0.5);
    glVertex2f(-0.55, -0.35);
    glVertex2f(-0.65, -0.35);
    glEnd();
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
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
    //병원 입구 손잡이1
    glTranslatef(-0.62, -0.43, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.01, 20, 20);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    //병원 입구 손잡이2
    glTranslatef(-0.58, -0.43, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.01, 20, 20);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.9, -0.5);
    glVertex2f(-0.9, -0.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.9, -0.3);
    glVertex2f(-0.7, -0.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.3);
    glVertex2f(-0.7, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.7, -0.1);
    glVertex2f(-0.5, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.5, -0.1);
    glVertex2f(-0.5, -0.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.5, -0.3);
    glVertex2f(-0.3, -0.3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.3, -0.3);
    glVertex2f(-0.3, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-0.3, -0.5);
    glVertex2f(-0.9, -0.5);
    glEnd();
    glPopMatrix();

}

void h_Wall() {

    glColor4f(0.75, 0.26, 0.16, 1.0); // 빨간색 중문
    glBegin(GL_POLYGON);
    glVertex2f(0.45, -0.67);
    glVertex2f(0.45, 0.67);
    glVertex2f(0.7, 0.67);
    glVertex2f(0.7, -0.67);
    glEnd();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //창틀
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
    glColor3f(0.0, 0.0, 0.0); //창틀
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
     glColor4f(0.92, 0.41, 0.12, 0.3); // 빨간색 안문
     glBegin(GL_POLYGON);
     glVertex2f(0.5, -0.67);
     glVertex2f(0.5, -0.00);
     glVertex2f(0.65, -0.00);
     glVertex2f(0.65, -0.67);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glColor3f(0.0, 0.0, 0.0); //창틀
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
     glColor3f(0.6, 0.3, 0.1); // 갈색 중문
     glBegin(GL_POLYGON);
     glVertex2f(0.65, -0.67);
     glVertex2f(0.65, -0.00);
     glVertex2f(0.85, -0.00);
     glVertex2f(0.85, -0.67);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glColor4f(0.6, 0.7, 0.1, 0.9); //갈색문 십자 표시
     glLineWidth(4.0);
     glBegin(GL_LINES);
     glVertex2f(0.65, -0.3);
     glVertex2f(0.85, -0.3);

     glVertex2f(0.75, -0.00);
     glVertex2f(0.75, -0.67);

     glEnd();
     glPopMatrix();

     glPushMatrix();
     glColor3f(0.0, 0.0, 0.0); //창틀
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
     glColor3f(0.0, 0.0, 0.0); //창틀
     glLineWidth(5.0);
     glBegin(GL_LINES);
     glVertex2f(0.45, -0.67);
     glVertex2f(0.45, 0.67);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glColor3f(0.0, 0.0, 0.0); //창틀
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
    glBegin(GL_LINE_LOOP);//D 밖
    glColor3f(1, 1, 1);
    glVertex2f(0.0, -0.3);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.4, 0.0);
    glVertex2f(0.1, 0.3);
    glVertex2f(0.0, 0.3);
    glEnd();

    glBegin(GL_LINE_LOOP);//D 안
    glColor3f(1, 1, 1);
    glVertex2f(0.1, -0.2);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.1, 0.2);
    glEnd();
    glPopMatrix();
}

void Home() {

    glColor3f(0.65, 0.16, 0.16);//집 바닥틀
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, 0.0);
    glVertex2f(-0.25, 0.05);
    glVertex2f(0.25, 0.05);
    glVertex2f(0.25, 0.0);
    glEnd();
    glPushMatrix(); //집 바닥틀 겉선
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

    glPushMatrix();  //집 본체 아래
    glColor3f(1.0, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.05);
    glVertex2f(-0.22, 0.35);
    glVertex2f(0.22, 0.35);
    glVertex2f(0.22, 0.05);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //집 본체 아래 겉선
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

    glPushMatrix(); //집 본체 위
    glColor3f(1.0, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.35);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.22, 0.35);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //집 본체 위 겉선
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glVertex2f(-0.22, 0.35);
    glVertex2f(0.0, 0.5);

    glVertex2f(0.0, 0.5);
    glVertex2f(0.22, 0.35);
    glEnd();
    glPopMatrix();

    glPushMatrix();//집 지붕 왼
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.35);
    glVertex2f(-0.27, 0.35);
    glVertex2f(0.0, 0.55);
    glVertex2f(0.0, 0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();//집 지붕 오른
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.0, 0.55);
    glVertex2f(0.27, 0.35);
    glVertex2f(0.22, 0.35);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //집 지붕 겉선
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

    glPushMatrix(); //집 문
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.17, 0.05);
    glVertex2f(-0.17, 0.2);
    glVertex2f(-0.07, 0.2);
    glVertex2f(-0.07, 0.05);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //집 손잡이
    glTranslatef(-0.09, 0.125, 0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //집 문 겉선
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

    glPushMatrix(); //집 창문
    glColor3f(0.68, 0.85, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(-0.04, 0.1);
    glVertex2f(-0.04, 0.2);
    glVertex2f(0.18, 0.2);
    glVertex2f(0.18, 0.1);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //집 창문 겉선
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

    glVertex2f(0.18, 0.15); //창 가로선
    glVertex2f(-0.04, 0.15);

    glVertex2f(0.065, 0.1); //창 세로선
    glVertex2f(0.065, 0.2);

    glEnd();
    glPopMatrix();

    glPushMatrix();//집 윗 동그라미 창문
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

    glLineWidth(6.0); //구름
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

    glColor3f(0.9, 0.4, 0.2); //사진 틀
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.7); // 사진 안 배경
    glBegin(GL_POLYGON);
    glVertex2f(-0.075, -0.075);
    glVertex2f(-0.075, 0.075);
    glVertex2f(0.075, 0.075);
    glVertex2f(0.075, -0.075);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0); //사진 배경
    glutWireSphere(0.05, 10, 30);
    glEnd();
    glPopMatrix();

}

void Picture2() {

    glColor3f(0.9, 0.4, 0.2); //사진 틀
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5); // 사진 안 배경
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

    glColor3f(0.9, 0.4, 0.2); //사진 틀
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5); // 사진 안 배경
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

    glColor3f(0.9, 0.4, 0.2); //사진 틀
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5); // 사진 안 배경
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

    glColor3f(0.1, 0.1, 0.1); // 관
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, -0.5);
    glVertex2f(-0.15, -0.0);
    glVertex2f(0.15, -0.0);
    glVertex2f(0.15, -0.5);
    glEnd();

    glPushMatrix();
    glColor3f(1.0, 0.84, 0); //십자가 위
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.25);
    glVertex2f(-0.1, -0.15);
    glVertex2f(0.1, -0.15);
    glVertex2f(0.1, -0.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 0.84, 0); //십자가 아래
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, -0.4);
    glVertex2f(-0.05, -0.08);
    glVertex2f(0.05, -0.08);
    glVertex2f(0.05, -0.4);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3); //겉선
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

    glColor3f(0.1, 0.1, 0.1); // 관
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, -0.5);
    glVertex2f(-0.15, -0.0);
    glVertex2f(0.15, -0.0);
    glVertex2f(0.15, -0.5);
    glEnd();

    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3); //겉선
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

    glColor3f(0.45, 0.25, 0); //선반 배경
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.2, 0.1);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.0, 0.15, 0); //선반 안1
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, -0.025);
    glVertex2f(-0.15, -0.075);
    glVertex2f(0.15, -0.075);
    glVertex2f(0.15, -0.025);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.15, 0); //선반 안2
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, 0.025);
    glVertex2f(-0.15, 0.075);
    glVertex2f(0.15, 0.075);
    glVertex2f(0.15, 0.025);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);//티비 틀
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, 0.1);
    glVertex2f(-0.25, 0.4);
    glVertex2f(0.25, 0.4);
    glVertex2f(0.25, 0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);//티비 화면
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.15);
    glVertex2f(-0.2, 0.35);
    glVertex2f(0.2, 0.35);
    glVertex2f(0.2, 0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //손잡이
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선2
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

    glColor4f(0.4, 0.2, 0.0, 0.75); //박스 앞면
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.5);
    glVertex2f(-0.1, -0.3);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.1, -0.5);
    glEnd();

    glPushMatrix(); //박스 옆
    glBegin(GL_POLYGON);
    glColor4f(0.4, 0.2, 0.0, 0.75);
    glVertex2f(0.1, -0.5);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.35, -0.3);
    glVertex2f(0.35, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //박스 글씨1
    glBegin(GL_LINES);
    glColor4f(1.0, 0.0, 0.0, 0.3);
    glLineWidth(5.0);
    glVertex2f(0.239, -0.4);
    glVertex2f(0.279, -0.4);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //박스 글씨2
    glBegin(GL_LINES);
    glColor4f(1.0, 0.0, 0.0, 0.3);
    glLineWidth(5.0);
    glVertex2f(0.229, -0.39);
    glVertex2f(0.289, -0.39);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //박스 글씨3
    glBegin(GL_LINES);
    glColor4f(1.0, 0.0, 0.0, 0.3);
    glLineWidth(5.0);
    glVertex2f(0.219, -0.38);
    glVertex2f(0.299, -0.38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //박스 글씨4
    glBegin(GL_LINES);
    glColor4f(1.0, 0.0, 0.0, 0.3);
    glLineWidth(5.0);
    glVertex2f(0.209, -0.37);
    glVertex2f(0.309, -0.37);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //박스 사과 잎
    glRotatef(60, 0, 0, 1);
    glTranslatef(-0.46, -0.03, 0);
    glBegin(GL_LINES);
    glColor4f(0.0, 1.0, 0.0, 0.3);
    glLineWidth(7.0);
    glVertex2f(0.25, -0.36);
    glVertex2f(0.3, -0.36);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //박스 구별선
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glVertex2f(0.1, -0.5);
    glVertex2f(0.1, -0.3);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //박스 테잎
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.0);
    glVertex2f(-0.03, -0.5);
    glVertex2f(-0.03, -0.3);
    glVertex2f(0.03, -0.3);
    glVertex2f(0.03, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //박스 겉선
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

    glColor3f(1.0, 1.0, 1.0); //콘센트 겉
    glScalef(0.5, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, -0.1);
    glVertex2f(-0.05, 0.1);
    glVertex2f(0.05, 0.1);
    glVertex2f(0.05, -0.1);
    glEnd();

    glPushMatrix(); //콘센트 겉선
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

    glPushMatrix(); //콘센트 틀
    glScalef(0.8, 0.8, 1.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.05, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //콘센트 구멍1
    glTranslatef(0.02, 0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //콘센트 구멍2
    glTranslatef(-0.02, 0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

}

void Mountain() {

    glColor3f(0.65, 0.27, 0.07); //산 전체
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.1, 0.2);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.2, -0.1);
    glEnd();
    glPushMatrix(); //산 겉선
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

    glPushMatrix();//산 봉우리
    glTranslatef(0.0, 0.2, 0.0);
    glScalef(1.7, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireSphere(0.07, 20, 20); //겉 선
    glColor3f(0.8, 0.8, 0.8);
    glutSolidSphere(0.07, 20, 20);
    glEnd();
    glPopMatrix();

}

void Hotel() {
    //회사 본체
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.3);
    glVertex2f(-0.2, 0.3);
    glVertex2f(0.2, 0.3);
    glVertex2f(0.2, -0.3);
    glEnd();
    glPushMatrix();//회사 본체 겉선
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


    glPushMatrix();//회사 문
    glColor3f(1.0, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, -0.3);
    glVertex2f(-0.05, -0.15);
    glVertex2f(0.05, -0.15);
    glVertex2f(0.05, -0.3);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);//문 나누기
    glBegin(GL_LINES);
    glLineWidth(0.5);
    glVertex2f(-0.00, -0.3);
    glVertex2f(-0.00, -0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();//회사 문 겉선
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
    glColor3f(0.0, 0.0, 0.0);//손잡이1
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.02, -0.25, 0);
    glColor3f(0.0, 0.0, 0.0);//손잡이2
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //회사 간판
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.07, -0.15);
    glVertex2f(-0.07, -0.2);
    glVertex2f(0.07, -0.2);
    glVertex2f(0.07, -0.15);
    glEnd();
    glPopMatrix();
    glPushMatrix();//회사 간판 겉선
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

    glPushMatrix();//회사 지붕
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.3);
    glVertex2f(-0.22, 0.35);
    glVertex2f(0.22, 0.35);
    glVertex2f(0.22, 0.3);
    glEnd();
    glPopMatrix();
    glPushMatrix();//회사 지붕 겉선
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

    glPushMatrix();//회사 유리1
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

    glPushMatrix();//회사 유리1.1
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

    glPushMatrix();//회사 유리1.2
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

    glPushMatrix();//회사 유리1.3
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
    glColor3f(0.0, 0.7, 0.9); //몸통
    glutSolidSphere(0.1, 20, 20);
    glEnd();

    glPushMatrix(); //머리
    glScalef(0.8, 1.5, 1.0);
    glTranslatef(-0.14, 0.0 + h_Move * 0.001, 0);
    glColor3f(0.0, 0.0, 0.88);
    glutSolidSphere(0.04, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //눈(흰)
    glTranslatef(-0.13, 0.01 + h_Move * 0.001 * 0.001, 0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(0.01, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //눈(검)
    glTranslatef(-0.135, 0.01 + h_Move * 0.001, 0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.005, 20, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //부리
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

    glPushMatrix(); //꼬리
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

    glPushMatrix(); //날개
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
    //머리
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.2, 20, 20);
    glEnd();

    //볼1(오른)
    glPushMatrix();
    glTranslatef(0.12, -0.14, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.07, 20, 20);
    glEnd();
    glPopMatrix();

    //볼(왼)
    glPushMatrix();
    glTranslatef(-0.12, -0.14, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.07, 20, 20);
    glEnd();
    glPopMatrix();

    //뼈(우상)
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

    //뼈(우하)
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

    //뼈(좌상)
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

    //뼈(좌하)
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

    //눈(왼)
    glPushMatrix();
    glTranslatef(-0.07, -0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.05, 20, 20);
    glEnd();
    glPopMatrix();

    //눈(오른)
    glPushMatrix();
    glTranslatef(0.07, -0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.05, 20, 20);
    glEnd();
    glPopMatrix();

    //코
    glPushMatrix();
    glScalef(0.8, 1.5, 1.0);
    glTranslatef(-0.00, -0.06, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.02, 20, 20);
    glEnd();
    glPopMatrix();

    //이빨
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
    glColor3f(0.0, 0.0, 0.0); //이빨 표시
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

    glPushMatrix(); //낙엽
    glScalef(1.0, 0.5, 1.0);
    glTranslatef(-0.5, 2.22, 0);
    glColor3f(0.00, 1.00, 0.00);
    glutSolidSphere(0.07, 20, 20);
    glEnd();
    glPopMatrix();

    /*glPushMatrix(); //낙엽 표시
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

    //벽1
    glPushMatrix();
    //glTranslatef(1.5 - h_Delta * 0.004, 0, 0.0);  //배경
    glTranslatef(3.0, 0.0, 0);
    glRotatef(180, 0, 1, 0);
    glTranslatef(-1, 0.0, 0);
    h_Wall();
    glPopMatrix();
    //벽2
    glPushMatrix();
    glTranslatef(0.6, 0.0, 0);
    h_Wall();
    glPopMatrix();
    //선
}

void h_elevatorOpen() {
    if (Delta < 3930) {
        elevator1();
    }
}

void h_backGround1() {

    glPushMatrix();
    glTranslatef(4.5 - h_Delta * 0.006, 0, 0.0);  //배경
    glColor3f(0.0 - h_Delta * 0.0007, 0.8 - h_Delta * 0.0007, 0.8 - h_Delta * 0.0007);
    glBegin(GL_POLYGON);
    glVertex2f(-2.50, -0.5);
    glVertex2f(-2.50, 0.67);
    glVertex2f(5.0, 0.67);
    glVertex2f(5.0, -0.5);
    glEnd();

    glPushMatrix();
    glColor3f(0.7, 1, 0.6);  // 회사 (내부 )
    glBegin(GL_POLYGON);
    glVertex2f(-6.50, -0.5);
    glVertex2f(-6.50, 0.5);
    glVertex2f(-3.0, 0.5);
    glVertex2f(-3.0, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);  // 회사 (아래 배경 )
    glBegin(GL_POLYGON);
    glVertex2f(-6.50, -0.67);
    glVertex2f(-6.50, -0.5);
    glVertex2f(-3.0, -0.5);
    glVertex2f(-3.0, -0.67);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6, 0.75, 0.95);  // 회사 (윗 배경 )
    glBegin(GL_POLYGON);
    glVertex2f(-6.50, 0.5);
    glVertex2f(-6.50, 0.67);
    glVertex2f(-3.0, 0.67);
    glVertex2f(-3.0, 0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); // 윗 겉선
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-9.5, 0.5);
    glVertex2f(-2.5, 0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); // 아래 겉선
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-10.5, -0.5);
    glVertex2f(20.0, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);  // 바닥
    glBegin(GL_POLYGON);
    glVertex2f(-3.0, -0.67);
    glVertex2f(-3.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, -0.67);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, -0.5);
    glVertex2f(20.0, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.3, 0.1); // 배경(집안)
    glBegin(GL_QUADS);
    glVertex2f(1.2, -0.5); // 좌측 하단
    glVertex2f(3.5, -0.5);  // 우측 하단
    glVertex2f(3.5, 0.67);   // 우측 하단 (밑면)
    glVertex2f(1.2, 0.67);  // 좌측 하단 (밑면)
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9); // 바닥(집안)
    glBegin(GL_QUADS);
    glVertex2f(1.2, -0.5); // 좌측 하단
    glVertex2f(3.5, -0.5);  // 우측 하단
    glVertex2f(3.5, -0.67);   // 우측 하단 (밑면)
    glVertex2f(1.2, -0.67);  // 좌측 하단 (밑면)
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, -0.5);
    glVertex2f(20.0, -0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.25, 0.175, 0.1); // 배경색(눈옴)
    glBegin(GL_QUADS);
    glVertex2f(3.5, -0.5); // 좌측 하단
    glVertex2f(20.0, -0.5);  // 우측 하단
    glVertex2f(20.0, -0.67);   // 우측 하단 (밑면)
    glVertex2f(3.5, -0.67);  // 좌측 하단 (밑면)
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1, 0.1, 0.3); // 흙색(눈옴)
    glBegin(GL_POLYGON);
    glVertex2f(3.5, -0.5); // 좌측 하단
    glVertex2f(3.5, 0.67);  // 우측 하단
    glVertex2f(20.0, 0.67);   // 우측 하단 (밑면)
    glVertex2f(20.0, -0.5);  // 좌측 하단 (밑면)
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //겉선
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, -0.5);
    glVertex2f(20.0, -0.5);
    glEnd();
    glPopMatrix();

    //물체들

    // 엘베문 (동철)
    glPushMatrix();
    glTranslatef(-4.9, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    h_elevatorIn();
    h_elevatorOpen();
    glPopMatrix();

    // 넘어가는 문1
    glPushMatrix();
    glTranslatef(-3.5, 0.0, 1);
    glScalef(1.0, 1.0, 0);
    glRotatef(180, 0, 1, 0);
    Entrance();
    glPopMatrix();


    //티비
    glPushMatrix();
    glTranslatef(-4.2, -0.4, 0);
    Tv();
    glPopMatrix();

    //커피머신
    glPushMatrix();
    glTranslatef(-3.6, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    coffee();
    glPopMatrix();

    //병원
    glPushMatrix();
    glTranslatef(0.5, 0.65, 0);
    glScalef(2.3, 2.3, 0);
    Hospital();
    glPopMatrix();

    //박스
    glPushMatrix();
    glTranslatef(2.5, 0.0, 0);
    h_Box();
    glPopMatrix();
    //콘센트
    glPushMatrix();
    glTranslatef(3.2, -0.3, 0);
    Carge();
    glPopMatrix();

    //구름 1
    glPushMatrix();
    glTranslatef(0.2, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //구름 2
    glPushMatrix();
    glTranslatef(-0.35, -0.05, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //구름 3
    glPushMatrix();
    glTranslatef(4.2, -0.05, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //구름 4
    glPushMatrix();
    glTranslatef(4.75, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //구름 5
    glPushMatrix();
    glTranslatef(5.25, -0.05, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //구름 6
    glPushMatrix();
    glTranslatef(6.15, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    Cloud();
    glPopMatrix();
    //나무
    glPushMatrix();
    glTranslatef(5.8, -0.5, 0);
    glScalef(0.5, 0.5, 1);
    Tree();
    glPopMatrix();
    //회사
    glPushMatrix();
    glTranslatef(-2.0, -0.08, 0);
    glScalef(1.4, 1.4, 0);
    Hotel();
    glPopMatrix();
    //집
    glPushMatrix();
    glTranslatef(0.3, -0.5, 0);
    glScalef(1.5, 1.5, 0);
    Home();
    glPopMatrix();
    //티비
    glPushMatrix();
    glTranslatef(2.0, -0.4, 0);
    Tv();
    glPopMatrix();
    //사진1
    glPushMatrix();
    glTranslatef(1.8, 0.4, 0);
    Picture1();
    glPopMatrix();
    //사진2
    glPushMatrix();
    glTranslatef(3, 0.4, 0);
    glScalef(1.5, 1.5, 0);
    Picture2();
    glPopMatrix();
    //사진3
    glPushMatrix();
    glTranslatef(2.6, -0.0, 0);
    glScalef(1.0, 1.0, 0);
    Picture3();
    glPopMatrix();
    //새
    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(-1.0 - h_Delta * 0.002, 0.75 + h_Delta * 0.0001, 0);
    Bird();
    glPopMatrix();
    //새2
    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(1.0 - h_Delta * 0.002, 0.5 + h_Delta * 0.0001, 0);
    Bird();
    glPopMatrix();
    //마지막 해
    glPushMatrix();
    glTranslatef(5.0, 0.0, 0);
    glScalef(1.0, 1.0, 0);
    Sun();
    glPopMatrix();
    // 관 안
    glPushMatrix();
    glTranslatef(5.0, 0, 0.0);
    Death2();
    glPopMatrix();
    //관 뚜껑
    glPushMatrix();
    glTranslatef(4.7 + h_a, 0, 0);
    Death();
    glPopMatrix();


    //사람
    if (h_Delta > 3 && h_Delta < 1610) {
        glPushMatrix();
        glTranslatef(-4.3 + h_Delta * 0.0062, 0.003 * h_Move, 0);
        h_charater();
        glPushMatrix(); //오른다리 흔들기
        glRotatef(0.1 * h_Move, 0, 0, 1);
        h_leftleg();
        glPopMatrix();

        glPushMatrix(); //왼다리 흔들기
        glRotatef(0.1 * -h_Move, 0, 0, 1);
        h_rightleg();
        glPopMatrix();

        glPushMatrix(); //팔 뒷짐
        glRotatef(0, 0, 0, 1);
        h_rightarm();
        glPopMatrix();

        glPushMatrix(); //팔 흔들기
        glRotatef(0.1 * h_Move, 0, 0, 1);
        h_leftarm();
        glPopMatrix();
        glPopMatrix();
    }
    // 넘어가는 문2
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

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 화면 지우기
    glClearColor(0.1f, 0.1f, 0.3f, 1.0f); // RGB 값
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


//------ 22124769 권동철 ---------------------------------------------------------

void window() {
    //창문 배경
    glTranslatef(0, -0.1, 0.0);
    glColor3f(0, 0.5, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.4);
    glVertex2f(0.3, -0.4);
    glVertex2f(-0.3, -0.4);
    glVertex2f(-0.3, 0.4);
    glEnd();
    //창문위
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
    //창문 중간
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
    //창문 왼쪽
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
    //창문 오른쪽
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

    //건물 1번
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

    //건물 1번 창문
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

    //건물 2번 창문
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

    //건물 3번 창문
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

    //건물 4번 창문
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

    //건물 5번 창문
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

    //건물 6번 창문
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

    //건물 7번 창문
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

    //건물 2번
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

    //건물 2번 창문 1번
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

    //건물 2번 창문 2번
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

    //건물 2번 창문 3번
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

    //건물 2번 창문 4번
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

    //건물 2번 창문 5번
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

    //건물 2번 창문 6번
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

    //건물 3번
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

    //건물 3번 창문 1번
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

    //건물 3번 창문 2번
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

    //건물 3번 창문 3번
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

    //건물 3번 창문 4번
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


    //하늘
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

    //구름안에 점들 1번
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

    //구름안에 점들 2번
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

    //구름안에 점들 3번
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

    //구름안에 점들 4번
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

    //구름안에 점들 5번
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

    //구름안에 점들 6번
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

    //구름안에 점들 7번
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

    //구름안에 점들 8번
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

    //구름안에 점들 9번
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
    //창문 배경
    glTranslatef(0, -0.1, 0.0);
    glColor3f(0, 0.5, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.4);
    glVertex2f(0.3, -0.4);
    glVertex2f(-0.3, -0.4);
    glVertex2f(-0.3, 0.4);
    glEnd();
    //창문위
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
    //창문 중간
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
    //창문 왼쪽
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
    //창문 오른쪽
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

    //건물 1번
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

    //건물 1번 창문
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

    //건물 2번 창문
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

    //건물 3번 창문
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

    //건물 4번 창문
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

    //건물 5번 창문
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

    //건물 6번 창문
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

    //건물 7번 창문
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

    //건물 2번
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

    //건물 2번 창문 1번
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

    //건물 2번 창문 2번
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

    //건물 2번 창문 3번
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

    //건물 2번 창문 4번
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

    //건물 2번 창문 5번
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

    //건물 2번 창문 6번
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

    //건물 3번
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

    //건물 3번 창문 1번
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

    //건물 3번 창문 2번
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

    //건물 3번 창문 3번
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

    //건물 3번 창문 4번
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


    //하늘
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

    //구름안에 점들 1번
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

    //구름안에 점들 2번
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

    //구름안에 점들 3번
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

    //구름안에 점들 4번
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

    //구름안에 점들 5번
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

    //구름안에 점들 6번
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

    //구름안에 점들 7번
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

    //구름안에 점들 8번
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

    //구름안에 점들 9번
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
    //컴퓨터 부스
    glTranslatef(0, 0, 0);
    glColor3f(0.5, 0.6, 0.65);
    glBegin(GL_POLYGON);
    glVertex2f(-0.24, -0.5);
    glVertex2f(-0.24, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.24, -0.5);
    glEnd();

    //컴퓨터 부스 오른쪽 색 다르게 해야됨 (!)
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


    //컴퓨터 부스 왼쪽 테두리
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

    //컴퓨터 부스 오른쪽 테두리
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

    //컴퓨터 부스 위쪽 테두리
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

    //컴퓨터 부스 중간 테두리
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

    //컴퓨터 메모 (흰색)
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

    //컴퓨터 메모 (노란색)
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

    //컴퓨터 테이블 왼쪽 밝은 부분
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

    //컴퓨터 테이블 오른쪽 어두운 부분
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

    //컴퓨터 모니터 지탱하는 하단부
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

    //컴퓨터 모니터 지탱하는 하단부(중앙)
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

    //컴퓨터 모니터
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

    //컴퓨터 모니터 속 화면
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

    //컴퓨터 모니터 속 화면 프로그램들 1번
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

    //컴퓨터 모니터 속 화면 프로그램들 2번
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


    //컴퓨터 모니터 속 화면 프로그램들 3번
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


    //컴퓨터 모니터 옆 메모
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
    //의자 등판
    glTranslatef(0, 0, 0);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-0.13, -0.32);
    glVertex2f(-0.13, -0.1);
    glVertex2f(0, -0.1);
    glVertex2f(0, -0.32);
    glEnd();
    //의자 등판 오른쪽 테두리
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

    //의자 머리받침 오른쪽 받침
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

    //의자 머리받침 왼쪽 받침
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

    //의자 머리 받침대
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

    //의자 머리 받침대 음영표현
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

    //의자 팔받이 1번
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

    //의자 팔받이 2번
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

    //의자 쿠션
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

    //의자 바퀴 연결부분
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

    //의자 밑에 기둥
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

    //의자 바퀴 연결 위에 부분
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

    //바퀴 왼쪽
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

    //바퀴 중간
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

    //바퀴 오른쪽
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

    //자판기 경계 테두리
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

    //자판기 커피모양 사각형
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

    //자판기 커피모양 사각형
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

    //커피모양
    glPushMatrix();
    glTranslatef(0.05, -0.05, 0);
    glColor3f(0.8, 0.8, 0.8);
    glutSolidTeapot(0.05);
    glEnd();
    glPopMatrix();

    //커피모양 테두리 1 (위)
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

    //커피모양 테두리 2 (아래)
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

    //커피모양 테두리 3 (왼)
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

    //커피모양 테두리 4 (오)
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

    //자판기 밑에 버튼 (빨간색)
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

    //자판기 밑에 버튼(노란색)
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

    //자판기 흰색 버튼 (위쪽 1)
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

    //자판기 흰색 버튼 (위쪽 2)
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

    //자판기 흰색 버튼 (위쪽 3)
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

    //자판기 흰색 버튼 (위쪽 4)
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

    //자판기 흰색 버튼 (위쪽 5)
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

    //자판기 흰색 버튼 (위쪽 6)
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

    //자판기 흰색 버튼 (아래 1)
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

    //자판기 흰색 버튼 (아래 2)
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

    //자판기 흰색 버튼 (아래 3)
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

    //자판기 흰색 버튼 (아래 4)
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

    //자판기 흰색 버튼 (아래 5)
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

    //자판기 흰색 버튼 (아래 6)
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

    //커피입구
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

    //커피입구에 커피
    glPushMatrix();
    glTranslatef(0.05, -0.4, 0);
    glColor3f(0.8, 0.8, 0.8);
    glutSolidTeapot(0.02);
    glEnd();
    glPopMatrix();

    //자판기 위에 테두리
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

    //자판기 밑 테두리
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

    //자판기 왼쪽 테두리
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

    //자판기 오른쪽 테두리
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

    //자판기 경계 테두리
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

    //자판기 커피모양 사각형
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

    //커피모양
    glPushMatrix();
    glTranslatef(0.05, -0.05, 0);
    glColor3f(0.1, 0.1, 0.9);
    glutSolidTeapot(0.05);
    glEnd();
    glPopMatrix();

    //커피모양 테두리 1 (위)
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

    //커피모양 테두리 2 (아래)
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

    //커피모양 테두리 3 (왼)
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

    //커피모양 테두리 4 (오)
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

    //자판기 밑에 버튼 (빨간색)
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

    //자판기 밑에 버튼(노란색)
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

    //자판기 흰색 버튼 (위쪽 1)
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

    //자판기 흰색 버튼 (위쪽 2)
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

    //자판기 흰색 버튼 (위쪽 3)
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

    //자판기 흰색 버튼 (위쪽 4)
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

    //자판기 흰색 버튼 (위쪽 5)
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

    //자판기 흰색 버튼 (위쪽 6)
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

    //자판기 흰색 버튼 (아래 1)
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

    //자판기 흰색 버튼 (아래 2)
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

    //자판기 흰색 버튼 (아래 3)
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

    //자판기 흰색 버튼 (아래 4)
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

    //자판기 흰색 버튼 (아래 5)
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

    //자판기 흰색 버튼 (아래 6)
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

    //커피입구
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

    //커피입구에 커피
    glPushMatrix();
    glTranslatef(0.05, -0.4, 0);
    glColor3f(0.1, 0.1, 0.9);
    glutSolidTeapot(0.02);
    glEnd();
    glPopMatrix();

    //자판기 위에 테두리
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

    //자판기 밑 테두리
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

    //자판기 왼쪽 테두리
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

    //자판기 오른쪽 테두리
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
    //미팅룸 전체 배경
    glTranslatef(0, 0.0, 0.0);
    glColor3f(0.3, 0.4, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.67);
    glVertex2f(-0.7, 0.5);
    glVertex2f(0.7, 0.5);
    glVertex2f(0.7, -0.5);
    glEnd();

    //빔프로젝트
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.35, -0.275);
    glVertex2f(-0.35, 0.3);
    glVertex2f(0.525, 0.3);
    glVertex2f(0.525, -0.275);
    glEnd();
    glPopMatrix();

    //빔프로젝트 위쪽 테두리
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.35, 0.3);
    glVertex2f(-0.35, 0.285);
    glVertex2f(0.525, 0.285);
    glVertex2f(0.525, 0.3);
    glEnd();
    glPopMatrix();

    //빔프로젝트 오른쪽 테두리
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0.525, -0.275);
    glVertex2f(0.525, 0.3);
    glVertex2f(0.535, 0.3);
    glVertex2f(0.535, -0.275);
    glEnd();
    glPopMatrix();

    //미팅룸 바닥
    glPushMatrix();
    glColor3f(0.7, 0.6, 0.55);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.67);
    glVertex2f(-0.7, -0.5);
    glVertex2f(0.7, -0.5);
    glVertex2f(0.7, -0.67);
    glEnd();
    glPopMatrix();

    //미팅룸 바닥테두리
    glPushMatrix();
    glColor3f(0.6, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.51);
    glVertex2f(-0.7, -0.5);
    glVertex2f(0.7, -0.5);
    glVertex2f(0.7, -0.51);
    glEnd();
    glPopMatrix();

    //미팅룸 왼쪽테두리
    glPushMatrix();
    glColor3f(0.6, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.5);
    glVertex2f(-0.7, 0.5);
    glVertex2f(-0.69, 0.5);
    glVertex2f(-0.69, -0.5);
    glEnd();
    glPopMatrix();

    //미팅룸 오른쪽테두리
    glPushMatrix();
    glColor3f(0.6, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.69, -0.5);
    glVertex2f(0.69, 0.5);
    glVertex2f(0.7, 0.5);
    glVertex2f(0.7, -0.5);
    glEnd();
    glPopMatrix();

    //미팅룸 위쪽테두리
    glPushMatrix();
    glColor3f(0.6, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, 0.49);
    glVertex2f(-0.7, 0.5);
    glVertex2f(0.7, 0.5);
    glVertex2f(0.7, 0.49);
    glEnd();
    glPopMatrix();

    //미팅룸 중앙 테이블
    glPushMatrix();
    glColor3f(0.4, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.55);
    glVertex2f(-0.5, -0.3);
    glVertex2f(0.1, -0.3);
    glVertex2f(0.1, -0.55);
    glEnd();
    glPopMatrix();

    //미팅룸 중앙 테이블(안에 그림자)
    glPushMatrix();
    glColor3f(0.25, 0.15, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.48, -0.55);
    glVertex2f(-0.48, -0.32);
    glVertex2f(0.08, -0.32);
    glVertex2f(0.08, -0.55);
    glEnd();
    glPopMatrix();

    //미팅룸 중앙 테이블(오른쪽)
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

    //발표대
    glPushMatrix();
    glColor3f(0.4, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.55);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.55);
    glEnd();
    glPopMatrix();

    //발표대 윗부분
    glPushMatrix();
    glColor3f(0.4, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.4, -0.25);
    glVertex2f(0.55, -0.25);
    glVertex2f(0.55, -0.3);
    glEnd();
    glPopMatrix();

    //발표대 윗부분(음영)
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.25);
    glVertex2f(0.6, -0.275);
    glVertex2f(0.6, -0.3);
    glEnd();
    glPopMatrix();

    //발표대(음영)
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.55, -0.55);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.6, -0.55);
    glEnd();
    glPopMatrix();

    //발표대 (음영) 1
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.42, -0.55);
    glVertex2f(0.42, -0.29);
    glVertex2f(0.43, -0.29);
    glVertex2f(0.43, -0.55);
    glEnd();
    glPopMatrix();

    //발표대 (음영) 2
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.52, -0.55);
    glVertex2f(0.52, -0.29);
    glVertex2f(0.53, -0.29);
    glVertex2f(0.53, -0.55);
    glEnd();
    glPopMatrix();

    //발표대 (음영) 3
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.29);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.29);
    glEnd();
    glPopMatrix();

    //발표대 (음영) 4
    glPushMatrix();
    glColor3f(0.3, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.4, -0.31);
    glVertex2f(0.6, -0.31);
    glVertex2f(0.6, -0.3);
    glEnd();
    glPopMatrix();

    //발표대 노트북
    glPushMatrix();
    glColor3f(0.66, 0.66, 0.66);
    glBegin(GL_POLYGON);
    glVertex2f(0.43, -0.25);
    glVertex2f(0.41, -0.2);
    glVertex2f(0.51, -0.2);
    glVertex2f(0.53, -0.25);
    glEnd();
    glPopMatrix();

    //발표대 노트북(음영)
    glPushMatrix();
    glColor3f(0.77, 0.77, 0.77);
    glBegin(GL_POLYGON);
    glVertex2f(0.53, -0.25);
    glVertex2f(0.51, -0.2);
    glVertex2f(0.52, -0.2);
    glVertex2f(0.54, -0.25);
    glEnd();
    glPopMatrix();

    //발표대 마이크
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.54, -0.25);
    glVertex2f(0.54, -0.22);
    glVertex2f(0.55, -0.22);
    glVertex2f(0.55, -0.25);
    glEnd();
    glPopMatrix();

    //발표대 마이크
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

    //발표대 마이크
    glPushMatrix();
    glTranslatef(0.57, -0.215, 0);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.3, 0.3, 0.1);
    glutSolidSphere(0.03, 50, 10);
    glEnd();
    glPopMatrix();




}
//현수가 쓰는 엘베

//마지막 현수네 스테이지로 넘어갈때 쓸 엘리베이터 문
void elevator() {
    glTranslatef(0, 0, 0);
    glColor3f(0.5, 0.6, 0.65);
    glBegin(GL_POLYGON);
    glVertex2f(-0.24, -0.5);
    glVertex2f(-0.24, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.24, -0.5);
    glEnd();

    //컴퓨터 부스 왼쪽 테두리
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

    //컴퓨터 부스 오른쪽 테두리
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

    //컴퓨터 부스 위쪽 테두리
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

    //컴퓨터 부스 중간 테두리
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

    //엘베 위 전광판
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

    //엘베 위 전광판 안 숫자
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

    //엘베 위 전광판 안 숫자
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

    //엘베 위 전광판 안 숫자
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

    //엘베 위 전광판 안 숫자
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

    //엘베 위 전광판 안 숫자
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

    //하얀 배경
    glTranslatef(0, 0, 0);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.24, -0.5);
    glVertex2f(-0.24, 0.1);
    glVertex2f(0.24, 0.1);
    glVertex2f(0.24, -0.5);
    glEnd();

    //안쪽 회색 벽
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

    //아래 바닥
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

    //위
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

    //엘베 안 유리
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

    //엘베 왼쪽 테두리
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

    //컴퓨터 부스 오른쪽 테두리
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

    //컴퓨터 부스 위쪽 테두리
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

    //엘베 위 전광판
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

    //엘베 위 전광판 안 숫자
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

    //엘베 위 전광판 안 숫자
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

    //엘베 위 전광판 안 숫자
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

    //엘베 위 전광판 안 숫자
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

    //엘베 위 전광판 안 숫자
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

    //오른쪽벽 음영

    //왼쪽 밝은색 벽
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-1, -0.5);
    glVertex2f(-1, 0.67);
    glVertex2f(-0.95, 0.67);
    glVertex2f(-0.95, -0.5);
    glEnd();
    glPopMatrix();

    //안쪽 입구
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, -0.5);
    glVertex2f(-0.95, 0.05);
    glVertex2f(-0.75, 0);
    glVertex2f(-0.75, -0.5);
    glEnd();
    glPopMatrix();

    //출입문
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

    //출입문 위쪽 테두리 (어두운색)
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-1.1, 0);
    glVertex2f(-1.1, 0.02);
    glVertex2f(-0.9, 0.02);
    glVertex2f(-0.9, 0);
    glEnd();
    glPopMatrix();

    //출입문 위쪽 테두리 (밝은색)
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-1.09, 0);
    glVertex2f(-1.09, 0.012);
    glVertex2f(-0.9, 0.012);
    glVertex2f(-0.9, 0);
    glEnd();
    glPopMatrix();


    //출입문 아래쪽 테두리 (밝은색)
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-1.1, -0.5);
    glVertex2f(-1.1, -0.45);
    glVertex2f(-0.9, -0.45);
    glVertex2f(-0.9, -0.5);
    glEnd();
    glPopMatrix();

    //출입문 아래쪽 테두리 (어두운색)
    glPushMatrix();
    glColor3f(0.55, 0.6, 0.65);
    glBegin(GL_POLYGON);
    glVertex2f(-1.09, -0.5);
    glVertex2f(-1.09, -0.46);
    glVertex2f(-0.9, -0.46);
    glVertex2f(-0.9, -0.5);
    glEnd();
    glPopMatrix();

    //출입문 오른쪽 테두리
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9, 0);
    glVertex2f(-0.9, -0.5);
    glVertex2f(-0.91, -0.5);
    glVertex2f(-0.91, 0);
    glEnd();
    glPopMatrix();

    //출입문 손잡이 (밝은색)
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-1.08, -0.3);
    glVertex2f(-1.08, -0.2);
    glVertex2f(-1.06, -0.2);
    glVertex2f(-1.06, -0.3);
    glEnd();
    glPopMatrix();

    //출입문 손잡이 (어두운색)
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
    //오른쪽벽 음영
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.67);
    glVertex2f(-0.7, 0.67);
    glVertex2f(-0.5, 0.67);
    glVertex2f(-0.5, -0.67);
    glEnd();

    //오른쪽 밝은색벽
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.75, -0.67);
    glVertex2f(-0.75, 0.67);
    glVertex2f(-0.7, 0.67);
    glVertex2f(-0.7, -0.67);
    glEnd();
    glPopMatrix();

    //위쪽 창문
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

    //위쪽 창문 테두리 왼
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.25);
    glVertex2f(-0.95, 0.45);
    glVertex2f(-0.91, 0.445);
    glVertex2f(-0.91, 0.24);
    glEnd();
    glPopMatrix();

    //위쪽 창문 테두리 오
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.77, 0.21);
    glVertex2f(-0.77, 0.415);
    glVertex2f(-0.75, 0.41);
    glVertex2f(-0.75, 0.205);
    glEnd();
    glPopMatrix();

    //위쪽 창문 테두리 밑
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.91, 0.24);
    glVertex2f(-0.91, 0.26);
    glVertex2f(-0.75, 0.22);
    glVertex2f(-0.75, 0.195);
    glEnd();
    glPopMatrix();

    //위쪽 밝은색 벽
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.45);
    glVertex2f(-0.95, 0.67);
    glVertex2f(-0.75, 0.67);
    glVertex2f(-0.75, 0.41);
    glEnd();
    glPopMatrix();

    //위쪽 밝은색 벽
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

//닫히고 열릴때 쓸거
void EntranceOut1() {
    glPushMatrix();
    glTranslatef(0, 0, 0);
    //오른쪽벽 음영
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.67);
    glVertex2f(-0.7, 0.67);
    glVertex2f(-0.5, 0.67);
    glVertex2f(-0.5, -0.67);
    glEnd();

    //오른쪽 밝은색벽
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.75, -0.67);
    glVertex2f(-0.75, 0.67);
    glVertex2f(-0.7, 0.67);
    glVertex2f(-0.7, -0.67);
    glEnd();
    glPopMatrix();

    //위쪽 창문
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

    //위쪽 창문 테두리 왼
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.25);
    glVertex2f(-0.95, 0.45);
    glVertex2f(-0.91, 0.445);
    glVertex2f(-0.91, 0.24);
    glEnd();
    glPopMatrix();

    //위쪽 창문 테두리 오
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.77, 0.21);
    glVertex2f(-0.77, 0.415);
    glVertex2f(-0.75, 0.41);
    glVertex2f(-0.75, 0.205);
    glEnd();
    glPopMatrix();

    //위쪽 창문 테두리 밑
    glPushMatrix();
    glColor3f(0.5, 0.55, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.91, 0.24);
    glVertex2f(-0.91, 0.26);
    glVertex2f(-0.75, 0.22);
    glVertex2f(-0.75, 0.195);
    glEnd();
    glPopMatrix();

    //위쪽 밝은색 벽
    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, 0.45);
    glVertex2f(-0.95, 0.67);
    glVertex2f(-0.75, 0.67);
    glVertex2f(-0.75, 0.41);
    glEnd();
    glPopMatrix();

    //위쪽 밝은색 벽
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
    // 문 전체 (갈색)
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-1.5, -0.5);
    glVertex2f(-1.5, 0.2);
    glVertex2f(-1.0, 0.2);
    glVertex2f(-1.0, -0.5);

    // 문 왼쪽 테두리 (짙은갈색)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.5, -0.5);
    glVertex2f(-1.5, 0.2);
    glVertex2f(-1.49, 0.2);
    glVertex2f(-1.49, -0.5);

    // 문 오른쪽 테두리 (짙은갈색)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.99, -0.5);
    glVertex2f(-0.99, 0.2);
    glVertex2f(-1.0, 0.2);
    glVertex2f(-1.0, -0.5);

    // 문 창문 아래 테두리 (짙은갈색)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, -0.25);
    glVertex2f(-1.45, -0.26);
    glVertex2f(-1.05, -0.26);
    glVertex2f(-1.05, -0.25);

    // 문 창문 위 테두리 (짙은갈색)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, 0.15);
    glVertex2f(-1.45, 0.14);
    glVertex2f(-1.05, 0.14);
    glVertex2f(-1.05, 0.15);

    // 문 창문 아래 손잡이 (짙은갈색)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, -0.35);
    glVertex2f(-1.45, -0.27);
    glVertex2f(-1.43, -0.27);
    glVertex2f(-1.43, -0.35);

    //문 창문
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, -0.23);
    glVertex2f(-1.45, 0.13);
    glVertex2f(-1.05, 0.13);
    glVertex2f(-1.05, -0.23);

    //문 창문 음영 (왼쪽)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, -0.23);
    glVertex2f(-1.45, 0.13);
    glVertex2f(-1.43, 0.13);
    glVertex2f(-1.43, -0.23);

    //문 창문 음영 (오른쪽)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.05, -0.23);
    glVertex2f(-1.05, 0.13);
    glVertex2f(-1.07, 0.13);
    glVertex2f(-1.07, -0.23);

    //문 창문 음영 (위)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, 0.13);
    glVertex2f(-1.45, 0.12);
    glVertex2f(-1.05, 0.12);
    glVertex2f(-1.05, 0.13);

    //문 창문 음영 (아래)
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.45, -0.23);
    glVertex2f(-1.45, -0.22);
    glVertex2f(-1.05, -0.22);
    glVertex2f(-1.05, -0.23);
    glEnd();

    //문 옆 창문 두개 (갈색 배경)
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, -0.25);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, -0.25);
    glEnd();
    glPopMatrix();

    //문 옆 창문
    glPushMatrix();
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-0.76, -0.22);
    glVertex2f(-0.76, 0.17);
    glVertex2f(-0.24, 0.17);
    glVertex2f(-0.24, -0.22);
    glEnd();
    glPopMatrix();

    //문 옆 창문 왼쪽 음영
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.77, -0.22);
    glVertex2f(-0.77, 0.17);
    glVertex2f(-0.755, 0.17);
    glVertex2f(-0.755, -0.22);
    glEnd();
    glPopMatrix();

    //왼쪽 창문 위쪽 음영
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.77, 0.17);
    glVertex2f(-0.77, 0.18);
    glVertex2f(-0.52, 0.18);
    glVertex2f(-0.52, 0.17);
    glEnd();
    glPopMatrix();

    //왼쪽 창문 아래쪽 음영
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.77, -0.22);
    glVertex2f(-0.77, -0.23);
    glVertex2f(-0.52, -0.23);
    glVertex2f(-0.52, -0.22);
    glEnd();
    glPopMatrix();

    //왼쪽 창문 오른쪽 음영
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.535, -0.22);
    glVertex2f(-0.535, 0.17);
    glVertex2f(-0.52, 0.17);
    glVertex2f(-0.52, -0.22);
    glEnd();
    glPopMatrix();

    //오른쪽 창문 왼쪽 음영
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.47, -0.22);
    glVertex2f(-0.47, 0.17);
    glVertex2f(-0.455, 0.17);
    glVertex2f(-0.455, -0.22);
    glEnd();
    glPopMatrix();

    //오른쪽 창문 오른쪽 음영
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.225, -0.22);
    glVertex2f(-0.225, 0.17);
    glVertex2f(-0.24, 0.17);
    glVertex2f(-0.24, -0.22);
    glEnd();
    glPopMatrix();

    //오른쪽 창문 아래쪽 음영
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.47, -0.22);
    glVertex2f(-0.47, -0.23);
    glVertex2f(-0.225, -0.23);
    glVertex2f(-0.225, -0.22);
    glEnd();
    glPopMatrix();

    //오른쪽 창문 위쪽 음영
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.47, 0.17);
    glVertex2f(-0.47, 0.18);
    glVertex2f(-0.225, 0.18);
    glVertex2f(-0.225, 0.17);
    glEnd();
    glPopMatrix();

    //문 옆 창문 두개 중간 두꺼운 테두리
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.52, -0.25);
    glVertex2f(-0.52, 0.2);
    glVertex2f(-0.47, 0.2);
    glVertex2f(-0.47, -0.25);
    glEnd();
    glPopMatrix();

    //오른쪽 창문 왼쪽 자물쇠
    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(-0.455, -0.05);
    glVertex2f(-0.455, 0);
    glVertex2f(-0.435, 0);
    glVertex2f(-0.435, -0.05);
    glEnd();
    glPopMatrix();

    //오른쪽 창문 자물쇠
    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(-0.455, -0.0);
    glVertex2f(-0.455, -0.035);
    glVertex2f(-0.425, -0.035);
    glVertex2f(-0.425, -0.0);
    glEnd();
    glPopMatrix();

    //오른쪽 창문 자물쇠 테두리
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.455, -0.0);
    glVertex2f(-0.455, -0.01);
    glVertex2f(-0.425, -0.01);
    glVertex2f(-0.425, -0.0);
    glEnd();
    glPopMatrix();

    //오른쪽 창문 자물쇠 테두리
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.455, -0.05);
    glVertex2f(-0.455, -0.04);
    glVertex2f(-0.435, -0.04);
    glVertex2f(-0.435, -0.05);
    glEnd();
    glPopMatrix();

    //오른쪽 창문 자물쇠 테두리
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.435, -0.04);
    glVertex2f(-0.435, -0.03);
    glVertex2f(-0.425, -0.03);
    glVertex2f(-0.425, -0.04);
    glEnd();
    glPopMatrix();

    //오른쪽 창문 자물쇠 테두리
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.43, -0.04);
    glVertex2f(-0.43, -0);
    glVertex2f(-0.42, -0);
    glVertex2f(-0.42, -0.04);
    glEnd();
    glPopMatrix();

    //테이블
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, -0.275);
    glVertex2f(-0.8, -0.5);
    glVertex2f(-0.2, -0.5);
    glVertex2f(-0.2, -0.275);
    glEnd();
    glPopMatrix();

    //테이블 위에 선 (위)
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.82, -0.28);
    glVertex2f(-0.82, -0.27);
    glVertex2f(-0.18, -0.27);
    glVertex2f(-0.18, -0.28);
    glEnd();
    glPopMatrix();

    //테이블 위에 갈색선 (아래)
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.815, -0.28);
    glVertex2f(-0.815, -0.29);
    glVertex2f(-0.185, -0.29);
    glVertex2f(-0.185, -0.28);
    glEnd();
    glPopMatrix();

    //테이블 테두리 (왼)
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.79, -0.3);
    glVertex2f(-0.79, -0.49);
    glVertex2f(-0.78, -0.49);
    glVertex2f(-0.78, -0.3);
    glEnd();
    glPopMatrix();

    //테이블 테두리 (오)
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.22, -0.3);
    glVertex2f(-0.22, -0.49);
    glVertex2f(-0.21, -0.49);
    glVertex2f(-0.21, -0.3);
    glEnd();
    glPopMatrix();

    //테이블 테두리 (위)
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.79, -0.31);
    glVertex2f(-0.79, -0.3);
    glVertex2f(-0.21, -0.3);
    glVertex2f(-0.21, -0.31);
    glEnd();
    glPopMatrix();

    //테이블 테두리 (아래)
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.79, -0.49);
    glVertex2f(-0.79, -0.48);
    glVertex2f(-0.21, -0.48);
    glVertex2f(-0.21, -0.49);
    glEnd();
    glPopMatrix();

    //테이블 중간 선
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.505, -0.3);
    glVertex2f(-0.505, -0.48);
    glVertex2f(-0.485, -0.48);
    glVertex2f(-0.485, -0.3);
    glEnd();
    glPopMatrix();

    //테이블 손잡이 (왼)
    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_QUADS);
    glVertex2f(-0.53, -0.375);
    glVertex2f(-0.53, -0.425);
    glVertex2f(-0.515, -0.425);
    glVertex2f(-0.515, -0.375);
    glEnd();
    glPopMatrix();

    //테이블 손잡이 (왼)아래음영
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-0.53, -0.425);
    glVertex2f(-0.53, -0.435);
    glVertex2f(-0.515, -0.435);
    glVertex2f(-0.515, -0.425);
    glEnd();
    glPopMatrix();

    //테이블 손잡이 (왼)위음영
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-0.53, -0.365);
    glVertex2f(-0.53, -0.375);
    glVertex2f(-0.515, -0.375);
    glVertex2f(-0.515, -0.365);
    glEnd();
    glPopMatrix();

    //테이블 손잡이 (오)
    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_QUADS);
    glVertex2f(-0.475, -0.375);
    glVertex2f(-0.475, -0.425);
    glVertex2f(-0.46, -0.425);
    glVertex2f(-0.46, -0.375);
    glEnd();
    glPopMatrix();

    //테이블 손잡이 (오)아래음영
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-0.475, -0.425);
    glVertex2f(-0.475, -0.435);
    glVertex2f(-0.46, -0.435);
    glVertex2f(-0.46, -0.425);
    glEnd();
    glPopMatrix();

    //테이블 손잡이 (오)위음영
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-0.475, -0.365);
    glVertex2f(-0.475, -0.375);
    glVertex2f(-0.46, -0.375);
    glVertex2f(-0.46, -0.365);
    glEnd();
    glPopMatrix();

    //위쪽 창문 (갈색배경)
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-1.5, 0.22);
    glVertex2f(-1.5, 0.48);
    glVertex2f(-0.2, 0.48);
    glVertex2f(-0.2, 0.22);
    glEnd();
    glPopMatrix();

    //위쪽 창문 (갈색배경)
    glPushMatrix();
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-1.5, 0.21);
    glVertex2f(-1.5, 0.48);
    glVertex2f(-0.2, 0.48);
    glVertex2f(-0.2, 0.21);
    glEnd();
    glPopMatrix();

    //위쪽 창문 1번
    glPushMatrix();
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-1.48, 0.23);
    glVertex2f(-1.48, 0.46);
    glVertex2f(-1.18, 0.46);
    glVertex2f(-1.18, 0.23);
    glEnd();
    glPopMatrix();

    //창문 1번 테두리 왼
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.48, 0.23);
    glVertex2f(-1.48, 0.46);
    glVertex2f(-1.47, 0.46);
    glVertex2f(-1.47, 0.23);
    glEnd();
    glPopMatrix();

    //창문 1번 테두리 오
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.19, 0.23);
    glVertex2f(-1.19, 0.46);
    glVertex2f(-1.18, 0.46);
    glVertex2f(-1.18, 0.23);
    glEnd();
    glPopMatrix();

    //창문 1번 테두리 아래
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.48, 0.23);
    glVertex2f(-1.48, 0.24);
    glVertex2f(-1.18, 0.24);
    glVertex2f(-1.18, 0.23);
    glEnd();
    glPopMatrix();

    //창문 1번 테두리 위
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.48, 0.45);
    glVertex2f(-1.48, 0.46);
    glVertex2f(-1.18, 0.46);
    glVertex2f(-1.18, 0.45);
    glEnd();
    glPopMatrix();

    //위쪽 창문 2번
    glPushMatrix();
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-1.16, 0.23);
    glVertex2f(-1.16, 0.46);
    glVertex2f(-0.86, 0.46);
    glVertex2f(-0.86, 0.23);
    glEnd();
    glPopMatrix();

    //창문 2번 테두리 왼
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.16, 0.23);
    glVertex2f(-1.16, 0.46);
    glVertex2f(-1.15, 0.46);
    glVertex2f(-1.15, 0.23);
    glEnd();
    glPopMatrix();

    //창문 2번 테두리 오
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85, 0.23);
    glVertex2f(-0.85, 0.46);
    glVertex2f(-0.86, 0.46);
    glVertex2f(-0.86, 0.23);
    glEnd();
    glPopMatrix();

    //창문 2번 테두리 아래
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.16, 0.23);
    glVertex2f(-1.16, 0.24);
    glVertex2f(-0.86, 0.24);
    glVertex2f(-0.86, 0.23);
    glEnd();
    glPopMatrix();

    //창문 2번 테두리 위
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.16, 0.45);
    glVertex2f(-1.16, 0.46);
    glVertex2f(-0.86, 0.46);
    glVertex2f(-0.86, 0.45);
    glEnd();
    glPopMatrix();

    //위쪽 창문 3번
    glPushMatrix();
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-0.84, 0.23);
    glVertex2f(-0.84, 0.46);
    glVertex2f(-0.54, 0.46);
    glVertex2f(-0.54, 0.23);
    glEnd();
    glPopMatrix();

    //창문 3번 테두리 왼
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.84, 0.23);
    glVertex2f(-0.84, 0.46);
    glVertex2f(-0.83, 0.46);
    glVertex2f(-0.83, 0.23);
    glEnd();
    glPopMatrix();

    //창문 3번 테두리 오
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.53, 0.23);
    glVertex2f(-0.53, 0.46);
    glVertex2f(-0.54, 0.46);
    glVertex2f(-0.54, 0.23);
    glEnd();
    glPopMatrix();

    //창문 3번 테두리 아래
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.84, 0.23);
    glVertex2f(-0.84, 0.24);
    glVertex2f(-0.54, 0.24);
    glVertex2f(-0.54, 0.23);
    glEnd();
    glPopMatrix();

    //창문 3번 테두리 위
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.84, 0.45);
    glVertex2f(-0.84, 0.46);
    glVertex2f(-0.54, 0.46);
    glVertex2f(-0.54, 0.45);
    glEnd();
    glPopMatrix();

    //위쪽 창문 4번
    glPushMatrix();
    glColor3f(0.65, 0.75, 0.85);
    glBegin(GL_QUADS);
    glVertex2f(-0.52, 0.23);
    glVertex2f(-0.52, 0.46);
    glVertex2f(-0.22, 0.46);
    glVertex2f(-0.22, 0.23);
    glEnd();
    glPopMatrix();

    //창문 4번 테두리 왼
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.52, 0.23);
    glVertex2f(-0.52, 0.46);
    glVertex2f(-0.51, 0.46);
    glVertex2f(-0.51, 0.23);
    glEnd();
    glPopMatrix();

    //창문 4번 테두리 오
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.21, 0.23);
    glVertex2f(-0.21, 0.46);
    glVertex2f(-0.22, 0.46);
    glVertex2f(-0.22, 0.23);
    glEnd();
    glPopMatrix();

    //창문 4번 테두리 아래
    glPushMatrix();
    glColor3f(0.5, 0.2, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.52, 0.23);
    glVertex2f(-0.52, 0.24);
    glVertex2f(-0.22, 0.24);
    glVertex2f(-0.22, 0.23);
    glEnd();
    glPopMatrix();

    //창문 4번 테두리 위
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
    //발표대
    glPushMatrix();
    glColor3f(0.4, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.55);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.55);
    glEnd();
    glPopMatrix();

    //발표대 윗부분
    glPushMatrix();
    glColor3f(0.4, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.4, -0.25);
    glVertex2f(0.55, -0.25);
    glVertex2f(0.55, -0.3);
    glEnd();
    glPopMatrix();

    //발표대 윗부분(음영)
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.25);
    glVertex2f(0.6, -0.275);
    glVertex2f(0.6, -0.3);
    glEnd();
    glPopMatrix();

    //발표대(음영)
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.55, -0.55);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.6, -0.55);
    glEnd();
    glPopMatrix();

    //발표대 (음영) 1
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.42, -0.55);
    glVertex2f(0.42, -0.29);
    glVertex2f(0.43, -0.29);
    glVertex2f(0.43, -0.55);
    glEnd();
    glPopMatrix();

    //발표대 (음영) 2
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.52, -0.55);
    glVertex2f(0.52, -0.29);
    glVertex2f(0.53, -0.29);
    glVertex2f(0.53, -0.55);
    glEnd();
    glPopMatrix();

    //발표대 (음영) 3
    glPushMatrix();
    glColor3f(0.35, 0.25, 0.25);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.29);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.55, -0.3);
    glVertex2f(0.55, -0.29);
    glEnd();
    glPopMatrix();

    //발표대 (음영) 4
    glPushMatrix();
    glColor3f(0.3, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.3);
    glVertex2f(0.4, -0.31);
    glVertex2f(0.6, -0.31);
    glVertex2f(0.6, -0.3);
    glEnd();
    glPopMatrix();

    //발표대 노트북
    glPushMatrix();
    glColor3f(0.66, 0.66, 0.66);
    glBegin(GL_POLYGON);
    glVertex2f(0.43, -0.25);
    glVertex2f(0.41, -0.2);
    glVertex2f(0.51, -0.2);
    glVertex2f(0.53, -0.25);
    glEnd();
    glPopMatrix();

    //발표대 노트북(음영)
    glPushMatrix();
    glColor3f(0.77, 0.77, 0.77);
    glBegin(GL_POLYGON);
    glVertex2f(0.53, -0.25);
    glVertex2f(0.51, -0.2);
    glVertex2f(0.52, -0.2);
    glVertex2f(0.54, -0.25);
    glEnd();
    glPopMatrix();

    //발표대 마이크
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.54, -0.25);
    glVertex2f(0.54, -0.22);
    glVertex2f(0.55, -0.22);
    glVertex2f(0.55, -0.25);
    glEnd();
    glPopMatrix();

    //발표대 마이크
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

    //발표대 마이크
    glPushMatrix();
    glTranslatef(0.57, -0.215, 0);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.3, 0.3, 0.1);
    glutSolidSphere(0.03, 50, 10);
    glEnd();
    glPopMatrix();
}

void classroom() {
    //바닥
    glColor3f(0.65, 0.5, 0.39);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.67);
    glVertex2f(-0.7, -0.5);
    glVertex2f(1.3, -0.5);
    glVertex2f(1.3, -0.67);
    glEnd();

    //바닥 - 중간 테두리
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.5);
    glVertex2f(-0.7, -0.51);
    glVertex2f(1.3, -0.51);
    glVertex2f(1.3, -0.5);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.62);
    glVertex2f(-0.7, -0.63);
    glVertex2f(1.3, -0.63);
    glVertex2f(1, -0.62);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.57);
    glVertex2f(-0.7, -0.56);
    glVertex2f(0.7, -0.56);
    glVertex2f(0.7, -0.57);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.56);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.51, -0.5);
    glVertex2f(-0.51, -0.56);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0, -0.56);
    glVertex2f(0, -0.5);
    glVertex2f(0.01, -0.5);
    glVertex2f(0.01, -0.56);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.56);
    glVertex2f(0.4, -0.5);
    glVertex2f(0.41, -0.5);
    glVertex2f(0.41, -0.56);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.4, -0.56);
    glVertex2f(0.4, -0.5);
    glVertex2f(0.41, -0.5);
    glVertex2f(0.41, -0.56);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.6, -0.62);
    glVertex2f(0.6, -0.56);
    glVertex2f(0.61, -0.56);
    glVertex2f(0.61, -0.62);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.3, -0.62);
    glVertex2f(0.3, -0.56);
    glVertex2f(0.31, -0.56);
    glVertex2f(0.31, -0.62);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, -0.62);
    glVertex2f(-0.3, -0.56);
    glVertex2f(-0.31, -0.56);
    glVertex2f(-0.31, -0.62);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.65, -0.62);
    glVertex2f(-0.65, -0.56);
    glVertex2f(-0.66, -0.56);
    glVertex2f(-0.66, -0.62);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(-0.44, -0.63);
    glVertex2f(-0.44, -0.67);
    glVertex2f(-0.45, -0.67);
    glVertex2f(-0.45, -0.63);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, -0.63);
    glVertex2f(0.15, -0.67);
    glVertex2f(0.16, -0.67);
    glVertex2f(0.16, -0.63);
    glEnd();

    //바닥 무늬들
    glColor3f(0.4, 0.26, 0.15);
    glBegin(GL_POLYGON);
    glVertex2f(0.47, -0.63);
    glVertex2f(0.47, -0.67);
    glVertex2f(0.48, -0.67);
    glVertex2f(0.48, -0.63);
    glEnd();

    //중간 (칠판)
    glColor3f(0, 0.3, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.3);
    glVertex2f(0.5, 0.3);
    glVertex2f(0.5, -0.2);
    glEnd();

    //중간 (칠판) 왼쪽
    glColor3f(0, 0.5, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.3);
    glVertex2f(-0.25, 0.3);
    glVertex2f(-0.25, -0.2);
    glEnd();

    //중간 (칠판) 왼쪽 메모 1
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.47, -0.1);
    glVertex2f(-0.47, 0);
    glVertex2f(-0.3, 0);
    glVertex2f(-0.3, -0.1);
    glEnd();

    //중간 (칠판) 왼쪽 메모 2
    glColor3f(0.9, 0.9, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.1);
    glVertex2f(-0.3, 0.03);
    glVertex2f(-0.37, 0.03);
    glVertex2f(-0.37, 0.1);
    glEnd();

    //중간 (칠판) 오른쪽
    glColor3f(0, 0.5, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.29, -0.2);
    glVertex2f(0.29, 0.3);
    glVertex2f(0.5, 0.3);
    glVertex2f(0.5, -0.2);
    glEnd();

    //중간 (칠판) 오른쪽 메모 1
    glColor3f(0.9, 0.9, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.33, 0.1);
    glVertex2f(0.33, 0.2);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.4, 0.1);
    glEnd();

    //중간 (칠판) 오른쪽 메모 2
    glColor3f(0.9, 0.9, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.36, -0.1);
    glVertex2f(0.36, -0.02);
    glVertex2f(0.43, -0.02);
    glVertex2f(0.43, -0.1);
    glEnd();

    //중간 테두리 (왼)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.3);
    glVertex2f(-0.52, 0.3);
    glVertex2f(-0.52, -0.2);
    glEnd();

    //중간 테두리 (오)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(0.48, -0.2);
    glVertex2f(0.48, 0.3);
    glVertex2f(0.5, 0.3);
    glVertex2f(0.5, -0.2);
    glEnd();

    //중간 테두리 (오른쪽 음영)
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.5, -0.22);
    glVertex2f(0.5, 0.32);
    glVertex2f(0.52, 0.32);
    glVertex2f(0.52, -0.22);
    glEnd();

    //중간 테두리 (위)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52, 0.3);
    glVertex2f(-0.52, 0.32);
    glVertex2f(0.5, 0.32);
    glVertex2f(0.5, 0.3);
    glEnd();

    //중간 테두리 (아래)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52, -0.22);
    glVertex2f(-0.52, -0.2);
    glVertex2f(0.5, -0.2);
    glVertex2f(0.5, -0.22);
    glEnd();

    //왼쪽 - 중간 테두리 (칠판 안)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, -0.2);
    glVertex2f(-0.25, 0.3);
    glVertex2f(-0.27, 0.3);
    glVertex2f(-0.27, -0.2);
    glEnd();

    //왼쪽 - 중간 테두리 음영(칠판 안)
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, -0.2);
    glVertex2f(-0.25, 0.3);
    glVertex2f(-0.23, 0.3);
    glVertex2f(-0.23, -0.2);
    glEnd();

    //중간 - 오른쪽 테두리 (칠판 안)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(0.25, -0.2);
    glVertex2f(0.25, 0.3);
    glVertex2f(0.27, 0.3);
    glVertex2f(0.27, -0.2);
    glEnd();

    //중간 - 오른쪽 테두리 음영(칠판 안)
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.27, -0.2);
    glVertex2f(0.27, 0.3);
    glVertex2f(0.29, 0.3);
    glVertex2f(0.29, -0.2);
    glEnd();

    //칠판 밑 음영
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

    //티비
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_POLYGON);
    glVertex2f(-0.65, 0.1);
    glVertex2f(-0.65, 0.4);
    glVertex2f(-0.15, 0.4);
    glVertex2f(-0.15, 0.1);
    glEnd();

    //티비 위 연결
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.41, 0.4);
    glVertex2f(-0.41, 0.5);
    glVertex2f(-0.38, 0.5);
    glVertex2f(-0.38, 0.4);
    glEnd();

    //티비 안 화면
    glColor3f(0, 0.1, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-0.625, 0.125);
    glVertex2f(-0.625, 0.3725);
    glVertex2f(-0.1725, 0.3725);
    glVertex2f(-0.1725, 0.125);
    glEnd();

    //티비 안 화면
    glColor3f(0, 0.2, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(-0.615, 0.135);
    glVertex2f(-0.615, 0.3625);
    glVertex2f(-0.475, 0.3625);
    glVertex2f(-0.275, 0.135);
    glEnd();

}

// 배경에 친구
void backcharater() {

    //몸통
    glTranslatef(-0.5, -0.25, 0);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(1, 1.7, 0.1);
    glutSolidSphere(0.1, 20, 10);
    glEnd();

    //교복넥타이 1
    glPushMatrix();
    glTranslatef(-0.12, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, 0.02);
    glVertex2f(0.14, 0.02);
    glEnd();
    glPopMatrix();

    //교복넥타이 2
    glPushMatrix();
    glTranslatef(-0.12, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //교복넥타이 3
    glPushMatrix();
    glTranslatef(-0.12, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.12, -0.06);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //명찰
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

    //명찰 안 이름
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

    //머리
    glPushMatrix();
    glTranslatef(0, 0.1, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();


    //눈 (흰색 배경)
    glPushMatrix();
    glTranslatef(-0.03, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();

    //눈 (흰색 배경)
    glPushMatrix();
    glTranslatef(0.02, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();


    //눈알 (검정)
    glPushMatrix();
    glTranslatef(-0.03, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //눈알 (검정)
    glPushMatrix();
    glTranslatef(0.02, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //입 (빨강)
    glPushMatrix();
    glTranslatef(0, 0.05, 0.0);
    glColor3f(0.8, 0.1, 0.1);
    glutSolidSphere(0.02, 30, 20);
    glEnd();
    glPopMatrix();
}

void backleftarm() {

    //왼쪽 팔 아랫부분
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
    //오른쪽팔 아랫부분
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
    //왼쪽 다리 윗부분
    glPushMatrix();
    glTranslatef(-0.55, -0.45, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.3, 1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //왼쪽 신발
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
    //오른쪽 다리 윗부분
    glPushMatrix();
    glTranslatef(-0.45, -0.45, 0.0);
    glRotatef(0, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.3, 1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //오른쪽 신발
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
    glPushMatrix();//엘베뒷부분
    glColor3f(0.9, 0.9, 0.5); // 회색
    glBegin(GL_POLYGON);
    glVertex2f(5.0, 0.67);
    glVertex2f(5.0, -0.67);
    glVertex2f(10.0, -0.67);
    glVertex2f(10.0, 0.67);
    glEnd();
    glPopMatrix();

    //학교 바닥
    glColor3f(0.75, 0.65, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5);
    glVertex2f(-1.0, -0.67);
    glVertex2f(-7.0, -0.67);
    glVertex2f(-7.0, -0.5);

    //학교
    //바닥 - 중간 화면 테두리
    glPushMatrix();
    glColor3f(0.5, 0.3, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.51);
    glVertex2f(-1.0, -0.5);
    glVertex2f(-7.0, -0.5);
    glVertex2f(-7.0, -0.51);  // 좌측 하단 (밑면)
    glPopMatrix();

    //학교 중간
    glPushMatrix(); //중간
    glColor3f(0.85, 0.85, 0.85); //
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5); // 좌측 하단
    glVertex2f(-1.0, 0.5);
    glVertex2f(-7.0, 0.5);
    glVertex2f(-7.0, -0.5);  // 좌측 하단 (밑면)
    glPopMatrix();

    //학교
    //중간 - 위 화면 테두리
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.1); // 회색
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, 0.49); // 좌측 하단
    glVertex2f(-1.0, 0.5);
    glVertex2f(-7.0, 0.5);
    glVertex2f(-7.0, 0.49);  // 좌측 하단 (밑면)
    glPopMatrix();

    //학교 위
    glPushMatrix(); // 위
    glColor3f(0.4, 0.4, 0.4); //
    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.5); // 좌측 하단
    glVertex2f(-1.0, 0.67);
    glVertex2f(-7.0, 0.67);
    glVertex2f(-7.0, 0.5);  // 좌측 하단 (밑면)
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

    //회사 바닥
    glColor3f(0.5, 0.55, 0.6); // 회색
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5); // 좌측 하단
    glVertex2f(-1.0, -0.67);
    glVertex2f(5.0, -0.67);
    glVertex2f(5.0, -0.5);  // 좌측 하단 (밑면)

    //바닥 - 중간 화면 테두리
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3); // 회색
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.51); // 좌측 하단
    glVertex2f(-1.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, -0.51);  // 좌측 하단 (밑면)
    glPopMatrix();

    glPushMatrix(); //중간
    glColor3f(0.7, 1, 0.6); //
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5); // 좌측 하단
    glVertex2f(-1.0, 0.5);
    glVertex2f(5.0, 0.5);
    glVertex2f(5.0, -0.5);  // 좌측 하단 (밑면)
    glPopMatrix();

    //중간 - 위 화면 테두리
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1); // 회색
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, 0.49); // 좌측 하단
    glVertex2f(-1.0, 0.5);
    glVertex2f(5.0, 0.5);
    glVertex2f(5.0, 0.49);  // 좌측 하단 (밑면)
    glPopMatrix();

    glPushMatrix(); // 위
    glColor3f(0.6, 0.75, 0.95); //
    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.5); // 좌측 하단
    glVertex2f(-1.0, 0.67);
    glVertex2f(5.0, 0.67);
    glVertex2f(5.0, 0.5);  // 좌측 하단 (밑면)
    glPopMatrix();
    glEnd();

    //회사
    glPushMatrix();//창문
    glTranslatef(0, 0, 0.0);
    window();
    glPopMatrix();

    glPushMatrix();//창문
    glTranslatef(1, 0, 0.0);
    window();
    glPopMatrix();

    glPushMatrix();//창문
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
    //몸통
    glTranslatef(-0.5, -0.25, 0);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(1, 1.7, 0.1);
    glutSolidSphere(0.1, 20, 10);
    glEnd();

    //정장넥타이 1
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, 0.02);
    glVertex2f(0.14, 0.02);
    glEnd();
    glPopMatrix();

    //정장넥타이 2
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //정장넥타이 3
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.12, -0.06);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //머리
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.1, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();


    //눈 (흰색 배경)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();

    //눈 (흰색 배경)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();


    //눈알 (검정)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //눈알 (검정)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();


    //머리카락
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //머리카락
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //머리카락
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.0305, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.035, 0);
    glEnd();
    glPopMatrix();

    //입 (빨강)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.06, 0.05, 0.0);
    glColor3f(0.8, 0.1, 0.1);
    glutSolidSphere(0.02, 30, 20);
    glEnd();
    glPopMatrix();

    //입 (안)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.055, 0.05, 0.0);
    glColor3f(0.8, 0.3, 0);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();
}

void leftarm1() {
    //왼쪽 팔 윗부분
    glPushMatrix();
    glTranslatef(-0.05, 0, 0.0);
    glRotatef(330, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.25, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //왼쪽 팔 아랫부분
    glPushMatrix();
    glTranslatef(-0.055, -0.05, 0.0);
    glRotatef(40, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.4, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //왼손
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

    //오른쪽팔 윗부분
    glPushMatrix();
    glTranslatef(0.1, -0.01, 0.0);
    glRotatef(30, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.25, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //오른쪽팔 아랫부분
    glPushMatrix();
    glTranslatef(0.14, -0.05, 0.0);
    glRotatef(70, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //오른손
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
    //왼쪽 다리 윗부분
    glPushMatrix();
    glTranslatef(-0.02, -0.1, 0.0);
    glRotatef(25, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.3, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //왼쪽 다리 아랫부분
    glPushMatrix();
    glTranslatef(-0.02, -0.15, 0.0);
    glRotatef(150, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.2, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //왼쪽 신발
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
    //오른쪽 다리 윗부분
    glPushMatrix();
    glTranslatef(0.05, -0.1, 0.0);
    glRotatef(30, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.3, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //오른쪽 다리 윗부분
    glPushMatrix();
    glTranslatef(0.04, -0.15, 0.0);
    glRotatef(120, 0, 0, 1);
    glColor3f(0.6, 0.6, 0.7);
    glScalef(0.15, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //오른쪽 신발
    glPushMatrix();
    glTranslatef(0.02, -0.175, 0.0);
    glRotatef(350, 0, 0, 1);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.25, 0.1, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

}

// 캐릭터
void charater() {

    //몸통
    glTranslatef(-0.5, -0.25, 0);
    glColor3f(0, 0, 0.5);
    glScalef(1, 1.7, 0.1);
    glutSolidSphere(0.1, 20, 10);
    glEnd();

    //정장넥타이 1
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, 0.02);
    glVertex2f(0.14, 0.02);
    glEnd();
    glPopMatrix();

    //정장넥타이 2
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //정장넥타이 3
    glPushMatrix();
    glTranslatef(-0.09, 0.01, 0.0);
    glColor3f(0.1, 0.1, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.12, -0.06);
    glVertex2f(0.14, -0.03);
    glEnd();
    glPopMatrix();

    //머리
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.1, 0.0);
    glColor3f(0.87, 0.68, 0.55);
    glutSolidSphere(0.07, 30, 30);
    glEnd();
    glPopMatrix();


    //눈 (흰색 배경)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();

    //눈 (흰색 배경)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glutSolidSphere(0.015, 30, 20);
    glEnd();
    glPopMatrix();


    //눈알 (검정)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.05, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();

    //눈알 (검정)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.08, 0.1, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();


    //머리카락
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //머리카락
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.03, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0.02, 0.03, 0);
    glEnd();
    glPopMatrix();

    //머리카락
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.0305, 0.17, 0.0);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.035, 0);
    glEnd();
    glPopMatrix();

    //입 (빨강)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.06, 0.05, 0.0);
    glColor3f(0.8, 0.1, 0.1);
    glutSolidSphere(0.02, 30, 20);
    glEnd();
    glPopMatrix();

    //입 (안)
    glPushMatrix();
    glRotatef(Move, 0, 0, 1);
    glTranslatef(0.055, 0.05, 0.0);
    glColor3f(0.8, 0.3, 0);
    glutSolidSphere(0.01, 30, 20);
    glEnd();
    glPopMatrix();
}

void leftarm() {
    //왼쪽 팔 윗부분
    glPushMatrix();
    glTranslatef(-0.05, 0, 0.0);
    glRotatef(330, 0, 0, 1);
    glColor3f(0, 0, 0.7);
    glScalef(0.25, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //왼쪽 팔 아랫부분
    glPushMatrix();
    glTranslatef(-0.055, -0.05, 0.0);
    glRotatef(40, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.4, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //왼손
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

    //오른쪽팔 윗부분
    glPushMatrix();
    glTranslatef(0.1, -0.01, 0.0);
    glRotatef(30, 0, 0, 1);
    glColor3f(0, 0, 0.7);
    glScalef(0.25, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //오른쪽팔 아랫부분
    glPushMatrix();
    glTranslatef(0.14, -0.05, 0.0);
    glRotatef(70, 0, 0, 1);
    glColor3f(0.87, 0.68, 0.55);
    glScalef(0.2, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //오른손
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
    //왼쪽 다리 윗부분
    glPushMatrix();
    glTranslatef(-0.02, -0.1, 0.0);
    glRotatef(25, 0, 0, 1);
    glColor3f(0, 0, 0.5);
    glScalef(0.3, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //왼쪽 다리 아랫부분
    glPushMatrix();
    glTranslatef(-0.02, -0.15, 0.0);
    glRotatef(150, 0, 0, 1);
    glColor3f(0, 0, 0.5);
    glScalef(0.2, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //왼쪽 신발
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
    //오른쪽 다리 윗부분
    glPushMatrix();
    glTranslatef(0.05, -0.1, 0.0);
    glRotatef(30, 0, 0, 1);
    glColor3f(0, 0, 0.5);
    glScalef(0.3, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //오른쪽 다리 윗부분
    glPushMatrix();
    glTranslatef(0.04, -0.15, 0.0);
    glRotatef(120, 0, 0, 1);
    glColor3f(0, 0, 0.5);
    glScalef(0.15, 0.5, 0.1);
    glutSolidSphere(0.1, 50, 10);
    glEnd();
    glPopMatrix();

    //오른쪽 신발
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
    //하트 모양
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

    //하트 모양
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

//------ 22125027 최강우 ---------------------------------------------------------

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
    glPushMatrix();//A블록
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

    glPushMatrix();//F블록
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

    glPushMatrix();//E블록
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
    //차체
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
    //창문
    glColor3f(0, 0, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.13);
    glVertex2f(0.01, 0.18);
    glVertex2f(0.08, 0.18);
    glVertex2f(0.08, 0.13);
    glEnd();
    //창문
    glColor3f(0, 0, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.01, 0.13);
    glVertex2f(-0.01, 0.18);
    glVertex2f(-0.08, 0.18);
    glVertex2f(-0.08, 0.13);
    glEnd();
    //라이트
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, 0.1);
    glVertex2f(0.15, 0.06);
    glVertex2f(0.18, 0.06);
    glVertex2f(0.18, 0.1);
    glEnd();
    //바퀴1
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
    //바퀴12
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
    //몸통
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
    //왼팔
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

    //오른팔
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

    //오른발
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
    //오른발
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
    //목
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
    //머리
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.5, 0.2);
    glVertex2f(0.15, 0.02);
    glVertex2f(0.15, 0.15);
    glVertex2f(-0.15, 0.15);
    glVertex2f(-0.15, 0.02);
    glEnd();
    //안테나
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.6, 0.3);
    glVertex2f(0.01, 0.2);
    glVertex2f(0.01, 0.15);
    glVertex2f(-0.01, 0.15);
    glVertex2f(-0.01, 0.2);
    glEnd();
    //안테나 꼬다리
    glPushMatrix();
    glTranslatef(0, 0.2, 0.0);
    glColor3f(0, color, 0);
    glScaled(0.8, 0.5, 0);
    glutSolidSphere(0.03, 20, 10);
    glPopMatrix();
    //입
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0, 0);
    glVertex2f(0.03, 0.03);
    glVertex2f(0.03, 0.05);
    glVertex2f(-0.03, 0.05);
    glVertex2f(-0.03, 0.03);
    glEnd();
    //눈
    glPushMatrix();
    glTranslatef(-0.07, 0.08, 0.0);
    glColor3f(color, 0, 0);
    glutSolidSphere(0.03, 20, 10);
    glPopMatrix();
    //눈
    glPushMatrix();
    glTranslatef(0.07, 0.08, 0.0);
    glColor3f(color, 0, 0);
    glutSolidSphere(0.03, 20, 10);
    glPopMatrix();

    glPopMatrix();
}

void flower() {
    glColor3f(0.6, 0.3, 0.3);//화분
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.1, 0.05);
    glEnd();

    glPushMatrix();//잎
    glTranslatef(0, 0.125, 0.0);
    glColor3f(0, 1, 0);
    glScaled(0.5, 3, 0);
    glutSolidCube(0.05);
    glPopMatrix();

    glPushMatrix();//꽃
    glTranslatef(0, 0.2, 0.0);
    glPushMatrix();//중심
    glColor3f(1, 1, 0);
    glutSolidCube(0.05);
    glPopMatrix();//중심


    glRotatef(angle, 0, 0, 1);
    glPushMatrix();//잎1
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//잎1

    glPushMatrix();//잎2
    glRotatef(90, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//잎2

    glPushMatrix();//잎3
    glRotatef(-90, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//잎3

    glPushMatrix();//잎4
    glRotatef(180, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//잎4
    glPopMatrix();//꽃

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
    glPushMatrix();//몸통
    glRotatef(10.0, 0.0, 0.0, 1);
    glPushMatrix();
    glColor3f(1, 0.72, 0.52);
    glScalef(1.3, 1, 1.0);
    glutSolidSphere(0.1, 20, 10);
    glPopMatrix();

    glPushMatrix();//기저귀
    glRotatef(90.0, 0.0, 0.0, 1);
    glColor3f(0.9, 0.9, 0.9);
    glScalef(0.1, 0.13, 1.0);
    drawHalfSphere();
    glPopMatrix();
    glPopMatrix();//몸통

    glPushMatrix();//팔1
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
    glPopMatrix();//팔1

    glPushMatrix();//팔2
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
    glPopMatrix();//팔2

    glPushMatrix();//다리1
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
    glPopMatrix();//다리1

    glPushMatrix();//기저귀
    glRotatef(90.0, 0.0, 0.0, 1);
    glColor3f(0.9, 0.9, 0.9);
    glScalef(0.1, 0.13, 1.0);
    drawHalfSphere();
    glPopMatrix();

    glPushMatrix();//다리2
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
    glPopMatrix();//다리2

    glPushMatrix();//머리
    glTranslatef(0.15, 0.1, 0.0);
    glRotatef(-sww * 0.3, 0.0, 0.0, 1);
    glColor3f(1, 0.72, 0.52);
    glutSolidSphere(0.1, 20, 10);

    glPushMatrix();//머리카락
    glTranslatef(0, 0.1, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.05, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//공갈
    glTranslatef(0.072, -0.052, 0.0);
    glColor3f(1, 0.68, 0);
    glutSolidSphere(0.025, 20, 10);

    glTranslatef(0.021, -0.01, 0.0);
    glColor3f(1, 0.68, 0);
    glutSolidSphere(0.018, 20, 10);
    glPopMatrix();

    glPushMatrix();//눈
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
    glPushMatrix();//몸통
    glTranslatef(0.02, 0.0, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1);
    glPushMatrix();
    glColor3f(0, 0.2, 0.5);
    glScalef(0.4, 0.3, 1.0);
    glutSolidSphere(0.3, 20, 10);
    glPopMatrix();

    glPushMatrix();//바지
    glRotatef(90.0, 0.0, 0.0, 1);
    glColor3f(0.9, 0.9, 0.9);
    glScalef(0.5, 0.5, 1.0);
    glPopMatrix();
    glPopMatrix();//몸통

    glPushMatrix();//팔1
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
    glPopMatrix();//팔1

    glPushMatrix();//팔2
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
    glPopMatrix();//팔2

    glPushMatrix();//다리1
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
    glPopMatrix();//다리1

    glPushMatrix();//다리2
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
    glPopMatrix();//다리2

    glPushMatrix();//머리
    glRotatef(-sww * 0.1, 0.0, 0.0, 1);
    glScalef(0.95, 0.95, 1.0);
    glTranslatef(0.05, 0.2, 0.0);
    glColor3f(1, 0.72, 0.52);
    glutSolidSphere(0.1, 20, 10);

    glPushMatrix();//머리카락
    glTranslatef(0, 0.1, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.05, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//머리카락
    glTranslatef(0, 0.1, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0.02, 0.05, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//입
    glTranslatef(0.072, -0.052, 0.0);
    glColor3f(1, 0.1, 0.1);
    glScaled(0.8, 1, 1);
    glutSolidSphere(0.018, 20, 10);
    glPopMatrix();

    glPushMatrix();//눈
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
    glPushMatrix();//몸통
    glRotatef(10.0, 0.0, 0.0, 1);
    glPushMatrix();
    glColor3f(1, 0.72, 0.52);
    glScalef(1.3, 1, 1.0);
    glutSolidSphere(0.1, 20, 10);
    glPopMatrix();

    glPushMatrix();//기저귀
    glRotatef(90.0, 0.0, 0.0, 1);
    glColor3f(0.9, 0.9, 0.9);
    glScalef(0.1, 0.13, 1.0);
    drawHalfSphere();
    glPopMatrix();
    glPopMatrix();//몸통

    glPushMatrix();//팔1
    glPushMatrix();
    glTranslatef(0.1, -0.06, 0.0);
    glColor3f(1, 0.72, 0.52);
    glScalef(0.5, 1, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();

    glTranslatef(0.1, -0.11, 0.0);
    glScalef(0.5, 0.5, 1.0);
    glutSolidSphere(0.05, 20, 10);
    glPopMatrix();//팔1

    glPushMatrix();//팔2
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
    glPopMatrix();//팔2

    glPushMatrix();//다리1
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
    glPopMatrix();//다리1

    glPushMatrix();//다리2
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
    glPopMatrix();//다리2

    glPushMatrix();//머리
    glTranslatef(0.15, 0.1, 0.0);
    glRotatef(0, 0.0, 0.0, 1);
    glColor3f(1, 0.72, 0.52);
    glutSolidSphere(0.1, 20, 10);

    glPushMatrix();//머리카락
    glTranslatef(0, 0.1, 0.0);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.02, 0.05, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//공갈
    glTranslatef(0.072, -0.052, 0.0);
    glColor3f(1, 0.68, 0);
    glutSolidSphere(0.025, 20, 10);

    glTranslatef(0.021, -0.01, 0.0);
    glColor3f(1, 0.68, 0);
    glutSolidSphere(0.018, 20, 10);
    glPopMatrix();

    glPushMatrix();//눈
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
    glColor3f(0.6, 0.3, 0.3);//화분
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.05);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.1, 0.05);
    glEnd();

    glPushMatrix();//잎
    glTranslatef(0, 0.125, 0.0);
    glColor3f(0, 1, 0);
    glScaled(0.5, 3, 0);
    glutSolidCube(0.05);
    glPopMatrix();

    glPushMatrix();//꽃
    glTranslatef(0, 0.2, 0.0);
    glPushMatrix();//중심
    glColor3f(1, 1, 0);
    glutSolidCube(0.05);
    glPopMatrix();//중심

    glRotatef(45, 0, 0, 1);
    glPushMatrix();//잎1
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//잎1

    glPushMatrix();//잎2
    glRotatef(90, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//잎2

    glPushMatrix();//잎3
    glRotatef(-90, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//잎3

    glPushMatrix();//잎4
    glRotatef(180, 0, 0, 1);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0.07, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.04, 0.03);
    glVertex2f(0.02, -0.03);
    glVertex2f(-0.02, -0.03);
    glVertex2f(-0.04, 0.03);
    glEnd();
    glPopMatrix();//잎4
    glPopMatrix();//꽃
}

void photo() {
    //액자
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
    //바닥
    glColor3f(0.7, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.2, -0.15);
    glVertex2f(-0.2, -0.15);
    glVertex2f(-0.2, -0.1);
    glEnd();
    //꽃
    glPushMatrix();
    glTranslatef(0.12, -0.07, 0);
    glScalef(0.4, 0.4, 0);
    photoflower();
    glPopMatrix();
    //애기
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
    glColor3f(0.5, 0.3, 0); // 바닥
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
    glColor3f(1, 0.8, 4); // 바닥
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

    glColor3f(0.45, 0.25, 0); //선반 배경
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.2, 0.1);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, -0.1);
    glEnd();

    glPushMatrix();
    glColor3f(0.0, 0.15, 0); //선반 안1
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, -0.025);
    glVertex2f(-0.15, -0.075);
    glVertex2f(0.15, -0.075);
    glVertex2f(0.15, -0.025);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.15, 0); //선반 안2
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, 0.025);
    glVertex2f(-0.15, 0.075);
    glVertex2f(0.15, 0.075);
    glVertex2f(0.15, 0.025);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);//티비 틀
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, 0.1);
    glVertex2f(-0.25, 0.4);
    glVertex2f(0.25, 0.4);
    glVertex2f(0.25, 0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);//티비 화면
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.15);
    glVertex2f(-0.2, 0.35);
    glVertex2f(0.2, 0.35);
    glVertex2f(0.2, 0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); //손잡이
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
    glPushMatrix();//벽지
    glTranslatef(-0.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//벽지
    glTranslatef(0, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//벽지
    glTranslatef(0.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//벽지
    glTranslatef(1, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//벽지
    glTranslatef(1.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//벽지
    glTranslatef(2, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//벽지
    glTranslatef(2.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//벽지
    glTranslatef(3, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//벽지
    glTranslatef(3.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//벽지
    glTranslatef(4, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//벽지
    glTranslatef(4.5, 0, 0.0);
    wallline();
    glPopMatrix();

    glPushMatrix();//벽지
    glTranslatef(5, 0, 0.0);
    wallline();
    glPopMatrix();
}

void background() {
    glColor3f(0.8, 0.6, 0.5); //벽
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, 0.67);
    glVertex2f(-1.0, 0.67);
    glEnd();

    glPushMatrix();//벽지
    glColor3f(0.75, 0.55, 0.45);
    walllines();
    glPopMatrix();

    glPushMatrix();//창문
    glTranslatef(-0.5, 0, 0.0);
    k_window();
    glPopMatrix();

    glPushMatrix();//창문
    glTranslatef(0.8, 0, 0.0);
    k_window();
    glPopMatrix();

    glPushMatrix();//창문
    glTranslatef(2.1, 0, 0.0);
    k_window();
    glPopMatrix();

    glPushMatrix();//창문
    glTranslatef(3.4, 0, 0.0);
    k_window();
    glPopMatrix();

    glPushMatrix();//테이블
    glTranslatef(-0.3, -0.35, 0.0);
    table();
    glPopMatrix();

    glPushMatrix();//테이블
    glTranslatef(1.8, -0.35, 0.0);
    table();
    glTranslatef(0.1, 0.2, 0.0);
    glColor3f(0.5, 0.4, 0.3);
    glutSolidTeapot(0.05);
    glPopMatrix();

    glPushMatrix();//테이블
    glTranslatef(4, -0.35, 0.0);
    table();
    glPopMatrix();

    glPushMatrix();//Tv
    glTranslatef(2.7, -0.4, 0.0);
    k_Tv();
    glPopMatrix();

    glPushMatrix();//시계
    glTranslatef(0.2, 0.2, 0.0);
    clock1();
    glPopMatrix();

    glPushMatrix();//시계
    glTranslatef(2.9, 0.2, 0.0);
    clock1();
    glPopMatrix();

    glPushMatrix();//젖병
    glTranslatef(0, -0.474, 0.0);
    glRotatef(-90, 0, 0, 1);
    feeding_bottle();
    glPopMatrix();

    glPushMatrix();//젖병
    glTranslatef(3.5, -0.45, 0.0);
    feeding_bottle();
    glPopMatrix();

    glPushMatrix();//꽃
    glTranslatef(-0.3, -0.136, 0.0);
    flower();
    glPopMatrix();

    glPushMatrix();//꽃
    glTranslatef(4, -0.136, 0.0);
    flower();
    glPopMatrix();
}

void background2() {
    glColor3f(0.79, 1, 0.29); //벽지
    glBegin(GL_QUADS);
    glVertex2f(10.0, -0.5);
    glVertex2f(5.0, -0.5);
    glVertex2f(5.0, 0.67);
    glVertex2f(10.0, 0.67);
    glEnd();

    glPushMatrix();//벽지
    glTranslatef(5.8, 0, 0.0);
    glColor3f(0.74, 0.95, 0.24);
    walllines();
    glPopMatrix();

    glPushMatrix();//테이블
    glTranslatef(5.8, -0.35, 0.0);
    table2();
    glPopMatrix();


    glPushMatrix();//테이블
    glTranslatef(8.6, -0.35, 0.0);
    table2();
    glPopMatrix();

    glPushMatrix();//젖병
    glTranslatef(8.7, -0.15, 0.0);
    feeding_bottle();
    glPopMatrix();

    glPushMatrix();//로봇
    glTranslatef(7.8, -0.36, 0.0);
    glScalef(0.5, 0.5, 0);
    robot();
    glPopMatrix();

    glPushMatrix();//로봇
    glTranslatef(5.5, -0.09, 0.0);
    glRotatef(180, 0, 1, 0);
    glScalef(0.4, 0.4, 0);
    robot();
    glPopMatrix();

    glPushMatrix();//꽃
    glTranslatef(6, -0.17, 0.0);
    glScalef(0.6, 0.6, 0);
    flower();
    glPopMatrix();

    glPushMatrix();//차
    glTranslatef(5 + Delta * 0.002, -0.49, 0.0);
    glScalef(0.6, 0.6, 0);
    car();
    glPopMatrix();

    glPushMatrix();//블록
    glTranslatef(6.6, -0.48, 0.0);
    glScalef(0.4, 0.4, 0);
    bloks();
    glPopMatrix();

    glPushMatrix();//블록
    glTranslatef(9.2, -0.48, 0.0);
    glScalef(0.4, 0.4, 0);
    bloks();
    glPopMatrix();

    glPushMatrix();//액자
    glTranslatef(7.3, 0.2, 0.0);
    photo();
    glPopMatrix();

    glPushMatrix();//시계
    glTranslatef(8.8, 0.2, 0.0);
    clock2();
    glPopMatrix();
}

void kangwoo() {
    glPushMatrix();
    glTranslatef(-Delta * 0.006, 0, 0.0);
    glPushMatrix();
    floor();//바닥1
    glPopMatrix();

    glPushMatrix();
    floor2();//바닥2
    glPopMatrix();

    glPushMatrix();
    background();//배경1
    glPopMatrix();

    glPushMatrix();
    background2();//배경2
    glPopMatrix();
    glPopMatrix();



    //목숨
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
    //애기 >> 소년
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
    glPushMatrix(); //오른다리 흔들기
    glRotatef(0.1 * hun_Move, 0, 0, 1);
    h_leftleg();
    glPopMatrix();

    glPushMatrix(); //왼다리 흔들기
    glRotatef(0.1 * -hun_Move, 0, 0, 1);
    h_rightleg();
    glPopMatrix();

    glPushMatrix(); //팔 뒷짐
    glRotatef(0, 0, 0, 1);
    h_rightarm();
    glPopMatrix();

    glPushMatrix(); //팔 흔들기
    glRotatef(0.1 * hun_Move, 0, 0, 1);
    h_leftarm();
    glPopMatrix();
    glPopMatrix();
}//할아버지

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

    //동
    Move += increment;
    if (Move > 10.0f) {
        Move = 10.0f;
        increment = -1.0f;
    }
    if (Move < 0.0f) {
        Move = 0.0f;
        increment = 1.0f;
    }

    //현
    if (Delta > 3930) {
        if (stop) {
            h_a += 0.05f; // 초당 0.1씩 이동
            if (h_a >= 0.3f) {
                h_a = 0.3f; // 위치가 1을 초과하지 않도록 제한
                stop = false; // 이동 멈춤
            }
        }
        else {
            // 10초가 지나면 이동 시작
            if (h_Delta >= 1610) {
                stop = true; // 이동 시작
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
            h_angle += 0.18f; // 각도 증가
            if (h_angle >= 90.0f) {
                h_angle = 90.0f; // 각도가 90도에 도달하면 멈춤
                isAnimating = false; // 애니메이션 상태 변경
            }
            glutPostRedisplay(); // 화면 갱신
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
