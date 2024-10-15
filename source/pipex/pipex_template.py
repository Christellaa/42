# pipex_template.py

from base_template import template
import os

# List of functions for documentation
functions = [
    {
        'function_name': 'wait_pids',
        'parameters': 't_pipex *pipex',
        'description': 'Waits for all child processes to finish.',
        'param_types': ['t_pipex *pipex'],
        'param_descriptions': ['Pointer to the pipex structure.'],
        'return_description': 'None.',
        'example': [
			'wait_pids(pipex);'
		],
		'notes': [
			'The function waits for all child processes to finish before returning.',
            'The function uses the waitpid system call to wait for child processes.',
            'The function takes as exit code the status of the last child process of the pipeline.'
		],
		'related_functions': [
            ':func:`create_pipes`: Creates pipes for each command in the pipeline.',
			':func:`dup_files`: Duplicates file descriptors for the command.',
			':func:`children`: Creates child processes for each command in the pipeline.',
			':func:`exec_cmd`: Executes a command in a child process.'
		],
		'output_dir': 'pipex'
	},
	{
		'function_name': 'create_pipes',
		'parameters': 't_pipex *pipex',
		'description': 'Creates pipes for each command in the pipeline.',
		'param_types': ['t_pipex *pipex'],
		'param_descriptions': ['Pointer to the pipex structure.'],
		'return_description': 'None.',
		'example': [
			'create_pipes(pipex);'
		],
		'notes': [
			'The function creates pipes for each command in the pipeline.',
			'The function uses the pipe system call to create pipes.'
		],
		'related_functions': [
            ':func:`wait_pids`: Waits for all child processes to finish.',
			':func:`dup_files`: Duplicates file descriptors for the command.',
			':func:`children`: Creates child processes for each command in the pipeline.',
			':func:`exec_cmd`: Executes a command in a child process.'
		],
		'output_dir': 'pipex'
	},
    {
        'function_name': 'children',
        'parameters': 't_pipex *pipex',
        'description': 'Creates child processes for each command in the pipeline.',
        'param_types': ['t_pipex *pipex'],
        'param_descriptions': ['Pointer to the pipex structure.'],
        'return_description': 'None.',
        'example': [
			'children(pipex);'
		],
		'notes': [
			'The function creates child processes for each command in the pipeline.',
			'The function uses the fork system call to create child processes.'
		],
		'related_functions': [
            ':func:`wait_pids`: Waits for all child processes to finish.',
			':func:`create_pipes`: Creates pipes for each command in the pipeline.',
            ':func:`dup_files`: Duplicates file descriptors for the command.',
			':func:`exec_cmd`: Executes a command in a child process.'
		],
		'output_dir': 'pipex'
	},
    {
        'function_name': 'dup_files',
        'parameters': 't_cmd *cmd, t_pipex *pipex',
		'description': 'Duplicates file descriptors for the command.',
		'param_types': ['t_cmd *cmd', 't_pipex *pipex'],
		'param_descriptions': [
			'Pointer to the command structure.',
			'Pointer to the pipex structure.'
		],
		'return_description': 'None.',
		'example': [
			'dup_files(cmd, pipex);'
		],
		'notes': [
			'The function duplicates file descriptors for the command.',
			'The function uses the dup2 system call to duplicate file descriptors.'
		],
		'related_functions': [
			':func:`wait_pids`: Waits for all child processes to finish.',
			':func:`create_pipes`: Creates pipes for each command in the pipeline.',
			':func:`children`: Creates child processes for each command in the pipeline.',
			':func:`exec_cmd`: Executes a command in a child process.'
		],
		'output_dir': 'pipex'
	},
    {
        'function_name': 'exec_cmd',
        'parameters': 't_cmd *cmd, t_pipex *pipex',
        'description': 'Executes a command in a child process.',
        'param_types': ['t_cmd *cmd', 't_pipex *pipex'],
        'param_descriptions': [
			'Pointer to the command structure.',
			'Pointer to the pipex structure.'
		],
        'return_description': 'None.',
		'example': [
			'exec_cmd(cmd, pipex);'
		],
		'notes': [
			'The function executes a command in a child process.',
			'The function uses the execve system call to execute the command.'
		],
		'related_functions': [
			':func:`wait_pids`: Waits for all child processes to finish.',
			':func:`create_pipes`: Creates pipes for each command in the pipeline.',
			':func:`dup_files`: Duplicates file descriptors for the command.',
			':func:`children`: Creates child processes for each command in the pipeline.'
		],
		'output_dir': 'pipex'
	},
    {
        'function_name': 'get_paths',
        'parameters': 'char **envp',
        'description': 'Gets the paths from the environment variables.',
        'param_types': ['char **envp'],
        'param_descriptions': [
			'Environment variables.'
		],
        'return_description': 'Array of paths.',
		'example': [
			'char **paths = get_paths(envp);'
		],
		'notes': [
			'The function gets the paths from the environment variables.',
			'The function recodes the getenv system call to get the PATH environment variable.'
		],
		'related_functions': [
			':func:`get_cmd_path`: Gets the path of the command.'
		],
		'output_dir': 'pipex'
	},
    {
        'function_name': 'get_cmd_path',
        'parameters': 'char *cmd, char **paths',
        'description': 'Gets the path of the command.',
        'param_types': ['char *cmd', 'char **paths'],
        'param_descriptions': [
			'Command to find.',
			'Array of paths.'
		],
        'return_description': 'Path of the command.',
		'example': [
			'char *path = get_cmd_path("ls", paths);'
		],
		'notes': [
			'The function gets the path of the command.',
			'The function uses the access system call to check if the command is executable.'
		],
		'related_functions': [
			':func:`get_paths`: Gets the paths from the environment variables.'
		],
		'output_dir': 'pipex'
	},
    {
        'function_name': 'handle_heredoc',
        'parameters': 'char *delimiter, t_pipex *pipex',
        'description': 'Handles the writing and reading of the heredoc.',
		'param_types': ['char *delimiter', 't_pipex *pipex'],
		'param_descriptions': [
			'Delimiter for the heredoc.',
			'Pointer to the pipex structure.'
		],
		'return_description': 'None.',
		'example': [
			'handle_heredoc("EOF", pipex);'
		],
		'notes': [
			'The function handles the writing and reading of the heredoc.',
			'The function uses the get_next_line function to read the heredoc.'
		],
		'related_functions': [
			':func:`get_next_line`: Reads a line from a file descriptor.'
		],
		'output_dir': 'pipex'
	}
]

# Generate .rst files for each function
def generate_rst_files():
    # Initialize content for pipex.rst
    pipex_rst_content = [
        "pipex Documentation",
        "===================",
        "",
        "this project is about creating a program that simulates the pipe operator in bash. The program will take in a file as input, another as output, and two commands as arguments. The first command will be executed and its output will be passed as input to the second command. The output of the second command will be written to a file. The program will also have the ability to handle multiple pipes.",
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
        pipex_rst_content.append(f"   {function['function_name']}")

    # Write to pipex.rst
    with open("pipex/pipex_index.rst", "w") as f:
        f.write("\n".join(pipex_rst_content))

    print("Updated pipex.rst with all functions.")

if __name__ == "__main__":
    generate_rst_files()
