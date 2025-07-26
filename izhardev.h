
//================================
// Function to control the motors based on IR sensor readings
void jeda_hitam(int speed) {
    while (1) {
    // Read IR sensors
    int IR_1_B = ir_Modul(1, 50, NONE);
    int IR_2_B = ir_Modul(2, 50, NONE);
    int IR_3_B = ir_Modul(3, 50, NONE);
    int IR_4_B = ir_Modul(4, 50, NONE);
    int IR_5_B = ir_Modul(5, 50, NONE);

        // Check the status of each IR sensor and control motors accordingly
        if (IR_1_B == TRUE) {
            moveMotors(FORWARD_DIRECTION, BACKWARD_DIRECTION, speed, -speed); 
        } else if (IR_2_B == TRUE) {
            moveMotors(FORWARD_DIRECTION, STOP_DIRECTION, speed, 0);
        } else if (IR_3_B == FALSE) {
            moveMotors(FORWARD_DIRECTION, FORWARD_DIRECTION, speed, speed); 
        } else if (IR_4_B == TRUE) {
            moveMotors(STOP_DIRECTION, FORWARD_DIRECTION, 0, speed); 
        } else if (IR_5_B == TRUE) {
            moveMotors(BACKWARD_DIRECTION, FORWARD_DIRECTION, -speed, speed);
        }

        // Break the loop if both sensor 2 and sensor 4 detect the line
        if (IR_2_B == TRUE && IR_4_B == TRUE) {
            stop(200); 
            break; // Stop for 200 ms & Exit the loop
        }

    }    
    maju(speed, 50); // Move forward with speed for 100 ms
}

//================================
// Function to follow a box shape
void kotak_hitam(int speed) {
    while (1) { // Turn left until sensor 2 detects the line
        // Read IR sensors
        int IR_2_B = ir_Modul(2, 50, NONE);
        kiri(speed, speed, 1); // Turn left for 1 second

        if (IR_2_B == TRUE) break; // Exit if sensor 2 detects the line
    }
    
    while (1) { // Turn right until sensor 4 detects the line   
        // Read IR sensors
        int IR_4_B = ir_Modul(4, 50, NONE);
        kanan(speed, speed, 1); // Turn right for 1 second

        if (IR_4_B == TRUE) break; // Exit if sensor 4 detects the line
    }
    
    while (1) { // Move forward while checking the sensors    
        // Read IR sensors
        int IR_2_B = ir_Modul(2, 50, NONE);
        int IR_4_B = ir_Modul(4, 50, NONE);    

        if (IR_2_B == TRUE) {
            moveMotors(STOP_DIRECTION, FORWARD_DIRECTION, 0, speed); // Stop left motor
        } else if (IR_2_B == FALSE && IR_4_B == FALSE) {
            moveMotors(FORWARD_DIRECTION, FORWARD_DIRECTION, speed, speed); // Move forward
        } else if (IR_4_B == TRUE) {
            moveMotors(FORWARD_DIRECTION, STOP_DIRECTION, speed, 0); // Stop right motor
        } else if (IR_2_B == TRUE && IR_4_B == TRUE) {
            stop(200); 
            break; // Stop for 200 ms & Exit the loop
        }

    }    
    maju(speed, 100); // Move forward with speed for 100 ms
}

//================================
// Function to read IR sensors and control motor movements
void baca_hitam(int speedlow, int speedfast) { 
    while (1) { // Infinite loop for continuous operation
        // Read IR sensors
        int IR_1_B = ir_Modul(1, 50, NONE);
        int IR_2_B = ir_Modul(2, 50, NONE);
        int IR_3_B = ir_Modul(3, 50, NONE);
        int IR_4_B = ir_Modul(4, 50, NONE);
        int IR_5_B = ir_Modul(5, 50, NONE);

        // Check for stopping conditions
        if ((IR_1_B == TRUE && IR_2_B == TRUE) ||
            (IR_2_B == TRUE && IR_3_B == TRUE) ||
            (IR_2_B == TRUE && IR_4_B == TRUE) ||
            (IR_3_B == TRUE && IR_4_B == TRUE) ||
            (IR_4_B == TRUE && IR_5_B == TRUE)) {
            stop(100); 
            break; // Stop for 100 ms & Exit the loop
        } else { // Line following logic 
            if (IR_3_B == TRUE) {
                moveMotors(FORWARD_DIRECTION, FORWARD_DIRECTION, speedfast, speedfast); // Move forward
            } else if (IR_1_B == TRUE) {
                moveMotors(FORWARD_DIRECTION, BACKWARD_DIRECTION, speedfast, -speedfast); // Turn right
            } else if (IR_2_B == TRUE) {
                moveMotors(FORWARD_DIRECTION, FORWARD_DIRECTION, speedlow, speedfast); // Turn slightly right
            } else if (IR_4_B == TRUE) {
                moveMotors(FORWARD_DIRECTION, FORWARD_DIRECTION, speedfast, speedlow); // Turn slightly left
            } else if (IR_5_B == TRUE) {
                moveMotors(BACKWARD_DIRECTION, FORWARD_DIRECTION, -speedfast, speedfast); // Turn left
            }

        }
    }    
    maju(speedfast, 100); // Move forward with speed for 100 ms
}

