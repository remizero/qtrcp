___
# Mantenimiento

## Conducta

**Ser amable con todo el mundo.**
Lea y siga el [código de conducta](code-of-conduct.md).


## Pruebas

 - `npm test`: Corrige errores de código y ejecuta todo el conjunto de tests con cobertura.
 - `npm run test-win`: Ejecuta los tests en GNU/Linux,MacOs y Windows.
 - `npm run coverage`: Genera un informe de la cobertura del último test generado (abre una ventana del navegador).
 - `tap test/fork.js --bail`:  Ejecuta un archivo de tests específico y se detiene en el primer error (útil cuando busquemos errores).


## Proceso de Lanzamiento

- Ajustar dependencias.
- Verificar que la Interfaz de usuario sea interactiva.
- Asegurase que está publicando desde la rama maestra.
- Asegurase que el directorio de trabajo esté limpio y que no haya cambios sin modificar.
- Reinstale las dependencias para garantizar que su proyecto funcione con el último árbol de dependencias.
- Ejecuta las pruebas unit-test para comprobar la exactitud de los datos solicitados y/o resultados.
- Actualizar la versión en package.json(si está presente) y crea una etiqueta git.
- Evita la publicación accidental de versiones previas al lanzamiento bajo la última dist-tag.
- Confirme cambios y genere etiquetas en GitHub.
- Escribir una [release note](https://github.com/remizero/ecomoditor/releases/new) siguiendo el estilo de las notas de la versión anterior.


## Pull requests

- Las nuevas características deben venir con tests y documentación.
- Asegúrese de que sigue las [directrices de contribución](contributing.md).
- Al menos un miembro del equipo deben `LGTM` un pull request antes de que se fusione.
- Haz squash de tus commits cuando fusiones. *[Example](https://github.com/remizero/ecomoditor/commit/0675d3444da6958b54c7e5eada91034e516bc97c)*

## Inducción de nuevos miembros

- Agregar el usuario al 'readme.md' y 'package.json'.
- Agregar el usuario como colaborador a todos los repositorios relacionado a AVA y paquetes npm.
- Compartir la información de inicio de sesión de cuenta de Twitter y así el usuario será libre de twittear y retwittear cosas relevantes. 
