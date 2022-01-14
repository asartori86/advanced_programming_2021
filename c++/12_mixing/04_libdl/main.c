#include <dlfcn.h>

int main(int argc, char* argv[]) {
  void* handle; /* handle for dynamic object */
  handle = dlopen("./libhello.so", RTLD_LAZY);

  /* function pointers */
  void (*hi)();
  int (*rep)(char*);

  if (handle) {
    /* hi = (void (*)())dlsym(handle, "hello"); */
    hi = dlsym(handle, "hello");
    (*hi)();
    /* rep = (int (*)(char*))dlsym(handle, "repeat"); */
    rep = dlsym(handle, "repeat");
    rep("I dont't care what fox says");
    dlclose(handle);
  }
  return 0;
}
