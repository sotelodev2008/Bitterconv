#include <imgui.h>
#include <cstdlib>
#include "window.hpp"

void window::menu() {
    if (ImGui::BeginMenuBar()) { // Creo la barra superior
        if (ImGui::BeginMenu("Config")) { // Apartado configuración
            if (ImGui::BeginMenu("Menu1")) {
                ImGui::SeparatorText("TemporalSample");
                ImGui::EndMenu();
            }
            if (ImGui::MenuItem("Salir")) {
                exit(0);
            }
            ImGui::EndMenu();

        }
        ImGui::EndMenuBar();
    }
}
