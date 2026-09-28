#include <cstring>
#include <GL/glew.h> // Se comunica con tu tarjeta grafica
#include <GL/gl.h> // Controla la iluminación y efectos especiales
#include <GLFW/glfw3.h>  // Libreria de opengl que maneja entrada de teclado y ratón
#include <imgui.h> // Nucleo de ImGui
#include <imgui_impl_glfw.h> // Libreria que permite entender teclado y ratón a ImGui
#include <imgui_impl_opengl3.h> // Libreria puente que permite que ImGui pueda dibujar en pantalla
#include <cstdlib> // Usada para salir del codigo
#include "window.hpp"
#include "../calc/calc.hpp"

using namespace std;

void window::loop() {

    static bool Menu = true; // Comprueba si el usuario esta en el menu
    static float pre_input_int; // Valor numerico que mete el usuario
    static int pre_actual_option = 11;
    static int post_actual_option = 0;
    static const char* options[] = {
        "Bit", "Kibibit", "Mebibit", "Gibibit", "Tebibit", "Pebibit", "Exbibit", "Zebibit", "Yobibit", 
        "Byte", "Kibibyte", "Mebibyte", "Gibibyte", "Tebibyte", "Pebibyte", "Exbibyte", "Zebibyte", "Yobibyte"
    }; //  Al usar char* puedes hacer cadenas de texto y si al nombre de la variable le pones [] puedes hacer arrays
    static const char* options_symbols[] = {
        "b", "Kib", "Mib", "Gib", "Tib", "Pib", "Eib", "Zib", "Yib",
        "B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};

    while (!glfwWindowShouldClose(ventana)) { // Comprueba si la ventana se tiene que cerrar
        glClearColor(0.1953125f, 0.32421875f, 0.22265625f, 1.0f); // Le dice a OpenGL los colores que debe usar para el proximo frame, estos son Rojo, Verde, Azul y Alfa (Transparencia)
        glClear(GL_COLOR_BUFFER_BIT); // Limpia cada frame antes de dibujar el siguiente
        ImGui_ImplOpenGL3_NewFrame(); // Le digo a OpenGL que se prepare para el siguiente frame
        ImGui_ImplGlfw_NewFrame(); // Le digo a OpenGL que se prepare para recibir operaciones i/o

        ImGui::NewFrame(); // Crea un nuevo frame de ImGui
        ImGuiWindowFlags flags = ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar;
        ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
        ImGui::SetNextWindowSize(ImVec2(450.0f, 350.0f));
        ImGui::Begin("Bitterconv", NULL, flags);

        ImGui::GetFont()->Scale = 6.0f; //Accede a la variable fuente y modifica el valor scales
        ImGui::PushFont(ImGui::GetFont()); // Actualiza la fuente volviendo a comprobar su valor actual
        ImGui::SetCursorPos(ImVec2((450 - (ImGui::CalcTextSize("Bitterconv").x + (ImGui::GetStyle().FramePadding.x * 2.0f))) * 0.5f, ImGui::GetCursorPosY() + 5.0f)); // Dummy se mueve el cursor usando como punto base la posición actual de este

        ImGui::Text("Bitterconv");
        ImGui::PopFont();
        ImGui::GetFont()->Scale = 1.2f; // Restaura el tamaño a la normalidad
        ImGui::PushFont(ImGui::GetFont());
        ImGui::PopFont();

        ImGui::InputFloat("##Pre_input", &pre_input_int); // El valor que el usuario escriba se guardara en ese float
        ImGui::Combo("##Pre_input_selector", &pre_actual_option, options, IM_ARRAYSIZE(options));
        /*Combo es un menu desplegable para seleccionar objetos y a la hora de configurarlo se divide en 4 valores
        1. El primero es el texto descriptivo que aparecera al lado del combo
        2. El segundo es un puntero a un int que almacena el numero del objeto actual en el que se encuentra el usuario
        3. La lista de objetos/opciones
        4. La longitud de la lista (Para saber cuando detenerse)*/

        ImGui::Combo("##Post_input_selector", &post_actual_option, options, IM_ARRAYSIZE(options));

        float bitter = datacalc::converter(pre_input_int, pre_actual_option, post_actual_option);
        if (bitter == pre_input_int) {ImGui::Text("%.3f", pre_input_int);}
        else if (bitter == -1) {ImGui::Text("Unknown error huh, soon to be patched");}
        else if (bitter == -8) {ImGui::Text("An update will be release, more Sooner than later adding comercial units");}
        else {ImGui::Text("%.9f", bitter);}
        ImGui::SameLine(); // Hace que la siguiente orden se encuentre en la misma linea que la anterior
        ImGui::Text("%s", options_symbols[post_actual_option]);

        ImGui::End(); // Cierra la ventana, ya que en ImGui la ventana se abre y cierra en bucle
        ImGui::Render(); // Reune y compila lo dibujado en el frame
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); // Muestra el nuevo frame por pantalla
        glfwSwapBuffers(ventana); // Actualiza la información en pantalla/Cambio de frame
        glfwPollEvents(); // Procesa los eventos de teclado y ratón
        }
    }