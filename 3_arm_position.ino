#include<Math.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  double alpha;
  double beta;
  double gamma;
  double sina = sin(alpha);
  double sinb = sin(beta);
  double sinc = sin(gamma);
  double cosa = cos(alpha);
  double cosb = cos(beta);
  double cosc = cos(gamma);
  double corner1[3];
  double corner2[3];
  double corner3[3];
  double new_c1[3];
  double new_c2[3];
  double new_c3[3];
  new_c1[0] = xcoord(corner1[0], corner1[1], corner1[2], sina, cosa, sinb, cosb, sinc, cosc);
  new_c2[0] = xcoord(corner2[0], corner2[1], corner2[2], sina, cosa, sinb, cosb, sinc, cosc);
  new_c3[0] = xcoord(corner3[0], corner3[1], corner3[2], sina, cosa, sinb, cosb, sinc, cosc);
  new_c1[1] = ycoord(corner1[0], corner1[1], corner1[2], sina, cosa, sinb, cosb, sinc, cosc);
  new_c2[1] = ycoord(corner2[0], corner2[1], corner2[2], sina, cosa, sinb, cosb, sinc, cosc);
  new_c3[1] = ycoord(corner3[0], corner3[1], corner3[2], sina, cosa, sinb, cosb, sinc, cosc);
  new_c1[2] = zcoord(corner1[0], corner1[1], corner1[2], sina, cosa, sinb, cosb, sinc, cosc);
  new_c2[2] = zcoord(corner2[0], corner2[1], corner2[2], sina, cosa, sinb, cosb, sinc, cosc);
  new_c3[2] = zcoord(corner3[0], corner3[1], corner3[2], sina, cosa, sinb, cosb, sinc, cosc);
}

double xcoord (double x, double y, double z, double sina, double cosa, double sinb, double cosb, double sinc, double cosc) {
  double xn = x * (cosa * cosb) + y * (sinc * sinb * cosa - cosc * sina) + z * (cosa * sinb * cosc + sina * sinc);
  return xn;
}

double ycoord (double x, double y, double z, double sina, double cosa, double sinb, double cosb, double sinc, double cosc) {
  double xn = x * (sina * cosb) + y * (sina * sinb * sinc + cosa * cosc) + z * (cosc * sinb * sina - cosa * sinc);
  return xn;
}

double zcoord (double x, double y, double z, double sina, double cosa, double sinb, double cosb, double sinc, double cosc) {
  double xn = x * (-1 * sinb) + y * (cosb * sinc) + z * (cosb * cosc);
  return xn;
}


