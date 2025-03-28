const int trigPin = 7;    // 超聲波感測器 TRIG 接腳
const int echoPin = 8;    // 超聲波感測器 ECHO 接腳
const int whiteLED = 12;  // 白色 LED 接腳

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(whiteLED, OUTPUT);
  Serial.begin(9600);
  
  // LED 測試：開機時閃爍一次
  digitalWrite(whiteLED, HIGH);
  delay(1000);
  digitalWrite(whiteLED, LOW);
  delay(1000);
}

void loop() {
  // 發送超聲波
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // 計算距離
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;  // 換算成公分
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // 根據距離控制 LED
  if (distance > 30) {
    // 安全距離：LED 持續亮著
    digitalWrite(whiteLED, HIGH);
    delay(200);
  } else if (distance > 10) {
    // 警告距離：LED 慢速閃爍
    digitalWrite(whiteLED, HIGH);
    delay(500);
    digitalWrite(whiteLED, LOW);
    delay(500);
  } else {
    // 危險距離：LED 快速閃爍
    digitalWrite(whiteLED, HIGH);
    delay(100);
    digitalWrite(whiteLED, LOW);
    delay(100);
  }
}