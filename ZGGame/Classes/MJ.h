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

//类型
typedef enum{
    MJType_Wan,
    MJType_Tiao,
    MJType_Tong,
    MJType_Feng
}MJType;

class MJ
{
public:
    MJ init(MJType,int);    //初始化
    MJType getMJType();     //获取类型
    int getNUM();           //获取NUM

private:
    string *name;
    MJType  type;
    int      NUM;
    
    
};

#endif /* defined(__ZGGame__MJ__) */
