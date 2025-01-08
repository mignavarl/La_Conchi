🐚 Minishell
Descripción

El objetivo del proyecto es desarrollar una shell , es decir, un intérprete de líneas de comandos de forma sencilla y completa. Utilizando las técnicas y conocimientos adquiridos durante el curso. La shell es una parte fundamental del sistema operativo y es la encargada de procesar los comandos que el usuario escribe en la consola o terminal.

El proyecto minishell se divide en varias partes:

1️⃣ → Análisis de la línea de comandos: en esta parte, se debe dividir la línea de comandos en distintos tokens (palabras), teniendo en cuenta las distintos espacios y caracteres especiales.

2️⃣ → Ejecución de comandos: una vez analizada la línea de comandos, se debe determinar el comando a ejecutar y sus argumentos. Luego, se debe utilizar la función execve() para ejecutar el comando en el sistema o ejecutar tu función propia si es un builtin.

3️⃣ → Gestión de errores: es importante gestionar los errores que puedan surgir durante el proceso de análisis y ejecución de la línea de comandos.

4️⃣ → Gestión de redirecciones: se deben implementar las redirecciones de entrada y salida (>, <, >>, <<) para poder redirigir la entrada y salida de los comandos a archivos.

5️⃣ → Gestión de pipes: se deben implementar los pies | para poder encadenar varios comandos y enviar la salida de un comando como entrada del siguiente.


🐚 Minishell TEST


🔴 TEST 1: ECHO BASIC COMMANDS

echo hello ; |
echo hello | |
|
echo hello |;
echo hello ; ls

🟠 TEST 2: REDIRECT OUTPUT

echo hello > test\ 1
echo hello >>> test
echo hello > > out
echo 2 >> out1 > out2
echo 2 > out1 >> out2
echo hello > $test w/ t

🟡 TEST 3: HANDLE VARIOUS COMMANDS

unset var1 # with undefined var1
export "" and unset ""
echo test > file test1
not_cmd hello > salut
export var; export var=test
echo hello > $test # with test not defined

🟢 TEST 4: TESTING WITH PIPES AND CHAINS

cat | cat | cat | ls # check outputs order
echo "bip | bip ; coyote > < " "
cat Makefile | grep pr | head -n 5 | cd test (mybin) # check status code
cat Makefile | grep pr | head -n 5 | cat test (bin) # check status code
echo "$HOME"
echo '$HOME'
echo "\n \n \n"

🔵 TEST 5: CD COMMANDS

cd
cd .
cd ~
cd /
cd no_file
cd a b c d
pwd a
pwd a b c d

🟣 TEST 6: VARS AND EXPORTS

export LOL=lala ROR=rara
unset LOL ROR
export "HI= hi"
export "HI =hi"

🟤 TEST 7: PIPES AND REDIRECTIONS COMBINED

cat < >
cat < <
cat > >
> a ls > b < Makefile
echo > a Hello World!
> a echo Hello World!
cat < Makefile | grep gcc > output

🟠 TEST 8: EXITS AND ERROR HANDLING

exit 0 | exit 1
exit 1 | exit 0
exit -10
exit +10

🟡 TEST 9: MISC COMMANDS AND VARIABLES

echo $HOME
echo $ ?
echo
echo simple
echo -n simple
echo ''
echo ""

🔴 TEST 10: CTRL COMMANDS

# write something then press ctrl+c
# write something then press ctrl+d
*# write something then press ctrl+*

🟢 TEST 11: MORE EDGE CASES

cat non_existing_file | echo "should handle non-existent files gracefully"
echo test >> test && cat test | wc -l
echo -n 'check' && echo 'check' | grep -v "check"
echo "multiple | pipe | handling | test" | tr '|' '\n'

¡Listo para copiar y pegar!
You said:
son exactamente los mismos test, veo menos
ChatGPT said:
ChatGPT

Mis disculpas por la confusión. Te paso una versión con más tests adicionales y más exhaustivos. Aquí tienes la lista revisada con más pruebas y en formato llamativo:

🔴 TEST 1: ECHO BASIC COMMANDS
echo hello ; |
echo hello | |
|
echo hello |;
echo hello ; ls
echo hello > test\ 1
echo hello >>> test
echo hello > > out
echo 2 >> out1 > out2
echo 2 > out1 >> out2

