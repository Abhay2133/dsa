import os
import sys
import subprocess

def compile_and_run_cpp(file_path):
    # Ensure the file exists
    if not os.path.isfile(file_path):
        print(f"Error: File '{file_path}' does not exist.")
        sys.exit(1)

    # Ensure the file is a C++ file
    if file_path.endswith('.cpp') or file_path.endswith('.cxx') or file_path.endswith('.c') or file_path.endswith('.c++'):
        pass
    else:
        print(f"Error: '{file_path}' is not a C++ file.")
        show_help()
        sys.exit(1)

    # Create the output directory if it doesn't exist
    out_dir = "out"
    os.makedirs(out_dir, exist_ok=True)

    # Compile the C++ file
    output_executable = os.path.join(out_dir, str(file_path).replace('/','-'))
    compile_command = ["g++", file_path, "-o", output_executable]
    try:
        subprocess.run(compile_command, check=True)
        print(f"Compilation successful. Executable created at '{output_executable}'.")
    except subprocess.CalledProcessError as e:
        print(f"Error during compilation: {e}")
        sys.exit(1)

    # Run the compiled executable
    try:
        print("Running the program...")
        subprocess.run([output_executable])
    except Exception as e:
        print(f"Error while running the program: {e}")
        sys.exit(1)

def show_help():
    print("Usage: python script.py <file_path>")
    print("Provide the path to a C++ file to compile and run it.")
    print("Example: python script.py hello.cpp")

def main():
    # Ensure a file path is provided
    if len(sys.argv) != 2:
        print("Error: Missing required argument.")
        show_help()
        sys.exit(1)

    file_path = sys.argv[1]
    compile_and_run_cpp(file_path)

if __name__ == "__main__":
    main()
