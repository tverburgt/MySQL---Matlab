%By Ion Comendant, Tyrone Verburgt and Assylzhan Mussin
%ctave script that plots a graph of temperature vs time obtained from the MySQL database


data=dlmread("plot.csv",",");  	%reads an ASCII-delimited numeric data file into matrix M. 
								%The dlmread function detects the delimiter from the file 
								%and treats repeated white spaces as a single delimiter


x=data(:,1);					%inserting 1st column data into the x varaible
y=data(:,2);					%inserting 2n column vectors i.e. temperature in the y variable


plot(x,y)
title('Graph of Temperature Vs Time(2 second delay)');
xlabel('Time (seconds)');
ylabel('Temperature (Celcius)');
axis([63598135287 63598135390 -1 1 ])