## step 1:
linux: ```sudo apt install cmake```

windows: https://cmake.org/download/ (Windows x64 Installer)

## step 2: projekt erstellen

linux: ```cmake -S . -B build```
```cmake --build build```
```./build/Bank```
OR
```./run.sh```

Windows: 
1. terminal im ordner des projekts oeffnen
2.  VISUAL STUDIO:  ```cmake -G "Visual Studio 17 2022" -A x64```
                    dann die generierte .sln datei oeffnen.

    VSCODE (MinGW): 1. ordner namens build erstellen 
                    2. ```cd build```
                    3. ```cmake .. -G "MinGW Makefiles"```
                    4. ```mingw32-make.exe```
                    5. ```Bank.exe```



