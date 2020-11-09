#include <GL/glut.h>
#include <Windows.h>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 768

const int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font1 = (int)GLUT_BITMAP_HELVETICA_18;

int horizontal_index = 50;
int vertical_index = 5;
int run = 0;
int horizontal_steps = 0;
int vertical_steps = 0;
int speed = 50;
int score = 0;
int level = 1;

//Road divider 1
float road_divider1_top = 0;
float road_divider1_middle = 0;
float road_divider1_bottom = 0;

//Road divider 3
float road_divider3_top = 0;
float road_divider3_middle = 0;
float road_divider3_bottom = 0;

void drawText(float x, float y, void* font, const char* string)
{
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void drawPreCar(int x, int y)
{
    int X = x;
    int Y = y;

    //Auto alap
    glColor3f(0.5, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(X, Y);
    glVertex2f(X, Y + 12);
    glVertex2f(X + 5, Y + 12);
    glVertex2f(X + 5, Y);
    glEnd();

    //Auto szelvedo
    glColor3f(0.3, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(X + 1, Y + 8);
    glVertex2f(X + 1, Y + 11);
    glVertex2f(X + 4, Y + 11);
    glVertex2f(X + 4, Y + 8);
    glEnd();
}

void start()
{
    //Road base
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(15, 0);
    glVertex2f(15, 100);
    glVertex2f(85, 100);
    glVertex2f(85, 0);
    glEnd();

    //Road left
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(14, 0);
    glVertex2f(14, 100);
    glVertex2f(16, 100);
    glVertex2f(16, 0);
    glEnd();

    //Road right
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(84, 0);
    glVertex2f(84, 100);
    glVertex2f(86, 100);
    glVertex2f(86, 0);
    glEnd();

    //Road divider 1
    //Top
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(30, road_divider1_top + 80);
    glVertex2f(30, road_divider1_top + 100);
    glVertex2f(31, road_divider1_top + 100);
    glVertex2f(31, road_divider1_top + 80);
    glEnd();
    road_divider1_top = road_divider1_top - 0.5;
    if (road_divider1_top < -100) {
        road_divider1_top = 20;
        score++;
    }

    //Middle
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(30, road_divider1_middle + 40);
    glVertex2f(30, road_divider1_middle + 60);
    glVertex2f(31, road_divider1_middle + 60);
    glVertex2f(31, road_divider1_middle + 40);
    glEnd();
    road_divider1_middle = road_divider1_middle - 0.5;
    if (road_divider1_middle < -60) {
        road_divider1_middle = 60;
        score++;
    }

    //Bottom
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(30, road_divider1_bottom + 0);
    glVertex2f(30, road_divider1_bottom + 20);
    glVertex2f(31, road_divider1_bottom + 20);
    glVertex2f(31, road_divider1_bottom + 0);
    glEnd();
    road_divider1_bottom = road_divider1_bottom - 0.5;
    if (road_divider1_bottom < -20) {
        road_divider1_bottom = 100;
        score++;
    }

    //Road double middle line
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(47, 0);
    glVertex2f(47, 100);
    glVertex2f(48, 100);
    glVertex2f(48, 0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(49, 0);
    glVertex2f(49, 100);
    glVertex2f(50, 100);
    glVertex2f(50, 0);
    glEnd();

    //Road divider 3
    //Top
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(66, road_divider3_top + 80);
    glVertex2f(66, road_divider3_top + 100);
    glVertex2f(67, road_divider3_top + 100);
    glVertex2f(67, road_divider3_top + 80);
    glEnd();
    road_divider3_top = road_divider3_top - 0.5;
    if (road_divider3_top < -100)
        road_divider3_top = 20;

    //Middle
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(66, road_divider3_middle + 40);
    glVertex2f(66, road_divider3_middle + 60);
    glVertex2f(67, road_divider3_middle + 60);
    glVertex2f(67, road_divider3_middle + 40);
    glEnd();
    road_divider3_middle = road_divider3_middle - 0.5;
    if (road_divider3_middle < -60)
        road_divider3_middle = 60;

    //Bottom
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(66, road_divider3_bottom + 0);
    glVertex2f(66, road_divider3_bottom + 20);
    glVertex2f(67, road_divider3_bottom + 20);
    glVertex2f(67, road_divider3_bottom + 0);
    glEnd();
    road_divider3_bottom = road_divider3_bottom - 0.5;
    if (road_divider3_bottom < -20)
        road_divider3_bottom = 100;

    //Info base
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(87, 82);
    glVertex2f(87, 100);
    glVertex2f(100, 100);
    glVertex2f(100, 82);
    glEnd();

    //Print score
    char bsc[50];
    sprintf_s(bsc, "SCORE: %d", score);
    glColor3f(1.0, 1.0, 1.0);
    drawText(89, 95, (void*)font, bsc);

    //Print speed
    char bsp[50];
    sprintf_s(bsc, "SPEED: %d", speed);
    glColor3f(1.0, 1.0, 1.0);
    drawText(89, 90, (void*)font, bsp);

    //Print level
    char bl[50];
    sprintf_s(bl, "LEVEL: %d", level);
    glColor3f(1.0, 1.0, 1.0);
    drawText(89, 85, (void*)font, bl);

    //Auto alap
    glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(horizontal_index, vertical_index);
    glVertex2f(horizontal_index, vertical_index + 15);
    glVertex2f(horizontal_index + 6, vertical_index + 15);
    glVertex2f(horizontal_index + 6, vertical_index);
    glEnd();



    //Speed increase
    switch (score)
    {
    case 20:
        speed = 60;
        break;
    case 40:
        speed = 70;
        break;
    case 60:
        speed = 80;
        break;
    case 80:
        speed = 100;
        break;
    default:
        break;
    }
}

void pre()
{
    //Road base
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(15, 0);
    glVertex2f(15, 100);
    glVertex2f(85, 100);
    glVertex2f(85, 0);
    glEnd();

    //Road left
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(14, 0);
    glVertex2f(14, 100);
    glVertex2f(16, 100);
    glVertex2f(16, 0);
    glEnd();

    //Road right
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(84, 0);
    glVertex2f(84, 100);
    glVertex2f(86, 100);
    glVertex2f(86, 0);
    glEnd();

    //Road divider 1
    //Top
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(30, road_divider1_top + 80);
    glVertex2f(30, road_divider1_top + 100);
    glVertex2f(31, road_divider1_top + 100);
    glVertex2f(31, road_divider1_top + 80);
    glEnd();
    road_divider1_top = road_divider1_top - 0.5;
    if (road_divider1_top < -100)
        road_divider1_top = 20;

    //Middle
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(30, road_divider1_middle + 40);
    glVertex2f(30, road_divider1_middle + 60);
    glVertex2f(31, road_divider1_middle + 60);
    glVertex2f(31, road_divider1_middle + 40);
    glEnd();
    road_divider1_middle = road_divider1_middle - 0.5;
    if (road_divider1_middle < -60)
        road_divider1_middle = 60;

    //Bottom
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(30, road_divider1_bottom + 0);
    glVertex2f(30, road_divider1_bottom + 20);
    glVertex2f(31, road_divider1_bottom + 20);
    glVertex2f(31, road_divider1_bottom + 0);
    glEnd();
    road_divider1_bottom = road_divider1_bottom - 0.5;
    if (road_divider1_bottom < -20)
        road_divider1_bottom = 100;

    //Road double middle line
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(47, 0);
    glVertex2f(47, 100);
    glVertex2f(48, 100);
    glVertex2f(48, 0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(49, 0);
    glVertex2f(49, 100);
    glVertex2f(50, 100);
    glVertex2f(50, 0);
    glEnd();

    //Road divider 3
    //Top
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(66, road_divider3_top + 80);
    glVertex2f(66, road_divider3_top + 100);
    glVertex2f(67, road_divider3_top + 100);
    glVertex2f(67, road_divider3_top + 80);
    glEnd();
    road_divider3_top = road_divider3_top - 0.5;
    if (road_divider3_top < -100)
        road_divider3_top = 20;

    //Middle
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(66, road_divider3_middle + 40);
    glVertex2f(66, road_divider3_middle + 60);
    glVertex2f(67, road_divider3_middle + 60);
    glVertex2f(67, road_divider3_middle + 40);
    glEnd();
    road_divider3_middle = road_divider3_middle - 0.5;
    if (road_divider3_middle < -60)
        road_divider3_middle = 60;

    //Bottom
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(66, road_divider3_bottom + 0);
    glVertex2f(66, road_divider3_bottom + 20);
    glVertex2f(67, road_divider3_bottom + 20);
    glVertex2f(67, road_divider3_bottom + 0);
    glEnd();
    road_divider3_bottom = road_divider3_bottom - 0.5;
    if (road_divider3_bottom < -20)
        road_divider3_bottom = 100;

    //Text background
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(36, 28);
    glVertex2f(36, 80);
    glVertex2f(56, 80);
    glVertex2f(56, 28);
    glEnd();


    //Title
    glColor3f(1.0, 1.0, 1.0);
    drawText(43, 75, (void*)font, "OpenCar V1.0");

    //Instructions
    glColor3f(0.0, 0.0, 1.0);
    drawText(39, 55, (void*)font, "Press SPACE to START!");

    glColor3f(1.0, 0.0, 0.0);
    drawText(41, 50, (void*)font, "Press ESC to EXIT!");

    glColor3f(0.0, 1.0, 0.0);
    drawText(44, 45, (void*)font1, "<- : move left");

    glColor3f(0.0, 1.0, 0.0);
    drawText(44, 40, (void*)font1, "-> : move right");

    glColor3f(0.0, 1.0, 0.0);
    drawText(44, 35, (void*)font1, "UP : move up");

    glColor3f(0.0, 1.0, 0.0);
    drawText(42, 30, (void*)font1, "DOWN : move down");
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);

    if (run == 1)
    {
        glClearColor(0.000, 0.392, 0.000, 1);
        start();
    }
    else
    {
        glClearColor(0.125, 0.125, 0.125, 1);
        pre();
    }

    glFlush();
    glutSwapBuffers();
}

void f_keys(int key, int x, int y)
{
    switch (key)
    {

    case GLUT_KEY_LEFT:
        if (horizontal_steps > 0)
        {
            horizontal_index = horizontal_index - 18;
            horizontal_steps--;
        }
        break;

    case GLUT_KEY_RIGHT:
        if (horizontal_steps < 3)
        {
            horizontal_index = horizontal_index + 18;
            horizontal_steps++;
        }
        break;

    case GLUT_KEY_UP:
        if (vertical_steps < 12) {
            vertical_index = vertical_index + 5;
            vertical_steps++;
        }
        break;

    case GLUT_KEY_DOWN:
        if (vertical_steps > 0) {
            vertical_index = vertical_index - 5;
            vertical_steps--;
        }
        break;

    default:
        break;
    }
}

void keys(unsigned char key, int x, int y)
{

    switch (key)
    {
    case ' ':
        if (run == 0)
        {
            run = 1;
            horizontal_index = 19;
            vertical_index = 5;
            horizontal_steps = 0;
            vertical_steps = 0;
            speed = 50;
            score = 0;
            level = 1;

            road_divider1_top = 0;
            road_divider1_middle = 0;
            road_divider1_bottom = 0;

            road_divider3_top = 0;
            road_divider3_middle = 0;
            road_divider3_bottom = 0;
        }
        break;

    case 27:
        exit(0);
        break;

    default:
        break;
    }
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / speed, timer, 0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(200, 20);
    glutCreateWindow("OpenCar");

    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glutSpecialFunc(f_keys);

    glOrtho(0, 100, 0, 100, -1, 1);
    //glClearColor(1.0, 1.0, 1.0, 1.0);

    glutTimerFunc(1000, timer, 0);
    glutMainLoop();

    return 0;
}