// CAN Send Example
//

#include <mcp_can.h>
#include <SPI.h>

MCP_CAN CAN0(10);     // Set CS to pin 10

void setup()
{
  Serial.begin(115200);

  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) Serial.println("MCP2515 Initialized Successfully!");
  else Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
}


void loop()
{
  int sensorValue = analogRead(A0) * 5.0 / 1023.0;  // Convert analog value to voltage
  float sensorValue1 = analogRead(A0) * 5.0 / 1023.0;
  int tt =(sensorValue1-sensorValue)*100; 
  data{2 = 
  byte data[1] = {sensorValue};
  byte data[2] = {tt};
  byte sndStat = CAN0.sendMsgBuf(0x100, 0, 2, data);
  if(sndStat == CAN_OK){
    Serial.println("Message Sent Successfully!");
  } else {
    Serial.println("Error Sending Message...");
  }
  delay(100);   // send data per 100ms
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
