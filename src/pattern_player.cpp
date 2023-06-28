/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/admin/CTD_2023/pattern_player/src/pattern_player.ino"
#include <vector>

void setup();
void loop();
void playback();
int m(int x);
#line 3 "/Users/admin/CTD_2023/pattern_player/src/pattern_player.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

std::vector< std::vector < int > > arr;
std::vector< int > row;

int rowi = 0;
int arrS = 0;

void setup() {
  pinMode(D8, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  if (digitalRead(A3)) {
    playback();
  } else if (digitalRead(A2)) {
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);

    arr.push_back(row);

    row = {};
    arrS += 1;
    rowi = 0;
    delay(800);

    digitalWrite(D4, 0);
    digitalWrite(D5, 0);
    digitalWrite(D6, 0);
    digitalWrite(D7, 0);
    digitalWrite(D8, 0);

  } else if (digitalRead(A1)) {
    row.push_back(4 + rowi);
    digitalWrite(4+ rowi, 1);
    rowi += 1;
    delay(800);
  } else if (digitalRead(A0)) {
    if (rowi > 5) {
      rowi = 0;
      row = {};

      digitalWrite(D4, 0);
      digitalWrite(D5, 0);
      digitalWrite(D6, 0);
      digitalWrite(D7, 0);
      digitalWrite(D8, 0);
    } else {
      row.push_back(3);
      rowi += 1;
    }
    delay(800);
  }
}

void playback() {
  while (true) {
    int i = 0;
    while (i < arrS) {
      digitalWrite(arr[i][0], m(arr[i][0]));
      digitalWrite(arr[i][1], m(arr[i][1]));
      digitalWrite(arr[i][2], m(arr[i][2]));
      digitalWrite(arr[i][3], m(arr[i][3]));
      digitalWrite(arr[i][4], m(arr[i][4]));
      delay(100);
      digitalWrite(arr[i][0], 0);
      digitalWrite(arr[i][1], 0);
      digitalWrite(arr[i][2], 0);
      digitalWrite(arr[i][3], 0);
      digitalWrite(arr[i][4], 0);
      i+=1;
    }
  }
}

int m(int x) {
  return x/(abs(x - 1) + 1);
}