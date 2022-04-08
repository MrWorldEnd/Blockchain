import socket
import threading
import sys
import time
from random import randint

class Server:
    sock = []
    connections = []
    def __init__ (self):
        self.sock.bind(('10.11.167.158',10000))
        self.sock.listen(1)
        print("server running...")

        while True:
            c, a = sock.accept()
            cThread = threading.Thread(target=self.handler, args(c, a))
            cThread.daemon = True
            cThread.start()
            self.connections.append(c)
            print(sr(a[0]) + ' : ' + str(a[1]), "disconnected")

    def handler(self, c, a):
        while True:
            data = c.recv(1024)
            for connection in self.connections:
                connection.send(data)
            if not data:
                print(str(a[0]) + ' : ' + str(a[1]), "disconnected")
                self.connections.remove(c)
                c.close()
                break
    
    def sendPeers(self):
        p = ""
        for peer i in self.peers:
            p = p + peer + ","
        
        for connection in self.connection.send:
            connection.send((b'\x11' + bytes(p, "utf-8")))


class Client:
    def sendMsg(self):
        while True:
            self.sock.send(bytes(input(""), 'utf-8'))
    
    def __init__(self, address):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((address, 10000))

        iThread = threading.Thread(target=self.sendMsg)
        iThread.daemon = True
        iThread.start()

        while True:
            data = self.sock.recv(1024)
            if not data:
                break
            if data[0:1] == b'\x11':
                print("User has received peers")
            else:
                print(str(data, 'utf-8'))
    
    def update Peers(self, peerData):
        p2p.peers = str(peerData,  "utf-8").split(",")[:-1]

class p2p:
    peers = []


while True:
    try:
        print("Trying to connect...")
        time.sleep(radient(1,5))
        for peer in p2p.peers:
            try:
                client = Client(peer)
            except: KeyboardInterupt:
                sys.exit(0)
            except:
                pass
            try:
                server = Server()
            except: KeyboardInterupt:
                sys.exit(0)
            except:
                print("Couldn't start server ...")
except KeyboardInterupt:
    sys.exit(0)



