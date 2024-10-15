# push_swap_template.py

from base_template import template
import os

# List of functions for documentation
functions = [
    {
        'function_name': 'sort_3_numbers',
        'parameters': 't_stack *a',
        'description': 'Sorts 3 numbers in stack A.',
        'param_types': ['t_stack *a'],
        'param_descriptions': [
			'Pointer to stack A.'
		],
        'return_description': 'None.',
		'example': [
			'sort_3_numbers(&a);'
            'In the terminal:',
            './push_swap 3 2 1'
            'Result: sa'
            './push_swap 2 3 1'
            'Result: ra'
            './push_swap 2 1 3'
            'Result: rra'
		],
		'notes': [
			'The function will exit the program if the stack is not valid.',
            'The function will sort the stack using the following operations: sa, ra, rra.',
            'The function will sort the stack by checking the the position of each number, then rotating or swapping the stack accordingly.'
		],
		'related_functions': [
            ':func:`complex_sort`: Sorts a stack of more than 3 numbers, using the two stacks.',
            ':func:`is_sorted`: Checks if stack A is sorted in ascending order.',
            ':func:`checker`: Checks if the stack is sorted after executing the operations.'
		],
		'output_dir': 'push_swap/algo'
	},
    {
        'function_name': 'complex_sort',
        'parameters': 't_stack *a, t_stack *b',
        'description': 'Sorts a stack of more than 3 numbers, using the two stacks.',
        'param_types': ['t_stack *a', 't_stack *b'],
        'param_descriptions': [
			'Pointer to stack A.',
			'Pointer to stack B.'
		],
		'return_description': 'None.',
		'example': [
			'complex_sort(&a, &b);'
			'In the terminal:'
            './push_swap 3 2 1 4 5'
            'Result: pb, pb, sa, pa, pa'
            './push_swap 3 2 1 5 4'
            'Result: pb, pb, sa, pa, pa, sa'
            './push_swap 4 2 7 5 1 6'
            'Result: pb, pb, pb, sa, pa, pa, pa'
		],
		'notes': [
			'The function will exit the program if the stacks are not valid.'
            'The function will sort the stack using the following operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.'
            'The function will sort the stack by pushing all numbers to stack B depending on their position in the stack A, then push them back to stack A depending on the number with the cheapest amount of moves to be at their position in stack A.'
		],
		'related_functions': [
			':func:`sort_3_numbers`: Sorts 3 numbers in stack A.',
            ':func:`is_sorted`: Checks if stack A is sorted in ascending order.',
            ':func:`checker`: Checks if the stack is sorted after executing the operations.'
		],
		'output_dir': 'push_swap/algo'
	},
    {
        'function_name': 'is_sorted',
        'parameters': 't_stack *a',
        'description': 'Checks if stack A is sorted in ascending order.',
        'param_types': ['t_stack *a'],
        'param_descriptions': [
			'Pointer to stack A.'
		],
		'return_description': '1 if sorted, 0 otherwise.',
		'example': [
			'is_sorted(&a);'
		],
		'notes': [
			'The function will exit the program if the stack is not valid.',
            'The function will return 1 if the stack is sorted in ascending order, 0 otherwise.'
		],
		'related_functions': [
			':func:`sort_3_numbers`: Sorts 3 numbers in stack A.',
			':func:`complex_sort`: Sorts a stack of more than 3 numbers, using the two stacks.',
            ':func:`checker`: Checks if the stack is sorted after executing the operations.'
		],
		'output_dir': 'push_swap/algo'
	},
    {
        'function_name': 'checker',
        'parameters': 'int argc, char **argv',
        'description': 'Checks if the stack is sorted after executing the operations.',
        'param_types': ['int argc', 'char **argv'],
        'param_descriptions': [
			'Number of arguments.',
			'Array of arguments.'
		],
		'return_description': 'None.',
		'example': [
            'In the terminal:'
            './push_swap 4 2 1 3 | ./checker 4 2 1 3'
			'Result: OK'
            './push_swap 4 2 1 3 | ./checker 4 1 -2 3'
			'Result: KO'
            './push_swap 4 2 1 3 | ./checker 4 2 1 three'
			'Result: Error'
		],
		'notes': [
			'The function will read the operations from the standard input and execute them on the stack, then check if the stack is sorted.'
            'The function will return OK if the stack is sorted, KO otherwise, and Error if the stack is not valid.'
		],
		'related_functions': [
			':func:`sort_3_numbers`: Sorts 3 numbers in stack A.',
			':func:`complex_sort`: Sorts a stack of more than 3 numbers, using the two stacks.',
			':func:`is_sorted`: Checks if stack A is sorted in ascending order.',
		],
        'output_dir': 'push_swap/checker'
	}
]

# Define your function categories and their corresponding directories
categories = {
    "Algorithm Functions": "algo",
    "Checker Functions": "checker",
}

# Generate .rst files for each function
def generate_rst_files():
    # Initialize content for push_swap.rst
    push_swap_rst_content = [
        "Push_swap Documentation",
        "=======================",
        "",
        "This project is about ordering a set of numbers, with no duplicates and up to INT_MAX and less than INT_MIN.",
        "",
        ".. toctree::",
        "   :maxdepth: 2",
        "",
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

    # Now, generate the push_swap.rst content based on category_entries
    for category, entries in category_entries.items():
        underline = "-" * len(category)
        push_swap_rst_content.append(f"{category}\n{underline}")
        push_swap_rst_content.append("\n.. toctree::\n   :maxdepth: 2\n")
        push_swap_rst_content.extend(f"   {entry}" for entry in entries)
        push_swap_rst_content.append("")  # Add a newline after each category

    # Write to push_swap.rst
    with open("push_swap/push_swap_index.rst", "w") as f:
        f.write("\n".join(push_swap_rst_content))

    print("Updated push_swap.rst with all functions.")

if __name__ == "__main__":
    generate_rst_files()
