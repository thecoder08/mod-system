# Mod system
This is a demonstrative mod system written in C. You can compile it as follows:
```bash
gcc modloader.c -o modloader
cd mods
gcc -shared mod.c -o mod.so
gcc -shared error.c -o error.so
gcc -shared runnable.c /usr/lib/x86_64-linux-gnu/Scrt1.o -o runnable.so
cd ..
```
You can then run it as follows:
```bash
./modloader
```
This will search the `mods` folder for all files ending in `.so`, load them, and execute the `initMod` function in each.

The script will error out if the mod is not an ELF shared library, or if the `initMod` function doesn't exist.

The expected output is as follows:
```
Searching for mods...
Found mod: runnable.so
The mod was ran from the loader in this case.
Found mod: error.so
Error running mod: mods/error.so: undefined symbol: initMod
Found mod: mod.so
The mod was ran!
```
The script fails to execute `error.so` because `initMod` is misspelt as `initmod`. It then skips this mod. The `runnable.so` mod is special because it is possible to run it directly by typing `mods/runnable.so`.

You are free to use this code in your own projects.

Make sure that you run the `modloader` program from the parent directory, not the `mods` directory.