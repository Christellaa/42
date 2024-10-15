#!/bin/bash

# Store the current directory
ORIGINAL_DIR=$(pwd)

# Change to the source directory
cd source || { echo "Source directory not found."; exit 1; }

# Run the Python script
python3 main_rst_generator.py
if [ $? -ne 0 ]; then
    echo "Error executing main_rst_generator.py"
    exit 1
fi

# Return to the original directory
cd "$ORIGINAL_DIR" || { echo "Could not return to the original directory."; exit 1; }

# Command file for Sphinx documentation

SPHINXBUILD=$(which sphinx-build)

if [ -z "$SPHINXBUILD" ]; then
    echo "The 'sphinx-build' command was not found. Make sure you have Sphinx installed."
    echo "If you don't have Sphinx installed, grab it from https://www.sphinx-doc.org/"
    exit 1
fi

SOURCEDIR="source"
BUILDDIR="build"

if [ -z "$1" ]; then
    echo "Please provide a target (e.g., html, clean, open)"
    $SPHINXBUILD -M help $SOURCEDIR $BUILDDIR
    exit 0
fi

if [ "$1" = "clean" ]; then
    # Clean the build directory
    if [ -d "$BUILDDIR" ]; then
        echo "Deleting build directory..."
        rm -rf "$BUILDDIR"
    fi

	# Clean the source directory while keeping .py files and specific files/directories
    find "$SOURCEDIR" -type f ! -name "*.py" ! -name "index.rst" -exec rm -f {} \;
    # Remove empty directories, excluding _static and _templates
    find "$SOURCEDIR" -type d -empty -not -path "$SOURCEDIR/_static" -not -path "$SOURCEDIR/_templates" -delete
    echo "Clean complete."
    exit 0
fi

if [ "$1" = "open" ]; then
    # Open the generated HTML if it exists
    OUTPUT_HTML="${BUILDDIR}/html/index.html"
    if [ -f "$OUTPUT_HTML" ]; then
        xdg-open "$OUTPUT_HTML" || { echo "Could not open HTML file."; exit 1; }
    else
        echo "HTML file not found at $OUTPUT_HTML."
    fi
    exit 0
fi

# Build the specified target
$SPHINXBUILD -M "$1" $SOURCEDIR $BUILDDIR

# Open the generated HTML if the target is "html"
if [ "$1" = "html" ]; then
    OUTPUT_HTML="${BUILDDIR}/html/index.html"
    if [ -f "$OUTPUT_HTML" ]; then
        xdg-open "$OUTPUT_HTML" || { echo "Could not open HTML file."; exit 1; }
    else
        echo "HTML file not found at $OUTPUT_HTML."
    fi
fi
