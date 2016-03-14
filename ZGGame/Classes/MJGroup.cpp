//
//  MJGroup.cpp
//  ZGGame
//
//  Created by ganbin on 16-3-8.
//
//

#include "MJGroup.h"


MJGroup *MJGroup::create_BJ()
{
    MJGroup *pRet = MJGroup::create();
    pRet->init_BJ();
    return pRet;
}

bool MJGroup::init_BJ()
{
//    if (mjList!= NULL) {
//        mjList->removeAllObjects();
//    }
//    else
    {
       setMjList(__Array::create());
    }
    addType(MJType_Wang);
    addType(MJType_Tiao);
    addType(MJType_Tong);
    return this;
}

#pragma mark - 外部方法

void MJGroup::wash()
{
    __Array *tempList = __Array::create();
    tempList->addObjectsFromArray(mjList);

    srand((unsigned)time(NULL));
    
    size_t max = tempList->count();
    int randCount=0, pos =0;
    do
    {
        randCount=rand()%(max-pos);
        mjList->setObject(tempList->getObjectAtIndex(randCount), pos);
        pos++;
        tempList->setObject(tempList->getObjectAtIndex(max-pos), randCount);
    } while (pos<max);
    
    show(mjList);
    
}


#pragma mark - 内部方法

void MJGroup::addType(MJType type)
{
    for (int i = 0; i<4; i++) {
        for (int j = 0; j<(type==MJType_Feng?7:9); j++) {
            MJ *mj = MJ::create(type, j);
            this->mjList->addObject(mj);
        }
    }
}

#pragma mark - ＋


//显示
void MJGroup::show(__Array *array)
{
    cout<<"-----";
    for (int i = 0; i<array->count(); i++) {
        MJ *mj = (MJ*)(array->getObjectAtIndex(i));
        
        CCLOG("%s",mj->getName()->getCString());
    }
    cout<<"-------------";
}

//显示
void MJGroup::showm(MJ *mj)
{
    CCLOG("%s",mj->getName()->getCString());
}

//整理
void MJGroup::sort(__Array *arr)
{
    int low = 0;
    int n = (int)arr->count();
    int high = n-1;
    int j;
    while (low<high) {
        for (j= low; j< high; ++j) {//正向冒泡,找到最大者
            MJ *mj1 = (MJ*)arr->getObjectAtIndex(j);
            MJ *mj2 = (MJ*)arr->getObjectAtIndex(j+1);
            
            if (mj1->tnum > mj2->tnum) {
                arr->exchangeObjectAtIndex(j, j+1);
            }
        }
        --high;
        //修改high值, 前移一位
        for ( j=high; j>low; --j) {//反向冒泡,找到最小者
            MJ *mj1 = (MJ*)arr->getObjectAtIndex(j);
            MJ *mj2 = (MJ*)arr->getObjectAtIndex(j-1);
            if (mj1->tnum < mj2->tnum) {
                arr->exchangeObjectAtIndex(j, j-1);
            }
        }
        ++low;                  //修改low值,后移一位
    }
}

#pragma mark - 

//分割
__Array *MJGroup::sqlit(__Array *array)
{
    __Array *temp = __Array::create();
    
    Ref *obj = NULL;
    CCARRAY_FOREACH(array, obj)
    {
        MJ *mj = static_cast<MJ*>(obj);
        
        
    }
    
}
