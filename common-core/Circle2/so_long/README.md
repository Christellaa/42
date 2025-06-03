# SO_LONG
This a small 2D game where the player moves on a map to collect items to be able to reach the exit.
As a bonus there are enemies that move semi-randomly each time the player moves.

## Technologies used
- Language
	- C
- Tools
	- Makefile, [Minilibx](https://github.com/42paris/minilibx-linux)
- Norm
	- [42 norminette](https://github.com/42school/norminette)

## What I learned
- Use a graphical library
- Event handling and key mapping
- Parse map files
- Validate game maps using flood fill
- Structure a game loop

## How to run
```make```
OR
```make bonus```

### Example usage
```
make
./so_long maps/valid/map0.ber

make bonus
./so_long_bonus maps/valid/bonus/map0b.ber
```

## Credits
For the assets (that I modified to make them larger) beside the exit textures:
[Cup Nooble](https://cupnooble.itch.io/)
