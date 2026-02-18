#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#endif

namespace colorama {
    inline void init() {
#ifdef _WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE) return;
        DWORD mode = 0;
        if (!GetConsoleMode(hOut, &mode)) return;
        SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
    }
    namespace Fore {
        const std::string BLACK          = "\033[30m";
        const std::string RED            = "\033[31m";
        const std::string GREEN          = "\033[32m";
        const std::string YELLOW         = "\033[33m";
        const std::string BLUE           = "\033[34m";
        const std::string MAGENTA        = "\033[35m";
        const std::string CYAN           = "\033[36m";
        const std::string WHITE          = "\033[37m";
        const std::string BRIGHT_BLACK   = "\033[90m";
        const std::string BRIGHT_RED     = "\033[91m";
        const std::string BRIGHT_GREEN   = "\033[92m";
        const std::string BRIGHT_YELLOW  = "\033[93m";
        const std::string BRIGHT_BLUE    = "\033[94m";
        const std::string BRIGHT_MAGENTA = "\033[95m";
        const std::string BRIGHT_CYAN    = "\033[96m";
        const std::string BRIGHT_WHITE   = "\033[97m";
        const std::string ORANGE         = "\033[38;5;214m";
        const std::string PINK           = "\033[38;5;213m";
        const std::string PURPLE         = "\033[38;5;141m";
        const std::string TEAL           = "\033[38;5;38m";
        const std::string LIME           = "\033[38;5;154m";
        const std::string GOLD           = "\033[38;5;220m";
        const std::string CORAL          = "\033[38;5;203m";
        const std::string LAVENDER       = "\033[38;5;183m";
        const std::string SKY            = "\033[38;5;117m";
        const std::string MINT           = "\033[38;5;121m";
        const std::string ROSE           = "\033[38;5;211m";
        const std::string PEACH          = "\033[38;5;223m";
        const std::string RESET          = "\033[39m";
    }
    namespace Back {
        const std::string GREEN   = "\033[42m";
        const std::string BLUE    = "\033[44m";
        const std::string MAGENTA = "\033[45m";
        const std::string RESET   = "\033[49m";
    }
    namespace Style {
        const std::string RESET_ALL = "\033[0m";
        const std::string BOLD      = "\033[1m";
        const std::string DIM       = "\033[2m";
    }
}

using namespace std;
using namespace colorama;

