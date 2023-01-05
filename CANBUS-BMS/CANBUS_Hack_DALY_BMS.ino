
#include <SPI.h>
#include "mcp2515_can.h"


// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 9;

mcp2515_can CAN(SPI_CS_PIN);                               // Set CS pin


unsigned char flagRecv = 0;
unsigned char len = 0;
unsigned char buf[8];
char str[20];

void setup()
{
    Serial.begin(115200);

    while (CAN_OK != CAN.begin(CAN_250KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");

    attachInterrupt(0, MCP2515_ISR, FALLING); // start interrupt


    /*
     * set mask, set both the mask to 0x3ff
     */
    CAN.init_Mask(0, 1, 0x3ff);                         // there are 2 mask in mcp2515, you need to set both of them
    CAN.init_Mask(1, 1, 0x3ff);


    /*
     * set filter, we can receive id from 0x04 ~ 0x09
     */
    CAN.init_Filt(0, 1, 0x18900140);                          // there are 6 filter in mcp2515
//    CAN.init_Filt(1, 1, 0x18914001);                          // there are 6 filter in mcp2515
//    CAN.init_Filt(2, 1, 0x18924001);                          // there are 6 filter in mcp2515
//    CAN.init_Filt(3, 1, 0x18954001);                          // there are 6 filter in mcp2515
    //CAN.init_Filt(4, 1, 0x05);                          // there are 6 filter in mcp2515
    //CAN.init_Filt(5, 1, 0x06);                          // there are 6 filter in mcp2515

}

void MCP2515_ISR()
{
    flagRecv = 1;
}

void loop()
{
    unsigned char stmp [8] = {00, 00, 00, 00, 00, 00, 00, 00};
    //CAN_ID [5] = {0x18900140, 0x18910140, 0x18920140, 0x18930140, 0x18940140};
    CAN.sendMsgBuf(0x18900140, 0, 8, 1, stmp);
    Serial.println("Send message 90 ok!");
    delay(100);                       // send data per 100ms
    if(flagRecv)                   // check if get data
    {
        flagRecv = 0;                // clear flag
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
        
        //Serial.println("\r\n------------------------------------------------------------------");
        //Serial.print("Get Data From id: ");
          Serial.print("0x");
          Serial.print(CAN.getCanId(), HEX);
          Serial.print(" ");
        for(int i = 0; i<len; i++)    // print the data
        {
            if( buf[i]<16){
            Serial.print("0");
            Serial.print(buf[i], HEX);
            Serial.print(" ");
            }
            else{
            Serial.print(buf[i], HEX);
            Serial.print(" ");}
        }
        Serial.println();
    }
    //-----------------------------------------//
//        CAN.sendMsgBuf(0x18910140, 1, 8, 1, stmp);
//        Serial.println("Send message 91 ok!");
//        delay(100);                       // send data per 100ms
//        if(flagRecv)                   // check if get data
//    {
//        flagRecv = 0;                // clear flag
//        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
//
//        //Serial.println("\r\n------------------------------------------------------------------");
//        //Serial.print("Get Data From id: ");
//          Serial.print("0x");
//          Serial.print(CAN.getCanId(), HEX);
//          Serial.print(" ");
//        for(int i = 0; i<len; i++)    // print the data
//        {
//            if( buf[i]<16){
//            Serial.print("0");
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");
//            }
//            else{
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");}
//        }
//        Serial.println();
//    } 
//        //-----------------------------------------//
//        CAN.sendMsgBuf(0x18920140, 1, 8, 1, stmp);
//        Serial.println("Send message 92 ok!");
//        delay(100);                       // send data per 100ms
//        if(flagRecv)                   // check if get data
//    {
//        flagRecv = 0;                // clear flag
//        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
//
//        //Serial.println("\r\n------------------------------------------------------------------");
//        //Serial.print("Get Data From id: ");
//          Serial.print("0x");
//          Serial.print(CAN.getCanId(), HEX);
//          Serial.print(" ");
//        for(int i = 0; i<len; i++)    // print the data
//        {
//            if( buf[i]<16){
//            Serial.print("0");
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");
//            }
//            else{
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");}
//        }
//        Serial.println();
//    } 
//        //-----------------------------------------//
//        CAN.sendMsgBuf(0x18930140, 1, 8, 1, stmp);
//        Serial.println("Send message 93 ok!");
//        delay(100);                       // send data per 100ms
//        if(flagRecv)                   // check if get data
//    {
//        flagRecv = 0;                // clear flag
//        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
//
//        //Serial.println("\r\n------------------------------------------------------------------");
//        //Serial.print("Get Data From id: ");
//          Serial.print("0x");
//          Serial.print(CAN.getCanId(), HEX);
//          Serial.print(" ");
//        for(int i = 0; i<len; i++)    // print the data
//        {
//            if( buf[i]<16){
//            Serial.print("0");
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");
//            }
//            else{
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");}
//        }
//        Serial.println();
//    } 
//    //-----------------------------------------//
//        CAN.sendMsgBuf(0x18940140, 1, 8, 1, stmp);
//        Serial.println("Send message 94 ok!");
//        delay(100);                       // send data per 100ms
//        if(flagRecv)                   // check if get data
//    {
//        flagRecv = 0;                // clear flag
//        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
//
//        //Serial.println("\r\n------------------------------------------------------------------");
//        //Serial.print("Get Data From id: ");
//          Serial.print("0x");
//          Serial.print(CAN.getCanId(), HEX);
//          Serial.print(" ");
//        for(int i = 0; i<len; i++)    // print the data
//        {
//            if( buf[i]<16){
//            Serial.print("0");
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");
//            }
//            else{
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");}
//        }
//        Serial.println();
//    } 
//    //-----------------------------------------//
//        CAN.sendMsgBuf(0x18960140, 1, 8, 1, stmp);
//        Serial.println("Send message 96 ok!");
//        delay(100);                       // send data per 100ms
//        if(flagRecv)                   // check if get data
//    {
//        flagRecv = 0;                // clear flag
//        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
//
//        //Serial.println("\r\n------------------------------------------------------------------");
//        //Serial.print("Get Data From id: ");
//          Serial.print("0x");
//          Serial.print(CAN.getCanId(), HEX);
//          Serial.print(" ");
//        for(int i = 0; i<len; i++)    // print the data
//        {
//            if( buf[i]<16){
//            Serial.print("0");
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");
//            }
//            else{
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");}
//        }
//        Serial.println();
//    } 
//    //-----------------------------------------//
//        CAN.sendMsgBuf(0x18970140, 1, 8, 1, stmp);
//        Serial.println("Send message 97 ok!");
//        delay(100);                       // send data per 100ms
//        if(flagRecv)                   // check if get data
//    {
//        flagRecv = 0;                // clear flag
//        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
//
//        //Serial.println("\r\n------------------------------------------------------------------");
//        //Serial.print("Get Data From id: ");
//          Serial.print("0x");
//          Serial.print(CAN.getCanId(), HEX);
//          Serial.print(" ");
//        for(int i = 0; i<len; i++)    // print the data
//        {
//            if( buf[i]<16){
//            Serial.print("0");
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");
//            }
//            else{
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");}
//        }
//        Serial.println();
//    } 
//    //-----------------------------------------//
//        CAN.sendMsgBuf(0x18980140, 1, 8, 1, stmp);
//        Serial.println("Send message 98 ok!");
//        delay(100);                       // send data per 100ms
//        if(flagRecv)                   // check if get data
//    {
//        flagRecv = 0;                // clear flag
//        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
//
//        //Serial.println("\r\n------------------------------------------------------------------");
//        //Serial.print("Get Data From id: ");
//          Serial.print("0x");
//          Serial.print(CAN.getCanId(), HEX);
//          Serial.print(" ");
//        for(int i = 0; i<len; i++)    // print the data
//        {
//            if( buf[i]<16){
//            Serial.print("0");
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");
//            }
//            else{
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");}
//        }
//        Serial.println();
//    } 
//     //-----------------------------------------//
//        CAN.sendMsgBuf(0x18950140, 1, 8, 1, stmp);
//        Serial.println("Send message 95 ok!");
//        delay(30);                       // send data per 100ms
//        if(flagRecv)                   // check if get data
//    {
//        for(int p = 0; p<3; p++)
//        { 
//        flagRecv = 0;                // clear flag
//        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
//
//        //Serial.println("\r\n------------------------------------------------------------------");
//        //Serial.print("Get Data From id: ");
//          Serial.print("0x");
//          Serial.print(CAN.getCanId(), HEX);
//          Serial.print(" ");
//        for(int i = 0; i<len; i++)    // print the data
//        {
//            if( buf[i]<16){
//            Serial.print("0");
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");
//            }
//            else{
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");}
//        }
//        Serial.println();
//    } }
//     //-----------------------------------------//
//        CAN.sendMsgBuf(0x18D80140, 1, 8, 1, stmp);
//        delay(100);                       // send data per 100ms
//        if(flagRecv)                   // check if get data
//    {
//        flagRecv = 0;                // clear flag
//        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
//
//        //Serial.println("\r\n------------------------------------------------------------------");
//        //Serial.print("Get Data From id: ");
//          Serial.print("0x");
//          Serial.print(CAN.getCanId(), HEX);
//          Serial.print(" ");
//        for(int i = 0; i<len; i++)    // print the data
//        {
//            if( buf[i]<16){
//            Serial.print("0");
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");
//            }
//            else{
//            Serial.print(buf[i], HEX);
//            Serial.print(" ");}
//        }
//        Serial.println();
//    } 
}


/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
