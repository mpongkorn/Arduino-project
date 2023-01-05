#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg1;
struct can_frame canMsg2;
struct can_frame canMsg_read;
MCP2515 mcp2515(10);

/// can write data
void setup() {
  canMsg1.can_id  = 0x0F6;
  canMsg1.can_dlc = 8;
  canMsg1.data[0] = 0x8E;
  canMsg1.data[1] = 0x87;
  canMsg1.data[2] = 0x32;
  canMsg1.data[3] = 0xFA;
  canMsg1.data[4] = 0x26;
  canMsg1.data[5] = 0x8E;
  canMsg1.data[6] = 0xBE;
  canMsg1.data[7] = 0x86;

  canMsg2.can_id  = 0x036;
  canMsg2.can_dlc = 8;
  canMsg2.data[0] = 0x0E;
  canMsg2.data[1] = 0x00;
  canMsg2.data[2] = 0x00;
  canMsg2.data[3] = 0x08;
  canMsg2.data[4] = 0x01;
  canMsg2.data[5] = 0x00;
  canMsg2.data[6] = 0x00;
  canMsg2.data[7] = 0xA0;
  
  while (!Serial);
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();
  
  //Serial.println("Example: Write to CAN");
  Serial.println("------- CAN Read ----------");
  Serial.println("ID  DLC   DATA");
}

void loop() {
  mcp2515.sendMessage(&canMsg1);
  mcp2515.sendMessage(&canMsg2);
  Serial.println("Messages sent!");
  
  /// -------------can read data-------------------------

  for (int i = 0; i<2; i++)  {
  if (mcp2515.readMessage(&canMsg_read) == MCP2515::ERROR_OK) {
    Serial.print(canMsg_read.can_id, HEX); // print ID
    Serial.print(" "); 
    Serial.print(canMsg_read.can_dlc, HEX); // print DLC
    Serial.print(" ");
    
    for (int i = 0; i<canMsg_read.can_dlc; i++)  {  // print the data
      Serial.print(canMsg_read.data[i],HEX);
      Serial.print(" ");
 }
 Serial.println(" ");
 }
 }

  delay(100);
  
}


  
