#include "Control.h"
#include "rt_nonfinite.h"

#include <stdio.h>
#include <stdlib.h>

static int parse_double(const char *text, const char *name, double *value)
{
  char *endptr = NULL;

  *value = strtod(text, &endptr);
  if ((endptr == text) || (*endptr != '\0')) {
    fprintf(stderr, "Error: valor invalido para %s: '%s'\n", name, text);
    return 0;
  }

  return 1;
}

static void print_usage(const char *prog)
{
  fprintf(stderr,
          "Uso:\n"
          "  %s <spd_ref> <pos_x_ref> <pos_y_ref> <fb_x> <fb_y> <fb_theta> <fb_psi> [fb_v]\n\n"
          "Entradas:\n"
          "  spd_ref                 referencia de velocidad\n"
          "  pos_x_ref, pos_y_ref    waypoint objetivo (x,y)\n"
          "  fb_x, fb_y              posicion actual\n"
          "  fb_theta                orientacion actual theta (rad)\n"
          "  fb_psi                  realimentacion de direccion psi (rad)\n"
          "  fb_v (opcional)         velocidad actual para fb[4] (si no se indica: 0.0)\n",
          prog);
}

int main(int argc, char *argv[])
{
  double spd_ref;
  double pos_x_ref;
  double pos_y_ref;
  double fb_x;
  double fb_y;
  double fb_theta;
  double fb_psi;
  double fb_v = 0.0;
  int i;

  if ((argc != 8) && (argc != 9)) {
    print_usage(argv[0]);
    return 1;
  }

  if (!parse_double(argv[1], "spd_ref", &spd_ref) ||
      !parse_double(argv[2], "pos_x_ref", &pos_x_ref) ||
      !parse_double(argv[3], "pos_y_ref", &pos_y_ref) ||
      !parse_double(argv[4], "fb_x", &fb_x) ||
      !parse_double(argv[5], "fb_y", &fb_y) ||
      !parse_double(argv[6], "fb_theta", &fb_theta) ||
      !parse_double(argv[7], "fb_psi", &fb_psi)) {
    print_usage(argv[0]);
    return 1;
  }

  if ((argc == 9) && !parse_double(argv[8], "fb_v", &fb_v)) {
    print_usage(argv[0]);
    return 1;
  }

  Control_initialize();

  Control_U.spd_ref = spd_ref;

  for (i = 0; i < 440; ++i) {
    Control_U.pos_ref[i] = rtNaN;
  }

  Control_U.pos_ref[0] = pos_x_ref;
  Control_U.pos_ref[220] = pos_y_ref;

  Control_U.fb[0] = fb_x;
  Control_U.fb[1] = fb_y;
  Control_U.fb[2] = fb_theta;
  Control_U.fb[3] = fb_psi;
  Control_U.fb[4] = fb_v;

  Control_step();

  printf("u[0]=%.10f\n", Control_Y.u[0]);
  printf("u[1]=%.10f\n", Control_Y.u[1]);

  Control_terminate();
  return 0;
}