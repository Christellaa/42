# gnl_template.py

from base_template import template
import os

# List of functions for documentation
functions = [
    {
        'function_name': 'get_next_line',
        'parameters': 'int fd',
        'description': 'Reads a line from a file descriptor.',
        'param_types': ['int fd'],
        'param_descriptions': ['File descriptor for reading.'],
        'return_description': 'Returns a line read from the file descriptor.',
		'example': [
			'char *line;',
			'int fd = open("file.txt", O_RDONLY);',
			'while ((line = get_next_line(fd)))',
			'    printf("%s", line);',
			'close(fd);'
		],
        'notes': [
            'The line read includes the newline character.',
			'The function returns NULL when the reading is finished.',
            'The function uses a static buffer to store the read data.',
            'The function uses a buffer size and multiple file descriptors.'
        ],
        'related_functions': [
            ':func:`read_until_newline_or_eof`: Reads from a file descriptor until a newline character or EOF is found.',
            ':func:`extract_line`: Extracts a line from a buffer.',
            ':func:`keep_rest`: Keeps the remaining data in the buffer.'
		],
		'output_dir': 'get_next_line'
	},
    {
        'function_name': 'read_until_newline_or_eof',
        'parameters': 'int fd, char **buffer',
        'description': 'Reads from a file descriptor until a newline character or EOF is found.',
        'param_types': ['int fd', 'char **buffer'],
        'param_descriptions': ['File descriptor for reading.', 'Buffer to store the read data.'],
        'return_description': 'Returns the number of bytes read.',
		'example': [
			'char *buffer = NULL;',
			'int fd = open("file.txt", O_RDONLY);',
			'read_until_newline_or_eof(fd, &buffer);',
			'printf("%s", buffer);',
			'free(buffer);',
			'close(fd);'
		],
        'notes': [
            'The buffer is reallocated to fit the read data.',
			'The buffer is NULL-terminated.'],
		'related_functions': [
			':func:`get_next_line`: Reads a line from a file descriptor.',
			':func:`extract_line`: Extracts a line from a buffer.',
			':func:`keep_rest`: Keeps the remaining data in the buffer.'
		],
		'output_dir': 'get_next_line'
	},
    {
        'function_name': 'extract_line',
        'parameters': 'char *buffer',
        'description': 'Extracts a line from a buffer.',
        'param_types': ['char *buffer'],
        'param_descriptions': ['Buffer containing the data.'],
        'return_description': 'Returns a line extracted from the buffer.',
		'example': [
			'char *buffer = "Hello, World!\\nThis is a test.";',
			'char *line = extract_line(buffer);',
			'printf("%s", line);',
			'free(line);'
		],
        'notes': [
			'The line includes the newline character.',
			'The buffer is reallocated to fit the remaining data.'
		],
		'related_functions': [
			':func:`get_next_line`: Reads a line from a file descriptor.',
			':func:`read_until_newline_or_eof`: Reads from a file descriptor until a newline character or EOF is found.',
			':func:`keep_rest`: Keeps the remaining data in the buffer.'
		],
		'output_dir': 'get_next_line'
	},
    {
        'function_name': 'keep_rest',
        'parameters': 'char *buffer',
        'description': 'Keeps the remaining data in the buffer.',
        'param_types': ['char *buffer'],
        'param_descriptions': ['Buffer containing the data.'],
        'return_description': 'Returns the remaining data in the buffer.',
		'example': [
			'char *buffer = "Hello, World!\\nThis is a test.";',
			'char *rest = keep_rest(buffer);',
			'printf("%s", rest);',
			'free(rest);'
		],
        'notes': [
			'The buffer is reallocated to fit the remaining data.',
			'The buffer is NULL-terminated.'
		],
		'related_functions': [
			':func:`get_next_line`: Reads a line from a file descriptor.',
			':func:`read_until_newline_or_eof`: Reads from a file descriptor until a newline character or EOF is found.',
			':func:`extract_line`: Extracts a line from a buffer.'
		],
		'output_dir': 'get_next_line'
	}
]

def generate_rst_files():
    # Initialize content for gnl.rst
    gnl_rst_content = [
        "Get Next Line Documentation",
        "===========================",
        "",
        "This project is about reading a line and returning it with a newline character or EOF if there is nothing else to read.",
        "",
        ".. toctree::",
        "   :maxdepth: 2",
        "",
    ]

    # Iterate through each function to generate .rst files
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

        # Add the .rst file to the toctree
        gnl_rst_content.append(f"   {function['function_name']}")

    # Write to gnl.rst
    with open("get_next_line/gnl_index.rst", "w") as f:
        f.write("\n".join(gnl_rst_content))

    print("Updated gnl.rst with all functions.")

if __name__ == "__main__":
    generate_rst_files()
