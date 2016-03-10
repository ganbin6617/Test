////
////  other.h
////  ZGGame
////
////  Created by ganbin on 16-3-9.
////
////
//
//#ifndef __ZGGame__other__
//#define __ZGGame__other__
//
//#include <stdio.h>
//
//#endif /* defined(__ZGGame__other__) */
//
//
//#include <iostream>
//
//using namespace std;
//
//#define MAX_REPERTORY 108//144
//typedef unsigned char BYTE;
//typedef unsigned short WORD;
////数组维数
//#ifndef CountArray
//#define CountArray(Array) (sizeof(Array)/sizeof(Array[0]))
//#endif
////逻辑掩码
//
//#define MASK_COLOR                  0xF0                                //花色掩码
//#define MASK_VALUE                  0x0F                                //数值掩码
//#define MAX_INDEX   27//42  //最大索引
//#define MAX_COUNT                   14                                  //最大数目
//
//const BYTE m_cbCardDataArray[MAX_REPERTORY]=
//{
//    0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,                       //万子
//    0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,                       //万子
//    0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,                       //万子
//    0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,                       //万子
//    0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,                       //同子
//    0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,                       //同子
//    0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,                       //同子
//    0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,                       //同子
//    0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,                       //索子
//    0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,                       //索子
//    0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,                       //索子
//    0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,                       //索子
//    
//    //    0x31,0x32,0x33,0x34,                                                //风牌
//    //    0x31,0x32,0x33,0x34,                                                //风牌
//    //    0x31,0x32,0x33,0x34,                                                //风牌
//    //    0x31,0x32,0x33,0x34,                                                //风牌
//    //    0x41,0x42,0x43,                                                     //箭牌
//    //    0x41,0x42,0x43,                                                     //箭牌
//    //    0x41,0x42,0x43,                                                     //箭牌
//    //    0x41,0x42,0x43,                                                     //箭牌
//    //
//    //    0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,                            //花牌
//    
//};
//const char* m_cbCardWordArray[MAX_INDEX]=
//{
//    "一万","二万","三万","四万","五万","六万","七万","八万","九万",
//    "一筒","二筒","三筒","四筒","五筒","六筒","七筒","八筒","九筒",
//    "一索","二索","三索","四索","五索","六索","七索","八索","九索",
//    //    "东", "南", "西", "北", "中", "发", "白",
//    //    "春", "夏", "秋", "冬", "梅", "兰", "竹", "菊"
//};
////混乱扑克
//static void RandCardData(BYTE cbCardData[],BYTE cbMaxCount)
//{
//    //混乱准备
//    BYTE cbCardDataTemp[CountArray(m_cbCardDataArray)];//为什么直接用MAX_REPERTORY? 因为这样无耦合
//    memcpy(cbCardDataTemp,m_cbCardDataArray,sizeof(m_cbCardDataArray));//拷贝一份到临时牌数组中
//    
//    //混乱扑克(关键的核心打乱代码)
//    BYTE cbRandCount=0,cbPosition=0;
//    do
//    {
//        
//        cbPosition=rand()%(cbMaxCount-cbRandCount);
//        cbCardData[cbRandCount++]=cbCardDataTemp[cbPosition];
//        cbCardDataTemp[cbPosition]=cbCardDataTemp[cbMaxCount-cbRandCount];
//    } while (cbRandCount<cbMaxCount);
//    
//    return;
//    
//}
////混乱扑克2
//void RandAppointCardData(BYTE cbCardData[],BYTE cbMaxCount,BYTE OriginalData[]/*源牌堆数据*/)
//{
//    //混乱扑克
//    BYTE cbRandCount=0,cbPosition=0;
//    do
//    {
//        cbPosition=rand()%(cbMaxCount-cbRandCount);
//        cbCardData[cbRandCount++]=OriginalData[cbPosition];
//        OriginalData[cbPosition]=OriginalData[cbMaxCount-cbRandCount];
//    } while (cbRandCount<cbMaxCount);
//    
//    return;
//}
////扑克转换(索引->牌值)
//BYTE SwitchToCardData(BYTE cbCardIndex)
//{
//    //assert(cbCardIndex<42);
//    if(cbCardIndex<31)   return ((cbCardIndex/9)<<4)|(cbCardIndex%9+1);
//    if(cbCardIndex>=31&&cbCardIndex<=33)  return(((cbCardIndex/7)<<4)+cbCardIndex%10 );
//    if(cbCardIndex>33)   return(cbCardIndex+0x2F);
//    //assert(false);
//    return 0;
//}
////扑克转换(牌型->索引)
//BYTE SwitchToCardIndex(BYTE cbCardData)
//{
//    //  ASSERT(IsValidCard(cbCardData));
//    if((cbCardData&MASK_COLOR)<=0x30)
//        return (((cbCardData&MASK_COLOR)>>4)*9+(cbCardData&MASK_VALUE)-1);
//    if((cbCardData&MASK_COLOR)==0x40)
//        return (31+(cbCardData&MASK_VALUE)-1);
//    if((cbCardData&MASK_COLOR)==0x50)
//        return (34+(cbCardData&MASK_VALUE)-1);
//    //ASSERT(false);
//    return 0;
//}
//
////扑克转换
//BYTE SwitchToCardData(BYTE cbCardIndex[MAX_INDEX]/*传入统计所有牌数量的表格*/, BYTE cbCardData[MAX_COUNT]/*传出手牌数据*/)
//{
//    //转换扑克
//    BYTE cbPosition=0;
//    for (BYTE i=0;i<MAX_INDEX;i++)
//    {
//        if (cbCardIndex[i]!=0)
//        {
//            for (BYTE j=0;j<cbCardIndex[i];j++)
//            {
//                // ASSERT(cbPosition<MAX_COUNT);
//                cbCardData[cbPosition++]=SwitchToCardData(i);
//            }
//        }
//    }
//    
//    return cbPosition;//返回手牌数
//}
////根据中文牌,得到牌索引
//int getIndexByWord(const char* ch)
//{
//    for (int i = 0; i < MAX_INDEX; i++)
//    {
//        if (!strcmp(ch,m_cbCardWordArray[i]))
//        {
//            return i;
//        }
//    }
//    return -1;
//}
////删除扑克
//bool RemoveCard(BYTE cbCardIndex[MAX_INDEX], BYTE cbRemoveCard)
//{
//    
//    //效验扑克
//    //ASSERT(IsValidCard(cbRemoveCard));
//    BYTE cbRemoveIndex=SwitchToCardIndex(cbRemoveCard);
//    //ASSERT(cbCardIndex[cbRemoveIndex]>0);
//    
//    //删除扑克
//    if (cbCardIndex[cbRemoveIndex]>0)
//    {
//        cbCardIndex[cbRemoveIndex]--;
//        return true;
//    }
//    
//    //失败效验
//    // ASSERT(FALSE);
//    
//    return false;
//}
//
//int main(int argc, const char * argv[])
//{
//    // insert code here...
//    srand((unsigned)time(NULL));
//    /*第一种混乱发*/
//    //创建一个空牌堆
//    BYTE _cardData1[MAX_REPERTORY];
//    //把在该函数中创建并打乱牌堆,然后把指针传给_cardData;
//    RandCardData(_cardData1, MAX_REPERTORY);
//    //输出牌数据
//    cout<<"混乱初始牌堆"<<endl;
//    for (int i = 0 ; i < MAX_REPERTORY; i++)
//    {
//        cout<<hex<<"0x"<<int(_cardData1[i])<<" ";
//    }
//    cout<<endl;
//    cout<<endl;
//    
//    /*第二种混乱发*/
//    //创建一个空牌堆
//    BYTE _cardData2[MAX_REPERTORY];
//    //把在该函数中创建并打乱牌堆,然后把指针传给_cardData;
//    RandAppointCardData(_cardData2, MAX_REPERTORY,_cardData1);
//    //输出牌数据
//    cout<<"混乱指定牌堆"<<endl;
//    for (int i = 0 ; i < MAX_REPERTORY; i++)
//    {
//        cout<<"0x"<<int(_cardData2[i])<<" ";
//    }
//    cout<<endl;
//    cout<<endl;
//    
//    /*添加手牌*/
//    //虚拟一副手牌 开始游戏时,每人13张手牌,然后庄家再摸一张牌即14张
//    //我们使用上面初始化好的牌堆,进行摸牌,假设只有一个玩家
//    BYTE cbCardIndex[MAX_INDEX];
//    for (int i = 0; i < MAX_COUNT; i++)
//    {
//        BYTE _cardValue = _cardData2[i];//得到牌堆中的牌
//        int _index = SwitchToCardIndex(_cardValue);//得到该牌对应的索引
//        cbCardIndex[_index]++;//该牌型加一
//    }
//    
//    cout<<"输出所有牌型对应的数量"<<endl;
//    for (int i = 0; i< MAX_INDEX; i++)
//    {
//        cout<<hex<<m_cbCardWordArray[i]<<"(0x"<<int(SwitchToCardData(i))<<"):"<<dec<<(int)cbCardIndex[i]<<" ";//输出手牌中所有牌型对应的数量
//    }
//    cout<<endl;
//    cout<<endl;
//    
//    cout<<"输出手牌数据"<<endl;
//    BYTE cbCardData[MAX_COUNT];
//    int _handsCount = (int)SwitchToCardData(cbCardIndex,cbCardData);
//    cout<<"手牌数量为:"<<_handsCount<<endl;
//    for (int i = 0 ; i < MAX_COUNT; i++)
//    {
//        cout<<m_cbCardWordArray[SwitchToCardIndex(cbCardData[i])]<<"(0x"<<hex<<(int)cbCardData[i]<<") ";
//    }
//    
//    cout<<endl;
//    cout<<endl;
//    
//    /*出牌*/
//    char ch[20];
//    cout<<"输入要出的牌(比如 三万): ";
//    cin>>ch;
//    int _outCardIndex = getIndexByWord(ch);
//    if (_outCardIndex == -1)
//    {
//        cout<<"输入错误"<<endl;
//        return 0;
//    }
//    BYTE _outCardValue = SwitchToCardData(_outCardIndex);
//    bool _b = RemoveCard(cbCardIndex, _outCardValue);
//    if (_b)
//    {
//        cout<<"出牌成功"<<endl;
//    }
//    else
//    {
//        cout<<"该牌不存在"<<endl;
//    }
//    BYTE _leftCardData[MAX_COUNT];
//    int _leftHandsCount = (int)SwitchToCardData(cbCardIndex,_leftCardData);
//    cout<<"手牌数量为:"<<dec<<_leftHandsCount<<endl;
//    cout<<"手牌数据为:"<<endl;
//    for (int i = 0 ; i < _leftHandsCount; i++)
//    {
//        cout<<m_cbCardWordArray[SwitchToCardIndex(_leftCardData[i])]<<"(0x"<<hex<<(int)_leftCardData[i]<<") ";
//    }
//    
//    cout<<endl<<endl;
//    return 0;
//}
