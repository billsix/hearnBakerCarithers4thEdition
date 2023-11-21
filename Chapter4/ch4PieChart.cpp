#ifdef __APPLE__
#include <glut.h>
#elif _WIN32
#include <GL/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>

const GLdouble twoPi = 6.283185;

GLsizei winWidth = 400, winHeight = 300;  // Initial display window size.

void init(void) {
  glClearColor(1.0, 1.0, 1.0, 1.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  55 gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

class screenPt {
 private:
  GLint x, y;

 public:
  /*  Default Constructor: initializes coordinate position to (0, 0).  */
  screenPt() { x = y = 0; }
  void setCoords(GLint xCoordValue, GLint yCoordValue) {
    x = xCoordValue;
    y = yCoordValue;
  }

  GLint getx() const { return x; }

  GLint gety() const { return y; }

  void setx(GLint x) { this->x = x; }

  void sety(GLint y) { this->y = y; }

  void incrementx() { x++; }
  void decrementy() { y--; }
};

void setPixel(GLint xCoord, GLint yCoord) {
  glBegin(GL_POINTS);
  { glVertex2i(xCoord, yCoord); }
  glEnd();
}

void circlePlotPoints(GLint xc, GLint yc, screenPt circPt) {
  setPixel(xc + circPt.getx(), yc + circPt.gety());
  setPixel(xc - circPt.getx(), yc + circPt.gety());
  setPixel(xc + circPt.getx(), yc - circPt.gety());
  setPixel(xc - circPt.getx(), yc - circPt.gety());
  setPixel(xc + circPt.gety(), yc + circPt.getx());
  setPixel(xc - circPt.gety(), yc + circPt.getx());
  setPixel(xc + circPt.gety(), yc - circPt.getx());
  setPixel(xc - circPt.gety(), yc - circPt.getx());
}

// void circleMidpoint (GLint xc, GLint yc, GLint radius)
void circleMidpoint(screenPt screenpt, GLint radius) {
  screenPt circPt;

  GLint p = 1 - radius;  //  Initial value for midpoint parameter.

  circPt.setCoords(0, radius);  //  Set coordinates for top point of circle.

  void circlePlotPoints(GLint, GLint, screenPt);

  /*  Plot the initial point in each circle quadrant.  */
  circlePlotPoints(screenpt.getx(), screenpt.gety(), circPt);
  /*  Calculate next point and plot in each octant.  */
  while (circPt.getx() < circPt.gety()) {
    circPt.incrementx();
    if (p < 0)
      p += 2 * circPt.getx() + 1;
    else {
      circPt.decrementy();
      p += 2 * (circPt.getx() - circPt.gety()) + 1;
    }
    circlePlotPoints(screenpt.getx(), screenpt.gety(), circPt);
  }
}

void pieChart(void) {
  screenPt circCtr, piePt;
  GLint radius = winWidth / 4;  // Circle radius.

  GLdouble sliceAngle, previousSliceAngle = 0.0;

  GLint k, nSlices = 12;  // Number of slices.
  GLfloat dataValues[12] = {10.0, 7.0,  13.0, 5.0, 13.0, 14.0,
                            3.0,  16.0, 5.0,  3.0, 17.0, 8.0};
  GLfloat dataSum = 0.0;

  circCtr.setx(winWidth / 2);  // Circle center position.
  circCtr.sety(winHeight / 2);
  circleMidpoint(circCtr, radius);  // Call a midpoint circle-plot routine.

  for (k = 0; k < nSlices; k++) dataSum += dataValues[k];

  for (k = 0; k < nSlices; k++) {
    sliceAngle = twoPi * dataValues[k] / dataSum + previousSliceAngle;
    piePt.setx(circCtr.getx() + radius * cos(sliceAngle));
    piePt.sety(circCtr.gety() + radius * sin(sliceAngle));
    glBegin(GL_LINES);
    {
      glVertex2i(circCtr.getx(), circCtr.gety());
      glVertex2i(piePt.getx(), piePt.gety());
    }
    glEnd();
    previousSliceAngle = sliceAngle;
  }
}

void displayFcn(void) {
  glClear(GL_COLOR_BUFFER_BIT);  //  Clear display window.
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glColor3f(0.0, 0.0, 1.0);  //  Set circle color to blue.

  pieChart();
  glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)(newWidth), 0.0, (GLdouble)(newHeight));

  glClear(GL_COLOR_BUFFER_BIT);

  /*  Reset display-window size parameters.  */
  winWidth = newWidth;
  winHeight = newHeight;
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(winWidth, winHeight);
  glutCreateWindow("Pie Chart");

  init();
  glutDisplayFunc(displayFcn);
  glutReshapeFunc(winReshapeFcn);

  glutMainLoop();
  return 0;
}
