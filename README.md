# CppND-Memory-Management-Chatbot-Project

An interactive C++ chatbot application demonstrating advanced memory management techniques. The project uses modern C++ features including `std::unique_ptr`, `std::shared_ptr`, move semantics, and RAII to manage ownership and resources safely. This project is part of the Udacity C++ Nanodegree Program.

## Overview

This chatbot provides:

- A graphical dialog with the chatbot (wxWidgets GUI)
- An answer graph loaded from a file (nodes and edges)
- Keyword-based matching to choose the next answer
- Safe transfer of the chatbot between graph nodes using move semantics and smart pointers

## Dependencies

- **CMake** >= 3.11.3  
  - All OSes: [installation instructions](https://cmake.org/install/)
- **make** (Linux/macOS) or **Ninja** (optional)  
  - Linux: `sudo apt-get install build-essential`
- **gcc/g++** with C++17 support (e.g. >= 5.4)  
  - Linux: `sudo apt-get install build-essential`
- **wxWidgets** (core, base)  
  - Linux (Ubuntu/Debian): `sudo apt-get install libwxgtk3.0-gtk3-dev` or `libwxgtk3.2-dev`  
  - macOS: `brew install wxwidgets`

## Build Instructions

1. Clone this repository:
   ```bash
   git clone <repository-url>
   cd CppND-Memory-Management-Chatbot-Project
   ```
2. Create a build directory and compile:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
3. The executable is built as `membot` (or `membot.exe` on Windows) inside `build/`.

## Run Instructions

From the project root:

```bash
./build/membot
```

Or from inside `build/`:

```bash
./membot
```

Ensure any required data files (e.g. the answer graph file) are in the expected path relative to where you run the program.

## Project Structure

```
.
├── src/                  # Source and header files
│   ├── chatbot.cpp      # ChatBot entity and message handling
│   ├── chatbot.h
│   ├── chatgui.cpp      # wxWidgets GUI (frame, dialog, app)
│   ├── chatgui.h
│   ├── chatlogic.cpp    # Graph loading and chat logic
│   ├── chatlogic.h
│   ├── graphedge.cpp    # Graph edge (parent/child, keywords)
│   ├── graphedge.h
│   ├── graphnode.cpp    # Graph node (answers, edges, chatbot)
│   └── graphnode.h
├── CMakeLists.txt       # CMake configuration
├── Doxyfile             # Doxygen configuration
├── LICENSE
└── README.md
```

## Key Components

- **ChatBot**: Holds avatar image and current position; receives user messages and uses move semantics when moving between nodes.
- **ChatLogic**: Loads the answer graph from a file, owns graph nodes, and coordinates messages between the user and the chatbot.
- **GraphNode**: A node in the answer graph with answers and owned child edges; can hold the ChatBot.
- **GraphEdge**: Directed edge between nodes with keywords for matching user input.
- **ChatBotPanelDialog / ChatBotFrame**: wxWidgets UI for the conversation and user input.

## Documentation (Doxygen)

The public API is documented with [Doxygen](https://www.doxygen.nl/) in the header files under `src/`. To generate HTML documentation:

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

The generated `docs/` directory is in `.gitignore`; regenerate the docs after cloning or when headers change.

## Implementation Notes

- Uses C++17 standard
- Smart pointers: `std::unique_ptr` for owned resources (nodes, edges, ChatBot, ChatLogic), raw pointers for non-owned references
- ChatBot is non-copyable; move constructor and move assignment used when transferring between graph nodes
- wxWidgets used for the graphical interface

## License

This project is licensed under the Udacity Educational Content License. See the [LICENSE](LICENSE) file for details.

Copyright (c) 2012–2021 Udacity, Inc.
