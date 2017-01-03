import tkinter as tk
import paho.mqtt.client as mqtt
import time
import sys
import subprocess
import array
import random
def on_connect(client,userdata,flags,rc):
    print("Connected with result code"+str(rc))
def on_publish(client,userdata,mid):
    print("Send Enc_OBDdata")
def test():
 print("1")
 client=mqtt.Client()
 print("2")
 client.on_connect=on_connect
 print("3")
 client.on_publish=on_publish
 client.connect("localhost",1883,60)
 f=open("/home/wei/Desktop/95765.txt.cpabe","rb")
 ba=f.read()
 #byteArray=bytes(ba)
 f.close
 client.publish("hello/word", ba ,0)
 print("EXIT")
def filemodify():
 t.delete(1.0,'insert')
 count=0
 fa=open("/home/wei/Desktop/obd.txt","r")
 for line in fa.readlines():
    fp=open("/home/wei/Desktop/95765.txt","w")
    random1=random.randint(1,15)
    count=count+1
    fp.write(line)
    if count==random1:
     fa.close
     fp.close
     break
 for line in open("/home/wei/Desktop/95765.txt","r"):
   print(line)
   context=line
   t.insert('insert',context)
 if a.get() == 'Toyota' and b.get() == 'Superuser':
  cmd=subprocess.call("sh /home/wei/Desktop/enc.sh 1" ,shell=True)
  if cmd !=0:print(cmd)
  test()
 elif str(a.get()) == 'Toyota' and str(b.get()) == 'user':
  cmd=subprocess.call("sh /home/wei/Desktop/enc.sh 2" ,shell=True)
  if cmd !=0:print(cmd)
  test()
 elif str(a.get()) == 'Toyota' and str(b.get()) == 'no choice':
  cmd=subprocess.call("sh /home/wei/Desktop/enc.sh 3" ,shell=True)
  if cmd !=0:print(cmd)
  test()
 elif str(a.get()) == 'Ford' and str(b.get()) == 'Superuser':
  cmd=subprocess.call("sh /home/wei/Desktop/enc.sh 4" ,shell=True)
  if cmd !=0:print(cmd)
  test()
 elif str(a.get()) == 'Ford' and str(b.get()) == 'user':
  cmd=subprocess.call("sh /home/wei/Desktop/enc.sh 5" ,shell=True)
  if cmd !=0:print(cmd) 
  test()
 elif str(a.get()) == 'Ford' and str(b.get()) == 'no choice':
  cmd=subprocess.call("sh /home/wei/Desktop/enc.sh 6" ,shell=True)
  if cmd !=0:print(cmd) 
  test() 
 else:
  print("error "+a.get()+"  "+b.get())
def sel():
 selection="choose : "+str(a.get())+" "+str(b.get())
 label.config(text = selection )
def client_exit():
 exit() 
win=tk.Tk()
win.grid()
win.geometry("850x250+500+300")
win.title("Publisher")
label=tk.Label(win,bg="yellow",text="This is Mqtt publisher client",font=('Arial',13),width=25,height=2)
label.pack()
frm=tk.Frame(win)
frm.pack()
frm_l=tk.Frame(frm)
frm_r=tk.Frame(frm)
frm_l.pack(side='left')
frm_r.pack(side='right')
a=tk.StringVar()
b=tk.StringVar()
r1=tk.Radiobutton(frm_l,text="Toyota",variable=a,value='Toyota',command=sel).pack()
r2=tk.Radiobutton(frm_l,text="Ford",variable=a,value='Ford',command=sel).pack()
r3=tk.Radiobutton(frm_r,text="Superuser",variable=b,value='Superuser',command=sel).pack()
r4=tk.Radiobutton(frm_r,text="user",variable=b,value='user',command=sel).pack()
r5=tk.Radiobutton(frm_r,text="no choice",variable=b,value='no choice',command=sel).pack()
button2=tk.Button(win,text="encrytion and Send",command=filemodify).pack()
button=tk.Button(win,text="exit",command=client_exit).pack()
t=tk.Text(win,height=5, width=120)
t.pack()
#label=tk.Label(win)
#label.pack()
win.mainloop()
