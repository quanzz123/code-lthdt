// include the fstream library for file operations
#include <fstream>
// include the iostream library for input/output
#include <iostream>
// include the string library for string manipulation
#include <string>
// include the vector library for dynamic arrays
#include <vector>
using namespace std;

// Base class for IT devices
class ITDevice {
  protected:
    string name; // name of the device
    string code; // code of the device
    string date; // date of entry
    string status; // status of the device (in use or expired)
  public:
    // constructor
    ITDevice(string n, string c, string d, string s) {
      name = n;
      code = c;
      date = d;
      status = s;
    }
    // getter methods
    string getName() { return name; }
    string getCode() { return code; }
    string getDate() { return date; }
    string getStatus() { return status; }
    // setter methods
    void setName(string n) { name = n; }
    void setCode(string c) { code = c; }
    void setDate(string d) { date = d; }
    void setStatus(string s) { status = s; }
};

// Derived class for printers
class Printer : public ITDevice {
  protected:
    string color; // color of the printer
    int speed; // speed of printing
    int memory; // memory of the printer
  public:
    // constructor
    Printer(string n, string c, string d, string s, string col, int sp, int mem) : ITDevice(n, c, d, s) {
      color = col;
      speed = sp;
      memory = mem;
    }
    // getter methods
    string getColor() { return color; }
    int getSpeed() { return speed; }
    int getMemory() { return memory; }
    // setter methods
    void setColor(string col) { color = col; }
    void setSpeed(int sp) { speed = sp; }
    void setMemory(int mem) { memory = mem; }
};

// Derived class for black and white printers
class BWPrinter : public Printer {
  private:
    int resolution; // resolution of the printer in dpi (dots per inch)
  public:
    // constructor
    BWPrinter(string n, string c, string d, string s, string col, int sp, int mem, int res) : Printer(n, c, d, s, col, sp, mem) {
      resolution = res;
    }
    // getter method
    int getResolution() { return resolution; }
    // setter method
    void setResolution(int res) { resolution = res; }
};

// Derived class for color printers
class ColorPrinter : public BWPrinter {
  private:
    int colors; // number of colors supported by the printer
  public:
    // constructor
    ColorPrinter(string n, string c, string d, string s, string col, int sp, int mem, int res, int clrs) : BWPrinter(n, c, d, s, col, sp, mem,res) {
      colors = clrs;
    }
    // getter method
    int getColors() { return colors; }
    // setter method
    void setColors(int clrs) { colors = clrs; }
};

// Derived class for scanners
class Scanner : public ITDevice {
  private:
    int scanSpeed; // scanning speed in pages per minute (ppm)
  public:
  	// constructor
  	Scanner(string n,string c,string d,string s,int ss) : ITDevice(n,c,d,s) {
  		scanSpeed = ss;
  	}
  	// getter method
  	int getScanSpeed() { return scanSpeed; }
  	// setter method
  	void setScanSpeed(int ss) { scanSpeed = ss; }
};

// Derived class for projectors
class Projector : public ITDevice {
  private:
  	int maxHours; // maximum hours of projection 
  public:
  	// constructor 
  	Projector(string n,string c,string d,string s,int mh) : ITDevice(n,c,d,s){
  		maxHours = mh;
  	}
  	// getter method 
  	int getMaxHours() { return maxHours;}
  	// setter method 
  	void setMaxHours(int mh) { maxHours = mh;}
};

// A function to display information about an IT device 
void displayInfo(ITDevice* device){
	cout << "Name: " << device->getName() << endl;
	cout << "Code: " << device->getCode() << endl;
	cout << "Date: " << device->getDate() << endl;
	cout << "Status: " << device->getStatus() << endl;
	// check the type of the device using dynamic_cast
	Printer* printer = dynamic_cast<Printer*>(device);
	Scanner* scanner = dynamic_cast<Scanner*>(device);
	Projector* projector = dynamic_cast<Projector*>(device);
	if(printer != nullptr){
		// device is a printer
		cout << "Color: " << printer->getColor() << endl;
		cout << "Speed: " << printer->getSpeed() << endl;
		cout << "Memory: " << printer->getMemory() << endl;
		BWPrinter* bwprinter = dynamic_cast<BWPrinter*>(printer);
		ColorPrinter* colorprinter = dynamic_cast<ColorPrinter*>(printer);
		if(bwprinter != nullptr){
			// printer is a black and white printer
			cout << "Resolution: " << bwprinter->getResolution() << endl;
			if(colorprinter != nullptr){
				// printer is a color printer
				cout << "Colors: " << colorprinter->getColors() << endl;
			}
		}
	}
	else if(scanner != nullptr){
		// device is a scanner
		cout << "Scan Speed: " << scanner->getScanSpeed() << endl;
	}
	else if(projector != nullptr){
		// device is a projector
		cout << "Max Hours: " << projector->getMaxHours() << endl;
	}
}

