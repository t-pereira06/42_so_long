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

##Video Examples:
[simplescreenrecorder-2023-04-17_14.46.17.webm]

## Controls 🎮

|Key|Action|
|---|---|
|`W`, ⬆️|UP|
|`A`, ⬅️|LEFT|
|`S`, ⬇️|DOWN|
|`D`, ➡️|RIGHT|

## Grade:
(https://user-images.githubusercontent.com/118270669/232503457-4859a486-8188-49e9-be82-ae228e1f8b22.webm)