void sleep_ms(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void rainbow_print(const string& text) {
    const string cols[10] = {
        Fore::BRIGHT_CYAN, Fore::BRIGHT_BLUE, Fore::PURPLE,
        Fore::BRIGHT_MAGENTA, Fore::PINK, Fore::CORAL,
        Fore::ORANGE, Fore::GOLD, Fore::LIME, Fore::MINT
    };
    for (size_t i = 0; i < text.size(); ++i)
        cout << cols[i % 10] << text[i];
    cout << Style::RESET_ALL << "\n";
}

int main() {
    colorama::init();

    cout << "\033[2J\033[H";

    // ── Top border ────────────────────────────────────────────────────
    rainbow_print("  +==============================================================+");

    // ── ASCII logo (figlet 'banner' style - pure ASCII) ───────────────
    cout << "\n";
    cout << Fore::BRIGHT_CYAN << Style::BOLD;
    cout << "  #####  #   #  #####   #   #  ###  #   #  #####  \n";
    cout << "  #   #   # #   #    #  #   #   #   ##  #  #    # \n";
    cout << "  #####    #    #    #  #   #   #   # # #  #    # \n";
    cout << "  #         #   #    #  #   #   #   #  ##  #    # \n";
    cout << "  #         #   #####    ###   ###  #   #  #####  \n";
    cout << Style::RESET_ALL << "\n";

    cout << Fore::CYAN << Style::BOLD;
    cout << "  ##### ##### ####  #   # ##### #   #  ###  #     \n";
    cout << "    #   #     #   # ## ##   #   ##  # #   # #     \n";
    cout << "    #   ####  ####  # # #   #   # # # ##### #     \n";
    cout << "    #   #     #  #  #   #   #   #  ## #   # #     \n";
    cout << "    #   ##### #   # #   # ##### #   # #   # ##### \n";
    cout << Style::RESET_ALL << "\n";

    // ── Sub-title ─────────────────────────────────────────────────────
    cout << Fore::GOLD << Style::BOLD;
    cout << "            Dependency Setup Assistant  |  v2.0\n";
    cout << Style::RESET_ALL << "\n";

    // ── Bottom border ─────────────────────────────────────────────────
    rainbow_print("  +==============================================================+");

    // ── Animated loading ──────────────────────────────────────────────
    cout << "\n" << Fore::TEAL << Style::BOLD << "  Initialising";
    cout.flush();
    for (int i = 0; i < 6; ++i) { sleep_ms(280); cout << " ."; cout.flush(); }
    sleep_ms(300);
    cout << Style::RESET_ALL << "\n\n";

    // ── Status badges ─────────────────────────────────────────────────
    cout << Back::GREEN   << Fore::BLACK << Style::BOLD << " OK  "
         << Style::RESET_ALL << Fore::BRIGHT_GREEN << "  Terminal online\n"        << Style::RESET_ALL;
    cout << Back::BLUE    << Fore::WHITE << Style::BOLD << " SYS "
         << Style::RESET_ALL << Fore::SKY            << "  Environment prepared\n" << Style::RESET_ALL;
    cout << Back::MAGENTA << Fore::WHITE << Style::BOLD << " ENV "
         << Style::RESET_ALL << Fore::LAVENDER       << "  PyDuino v2.0 loaded\n"  << Style::RESET_ALL;
    cout << "\n";

    // ── Install list ──────────────────────────────────────────────────
    cout << Style::BOLD << Fore::ORANGE << "  > This setup can install:\n" << Style::RESET_ALL;

    const char* icols[6] = {
        Fore::LIME.c_str(), Fore::SKY.c_str(), Fore::PEACH.c_str(),
        Fore::ROSE.c_str(), Fore::PURPLE.c_str(), Fore::GOLD.c_str()
    };
    const char* itexts[6] = {
        "Python packages  (pip, virtualenv, pyserial ...)",
        "Arduino CLI      (avr-gcc, avrdude ...)",
        "Required toolchains & compilers",
        "Drivers & utilities  (CH340, CP2102 ...)",
        "Board definitions & library manager",
        "IDE plugins & VS Code extensions"
    };
    for (int i = 0; i < 6; ++i)
        cout << icols[i] << "    [+]  " << itexts[i] << "\n" << Style::RESET_ALL;

    cout << "\n";

    // ── Hint box ──────────────────────────────────────────────────────
    cout << Style::BOLD << Fore::BRIGHT_CYAN
         << "  +------------------------------------------------------+\n"
         << "  |   Type  help  to see all available commands          |\n"
         << "  +------------------------------------------------------+\n"
         << Style::RESET_ALL << "\n";

    // ── Footer ────────────────────────────────────────────────────────
    cout << Fore::BRIGHT_BLACK << Style::DIM
         << "  ----------------------------------------------------------------\n"
         << "  PyDuino Open-Source Project\n"
         << "  https://github.com/pyduinocontact-alt\n"
         << "  ----------------------------------------------------------------\n"
         << Style::RESET_ALL << "\n";

    // ── REPL ──────────────────────────────────────────────────────────
    while (true) {
        cout << Fore::TEAL << Style::BOLD << "  > " << Style::RESET_ALL;
        string command;
        getline(cin, command);

        if (command == "help") {
            cout << "\n" << Fore::TEAL << Style::BOLD << "  Fetching commands";
            cout.flush();
            for (int i = 0; i < 6; ++i) { sleep_ms(280); cout << " ."; cout.flush(); }
            cout << Style::RESET_ALL << "\n\n";
            cout << Fore::GREEN << R"DELIMA(  Available commands:
    help                              :: Shows all the commands available
    info                              :: About PyDuino Terminal
    install llama.cpp                 :: Clone llama.cpp to default path (C:\\llama.cpp)
    install llama.cpp <path>          :: Clone llama.cpp to specified path
    install openblas                  :: Install OpenBLAS via vcpkg (C:\\vcpkg)
    install graphviz [--winget|--curl|--resume]
                                      :: Install Graphviz (winget or curl if supported)
    install dependencies-python [--curl|--resume]
                                      :: Install PyDuino python requirements via pip
    install python [--winget|--curl|--resume]
                                      :: Install Python (winget or curl if supported)
    install cmake [--winget|--curl|--resume]
                                      :: Install CMake (winget or curl if supported)
    install nvidia-sdk [--winget|--curl|--resume]
                                      :: Install NVIDIA CUDA SDK (winget or curl if supported)
    install vulkan-sdk [--winget|--curl|--resume]
                                      :: Install Vulkan SDK (winget or curl if supported)
    install openblas-sdk [--winget|--curl]
                                      :: Install OpenBLAS SDK (vcpkg)
    install amd-sdk [--winget|--curl|--resume]
                                      :: Install AMD SDK (winget or curl if supported)
    install pyduino-versions [--curl|--resume]
                                      :: Download PyDuino versions metadata
    setup python                      :: Verify Python is installed and on PATH
    setup cmake                       :: Verify CMake is installed and on PATH
    setup nvidia-sdk                  :: Verify NVIDIA CUDA (nvcc) is on PATH
    setup vulkan-sdk                  :: Verify Vulkan SDK is installed
    setup openblas-sdk                :: Verify OpenBLAS is installed
    setup amd-sdk                     :: Verify AMD SDK is installed
    launch python-exe [args]          :: Launch python.exe with optional args
    add model llama.cpp <gguf> [path] :: Copy a .gguf model into llama.cpp\\models
    setup llama.cpp <backends> <path> :: Build llama.cpp for your hardware
      backends: cpu / nvidia / cuda / amd / vulkan / openblas / intel / hp / all
      example:  setup llama.cpp [nvidia,amd] C:\\dev\\llama
    setup graphviz                    :: Verify Graphviz (dot) is installed and on PATH
    dir llama.cpp [--path P] [--folder F] [--files|--dirs|--all]
                                      :: List contents of llama.cpp (dirs by default)
    remove llama.cpp [--path P] --models|--build|--whole
                                      :: Remove parts of llama.cpp (asks to confirm)
    dir graphviz [--path P] [--files|--dirs|--all]
                                      :: List contents of Graphviz (dirs by default)
    remove graphviz [--path P] --whole
                                      :: Remove Graphviz folder (asks to confirm)
    dir python [--path P] [--files|--dirs|--all]
                                      :: List contents of Python install (dirs by default)
    remove python [--path P] --whole
                                      :: Remove Python folder (asks to confirm)
    dir cmake [--path P] [--files|--dirs|--all]
                                      :: List contents of CMake (dirs by default)
    remove cmake [--path P] --whole
                                      :: Remove CMake folder (asks to confirm)
    dir nvidia-sdk [--path P] [--files|--dirs|--all]
                                      :: List contents of NVIDIA SDK (dirs by default)
    remove nvidia-sdk [--path P] --whole
                                      :: Remove NVIDIA SDK folder (asks to confirm)
    dir vulkan-sdk [--path P] [--files|--dirs|--all]
                                      :: List contents of Vulkan SDK (dirs by default)
    remove vulkan-sdk [--path P] --whole
                                      :: Remove Vulkan SDK folder (asks to confirm)
    dir openblas-sdk [--path P] [--files|--dirs|--all]
                                      :: List contents of OpenBLAS SDK (dirs by default)
    remove openblas-sdk [--path P] --whole
                                      :: Remove OpenBLAS SDK folder (asks to confirm)
    dir amd-sdk [--path P] [--files|--dirs|--all]
                                      :: List contents of AMD SDK (dirs by default)
    remove amd-sdk [--path P] --whole
                                      :: Remove AMD SDK folder (asks to confirm)
    pyduino list-versions             :: Show available PyDuino versions
    install pyduino <version> [--curl|--resume]
                                      :: Download and extract a PyDuino version
    pyduino launch <version>          :: Launch PYDUINOide.py for a version
    exit                              :: Exits the terminal
)DELIMA" << Style::RESET_ALL << "\n";
        }

        else if (command == "info") {
            cout << "\n";
            rainbow_print("  +==============================================================+");
            cout << Fore::BRIGHT_CYAN << Style::BOLD << "\n  About PyDuino Terminal\n\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_WHITE
                 << "  PyDuino Terminal is a dependency setup assistant for the\n"
                 << "  PyDuino project. It helps you install and manage all the\n"
                 << "  tools, libraries, and drivers needed to run PyDuino.\n\n"
                 << Style::RESET_ALL;
            cout << Fore::GOLD  << "  Version  : " << Style::RESET_ALL << Fore::BRIGHT_WHITE << "v2.0\n"                              << Style::RESET_ALL;
            cout << Fore::GOLD  << "  Project  : " << Style::RESET_ALL << Fore::SKY          << "https://github.com/pyduinocontact-alt\n" << Style::RESET_ALL;
            cout << Fore::GOLD  << "  Language : " << Style::RESET_ALL << Fore::BRIGHT_WHITE << "C++\n\n"                             << Style::RESET_ALL;
            cout << Style::BOLD << Fore::BRIGHT_YELLOW
                 << "  !! ITS RECOMMENDED TO INSTALL VISUAL STUDIO TOOLS AND\n"
                 << "  !! RUN THIS TOOL TERMINAL.EXE FROM THE X64 NATIVE TOOLS\n"
                 << "  !! COMMAND PROMPT OF VISUAL STUDIO\n"
                 << Style::RESET_ALL << "\n";
            rainbow_print("  +==============================================================+");
            cout << "\n";
        }

        else if (command == "setup llama.cpp" ||
                 command.rfind("setup llama.cpp ", 0) == 0) {

            // ── Parse backend flags from command ──────────────────────────
            bool useCUDA    = false;
            bool useVulkan  = false;
            bool useOpenBLAS= false;
            bool useCPU     = false;
            string buildPath = "C:\\llama.cpp";

            // tokenise everything after "setup llama.cpp"
            string args = "";
            if (command.rfind("setup llama.cpp ", 0) == 0)
                args = command.substr(string("setup llama.cpp ").size());

            // allow bracketed backend lists like [nvidia,amd]
            for (char &ch : args) {
                if (ch == '[' || ch == ']' || ch == ',') ch = ' ';
            }

            // scan tokens
            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "cuda"     || tok == "CUDA"    ) useCUDA     = true;
                else if (tok == "vulkan"  || tok == "VULKAN" ) useVulkan   = true;
                else if (tok == "openblas"|| tok == "OPENBLAS")useOpenBLAS = true;
                else if (tok == "cpu"     || tok == "CPU"    ) useCPU      = true;
                else if (tok == "nvidia"  || tok == "NVIDIA" ) useCUDA     = true;
                else if (tok == "amd"     || tok == "AMD"    ) useVulkan   = true;
                else if (tok == "intel"   || tok == "INTEL"  ) useVulkan   = true;
                else if (tok == "hp"      || tok == "HP"     ) useVulkan   = true;
                else if (tok == "all"     || tok == "ALL"    ) { useCUDA = useVulkan = useOpenBLAS = true; }
                else { buildPath = tok; } // treat unknown token as path
            }

            // default to CPU-only if nothing picked
            if (!useCUDA && !useVulkan && !useOpenBLAS) useCPU = true;

            // strip quotes from path
            if (!buildPath.empty() && buildPath.front() == '"') buildPath = buildPath.substr(1);
            if (!buildPath.empty() && buildPath.back()  == '"') buildPath.pop_back();

            // ── Print summary ─────────────────────────────────────────────
            cout << "\n";
            rainbow_print("  +==============================================================+");
            cout << Fore::BRIGHT_CYAN << Style::BOLD << "  llama.cpp  Build Configuration\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD  << "  Install path : " << Style::RESET_ALL << Fore::BRIGHT_WHITE << buildPath         << "\n" << Style::RESET_ALL;
            cout << Fore::GOLD  << "  CUDA         : " << Style::RESET_ALL << (useCUDA     ? (Fore::BRIGHT_GREEN+"ON") : (Fore::BRIGHT_BLACK+"OFF")) << Style::RESET_ALL << "\n";
            cout << Fore::GOLD  << "  Vulkan       : " << Style::RESET_ALL << (useVulkan   ? (Fore::BRIGHT_GREEN+"ON") : (Fore::BRIGHT_BLACK+"OFF")) << Style::RESET_ALL << "\n";
            cout << Fore::GOLD  << "  OpenBLAS     : " << Style::RESET_ALL << (useOpenBLAS ? (Fore::BRIGHT_GREEN+"ON") : (Fore::BRIGHT_BLACK+"OFF")) << Style::RESET_ALL << "\n";
            cout << Fore::GOLD  << "  CPU-only     : " << Style::RESET_ALL << (useCPU      ? (Fore::BRIGHT_GREEN+"ON") : (Fore::BRIGHT_BLACK+"OFF")) << Style::RESET_ALL << "\n\n";

            // ── Build the cmake flags ──────────────────────────────────────
            string cmakeFlags = "-G \"Visual Studio 17 2022\" -A x64";
            if (useCUDA)     cmakeFlags += " -DGGML_CUDA=ON";
            if (useVulkan)   cmakeFlags += " -DGGML_VULKAN=ON";
            if (useOpenBLAS) cmakeFlags += " -DGGML_BLAS=ON -DGGML_BLAS_VENDOR=OpenBLAS -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake";

            // print the plan
            cout << Fore::ORANGE << Style::BOLD << "  Steps that will run:\n" << Style::RESET_ALL;
            cout << Fore::PEACH << "    [1] cmake configure with: " << cmakeFlags << "\n" << Style::RESET_ALL;
            cout << Fore::PEACH << "    [2] cmake --build Release\n" << Style::RESET_ALL;
            if (useOpenBLAS) {
                cout << Fore::PEACH << "    [3] Copy openblas.dll to bin\\Release\\\n" << Style::RESET_ALL;
            }

            cout << Style::BOLD << Fore::BRIGHT_YELLOW
                 << "\n  !! RUN THIS FROM X64 NATIVE TOOLS COMMAND PROMPT OF VISUAL STUDIO\n"
                 << Style::RESET_ALL << "\n";

            int totalSteps = useOpenBLAS ? 3 : 2;

            // ── Confirm ───────────────────────────────────────────────────
            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with build? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {

                int ret = 0;

                // Ensure llama.cpp exists at the path
                {
                    string checkCmd = "if exist \"" + buildPath + "\\CMakeLists.txt\" (exit /b 0) else (exit /b 1)";
                    int chk = system(checkCmd.c_str());
                    if (chk != 0) {
                        cout << Fore::BRIGHT_RED << "  [ERROR] No llama.cpp found at: " << buildPath << "\n" << Style::RESET_ALL;
                        cout << Fore::BRIGHT_BLACK << "  Use: install llama.cpp <path> to clone it first.\n" << Style::RESET_ALL << "\n";
                        goto setup_done;
                    }
                }

                // Step: mkdir build
                {
                    string mkdirCmd = "mkdir \"" + buildPath + "\\build\" 2>nul";
                    system(mkdirCmd.c_str());
                }

                // Step: cmake configure
                cout << "\n" << Fore::TEAL << Style::BOLD << "  [1/" << totalSteps << "] Configuring cmake";
                cout.flush();
                for (int i = 0; i < 4; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";

                {
                    string cmakeCmd = "cd \"" + buildPath + "\\build\" && cmake .. " + cmakeFlags;
                    cout << Fore::BRIGHT_BLACK << "  $ " << Style::RESET_ALL << Fore::BRIGHT_WHITE << cmakeCmd << "\n" << Style::RESET_ALL;
                    ret = system(cmakeCmd.c_str());
                    if (ret != 0) {
                        cout << Fore::BRIGHT_RED << "  [ERROR] cmake configure failed.\n" << Style::RESET_ALL << "\n";
                        goto setup_done;
                    }
                }

                // Step: cmake build
                cout << "\n" << Fore::TEAL << Style::BOLD << "  [2/" << totalSteps << "] Building (this may take several minutes)";
                cout.flush();
                for (int i = 0; i < 4; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";

                {
                    string buildCmd = "cd \"" + buildPath + "\\build\" && cmake --build . --config Release";
                    cout << Fore::BRIGHT_BLACK << "  $ " << Style::RESET_ALL << Fore::BRIGHT_WHITE << buildCmd << "\n" << Style::RESET_ALL;
                    ret = system(buildCmd.c_str());
                    if (ret != 0) {
                        cout << Fore::BRIGHT_RED << "  [ERROR] Build failed.\n" << Style::RESET_ALL << "\n";
                        goto setup_done;
                    }
                }

                // Step: copy openblas.dll
                if (useOpenBLAS) {
                    cout << "\n" << Fore::TEAL << Style::BOLD << "  [3/" << totalSteps << "] Copying openblas.dll";
                    cout.flush();
                    for (int i = 0; i < 3; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                    cout << Style::RESET_ALL << "\n";
                    string copyCmd = "copy C:\\vcpkg\\installed\\x64-windows\\bin\\openblas.dll \"" + buildPath + "\\build\\bin\\Release\\\"";
                    system(copyCmd.c_str());
                }

                cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  llama.cpp built successfully at: " << buildPath << "\\build\\bin\\Release\\\n"
                     << Style::RESET_ALL << "\n";

                setup_done:;

            } else {
                cout << Fore::BRIGHT_BLACK << "\n  Build cancelled.\n" << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "install llama.cpp" || command.rfind("install llama.cpp ", 0) == 0) {

            // Supported forms:
            //   install llama.cpp
            //   install llama.cpp C:\some\path
            //   install llama.cpp --path=C:\some\path
            //   install llama.cpp --existing=C:\already\installed
            string installPath  = "C:\\llama.cpp";
            string existingPath = "";
            bool   useExisting  = false;

            if (command.rfind("install llama.cpp ", 0) == 0) {
                string args = command.substr(string("install llama.cpp ").size());

                // strip surrounding quotes helper
                auto sq = [](string s) -> string {
                    if (!s.empty() && s.front() == '"') s = s.substr(1);
                    if (!s.empty() && s.back()  == '"') s.pop_back();
                    return s;
                };

                // extract --key=value
                auto getParam = [&](const string& key) -> string {
                    string needle = key + "=";
                    size_t pos = args.find(needle);
                    if (pos == string::npos) return "";
                    string val = args.substr(pos + needle.size());
                    if (!val.empty() && val.front() == '"') {
                        size_t e = val.find('"', 1);
                        return (e != string::npos) ? val.substr(1, e - 1) : val.substr(1);
                    }
                    size_t sp = val.find(' ');
                    return (sp != string::npos) ? val.substr(0, sp) : val;
                };

                string pParam = getParam("--path");
                string eParam = getParam("--existing");

                if (!eParam.empty()) {
                    existingPath = sq(eParam);
                    useExisting  = true;
                } else if (!pParam.empty()) {
                    installPath = sq(pParam);
                } else {
                    // positional path (no -- prefix)
                    installPath = sq(args);
                }
            }

            const string releaseSize = "~180 MB";
            const string releaseUrl  = "https://github.com/ggml-org/llama.cpp";

            cout << "\n";
            cout << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  llama.cpp  (latest official release)\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Source   : " << Style::RESET_ALL
                 << Fore::SKY << releaseUrl << "\n" << Style::RESET_ALL;

            if (useExisting) {
                cout << Fore::BRIGHT_BLACK << "  Mode     : " << Style::RESET_ALL
                     << Fore::GOLD << "Use existing installation\n" << Style::RESET_ALL;
                cout << Fore::BRIGHT_BLACK << "  Path     : " << Style::RESET_ALL
                     << Fore::LIME << existingPath << "\n" << Style::RESET_ALL;
            } else {
                cout << Fore::BRIGHT_BLACK << "  Size     : " << Style::RESET_ALL
                     << Fore::PEACH << releaseSize << "\n" << Style::RESET_ALL;
                cout << Fore::BRIGHT_BLACK << "  Install  : " << Style::RESET_ALL
                     << Fore::LIME << installPath << "\n" << Style::RESET_ALL;
            }
            cout << "\n";

            if (useExisting) {
                // Just register/acknowledge the existing path - no download needed
                cout << Fore::GOLD << Style::BOLD
                     << "  Register existing llama.cpp at \"" << existingPath << "\" ? [Y/n]: "
                     << Style::RESET_ALL;
                cout.flush();
                string confirm; getline(cin, confirm);
                if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {
                    // Check the path actually exists
                    string checkCmd = "if exist \"" + existingPath + "\" (echo FOUND) else (echo NOTFOUND)";
                    int chk = system(checkCmd.c_str());
                    (void)chk;
                    cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD << " OK  " << Style::RESET_ALL
                         << Fore::BRIGHT_GREEN << "  Registered existing llama.cpp at: " << existingPath << "\n"
                         << Style::RESET_ALL << "\n";
                } else {
                    cout << Fore::BRIGHT_BLACK << "\n  Cancelled.\n" << Style::RESET_ALL << "\n";
                }
            } else {
                // Fresh install
                cout << Fore::GOLD << Style::BOLD
                     << "  Do you want to install llama.cpp (" << releaseSize << ") ? [Y/n]: "
                     << Style::RESET_ALL;
                cout.flush();
                string confirm; getline(cin, confirm);

                if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {

                    cout << "\n" << Fore::TEAL << Style::BOLD << "  Connecting to GitHub";
                    cout.flush();
                    for (int i = 0; i < 5; ++i) { sleep_ms(280); cout << " ."; cout.flush(); }
                    cout << Style::RESET_ALL << "\n";

                    string gitCmd = "git clone --depth=1 https://github.com/ggml-org/llama.cpp.git \"" + installPath + "\"";
                    cout << Fore::BRIGHT_BLACK << "  $ " << Style::RESET_ALL
                         << Fore::BRIGHT_WHITE << gitCmd << "\n" << Style::RESET_ALL << "\n";

                    int ret = system(gitCmd.c_str());

                    if (ret == 0) {
                        cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                             << " OK  " << Style::RESET_ALL
                             << Fore::BRIGHT_GREEN << "  llama.cpp installed to: " << installPath << "\n"
                             << Style::RESET_ALL << "\n";
                    } else {
                        cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                             << "  [ERROR]  " << Style::RESET_ALL
                             << Fore::RED << "Installation failed (code " << ret << ").\n"
                             << Fore::BRIGHT_BLACK << "  Make sure git is installed and you have internet access.\n"
                             << Style::RESET_ALL << "\n";
                    }

                } else {
                    cout << Fore::BRIGHT_BLACK << "\n  Installation cancelled.\n" << Style::RESET_ALL << "\n";
                }
            }
        }

        else if (command == "install openblas") {
            cout << "\n";
            cout << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  OpenBLAS  (via vcpkg)\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Install  : " << Style::RESET_ALL
                 << Fore::LIME << "C:\\vcpkg\n" << Style::RESET_ALL;
            cout << "\n";

            cout << Fore::ORANGE << Style::BOLD << "  Steps that will run:\n" << Style::RESET_ALL;
            cout << Fore::PEACH << "    [1] Clone vcpkg to C:\\vcpkg (if missing)\n" << Style::RESET_ALL;
            cout << Fore::PEACH << "    [2] Bootstrap vcpkg\n" << Style::RESET_ALL;
            cout << Fore::PEACH << "    [3] vcpkg install openblas:x64-windows\n" << Style::RESET_ALL;
            cout << Fore::PEACH << "    [4] vcpkg integrate install\n" << Style::RESET_ALL;

            cout << Fore::GOLD << Style::BOLD
                 << "\n  Proceed with OpenBLAS install? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {
                int ret = 0;

                cout << "\n" << Fore::TEAL << Style::BOLD << "  [1/4] Cloning vcpkg";
                cout.flush();
                for (int i = 0; i < 3; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";
                ret = system("cd C:\\ && git clone https://github.com/Microsoft/vcpkg.git 2>nul || echo vcpkg already exists");
                if (ret != 0) goto openblas_done;

                cout << "\n" << Fore::TEAL << Style::BOLD << "  [2/4] Bootstrapping vcpkg";
                cout.flush();
                for (int i = 0; i < 3; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";
                ret = system("cd C:\\vcpkg && bootstrap-vcpkg.bat -disableMetrics");
                if (ret != 0) goto openblas_done;

                cout << "\n" << Fore::TEAL << Style::BOLD << "  [3/4] Installing OpenBLAS";
                cout.flush();
                for (int i = 0; i < 3; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";
                ret = system("C:\\vcpkg\\vcpkg install openblas:x64-windows");
                if (ret != 0) goto openblas_done;

                cout << "\n" << Fore::TEAL << Style::BOLD << "  [4/4] Integrating vcpkg";
                cout.flush();
                for (int i = 0; i < 3; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";
                ret = system("C:\\vcpkg\\vcpkg integrate install");

                openblas_done:
                if (ret == 0) {
                    cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                         << " OK  " << Style::RESET_ALL
                         << Fore::BRIGHT_GREEN << "  OpenBLAS installed via vcpkg.\n"
                         << Style::RESET_ALL << "\n";
                } else {
                    cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                         << "  [ERROR]  " << Style::RESET_ALL
                         << Fore::RED << "OpenBLAS install failed (code " << ret << ").\n"
                         << Fore::BRIGHT_BLACK << "  Make sure git is installed and you have internet access.\n"
                         << Style::RESET_ALL << "\n";
                }
            } else {
                cout << Fore::BRIGHT_BLACK << "\n  Installation cancelled.\n" << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "install graphviz" ||
                 command.rfind("install graphviz ", 0) == 0) {
            bool useCurl = false;
            bool useWinget = true;
            if (command.rfind("install graphviz ", 0) == 0) {
                string args = command.substr(string("install graphviz ").size());
                stringstream ss(args);
                string tok;
                while (ss >> tok) {
                    if (tok == "--curl") { useCurl = true; useWinget = false; }
                    else if (tok == "--winget") { useWinget = true; useCurl = false; }
                }
            }
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Graphviz  (winget)\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Command : " << Style::RESET_ALL
                 << Fore::LIME << "winget install -e --id Graphviz.Graphviz\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with Graphviz install? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {
                int ret = 0;
                if (useCurl) {
                    cout << Fore::BRIGHT_RED << "  [ERROR] curl install not configured for Graphviz.\n"
                         << Fore::BRIGHT_BLACK << "  Use: install graphviz --winget\n"
                         << Style::RESET_ALL << "\n";
                    ret = 1;
                } else {
                    ret = system("winget install -e --id Graphviz.Graphviz");
                }
                if (ret == 0) {
                    cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                         << " OK  " << Style::RESET_ALL
                         << Fore::BRIGHT_GREEN << "  Graphviz installed.\n"
                         << Style::RESET_ALL << "\n";
                } else {
                    cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                         << "  [ERROR]  " << Style::RESET_ALL
                         << Fore::RED << "Graphviz install failed (code " << ret << ").\n"
                         << Fore::BRIGHT_BLACK << "  Ensure winget is installed or install Graphviz manually.\n"
                         << Style::RESET_ALL << "\n";
                }
            } else {
                cout << Fore::BRIGHT_BLACK << "\n  Installation cancelled.\n" << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "install dependencies-python" ||
                 command.rfind("install dependencies-python ", 0) == 0) {
            bool useCurl = true;
            bool resume = false;
            if (command.rfind("install dependencies-python ", 0) == 0) {
                string args = command.substr(string("install dependencies-python ").size());
                stringstream ss(args);
                string tok;
                while (ss >> tok) {
                    if (tok == "--curl") useCurl = true;
                    else if (tok == "--resume") resume = true;
                }
            }
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Python dependencies  (PyDuino)\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Source  : " << Style::RESET_ALL
                 << Fore::SKY << "https://github.com/pyduinocontact-alt/requirements/blob/main/PyDuino.requirements\n"
                 << Style::RESET_ALL;
            cout << "\n";

            cout << Fore::ORANGE << Style::BOLD << "  Steps that will run:\n" << Style::RESET_ALL;
            cout << Fore::PEACH << "    [1] Download PyDuino.requirements\n" << Style::RESET_ALL;
            cout << Fore::PEACH << "    [2] pip install -r PyDuino.requirements\n" << Style::RESET_ALL;

            cout << Fore::GOLD << Style::BOLD
                 << "\n  Proceed with python dependencies install? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {
                int ret = 0;
                string reqUrl = "https://raw.githubusercontent.com/pyduinocontact-alt/requirements/main/PyDuino.requirements";
                string reqFile = "PyDuino.requirements";

                cout << "\n" << Fore::TEAL << Style::BOLD << "  [1/2] Downloading requirements";
                cout.flush();
                for (int i = 0; i < 3; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";
                string dlCmd;
                if (useCurl) {
                    cout << Fore::BRIGHT_YELLOW
                         << "  [WARN] curl downloads are experimental and may fail. "
                         << "We recommend using --winget when available.\n"
                         << Style::RESET_ALL;
                    cout << Fore::GOLD << Style::BOLD
                         << "  Continue with curl? [Y/n]: "
                         << Style::RESET_ALL;
                    cout.flush();
                    string cconfirm;
                    getline(cin, cconfirm);
                    if (!(cconfirm.empty() || cconfirm == "Y" || cconfirm == "y" || cconfirm == "yes" || cconfirm == "YES")) {
                        cout << Fore::BRIGHT_BLACK << "\n  Download cancelled.\n" << Style::RESET_ALL << "\n";
                        continue;
                    }
                    dlCmd = "curl -L ";
                    if (resume) dlCmd += "-C - ";
                    dlCmd += "\"" + reqUrl + "\" -o \"" + reqFile + "\"";
                } else {
                    dlCmd = "powershell -Command \"Invoke-WebRequest -Uri '" + reqUrl + "' -OutFile '" + reqFile + "'\"";
                }
                ret = system(dlCmd.c_str());
                if (ret != 0) goto deps_done;

                cout << "\n" << Fore::TEAL << Style::BOLD << "  [2/2] Installing with pip";
                cout.flush();
                for (int i = 0; i < 3; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";
                ret = system(("python -m pip install -r " + reqFile).c_str());

                deps_done:
                if (ret == 0) {
                    cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                         << " OK  " << Style::RESET_ALL
                         << Fore::BRIGHT_GREEN << "  Python dependencies installed.\n"
                         << Style::RESET_ALL << "\n";
                } else {
                    cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                         << "  [ERROR]  " << Style::RESET_ALL
                         << Fore::RED << "Dependencies install failed (code " << ret << ").\n"
                         << Fore::BRIGHT_BLACK << "  Ensure Python and pip are installed and on PATH.\n"
                         << Style::RESET_ALL << "\n";
                }
            } else {
                cout << Fore::BRIGHT_BLACK << "\n  Installation cancelled.\n" << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "install python" ||
                 command.rfind("install python ", 0) == 0) {
            bool useCurl = false;
            bool useWinget = true;
            if (command.rfind("install python ", 0) == 0) {
                string args = command.substr(string("install python ").size());
                stringstream ss(args);
                string tok;
                while (ss >> tok) {
                    if (tok == "--curl") { useCurl = true; useWinget = false; }
                    else if (tok == "--winget") { useWinget = true; useCurl = false; }
                }
            }
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Python  (winget)\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Command : " << Style::RESET_ALL
                 << Fore::LIME << "winget install -e --id Python.Python.3.10\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with Python install? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {
                int ret = 0;
                if (useCurl) {
                    cout << Fore::BRIGHT_RED << "  [ERROR] curl install not configured for Python.\n"
                         << Fore::BRIGHT_BLACK << "  Use: install python --winget\n"
                         << Style::RESET_ALL << "\n";
                    ret = 1;
                } else {
                    ret = system("winget install -e --id Python.Python.3.10");
                }
                if (ret == 0) {
                    cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                         << " OK  " << Style::RESET_ALL
                         << Fore::BRIGHT_GREEN << "  Python installed.\n"
                         << Style::RESET_ALL << "\n";
                } else {
                    cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                         << "  [ERROR]  " << Style::RESET_ALL
                         << Fore::RED << "Python install failed (code " << ret << ").\n"
                         << Fore::BRIGHT_BLACK << "  Ensure winget is installed or install Python manually.\n"
                         << Style::RESET_ALL << "\n";
                }
            } else {
                cout << Fore::BRIGHT_BLACK << "\n  Installation cancelled.\n" << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "install cmake" ||
                 command.rfind("install cmake ", 0) == 0) {
            bool useCurl = false;
            bool useWinget = true;
            bool resume = false;
            if (command.rfind("install cmake ", 0) == 0) {
                string args = command.substr(string("install cmake ").size());
                stringstream ss(args);
                string tok;
                while (ss >> tok) {
                    if (tok == "--curl") { useCurl = true; useWinget = false; }
                    else if (tok == "--winget") { useWinget = true; useCurl = false; }
                    else if (tok == "--resume") resume = true;
                }
            }
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  CMake  (winget)\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Command : " << Style::RESET_ALL
                 << Fore::LIME << "winget install -e --id Kitware.CMake\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with CMake install? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {
                int ret = 0;
                if (useCurl) {
                    cout << Fore::BRIGHT_YELLOW
                         << "  [WARN] curl downloads are experimental and may fail. "
                         << "We recommend using --winget when available.\n"
                         << Style::RESET_ALL;
                    cout << Fore::GOLD << Style::BOLD
                         << "  Continue with curl? [Y/n]: "
                         << Style::RESET_ALL;
                    cout.flush();
                    string cconfirm;
                    getline(cin, cconfirm);
                    if (!(cconfirm.empty() || cconfirm == "Y" || cconfirm == "y" || cconfirm == "yes" || cconfirm == "YES")) {
                        cout << Fore::BRIGHT_BLACK << "\n  Download cancelled.\n" << Style::RESET_ALL << "\n";
                        continue;
                    }
                    string url = "https://cmake.org/files/v4.2/cmake-4.2.3-windows-x86_64.zip";
                    string outDir = "C:\\PyDuino\\downloads";
                    string zipFile = outDir + "\\cmake.zip";
                    system(("mkdir \"" + outDir + "\" 2>nul").c_str());
                    string dlCmd = "curl -L ";
                    if (resume) dlCmd += "-C - ";
                    dlCmd += "\""+url+"\" -o \""+zipFile+"\"";
                    ret = system(dlCmd.c_str());
                    if (ret == 0) {
                        cout << Fore::BRIGHT_BLACK
                             << "  Downloaded: " << zipFile << "\n"
                             << "  Extract it and add bin to PATH.\n"
                             << Style::RESET_ALL;
                    }
                } else {
                    ret = system("winget install -e --id Kitware.CMake");
                }
                if (ret == 0) {
                    cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                         << " OK  " << Style::RESET_ALL
                         << Fore::BRIGHT_GREEN << "  CMake installed.\n"
                         << Style::RESET_ALL << "\n";
                } else {
                    cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                         << "  [ERROR]  " << Style::RESET_ALL
                         << Fore::RED << "CMake install failed (code " << ret << ").\n"
                         << Fore::BRIGHT_BLACK << "  Ensure winget is installed or install CMake manually.\n"
                         << Style::RESET_ALL << "\n";
                }
            } else {
                cout << Fore::BRIGHT_BLACK << "\n  Installation cancelled.\n" << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "install nvidia-sdk" ||
                 command.rfind("install nvidia-sdk ", 0) == 0) {
            bool useCurl = false;
            bool useWinget = true;
            bool resume = false;
            if (command.rfind("install nvidia-sdk ", 0) == 0) {
                string args = command.substr(string("install nvidia-sdk ").size());
                stringstream ss(args);
                string tok;
                while (ss >> tok) {
                    if (tok == "--curl") { useCurl = true; useWinget = false; }
                    else if (tok == "--winget") { useWinget = true; useCurl = false; }
                    else if (tok == "--resume") resume = true;
                }
            }
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  NVIDIA CUDA SDK  (winget)\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Command : " << Style::RESET_ALL
                 << Fore::LIME << "winget install -e --id NVIDIA.CUDA\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with NVIDIA SDK install? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {
                int ret = 0;
                if (useCurl) {
                    cout << Fore::BRIGHT_YELLOW
                         << "  [WARN] curl downloads are experimental and may fail. "
                         << "We recommend using --winget when available.\n"
                         << Style::RESET_ALL;
                    cout << Fore::GOLD << Style::BOLD
                         << "  Continue with curl? [Y/n]: "
                         << Style::RESET_ALL;
                    cout.flush();
                    string cconfirm;
                    getline(cin, cconfirm);
                    if (!(cconfirm.empty() || cconfirm == "Y" || cconfirm == "y" || cconfirm == "yes" || cconfirm == "YES")) {
                        cout << Fore::BRIGHT_BLACK << "\n  Download cancelled.\n" << Style::RESET_ALL << "\n";
                        continue;
                    }
                    string url = "https://developer.download.nvidia.com/compute/cuda/12.6.0/local_installers/cuda_12.6.0_windows.exe";
                    string outDir = "C:\\PyDuino\\downloads";
                    string exeFile = outDir + "\\cuda_12.6.0_windows.exe";
                    system(("mkdir \"" + outDir + "\" 2>nul").c_str());
                    string dlCmd = "curl -L ";
                    if (resume) dlCmd += "-C - ";
                    dlCmd += "\"" + url + "\" -o \"" + exeFile + "\"";
                    ret = system(dlCmd.c_str());
                    if (ret == 0) {
                        cout << Fore::BRIGHT_BLACK
                             << "  Downloaded: " << exeFile << "\n"
                             << "  Launching installer...\n"
                             << Style::RESET_ALL;
                        system(("\"" + exeFile + "\"").c_str());
                    }
                } else {
                    ret = system("winget install -e --id NVIDIA.CUDA");
                }
                if (ret == 0) {
                    cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                         << " OK  " << Style::RESET_ALL
                         << Fore::BRIGHT_GREEN << "  NVIDIA SDK installed.\n"
                         << Style::RESET_ALL << "\n";
                } else {
                    cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                         << "  [ERROR]  " << Style::RESET_ALL
                         << Fore::RED << "NVIDIA SDK install failed (code " << ret << ").\n"
                         << Fore::BRIGHT_BLACK << "  Ensure winget is installed or install CUDA manually.\n"
                         << Style::RESET_ALL << "\n";
                }
            } else {
                cout << Fore::BRIGHT_BLACK << "\n  Installation cancelled.\n" << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "install vulkan-sdk" ||
                 command.rfind("install vulkan-sdk ", 0) == 0) {
            bool useCurl = false;
            bool useWinget = true;
            bool resume = false;
            if (command.rfind("install vulkan-sdk ", 0) == 0) {
                string args = command.substr(string("install vulkan-sdk ").size());
                stringstream ss(args);
                string tok;
                while (ss >> tok) {
                    if (tok == "--curl") { useCurl = true; useWinget = false; }
                    else if (tok == "--winget") { useWinget = true; useCurl = false; }
                    else if (tok == "--resume") resume = true;
                }
            }
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Vulkan SDK  (winget)\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Command : " << Style::RESET_ALL
                 << Fore::LIME << "winget install -e --id LunarG.VulkanSDK\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with Vulkan SDK install? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {
                int ret = 0;
                if (useCurl) {
                    cout << Fore::BRIGHT_YELLOW
                         << "  [WARN] curl downloads are experimental and may fail. "
                         << "We recommend using --winget when available.\n"
                         << Style::RESET_ALL;
                    cout << Fore::GOLD << Style::BOLD
                         << "  Continue with curl? [Y/n]: "
                         << Style::RESET_ALL;
                    cout.flush();
                    string cconfirm;
                    getline(cin, cconfirm);
                    if (!(cconfirm.empty() || cconfirm == "Y" || cconfirm == "y" || cconfirm == "yes" || cconfirm == "YES")) {
                        cout << Fore::BRIGHT_BLACK << "\n  Download cancelled.\n" << Style::RESET_ALL << "\n";
                        continue;
                    }
                    string url = "https://sdk.lunarg.com/sdk/download/latest/windows/vulkan-sdk.exe";
                    string outDir = "C:\\PyDuino\\downloads";
                    string exeFile = outDir + "\\vulkan-sdk.exe";
                    system(("mkdir \"" + outDir + "\" 2>nul").c_str());
                    string dlCmd = "curl -L ";
                    if (resume) dlCmd += "-C - ";
                    dlCmd += "\"" + url + "\" -o \"" + exeFile + "\"";
                    ret = system(dlCmd.c_str());
                    if (ret == 0) {
                        cout << Fore::BRIGHT_BLACK
                             << "  Downloaded: " << exeFile << "\n"
                             << "  Launching installer...\n"
                             << Style::RESET_ALL;
                        system(("\"" + exeFile + "\"").c_str());
                    }
                } else {
                    ret = system("winget install -e --id LunarG.VulkanSDK");
                }
                if (ret == 0) {
                    cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                         << " OK  " << Style::RESET_ALL
                         << Fore::BRIGHT_GREEN << "  Vulkan SDK installed.\n"
                         << Style::RESET_ALL << "\n";
                } else {
                    cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                         << "  [ERROR]  " << Style::RESET_ALL
                         << Fore::RED << "Vulkan SDK install failed (code " << ret << ").\n"
                         << Fore::BRIGHT_BLACK << "  Ensure winget is installed or install Vulkan SDK manually.\n"
                         << Style::RESET_ALL << "\n";
                }
            } else {
                cout << Fore::BRIGHT_BLACK << "\n  Installation cancelled.\n" << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "install openblas-sdk" ||
                 command.rfind("install openblas-sdk ", 0) == 0) {
            bool useCurl = false;
            bool useWinget = true;
            bool resume = false;
            if (command.rfind("install openblas-sdk ", 0) == 0) {
                string args = command.substr(string("install openblas-sdk ").size());
                stringstream ss(args);
                string tok;
                while (ss >> tok) {
                    if (tok == "--curl") { useCurl = true; useWinget = false; }
                    else if (tok == "--winget") { useWinget = true; useCurl = false; }
                    else if (tok == "--resume") resume = true;
                }
            }
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  OpenBLAS SDK  (vcpkg)\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Tip     : " << Style::RESET_ALL
                 << Fore::LIME << "Use: install openblas\n" << Style::RESET_ALL << "\n";
            cout << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with OpenBLAS install? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {
                int ret = 0;
                if (useCurl) {
                    cout << Fore::BRIGHT_YELLOW
                         << "  [WARN] curl downloads are experimental and may fail. "
                         << "We recommend using --winget when available.\n"
                         << Style::RESET_ALL;
                    cout << Fore::GOLD << Style::BOLD
                         << "  Continue with curl? [Y/n]: "
                         << Style::RESET_ALL;
                    cout.flush();
                    string cconfirm;
                    getline(cin, cconfirm);
                    if (!(cconfirm.empty() || cconfirm == "Y" || cconfirm == "y" || cconfirm == "yes" || cconfirm == "YES")) {
                        cout << Fore::BRIGHT_BLACK << "\n  Download cancelled.\n" << Style::RESET_ALL << "\n";
                        continue;
                    }
                    string url = "https://github.com/xianyi/OpenBLAS/releases/latest/download/OpenBLAS-0.3.26-x64.zip";
                    string outDir = "C:\\PyDuino\\downloads";
                    string zipFile = outDir + "\\openblas.zip";
                    string destDir = "C:\\PyDuino\\tools\\openblas";
                    system(("mkdir \"" + outDir + "\" 2>nul").c_str());
                    system(("mkdir \"" + destDir + "\" 2>nul").c_str());
                    string dlCmd = "curl -L ";
                    if (resume) dlCmd += "-C - ";
                    dlCmd += "\"" + url + "\" -o \"" + zipFile + "\"";
                    ret = system(dlCmd.c_str());
                    if (ret == 0) {
                        string unzipCmd = "powershell -Command \"Expand-Archive -Path '" + zipFile + "' -DestinationPath '" + destDir + "' -Force\"";
                        ret = system(unzipCmd.c_str());
                    }
                    if (ret == 0) {
                        cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                             << " OK  " << Style::RESET_ALL
                             << Fore::BRIGHT_GREEN << "  OpenBLAS extracted to: " << destDir << "\n"
                             << Style::RESET_ALL << "\n";
                    } else {
                        cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                             << "  [ERROR]  " << Style::RESET_ALL
                             << Fore::RED << "OpenBLAS download/extract failed (code " << ret << ").\n"
                             << Style::RESET_ALL << "\n";
                    }
                    continue;
                }
                cout << "\n" << Fore::TEAL << Style::BOLD << "  [1/4] Cloning vcpkg";
                cout.flush();
                for (int i = 0; i < 3; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";
                ret = system("cd C:\\ && git clone https://github.com/Microsoft/vcpkg.git 2>nul || echo vcpkg already exists");
                if (ret != 0) goto openblas_sdk_done;

                cout << "\n" << Fore::TEAL << Style::BOLD << "  [2/4] Bootstrapping vcpkg";
                cout.flush();
                for (int i = 0; i < 3; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";
                ret = system("cd C:\\vcpkg && bootstrap-vcpkg.bat -disableMetrics");
                if (ret != 0) goto openblas_sdk_done;

                cout << "\n" << Fore::TEAL << Style::BOLD << "  [3/4] Installing OpenBLAS";
                cout.flush();
                for (int i = 0; i < 3; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";
                ret = system("C:\\vcpkg\\vcpkg install openblas:x64-windows");
                if (ret != 0) goto openblas_sdk_done;

                cout << "\n" << Fore::TEAL << Style::BOLD << "  [4/4] Integrating vcpkg";
                cout.flush();
                for (int i = 0; i < 3; ++i) { sleep_ms(250); cout << " ."; cout.flush(); }
                cout << Style::RESET_ALL << "\n";
                ret = system("C:\\vcpkg\\vcpkg integrate install");

                openblas_sdk_done:
                if (ret == 0) {
                    cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                         << " OK  " << Style::RESET_ALL
                         << Fore::BRIGHT_GREEN << "  OpenBLAS installed via vcpkg.\n"
                         << Style::RESET_ALL << "\n";
                } else {
                    cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                         << "  [ERROR]  " << Style::RESET_ALL
                         << Fore::RED << "OpenBLAS install failed (code " << ret << ").\n"
                         << Fore::BRIGHT_BLACK << "  Make sure git is installed and you have internet access.\n"
                         << Style::RESET_ALL << "\n";
                }
            } else {
                cout << Fore::BRIGHT_BLACK << "\n  Installation cancelled.\n" << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "install amd-sdk" ||
                 command.rfind("install amd-sdk ", 0) == 0) {
            bool useCurl = false;
            bool useWinget = true;
            bool resume = false;
            if (command.rfind("install amd-sdk ", 0) == 0) {
                string args = command.substr(string("install amd-sdk ").size());
                stringstream ss(args);
                string tok;
                while (ss >> tok) {
                    if (tok == "--curl") { useCurl = true; useWinget = false; }
                    else if (tok == "--winget") { useWinget = true; useCurl = false; }
                    else if (tok == "--resume") resume = true;
                }
            }
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  AMD SDK  (winget)\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Command : " << Style::RESET_ALL
                 << Fore::LIME << "winget install -e --id AMD.RadeonSDK\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with AMD SDK install? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {
                int ret = 0;
                if (useCurl) {
                    cout << Fore::BRIGHT_YELLOW
                         << "  [WARN] curl downloads are experimental and may fail. "
                         << "We recommend using --winget when available.\n"
                         << Style::RESET_ALL;
                    cout << Fore::GOLD << Style::BOLD
                         << "  Continue with curl? [Y/n]: "
                         << Style::RESET_ALL;
                    cout.flush();
                    string cconfirm;
                    getline(cin, cconfirm);
                    if (!(cconfirm.empty() || cconfirm == "Y" || cconfirm == "y" || cconfirm == "yes" || cconfirm == "YES")) {
                        cout << Fore::BRIGHT_BLACK << "\n  Download cancelled.\n" << Style::RESET_ALL << "\n";
                        continue;
                    }
                    string url = "https://repo.radeon.com/rocm/windows/rocm-install.exe";
                    string outDir = "C:\\PyDuino\\downloads";
                    string exeFile = outDir + "\\rocm-install.exe";
                    system(("mkdir \"" + outDir + "\" 2>nul").c_str());
                    string dlCmd = "curl -L ";
                    if (resume) dlCmd += "-C - ";
                    dlCmd += "\"" + url + "\" -o \"" + exeFile + "\"";
                    ret = system(dlCmd.c_str());
                    if (ret == 0) {
                        cout << Fore::BRIGHT_BLACK
                             << "  Downloaded: " << exeFile << "\n"
                             << "  Launching installer...\n"
                             << Style::RESET_ALL;
                        system(("\"" + exeFile + "\"").c_str());
                    }
                } else {
                    ret = system("winget install -e --id AMD.RadeonSDK");
                }
                if (ret == 0) {
                    cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                         << " OK  " << Style::RESET_ALL
                         << Fore::BRIGHT_GREEN << "  AMD SDK installed.\n"
                         << Style::RESET_ALL << "\n";
                } else {
                    cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                         << "  [ERROR]  " << Style::RESET_ALL
                         << Fore::RED << "AMD SDK install failed (code " << ret << ").\n"
                         << Fore::BRIGHT_BLACK << "  Ensure winget is installed or install AMD SDK manually.\n"
                         << Style::RESET_ALL << "\n";
                }
            } else {
                cout << Fore::BRIGHT_BLACK << "\n  Installation cancelled.\n" << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "install pyduino-versions" ||
                 command.rfind("install pyduino-versions ", 0) == 0) {
            bool useCurl = true;
            bool resume = false;
            if (command.rfind("install pyduino-versions ", 0) == 0) {
                string args = command.substr(string("install pyduino-versions ").size());
                stringstream ss(args);
                string tok;
                while (ss >> tok) {
                    if (tok == "--curl") useCurl = true;
                    else if (tok == "--resume") resume = true;
                }
            }
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  PyDuino Versions Metadata\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Source  : " << Style::RESET_ALL
                 << Fore::SKY << "https://github.com/pyduinocontact-alt/versions/blob/main/versions.metadata\n"
                 << Style::RESET_ALL;
            cout << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Download versions metadata? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES") {
                string metaUrl = "https://raw.githubusercontent.com/pyduinocontact-alt/versions/main/versions.metadata";
                string metaFile = "versions.metadata";
                string dlCmd;
                if (useCurl) {
                    cout << Fore::BRIGHT_YELLOW
                         << "  [WARN] curl downloads are experimental and may fail. "
                         << "We recommend using --winget when available.\n"
                         << Style::RESET_ALL;
                    cout << Fore::GOLD << Style::BOLD
                         << "  Continue with curl? [Y/n]: "
                         << Style::RESET_ALL;
                    cout.flush();
                    string cconfirm;
                    getline(cin, cconfirm);
                    if (!(cconfirm.empty() || cconfirm == "Y" || cconfirm == "y" || cconfirm == "yes" || cconfirm == "YES")) {
                        cout << Fore::BRIGHT_BLACK << "\n  Download cancelled.\n" << Style::RESET_ALL << "\n";
                        continue;
                    }
                    dlCmd = "curl -L ";
                    if (resume) dlCmd += "-C - ";
                    dlCmd += "\"" + metaUrl + "\" -o \"" + metaFile + "\"";
                } else {
                    dlCmd = "powershell -Command \"Invoke-WebRequest -Uri '" + metaUrl + "' -OutFile '" + metaFile + "'\"";
                }
                int ret = system(dlCmd.c_str());
                if (ret == 0) {
                    cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                         << " OK  " << Style::RESET_ALL
                         << Fore::BRIGHT_GREEN << "  Saved: " << metaFile << "\n"
                         << Style::RESET_ALL << "\n";
                } else {
                    cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                         << "  [ERROR]  " << Style::RESET_ALL
                         << Fore::RED << "Download failed (code " << ret << ").\n"
                         << Style::RESET_ALL << "\n";
                }
            } else {
                cout << Fore::BRIGHT_BLACK << "\n  Download cancelled.\n" << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "setup python") {
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Python  Setup Check\n" << Style::RESET_ALL << "\n";

            int ret = system("python --version >nul 2>nul");
            if (ret == 0) {
                cout << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Python is installed and on PATH.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "python not found on PATH.\n"
                     << Fore::BRIGHT_BLACK << "  Install with: install python\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "setup cmake") {
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  CMake  Setup Check\n" << Style::RESET_ALL << "\n";
            int ret = system("cmake --version >nul 2>nul");
            if (ret == 0) {
                cout << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  CMake is installed and on PATH.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "cmake not found on PATH.\n"
                     << Fore::BRIGHT_BLACK << "  Install with: install cmake\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "setup nvidia-sdk") {
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  NVIDIA SDK  Setup Check\n" << Style::RESET_ALL << "\n";
            int ret = system("nvcc --version >nul 2>nul");
            if (ret == 0) {
                cout << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  NVIDIA CUDA (nvcc) is on PATH.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "nvcc not found on PATH.\n"
                     << Fore::BRIGHT_BLACK << "  Install with: install nvidia-sdk\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "setup vulkan-sdk") {
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Vulkan SDK  Setup Check\n" << Style::RESET_ALL << "\n";
            int ret = system("vulkaninfo >nul 2>nul");
            if (ret == 0) {
                cout << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Vulkan SDK is installed and on PATH.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "vulkaninfo not found on PATH.\n"
                     << Fore::BRIGHT_BLACK << "  Install with: install vulkan-sdk\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "setup openblas-sdk") {
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  OpenBLAS SDK  Setup Check\n" << Style::RESET_ALL << "\n";
            string dll = "C:\\vcpkg\\installed\\x64-windows\\bin\\openblas.dll";
            string checkCmd = "if exist \"" + dll + "\" (exit /b 0) else (exit /b 1)";
            int ret = system(checkCmd.c_str());
            if (ret == 0) {
                cout << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  OpenBLAS is installed.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "OpenBLAS not found.\n"
                     << Fore::BRIGHT_BLACK << "  Install with: install openblas-sdk\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "setup amd-sdk") {
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  AMD SDK  Setup Check\n" << Style::RESET_ALL << "\n";
            string basePath = "C:\\Program Files\\AMD";
            string checkCmd = "if exist \"" + basePath + "\" (exit /b 0) else (exit /b 1)";
            int ret = system(checkCmd.c_str());
            if (ret == 0) {
                cout << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  AMD SDK appears installed.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "AMD SDK not found.\n"
                     << Fore::BRIGHT_BLACK << "  Install with: install amd-sdk\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "launch python-exe" ||
                 command.rfind("launch python-exe ", 0) == 0) {
            string args = "";
            if (command.rfind("launch python-exe ", 0) == 0)
                args = command.substr(string("launch python-exe ").size());

            string cmd = "python";
            if (!args.empty()) cmd += " " + args;
            system(cmd.c_str());
        }

        else if (command == "pyduino list-versions") {
            string metaFile = "versions.metadata";
            string checkCmd = "if exist \"" + metaFile + "\" (exit /b 0) else (exit /b 1)";
            if (system(checkCmd.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] versions.metadata not found.\n"
                     << Fore::BRIGHT_BLACK << "  Run: install pyduino-versions\n"
                     << Style::RESET_ALL;
                continue;
            }
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  PyDuino Versions\n" << Style::RESET_ALL << "\n";
            system(("type \"" + metaFile + "\"").c_str());
            cout << "\n";
        }

        else if (command == "install pyduino" ||
                 command.rfind("install pyduino ", 0) == 0) {
            bool useCurl = true;
            bool resume = false;
            string version = "";
            string args = "";
            if (command.rfind("install pyduino ", 0) == 0)
                args = command.substr(string("install pyduino ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--curl") useCurl = true;
                else if (tok == "--resume") resume = true;
                else if (version.empty()) version = tok;
            }

            if (version.empty()) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Missing version.\n"
                     << Fore::BRIGHT_BLACK << "  Usage: install pyduino <version>\n"
                     << Style::RESET_ALL;
                continue;
            }

            string metaFile = "versions.metadata";
            string checkCmd = "if exist \"" + metaFile + "\" (exit /b 0) else (exit /b 1)";
            if (system(checkCmd.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] versions.metadata not found.\n"
                     << Fore::BRIGHT_BLACK << "  Run: install pyduino-versions\n"
                     << Style::RESET_ALL;
                continue;
            }

            string listCmd = "powershell -Command \"Get-Content '" + metaFile + "'\"";
            FILE* pipe = _popen(listCmd.c_str(), "r");
            string matchLine = "";
            if (pipe) {
                char buffer[4096];
                while (fgets(buffer, sizeof(buffer), pipe)) {
                    string line = buffer;
                    if (line.find(version) != string::npos) {
                        matchLine = line;
                        break;
                    }
                }
                _pclose(pipe);
            }

            if (matchLine.empty()) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Version not found in metadata.\n"
                     << Fore::BRIGHT_BLACK << "  Run: pyduino list-versions\n"
                     << Style::RESET_ALL;
                continue;
            }

            // parse line: name | size | date | url
            string url = "";
            {
                size_t lastBar = matchLine.rfind('|');
                if (lastBar != string::npos) {
                    url = matchLine.substr(lastBar + 1);
                    // trim spaces
                    while (!url.empty() && (url.front() == ' ' || url.front() == '\t')) url.erase(url.begin());
                    while (!url.empty() && (url.back()  == ' ' || url.back()  == '\t' || url.back()=='\r' || url.back()=='\n')) url.pop_back();
                }
            }

            if (url.empty()) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Could not parse URL.\n" << Style::RESET_ALL;
                continue;
            }

            string baseDir = "C:\\PyDuino\\versions";
            string safeVer = version;
            for (char &c : safeVer) { if (c == ' ' || c == '\\' || c == '/' || c == ':' ) c = '_'; }
            string destDir = baseDir + "\\" + safeVer;
            string zipFile = destDir + "\\pyduino.zip";

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Install PyDuino " << version << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  URL     : " << Style::RESET_ALL << Fore::SKY << url << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Target  : " << Style::RESET_ALL << Fore::LIME << destDir << "\n" << Style::RESET_ALL << "\n";

            system(("mkdir \"" + destDir + "\" 2>nul").c_str());

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with download & extract? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (!(confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES")) {
                cout << Fore::BRIGHT_BLACK << "\n  Install cancelled.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            int ret = 0;
            string dlCmd;
            if (useCurl) {
                cout << Fore::BRIGHT_YELLOW
                     << "  [WARN] curl downloads are experimental and may fail. "
                     << "We recommend using --winget when available.\n"
                     << Style::RESET_ALL;
                cout << Fore::GOLD << Style::BOLD
                     << "  Continue with curl? [Y/n]: "
                     << Style::RESET_ALL;
                cout.flush();
                string cconfirm;
                getline(cin, cconfirm);
                if (!(cconfirm.empty() || cconfirm == "Y" || cconfirm == "y" || cconfirm == "yes" || cconfirm == "YES")) {
                    cout << Fore::BRIGHT_BLACK << "\n  Download cancelled.\n" << Style::RESET_ALL << "\n";
                    continue;
                }
                dlCmd = "curl -L ";
                if (resume) dlCmd += "-C - ";
                dlCmd += "\"" + url + "\" -o \"" + zipFile + "\"";
            } else {
                dlCmd = "powershell -Command \"Invoke-WebRequest -Uri '" + url + "' -OutFile '" + zipFile + "'\"";
            }
            ret = system(dlCmd.c_str());
            if (ret != 0) {
                cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "Download failed (code " << ret << ").\n"
                     << Style::RESET_ALL << "\n";
                continue;
            }

            string unzipCmd = "powershell -Command \"Expand-Archive -Path '" + zipFile + "' -DestinationPath '" + destDir + "' -Force\"";
            ret = system(unzipCmd.c_str());
            if (ret == 0) {
                cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Installed to: " << destDir << "\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "Extract failed (code " << ret << ").\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "pyduino launch" ||
                 command.rfind("pyduino launch ", 0) == 0) {
            string version = "";
            string args = "";
            if (command.rfind("pyduino launch ", 0) == 0)
                args = command.substr(string("pyduino launch ").size());

            stringstream ss(args);
            string tok;
            if (ss >> tok) version = tok;

            if (version.empty()) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Missing version.\n"
                     << Fore::BRIGHT_BLACK << "  Usage: pyduino launch <version>\n"
                     << Style::RESET_ALL;
                continue;
            }

            string baseDir = "C:\\PyDuino\\versions";
            string safeVer = version;
            for (char &c : safeVer) { if (c == ' ' || c == '\\' || c == '/' || c == ':' ) c = '_'; }
            string destDir = baseDir + "\\" + safeVer;

            string checkCmd = "if exist \"" + destDir + "\\PYDUINOide.py\" (exit /b 0) else (exit /b 1)";
            if (system(checkCmd.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] PYDUINOide.py not found in: " << destDir << "\n"
                     << Fore::BRIGHT_BLACK << "  Install with: install pyduino " << version << "\n"
                     << Style::RESET_ALL;
                continue;
            }

            string launchCmd = "cd \"" + destDir + "\" && python PYDUINOide.py";
            system(launchCmd.c_str());
        }

        else if (command == "add model llama.cpp" ||
                 command.rfind("add model llama.cpp ", 0) == 0) {

            string modelPath = "";
            string llamaPath = "C:\\llama.cpp";

            string args = "";
            if (command.rfind("add model llama.cpp ", 0) == 0)
                args = command.substr(string("add model llama.cpp ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok.rfind("--model=", 0) == 0) modelPath = tok.substr(8);
                else if (tok.rfind("--path=", 0) == 0) llamaPath = tok.substr(7);
                else if (modelPath.empty()) modelPath = tok;
                else llamaPath = tok;
            }

            if (modelPath.empty()) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Missing .gguf path.\n"
                     << Fore::BRIGHT_BLACK << "  Usage: add model llama.cpp <gguf> [path]\n"
                     << Style::RESET_ALL;
                continue;
            }

            if (!modelPath.empty() && modelPath.front() == '"') modelPath = modelPath.substr(1);
            if (!modelPath.empty() && modelPath.back()  == '"') modelPath.pop_back();
            if (!llamaPath.empty() && llamaPath.front() == '"') llamaPath = llamaPath.substr(1);
            if (!llamaPath.empty() && llamaPath.back()  == '"') llamaPath.pop_back();

            string modelsDir = llamaPath + "\\models";
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Add model to llama.cpp\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Model   : " << Style::RESET_ALL << Fore::LIME << modelPath << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Target  : " << Style::RESET_ALL << Fore::LIME << modelsDir << "\n" << Style::RESET_ALL << "\n";

            string checkModel = "if exist \"" + modelPath + "\" (exit /b 0) else (exit /b 1)";
            if (system(checkModel.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Model file not found.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            system(("mkdir \"" + modelsDir + "\" 2>nul").c_str());
            string copyCmd = "copy /y \"" + modelPath + "\" \"" + modelsDir + "\\\"";
            int ret = system(copyCmd.c_str());
            if (ret == 0) {
                cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Model copied to: " << modelsDir << "\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "Copy failed (code " << ret << ").\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "dir llama.cpp" ||
                 command == "dirs llama.cpp" ||
                 command.rfind("dir llama.cpp ", 0) == 0 ||
                 command.rfind("dirs llama.cpp ", 0) == 0) {

            string basePath = "C:\\llama.cpp";
            string folder = "";
            bool listDirs = true;
            bool listFiles = false;
            bool listAll = false;

            string args = "";
            if (command.rfind("dir llama.cpp ", 0) == 0)
                args = command.substr(string("dir llama.cpp ").size());
            else if (command.rfind("dirs llama.cpp ", 0) == 0)
                args = command.substr(string("dirs llama.cpp ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--all") { listAll = true; listDirs = true; listFiles = true; }
                else if (tok == "--files") { listFiles = true; listDirs = false; listAll = false; }
                else if (tok == "--dirs") { listDirs = true; listFiles = false; listAll = false; }
                else if (tok == "--folder") { if (ss >> tok) folder = tok; }
                else if (tok.rfind("--folder=", 0) == 0) folder = tok.substr(9);
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
                else { basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();
            if (!folder.empty() && folder.front() == '"') folder = folder.substr(1);
            if (!folder.empty() && folder.back()  == '"') folder.pop_back();

            string target = folder.empty() ? basePath : (basePath + "\\" + folder);

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Directory listing\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << target << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Mode    : " << Style::RESET_ALL
                 << Fore::SKY << (listAll ? "all" : (listFiles ? "files" : "dirs")) << "\n"
                 << Style::RESET_ALL << "\n";

            string checkCmd = "if exist \"" + target + "\" (exit /b 0) else (exit /b 1)";
            if (system(checkCmd.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Path not found.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            string dirCmd;
            if (listAll) dirCmd = "dir /b \"" + target + "\"";
            else if (listFiles) dirCmd = "dir /b /a-d \"" + target + "\"";
            else dirCmd = "dir /b /ad \"" + target + "\"";

            system(dirCmd.c_str());
            cout << "\n";
        }

        else if (command == "setup graphviz") {
            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Graphviz  Setup Check\n" << Style::RESET_ALL << "\n";

            int ret = system("dot -V >nul 2>nul");
            if (ret == 0) {
                cout << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Graphviz is installed and on PATH.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "dot not found on PATH.\n"
                     << Fore::BRIGHT_BLACK << "  Install with: install graphviz\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "dir graphviz" ||
                 command.rfind("dir graphviz ", 0) == 0) {

            string basePath = "C:\\Program Files\\Graphviz";
            bool listDirs = true;
            bool listFiles = false;
            bool listAll = false;

            string args = "";
            if (command.rfind("dir graphviz ", 0) == 0)
                args = command.substr(string("dir graphviz ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--all") { listAll = true; listDirs = true; listFiles = true; }
                else if (tok == "--files") { listFiles = true; listDirs = false; listAll = false; }
                else if (tok == "--dirs") { listDirs = true; listFiles = false; listAll = false; }
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
                else { basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Graphviz directory listing\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Mode    : " << Style::RESET_ALL
                 << Fore::SKY << (listAll ? "all" : (listFiles ? "files" : "dirs")) << "\n"
                 << Style::RESET_ALL << "\n";

            string checkCmd = "if exist \"" + basePath + "\" (exit /b 0) else (exit /b 1)";
            if (system(checkCmd.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Path not found.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            string dirCmd;
            if (listAll) dirCmd = "dir /b \"" + basePath + "\"";
            else if (listFiles) dirCmd = "dir /b /a-d \"" + basePath + "\"";
            else dirCmd = "dir /b /ad \"" + basePath + "\"";

            system(dirCmd.c_str());
            cout << "\n";
        }

        else if (command == "dir python" ||
                 command.rfind("dir python ", 0) == 0) {

            string basePath = "C:\\Users\\bismi\\AppData\\Local\\Programs\\Python";
            bool listDirs = true;
            bool listFiles = false;
            bool listAll = false;

            string args = "";
            if (command.rfind("dir python ", 0) == 0)
                args = command.substr(string("dir python ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--all") { listAll = true; listDirs = true; listFiles = true; }
                else if (tok == "--files") { listFiles = true; listDirs = false; listAll = false; }
                else if (tok == "--dirs") { listDirs = true; listFiles = false; listAll = false; }
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
                else { basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Python directory listing\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Mode    : " << Style::RESET_ALL
                 << Fore::SKY << (listAll ? "all" : (listFiles ? "files" : "dirs")) << "\n"
                 << Style::RESET_ALL << "\n";

            string checkCmd = "if exist \"" + basePath + "\" (exit /b 0) else (exit /b 1)";
            if (system(checkCmd.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Path not found.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            string dirCmd;
            if (listAll) dirCmd = "dir /b \"" + basePath + "\"";
            else if (listFiles) dirCmd = "dir /b /a-d \"" + basePath + "\"";
            else dirCmd = "dir /b /ad \"" + basePath + "\"";

            system(dirCmd.c_str());
            cout << "\n";
        }

        else if (command == "dir cmake" ||
                 command.rfind("dir cmake ", 0) == 0) {
            string basePath = "C:\\Program Files\\CMake";
            bool listDirs = true;
            bool listFiles = false;
            bool listAll = false;

            string args = "";
            if (command.rfind("dir cmake ", 0) == 0)
                args = command.substr(string("dir cmake ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--all") { listAll = true; listDirs = true; listFiles = true; }
                else if (tok == "--files") { listFiles = true; listDirs = false; listAll = false; }
                else if (tok == "--dirs") { listDirs = true; listFiles = false; listAll = false; }
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
                else { basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  CMake directory listing\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Mode    : " << Style::RESET_ALL
                 << Fore::SKY << (listAll ? "all" : (listFiles ? "files" : "dirs")) << "\n"
                 << Style::RESET_ALL << "\n";

            string checkCmd = "if exist \"" + basePath + "\" (exit /b 0) else (exit /b 1)";
            if (system(checkCmd.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Path not found.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            string dirCmd;
            if (listAll) dirCmd = "dir /b \"" + basePath + "\"";
            else if (listFiles) dirCmd = "dir /b /a-d \"" + basePath + "\"";
            else dirCmd = "dir /b /ad \"" + basePath + "\"";

            system(dirCmd.c_str());
            cout << "\n";
        }

        else if (command == "dir nvidia-sdk" ||
                 command.rfind("dir nvidia-sdk ", 0) == 0) {
            string basePath = "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA";
            bool listDirs = true;
            bool listFiles = false;
            bool listAll = false;

            string args = "";
            if (command.rfind("dir nvidia-sdk ", 0) == 0)
                args = command.substr(string("dir nvidia-sdk ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--all") { listAll = true; listDirs = true; listFiles = true; }
                else if (tok == "--files") { listFiles = true; listDirs = false; listAll = false; }
                else if (tok == "--dirs") { listDirs = true; listFiles = false; listAll = false; }
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
                else { basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  NVIDIA SDK directory listing\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Mode    : " << Style::RESET_ALL
                 << Fore::SKY << (listAll ? "all" : (listFiles ? "files" : "dirs")) << "\n"
                 << Style::RESET_ALL << "\n";

            string checkCmd = "if exist \"" + basePath + "\" (exit /b 0) else (exit /b 1)";
            if (system(checkCmd.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Path not found.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            string dirCmd;
            if (listAll) dirCmd = "dir /b \"" + basePath + "\"";
            else if (listFiles) dirCmd = "dir /b /a-d \"" + basePath + "\"";
            else dirCmd = "dir /b /ad \"" + basePath + "\"";

            system(dirCmd.c_str());
            cout << "\n";
        }

        else if (command == "dir vulkan-sdk" ||
                 command.rfind("dir vulkan-sdk ", 0) == 0) {
            string basePath = "C:\\VulkanSDK";
            bool listDirs = true;
            bool listFiles = false;
            bool listAll = false;

            string args = "";
            if (command.rfind("dir vulkan-sdk ", 0) == 0)
                args = command.substr(string("dir vulkan-sdk ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--all") { listAll = true; listDirs = true; listFiles = true; }
                else if (tok == "--files") { listFiles = true; listDirs = false; listAll = false; }
                else if (tok == "--dirs") { listDirs = true; listFiles = false; listAll = false; }
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
                else { basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Vulkan SDK directory listing\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Mode    : " << Style::RESET_ALL
                 << Fore::SKY << (listAll ? "all" : (listFiles ? "files" : "dirs")) << "\n"
                 << Style::RESET_ALL << "\n";

            string checkCmd = "if exist \"" + basePath + "\" (exit /b 0) else (exit /b 1)";
            if (system(checkCmd.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Path not found.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            string dirCmd;
            if (listAll) dirCmd = "dir /b \"" + basePath + "\"";
            else if (listFiles) dirCmd = "dir /b /a-d \"" + basePath + "\"";
            else dirCmd = "dir /b /ad \"" + basePath + "\"";

            system(dirCmd.c_str());
            cout << "\n";
        }

        else if (command == "dir openblas-sdk" ||
                 command.rfind("dir openblas-sdk ", 0) == 0) {
            string basePath = "C:\\vcpkg";
            bool listDirs = true;
            bool listFiles = false;
            bool listAll = false;

            string args = "";
            if (command.rfind("dir openblas-sdk ", 0) == 0)
                args = command.substr(string("dir openblas-sdk ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--all") { listAll = true; listDirs = true; listFiles = true; }
                else if (tok == "--files") { listFiles = true; listDirs = false; listAll = false; }
                else if (tok == "--dirs") { listDirs = true; listFiles = false; listAll = false; }
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
                else { basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  OpenBLAS SDK directory listing\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Mode    : " << Style::RESET_ALL
                 << Fore::SKY << (listAll ? "all" : (listFiles ? "files" : "dirs")) << "\n"
                 << Style::RESET_ALL << "\n";

            string checkCmd = "if exist \"" + basePath + "\" (exit /b 0) else (exit /b 1)";
            if (system(checkCmd.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Path not found.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            string dirCmd;
            if (listAll) dirCmd = "dir /b \"" + basePath + "\"";
            else if (listFiles) dirCmd = "dir /b /a-d \"" + basePath + "\"";
            else dirCmd = "dir /b /ad \"" + basePath + "\"";

            system(dirCmd.c_str());
            cout << "\n";
        }

        else if (command == "dir amd-sdk" ||
                 command.rfind("dir amd-sdk ", 0) == 0) {
            string basePath = "C:\\Program Files\\AMD";
            bool listDirs = true;
            bool listFiles = false;
            bool listAll = false;

            string args = "";
            if (command.rfind("dir amd-sdk ", 0) == 0)
                args = command.substr(string("dir amd-sdk ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--all") { listAll = true; listDirs = true; listFiles = true; }
                else if (tok == "--files") { listFiles = true; listDirs = false; listAll = false; }
                else if (tok == "--dirs") { listDirs = true; listFiles = false; listAll = false; }
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
                else { basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  AMD SDK directory listing\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Mode    : " << Style::RESET_ALL
                 << Fore::SKY << (listAll ? "all" : (listFiles ? "files" : "dirs")) << "\n"
                 << Style::RESET_ALL << "\n";

            string checkCmd = "if exist \"" + basePath + "\" (exit /b 0) else (exit /b 1)";
            if (system(checkCmd.c_str()) != 0) {
                cout << Fore::BRIGHT_RED << "  [ERROR] Path not found.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            string dirCmd;
            if (listAll) dirCmd = "dir /b \"" + basePath + "\"";
            else if (listFiles) dirCmd = "dir /b /a-d \"" + basePath + "\"";
            else dirCmd = "dir /b /ad \"" + basePath + "\"";

            system(dirCmd.c_str());
            cout << "\n";
        }

        else if (command == "remove llama.cpp" ||
                 command.rfind("remove llama.cpp ", 0) == 0) {

            bool removeModels = false;
            bool removeBuild  = false;
            bool removeWhole  = false;
            string basePath = "C:\\llama.cpp";

            string args = "";
            if (command.rfind("remove llama.cpp ", 0) == 0)
                args = command.substr(string("remove llama.cpp ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--models") removeModels = true;
                else if (tok == "--build") removeBuild = true;
                else if (tok == "--whole") removeWhole = true;
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            if (!removeModels && !removeBuild && !removeWhole) {
                cout << Fore::BRIGHT_RED << "  [ERROR] No remove target specified.\n"
                     << Fore::BRIGHT_BLACK << "  Use: remove llama.cpp --models|--build|--whole [--path P]\n"
                     << Style::RESET_ALL;
                continue;
            }

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Remove llama.cpp items\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Base    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Targets : " << Style::RESET_ALL
                 << Fore::SKY
                 << (removeWhole ? "whole" :
                    (string(removeModels ? "models " : "") + string(removeBuild ? "build " : "")))
                 << "\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with delete? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (!(confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES")) {
                cout << Fore::BRIGHT_BLACK << "\n  Cancelled.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            int ret = 0;
            if (removeWhole) {
                string cmd = "rmdir /s /q \"" + basePath + "\"";
                ret = system(cmd.c_str());
            } else {
                if (removeModels) {
                    string cmd = "rmdir /s /q \"" + basePath + "\\models\"";
                    ret = system(cmd.c_str());
                }
                if (removeBuild) {
                    string cmd = "rmdir /s /q \"" + basePath + "\\build\"";
                    int r2 = system(cmd.c_str());
                    if (ret == 0) ret = r2;
                }
            }

            if (ret == 0) {
                cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Remove completed.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "Remove failed (code " << ret << ").\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "remove graphviz" ||
                 command.rfind("remove graphviz ", 0) == 0) {

            bool removeWhole  = false;
            string basePath = "C:\\Program Files\\Graphviz";

            string args = "";
            if (command.rfind("remove graphviz ", 0) == 0)
                args = command.substr(string("remove graphviz ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--whole") removeWhole = true;
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            if (!removeWhole) {
                cout << Fore::BRIGHT_RED << "  [ERROR] No remove target specified.\n"
                     << Fore::BRIGHT_BLACK << "  Use: remove graphviz --whole [--path P]\n"
                     << Style::RESET_ALL;
                continue;
            }

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Remove Graphviz\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with delete? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (!(confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES")) {
                cout << Fore::BRIGHT_BLACK << "\n  Cancelled.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            int ret = system(("rmdir /s /q \"" + basePath + "\"").c_str());
            if (ret == 0) {
                cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Remove completed.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "Remove failed (code " << ret << ").\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "remove python" ||
                 command.rfind("remove python ", 0) == 0) {

            bool removeWhole  = false;
            string basePath = "C:\\Users\\bismi\\AppData\\Local\\Programs\\Python";

            string args = "";
            if (command.rfind("remove python ", 0) == 0)
                args = command.substr(string("remove python ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--whole") removeWhole = true;
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            if (!removeWhole) {
                cout << Fore::BRIGHT_RED << "  [ERROR] No remove target specified.\n"
                     << Fore::BRIGHT_BLACK << "  Use: remove python --whole [--path P]\n"
                     << Style::RESET_ALL;
                continue;
            }

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Remove Python\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with delete? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (!(confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES")) {
                cout << Fore::BRIGHT_BLACK << "\n  Cancelled.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            int ret = system(("rmdir /s /q \"" + basePath + "\"").c_str());
            if (ret == 0) {
                cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Remove completed.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "Remove failed (code " << ret << ").\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "remove cmake" ||
                 command.rfind("remove cmake ", 0) == 0) {
            bool removeWhole  = false;
            string basePath = "C:\\Program Files\\CMake";

            string args = "";
            if (command.rfind("remove cmake ", 0) == 0)
                args = command.substr(string("remove cmake ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--whole") removeWhole = true;
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            if (!removeWhole) {
                cout << Fore::BRIGHT_RED << "  [ERROR] No remove target specified.\n"
                     << Fore::BRIGHT_BLACK << "  Use: remove cmake --whole [--path P]\n"
                     << Style::RESET_ALL;
                continue;
            }

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Remove CMake\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with delete? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (!(confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES")) {
                cout << Fore::BRIGHT_BLACK << "\n  Cancelled.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            int ret = system(("rmdir /s /q \"" + basePath + "\"").c_str());
            if (ret == 0) {
                cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Remove completed.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "Remove failed (code " << ret << ").\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "remove nvidia-sdk" ||
                 command.rfind("remove nvidia-sdk ", 0) == 0) {
            bool removeWhole  = false;
            string basePath = "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA";

            string args = "";
            if (command.rfind("remove nvidia-sdk ", 0) == 0)
                args = command.substr(string("remove nvidia-sdk ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--whole") removeWhole = true;
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            if (!removeWhole) {
                cout << Fore::BRIGHT_RED << "  [ERROR] No remove target specified.\n"
                     << Fore::BRIGHT_BLACK << "  Use: remove nvidia-sdk --whole [--path P]\n"
                     << Style::RESET_ALL;
                continue;
            }

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Remove NVIDIA SDK\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with delete? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (!(confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES")) {
                cout << Fore::BRIGHT_BLACK << "\n  Cancelled.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            int ret = system(("rmdir /s /q \"" + basePath + "\"").c_str());
            if (ret == 0) {
                cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Remove completed.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "Remove failed (code " << ret << ").\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "remove vulkan-sdk" ||
                 command.rfind("remove vulkan-sdk ", 0) == 0) {
            bool removeWhole  = false;
            string basePath = "C:\\VulkanSDK";

            string args = "";
            if (command.rfind("remove vulkan-sdk ", 0) == 0)
                args = command.substr(string("remove vulkan-sdk ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--whole") removeWhole = true;
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            if (!removeWhole) {
                cout << Fore::BRIGHT_RED << "  [ERROR] No remove target specified.\n"
                     << Fore::BRIGHT_BLACK << "  Use: remove vulkan-sdk --whole [--path P]\n"
                     << Style::RESET_ALL;
                continue;
            }

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Remove Vulkan SDK\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with delete? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (!(confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES")) {
                cout << Fore::BRIGHT_BLACK << "\n  Cancelled.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            int ret = system(("rmdir /s /q \"" + basePath + "\"").c_str());
            if (ret == 0) {
                cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Remove completed.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "Remove failed (code " << ret << ").\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "remove openblas-sdk" ||
                 command.rfind("remove openblas-sdk ", 0) == 0) {
            bool removeWhole  = false;
            string basePath = "C:\\vcpkg";

            string args = "";
            if (command.rfind("remove openblas-sdk ", 0) == 0)
                args = command.substr(string("remove openblas-sdk ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--whole") removeWhole = true;
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            if (!removeWhole) {
                cout << Fore::BRIGHT_RED << "  [ERROR] No remove target specified.\n"
                     << Fore::BRIGHT_BLACK << "  Use: remove openblas-sdk --whole [--path P]\n"
                     << Style::RESET_ALL;
                continue;
            }

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Remove OpenBLAS SDK\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with delete? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (!(confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES")) {
                cout << Fore::BRIGHT_BLACK << "\n  Cancelled.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            int ret = system(("rmdir /s /q \"" + basePath + "\"").c_str());
            if (ret == 0) {
                cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Remove completed.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "Remove failed (code " << ret << ").\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "remove amd-sdk" ||
                 command.rfind("remove amd-sdk ", 0) == 0) {
            bool removeWhole  = false;
            string basePath = "C:\\Program Files\\AMD";

            string args = "";
            if (command.rfind("remove amd-sdk ", 0) == 0)
                args = command.substr(string("remove amd-sdk ").size());

            stringstream ss(args);
            string tok;
            while (ss >> tok) {
                if (tok == "--whole") removeWhole = true;
                else if (tok.rfind("--path=", 0) == 0) basePath = tok.substr(7);
                else if (tok == "--path") { if (ss >> tok) basePath = tok; }
            }

            if (!basePath.empty() && basePath.front() == '"') basePath = basePath.substr(1);
            if (!basePath.empty() && basePath.back()  == '"') basePath.pop_back();

            if (!removeWhole) {
                cout << Fore::BRIGHT_RED << "  [ERROR] No remove target specified.\n"
                     << Fore::BRIGHT_BLACK << "  Use: remove amd-sdk --whole [--path P]\n"
                     << Style::RESET_ALL;
                continue;
            }

            cout << "\n" << Fore::BRIGHT_CYAN << Style::BOLD
                 << "  Remove AMD SDK\n" << Style::RESET_ALL;
            cout << Fore::BRIGHT_BLACK << "  Path    : " << Style::RESET_ALL << Fore::LIME << basePath << "\n" << Style::RESET_ALL << "\n";

            cout << Fore::GOLD << Style::BOLD
                 << "  Proceed with delete? [Y/n]: "
                 << Style::RESET_ALL;
            cout.flush();
            string confirm;
            getline(cin, confirm);

            if (!(confirm.empty() || confirm == "Y" || confirm == "y" || confirm == "yes" || confirm == "YES")) {
                cout << Fore::BRIGHT_BLACK << "\n  Cancelled.\n" << Style::RESET_ALL << "\n";
                continue;
            }

            int ret = system(("rmdir /s /q \"" + basePath + "\"").c_str());
            if (ret == 0) {
                cout << "\n" << Back::GREEN << Fore::BLACK << Style::BOLD
                     << " OK  " << Style::RESET_ALL
                     << Fore::BRIGHT_GREEN << "  Remove completed.\n"
                     << Style::RESET_ALL << "\n";
            } else {
                cout << "\n" << Fore::BRIGHT_RED << Style::BOLD
                     << "  [ERROR]  " << Style::RESET_ALL
                     << Fore::RED << "Remove failed (code " << ret << ").\n"
                     << Style::RESET_ALL << "\n";
            }
        }

        else if (command == "exit") {
            cout << "\n" << Fore::TEAL << Style::BOLD << "  Exiting terminal";
            cout.flush();
            for (int i = 0; i < 6; ++i) { sleep_ms(280); cout << " ."; cout.flush(); }
            cout << Style::RESET_ALL << "\n\n";
            break;
        }

        else if (!command.empty()) {
            cout << Fore::RED << "  Unknown command: " << command
                 << Fore::BRIGHT_BLACK << "  (type help for commands)\n" << Style::RESET_ALL;
        }
    }

    return 0;
}
