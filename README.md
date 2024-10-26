Funciones y conceptos básicos

    readline: Esta función se utiliza para leer una línea de entrada del usuario. Es parte de la biblioteca GNU Readline, que proporciona una interfaz para el manejo de entrada de texto, incluyendo características como la edición de línea y el historial.

    rl_clear_history: Limpia el historial de comandos guardados en la sesión actual.

    rl_on_new_line: Indica que se ha llegado a una nueva línea, lo que permite que la función Readline ajuste el comportamiento de entrada.

    rl_replace_line: Reemplaza la línea actual en el buffer de Readline, permitiendo así modificar lo que el usuario está editando.

    rl_redisplay: Redibuja la línea actual en la terminal.

    add_history: Agrega la línea actual al historial de comandos.

    printf: Función de salida estándar para imprimir texto en la consola.

    malloc / free: Funciones de gestión de memoria que se utilizan para asignar y liberar memoria dinámicamente.

    write: Escribe datos en un descriptor de archivo. Puede ser utilizado para escribir en la salida estándar o en archivos.

    access: Verifica si el programa tiene acceso a un archivo o directorio.

    open, read, close: Funciones para manejar archivos. open abre un archivo, read lee datos de él, y close cierra el descriptor de archivo.

    fork: Crea un nuevo proceso duplicando el proceso que lo llama. Es fundamental para ejecutar otros programas.

    wait, waitpid, wait3, wait4: Estas funciones hacen que un proceso espere a que sus procesos hijos terminen su ejecución.

    signal, sigaction, kill: Manejo de señales. Permiten la comunicación entre procesos y el manejo de eventos como la interrupción de un proceso.

    exit: Termina un proceso con un código de salida específico.

    getcwd, chdir: getcwd obtiene el directorio de trabajo actual y chdir cambia el directorio de trabajo.

    stat, lstat, fstat: Obtienen información sobre archivos y directorios.

    unlink: Elimina un archivo.

    execve: Ejecuta un programa especificado, reemplazando el proceso actual con el nuevo.

    dup, dup2: Duplican descriptores de archivo. Se utilizan comúnmente para redirigir la entrada y salida de procesos.

    pipe: Crea un canal de comunicación entre procesos, permitiendo la comunicación unidireccional.

    opendir, readdir, closedir: Funciones para manejar directorios, permitiendo abrir, leer y cerrar directorios.

    strerror, perror: Devuelven mensajes de error descriptivos.

    isatty, ttyname, ttyslot: Funciones para manejar y verificar terminales.

    ioctl: Permite realizar operaciones de entrada/salida de bajo nivel en dispositivos.

    getenv: Obtiene el valor de una variable de entorno.

    tcsetattr, tcgetattr: Configuran y obtienen atributos de terminal.

    tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs: Funciones para manejar capacidades de terminal.

Implementación de tu minishell

Tu minishell debe cumplir con varios requisitos, y aquí hay algunos consejos:

    Entrada y salida: Debes mostrar un prompt e implementar la función readline para que el usuario ingrese comandos.

    Historial: Usa add_history para mantener un historial funcional de comandos.

    Ejecución de comandos: Debes buscar y ejecutar el ejecutable correcto, manejando la variable PATH y rutas relativas y absolutas.

    Manejo de señales: Implementa el manejo de señales con signal o sigaction, asegurando que no uses más de una variable global para gestionar señales.

    Redirecciones y pipes: Implementa el manejo de redirecciones de entrada y salida y conecta comandos mediante pipes.

    Variables de entorno: Implementa la expansión de variables de entorno y la gestión del estado de salida del último comando ejecutado.

    Built-ins: Asegúrate de implementar comandos internos como cd, pwd, exit, etc.

Revisión de tu código

    Comprobación de caracteres: La función check_chars está bien para contar y verificar los caracteres de redirección y pipes.

    División de palabras: Asegúrate de que search_in_line y otras funciones relacionadas con el análisis de líneas manejen adecuadamente las comillas y los metacaracteres.

    Ejecución de comandos: La función execute_cmds debería encargarse de llamar a los comandos construidos, ejecutando aquellos que son built-ins directamente y delegando la ejecución a un proceso hijo para los comandos externos.
