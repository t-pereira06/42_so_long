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

## Controls 🎮

|Key|Action|
|---|---|
|`W`, ⬆️|UP|
|`A`, ⬅️|LEFT|
|`S`, ⬇️|DOWN|
|`D`, ➡️|RIGHT|

## Gameplay
Mandatory:
![simplescreenrecorder-2023-04-17_15 04 52](https://user-images.githubusercontent.com/118270669/232509337-65d77d14-2625-4e7e-8e16-012988998535.gif)
Bonus:
![simplescreenrecorder-2023-04-17_15 06 18](https://user-images.githubusercontent.com/118270669/232509272-58d16ea3-e8fc-4149-8839-1db7790c4501.gif)



