# About
So long is a simple 2D game implemented using the mlx library from 42 school. Your goal is to collect all the collectibles on the map (torches) without beeing caught by enemies. You'll be able able to exit the game through the exit door only if you collect all collectibles present on the map. Use the arrows to move, and press escape or close window if you want to exit the game prematurely.

<img src="demo.gif" width="100%"/>

# Usage
`git clone` and `cd` into the directory. Then hit `make` if you are a linux user or `make MODE=mac` a macOS user. The makefile will generate a `so_long` executable. If you want more features (enemies, move counter on screen) hit `make bonus MODE=your_OS`. Then run:
```shell
./so_long maps/<file_name>
```
# Norme

All 42 projects must be written following the **Norme**.

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
 	- Each line must be at most 80 columns wide, comments included
	- A function can take 4 named parameters maximum
	- No more than 5 variables in 1 function
