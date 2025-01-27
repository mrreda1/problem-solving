# C++ Problem Solving Template

## Overview

This repository provides a C++ problem-solving template that streamlines the process of creating problem files, managing test cases, and running solutions. It includes custom shell commands to automate common tasks such as generating problem files, handling input/output, and compiling solutions.

## Features

- **Problem File Generation**: Quickly create C++ problem files using the `solve` command.
- **Efficient Input Handling**: Custom functions like `nxt<int>()` and `nxtseq()` for easy input handling.
- **Test Case Management**: Easily add test cases with `addcase`, and run the solution with `try`.
- **Fast Compilation & Execution**: Use custom commands to compile and execute solutions.
  
## Setup Instructions

### 1. Clone the Repository

Clone the repository to your local machine:

```bash
git clone https://github.com/yourusername/template-repo.git
cd template-repo
```

### 2. Link the `functions` Directory (Optional)

If you want to use shared shell functions from this template repository
(like `solve`, `addcase`, etc.), you can copy them into fish config directory:

```bash
cp functions/* ~/.config/fish/functions/
```

Now, you will have access to the shared shell functions for managing problems.

## Usage

### Generate a New Problem File

Use the `solve` command to generate a new C++ problem file based on a template:

```bash
solve ProblemName
```

This will create a file named `ProblemName.cpp` in your current directory, pre-populated with a basic template. If you'd like to specify the `.cpp` extension, you can also use:

```bash
solve ProblemName.cpp
```

If there's a file with same name the command will simply open it, it won't be replaced.

### Customize the Problem File

Open the newly generated `ProblemName.cpp` file. You'll need to customize the following fields:

```bash
const bool T = false;     // Set to true if there are multiple test cases, false otherwise.
const string iofile = ""; // Input/Output file name (if applicable).

void solve() {
    // Implement the solution for one test case here.
}
```

- T: Set to true if the problem involves multiple test cases.
- iofile: Specify the input/output file path if needed.
- solve(): Implement your solution for a single test case in this function.

### Efficient Input Handling

The template includes custom functions for simple and efficient input reading:

- `nxt<int>()` to read an integer (or any other type like `nxt<string>()` for strings).
- `nxtseq(variable)` to read sequences like `vector<int>`, `vector<pair<int, char>>`, etc.

### Add Test Cases

To add a test case, use the `addcase` command:

```bash
addcase "your test case"
```

If you don't specify the test case manually, the command will take the last copied content from your clipboard:

```bash
addcase
```

### Compile and Run the Solution

Once you've added your test case(s), use the `try` command to compile and execute the solution, you must use the `solve` command first:

```bash
try
```

This command will compile the C++ code and run it with the provided test cases.

### View Last Test Case or Result

- To view the last added test case, use the `in` command:

```bash
in
```

This will display the contents of `templates/default.in`.

- To see the last result (output), use the `out` command:

```bash
out
```

This will display the contents of `templates/default.out`.

## Customizing the Template

You can modify the problem template to fit your needs. The template is located in:

```bash
templates/main.cpp
```

Changes to this file will be reflected when you generate new problem files using the `solve` command.

## Updating the Template

To update the template in the future, simply pull the latest changes from the repository:

```bash
git pull origin main
```

## Additional Information

For more understanding and examples, you can view problems already solved in this repository.

If you need help, feel free to contact me!
