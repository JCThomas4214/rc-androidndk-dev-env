//=============================================================
// templateProject.h
//=============================================================
#ifndef TEMPLATEPROJECT_H
#define TEMPLATEPROJECT_H

#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

#include <stdio.h>

#if defined RELEASE || defined DEBUG
    // #define replace(a, b, c, d) a##b##c##d
    #define init(argc, argv) main(argc, argv)
#endif

int init(int argc, char** argv);

#endif // TEMPLATEPROJECT_H