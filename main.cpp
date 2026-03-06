#include <cstdlib>
#include <iostream>

#include "Control.h"

int main(int argc, char* argv[])
{
  Control controller;
  controller.initialize();

  ExtU_Control_T input{};

  if (argc == 3) {
    input.ref = std::atof(argv[1]);
    input.fb = std::atof(argv[2]);
  } else {
    std::cout << "Ingrese ref: ";
    std::cin >> input.ref;
    std::cout << "Ingrese fb: ";
    std::cin >> input.fb;

    if (!std::cin) {
      std::cerr << "Entrada invalida. Uso: ./control_app <ref> <fb>" << std::endl;
      return 1;
    }
  }

  controller.setExternalInputs(&input);
  controller.step();

  const auto& output = controller.getExternalOutputs();
  std::cout << "Out1 = " << output.Out1 << std::endl;

  Control::terminate();
  return 0;
}
