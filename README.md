opencv_dollar_detector  
======================  
  
This is an attempt to improve the Dóllar pedestrian detector's performance using camera calibration.   
By Charles Arnoud, under the mentorship of Cláudio Rosito Jüng and with the help of Gustavo Führ.  
  
  
Current Status  
======================  
  
Detection working, but is too slow. Calibrated detection and feature pyramid online, but calibrated detection needs optimization.  
  
  
To Do List:  
======================  
  
Current Total: 5    
  
Opencv_Dollar_Detector.cpp:  
&nbsp;&nbsp;&nbsp;&nbsp;find out why the program is so slow!  
&nbsp;&nbsp;&nbsp;&nbsp;Change the project's name  
  
Calibrated Detection:  
&nbsp;&nbsp;&nbsp;&nbsp;Possibly add a way to use background information  
&nbsp;&nbsp;&nbsp;&nbsp;Remove magic numbers on calibrated detector  
&nbsp;&nbsp;&nbsp;&nbsp;Fix new detector or remove it and just create a new getCandidates function  
      