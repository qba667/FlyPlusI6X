import struct
import array
import sys
import time
import datetime


def saveFile (name, data):
	endAddress = len(data)-1024*8;
	outFile = open(name + "_updater_" + time.strftime("%m_%d_%H_%M") + ".bin", 'wb')
	outFile.write(data[0x4000:endAddress])
	outFile.close()
	

print('Number of arguments: ' + str(len(sys.argv)) +' arguments.')
print('Argument List: ' + str(sys.argv))

baseFile = sys.argv[1]
destFile = sys.argv[2]

dataFile = open(baseFile, 'rb')
data = bytearray(dataFile.read())
dataFile.close()

	
index2 = 0
timeArray = bytearray(datetime.datetime.now().strftime("%H:%M:%S"), 'utf8')
dataArray = bytearray(datetime.datetime.now().strftime("%b %d %Y"), 'utf8')
dateVersionArray =  bytearray(datetime.datetime.now().strftime("1.0 %b %d %Y"), 'utf8')

for dt in timeArray:
	data[0x11D6C + index2] = dt
	index2+=1
index2 = 0
for dt in dataArray:
	data[0x11D50 + index2] = dt
	index2+=1
index2 = 0
for dt in dateVersionArray:
	data[0x11D34 + index2] = dt
	index2+=1

saveFile(destFile, data)
