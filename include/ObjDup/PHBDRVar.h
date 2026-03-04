//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _PHBDRVar_H_
#define _PHBDRVar_H_

#include <ObjDup/ObjDupDecl.h>

class PHBDRVarRoot {
};

#include <ObjDup/PHBDRTemplate_double.h>
#include <ObjDup/_PHBDRVar.h>

#include <ObjDup/PHBDRTemplate_float.h>
#include <ObjDup/_PHBDRVar.h>

#include <ObjDup/PHBDRTemplate_int.h>
#include <ObjDup/_PHBDRVar.h>

#define PHBDRVAR(type) PHBDRVar_##type

#ifdef _TEST_ENABLED
bool PHBDRTest();
#endif

#endif
