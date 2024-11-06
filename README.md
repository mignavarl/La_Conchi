🐚 Minishell
Descripción

El objetivo del proyecto es desarrollar una shell , es decir, un intérprete de líneas de comandos de forma sencilla y completa. Utilizando las técnicas y conocimientos adquiridos durante el curso. La shell es una parte fundamental del sistema operativo y es la encargada de procesar los comandos que el usuario escribe en la consola o terminal.

El proyecto minishell se divide en varias partes:

1️⃣ → Análisis de la línea de comandos: en esta parte, se debe dividir la línea de comandos en distintos tokens (palabras), teniendo en cuenta las distintos espacios y caracteres especiales.

2️⃣ → Ejecución de comandos: una vez analizada la línea de comandos, se debe determinar el comando a ejecutar y sus argumentos. Luego, se debe utilizar la función execve() para ejecutar el comando en el sistema o ejecutar tu función propia si es un builtin.

3️⃣ → Gestión de errores: es importante gestionar los errores que puedan surgir durante el proceso de análisis y ejecución de la línea de comandos.

4️⃣ → Gestión de redirecciones: se deben implementar las redirecciones de entrada y salida (>, <, >>, <<) para poder redirigir la entrada y salida de los comandos a archivos.

5️⃣ → Gestión de pipes: se deben implementar los pies | para poder encadenar varios comandos y enviar la salida de un comando como entrada del siguiente.

    

Implementación de Nuestra Minishell

Nuestra minishell debe cumplir con varios requisitos, y aquí hay algunos consejos sobre cómo podemos colaborar en su desarrollo:

    Entrada y Salida: Debemos mostrar un prompt y utilizar la función readline para permitir que los usuarios ingresen comandos de manera intuitiva.
    

    Historial: Implementaremos add_history para mantener un historial funcional de los comandos ejecutados, facilitando la navegación y reutilización de entradas anteriores.
    

    Ejecución de Comandos: Es esencial que busquemos y ejecutemos el ejecutable correcto, gestionando adecuadamente la variable PATH y asegurando que tanto las rutas relativas como las absolutas funcionen sin problemas.
    

    Manejo de Señales: Implementaremos el manejo de señales utilizando signal o sigaction, asegurándonos de que solo usemos una variable global para gestionar las señales, lo que facilitará el control y la organización del código.
    

    Redirecciones y Pipes: Trabajaremos juntos para implementar el manejo de redirecciones de entrada y salida, así como la conexión de comandos mediante pipes, lo que permitirá una mayor flexibilidad en el uso de nuestra minishell.
    

    Variables de Entorno: Debemos asegurarnos de implementar la expansión de variables de entorno y la gestión del estado de salida del último comando ejecutado, lo cual es fundamental para una experiencia de usuario completa.
    

    Built-ins: Finalmente, es crucial que implementemos comandos internos como cd, pwd, exit, entre otros, para que nuestra minishell tenga la funcionalidad necesaria que esperan los usuarios.


