#include <renderer.h>


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void onSurfaceCreated(int width, int height) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);     // This Will Clear The Background Color To Black
    glClearDepth(1.0);                // Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS);             // The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);          // Enables Depth Testing
    glShadeModel(GL_SMOOTH);          // Enables Smooth Color Shading

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();             // Reset The Projection Matrix

    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f); // Calculate The Aspect Ratio Of The Window

    glMatrixMode(GL_MODELVIEW);
}
void onSurfaceChanged(int width, int height) {
    if (height==0)                // Prevent A Divide By Zero If The Window Is Too Small
        height=1;

    glViewport(0, 0, width, height);      // Reset The Current Viewport And Perspective Transformation

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
}
void onDrawFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);       // Clear The Screen And The Depth Buffer
    glLoadIdentity();             // Reset The View

    glTranslatef(-1.5f,0.0f,-6.0f);       // Move Left 1.5 Units And Into The Screen 6.0

    // draw a triangle
    glBegin(GL_POLYGON);              // start drawing a polygon
    glVertex3f( 0.0f, 1.0f, 0.0f);        // Top
    glVertex3f( 1.0f,-1.0f, 0.0f);        // Bottom Right
    glVertex3f(-1.0f,-1.0f, 0.0f);        // Bottom Left
    glEnd();                  // we're done with the polygon

    glTranslatef(3.0f,0.0f,0.0f);             // Move Right 3 Units

    // draw a square (quadrilateral)
    glBegin(GL_QUADS);                // start drawing a polygon (4 sided)
    glVertex3f(-1.0f, 1.0f, 0.0f);        // Top Left
    glVertex3f( 1.0f, 1.0f, 0.0f);        // Top Right
    glVertex3f( 1.0f,-1.0f, 0.0f);        // Bottom Right
    glVertex3f(-1.0f,-1.0f, 0.0f);        // Bottom Left
    glEnd();                  // done with the polygon

    // swap buffers to display, since we're double buffered.
    glutSwapBuffers();
}
