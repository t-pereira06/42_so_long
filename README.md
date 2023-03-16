## so_long

This project is a very small 2D game.
Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements.

## Rules of the map
You must run the program with maps that have the .ber extension, in which the following parameters must be met:

◦ All map must be surrounded by walls : '1'
◦ Contain only 1 player: '1'
◦ Have 1 or more exits: 'E'
◦ Contain, at least, 1 collectible: ☞ ''


## How To Play The Game
To compile the game without enemies:
```bash
$ make
```
To compile the game with enemies:
```bash
$ make bonus
```
After compiling, execute the program, followed by the map:
```bash
$ ./so_long <map_name>.ber
```
## Controls 🎮

|Key|Action|
|---|---|
|`W`, ⬆️|UP|
|`A`, ⬅️|LEFT|
|`S`, ⬇️|DOWN|
|`D`, ➡️|RIGHT|
