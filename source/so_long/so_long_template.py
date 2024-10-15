# so_long_template.py

from base_template import template
import os

# List of functions for documentation
functions = [
    {
        'function_name': 'parse_map',
        'parameters': 't_game *game, char *file',
        'description': 'Parses the map from the file and stores it in the game struct.',
        'param_types': ['t_game *game', 'char *file'],
        'param_descriptions': [
			'Pointer to the game struct.',
			'Path to the map file.'
		],
        'return_description': 'None.',
		'example': [
			'parse_map(&game, "maps/map.ber");'
		],
		'notes': [
			'The function will exit the program if the map file is invalid.'
		],
		'related_functions': [
			':func:`render_map`: Renders the map on the screen.',
            ':func:`draw_map`: Draws the map on the screen.',
		],
   		'output_dir': 'so_long/map'	
	},
    {
        'function_name': 'render_map',
        'parameters': 't_game *game',
        'description': 'Renders the map on the screen.',
        'param_types': ['t_game *game'],
        'param_descriptions': [
			'Pointer to the game struct.'
		],
		'return_description': 'None.',
		'example': [
			'render_map(&game);'
		],
		'notes': [
			'The function will exit the program if the map is not valid.'
		],
		'related_functions': [
			':func:`parse_map`: Parses the map from the file and stores it in the game struct.',
			':func:`draw_map`: Draws the map on the screen.',
		],
		'output_dir': 'so_long/map'
	},
    {
        'function_name': 'draw_map',
        'parameters': ['t_game *game', 't_img *img', 'int pos_x', 'int pos_y'],
        'description': 'Draws the map on the screen.',
        'param_types': ['t_game *game', 't_img *img', 'int pos_x', 'int pos_y'],
        'param_descriptions': [
			'Pointer to the game struct.',
			'Pointer to the image struct.',
			'X position to draw the map.',
			'Y position to draw the map.'
		],
		'return_description': 'None.',
		'example': [
			'draw_map(&game, &img, 0, 0);'
		],
		'notes': [
			'The function will exit the program if the map is not valid.'
		],
		'related_functions': [
			':func:`parse_map`: Parses the map from the file and stores it in the game struct.',
			':func:`render_map`: Renders the map on the screen.',
		],
        'output_dir': 'so_long/map'
	},
    {
        'function_name': 'mlx_init',
		'parameters': 'void *pointer',
		'description': 'Initializes the mlx library.',
		'param_types': ['void *pointer'],
		'param_descriptions': [
			'Pointer to the mlx library.'
		],
		'return_description': 'Pointer to the mlx library.',
		'example': [
			'mlx = mlx_init();'
		],
		'notes': [
			'The function will exit the program if the mlx library cannot be initialized.'
		],
		'related_functions': [
			':func:`mlx_new_window`: Creates a new window.',
			':func:`mlx_new_image`: Creates a new image.',
            ':func:`mlx_hook`: Sets a hook function for a specific event.',
            ':func:`mlx_loop`: Starts the event loop.',
            ':func:`mlx_put_image_to_window`: Draws an image on the screen.',
            ':func:`mlx_string_put`: Draws a string on the screen.',
            ':func:`mlx_destroy_image`: Destroys the image.',
  			':func:`mlx_destroy_window`: Destroys the window.',
            ':func:`mlx_destroy_display`: Destroys the display.'
		],
		'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'mlx_new_window',
		'parameters': 'void *mlx, int width, int height, char *title',
		'description': 'Creates a new window.',
		'param_types': ['void *mlx', 'int width', 'int height', 'char *title'],
		'param_descriptions': [
			'Pointer to the mlx library.',
			'Width of the window.',
			'Height of the window.',
			'Title of the window.'
		],
    	'return_description': 'Pointer to the new window.',
		'example': [
			'win = mlx_new_window(mlx, 800, 600, "so_long");'
		],
		'notes': [
			'The function will exit the program if the window cannot be created.'
		],
		'related_functions': [
			':func:`mlx_init`: Initializes the mlx library.',
			':func:`mlx_new_image`: Creates a new image.',
			':func:`mlx_hook`: Sets a hook function for a specific event.',
			':func:`mlx_loop`: Starts the event loop.',
			':func:`mlx_put_image_to_window`: Draws an image on the screen.',
			':func:`mlx_string_put`: Draws a string on the screen.',
            ':func:`mlx_destroy_image`: Destroys the image.',
  			':func:`mlx_destroy_window`: Destroys the window.',
            ':func:`mlx_destroy_display`: Destroys the display.'
		],
		'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'mlx_new_image',
		'parameters': 'void *mlx, int width, int height',
		'description': 'Creates a new image.',
		'param_types': ['void *mlx', 'int width', 'int height'],
		'param_descriptions': [
			'Pointer to the mlx library.',
			'Width of the image.',
			'Height of the image.'
		],
		'return_description': 'Pointer to the new image.',
		'example': [
			'img = mlx_new_image(mlx, 800, 600);'
		],
		'notes': [
			'The function will exit the program if the image cannot be created.'
		],
		'related_functions': [
			':func:`mlx_init`: Initializes the mlx library.',
			':func:`mlx_new_window`: Creates a new window.',
			':func:`mlx_hook`: Sets a hook function for a specific event.',
			':func:`mlx_loop`: Starts the event loop.',
			':func:`mlx_put_image_to_window`: Draws an image on the screen.',
			':func:`mlx_string_put`: Draws a string on the screen.',
            ':func:`mlx_destroy_image`: Destroys the image.',
  			':func:`mlx_destroy_window`: Destroys the window.',
            ':func:`mlx_destroy_display`: Destroys the display.'
		],
		'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'mlx_hook',
		'parameters': 'void *win, int event, int mask, int (*funct)(), void *param',
		'description': 'Sets a hook function for a specific event.',
		'param_types': ['void *win', 'int event', 'int mask', 'int (*funct)()', 'void *param'],
		'param_descriptions': [
			'Pointer to the window.',
			'Event code.',
			'Mask code.',
			'Function pointer to the hook function.',
			'Pointer to the parameter.'
		],
		'return_description': '1 if successful, 0 otherwise.',
		'example': [
			'mlx_hook(win, 2, 1L<<0, &close_window, NULL);'
		],
		'notes': [
			'The function will exit the program if the hook function cannot be set.',
            'The function is used for handling events like key presses and mouse clicks.'
		],
        'related_functions': [
            ':func:`close_window`: Closes the window when the close button is clicked.',
            ':func:`key_press`: Handles key press events.',
			':func:`mlx_init`: Initializes the mlx library.',
			':func:`mlx_new_window`: Creates a new window.',
			':func:`mlx_new_image`: Creates a new image.',
			':func:`mlx_loop`: Starts the event loop.',
			':func:`mlx_put_image_to_window`: Draws an image on the screen.',
			':func:`mlx_string_put`: Draws a string on the screen.',
            ':func:`mlx_destroy_image`: Destroys the image.',
  			':func:`mlx_destroy_window`: Destroys the window.',
            ':func:`mlx_destroy_display`: Destroys the display.'
		],
		'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'mlx_loop',
   		'parameters': 'void *mlx',
		'description': 'Starts the event loop.',
		'param_types': ['void *mlx'],
		'param_descriptions': [
			'Pointer to the mlx library.'
		],
		'return_description': 'None.',
		'example': [
			'mlx_loop(mlx);'
		],
		'notes': [
			'The function will exit the program if the event loop cannot be started.',
            'The function will continue to run until the window is closed.',
		],
		'related_functions': [
			':func:`mlx_init`: Initializes the mlx library.',
			':func:`mlx_new_window`: Creates a new window.',
			':func:`mlx_new_image`: Creates a new image.',
			':func:`mlx_hook`: Sets a hook function for a specific event.',
			':func:`mlx_put_image_to_window`: Draws an image on the screen.',
			':func:`mlx_string_put`: Draws a string on the screen.',
            ':func:`mlx_destroy_image`: Destroys the image.',
  			':func:`mlx_destroy_window`: Destroys the window.',
            ':func:`mlx_destroy_display`: Destroys the display.'
		],
        'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'mlx_put_image_to_window',
		'parameters': 'void *mlx, void *win, void *img, int x, int y',
		'description': 'Draws an image on the screen.',
		'param_types': ['void *mlx', 'void *win', 'void *img', 'int x', 'int y'],
		'param_descriptions': [
			'Pointer to the mlx library.',
			'Pointer to the window.',
			'Pointer to the image.',
			'X position to draw the image.',
			'Y position to draw the image.'
		],
		'return_description': 'None.',
		'example': [
			'mlx_put_image_to_window(mlx, win, img, 0, 0);'
		],
		'notes': [
			'The function will exit the program if the image cannot be drawn.',
            'The function is used for drawing images on the screen.',
            'The function will draw the image at the specified position (x, y).'
		],
        'related_functions': [
			':func:`mlx_init`: Initializes the mlx library.',
			':func:`mlx_new_window`: Creates a new window.',
			':func:`mlx_new_image`: Creates a new image.',
			':func:`mlx_hook`: Sets a hook function for a specific event.',
			':func:`mlx_loop`: Starts the event loop.',
			':func:`mlx_string_put`: Draws a string on the screen.',
            ':func:`mlx_destroy_image`: Destroys the image.',
  			':func:`mlx_destroy_window`: Destroys the window.',
            ':func:`mlx_destroy_display`: Destroys the display.'
		],
		'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'mlx_string_put',
		'parameters': 'void *mlx, void *win, int x, int y, int color, char *str',
		'description': 'Draws a string on the screen.',
		'param_types': ['void *mlx', 'void *win', 'int x', 'int y', 'int color', 'char *str'],
		'param_descriptions': [
			'Pointer to the mlx library.',
			'Pointer to the window.',
			'X position to draw the string.',
			'Y position to draw the string.',
			'Color of the string.',
			'String to draw.'
		],
		'return_description': 'None.',
		'example': [
			'mlx_string_put(mlx, win, 100, 100, 0xFFFFFF, "Hello, World!");'
		],
		'notes': [
			'The function will exit the program if the string cannot be drawn.',
			'The function is used for drawing strings on the screen.',
			'The function will draw the string at the specified position (x, y).'
		],
		'related_functions': [
			':func:`mlx_init`: Initializes the mlx library.',
			':func:`mlx_new_window`: Creates a new window.',
			':func:`mlx_new_image`: Creates a new image.',
			':func:`mlx_hook`: Sets a hook function for a specific event.',
			':func:`mlx_loop`: Starts the event loop.',
			':func:`mlx_put_image_to_window`: Draws an image on the screen.',
            ':func:`mlx_destroy_image`: Destroys the image.',
  			':func:`mlx_destroy_window`: Destroys the window.',
            ':func:`mlx_destroy_display`: Destroys the display.'

		],
		'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'close_window',
		'parameters': 'void *param',
		'description': 'Closes the window when the close button is clicked.',
		'param_types': ['void *param'],
		'param_descriptions': [
			'Pointer to the parameter.'
		],
		'return_description': 'exit(0) if successful, exit(1) otherwise.',
		'example': [
            'mlx_hook(win, 17, 1L<<0, &close_window, &game);',
            '// 17 is the event code for the close button.',
            '// 1L<<0 is the mask code for the close button.'
		],
		'notes': [
			'The function is used as a hook function for closing the window when the close button is clicked.'
		],
		'related_functions': [
			':func:`mlx_hook`: Sets a hook function for a specific event.'
		],
		'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'key_press',
		'parameters': 'int keycode, void *param',
        'description': 'Handles key press events.',
		'param_types': ['int keycode', 'void *param'],
		'param_descriptions': [
			'Keycode of the key pressed.',
			'Pointer to the parameter.'
		],
		'return_description': 'return (0) if successful, return (1) otherwise.',
		'example': [
			'mlx_hook(win, 2, 1L<<0, &key_press, &game);',
            '// 2 is the event code for key press events.',
            '// 1L<<0 is the mask code for key press events.'
		],
		'notes': [
			'The function is used as a hook function for handling key press events.'
		],
		'related_functions': [
            ':func:`close_window`: Closes the window when the close button is clicked.',
			':func:`mlx_hook`: Sets a hook function for a specific event.'
		],
		'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'mlx_destroy_image',
		'parameters': 'void *mlx, void *img',
        'description': 'Destroys the image.',
		'param_types': ['void *mlx', 'void *img'],
		'param_descriptions': [
			'Pointer to the mlx library.',
			'Pointer to the image.'
		],
		'return_description': '1 if successful, 0 otherwise.',
		'example': [
			'mlx_destroy_image(mlx, img);'
		],
		'notes': [
			'The function will exit the program if the image cannot be destroyed.',
            'The function is used for freeing the memory allocated for the image.',
            'The function will crash if the image is not valid.',
            'The function will crash if the mlx library is not valid.'
		],
		'related_functions': [
			':func:`mlx_init`: Initializes the mlx library.',
			':func:`mlx_new_window`: Creates a new window.',
			':func:`mlx_new_image`: Creates a new image.',
			':func:`mlx_hook`: Sets a hook function for a specific event.',
			':func:`mlx_loop`: Starts the event loop.',
			':func:`mlx_put_image_to_window`: Draws an image on the screen.',
			':func:`mlx_string_put`: Draws a string on the screen.',
			':func:`mlx_destroy_window`: Destroys the window.',
            ':func:`mlx_destroy_display`: Destroys the display.'
		],
		'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'mlx_destroy_window',
		'parameters': 'void *mlx, void *win',
        'description': 'Destroys the window.',
		'param_types': ['void *mlx', 'void *win'],
		'param_descriptions': [
			'Pointer to the mlx library.',
			'Pointer to the window.'
		],
		'return_description': '1 if successful, 0 otherwise.',
		'example': [
			'mlx_destroy_window(mlx, win);'
		],
		'notes': [
			'The function will exit the program if the window cannot be destroyed.',
			'The function is used for freeing the memory allocated for the window.',
			'The function will crash if the window is not valid.',
			'The function will crash if the mlx library is not valid.'
		],
		'related_functions': [
			':func:`mlx_init`: Initializes the mlx library.',
			':func:`mlx_new_window`: Creates a new window.',
			':func:`mlx_new_image`: Creates a new image.',
			':func:`mlx_hook`: Sets a hook function for a specific event.',
			':func:`mlx_loop`: Starts the event loop.',
			':func:`mlx_put_image_to_window`: Draws an image on the screen.',
			':func:`mlx_string_put`: Draws a string on the screen.',
            ':func:`mlx_destroy_image`: Destroys the image.',
            ':func:`mlx_destroy_display`: Destroys the display.'
		],
		'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'mlx_destroy_display',
		'parameters': 'void *mlx',
        'description': 'Destroys the display.',
		'param_types': ['void *mlx'],
		'param_descriptions': [
			'Pointer to the mlx library.'
		],
		'return_description': '1 if successful, 0 otherwise.',
		'example': [
			'mlx_destroy_display(mlx);'
		],
		'notes': [
			'The function will exit the program if the display cannot be destroyed.',
			'The function is used for freeing the memory allocated for the display.',
			'The function will crash if the display is not valid.',
			'The function will crash if the mlx library is not valid.'
		],
		'related_functions': [
			':func:`mlx_init`: Initializes the mlx library.',
			':func:`mlx_new_window`: Creates a new window.',
			':func:`mlx_new_image`: Creates a new image.',
			':func:`mlx_hook`: Sets a hook function for a specific event.',
			':func:`mlx_loop`: Starts the event loop.',
			':func:`mlx_put_image_to_window`: Draws an image on the screen.',
			':func:`mlx_string_put`: Draws a string on the screen.',
			':func:`mlx_destroy_image`: Destroys the image.',
			':func:`mlx_destroy_window`: Destroys the window.',
		],
        'output_dir': 'so_long/mlx'
	},
    {
        'function_name': 'init_checked',
		'parameters': 't_game *game',
        'description': 'Initializes a grid to keep track of checked positions.',
		'param_types': ['t_game *game'],
		'param_descriptions': [
			'Pointer to the game struct.'
		],
		'return_description': 'Pointer to the grid.',
		'example': [
			'char **checked = init_checked(&game);'
		],
		'notes': [
			'The function will exit the program if the grid cannot be initialized.'
		],
		'related_functions': [
            ':func:`flood_fill`: Fills the area around the player with a specific character to mark it as checked.',
            ':func:`check_reachability`: Checks if the player can reach the exit and all collectibles.'
		],
        'output_dir': 'so_long/checks'
	},
    {
        'function_name': 'flood_fill',
		'parameters': 't_game *game, int x, int y, char **checked',
        'description': 'Fills the area around the player with a specific character to mark it as checked.',
		'param_types': ['t_game *game', 'int x', 'int y', 'char **checked'],
		'param_descriptions': [
			'Pointer to the game struct.',
			'X position of the player.',
			'Y position of the player.',
			'Pointer to the grid of checked positions.'
		],
		'return_description': 'None.',
		'example': [
            'grid before:',
            '1 1 1 1 1'
            '1 0 E 1 1'
            '1 C C P 1'
            '1 1 1 1 1'
            'char **checked = init_checked(&game);'
			'flood_fill(&game, game.player.x, game.player.y, checked);'
            'grid after:',
            '1 1 1 1 1'
            '1 F F 1 1'
            '1 F F F 1'
            '1 1 1 1 1'
		],
		'notes': [
			'The function will exit the program if the area cannot be filled.'
		],
		'related_functions': [
			':func:`init_checked`: Initializes a grid to keep track of checked positions.',
			':func:`check_reachability`: Checks if the player can reach the exit and all collectibles.'
		],
		'output_dir': 'so_long/checks'
	},
    {
        'function_name': 'check_reachability',
		'parameters': 't_game *game',
        'description': 'Checks if the player can reach the exit and all collectibles.',
		'param_types': ['t_game *game'],
		'param_descriptions': [
			'Pointer to the game struct.'
		],
		'return_description': '1 if successful, 0 otherwise.',
		'example': [
			'check_reachability(&game);'
		],
		'notes': [
			'The function will exit the program if the player cannot reach the exit and all collectibles.'
		],
		'related_functions': [
			':func:`init_checked`: Initializes a grid to keep track of checked positions.',
			':func:`flood_fill`: Fills the area around the player with a specific character to mark it as checked.'
		],
		'output_dir': 'so_long/checks'
	}
]

