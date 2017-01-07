#include "Visualiser.h"
#include "VisualisationMain.h"
#include "global.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void render();
void update();

//Used to display data
void render()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glPushMatrix();

    glTranslatef(0.0, 0.0, -10.0);

    glBegin(GL_POINTS);

    for(int i = 0; i < visual->list->vecList.size(); i++)
    {
        glVertex3f(visual->list->vecList[i].getX(), visual->list->vecList[i].getY(), visual->list->vecList[i].getZ());
    }

    glEnd();

    glFlush();

    glutSwapBuffers();
}

void update()
{
    render();
}

//Object creation
Visualiser::Visualiser(int gc, char **gv, List *l)
{
    this->argc = gc;
    this->argv = gv;
    this->list = l;
}


//Starting up OpenGL and glut
void Visualiser::startUp()
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    glutInitWindowPosition(100, 100);

    glutInitWindowSize(800, 600);

    glutCreateWindow("Data Visualiser");

    glutDisplayFunc(render);

    glutIdleFunc(update);

    init();

    glutMainLoop();
}


//OpenGL and glut settings
void Visualiser::init()
{

    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)800/(GLfloat)600, 0.1f, 1000.0f);

    //Set Colour and point size
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5);
}


