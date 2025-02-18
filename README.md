🐚 Minishell
Descripción

El objetivo del proyecto es desarrollar una shell , es decir, un intérprete de líneas de comandos de forma sencilla y completa. Utilizando las técnicas y conocimientos adquiridos durante el curso. La shell es una parte fundamental del sistema operativo y es la encargada de procesar los comandos que el usuario escribe en la consola o terminal.

El proyecto minishell se divide en varias partes:

1️⃣ → Análisis de la línea de comandos: en esta parte, se debe dividir la línea de comandos en distintos tokens (palabras), teniendo en cuenta las distintos espacios y caracteres especiales.

2️⃣ → Ejecución de comandos: una vez analizada la línea de comandos, se debe determinar el comando a ejecutar y sus argumentos. Luego, se debe utilizar la función execve() para ejecutar el comando en el sistema o ejecutar tu función propia si es un builtin.

3️⃣ → Gestión de errores: es importante gestionar los errores que puedan surgir durante el proceso de análisis y ejecución de la línea de comandos.

4️⃣ → Gestión de redirecciones: se deben implementar las redirecciones de entrada y salida (>, <, >>, <<) para poder redirigir la entrada y salida de los comandos a archivos.

5️⃣ → Gestión de pipes: se deben implementar los pies | para poder encadenar varios comandos y enviar la salida de un comando como entrada del siguiente.


🐚 Minishell TESTS

Tests

    echo hello ; |
    echo hello | |
    |
    echo hello |;
    echo hello ; ls
    echo hello > test\ 1
    cd $HOME/Documents
    echo "\s" & echo "\s"
    echo >
    echo -n -n -nnnn -nnnnm
    cat /dev/random | head -n 1 | cat -e
    unset var1 # with undefined var1
    export "" et unset ""
    echo test > file test1
    $
    not_cmd hello > salut
    env puis export puis env # vars aren't sorted
    cat Makefile | grep pr | head -n 5 | cd test (mybin) # check status code
    cat Makefile | grep pr | head -n 5 | cat test (bin) # check status code
    cat Makefile | grep pr | head -n 5 | hello (NA) # check status code
    echo hello >>> test
    echo hello > > out
    echo 2 >> out1 > out2
    echo 2 > out1 >> out2
    cat < test # with non-existent test
    export var; export var=test
    echo hello > $test # with test not defined
    file_name_in_current_dir
    cd ../../../../../.. ; pwd
    ctrl-C . 130 sur bin(ex : sleep 10)&line vide
    ctrl-\ .131 sur bin
    echo "bip | bip ; coyotte > < " "
    cat | cat | cat | ls # check outputs order
    $bla # with bla not defined
    export var ="cat Makefile | grep >"
    export "test=ici"=coucou
    c$var Makefile # with var=at
    $LESS$VAR
    /bin/echo hello
    not_cmd
    sleep 5 | exit
    echo hello > $test w/ t
    "exit retour a la ligne"
    minishell # binary not in path without "./" before
    cat diufosgid # check exit code
    exit # should return the last exit code value
    exit -10
    exit +10
    ;
    echo coucou | ;
    echo "$HOME"
    echo '$HOME'
    export ; env # display is different for both commands
    echo $HOME
    > log echo coucou
    echo hudifg d | | hugdfihd
    echo
    echo simple
    echo -n simple
    echo ''
    echo ""
    echo "\"
    echo "\n \n \n"
    echo "\n \n \\n"
    echo ;;
    echo hi";" hihi
    echo hi " ; " hihi
    cd
    cd .
    cd ~
    cd /
    cd no_file
    cd a b c d
    pwd a
    pwd a b c d
    export LOL=lala ROR=rara
    unset LOL ROR
    export "HI= hi"
    export "HI =hi"
    /bin/ls
    # write something the press ctrl+c
    # write something then press ctrl+d
    # write something then press ctrl+\
    echo $?
    l^Ds
    echo |
    | echo
    sort | ls # check output order
    cat < >
    cat < <
    cat > >
    > a ls > b < Makefile
    echo > a Hello World!
    > a echo Hello World!
    cat < Makefile | grep gcc > output
    exit 0 | exit 1
    exit 1 | exit 0


    export
    export a=hola
    env

    unset a=holaSSSSSS 1a=adios b=nada
    export
    unset a 1a b
    export
    

Compilación

Utiliza make -n para verificar que la compilación
utilice -Wall -Werror -Wextra

El Makefile no debe hacer relink. Si no, utiliza el flag apropiado.

Comandos simples y la variable global

Ejecuta un comando sencillo con una ruta absoluta de la forma /bin/ls, o cualquier otro comando sin argumentos.

¿Cuántas variables globales utiliza? ¿Por qué? Debe dar un ejemplo concreto de por qué le parece necesario o lógico.

Prueba un comando vacío.

Prueba solo tabuladores o espacios.

Argumentos
Ejecuta un comando simple con una ruta absoluta como /bin/ls, u otro comando con argumentos pero sin comillas simples y
comillas dobles.
Hazlo varias veces con distintos comandos y argumentos.

echo
Ejecuta el comando echo con o sin argumentos, y con o sin -n.
Hazlo múltiples veces con distintos argumentos.

exit
Ejecuta el comando exit con o sin argumentos.
Hazlo varias veces con distintos argumentos.
No olvides lanzar de nuevo minishell.

