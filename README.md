# kalah_game
>Kalah or Mankalah game in c using sdl.

## Presentation 
`Kalah` is a game in which each user tries to get the maximum of score in the main hole (Kalah). 
At each time the player has to find which hole to choose so that the pieces in there will be distributed equaly and sequentiely on each hole of the board. Also one have to think of the best choice carefully so that he or she won't give a bonus score to the oponent.

1. The game start by showing the main options board to the player:
![main options board](src/OptionsMenu.bmp)
2. Then the player can initiate the number of pieces in all the holes of the board so that the game start:
![initialization board](src/InitialisationBoard.bmp)
3. The game start then and the user can choose a hole by clicking it:
![game board](src/GameBoard.bmp)
4. Finally the smarter wins!


<p align="center">
      <img align="center"  width="50%" src="src/Player1Win.bmp"/>
      <img align="center"  width="50%" src="src/Player2Win.bmp"/>
</p>

***

### Befor you use this code remember...
Please remember that you need to set up you work space so that you can use sdl2 and sdl ttf and sdl image.

***

### How to run this code

It is simple to run the code. In the section below we are going to work through two methods to run the code.

1. Using `CMake`, (this example is for linux. However, using the same`CMakeLists.txt` you can run the application.)

```sh
# Create the build directory
$ mkdir ./build
# Configure the CMakeLists.txt project
$ cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc -Hkalah_game -Bkalah_game/build -G "Unix Makefiles"
# Build the Project
$ cmake --build /home/kotbi/Documents/Projects/kalah_game/build --config Debug --target all -j 6 --
# Run the game
$ cd build
$ ./kalah
```

2. Using the Makefile commands. this is an easy way to run the application, since all commands follow one pattern:

```sh
# Create obj directory
$ mkdir obj
$ make command
``` 
The commands in the Makefile are: `all`, `clean` and so on. However, the clean commands depend on the os you are using: `cleanw`, `cleandepw` in Windows, while  `clean`, `cleandep`. After building the project you can run it like this:

```sh
$ ./kalah
``` 
>Also, remember to create src/include directory and put the sdl librairies there, if you didn't install them globaly.

If you are using vscode you can run and debug the code easly using the following launch.json file to configure `gdb`:

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/kalah",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```
