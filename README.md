# stopwatch-cardputer
Simple stopwatch app for M5Stack Cardputer

# requirements
- M5Stack Cardputer
- SD Card
- Arduino IDE and libraries: M5Cardputer
- M5Launcher firmware installed on M5Stack Cardputer

# installation
## 1st method
Download stopwatch-cardputer.ino and open it in Arduino IDE. Go to Tools > Board and select M5Stack > M5StampS3. Then Go to Sketch > Export Compiled Binary and wait until it finishes. After that go to Sketch > Show sketch folder, then go to build/m5stack.esp32.m5stack_stamp_s3 and there should be a file called stopwatch-cardputer.ino.bin. Put it on your SD Card, then put the SD Card in your M5Stack Cardputer and launch it from the M5Launcher. That's pretty much it, enjoy!

## 2nd method
Go to the Releases tab and download stopwatch-cardputer.bin. Put it on the SD Card, then put the SD Card in your M5Stack Cardputer and launch it from the M5Launcher.

# usage
- Press any button on the keyboard to start/stop the stopwatch
- Press BtnGO to reset the stopwatch
