
#include <renderer.h>
#include <GL/glut.h>


int window;

void onKeyPressed(unsigned char key, int x, int y) {

    if (key == 27) {
        glutDestroyWindow(window);
        exit(0);
    }
}

int main(int argc, char *argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);


    window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... NeHe '99");
    glutDisplayFunc(&onDrawFrame);
    glutIdleFunc(&onDrawFrame);
    glutReshapeFunc(&onSurfaceChanged);
    glutKeyboardFunc(&onKeyPressed);

    onSurfaceCreated(640, 480);

    glutMainLoop();

    return 1;
}