# Define your function categories and their corresponding directories
categories = {
    "Map Functions": "map",
    "Check Functions": "checks",
    "Mlx Functions": "mlx",
}

# Generate .rst files for each function
def generate_rst_files():
    # Initialize content for so_long.rst
    so_long_rst_content = [
        "So_long Documentation",
        "===================",
        "",
        "This project is about creating a 2D game.",
        ""
    ]

    # Initialize a dictionary to keep track of function entries for each category
    category_entries = {category: [] for category in categories.keys()}

    for function in functions:
        # Create the .rst filename
        rst_filename = os.path.join(function['output_dir'], f"{function['function_name']}.rst")
        
        print(f"Creating output directory: {function['output_dir']}")
        os.makedirs(function['output_dir'], exist_ok=True)

        # Prepare param_descriptions as a formatted string
        param_descriptions_formatted = "\n".join(
            f"   - **{param.split()[1]}** (*{param.split()[0]}*): {desc}"
            for param, desc in zip(function['param_types'], function['param_descriptions'])
        )

        # Prepare param_types as a formatted string
        param_types_formatted = "\n   ".join(f":param {param_type}:" for param_type in function['param_types'])

        # Prepare notes as a formatted string
        notes_formatted = "\n   ".join(f"- {note}" for note in function['notes'])

        # Prepare related functions as a formatted string in list format
        related_functions_formatted = "\n   ".join(f"- {func}" for func in function['related_functions'])

        # Prepare example as a formatted string
        example_formatted = "\n       ".join(line for line in function['example'])

        # Fill in the template with function details
        with open(rst_filename, 'w') as f:
            print(f"Writing RST content for {function['function_name']} to {rst_filename}...")
            f.write(template.format(
                param_descriptions=param_descriptions_formatted,
                notes=notes_formatted,
                related_functions=related_functions_formatted,
                example=example_formatted,
                function_name=function['function_name'],
                parameters=function['parameters'],
                description=function['description'],
                param_types=function['param_types'],
                return_description=function['return_description']
            ))

        print(f"Generated documentation for {function['function_name']} in {rst_filename}.")

        # Determine the category of the function and add it to the category_entries
        for category, directory in categories.items():
            if directory in function['output_dir']:
                category_entries[category].append(f"{directory}/{function['function_name']}")
                break

    # Now, generate the so_long.rst content based on category_entries
    for category, entries in category_entries.items():
        underline = "-" * len(category)
        so_long_rst_content.append(f"{category}\n{underline}")
        so_long_rst_content.append("\n.. toctree::\n   :maxdepth: 2\n")
        so_long_rst_content.extend(f"   {entry}" for entry in entries)
        so_long_rst_content.append("")  # Add a newline after each category

    # Write to so_long.rst
    with open("so_long/so_long_index.rst", "w") as f:
        f.write("\n".join(so_long_rst_content))

    print("Updated so_long.rst with all functions.")

if __name__ == "__main__":
    generate_rst_files()
