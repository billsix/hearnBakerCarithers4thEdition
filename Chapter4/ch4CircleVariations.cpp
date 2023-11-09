#ifdef __APPLE__
#include <glut.h>
#elif _WIN32
#include <GL/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

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

typedef enum { limacon = 1, cardioid, threeLeaf, fourLeaf, spiral } curveName;

GLsizei winWidth = 600, winHeight = 500;  // Initial display window size.
int curveNum = 1;

void init(void) {
  glClearColor(1.0, 1.0, 1.0, 1.0);

  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(screenPt pt1, screenPt pt2) {
  glBegin(GL_LINES);
  {
    glVertex2i(pt1.getx(), pt1.gety());
    glVertex2i(pt2.getx(), pt2.gety());
  }
  glEnd();
}

void setPixel(GLint xCoord, GLint yCoord) {
  glBegin(GL_POINTS);
  { glVertex2i(xCoord, yCoord); }
  glEnd();
}

void circleMidpoint(GLint xc, GLint yc, GLint radius) {
  screenPt circPt;

  GLint p = 1 - radius;  //  Initial value for midpoint parameter.

  circPt.setCoords(0, radius);  //  Set coordinates for top point of circle.

  void circlePlotPoints(GLint, GLint, screenPt);

  /*  Plot the initial point in each circle quadrant.  */
  circlePlotPoints(xc, yc, circPt);
  /*  Calculate next point and plot in each octant.  */
  while (circPt.getx() < circPt.gety()) {
    circPt.incrementx();
    if (p < 0)
      p += 2 * circPt.getx() + 1;
    else {
      circPt.decrementy();
      p += 2 * (circPt.getx() - circPt.gety()) + 1;
    }
    circlePlotPoints(xc, yc, circPt);
  }
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

void drawCurve(GLint curveNum) {
  /*  The limacon of Pascal is a modification of the circle equation
   *  with the radius varying as r = a * cos (theta) + b, where a
   *  and b are constants.  A cardioid is a limacon with a = b.
   *  Three-leaf and four-leaf curves are generated when
   *  r = a * cos (n * theta), with n = 3 and n = 2, respectively.
   *  A spiral is displayed when r is a multiple of theta.
   */

  const GLdouble twoPi = 6.283185;
  const GLint a = 175, b = 60;

  GLfloat r, theta, dtheta = 1.0 / float(a);
  GLint x0 = 200, y0 = 250;  // Set an initial screen position.
  screenPt curvePt[2];

  glColor3f(0.0, 0.0, 0.0);  //  Set curve color to black.

  curvePt[0].setx(x0);  // Initialize curve position.
  curvePt[0].sety(y0);

  switch (curveNum) {
    case limacon:
      curvePt[0].setx(curvePt[0].getx() + a + b);
      break;
    case cardioid:
      curvePt[0].setx(curvePt[0].getx() + a + a);
      break;
    case threeLeaf:
      curvePt[0].setx(curvePt[0].getx() + a);
      break;
    case fourLeaf:
      curvePt[0].setx(curvePt[0].getx() + a);
      break;
    case spiral:
      break;
    default:
      break;
  }

  theta = dtheta;
  while (theta < twoPi) {
    switch (curveNum) {
      case limacon:
        r = a * cos(theta) + b;
        break;
      case cardioid:
        r = a * (1 + cos(theta));
        break;
      case threeLeaf:
        r = a * cos(3 * theta);
        break;
      case fourLeaf:
        r = a * cos(2 * theta);
        break;
      case spiral:
        r = (a / 4.0) * theta;
        break;
      default:
        break;
    }

    curvePt[1].setx(x0 + r * cos(theta));
    curvePt[1].sety(y0 + r * sin(theta));
    lineSegment(curvePt[0], curvePt[1]);

    curvePt[0].setx(curvePt[1].getx());
    curvePt[0].sety(curvePt[1].gety());
    theta += dtheta;
  }
}

void displayFcn(void) {
  glClear(GL_COLOR_BUFFER_BIT);  //  Clear display window.

  if (curveNum == 1 || curveNum == 2 || curveNum == 3 || curveNum == 4 ||
      curveNum == 5)
    drawCurve(curveNum);
  else
    exit(0);

  glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);

  glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv) {
  cout << "\nEnter the integer value corresponding to\n";
  cout << "one of the following curve names.\n";
  cout << "Press any other key to exit.\n";
  cout << "\n1-limacon, 2-cardioid, 3-threeLeaf, 4-fourLeaf, 5-spiral:  ";
  cin >> curveNum;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(winWidth, winHeight);
  glutCreateWindow("Draw Curves");

  init();
  glutDisplayFunc(displayFcn);
  glutReshapeFunc(winReshapeFcn);

  glutMainLoop();
  return 0;
}
