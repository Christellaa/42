import subprocess
import sys

def run_rst_scripts():
    # List of project-specific RST scripts
    scripts = [
        "libft/libft_rst.py",
        "get_next_line/gnl_rst.py",
        "ft_printf/ft_printf_rst.py",
        "pipex/pipex_rst.py",
        "so_long/so_long_rst.py",
        "push_swap/push_swap_rst.py",
        # Add other project scripts here
    ]

    for script in scripts:
        print(f"Running {script}...")
        # Use sys.executable to ensure the correct Python interpreter is used
        subprocess.run([sys.executable, script], check=True)

if __name__ == "__main__":
    run_rst_scripts()