// A function to write information about an IT device to a file
void writeInfo(ITDevice* device, ofstream& outFile){
	outFile << device->getName() << ",";
	outFile << device->getCode() << ",";
	outFile << device->getDate() << ",";
	outFile << device->getStatus();
	// check the type of the device using dynamic_cast
	Printer* printer = dynamic_cast<Printer*>(device);
	Scanner* scanner = dynamic_cast<Scanner*>(device);
	Projector* projector = dynamic_cast<Projector*>(device);
	if(printer != nullptr){
		// device is a printer
		outFile << "," << printer->getColor();
		outFile << "," << printer->getSpeed();
		outFile < < "," < < printer->getMemory();
		BWPrinter* bwprinter = dynamic_cast<BWPrinter*>(printer);
		ColorPrinter* colorprinter = dynamic_cast<ColorPrinter*>(printer);
		if(bwprinter != nullptr){
			// printer is a black and white printer
			outFile < < "," < < bwprinter->getResolution();
			if(colorprinter != nullptr){
				// printer is a color printer
				outFile < < "," < < colorprinter->getColors();
			}
			else {
				outFile < < ",0"; // no colors for black and white printer
			}
		}
		else {
			outFile < < ",0,0"; // no resolution and colors for normal printer
		}
	}
	else if(scanner != nullptr){
		// device is a scanner
		outFile << ",0,0,0,0"; // no color, speed, memory and resolution for scanner
		outFile << "," << scanner->getScanSpeed();
	}
	else if(projector != nullptr){
		// device is a projector
		outFile << ",0,0,0,0,0"; // no color, speed, memory, resolution and scan speed for projector
		outFile << "," << projector->getMaxHours();
	}
	else {
		outFile << ",0,0,0,0,0,0"; // no extra information for normal IT device
	}
	outFile << endl; // end the line
}

// A function to write information about an IT device to a file
void writeInfo(ITDevice* device, ofstream& outFile){
	outFile << device->getName() << ",";
	outFile << device->getCode() << ",";
	outFile << device->getDate() << ",";
	outFile << device->getStatus();
	// check the type of the device using dynamic_cast
	Printer* printer = dynamic_cast<Printer*>(device);
	Scanner* scanner = dynamic_cast<Scanner*>(device);
	Projector* projector = dynamic_cast<Projector*>(device);
	if(printer != nullptr){
		// device is a printer
		outFile << "," << printer->getColor();
		outFile << "," << printer->getSpeed();
		outFile < < "," < < printer->getMemory();
		BWPrinter* bwprinter = dynamic_cast<BWPrinter*>(printer);
		ColorPrinter* colorprinter = dynamic_cast<ColorPrinter*>(printer);
		if(bwprinter != nullptr){
			// printer is a black and white printer
			outFile < < "," < < bwprinter->getResolution();
			if(colorprinter != nullptr){
				// printer is a color printer
				outFile < < "," < < colorprinter->getColors();
			}
			else {
				outFile < < ",0"; // no colors for black and white printer
			}
		}
		else {
			outFile < < ",0,0"; // no resolution and colors for normal printer
		}
	}
	else if(scanner != nullptr){
		// device is a scanner
		outFile << ",0,0,0,0"; // no color, speed, memory and resolution for scanner
		outFile << "," << scanner->getScanSpeed();
	}
	else if(projector != nullptr){
		// device is a projector
		outFile << ",0,0,0,0,0"; // no color, speed, memory, resolution and scan speed for projector
		outFile << "," << projector->getMaxHours();
	}
	else {
		outFile << ",0,0,0,0,0,0"; // no extra information for normal IT device
	}
	outFile << endl; // end the line
}

