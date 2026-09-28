#include <cstddef>
#include <cstring>
#include <iostream>
#include <GL/glew.h> // Se comunica con tu tarjeta grafica
#include <GL/gl.h> // Controla la iluminación y efectos especiales
#include <GLFW/glfw3.h>  // Libreria de opengl que maneja entrada de teclado y ratón
#include <imgui.h> // Nucleo de ImGui
#include <imgui_impl_glfw.h> // Libreria que permite entender teclado y ratón a ImGui
#include <imgui_impl_opengl3.h> // Libreria puente que permite que ImGui pueda dibujar en pantalla
#include <cstdlib> // Usada para salir del codigo
#include "window.hpp"

using namespace std;

namespace window {
    GLFWwindow* ventana; // Le digo al archivo hpp que la variable global que busca esta aquí, a la vez que la defino
}

void window::init(){
    if (!glfwInit()) { // Comprueba si OpenGL se ha iniciado
        cout << "No se puede abir";
        exit(-1);
    }
    // Los comandos de glfwWindowHint son configuraciones para la ventana que estas por crear
    glfwWindowHint(GLFW_SAMPLES, 4); // Antialiasing x4
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // La versión máxima permitida de opengl
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // La versión minima permitida de opengl
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Desactiva por completo las ordenes de versiones anteriores
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Impide que se pueda modificar el tamaño de la ventana
    ventana = glfwCreateWindow(450, 350, "Bitterconv", NULL, NULL); /* Esto te permite crear la ventana:
    Los valores se dividen en 
    1º Ancho (En pixeles)
    2º Alto (En pixeles)
    3º Titulo de la ventana
    4º Monitor para el modo pantalla completa (si se pasa NULL, se abre en modo ventana en el monitor principal)
    5º Puntero a otra ventana del mismo programa para COMPARTIR recursos gráficos (texturas, shaders, etc.) en la tarjeta gráfica */
    if (ventana == NULL) { // Comprueba si la ventana no se ha logrado iniciar
        cout << "Su procesador no es compatible";
        exit(-1); // Acaba en error;
    }
    glfwMakeContextCurrent(ventana); // Inicia la ventana
    glewExperimental = true; // Comprueba los punteroes de ciertas ordenes a pesar de que la grafica no reconozca la orden
    if (glewInit() != GLEW_OK) { // Comprueba si la ventana a logrado abrirse correctamente
        cout << "La aplicación falla por algún motivo";
        exit(-1); // Acaba en error
    }
    IMGUI_CHECKVERSION(); // Comprueba la versión actual de ImGui
    ImGui::CreateContext(); // Crea una ventana/contexto en ImGui
    ImGui::GetIO().IniFilename = nullptr; // Le dice a ImGui que no cree ningun archivo,ini
    ImGuiIO& io = ImGui::GetIO(); // Crea un puntero hacia ImGuiIO, este simplemente recoje las operaciones de entrada y salida
    ImGui_ImplGlfw_InitForOpenGL(ventana, true); // Implemento OpenGL a la ventana de ImGui
    ImGui_ImplOpenGL3_Init("#version 330"); // Inicio la versión 330
}
