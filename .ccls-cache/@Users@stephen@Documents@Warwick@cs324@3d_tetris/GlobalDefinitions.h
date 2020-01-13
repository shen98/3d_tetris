#ifndef _GLOBAL_DEFINITIONS_H_
#define _GLOBAL_DEFINITIONS_H_


#define PI 3.141592654
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif

#include <cstdlib>
#include <iostream>
#include <vector>
#endif
