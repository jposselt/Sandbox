#include <iostream>
#include <functional>

#include "hello.h"

void hello()
{
  [out = std::ref(std::cout << "Hello ")](){ out.get() << "World\n"; }();
}