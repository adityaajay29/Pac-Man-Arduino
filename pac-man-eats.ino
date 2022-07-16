#include <LedControl.h>

const int din = 12;
const int cs = 11;
const int clk = 10;

const uint64_t images [] = 
{
  0x0000000207020000,
  0x000000040e040000,
  0x000000050e050000,
  0x000100081c080001,
  0x0000010b1c0b0100,
  0x0003011038100103,
  0x0001031738170301,
  0x0007032170210307,
  0x0003072f712f0703,
  0x000f0743e143070f,
  0x00070f5fe35f0f07,
  0x001e0f87c3870f1e,
  0x000e1fbfc7bf1f0e,
  0x003c1e0f870f1e3c,
  0x001c3e7f8f7f3e1c,
  0x00783c1e0e1e3c78,
  0x00387cfe1efe7c38,
  0x00f0783c1c3c78f0,
  0x0070f8fc3cfcf870,
  0x00e0f0783878f0e0,
  0x00e0f0f8f8f8f0e0,
  0x00c0e0f0f0f0e0c0,
  0x00c0e0f0f0f0e0c0,
  0x0080c0e0e0e0c080,
  0x0080c0e0e0e0c080,
  0x000080c0c0c08000,
  0x000080c0c0c08000,
  0x0000008080800000,
  0x0000008080800000,
  0x0000000000000000
};

int n = sizeof(images) / 8;

LedControl display = LedControl(din, clk, cs);

void setup()
{
  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 0.5);
}

void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}

int i = 0;

void loop() {
  displayImage(images[i]);
  if (++i >= n ) {
    i = 0;
  }
  delay(130);
}
