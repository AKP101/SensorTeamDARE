GOAL: To configure this sensor and get it working

So from what I gathered, the manufacturer has actually set most of this up for us already.

Wiring for the Arduino Uno: https://github.com/climateguard/RadSens/blob/master/extras/Example%20schemes/Arduino/Uno%20scheme.jpg 

Then we can run a test given the provided testing code at: https://github.com/climateguard/RadSens/blob/master/examples/I2C_rad_test/I2C_rad_test.ino 

Then after, we can modify that Arduino sketch to fit our drone’s purposes (small changes like sampling rate, etc.) 


IMPORTANT NOTES:
-	MUST POWER W 3.3V SUPPLY, W 5V IT WILL BURN OUT
-	Do not touch the high voltage area of the board (won't kill you, but unpleasant)
-	Can try testing with an americium peel from a smoke detector (or other source of radiation – uranium glass?)
-	Sources: https://www.youtube.com/watch?v=lzGORSGwaEc  (youtube video) and https://github.com/climateguard/RadSens/tree/master  (repository)
-	Datasheet for mechanical and electrical (dimensions, etc.): https://github.com/climateguard/RadSens/blob/master/extras/RadSens-1v4_datasheet_ENG_CG002-0.pdf 
o	They have 3D CAD models even
![image](https://github.com/AKP101/SensorTeamDARE/assets/47980558/9943ba60-3063-4279-aa2c-7f2aa7733157)

