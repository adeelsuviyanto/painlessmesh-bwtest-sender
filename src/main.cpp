/*
 * ESP8266-based PainlessMesh Bandwidth Test Program
 * Muhammad Adeel Mahdi Suviyanto
 * Telkom University
 * 
 * Sender Node
 */

#include <Arduino.h>
#include <painlessMesh.h>

#define MESH_PREFIX "BW_TEST_PAINLESSMESH"
#define MESH_PASS "12345678"
#define MESH_PORT 5555

int arrayToSend[256];
painlessMesh mesh;
Scheduler userScheduler;

void newConnectionCallback(uint32_t nodeId){
  Serial.printf("New Connection, nodeId = %u\n", nodeId);
}

void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}

void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(),offset);
}

void receivedCallback(uint32_t from, String &msg){
  Serial.printf("Message from %u msg=%s\n", from, msg.c_str());
}

void bandwidthTest(){
  
}

void setup() {
  Serial.begin(115200);
  mesh.setDebugMsgTypes( ERROR | STARTUP | CONNECTION );
  mesh.init(MESH_PREFIX, MESH_PASS, MESH_PORT);
}

void loop() {
  // put your main code here, to run repeatedly:
}