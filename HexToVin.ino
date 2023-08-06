//This file only contain HexToVin function and variable
//It take an array of bytes and respond a VIN as an array of char. 

//HexToVin variable and constant
  uint16_t decoded; //decoded single value
  int index; //Inedex used in loop
  const char Unicode[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};  //Sort of unicode table 
  uint8_t vhex[13] = {0x13, 0x3D, 0xE2, 0x04, 0x1A, 0x27, 0x9B, 0x10, 0x90, 0xDE, 0x4C, 0xE4, 0xCD};			//VIN IN HEX variable
  const uint8_t vindecode[17] = {0x01, 0x04, 0x10, 0x40, 0x01, 0x04, 0x10, 0x40, 0x01, 0x04, 0x10, 0x40, 0x01, 0x04, 0x10, 0x40, 0x01};			//Decoding constant
  const int indexes[17]= {0,1,2,3,3,4,5,6,6,7,8,9,9,10,11,12,12}; //Decoding indexes
  char decodedvin[17]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'}; //Variable to store decoded vin 

void HextoVin(){
 for (int i=0; i<=16; i++){
      index = indexes[i];
      if(i==0){
        decoded = (vhex[index]) / vindecode[i];
        vhex[index]=vhex[index]-(vhex[index] * vindecode[i]);
      }
      if(i>0){
        decoded = ((vhex[index-1]<< 8) + vhex[index]) / vindecode[i];
        vhex[index-1]=vhex[index-1]-(decoded * vindecode[i])<<8;
        vhex[index]=vhex[index]-(decoded * vindecode[i]);
      }
      decodedvin[i]= (Unicode[decoded]);
    } 
}