🟠 TEST 2: HANDLING UNDEFINED VARIABLES AND EXPORT
unset var1 # with undefined var1
export "" et unset ""
echo test > file test1
not_cmd hello > salut
env puis export puis env # vars aren't sorted
export var; export var=test
echo hello > $test # with test not defined
export LOL=lala ROR=rara
unset LOL ROR
export "HI= hi"
export "HI =hi"

🟡 TEST 3: PIPES AND CHAINING COMMANDS
cat | cat | cat | ls # check outputs order
echo "bip | bip ; coyote > < " "
cat Makefile | grep pr | head -n 5 | cd test (mybin) # check status code
cat Makefile | grep pr | head -n 5 | cat test (bin) # check status code
echo "$HOME"
echo '$HOME'
echo "\n \n \n"
echo "\n \n \n"
echo coucou | ;
echo "$HOME"
echo '$HOME'

🟢 TEST 4: CD AND PWD COMMANDS
cd
cd .
cd ~
cd /
cd no_file
cd a b c d
pwd a
pwd a b c d
cd ../../../../../.. ; pwd

🔵 TEST 5: FILE HANDLING AND REDIRECTS
echo > a Hello World!
> a echo Hello World!
cat < Makefile | grep gcc > output
cat < >
cat < <
cat > >
> a ls > b < Makefile
cat /dev/random | head -n 1 | cat -e

🟣 TEST 6: CONTROL COMMANDS AND SIGNALS
# write something then press ctrl+c
# write something then press ctrl+d
*# write something then press ctrl+*
ctrl-C . 130 sur bin (ex : sleep 10) & line vide
ctrl-\ .131 sur bin

🟤 TEST 7: EXITS AND ERROR HANDLING
exit 0 | exit 1
exit 1 | exit 0
exit -10
exit +10
echo $?

🟠 TEST 8: MISCELLANEOUS TEST CASES
cat non_existing_file | echo "should handle non-existent files gracefully"
echo test >> test && cat test | wc -l
echo -n 'check' && echo 'check' | grep -v "check"
echo "multiple | pipe | handling | test" | tr '|' '\n'
echo "this is a test" | tr ' ' '\n'
echo -n simple
echo ""

🟡 TEST 9: SPECIAL CHARACTERS HANDLING
echo "check$HOME"
echo "$HOME"
echo "\n \n \n"
echo "\n"

🟢 TEST 10: ENVIRONMENT AND SHELL VARIABLES
export HOME=$PWD
export TESTVAR=test123
echo $HOME
echo $TESTVAR
env
env | grep TESTVAR

🔴 TEST 11: INVALID COMMANDS AND ERROR CODES
not_cmd hello > salut
echo $?

🟣 TEST 12: VARIOUS COMBINATIONS OF PIPE AND REDIRECT
echo "This is a test" | cat > testfile
cat testfile
echo "This is another test" | tee testfile
cat testfile

🔵 TEST 13: MULTIPLE COMMANDS IN A LINE
echo "Hello" ; echo "World"
echo "First" && echo "Second" && echo "Third"
echo "One" || echo "Two"

🟠 TEST 14: VALID AND INVALID FILE HANDLING
cat Makefile | grep gcc > output
cat < Makefile | grep gcc > output
cat < non_existing_file

🟡 TEST 15: VALIDATING EXIT CODES AND STDERR
echo "Test with wrong command" | not_cmd
echo $?

🟢 TEST 16: RECURSION AND PATH NAVIGATION
cd ../../../../../.. ; pwd
cd ~/Documents; pwd
cd $HOME

🔴 TEST 17: HANDLING INVALID COMMANDS AND ARGUMENTS
cat Makefile | grep pr | head -n 5 | hello (NA) # check status code
$bla # with bla not defined

🟣 TEST 18: COMBINING MULTIPLE INPUTS AND OUTPUTS
echo "combine | test | echo" | cat | tee testfile

🟤 TEST 19: PIPE AND ERRORS COMBINATION
echo "test" | non_existing_command | cat
echo $?
    
