## so_long

This project is a very small 2D game.
Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements.

## Rules of the map
You must run the program with maps that have the .ber extension, in which the following parameters must be met:

◦ All map must be surrounded by walls : '1'


◦ Contain only 1 player: 'P'


◦ Have 1 or more exits: 'E'


◦ Contain, at least, 1 collectible: 'C'


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
$ ./so_long_bonus <map_name>.ber
```
After playing the game, if you want to clean the object files, execute:
```bash
$ make fclean

```
## Requirements of evaluation:

Sorting 3 values: no more than 3 moves.

Sorting 5 values: no more than 12 moves.

Sorting 100 values: rating from 1 to 5 points depending on the number of moves:
   - 5 points for less than 700
   - 4 points for less than 900
   - 3 points for less than 1100
   - 2 points for less than 1300
   - 1 point for less than 1500

Sorting 500 values: rating from 1 to 5 points depending on the number of moves:
   - 5 points for less than 5500
   - 4 points for less than 7000
   - 3 points for less than 8500
   - 2 points for less than 10000
   - 1 point for less than 11500

## Controls 🎮

|Key|Action|
|---|---|
|`W`, ⬆️|UP|
|`A`, ⬅️|LEFT|
|`S`, ⬇️|DOWN|
|`D`, ➡️|RIGHT|

## Grade:
