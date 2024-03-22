#ifndef _TSUPER_H_
#define _TSUPER_H_

#include "tProd.h"

typedef struct tSuper tSuper;

tSuper* CriaSuper(char* nome, tProd** prod, int nprod);

void DesalocaSuper(tSuper* s);

void ImprimeSuper(tSuper* s);

#endif