Valor de retorno de un proceso
Ejecuta una prueba simple con una ruta absoluta del tipo /bin/ls, o algún otro comando con argumentos pero sin comillas
simples o comillas dobles. Después ejecuta echo $?
Comprueba el valor devuelto. Puedes hacer lo mismo en bash y comparar ambos resultados.
Hazlo varias veces, con distintos comandos y argumentos. Ejecuta algunos comandos que fallen como '/bin/ls
archivo_que_no_existe'.
Algo como 'expr $? + $?'.

Señales
Verifica que ctrl-C en una entrada limpia muestra una nueva línea con una entrada limpia.

Verifica que ctrl-\ en una entrada limpia no hace nada.

Verifica que ctrl-D en una entrada limpia termina minishell, ejecútalo de nuevo.

Verifica que ctrl-C en una entrada con texto, muestra una nueva línea con una entrada limpia.

El buffer debería limpiarse correctamente, pulsa "enter" para verificar que nada de lo que habías escrito se ejecute.

Verifica que ctrl-D en una entrada con texto no hace nada.

Verifica que ctrl-\ en una entrada con texto no hace nada.

Verifica que ctrl-C después de ejecutar un comando bloqueante como cat sin argumentos o grep "algo".

Verifica que ctrl-\ después de ejecutar un comando bloqueante como cat sin argumentos o grep "algo".

Verifica que ctrl-D después de ejecutar un comando bloqueante como cat sin argumentos o grep "algo".


Comillas dobles
Ejecuta un comando simple con argumentos, esta vez con comillas dobles (deberías probar a incluir espacios en blanco
también).
Un comando como echo "cat lol.c | cat > lol.c"
Cualquier cosa, salvo $.

Comillas simples
Ejecuta comandos con comillas simples como argumento.
Prueba argumentos vacíos.
Prueba variables de entorno, espacios en blanco, pipes y redirecciones en las comillas simples.
echo '$USER' debe imprimir $USER.
Nada debe interpretarse.

env
Comprueba si env muestra las variables de entorno actuales

export
Exporta variables de entorno, crea nuevas, y reemplaza viejas.
Comprueba que funcione correctamente con env.

unset
Exporta variables de entorno, crea nuevas, y reemplaza viejas.
Utiliza unset para eliminar algunas de ellas.
Verifica el resultado con env.

cd
Utiliza el comando cd para cambiar de directorio de trabajo, y asegúrate de que estás en el directorio correcto con /bin/ls.
Repite esto varias veces, algunas que funcionen y otras que no.
Prueba '.' y '..' como argumentos.

pwd
Utiliza el comando pwd.
Repite esto varias veces en múltiples directorios.

Rutas relativas
Ejecuta comandos, pero esta vez con rutas relativas.
Repite esto múltiples veces en múltiples directorios con rutas relativas complejas (muchos ..)

La variable de entorno PATH
Ejecuta comandos, pero esta vez sin rutas (ls, wc, awk, etc).
Elimina $PATH y verifica que ya no funcionen.
Establece $PATH para varios directorios (directorio1:directorio2) y valida que los directorios se comprueban de izquierda a
derecha.

Redirecciones
Ejecuta comandos con redirecciones < y/o >.
Repite esto varias veces con diferentes comandos y argumentos, cambia de vez en cuando > por >>.
Comprueba si varias redirecciones del mismo tipo fallan.
Prueba la redirección << (no necesita actualizar el historial).

Pipes
Ejecuta comandos con pipes como 'cat file | grep bla | more'.
Haz esto varias veces cambiando comandos y argumentos.
Prueba algunos comandos que fallen como 'ls archivoquenoexiste | grep bla | more'.
Prueba a mezclar pipes y redirecciones.

Vuélvete loco
Escribe una línea de comandos, utiliza ctrl-C y pulsa enter. El buffer deberá estar vacío y nada deberá ejecutarse.
¿Puedes navegar en el historial con las flechas de arriba y abajo ¿Puedes volver a probar algún comando?
Ejecuta comandos que no deberían funcionar como 'wjkgjrgwg4g43go34o' y verifica que minishell no termina y muestra un
error.
"cat | cat | ls" se comporta de forma "normal".
Prueba a ejecutar un comando largo con muchísimos argumentos.
Pásatelo bien con este increíble minishell y disfruta.

Variables de entorno
Ejecuta echo con algunas $ variables como argumentos.
Verifica que $ se interpreta como una variable de entorno.
Verifica que las comillas dobles interpolan $.
Verifica que $USER existe o créalo.
echo "$USER" deberá imprimir el valor de $USER.

Bonus
Se tendrá en cuenta tus bonus si y solo si la parte obligatoria está PERFECTA. Por PERFECTA queremos naturalmente decir que la
parte obligatoria está completa, de principio a fin, y la gestión de errores es impecable, incluso en casos retorcidos o de mal uso. Si
no has conseguido todos los puntos de la parte obligatoria, la parte bonus será completamente ignorada.
And, Or
Utiliza &&, || y paréntesis con comandos y verifica que funciona como en bash.

WildCard
Utiliza wildcards en argumentos para el directorio actual.

¡Sorpresa! (O no...)
Establece la variable de entorno USER.
Prueba echo "'$USER'", esto deberá imprimir 'VALOR_DE_USER'.
Prueba echo '"$USER"', deberá imprimir "$USER
