#include "src/window/window.hpp"
#include <GLFW/glfw3.h>

int main(){
    window::init();
    window::loop();
    window::end();
    return 0;
}