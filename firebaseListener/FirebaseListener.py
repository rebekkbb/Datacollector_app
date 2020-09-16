import pyrebase
import time
import numpy 


polarID= "75157825"

config = {
  "apiKey": "APIkey",
  "authDomain": "projectId.firebaseapp.com",
  "databaseURL": "https://projectId.firebaseio.com/",
  "storageBucket": "projectId.appspot.com"
}

arr=[]
file=open(polarID+"-rrs.txt",'a')
firebase=pyrebase.initialize_app(config)
db = firebase.database()

start=db.child(polarID).child("start").get()
print(start.val())

while(int(start.val())==1):
    start=db.child(polarID).child("start").get()
    data=db.child(polarID).child("rrs").get()
    y=db.child(polarID).child("rrs").child("rr").get()
    arr.append(data.val())
    if int(start.val())==0:
        break

for k in arr:
    file.write(k['timestamp']+","+k['rr']+"\n")

