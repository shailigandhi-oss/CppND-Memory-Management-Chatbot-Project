# CppND-Memory-Management-Chatbot-Project

An interactive C++ chatbot project demonstrating advanced memory management techniques. Refactored using modern C++ features including `std::unique_ptr`, `std::shared_ptr`, move semantics, and RAII principles to ensure safe ownership transfer and efficient resource handling. This project is part of the Udacity C++ Nanodegree Program.

## Building the project

See the project's build instructions (e.g. CMake or Makefile in the repo) to compile and run the chatbot.

## Documentation (Doxygen)

The public API is documented with [Doxygen](https://www.doxygen.nl/) in the header files under `src/`. You can generate HTML documentation as follows:

1. **Install Doxygen** (if needed):
   - Ubuntu/Debian: `sudo apt install doxygen`
   - macOS: `brew install doxygen`
   - Or download from [doxygen.nl](https://www.doxygen.nl/download.html)

2. **Generate docs** from the project root:
   ```bash
   doxygen Doxyfile
   ```
   Output is written to `docs/html/`.

3. **View the docs**: open `docs/html/index.html` in a browser.

The `Doxyfile` in the project root configures input to `src/`, recursive parsing, and HTML output to `docs/`. The generated `docs/` directory is listed in `.gitignore`; regenerate the docs after cloning or when headers change.
