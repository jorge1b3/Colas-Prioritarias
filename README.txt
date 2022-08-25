Como compilar

Para sistemas tipo unix, con cmake y make instaladas

cmake CMakeList.txt && make

Para windows, se puede utilizar Visual Studio (tiene compatibilidad con cmake).
Si se tiene mingw, se puede compilar habriendo una terminal en la carpeta, y escribiendo

g++ *.cpp -o main.exe
