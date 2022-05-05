import socket
import time
import pickle

d = {1: "hey",2:"there"}
msg = pickle.dumps(d)
print(msg)
