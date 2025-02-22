import cv2 
import serial

port = "COM7"
baudrate = 9600

ser = serial.Serial(port, baudrate=baudrate)

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

cap = cv2.VideoCapture(1)

while 1: 
    ret, img = cap.read() 
    
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

    for (x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(0, 0, 255),2)
        cv2.putText(img,"ENEMY", (x,y-5), 0, 1, (0,0,255),2)
    x = 0
    y = 0
    if len(faces) > 0:
        x,y,w,h = faces[0]
        x=x+w/2-gray.shape[1]/2
        y=y+h/2-gray.shape[0]/2

    if x > gray.shape[1]/8:
        ser.write(b'r')
    elif x < -gray.shape[1]/8:
        ser.write(b'l')
    
    if y > gray.shape[0]/8:
        ser.write(b'd')
    elif y < -gray.shape[0]/8:
        ser.write(b'u')

    cv2.imshow('BORYVITER',img)

    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

cap.release()

ser.close()

cv2.destroyAllWindows() 
