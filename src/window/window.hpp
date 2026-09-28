#pragma once
#include <GLFW/glfw3.h>

namespace window {
    extern GLFWwindow* ventana; // Le dice al programa que la variable existe, para que sea usada globalmente
    void init();
    void loop();
    int end();
}
