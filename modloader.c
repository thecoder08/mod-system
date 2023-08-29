#include <stdio.h>
#include <dlfcn.h>
#include <dirent.h>
#include <string.h>

int main() {
  printf("Searching for mods...\n");
  DIR* dir = opendir("mods");
  struct dirent *entry;
  if (dir) {
    while ((entry = readdir(dir)) != NULL) {
      // do something with entry name
      char *ext = strrchr(entry->d_name, '.');
      if (ext && !strcmp(ext, ".so")) {
        printf("Found mod: %s\n", entry->d_name);
        char filename[261] = "mods/";
        void* modhandle = dlopen(strcat(filename, entry->d_name), RTLD_LAZY);
        if (!modhandle) {
          printf("Error loading mod: %s\n", dlerror());
          continue;
        }
        void (*initMod)() = dlsym(modhandle, "initMod");
        if (!initMod) {
          printf("Error running mod: %s\n", dlerror());
          continue;
        }
        initMod();
        dlclose(modhandle);
      }
    }
    closedir(dir);
  }
  return 0;
}
