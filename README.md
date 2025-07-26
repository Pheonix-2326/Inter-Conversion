# 🧮 Inter-Conversion Calculator

A simple **console-based C++ application** that converts numbers between **Binary**, **Decimal**, **Hexadecimal**, and **Octal** formats. Designed without a GUI, this program offers a clean and efficient way to explore number systems and their interrelationships.


## ✨ Features

- 🔄 Convert between Binary, Decimal, Hexadecimal, and Octal
- ✅ Input in one format → Output in all other formats
- 🧩 Modular and well-commented C++ code
- 🧑‍🎓 Great for students, educators, or anyone learning number systems

## 📚 Use Cases

🔹 Understand and visualize number system conversions

🔹 Practice modular C++ programming

🔹 Use in CS education, coding practice, or micro-utilities


## 🛠 Technologies

Language: C++

Environment: Command Line Interface (CLI)

Compiler: g++ / Visual Studio C++

---

## 📌 Requirements

To compile and run this program, you’ll need:

- **C++17 compatible compiler**
  - Windows: [MinGW](https://www.mingw-w64.org/), MSVC (Visual Studio)
  - Linux/macOS: g++ or clang
- (Optional) **Visual Studio Code** with:
  - C/C++ extension by Microsoft
  - Code Runner extension (optional but useful)

---

```
## 📁 Folder Structure
inter-conversion-calculator/
│
├── BIN_to_DEC.cpp
├── BIN_to_HEX.cpp
├── BIN_to_OCT.cpp
│
├── DEC_to_BIN.cpp
├── DEC_to_HEX.cpp
├── DEC_to_OCT.cpp
│
├── HEX_to_BIN.cpp
├── HEX_to_DEC.cpp
├── HEX_to_OCT.cpp
│
├── OCT_to_BIN.cpp
├── OCT_to_DEC.cpp
├── OCT_to_HEX.cpp
│
├── connector.h
├── INTER_CO.cpp
│
├── .vscode/
│   ├── tasks.json
│   ├── launch.json
│   └── settings.json
│
├── README.md
└── LICENSE
```

## 🚀 How to Run

### 🖥️ Option 1: Use the Precompiled Executable (Windows Only)

1. Open **Command Prompt** or **VS Code terminal**
2. Navigate to the project directory
3. Compile all files together:
   ```bash
   g++ *.cpp -o INTER_CO.exe
   ```
4. Run the executable:
   ```bash
   INTER_CO.exe
   ```

---

### 🧩 Option 2: Compile from VS Code Using tasks.json

To support compiling multiple `.cpp` files in VS Code:

1. Create a folder named `.vscode` inside the same folder where all `.cpp` files are located.
2. Inside `.vscode`, create or edit the `tasks.json` file.
3. In the `args` section, change this:
   ```json
   "${file}"
   ```
   to:
   ```json
   "${fileDirname}/*.cpp"
   ```

4. Your `args` section should look like:
   ```json
   "args": [
     "-fdiagnostics-color=always",
     "-g",
     "${fileDirname}/*.cpp",
     "-o",
     "${fileDirname}/${fileBasenameNoExtension}.exe"
   ]
   ```

---

### 📂 JSON Files for VS Code (Pre-Configured)

- Three `.json` files are included in the repository to help configure VS Code easily:
  - `launch.json`
  - `settings.json`
  - `tasks.json`

> 📝 **Important:**
> - If you're facing any issues configuring the `.json` files manually, simply copy the provided `.json` files into a folder named `.vscode`.
> - The `.vscode` folder **must be created inside the same directory** where all your `.cpp` files are located.
> - When the repository is cloned, these `.json` files will appear alongside the `.cpp` files.  
>   You need to manually create the `.vscode` folder and move the `.json` files inside it.

> When using **`tasks.json`** to compile all `.cpp` files in Visual Studio Code:

- ✅ Make sure that **only one `.cpp` file contains the `main()` function**.
- ❌ If **more than one `.cpp` file has a `main()`**, the program **will fail to run or debug**.
- This is because the linker cannot resolve which `main()` to use, resulting in a **multiple definition error**.

> 💡 Tip: Keep your `main()` inside `INTER_CO.cpp` and ensure no other file has it.

> ✅ Once set up, you can press `Ctrl+Shift+B` to build your project directly in VS Code.

---


## 🔗 Contributing / Feedback

Found a bug? Have a suggestion? Feel free to open an issue or submit a pull request!


## ❓ Frequently Asked Questions (FAQ)

### 📌 Q1: Do I need Visual Studio Code to run this project?
**A:** No, it's not mandatory. You can compile and run the `.cpp` files using any C++ compiler like `g++` directly from the command line:
```bash
g++ -o INTER_CO.exe *.cpp
./INTER_CO.exe
```

### 📌 Q2: What is the purpose of connector.h?
**A:** connector.h is a common header file that contains function declarations and shared includes used by multiple .cpp files. It promotes modularity and prevents code duplication.

### 📌 Q3: How can I build all .cpp files at once?
**A:** You can compile all source files at once using:
```bash
g++ *.cpp -o INTER_CO.exe
```
If you're using Visual Studio Code, pressing Ctrl+Shift+B (after setting up .vscode/tasks.json) will build everything automatically.

### 📌 Q4: Where are the output .exe files stored?
**A:** By default, the .exe file (e.g., INTER_CO.exe) will be created in the root project folder. You can modify the output directory in tasks.json to store executables in a subfolder like build/.

### 📌 Q5: I’m on Linux or macOS. Can I still use this project?
**A:** Absolutely! Just change the compile command:
```bash
g++ *.cpp -o INTER_CO
./INTER_CO
```
On Linux/macOS, the executable won't have a .exe extension.


## 🧑‍💻 Author
Dhruv Patel
Pheonix-2326

## 📄 License

This project is licensed under the [MIT License](LICENSE).
