from PyQt5 import QtWidgets, QtCore
from pyqtgraph import PlotWidget, plot
import pyqtgraph as pg
import sys  # We need sys so that we can pass argv to QApplication
import os
import serial
import time
import re
import plotly.graph_objs as go
from plotly.subplots import make_subplots
import numpy as np
import time
import plotly.graph_objs as go
from plotly.subplots import make_subplots

t=time.time()
arduino = serial.Serial(port='/dev/ttyACM0', baudrate=230400)
def write_read():
    # arduino.write(bytes(angle, 'utf-8'))
    data = arduino.readline()
    return data.decode("utf-8")


class MainWindow(QtWidgets.QMainWindow):

    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)
        self.graphWidget = pg.PlotWidget()
        self.setCentralWidget(self.graphWidget)
        self.x = []  
        self.y = [[],[],[],[],[]]
        self.lines=[]
        self.graphWidget.setBackground('k')
        self.graphWidget.addLegend(offset=(0,1), horizontalStretch=2)
        self.graphWidget.getPlotItem().showGrid(x=True, y=True)
        self.graphWidget.setXRange(0, 20)
        self.graphWidget.setYRange(0, 1000)
        names=['current','position','x','y','z']
        pen = pg.mkPen(color=(255, 0, 0))
        for i in range(len(self.y)):
            self.lines.append(self.graphWidget.plot(self.x, self.y[i], pen=(i,len(self.y)),name=names[i]))
        self.timer = QtCore.QTimer()
        self.timer.setInterval(1)
        self.timer.timeout.connect(self.update_plot_data)
        self.timer.start()
    
    def update_plot_data(self):
        self.x.append(time.time()-t) 
        data=write_read()
        data=data.split(',')    
        for i in range(len(data)):
            self.y[i].append(float(data[i]))
            self.lines[i].setData(self.x, self.y[i])  # Update the data.
        if self.x[len(self.x)-1] > 20:
            self.graphWidget.setXRange(self.lines[0].xData[-1]-20, self.lines[0].xData[-1])
    def return_data(self):
        return self.y

        
        
app = QtWidgets.QApplication(sys.argv)
w = MainWindow()
w.show()
sys.exit(app.exec_())


