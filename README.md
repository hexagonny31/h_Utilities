# Hexagonny's Utilities
A lightweight, standalone utility built entirely in C++ with zero external dependencies — only requiring a C++ compiler to build and run. No third-party libraries, just pure C++ code. Made for simplicity and portability, the project relies solely on the C++ standard library without any additional frameworks or libraries.

***

## Requirements
* **Operating System:** The program is designed to run on Windows, Linux, or macOS, as long as the system supports C++17 or later.

* **C++ Compiler:** A C++17-compatible compiler such as GCC, Clang, or MSVC is required to compile and run the code.

* **UTF-8 & ANSI Codes Support:** These two requirements are necessary for the proper display of graphical bars (like █, ▓, ▒, or ▀) and colored text in the console.

> Note: Some older CMD versions do not fully support ANSI colors without a third-party emulator like ConEmu or Cmder.

***

## Enabling UTF-8
By default, Windows CMD uses Code Page 437, which does not support special characters like Unicode symbols. To enable UTF-8:

### Temporary Method
Run this command inside CMD before executing your program.
```
chcp 65001
```

### Permanent Method
#### Option 1: Registry Edit
1. Open Run (Win + R), type regedit, and press Enter.
2. Navigate to:
```
HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Nls\CodePage
```
4. Find OEMCP, double-click it, and change its value to:
```
65001
```
5. Restart your computer.

#### Option 2: Windows Settings (Windows 10/11)
1. Open Settings → Time & Language → Language & Region.
2. Scroll down and click Administrative language settings.
3. In the new window, go to Change system locale.
4. Check Beta: Use Unicode UTF-8 for worldwide language support.
5. Restart your computer.

***

## Enabling ANSI 256 Colors in CMD

### Enable Virtual Terminal Processing
Run this command in CMD:
```
reg add HKEY_CURRENT_USER\Console /v VirtualTerminalLevel /t REG_DWORD /d 1 /f
```
* This enables ANSI escape sequences in CMD.
* Restart CMD after executing this command.
### Using ANSI 256 Colors in CMD
After enabling ANSI support, you can use ANSI escape sequences in your C++ program:
```
std::cout << "\033[38;5;124m Red Text \033[0m\n"; // Foreground color (Red)
std::cout << "\033[48;5;46m Green Background \033[0m\n"; // Background color (Green)
```

***

### Verifying UTF-8 and ANSI Support
After setting up:
* Check UTF-8:
  ```
  chcp
  ```
  * If it returns 65001, UTF-8 is enabled.
* Check ANSI Colors:
  Try running this C++ snippet:
  ```
  #include <iostream>

  int main() {
      std::cout << "\033[38;5;124mRed Text\033[0m" << std::endl;
      std::cout << "\033[48;5;46mGreen Background\033[0m" << std::endl;
      return 0;
  }
  ```
  If you see colored text, ANSI colors are working.

***

## Final Notes
* Windows Terminal (from Microsoft Store) has built-in UTF-8 and ANSI support.
* Always test your settings with chcp and ANSI color codes before running your program.
