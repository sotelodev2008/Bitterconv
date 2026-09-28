add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate") 
set_policy("build.compile_commands", true)

-- 1. Declarar dependencias (Añadimos "opengl" para sistemas Linux/macOS)
add_requires("imgui", {configs = {glfw_opengl3 = true}})
add_requires("glew")
add_requires("glfw")
add_requires("opengl", {optional = true}) -- Evita fallos de enlazado del driver gráfico

target("bitterconv")
    set_kind("binary")
    set_languages("c++23")
    
    -- 2. Buscar cabeceras tanto en la raíz como en las dependencias
    add_includedirs(".")
    add_files("./src/main.cpp", "./src/window/*.cpp", "./src/calc/*.cpp")
    add_headerfiles("./src/window/window.hpp", "./src/calc/calc.hpp")
    
    -- 3. Vincular los paquetes cargados
    add_packages("imgui", "glew", "glfw", "opengl")