//================================
// Function to turn right until the center sensor detects the line
void putarkanan_hitam(int speedL, int speedR) {
    while (1) {
        // Read IR sensors
        int IR_3_B = ir_Modul(3, 50, NONE);
        moveMotors(FORWARD_DIRECTION, BACKWARD_DIRECTION, speedL, -speedR); // Turn right

        if (IR_3_B == TRUE) {
            stop(200); 
            break;  // Stop for 200 ms & Exit the loop
        }
        
    }
}

//================================
// Function to turn left until the center sensor detects the line
void putarkiri_hitam(int speedL, int speedR) {
    while (1) {
        // Read IR sensors
        int IR_3_B = ir_Modul(3, 50, NONE);
        moveMotors(BACKWARD_DIRECTION, FORWARD_DIRECTION, -speedL, speedR); // Turn left

        if (IR_3_B == TRUE) {
            stop(200); 
            break;  // Stop for 200 ms & Exit the loop
        }
        
    }
}

//================================
// Function to control motor movements
void moveMotors(int leftDirection, int rightDirection, int speedL, int speedR) {
    dc_motor(LEFT_MOTOR_1, leftDirection, speedL); // Control left motor
    dc_motor(RIGHT_MOTOR_1, rightDirection, speedR); // Control right motor
}

//================================
// Function to move forward for a specified duration
void maju(int speed, int duration) {
    moveMotors(FORWARD_DIRECTION, FORWARD_DIRECTION, speed, speed); // Move forward
    delay(0, 0, 0, duration); // Delay for the specified duration
}

//================================
// Function to move backward for a specified duration
void mundur(int speed, int duration) {
    moveMotors(BACKWARD_DIRECTION, BACKWARD_DIRECTION, -speed, -speed); // Move backward
    delay(0, 0, 0, duration); // Delay for the specified duration
}

//================================
// Function to turn right for a specified duration
void kanan(int speedL, int speedR, int duration) {
    moveMotors(FORWARD_DIRECTION, BACKWARD_DIRECTION, speedL, -speedR); // Turn right
    delay(0, 0, 0, duration); // Delay for the specified duration
}

//================================
// Function to turn left for a specified duration
void kiri(int speedL, int speedR, int duration) {
    moveMotors(BACKWARD_DIRECTION, FORWARD_DIRECTION, -speedL, speedR); // Turn left
    delay(0, 0, 0, duration); // Delay for the specified duration
}

//================================
// Function to stop the motors for a specified duration
void stop(int duration) {
    moveMotors(STOP_DIRECTION, STOP_DIRECTION, 0, 0); // Stop left & right motor
    delay(0, 0, 0, duration); // Delay for the specified duration
}

//================================
// Function to delay the program for a specified duration
void tahan(int duration) {
    delay(0, 0, 0, duration); // Delay for the specified duration
}

//================================
//=== Sound functions
void beep(int pinbuzzer, int ulangi, int frek, int durasi) { 
    for (int counter_0 = 0; counter_0 < ulangi; counter_0++) {
        tone(pinbuzzer, frek, durasi);
    }
}

//================================
//=== Robot arm commands
void arm_ambil(int pinservo, int Angle, int pause) {
    run_servo(pinservo, Angle);
    delay(0, 0, 0, pause);
}

void arm_lepas(int pinservo, int Angle, int pause) {
    run_servo(pinservo, Angle);
    delay(0, 0, 0, pause);
}

void arm_cek(int pinservo, int Angle, int pause) {
    run_servo(pinservo, 0);
    delay(0, 0, 0, pause);
    run_servo(6, Angle);
    delay(0, 0, 0, pause);
    run_servo(pinservo, 0);
    delay(0, 0, 0, pause);
    run_servo(pinservo, -Angle);
    delay(0, 0, 0, pause);
    run_servo(pinservo, 0);
    delay(0, 0, 0, pause);
}

//================================
//=== LED control functions
void signL(int pin1, int pin2){ 
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
}

void signR(int pin1, int pin2){ 
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
}

void signB(int pin1, int pin2){ 
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
}

void signO(int pin1, int pin2){ 
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}

void LED_ON(int pin3){ 
    digitalWrite(pin3, HIGH);
}

void LED_OFF(int pin){ 
    digitalWrite(pin, LOW);
}

//=== Special functions===
void START() {
    LED_ON(3);
    maju(5, 100);
}

void FINISH() {
    baca_hitam(5, 5);
    LED_OFF(3);
    stop(999);
}

void kananhitam(int speedL, int speedR, int duration) {
    baca_hitam(speedR, speedL);
    signR(1, 2);
    kanan(speedL, speedR, duration);
    signO(1, 2);
}

void kirihitam(int speedL, int speedR, int duration) {
    baca_hitam(speedL, speedR);
    signL(1, 2);
    kiri(speedL, speedR, duration);
    signO(1, 2);
}

void putarkananhitam(int speedL, int speedR) {
    baca_hitam(speedR, speedL);
    signR(1, 2);
    putarkanan_hitam(speedL, speedR);
    signO(1, 2);
}

void putarkirihitam(int speedL, int speedR) {
    baca_hitam(speedL, speedR);
    signL(1, 2);
    putarkiri_hitam(speedL, speedR);
    signO(1, 2);
}

void kotakhitam(int speedL, int speedR) {
    baca_hitam(speedL, speedR);
    beep(4, 2, 1500, 50);
    kotak_hitam(speedR);
}

void jedahitam(int speedL, int speedR) {
    baca_hitam(speedL, speedR);
    beep(4, 1, 900, 50);
    beep(4, 1, 1300, 50);
    beep(4, 1, 1100, 50);
    jeda_hitam(speedR);
}

//=== End of Program