# Bitterconv 🚀

## Index / Índice

* [English 🇬🇧](#english-)
* [Español 🇪🇸](#español-)

## English 🇬🇧

Storage unit converter (bits and bytes) with a graphical interface built on
ImGui + OpenGL/GLFW.

---

## Recent changes

- **Converter function completed.** `datacalc::converter()` now resolves the
  conversion between all available units.
- **Commercial unit support (base 10^3):** added the Kilobit…Yottabit and
  Kilobyte…Yottabyte families.
- **Binary conversions fixed (base 2^10):** Bit…Yobibit and Byte…Yobibyte,
  with the bit ↔ byte step applied as ÷/× 8.
- **Converter branches reorganized** so the commercial and binary ranges no
  longer overlap.
- **Label fix:** the "Yottabit" entry in the decimal bit list was spelled
  "Yottabyte".
- **The menu bar has been removed**, leaving a cleaner window.

## Coming soon

- **Perhaps in a future update the graphical interface will be improved.**

## Current state

- Working conversion for bits and bytes, in both binary and commercial units.
- Single-window interface with no menu bar.
- Numeric input and source/destination unit selectors.

## Development notes

- The internal calculation normalizes everything to bits and then
  denormalizes to the target unit, avoiding crossed branches.
- Binary family: 2^10 (1,024) step. Commercial family: 10^3 (1,000) step. The
  bit ↔ byte step is applied as ÷8 / ×8.

## Build

Built with **xmake**. The `xmake.lua` script pulls in the GLFW, GLEW, and
ImGui dependencies.

```bash
xmake          # configure and build
xmake run      # run the app
```
## Español 🇪🇸

Conversor de unidades de almacenamiento (bits y bytes) con interfaz gráfica
construida sobre ImGui + OpenGL/GLFW.

---

## Cambios recientes

- **Función de cálculo completada.** `datacalc::converter()` ya resuelve la
  conversión entre todas las unidades disponibles.
- **Soporte de unidades comerciales (base 10^3):** añadidas las familias
  Kilobit…Yottabit y Kilobyte…Yottabyte.
- **Conversiones binarias corregidas (base 2^10):** Bit…Yobibit y
  Byte…Yobibyte, con el paso bit ↔ byte aplicado como ÷/× 8.
- **Ramas del conversor reorganizadas** para que los tramos comerciales y
  binarios no se pisen entre sí.
- **Corrección de etiqueta:** el índice de "Yottabit" en la lista de bits
  decimales estaba escrito como "Yottabyte".
- **Se ha eliminado la barra de menú**, dejando una ventana más limpia.

## Próximamente

- **Quizás en una futura actualización se mejore la interfaz gráfica.**

## Estado actual

- Conversión funcional para bits y bytes, tanto en unidades binarias como
  comerciales.
- Interfaz de una sola ventana sin barra de menú.
- Entrada numérica y selectores de unidad de origen y destino.

## Notas de desarrollo

- El cálculo interno normaliza todo a bits y luego desnormaliza a la unidad
  de destino, evitando ramas cruzadas.
- Familia binaria: escalón de 2^10 (1.024). Familia comercial: escalón de
  10^3 (1.000). El paso bit ↔ byte se aplica como ÷8 / ×8.

## Compilar

Compila con **xmake**. El archivo `xmake.lua` Descarga las dependencias.

```bash
xmake          # configure and build
xmake run      # run the app
```
