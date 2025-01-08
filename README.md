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

    echo bonjour ; |
    echo bonjour | |
    |
    echo bonjour |;
    echo bonjour ; ls
    echo bonjour > test\ 1
    cd $HOME/Documents
    echo "\s" & echo "\s"
    echo >
    echo -n -n -nnnn -nnnnm
    cat /dev/random | head -n 1 | cat -e
    unset var1 # with undefined var1
    export "" et unset ""
    echo test > file test1
    $
    not_cmd bonjour > salut
    env puis export puis env # vars aren't sorted
    cat Makefile | grep pr | head -n 5 | cd test (mybin) # check status code
    cat Makefile | grep pr | head -n 5 | cat test (bin) # check status code
    cat Makefile | grep pr | head -n 5 | hello (NA) # check status code
    echo bonjour >>> test
    echo bonjour > > out
    echo 2 >> out1 > out2
    echo 2 > out1 >> out2
    cat < test # with non-existent test
    export var; export var=test
    echo bonjour > $test # with test not defined
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
    /bin/echo bonjour
    not_cmd
    sleep 5 | exit
    echo bonjour > $test w/ t
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


