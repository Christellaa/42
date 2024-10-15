import os

def generate_rst(project_name, module_name, function_name, output_dir):
    # Read the base template
    with open("base_template.rst", "r") as template_file:
        template = template_file.read()
    
    # Create the RST content by replacing placeholders
    rst_content = template.format(
        project_name=project_name,
        module_name=module_name,
        function_name=function_name
    )
    
    # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)
    
    # Write the RST content to a file
    output_file = os.path.join(output_dir, f"{function_name}.rst")
    with open(output_file, "w") as rst_file:
        rst_file.write(rst_content)
    
    print(f"Generated documentation for {function_name} in {output_file}.")
