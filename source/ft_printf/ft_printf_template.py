# ft_printf_template.py

from base_template import template
import os

# List of functions for documentation
functions = [
    {
        'function_name': 'ft_printf',
        'parameters': 'const char *format, ...',
        'description': 'Prints formatted output to stdout.',
        'param_types': ['const char *format', '...'],
        'param_descriptions': ['Format string for printing.', 'Variable number of arguments for formatting.'],
        'return_description': 'Returns the number of characters printed.',
		'example': [
			'ft_printf("Hello, %s!\\n", "world");',
            'ft_printf("The number is %d.\\n", 42);'
		],
		'notes': [
			'The function supports the following conversions: c, s, p, d, i, u, x, X, and %.',
            'The function uses other functions to handle conversions, from parsing the format string to printing the output.'
        ],
		'related_functions': [
			':func:`ft_dprintf`: Prints formatted output to a file descriptor.'
		],
        'output_dir': 'ft_printf'
	,
    },
	{
		'function_name': 'ft_dprintf',
		'parameters': 'int fd, const char *format, ...',
		'description': 'Prints formatted output to a file descriptor.',
		'param_types': ['int fd', 'const char *format', '...'],
		'param_descriptions': ['File descriptor to print to.', 'Format string for printing.', 'Variable number of arguments for formatting.'],
		'return_description': 'Returns the number of characters printed.',
		'example': [
			'ft_dprintf(1, "Hello, %s!\\n", "world");',
            'ft_dprintf(2, "The number is %d.\\n", 42);',
            'int fd = open("file.txt", O_WRONLY);',
            'ft_dprintf(fd, "Writing to file.\\n");',
            'close(fd);'
		],
		'notes': [
			'The function supports the following conversions: c, s, p, d, i, u, x, X, and %.'
		],
		'related_functions': [
			':func:`ft_printf`: Prints formatted output to stdout.'
		],
		'output_dir': 'ft_printf'
	}
]

def generate_rst_files():
    # Initialize content for ft_printf.rst
    ft_printf_rst_content = [
        "Ft_printf Documentation",
        "=======================",
        "",
        "This project is a recode of the printf function in C. The goal is to understand how printf works and to learn how to use variadic functions.",
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
            f"   - **{param.split()[1] if len(param.split()) > 1 else param}** (*{param.split()[0]}*): {desc}"
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
        ft_printf_rst_content.append(f"   {function['function_name']}")

    # Write to ft_printf.rst
    with open("ft_printf/ft_printf_index.rst", "w") as f:
        f.write("\n".join(ft_printf_rst_content))

    print("Updated ft_printf.rst with all functions.")

if __name__ == "__main__":
    generate_rst_files()
