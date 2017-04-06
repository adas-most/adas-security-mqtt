import tkinter as tk				# Python interface to Tcl/Tk (GUI)
import paho.mqtt.client as mqtt		# Paho MQTT clinet
import time
import sys
import subprocess
import array
import random

def on_connect(client,userdata,flags,rc):
    print("Connected with result code"+str(rc))

def on_publish(client,userdata,mid):
    print("Encrypted OBD2 data has been send.")

def send_data():
	client = mqtt.Client()
	client.on_connect=on_connect
	client.on_publish=on_publish
	client.connect("iot.eclipse.org",1883,60)
	
	f = open("./obd2.cpabe","rb")
	cipher_data = f.read()
	#byteArray=bytes(ba)
	f.close
	client.publish("adas/most/security", cipher_data ,0)

def encrypt_data():
	t.delete(1.0,'insert')
	count = 0
	f = open("./obd2.txt","r")
	
	for line in f.readlines():
		fp = open("./obd2.plain","w")
		random1 = random.randint(1,15)
		count = count + 1
		fp.write(line)
		
		if count == random1:
			fa.close
			fp.close
			break
 
	for line in open("./obd2.plain","r"):
		print(line)
		context = line
		t.insert('insert',context)
		if a.get() == 'Toyota' and b.get() == 'Superuser':
			cmd = subprocess.call("sh /home/wei/Desktop/enc.sh 1" ,shell=True)
			if cmd !=0:
				print(cmd)
				send_data()
		
		elif str(a.get()) == 'Toyota' and str(b.get()) == 'user':
			cmd=subprocess.call("sh /home/wei/Desktop/enc.sh 2" ,shell=True)
			if cmd !=0:
				print(cmd)
				send_data()
		
		elif str(a.get()) == 'Toyota' and str(b.get()) == 'no choice':
			cmd=subprocess.call("sh /home/wei/Desktop/enc.sh 3" ,shell=True)
			if cmd !=0:
				print(cmd)
				send_data()
				
		elif str(a.get()) == 'Ford' and str(b.get()) == 'Superuser':
			cmd=subprocess.call("sh /home/wei/Desktop/enc.sh 4" ,shell=True)
			if cmd !=0:
				print(cmd)
				send_data()
				
		elif str(a.get()) == 'Ford' and str(b.get()) == 'user':
			cmd=subprocess.call("sh /home/wei/Desktop/enc.sh 5" ,shell=True)			
			if cmd !=0:
				print(cmd) 
				send_data()
				
		elif str(a.get()) == 'Ford' and str(b.get()) == 'no choice':
			cmd=subprocess.call("sh /home/wei/Desktop/enc.sh 6" ,shell=True)
			if cmd !=0:
				print(cmd) 
				send_data()
				
		else:
			print("error "+a.get()+"  "+b.get())

def access_policy():
	selection="choose : "+str(a.get())+" "+str(b.get())
	label.config(text = selection )

def client_exit():
	exit() 

win = tk.Tk()
win.grid()
win.geometry("850x250+500+300")
win.title("Publisher")

label = tk.Label(win,bg="yellow",text="This is Mqtt publisher",font=('Arial',13),width=25,height=2)
label.pack()
frm = tk.Frame(win)
frm.pack()
frm_l = tk.Frame(frm)
frm_r = tk.Frame(frm)
frm_l.pack(side='left')
frm_r.pack(side='right')
a = tk.StringVar()
b = tk.StringVar()
r1 = tk.Radiobutton(frm_l,text="Toyota",variable=a,value='Toyota',command=access_policy).pack()
r2 = tk.Radiobutton(frm_l,text="Ford",variable=a,value='Ford',command=access_policy).pack()
r3 = tk.Radiobutton(frm_r,text="Superuser",variable=b,value='Superuser',command=access_policy).pack()
r4 = tk.Radiobutton(frm_r,text="user",variable=b,value='user',command=access_policy).pack()
r5  =tk.Radiobutton(frm_r,text="no choice",variable=b,value='no choice',command=access_policy).pack()
button2 = tk.Button(win,text="encrytion and Send",command=filemodify).pack()
button = tk.Button(win,text="exit",command=client_exit).pack()
t = tk.Text(win,height=5, width=120)
t.pack()
#label=tk.Label(win)
#label.pack()
win.mainloop()