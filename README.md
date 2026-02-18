# PyDuino Terminal

A Windows terminal helper for the PyDuino project. It provides interactive commands to install, manage, and verify common tools (llama.cpp, Graphviz, Python, SDKs), plus download and launch PyDuino IDE versions.

## Highlights
- Command-driven installer for common dependencies
- llama.cpp setup helper with backend flags
- PyDuino IDE version manager (list/install/launch)
- Simple directory and cleanup commands

## Build
This project is built with MSVC:

```
cl terminal.cpp -o terminal.exe
```

## Run
```
terminal.exe
```

## Notes
- Some installs use `winget` or `curl`. When using `curl`, the app warns and asks for confirmation.
- Run from the “x64 Native Tools Command Prompt for VS” for best results.

## License
MIT. See `LICENSE`.
