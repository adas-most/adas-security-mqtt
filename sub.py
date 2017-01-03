import paho.mqtt.client as mqtt
import socket,sys
import subprocess
import os
import tkinter as tk
def on_connect(client, userdata, flags, rc):
    print("Connected with result code" + str(rc))
    client.subscribe("hello/#")
def on_message(client, userdata, msg):
    t.delete(1.0,'insert')
    byte=msg.payload
    with open("/home/wei/Desktop/Toyota/superuser/95765obd.txt.cpabe",'wb')as f:
    	f.write(byte)
    f.close
    print("Topic", msg.topic +'\nMessage:' + 'get Enc_OBDdata')#test 'str(msg.payload)'
    cmd=subprocess.call("sh /home/wei/Desktop/Toyota/superuser/dec01.sh" ,shell=True)
    if os.path.exists(r"/home/wei/Desktop/Toyota/superuser/95765obd.txt"):
      with open("/home/wei/Desktop/Toyota/superuser/95765obd.txt","r") as f2:
        a=f2.read()
        print(f2.read())
        print(a)
        t.insert('insert',a)
        os.remove("/home/wei/Desktop/Toyota/superuser/95765obd.txt")
    else:
        t.insert('insert','cannot decrypt, attributes in key do not satisfy policy')
    return
def client_exit():
 exit()
win=tk.Tk()
win.geometry("850x150")
win.title("Subscriber")
label=tk.Label(win,bg="yellow",text="Toyota Superuser",font=('Arial',13),width=15,height=2)
label.pack()
#button2=tk.Button(win,text="Star and decrypt",command=start).pack()
button=tk.Button(win,text="exit",command=client_exit).pack()
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("localhost", 1883, 60)
t=tk.Text(win,height=5, width=120)
t.pack()
client.loop_start()
win.mainloop()
client.loop_stop(force=False)
