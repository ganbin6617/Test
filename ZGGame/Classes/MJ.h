//
//  MJ.h
//  ZGGame
//
//  Created by Thesy on 16/3/8.
//
//

#ifndef __ZGGame__MJ__
#define __ZGGame__MJ__

#include <stdio.h>
using namespace std;

typedef enum{
    MJType_Wan,
    MJType_Tiao,
    MJType_Tong,
    MJType_Feng
}MJType;

class MJ
{
public:
    string *name;
    MJType  type;
    
};

#endif /* defined(__ZGGame__MJ__) */
