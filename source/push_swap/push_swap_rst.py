import sys
import os

# Add the parent directory to the sys.path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from push_swap_template import generate_rst_files

if __name__ == "__main__":
    generate_rst_files()
