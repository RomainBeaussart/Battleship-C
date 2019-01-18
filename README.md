# Battlesheep

* _Project name_: battlesheep.
* _Student project_: creation of a networked naval battle game (Battleship-like).
* _Programming language_: C.
* _Maintainers_: Louis Singer & Romain Beaussart, Software Engineering students at Efrei Paris.

# Features

The game is a networked battleship-like using TCP sockets with C language. See below a list of features. Features in __bold__ are implemented.
* __Client/Server implementation__.
* __Game objects (ships, player, game boards...)__.
* An artificial intelligence for playing against the computer.

# Project description

The projects repository is composed by three folders which divide code.
* __AI__ for the artificial intelligence.
* __Board__ for the game boards and their features.
* __Ship__ for the ships.
* __main__ for the main game functions.

# Play

You need to use `game`.

Launch a server:
```bash
#Command
./game server PORT_NUMBER
#Example
./game server 8000
```

Connect client to a server
```bash
#Command
./game client SERVER_ADDRESS PORT_NUMBER
#Example
./game client 127.0.0.1 8000
```

# Build sources

```bash
gcc -o game main/*.c Board/*.c Ship/*.c
gcc -Wall -Wextra -Werror --std=c99 -o game main/*.c Board/*.c Ship/*.c
```

