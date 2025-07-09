# C++ Web Hex Viewer ✨

**Live Demo:** [https://dhruvdesai793.github.io/Hex-Viewr-cpp/](https://dhruvdesai793.github.io/Hex-Viewr-cpp/) 🚀

A simple yet powerful web-based hexadecimal viewer, forged by compiling C++ to WebAssembly. This tool lets you peek into the binary soul of files or text, right from your browser! 🕵️‍♂️💻

## Features 🌟

* **File Upload:** Convert any binary file (e.g., `.bin`, `.txt`, `.rom`) to its hex and ASCII glory. 📁➡️🔢
* **Direct Text Input:** Type or paste text to instantly see its hex/ASCII representation. ✍️➡️📊
* **Dynamic Output:** Get instant info on file name and size, with beautifully formatted hex/ASCII. 🏷️📏
* **Search Functionality:** Hunt down specific hex bytes or ASCII text within the displayed data. 🔍
* **Output Controls:** Clear the screen, copy output to clipboard, or download it as a text file. 🗑️📋⬇️
* **Dark Mode Toggle:** Give your eyes a break with a sleek dark theme. 🌙➡️☀️
* **Responsive Design:** Looks great on any device, big or small. 📱🖥️

## My Journey: A WebAssembly Adventure! 🎢

This project began as a quest to truly grasp WebAssembly and bridge my love for low-level C++ with the dynamic world of web apps. What started as a humble command-line tool blossomed into this interactive web viewer, pushing my limits in C++ compilation, Emscripten wizardry, and JavaScript magic. 🧙‍♂️

The path wasn't always smooth! I battled relentless "command not found" errors, chased elusive "undefined symbols," and tamed tricky "MIME type" conflicts. Each bug felt like a boss battle, demanding meticulous attention to compiler flags, environment setups, and the intricate dance of JavaScript module loading. It was a challenging, yet incredibly rewarding odyssey, turning frustration into the pure joy of seeing C++ code run flawlessly in a web browser. This adventure has laid a rock-solid foundation for future, even bolder projects... like a Game Boy emulator! 🎮✨

## Tech Stack 🛠️

* **Frontend:** HTML, CSS, JavaScript 🌐
* **Backend (Compilation):** C++ 🚀
* **WebAssembly Toolchain:** Emscripten SDK (`emcc`) 🔗
* **Version Control:** Git, GitHub Pages 🐙

## Local Setup & Run Instructions ⚙️

Want to run this viewer on your own machine? Here's how!

### Prerequisites ✅

* **Git:** For cloning this awesome repo.
* **Emscripten SDK (emsdk):** The magic wand for C++ to WebAssembly compilation.
    * **Installation:** Best to follow the official `emsdk` instructions. Clone the repo and use its scripts:
        ```bash
        git clone [https://github.com/emscripten-core/emsdk.git](https://github.com/emscripten-core/emsdk.git) ~/emsdk
        cd ~/emsdk
        ./emsdk install latest
        ./emsdk activate latest
        ```
* **Python 3:** For a quick local web server. 🐍

### Steps 🪜

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/dhruvdesai793/Hex-Viewr-cpp.git](https://github.com/dhruvdesai793/Hex-Viewr-cpp.git)
    cd Hex-Viewr-cpp
    ```

2.  **Activate Emscripten environment:**
    Crucial for *every new terminal session* where you'll compile or work with Emscripten:
    ```bash
    source ~/emsdk/emsdk_env.sh
    ```
    (Adjust path if `emsdk` lives elsewhere).

3.  **Compile C++ to WebAssembly:**
    This command tells `emcc` to transform `main_web.cpp` into the web-ready `hex_viewer_web.js` (JavaScript glue) and `hex_viewer_web.wasm` (the binary magic!).
    ```bash
    make clean
    make
    ```
    * _Troubleshooting Tip:_ If `emcc: command not found` appears, re-check step 2 in your current terminal. If `undefined exported symbol` pops up, double-check your `Makefile`'s `EXPORTED_FUNCTIONS` flag.

4.  **Run a local web server:**
    From the project root (`Hex-Viewr-cpp`), fire up a simple Python HTTP server. This ensures your browser loads all files correctly.
    ```bash
    python3 -m http.server 8000
    ```

5.  **Open in browser:**
    Navigate your web browser to:
    ```
    http://localhost:8000/index.html
    ```
    Voila! Your C++ Web Hex Viewer should now be running locally! 🎉

## Contributing 🤝

Got ideas? Found a bug? Feel free to fork, open issues, or send pull requests!

## License 📄

This project is open-source and available under the [MIT License](LICENSE).