// A function to read information about an IT device from a file
ITDevice* readInfo(ifstream& inFile){
	string name, code, date, status;
	string color;
	int speed, memory;
	int resolution;
	int colors;
	int scanSpeed;
	int maxHours;
	char delimiter = ','; // delimiter character for csv file
	getline(inFile,name,delimiter); // read name until delimiter
	getline(inFile,code,delimiter); // read code until delimiter
	getline(inFile,date,delimiter); // read date until delimiter
	getline(inFile,status); // read status until end of line
	inFile >> color >> delimiter; // read color and delimiter
	inFile >> speed >> delimiter; // read speed and delimiter
	inFile >> memory >> delimiter; // read memory and delimiter
	inFile >> resolution >> delimiter; // read resolution and delimiter
	inFile >> colors >> delimiter; // read colors and delimiter
	inFile >> scanSpeed >> delimiter; // read scan speed and delimiter
	inFile >> maxHours; // read max hours until end of line
	inFile.ignore(); // ignore the newline character

	if(color == "0" && speed == 0 && memory == 0 && resolution == 0 && colors == 0 && scanSpeed == 0 && maxHours == 0){
		// device is a normal IT device
		return new ITDevice(name,code,date,status);
	}
	else if(color != "0" && speed != 0 && memory != 0 && resolution == 0 && colors == 0 && scanSpeed == 0 && maxHours == 0){
		// device is a normal printer
		return new Printer(name,code,date,status,color,speed,memory);
	}
	else if(color != "0" && speed != 0 && memory != 0 && resolution != 0 && colors == 0 && scanSpeed == 0 && maxHours == 0){
		// device is a black and white printer
		return new BWPrinter(name,code,date,status,color,speed,memory,resolution);
	}
	else if(color != "0" && speed != 0 && memory != 0 && resolution != 0 && colors != 0 && scanSpeed == 0 && maxHours == 0){
		// device is a color printer
		return new ColorPrinter(name,code,date,status,color,speed,memory,resolution,colors);
	}
	else if(color == "0" && speed == 0 && memory == 0 && resolution == 0 && colors == 0 && scanSpeed != 0 && maxHours == 0){
		// device is a scanner
		return new Scanner(name,code,date,status,scanSpeed);
	}
	else if(color == "0" && speed == 0 && memory == 0 && resolution == 0 && colors == 0 && scanSpeed == 0 && maxHours != 0){
		// device is a projector
		return new Projector(name,code,date,status,maxHours);
	}
	else {
		// invalid data in the file
		return nullptr;
	}
}

// A function to write all devices in a vector to a file
void writeAll(vector<ITDevice*>& devices, string fileName){
	ofstream outFile;
	outFile.open(fileName); // open the file in output mode
	if(outFile.is_open()){
		for(auto device : devices){ // for each device in the vector
			writeInfo(device,outFile); // write its information to the file
		}
		outFile.close(); // close the file
	}
	else {
		cout << "Error: Cannot open the file for writing." << endl;
	}
}

// A function to read all devices from a file and store them in a vector
void readAll(vector<ITDevice*>& devices, string fileName){
	ifstream inFile;
	inFile.open(fileName); // open the file in input mode
	if(inFile.is_open()){
		while(!inFile.eof()){ // while not end of file
			ITDevice* device = readInfo(inFile); // read a device from the file
			if(device != nullptr){ // if the device is valid
				devices.push_back(device); // add it to the vector
			}
			else {
				cout << "Error: Invalid data in the file." << endl;
			}
		}
		inFile.close(); // close the file
	}
	else {
		cout << "Error: Cannot open the file for reading." << endl;
	}
}

// A function to sort the devices in a vector by name or code
void sort(vector<ITDevice*>& devices, string criterion){
	if(criterion == "name"){
		// sort by name using a lambda expression
		sort(devices.begin(),devices.end(),[](ITDevice* a, ITDevice* b){
			return a->getName() < b->getName();
		});
	}
	else if(criterion == "code"){
		// sort by code using a lambda expression
		sort(devices.begin(),devices.end(),[](ITDevice* a, ITDevice* b){
			return a->getCode() < b->getCode();
		});
	}
	else {
		cout << "Error: Invalid criterion." << endl;
	}
}

// A function to display all devices in a vector
void displayAll(vector<ITDevice*>& devices){
	for(auto device : devices){ // for each device in the vector
		displayInfo(device); // display its information
		cout << "\n";
	}
}

// A function to add a device to the vector
void add(vector<ITDevice*>& devices, ITDevice* device){
	devices.push_back(device); // add the device to the end of the vector
}

// A function to delete a device from the vector by code
void del(vector<ITDevice*>& devices, string code){
	for(int i = 0; i < devices.size(); i++){ // loop through the vector
		if(devices[i]->getCode() == code){ // if the device has the same code
			delete devices[i]; // delete the device from memory
			devices.erase(devices.begin() + i); // erase the device from the vector
			return; // exit the function
		}
	}
	cout << "Error: No device with that code." << endl; // no device found
}

// main function
int main(){
	vector<ITDevice*> devices; // create a vector of IT devices

	readAll(devices,"data.txt"); // read all devices from data.txt and store them in the vector

	displayAll(devices); // display all devices in the vector

	sort(devices,"name"); // sort the devices by name

	displayAll(devices); // display all devices in the vector

	sort(devices,"code"); // sort the devices by code

	displayAll(devices); // display all devices in the vector

	add(devices,new Computer("Computer","C002","01/06/2020","In use")); // add a new computer to the vector

	displayAll(devices); // display all devices in the vector

	del(devices,"P002"); // delete a color printer from the vector

	displayAll(devices); // display all devices in the vector

	writeAll(devices,"data.txt"); // write all devices in the vector to data.txt

	return 0;
}
